using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Progress;
using UnityEngine;

namespace FF.Gameplay.Delivery
{
    /// <summary>
    /// Trucks and bays (prototype <c>makeTruck / updTrucks</c>): one truck per Truck pad level (also after loading), each
    /// takes the first free open bay when it is back, loads 8 items, drives off and pays Σ round(salePrice·1.4) plus XP
    /// once it is gone. Bed contents are mirrored into <see cref="DeliveryCargo"/> for the save.
    /// </summary>
    public sealed class DeliveryDirector : MonoBehaviour
    {
        public const string TruckPadId = "truck";
        const string QualityId = "quality";

        [SerializeField] Truck prefab;
        [Tooltip("In prototype order: bay 0 is next to the shop.")]
        [SerializeField] List<TruckBay> bays = new List<TruckBay>();

        readonly List<Truck> _trucks = new List<Truck>(4);
        readonly List<TruckMotion> _motions = new List<TruckMotion>(4);
        readonly List<TruckMotion> _bayMotions = new List<TruckMotion>(3);
        readonly List<int> _cargoCounts = new List<int>(4);
        readonly List<ProductDef> _scratch = new List<ProductDef>(8);
        readonly Dictionary<ItemType, ProductDef> _products = new Dictionary<ItemType, ProductDef>();

        GameDatabase _db;
        EconomyConfig _economy;
        WorldLayout.DeliverySettings _settings;
        IUpgradeLevels _levels;
        GameProgress _progress;
        ItemPool _items;
        DeliveryCargo _cargo;

        public IReadOnlyList<TruckMotion> Motions => _motions;
        public IReadOnlyList<Truck> Trucks => _trucks;
        public IReadOnlyList<TruckBay> Bays => bays;
        public int OrderSize => _economy.truckOrderSize;

        /// <summary>Editor tools only.</summary>
        public void Setup(Truck truckPrefab, List<TruckBay> bayList)
        {
            prefab = truckPrefab;
            bays = bayList;
        }

        void Awake()
        {
            foreach (TruckBay b in bays)
            {
                b.Init(this, bays.Count);
                _bayMotions.Add(null);
            }
        }

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _economy = _db.economy;
            _settings = _db.world.delivery;
            _levels = Services.Get<IUpgradeLevels>();
            _progress = Services.Get<GameProgress>();
            _items = Services.Get<ItemPool>();
            _cargo = Services.Get<DeliveryCargo>();
            foreach (ProductDef p in _db.products) _products[p.item] = p;

            int owned = _levels.GetLevel(TruckPadId);
            for (int i = 0; i < owned; i++) AddTruck();
            RestoreCargo();
        }

        void OnEnable() => GameEvents.PadCompleted += OnPadCompleted;

        void OnDisable() => GameEvents.PadCompleted -= OnPadCompleted;

        void OnPadCompleted(string padId, int level)
        {
            if (padId == TruckPadId) AddTruck();
        }

        void AddTruck()
        {
            Truck t = Instantiate(prefab, transform);
            t.name = prefab.name + _trucks.Count;
            TruckMotion motion = t.Motion;
            t.Init(_db.items, _settings.truckBed, () => motion.Phase == TruckPhase.Docked ? _economy.truckOrderSize : 0);
            t.gameObject.SetActive(false);
            _trucks.Add(t);
            _motions.Add(motion);
            _cargoCounts.Add(0);
        }

        /// <summary>Saved beds: each loaded truck stands at the first free open bay with its load.</summary>
        void RestoreCargo()
        {
            int active = ActiveBays();
            for (int i = 0; i < _trucks.Count && i < _cargo.Loads.Count; i++)
            {
                List<ItemType> load = _cargo.Loads[i];
                if (load.Count == 0) continue;
                int bay = DeliveryRules.FreeBay(_bayMotions, active);
                if (bay < 0)
                {
                    load.Clear();
                    continue;
                }
                Truck t = _trucks[i];
                t.Motion.DockAt(bay, bays[bay].ProtoX, _settings);
                Take(bay, t);
                t.gameObject.SetActive(true);
                t.Sync();
                for (int k = 0; k < load.Count && k < _economy.truckOrderSize; k++)
                    t.Bed.Place(_items.Get(load[k], t.transform.position));
                _cargoCounts[i] = t.Bed.Settled;
            }
        }

        int ActiveBays() => EconomyConfig.ActiveBays(_levels.GetLevel(TruckBay.ParkingPadId), bays.Count);

        void Take(int bay, Truck t)
        {
            _bayMotions[bay] = t.Motion;
            bays[bay].Truck = t;
            bays[bay].Dock.UsePile(t.Bed);
        }

        void Free(int bay)
        {
            _bayMotions[bay] = null;
            bays[bay].Truck = null;
            bays[bay].Dock.UsePile(null);
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            int active = ActiveBays();
            for (int i = 0; i < _trucks.Count; i++)
            {
                Truck t = _trucks[i];
                TruckMotion m = t.Motion;
                int bay = m.Bay;
                TruckEvent ev = m.Step(dt, bay >= 0 ? bays[bay].ProtoX : 0f, t.Bed.Settled, _economy, _settings);
                switch (ev)
                {
                    case TruckEvent.Full:
                        CargoProducts(t);
                        t.PendingPay = DeliveryRules.Payout(_scratch, _economy, _levels.GetLevel(QualityId));
                        t.PendingXp = DeliveryRules.PayoutXp(_scratch);
                        break;
                    case TruckEvent.LeftBay:
                        Free(bay);
                        break;
                    case TruckEvent.Delivered:
                        Deliver(t);
                        break;
                }

                if (m.CanDispatch)
                {
                    int free = DeliveryRules.FreeBay(_bayMotions, active);
                    if (free >= 0)
                    {
                        m.Dispatch(free, _settings);
                        Take(free, t);
                        t.gameObject.SetActive(true);
                    }
                }
                if (m.Phase != TruckPhase.Away) t.Sync();
                TrackCargo(i, t);
            }
        }

        void CargoProducts(Truck t)
        {
            _scratch.Clear();
            for (int k = 0; k < t.Bed.Settled; k++)
                if (_products.TryGetValue(t.Bed[k].Type, out ProductDef p)) _scratch.Add(p);
        }

        void Deliver(Truck t)
        {
            while (t.Bed.Settled > 0) _items.Release(t.Bed.Pop());
            t.gameObject.SetActive(false);
            long pay = t.PendingPay;
            int xp = t.PendingXp;
            t.PendingPay = 0;
            t.PendingXp = 0;
            if (pay > 0) _progress.AddMoney(pay);
            if (xp > 0) _progress.AddXp(xp);
            if (pay > 0) GameEvents.RaiseTruckDelivered(pay);
        }

        /// <summary>Mirrors a bed into the save when its item count changed (no work on other frames).</summary>
        void TrackCargo(int index, Truck t)
        {
            int n = t.Bed.Settled;
            if (n == _cargoCounts[index]) return;
            _cargoCounts[index] = n;
            List<ItemType> load = _cargo.Of(index);
            load.Clear();
            for (int k = 0; k < n; k++) load.Add(t.Bed[k].Type);
            GameEvents.RaiseProgressChanged();
        }
    }
}
