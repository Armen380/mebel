namespace FF.Core
{
    /// <summary>The Upgrades panel's view of the upgrades (prototype <c>UPG</c>, <c>upPrice</c>, <c>upLocked</c>, buy click).</summary>
    public interface IUpgradeShop
    {
        int GetLevel(string id);
        int GetMaxLevel(string id);
        /// <summary>Price of the next level.</summary>
        long GetPrice(string id);
        /// <summary>Locked by the shop level (needShopLevel &gt; 0) or by plumbing.</summary>
        bool IsLocked(string id, out int needShopLevel, out bool needPlumbing);
        /// <summary>Not locked, not maxed and affordable.</summary>
        bool CanBuy(string id);
        bool TryBuy(string id);
    }
}
