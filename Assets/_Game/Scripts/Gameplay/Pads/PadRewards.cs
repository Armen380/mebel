using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.World;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Pads
{
    /// <summary>
    /// What a completed pad does beyond its level (prototype <c>addPad({onLevel})</c>): Sawmill 2 and factory buy pads
    /// own the building (<c>ownFactory</c>), the shop pad widens the shop (<c>refreshBlocks</c> + toast), the register pad
    /// opens the next register. Speed / qty pads need nothing here: machines and buildings read the levels.
    /// </summary>
    public sealed class PadRewards : MonoBehaviour
    {
        public const string Sawmill2BuyPad = "saw2_buy";
        const string BuySuffix = "_buy";
        const string Table = "Game";

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        GameDatabase _db;
        Ownership _ownership;
        WorldStateSnapshot _state;
        WorldCollision _collision;
        IUpgradeLevels _levels;

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _ownership = Services.Get<Ownership>();
            _state = Services.Get<WorldStateSnapshot>();
            _collision = Services.Get<WorldCollision>();
            _levels = Services.Get<IUpgradeLevels>();
        }

        void OnEnable() => GameEvents.PadCompleted += OnPadCompleted;

        void OnDisable() => GameEvents.PadCompleted -= OnPadCompleted;

        void OnPadCompleted(string padId, int level)
        {
            if (padId == Sawmill2BuyPad)
            {
                _ownership.Own(WorldStateSnapshot.Sawmill2Id);
                GameEvents.RaiseToast(Text("sign.saw2"), Text("t.saw2"));
            }
            else if (padId.EndsWith(BuySuffix))
            {
                ProductDef p = _db.Product(padId.Substring(0, padId.Length - BuySuffix.Length));
                if (p == null) return;
                _ownership.Own(p.id);
                GameEvents.RaiseToast(Text(p.signKey), Text("t.factoryOpened"));
            }
            else if (padId == WorldStateSync.ShopPadId || padId == WorldStateSync.RegisterPadId)
            {
                WorldStateSync.Apply(_state, _levels);
                _collision.Rebuild(_state);
                if (padId == WorldStateSync.ShopPadId) GameEvents.RaiseToast(Text("t.shopLv", "n", level), ShopUnlockText(level));
            }
        }

        /// <summary>Prototype <c>shopUnlockText(l)</c>: "Can hire: Stocker · " for staff opening at this level, then "+1 register slot".</summary>
        string ShopUnlockText(int shopLevel)
        {
            var names = new System.Text.StringBuilder();
            foreach (UpgradeDef u in _db.upgrades)
            {
                if (u.requiresShopLevel != shopLevel) continue;
                if (names.Length > 0) names.Append(", ");
                names.Append(Text(u.nameKey));
            }
            string hire = names.Length > 0 ? Text("t.canHire", "list", names.ToString()) : "";
            return hire + Text("t.regSlot");
        }

        string Text(string key) => LocalizationSettings.StringDatabase.GetLocalizedString(Table, key);

        string Text(string key, string arg, object value)
        {
            _args.Clear();
            _args[arg] = value;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, key, new object[] { _args });
        }
    }
}
