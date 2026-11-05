using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Production;
using FF.Gameplay.Shop;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.AI
{
    /// <summary>
    /// Hires (one worker per upgrade level, also after loading) and runs the workers: prototype <c>updLumber</c>,
    /// <c>updCarrier</c> (carrier, stocker, robot), <c>assignStaff / updCashier</c>, <c>updManager</c>, <c>updConsult</c>.
    /// Runs before customers so registers know who serves them this frame.
    /// </summary>
    [DefaultExecutionOrder(-10)]
    public sealed class WorkerDirector : MonoBehaviour
    {
        const float CashTargetHeight = 1.3f;

        [Tooltip("One prefab per WorkerKind, in enum order.")]
        [SerializeField] List<Worker> prefabs = new List<Worker>();
        [SerializeField] List<Machine> machines = new List<Machine>();
        [SerializeField] List<Shelf> shelves = new List<Shelf>();
        [Tooltip("Indexed by register number.")]
        [SerializeField] List<Register> registers = new List<Register>();
        [SerializeField] CustomerDirector customers;
        [SerializeField] Transform player;
        [Tooltip("Truck dock zones in bay order (prototype freeDock takes the first with room).")]
        [SerializeField] List<Zone> docks = new List<Zone>();

        readonly List<Worker> _workers = new List<Worker>(32);
        readonly List<ProductionLine> _lines = new List<ProductionLine>();
        readonly List<IPile> _sawInputs = new List<IPile>();
        readonly List<IPile> _sawOutputs = new List<IPile>();
        readonly List<ProductionLine> _scratch = new List<ProductionLine>();
        readonly List<IPile> _docks = new List<IPile>(3);
        readonly List<bool> _registerActive = new List<bool>();
        readonly int[] _cashierRegister = new int[16];
        readonly int[] _sectionRegister = new int[4];
        readonly int[] _countPerKind = new int[WorkerKinds.All.Length];

        GameDatabase _db;
        EconomyConfig _economy;
        WorldLayout _world;
        IUpgradeLevels _levels;
        ItemPool _items;
        ItemFlights _flights;
        NodeRegistry _nodes;
        WorldStateSnapshot _state;
        IPile _clayInput, _ironInput;

        public IReadOnlyList<Worker> Workers => _workers;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<Worker> workerPrefabs, List<Machine> machineList, List<Shelf> shelfList, List<Register> registerList,
            CustomerDirector customerDirector, Transform playerTransform, List<Zone> dockZones)
        {
            docks = dockZones;
            prefabs = workerPrefabs;
            machines = machineList;
            shelves = shelfList;
            registers = registerList;
            customers = customerDirector;
            player = playerTransform;
        }

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _economy = _db.economy;
            _world = _db.world;
            _levels = Services.Get<IUpgradeLevels>();
            _items = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
            _nodes = Services.Get<NodeRegistry>();
            _state = Services.Get<WorldStateSnapshot>();
            BuildLines();
            foreach (Zone d in docks) _docks.Add(d);
            foreach (WorkerKind kind in WorkerKinds.All)
                for (int i = 0; i < _levels.GetLevel(WorkerKinds.UpgradeId(kind)); i++) Spawn(kind);
        }

        void OnEnable() => GameEvents.UpgradeBought += OnUpgradeBought;

        void OnDisable() => GameEvents.UpgradeBought -= OnUpgradeBought;

        void OnUpgradeBought(string id, int level)
        {
            if (WorkerKinds.TryFromUpgrade(id, out WorkerKind kind)) Spawn(kind);
        }

        void BuildLines()
        {
            foreach (Machine m in machines)
            {
                if (m.Product == null)
                {
                    _sawInputs.Add(m.InputZone);
                    _sawOutputs.Add(m.OutputZone);
                    continue;
                }
                Machine machine = m;
                _lines.Add(new ProductionLine
                {
                    ProductId = m.Product.id,
                    ProductNameKey = m.Product.nameKey,
                    InputType = m.Product.input,
                    InputPerCycle = m.Product.inputPerCycle,
                    Input = m.InputZone,
                    Output = m.OutputZone,
                    Shelf = ShelfOf(m.Product)?.Zone,
                    Section = m.Product.sellsIn == ShopKind.Materials,
                    MachineBusy = () => machine.Core.Busy,
                });
                if (m.Product.input == ItemType.Clay) _clayInput = m.InputZone;
                else if (m.Product.input == ItemType.Iron) _ironInput = m.InputZone;
            }
        }

        Shelf ShelfOf(ProductDef product)
        {
            foreach (Shelf s in shelves)
                if (s.Product == product) return s;
            return null;
        }

        void Spawn(WorkerKind kind)
        {
            Worker prefab = prefabs[(int)kind];
            Worker w = Instantiate(prefab, transform);
            w.name = prefab.name;
            bool robot = kind == WorkerKind.Robot;
            int capacity = kind == WorkerKind.Lumber ? _economy.lumberCapacity : robot ? _economy.robotCapacity : _economy.workerCapacity;
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            w.Init(_countPerKind[(int)kind]++, robot ? _economy.robotSpeed : _economy.workerSpeed, capacity, _db.items,
                s.robotTagHeight, s.robotTagPerItem);
            w.transform.position = ProtoCoords.ToUnity(SpawnPoint(kind, s));
            _workers.Add(w);
        }

        static Vector2 SpawnPoint(WorkerKind kind, WorldLayout.WorkerLayoutSettings s)
        {
            switch (kind)
            {
                case WorkerKind.Lumber: return s.lumberSpawn;
                case WorkerKind.Robot: return s.robotSpawn;
                case WorkerKind.Carrier: return s.carrierSpawn;
                case WorkerKind.Miner:
                case WorkerKind.SectionCarrier: return s.sectionSpawn;
                case WorkerKind.SectionCashier: return s.sectionCashierSpawn;
                default: return s.shopStaffSpawn;
            }
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            AssignCashiers();
            for (int i = 0; i < _workers.Count; i++)
            {
                Worker w = _workers[i];
                switch (w.Kind)
                {
                    case WorkerKind.Lumber: UpdateLumber(w, dt); break;
                    case WorkerKind.Miner: UpdateMiner(w, dt); break;
                    case WorkerKind.Cashier:
                    case WorkerKind.SectionCashier: UpdateCashier(w, dt); break;
                    case WorkerKind.Manager: UpdateManager(w, dt); break;
                    case WorkerKind.Consultant: UpdateConsultant(w, dt); break;
                    default: UpdateCarrier(w, dt); break;
                }
                w.Animator.Carrying = w.Hands.Count > 0;
            }
        }

        // ---------- lumberjack (prototype updLumber) ----------

        void UpdateLumber(Worker w, float dt)
        {
            ItemStack hands = w.Hands;
            w.Animator.Chopping = false;
            if (w.Delivering)
            {
                if (hands.Count == 0)
                {
                    w.Delivering = false;
                    return;
                }
                w.Destination ??= CarrierJobs.SawInput(_sawInputs);
                if (w.Destination == null || !GoTo(w, w.Destination.Position, dt)) return;
                Unload(w, (Zone)w.Destination, dt);
                if (hands.Count == 0) w.Destination = null;
                return;
            }

            if (hands.Count >= w.Capacity)
            {
                w.Delivering = true;
                Release(w);
                return;
            }
            if (w.Tree == null || !w.Tree.State.Alive)
            {
                Release(w);
                w.Tree = _nodes.Nearest(w.transform.position, ItemType.Log, w);
                if (w.Tree != null) w.Tree.State.ReservedBy = w;
                else
                {
                    if (hands.Count > 0) w.Delivering = true;
                    w.Animator.Moving = false;
                    return;
                }
            }

            Vector3 tree = w.Tree.Position, p = w.transform.position;
            if (ZoneRegistry.Distance(p, tree) > _economy.workerChopReach)
            {
                w.MoveTo(tree, dt, w.Speed);
                return;
            }
            w.Animator.Moving = false;
            w.Animator.FacingYaw = Mathf.Atan2(tree.x - p.x, tree.z - p.z) * Mathf.Rad2Deg;
            // prototype tryChop uses st.chop(): the player's axe level speeds up the lumberjacks too
            Chopper.Result r = w.Chopper.TryChop(w.Tree.State, hands, dt, _economy.lumberChopRate, _economy.ChopSeconds(_levels.GetLevel("axe")),
                _economy.chopHitInterval, _economy.itemsPerChop);
            w.Animator.Chopping = r.Chopping;
            for (int i = 0; i < r.Yield; i++)
            {
                Vector3 at = tree;
                at.y = _economy.chopSpawnHeight + i * _economy.chopSpawnStep;
                _flights.FlyToStack(_items.Get(ItemType.Log, at), hands, _economy.chopFlightSeconds, _economy.flightArc);
            }
            if (r.Yield > 0) w.Tree = null; // felled: the prototype releases the reservation with the fall
        }

        // ---------- miner (prototype updMiner) ----------

        void UpdateMiner(Worker w, float dt)
        {
            ItemStack hands = w.Hands;
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            w.Animator.Chopping = false;
            if (!_state.OwnsPlumbing)
            {
                w.MoveTo(ProtoCoords.ToUnity(s.sectionSpawn), dt, w.Speed * _economy.workerIdleSpeedFactor);
                return;
            }
            if (w.Way.Count > 0)
            {
                if (w.MoveTo(w.Way[0], dt, w.Speed)) w.Way.RemoveAt(0);
                return;
            }
            if (w.Delivering)
            {
                if (hands.Count == 0)
                {
                    w.Delivering = false;
                    w.Resource = ItemType.None;
                    MinerRules.GapWay(true, s, w.Way);
                    return;
                }
                var input = (Zone)(hands.Type == ItemType.Iron ? _ironInput : _clayInput);
                if (input == null || !w.MoveTo(input.Position, dt, w.Speed)) return;
                if (input.IsActive) Unload(w, input, dt);
                return;
            }
            if (!MinerRules.InYard(-w.transform.position.z, s))
            {
                MinerRules.GapWay(true, s, w.Way);
                return;
            }
            if (w.Resource == ItemType.None) w.Resource = MinerRules.ChooseResource(_clayInput, _ironInput);
            if (hands.Count >= w.Capacity)
            {
                StartMinerDelivery(w, s);
                return;
            }
            if (w.Tree == null || !w.Tree.State.Alive)
            {
                Release(w);
                w.Tree = _nodes.Nearest(w.transform.position, w.Resource, w);
                if (w.Tree != null) w.Tree.State.ReservedBy = w;
                else
                {
                    w.Animator.Moving = false;
                    if (hands.Count > 0) StartMinerDelivery(w, s);
                    return;
                }
            }

            Vector3 rock = w.Tree.Position, p = w.transform.position;
            if (ZoneRegistry.Distance(p, rock) > _economy.workerChopReach)
            {
                w.MoveTo(rock, dt, w.Speed);
                return;
            }
            w.Animator.Moving = false;
            w.Animator.FacingYaw = Mathf.Atan2(rock.x - p.x, rock.z - p.z) * Mathf.Rad2Deg;
            Chopper.Result r = w.Chopper.TryChop(w.Tree.State, hands, dt, _economy.lumberChopRate, _economy.ChopSeconds(_levels.GetLevel("axe")),
                _economy.chopHitInterval, _economy.itemsPerChop);
            w.Animator.Chopping = r.Chopping;
            for (int i = 0; i < r.Yield; i++)
            {
                Vector3 at = rock;
                at.y = _economy.chopSpawnHeight + i * _economy.chopSpawnStep;
                _flights.FlyToStack(_items.Get(w.Resource, at), hands, _economy.chopFlightSeconds, _economy.flightArc);
            }
            if (r.Yield > 0) w.Tree = null;
        }

        void StartMinerDelivery(Worker w, WorldLayout.WorkerLayoutSettings s)
        {
            w.Delivering = true;
            Release(w);
            MinerRules.GapWay(false, s, w.Way);
        }

        static void Release(Worker w)
        {
            if (w.Tree != null && ReferenceEquals(w.Tree.State.ReservedBy, w)) w.Tree.State.ReservedBy = null;
            w.Tree = null;
        }

        // ---------- carrier / stocker / robot (prototype updCarrier) ----------

        void UpdateCarrier(Worker w, float dt)
        {
            ItemStack hands = w.Hands;
            bool robot = w.Kind == WorkerKind.Robot, stocker = w.Kind == WorkerKind.Stocker, section = w.Kind == WorkerKind.SectionCarrier;
            if (w.Job == null)
            {
                if (hands.Count > 0)
                {
                    IPile leftover = CarrierJobs.LeftoverTarget(hands.Type, _lines, _sawInputs, stocker, robot, _docks);
                    if (leftover == null)
                    {
                        Rest(w, dt);
                        return;
                    }
                    w.Putting = true;
                    w.Job = new WorkerJob { To = leftover };
                }
                else
                {
                    w.Job = robot
                        ? RobotScoring.Best(w.transform.position, _lines, _sawOutputs, _docks, WaitingCustomers, p => RobotsHeadingTo(p, w), _economy)
                        : CarrierJobs.Pick(_lines, _sawOutputs, stocker, _docks, _scratch, section);
                    w.Putting = false;
                    if (w.Job == null)
                    {
                        Rest(w, dt);
                        if (!w.Animator.Moving) w.Animator.FacingYaw = AgentMotor.YawFromPrototype(0f);
                        return;
                    }
                }
            }

            WorkerJob job = w.Job;
            if (!w.Putting)
            {
                var from = (Zone)job.From;
                if (!GoTo(w, from.Position, dt)) return;
                w.Cooldown -= dt;
                if (hands.Count >= w.Capacity || (job.Want > 0 && hands.Count >= job.Want) || (from.Stack.Settled == 0 && hands.Count > 0))
                {
                    w.Putting = true;
                    return;
                }
                if (from.Stack.Settled == 0)
                {
                    w.Job = null;
                    return;
                }
                if (w.Cooldown <= 0f && (hands.Type == ItemType.None || hands.Type == from.Stack.Type))
                {
                    _flights.FlyToStack(from.Stack.Pop(), hands, _economy.transferFlightSeconds, _economy.flightArc);
                    w.Cooldown = _economy.workerTransferInterval;
                }
                return;
            }

            var to = (Zone)job.To;
            if (!GoTo(w, to.Position, dt)) return;
            w.Cooldown -= dt;
            if (hands.Count == 0)
            {
                w.Job = null;
                return;
            }
            if (to.IsActive && to.Stack.HasRoom)
            {
                w.Stuck = 0f;
                if (w.Cooldown <= 0f && hands.Settled > 0)
                {
                    _flights.FlyToStack(hands.Pop(), to.Stack, _economy.transferFlightSeconds, _economy.flightArc);
                    w.Cooldown = _economy.workerTransferInterval;
                }
            }
            else
            {
                w.Stuck += dt;
                if (w.Stuck > _economy.workerStuckSeconds)
                {
                    w.Stuck = 0f;
                    w.Job = null;
                }
            }
        }

        void Unload(Worker w, Zone zone, float dt)
        {
            w.Cooldown -= dt;
            if (w.Cooldown > 0f || w.Hands.Settled == 0 || !zone.Stack.HasRoom) return;
            _flights.FlyToStack(w.Hands.Pop(), zone.Stack, _economy.transferFlightSeconds, _economy.flightArc);
            w.Cooldown = _economy.workerTransferInterval;
        }

        void Rest(Worker w, float dt)
        {
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            Vector2 spot = w.Kind == WorkerKind.Stocker ? s.stockerRest + new Vector2(w.Index * s.stockerRestStep, 0f)
                : w.Kind == WorkerKind.Robot ? s.robotRest + new Vector2(w.Index * s.robotRestStep, 0f)
                : w.Kind == WorkerKind.SectionCarrier ? s.sectionCarrierRest + new Vector2(w.Index * s.sectionCarrierRestStep, 0f)
                : s.CarrierRest(w.Index);
            w.MoveTo(ProtoCoords.ToUnity(spot), dt, w.Speed * _economy.workerIdleSpeedFactor);
        }

        int WaitingCustomers(IPile shelf)
        {
            int n = 0;
            IReadOnlyList<Customer> list = customers.Customers;
            for (int i = 0; i < list.Count; i++)
            {
                Customer c = list[i];
                if (c.State == Customer.Phase.Shelf && c.Shelf != null && ReferenceEquals(c.Shelf.Zone, shelf) && c.TakeTimer < 0f) n++;
            }
            return n;
        }

        int RobotsHeadingTo(IPile pile, Worker self)
        {
            int n = 0;
            for (int i = 0; i < _workers.Count; i++)
            {
                Worker o = _workers[i];
                if (o != self && o.Kind == WorkerKind.Robot && o.Job != null && ReferenceEquals(o.Job.To, pile)) n++;
            }
            return n;
        }

        bool GoTo(Worker w, Vector3 target, float dt) => w.GoTo(target, dt, _world.workers, _world.fenceLineZ);

        // ---------- cashier (prototype assignStaff / updCashier) ----------

        void AssignCashiers()
        {
            _registerActive.Clear();
            for (int i = 0; i < registers.Count; i++)
            {
                _registerActive.Add(registers[i].IsActive);
                registers[i].StaffRate = 0f;
            }
            int cashiers = 0, section = 0;
            foreach (Worker w in _workers)
                if (w.Kind == WorkerKind.Cashier) cashiers++;
                else if (w.Kind == WorkerKind.SectionCashier) section++;
            StaffAssignment.AssignStaff(_registerActive, Mathf.Min(section, _sectionRegister.Length), _sectionRegister,
                Mathf.Min(cashiers, _cashierRegister.Length), _cashierRegister);
            int c = 0, sc = 0;
            foreach (Worker w in _workers)
                if (w.Kind == WorkerKind.Cashier)
                {
                    int r = c < _cashierRegister.Length ? _cashierRegister[c] : -1;
                    w.Register = r >= 0 ? registers[r] : null;
                    c++;
                }
                else if (w.Kind == WorkerKind.SectionCashier)
                {
                    int r = sc < _sectionRegister.Length ? _sectionRegister[sc] : -1;
                    w.Register = r >= 0 ? registers[r] : null;
                    sc++;
                }
        }

        void UpdateCashier(Worker w, float dt)
        {
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            w.Posted = false;
            Register r = w.Register;
            if (r == null)
            {
                Vector2 idle = w.Kind == WorkerKind.SectionCashier
                    ? s.sectionCashierIdle + new Vector2(w.Index * s.sectionCashierIdleStep, 0f)
                    : s.cashierIdle + new Vector2(w.Index * s.cashierIdleStep, 0f);
                w.MoveTo(ProtoCoords.ToUnity(idle), dt, w.Speed * _economy.workerIdleSpeedFactor);
                if (!w.Animator.Moving) w.Animator.FacingYaw = AgentMotor.YawFromPrototype(0f);
                return;
            }
            Vector3 stand = r.Position + new Vector3(s.cashierStand.x, 0f, -s.cashierStand.y);
            if (!w.MoveTo(stand, dt, w.Speed)) return;
            w.Animator.FacingYaw = AgentMotor.YawFromPrototype(Mathf.PI / 2f);
            w.Posted = true;
            r.StaffRate = _economy.cashierServeRateWorker;
        }

        // ---------- manager (prototype updManager) ----------

        void UpdateManager(Worker w, float dt)
        {
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            if (w.Register == null || w.Register.CashZone.Stack.Settled == 0) w.Register = RegisterWithMostBills();
            if (w.Register == null)
            {
                w.MoveTo(ProtoCoords.ToUnity(s.managerIdle + new Vector2(w.Index * s.managerIdleStep, 0f)), dt, w.Speed * _economy.workerIdleSpeedFactor);
                if (!w.Animator.Moving) w.Animator.FacingYaw = AgentMotor.YawFromPrototype(0f);
                return;
            }
            Zone cash = w.Register.CashZone;
            float dz = s.ManagerStandZ(w.Index);
            if (!w.MoveTo(cash.Position + new Vector3(s.managerStand.x, 0f, -dz), dt, w.Speed)) return;
            w.Animator.FacingYaw = AgentMotor.YawFromPrototype(Mathf.PI / 2f);
            w.Cooldown -= dt;
            if (w.Cooldown > 0f) return;
            w.Cooldown = _economy.managerCollectInterval;
            Item bill = cash.Stack.Pop();
            if (bill == null) return;
            bool near = ZoneRegistry.Distance(player.position, w.transform.position) <= _economy.managerQuietDistance;
            _flights.FlyAndCollect(bill, w.transform, CashTargetHeight, _economy.cashFlightSeconds, _economy.cashFlightArc, near);
        }

        Register RegisterWithMostBills()
        {
            Register best = null;
            foreach (Register r in registers)
                if (r.IsActive && r.CashZone.Stack.Settled > 0 && (best == null || r.CashZone.Stack.Settled > best.CashZone.Stack.Settled))
                    best = r;
            return best;
        }

        // ---------- consultant (prototype updConsult) ----------

        void UpdateConsultant(Worker w, float dt)
        {
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            Vector3 spot = ProtoCoords.ToUnity(s.consultantSpot + new Vector2(w.Index * s.consultantSpotStep, 0f));
            if (w.MoveTo(spot, dt, w.Speed * _economy.consultantSpeedFactor))
                w.Animator.FacingYaw = AgentMotor.YawFromPrototype(Mathf.Sin(Time.time * 0.6f + w.Index * 2f) * 1.2f);
        }
    }
}
