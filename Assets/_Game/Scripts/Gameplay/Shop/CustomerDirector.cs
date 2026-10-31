using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>
    /// Walk-in customers (prototype <c>spawnCustomer / chooseReg / updCustomers / leave</c>): spawning, shelf and
    /// register queues, taking an item, being served by whoever stands at the register, paying with a bill,
    /// XP, the "+430 ֏" float and leaving (angry when patience runs out). Customers are pooled.
    /// </summary>
    public sealed class CustomerDirector : MonoBehaviour
    {
        const string AdsId = "ads";
        const string ConsultantId = "consult";
        const string QualityId = "quality";
        const string ShopPadId = "shop";
        const float FloatTextHeight = 2.2f;

        [SerializeField] List<Customer> variants = new List<Customer>();
        [SerializeField] int prewarmPerVariant = 2;
        [SerializeField] List<Shelf> shelves = new List<Shelf>();
        [Tooltip("Indexed by register number (prototype regs[i]).")]
        [SerializeField] List<Register> registers = new List<Register>();
        [SerializeField] Transform player;

        readonly List<Customer> _customers = new List<Customer>(32);
        readonly List<Stack<Customer>> _free = new List<Stack<Customer>>();
        readonly List<ProductDef> _ownedScratch = new List<ProductDef>(8);
        readonly List<int> _candidateScratch = new List<int>(8);
        int[] _shelfQueue, _registerQueue, _registerLoad;

        GameDatabase _db;
        EconomyConfig _economy;
        IUpgradeLevels _levels;
        GameProgress _progress;
        ItemPool _items;
        ItemFlights _flights;
        WorldTagRegistry _tags;
        WorldLayout _world;
        WorldStateSnapshot _state;
        float _spawnTimer;

        public IReadOnlyList<Customer> Customers => _customers;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<Customer> variantPrefabs, List<Shelf> shelfList, List<Register> registerList, Transform playerTransform)
        {
            variants = variantPrefabs;
            shelves = shelfList;
            registers = registerList;
            player = playerTransform;
        }

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _economy = _db.economy;
            _world = _db.world;
            _levels = Services.Get<IUpgradeLevels>();
            _state = Services.Get<WorldStateSnapshot>();
            _progress = Services.Get<GameProgress>();
            _items = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
            Services.TryGet(out _tags);
            _spawnTimer = _economy.customerFirstSpawn;
            _shelfQueue = new int[shelves.Count];
            _registerQueue = new int[registers.Count];
            _registerLoad = new int[registers.Count];

            for (int v = 0; v < variants.Count; v++)
            {
                _free.Add(new Stack<Customer>());
                for (int i = 0; i < prewarmPerVariant; i++) _free[v].Push(Create(v));
            }
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            int ads = _levels.GetLevel(AdsId), shopLevel = _levels.GetLevel(ShopPadId);

            _spawnTimer -= dt;
            if (_spawnTimer <= 0f)
            {
                _spawnTimer = _economy.CustomerSpawnInterval(ads, shopLevel);
                if (WalkIns() < _economy.MaxWalkIns(ads, shopLevel)) Spawn();
            }

            AssignQueueIndices();
            float speed = _economy.customerWalkSpeed;
            Vector3 playerPos = player.position;
            for (int i = _customers.Count - 1; i >= 0; i--)
            {
                Customer c = _customers[i];
                if (c.HasWay)
                {
                    bool done = c.FollowWay(dt, speed);
                    if (done && c.State == Customer.Phase.Out) Despawn(i);
                    continue;
                }
                if (c.State == Customer.Phase.Shelf) UpdateAtShelf(c, dt, speed);
                else if (c.State == Customer.Phase.Register) UpdateAtRegister(c, dt, speed, playerPos);
            }

            for (int i = 0; i < _customers.Count; i++) _customers[i].Animator.Carrying = _customers[i].Hands.Count > 0;
        }

        int WalkIns()
        {
            int n = 0;
            for (int i = 0; i < _customers.Count; i++)
                if (_customers[i].State != Customer.Phase.Out) n++;
            return n;
        }

        /// <summary>Prototype <c>sq/rq</c>: queue position = order among customers in the same state and place.</summary>
        void AssignQueueIndices()
        {
            System.Array.Clear(_shelfQueue, 0, _shelfQueue.Length);
            System.Array.Clear(_registerQueue, 0, _registerQueue.Length);
            for (int i = 0; i < _customers.Count; i++)
            {
                Customer c = _customers[i];
                if (c.State == Customer.Phase.Shelf) c.QueueIndex = _shelfQueue[shelves.IndexOf(c.Shelf)]++;
                else if (c.State == Customer.Phase.Register) c.QueueIndex = _registerQueue[c.Register.Index]++;
            }
        }

        void UpdateAtShelf(Customer c, float dt, float speed)
        {
            Shelf shelf = c.Shelf;
            if (c.MoveTo(CustomerQueues.ShelfSlot(shelf.Zone.Position, c.QueueIndex, _world.mainShop), dt, speed))
            {
                c.Animator.FacingYaw = 0f; // prototype face = π: toward the shelf
                if (c.QueueIndex == 0)
                {
                    c.Wait += dt;
                    if (c.TakeTimer < 0f && c.Wait > _economy.customerTakeDelay && shelf.Stack.Settled > 0 && c.Hands.Count < c.Need)
                    {
                        c.TakeTimer = _economy.customerTakeSeconds;
                        _flights.FlyToStack(shelf.Stack.Pop(), c.Hands, _economy.customerTakeFlightSeconds, _economy.flightArc);
                    }
                    if (c.Hands.Settled > 0 && shelf.Stack.Settled == 0) c.Partial += dt;
                }
            }

            if (c.TakeTimer >= 0f)
            {
                c.TakeTimer -= dt;
                if (c.TakeTimer < 0f)
                {
                    int n = c.Hands.Settled;
                    if (n >= c.Need || (n > 0 && c.Partial > _economy.customerPartialWait)) GoToRegister(c);
                    else c.TakeTimer = -1f;
                }
            }
            else if (c.Hands.Settled > 0 && c.Partial > _economy.customerPartialWait) GoToRegister(c);
            else if (c.Hands.Settled == 0)
            {
                c.Patience -= dt;
                if (c.Patience <= 0f) Leave(c, true);
            }
        }

        void UpdateAtRegister(Customer c, float dt, float speed, Vector3 playerPos)
        {
            Register r = c.Register;
            if (!c.MoveTo(CustomerQueues.RegisterSlot(r.Position, c.QueueIndex, _world.mainShop), dt, speed)) return;
            c.Animator.FacingYaw = -90f; // prototype face = −π/2: toward the counter
            if (c.QueueIndex != 0) return;

            // workers serve registers from M6; the player serves while standing on the cash zone
            float rate = r.PlayerServes(playerPos) ? _economy.playerServeRate : 0f;
            c.WaitRegister = rate > 0f ? 0f : c.WaitRegister + dt;
            c.Serve += dt * rate;
            if (c.Serve < _economy.serveSeconds) return;
            c.Serve = 0f;
            Pay(c, r);
            Leave(c, false);
        }

        void Pay(Customer c, Register r)
        {
            ProductDef p = c.Want;
            int n = Mathf.Max(1, c.Hands.Settled);
            long price = _economy.SalePrice(p.basePrice, _levels.GetLevel(QualityId));
            long value = _economy.BillValue(price, _levels.GetLevel(ConsultantId), n, false);

            Vector3 at = c.transform.position;
            at.y = _economy.billSpawnHeight;
            Item bill = _items.Get(ItemType.Bill, at);
            bill.Value = value;
            _flights.FlyToStack(bill, r.CashZone.Stack, _economy.billFlightSeconds, _economy.flightArc);

            _progress.AddXp(p.xpPerSale * n);
            at.y = FloatTextHeight;
            GameEvents.RaiseFloatText(at, "+" + NumberFormat.Money(value));
        }

        void GoToRegister(Customer c)
        {
            c.State = Customer.Phase.Register;
            c.Register = ChooseRegister(c);
            c.Serve = 0f;
            c.ClearWay();
            c.AddWaypoint(CustomerQueues.RegisterApproach(c.Register.Position, _world.mainShop));
        }

        Register ChooseRegister(Customer c)
        {
            bool annex = c.Want.sellsIn == ShopKind.Materials;
            System.Array.Clear(_registerLoad, 0, _registerLoad.Length);
            for (int i = 0; i < _customers.Count; i++)
                if (_customers[i].State == Customer.Phase.Register && _customers[i].Register != null)
                    _registerLoad[_customers[i].Register.Index]++;
            _candidateScratch.Clear();
            for (int i = 0; i < registers.Count; i++)
                if (registers[i].IsAnnex == annex && registers[i].IsActive) _candidateScratch.Add(i);
            int best = CustomerQueues.LeastBusy(_candidateScratch, _registerLoad);
            return registers[best < 0 ? 0 : best];
        }

        void Leave(Customer c, bool angry)
        {
            Doors(c.Want, out Vector2 doorOut, out Vector2 doorIn);
            c.State = Customer.Phase.Out;
            c.Angry = angry;
            c.ClearWay();
            c.AddWaypoint(ProtoCoords.ToUnity(doorIn));
            c.AddWaypoint(ProtoCoords.ToUnity(doorOut));
            c.AddWaypoint(ProtoCoords.ToUnity(_world.customerPaths.exit));
        }

        void Spawn()
        {
            _ownedScratch.Clear();
            foreach (Shelf shelf in shelves)
                if (_state.Owns(shelf.Product.id)) _ownedScratch.Add(shelf.Product);
            if (_ownedScratch.Count == 0 || variants.Count == 0) return;

            ProductDef want = _ownedScratch[Random.Range(0, _ownedScratch.Count)];
            Customer c = Take(Random.Range(0, variants.Count));
            c.Begin(want, ShelfOf(want), _economy.CustomerPatience(_levels.GetLevel(ConsultantId)));
            c.transform.position = ProtoCoords.ToUnity(_world.customerPaths.spawn);

            Doors(want, out Vector2 doorOut, out Vector2 doorIn);
            WorldLayout.MainShopSettings shop = _world.mainShop;
            Vector2 inside = doorIn + new Vector2((Random.value - 0.5f) * shop.doorJitter, shop.doorInsideOffset);
            c.AddWaypoint(ProtoCoords.ToUnity(doorOut));
            c.AddWaypoint(ProtoCoords.ToUnity(inside));
            _customers.Add(c);
            _tags?.Register(c);
        }

        void Doors(ProductDef want, out Vector2 doorOut, out Vector2 doorIn)
        {
            WorldLayout.CustomerPathSettings p = _world.customerPaths;
            bool annex = want.sellsIn == ShopKind.Materials;
            doorOut = annex ? p.annexDoorOut : p.mainDoorOut;
            doorIn = annex ? p.annexDoorIn : p.mainDoorIn;
        }

        Shelf ShelfOf(ProductDef product)
        {
            foreach (Shelf s in shelves)
                if (s.Product == product) return s;
            return null;
        }

        Customer Take(int variant)
        {
            Customer c = _free[variant].Count > 0 ? _free[variant].Pop() : Create(variant);
            c.gameObject.SetActive(true);
            return c;
        }

        void Despawn(int index)
        {
            Customer c = _customers[index];
            _customers.RemoveAt(index);
            _tags?.Unregister(c);
            while (c.Hands.Settled > 0) _items.Release(c.Hands.Pop());
            c.gameObject.SetActive(false);
            _free[c.PoolIndex].Push(c);
        }

        Customer Create(int variant)
        {
            Customer c = Instantiate(variants[variant], transform);
            c.name = variants[variant].name;
            c.PoolIndex = variant;
            c.Init(_db.items, _economy.cashBubbleDelay, _economy.shelfBubbleDelay);
            c.gameObject.SetActive(false);
            return c;
        }
    }
}
