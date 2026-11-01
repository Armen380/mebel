using FF.Core;
using FF.Data;
using FF.Gameplay.World;

namespace FF.Gameplay.Progress
{
    /// <summary>Upgrades-panel purchases on top of <see cref="GameProgress"/> (prototype <c>upPrice / upLocked</c> and the buy click).</summary>
    public sealed class UpgradeShop : IUpgradeShop
    {
        const string ShopPadId = "shop";

        readonly GameDatabase _db;
        readonly GameProgress _progress;
        readonly WorldStateSnapshot _state;

        public UpgradeShop(GameDatabase db, GameProgress progress, WorldStateSnapshot state)
        {
            _db = db;
            _progress = progress;
            _state = state;
        }

        public int GetLevel(string id) => _progress.GetUpgradeLevel(id);

        public int GetMaxLevel(string id) => _db.Upgrade(id).maxLevel;

        public long GetPrice(string id)
        {
            UpgradeDef u = _db.Upgrade(id);
            return _db.economy.UpgradePrice(u, _progress.GetUpgradeLevel(id));
        }

        public bool IsLocked(string id, out int needShopLevel, out bool needPlumbing) =>
            UpgradeRules.IsLocked(_db.Upgrade(id), _progress.GetLevel(ShopPadId), _state.OwnsPlumbing, out needShopLevel, out needPlumbing);

        public bool CanBuy(string id)
        {
            UpgradeDef u = _db.Upgrade(id);
            int level = _progress.GetUpgradeLevel(id);
            return level < u.maxLevel && !IsLocked(id, out _, out _) && _progress.Money >= _db.economy.UpgradePrice(u, level);
        }

        public bool TryBuy(string id)
        {
            if (!CanBuy(id) || !_progress.Spend(GetPrice(id))) return false;
            int level = _progress.GetUpgradeLevel(id) + 1;
            _progress.SetUpgradeLevel(id, level);
            GameEvents.RaiseUpgradeBought(id, level);
            return true;
        }
    }

    public static class UpgradeRules
    {
        /// <summary>Prototype <c>upLocked</c>: shop level below the requirement, or plumbing required and not owned.</summary>
        public static bool IsLocked(UpgradeDef u, int shopLevel, bool ownsPlumbing, out int needShopLevel, out bool needPlumbing)
        {
            needShopLevel = u.requiresShopLevel > 0 && shopLevel < u.requiresShopLevel ? u.requiresShopLevel : 0;
            needPlumbing = u.requiresPlumbing && !ownsPlumbing;
            return needShopLevel > 0 || needPlumbing;
        }
    }
}
