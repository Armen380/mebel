using UnityEngine;

namespace FF.Data
{
    /// <summary>Upgrades-panel row (player, workers, staff, business).</summary>
    [CreateAssetMenu(menuName = "FF/Upgrade", fileName = "Upgrade")]
    public sealed class UpgradeDef : ScriptableObject
    {
        public string id;
        public string groupKey;
        public int maxLevel;
        public long baseCost;
        public double costMultiplier;
        [Tooltip("0 = no shop-level requirement.")]
        public int requiresShopLevel;
        public bool requiresPlumbing;
    }
}
