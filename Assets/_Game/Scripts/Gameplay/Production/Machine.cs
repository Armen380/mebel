using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Production
{
    /// <summary>
    /// A sawmill or product factory (prototype <c>machines</c> entry + <c>updMachine</c>): input zone → machine
    /// mouth → output zone. Numbers come from EconomyConfig / ProductDef / WorldLayout at runtime; the scene only
    /// holds positions and references.
    /// </summary>
    public sealed class Machine : MonoBehaviour
    {
        [Tooltip("saw, saw2 or a product id. Pad levels are read as <id>_speed / <id>_qty.")]
        [SerializeField] string machineId;
        [Tooltip("Product made here; empty for sawmills (log → plank).")]
        [SerializeField] ProductDef product;
        [SerializeField] Zone inputZone;
        [SerializeField] Zone outputZone;
        [SerializeField] Transform mouth;
        [SerializeField] MachineVisual visual;

        MachineCore _core;
        ItemType _outputType;
        float _baseCycle;
        int _baseIn, _baseOut;
        string _speedId, _qtyId;
        EconomyConfig _economy;
        IUpgradeLevels _levels;
        WorldStateSnapshot _state;
        ItemPool _pool;
        ItemFlights _flights;

        public string Id => machineId;
        public bool IsActive => _state.Owns(machineId);
        public MachineCore Core => _core;
        public Zone InputZone => inputZone;
        public Zone OutputZone => outputZone;

        /// <summary>Editor tools only.</summary>
        public void Setup(string id, ProductDef productDef, Zone input, Zone output, Transform mouthPoint, MachineVisual machineVisual)
        {
            machineId = id;
            product = productDef;
            inputZone = input;
            outputZone = output;
            mouth = mouthPoint;
            visual = machineVisual;
        }

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _levels = Services.Get<IUpgradeLevels>();
            _state = Services.Get<WorldStateSnapshot>();
            _pool = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
            _speedId = machineId + "_speed";
            _qtyId = machineId + "_qty";

            WorldLayout.ProductionSettings layout = db.world.production;
            WorldLayout.PileSettings inPile, outPile;
            if (product == null)
            {
                _core = new MachineCore(_economy.sawmillLogsIn, _economy.sawmillPlanksOut);
                _outputType = ItemType.Plank;
                _baseCycle = _economy.sawmillCycleSeconds;
                _baseIn = _economy.sawmillInStorage;
                _baseOut = _economy.sawmillOutStorage;
                inPile = layout.sawIn;
                outPile = layout.sawOut;
            }
            else
            {
                bool planks = product.input == ItemType.Plank;
                _core = new MachineCore(product.inputPerCycle, 1);
                _outputType = product.item;
                _baseCycle = product.cycleSeconds;
                _baseIn = planks ? _economy.plankFactoryInStorage : _economy.mineFactoryInStorage;
                _baseOut = planks ? _economy.plankFactoryOutStorage : _economy.mineFactoryOutStorage;
                inPile = planks ? layout.plankIn : layout.mineIn;
                outPile = layout.productOut;
            }

            inputZone.Configure(new PileLayout(inPile), InputCapacity, () => IsActive, db.items, _economy.zoneRadius, layout.counterTagHeight);
            outputZone.Configure(new PileLayout(outPile), OutputCapacity, () => IsActive, db.items, _economy.zoneRadius, layout.counterTagHeight);
        }

        int InputCapacity() => _economy.StorageCapacity(_baseIn, _levels.GetLevel(_qtyId), _levels.GetLevel(_speedId));

        int OutputCapacity() => _economy.StorageCapacity(_baseOut, _levels.GetLevel(_qtyId), _levels.GetLevel(_speedId));

        void Update()
        {
            if (!IsActive)
            {
                if (visual != null) visual.Busy = false;
                return;
            }
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            ItemStack input = inputZone.Stack, output = outputZone.Stack;

            if (!_core.Busy)
            {
                int k = _core.BatchesAvailable(input.Settled, output.Count, output.Capacity,
                    _economy.ParallelBatches(_levels.GetLevel(_qtyId)));
                if (k >= 1)
                {
                    Vector3 target = mouth.position;
                    int consume = k * _core.InputPerCycle;
                    for (int i = 0; i < consume; i++)
                        _flights.FlyAndDespawn(input.Pop(), target,
                            _economy.machineInFlightSeconds + i * _economy.machineInFlightStep, _economy.machineInArc);
                    _core.Start(k);
                }
            }
            else
            {
                float cycle = _economy.FactoryCycleSeconds(_baseCycle, _levels.GetLevel(_speedId));
                int made = _core.Tick(dt, cycle);
                for (int i = 0; i < made; i++)
                    _flights.FlyToStack(_pool.Get(_outputType, mouth.position), output,
                        _economy.machineOutFlightSeconds + i * _economy.machineOutFlightStep, _economy.flightArc);
            }

            if (visual != null) visual.Busy = _core.Busy;
        }
    }
}
