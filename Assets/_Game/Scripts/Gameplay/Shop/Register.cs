using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>
    /// A register stall with its cash zone (bills pile on the counter). Active rule of the prototype:
    /// main registers i &lt; 1 + min(reg level, shop level); materials-shop register 6 with plumbing, 7 also needs reg_annex.
    /// </summary>
    public sealed class Register : MonoBehaviour
    {
        public const int FirstAnnexIndex = 6;
        const int CashCapacity = 999;

        [SerializeField] int index;
        [SerializeField] Zone cashZone;
        [Tooltip("Stall furniture in the blockout; hidden while the register is inactive.")]
        [SerializeField] GameObject stall;

        WorldStateSnapshot _state;
        IUpgradeLevels _levels;

        public int Index => index;
        public bool IsAnnex => index >= FirstAnnexIndex;
        public Zone CashZone => cashZone;
        /// <summary>Stall centre (prototype regs[i].x, z).</summary>
        public Vector3 Position => transform.position;

        public bool IsActive
        {
            get
            {
                if (index == FirstAnnexIndex) return _state.OwnsPlumbing;
                if (index > FirstAnnexIndex) return _state.OwnsPlumbing && _levels.GetLevel("reg_annex") > 0;
                return index < 1 + Mathf.Min(_levels.GetLevel("reg"), _levels.GetLevel("shop"));
            }
        }

        /// <summary>Editor tools only.</summary>
        public void Setup(int registerIndex, Zone zone, GameObject stallObject)
        {
            index = registerIndex;
            cashZone = zone;
            stall = stallObject;
        }

        void Awake()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _levels = Services.Get<IUpgradeLevels>();
        }

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            WorldLayout.MainShopSettings s = db.world.mainShop;
            cashZone.Configure(new PileLayout(s.cashPile), () => CashCapacity, () => IsActive, db.items,
                db.economy.zoneRadius, s.cashCounterHeight);
        }

        void LateUpdate()
        {
            bool show = IsActive;
            if (stall != null && stall.activeSelf != show) stall.SetActive(show);
        }

        /// <summary>Prototype <c>regServer</c> for the player: standing inside the cash zone.</summary>
        public bool PlayerServes(Vector3 playerPosition) =>
            ZoneRegistry.Distance(playerPosition, cashZone.Position) < cashZone.Radius;
    }
}
