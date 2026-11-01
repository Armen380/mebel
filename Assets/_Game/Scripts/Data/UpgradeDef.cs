using UnityEngine;

namespace FF.Data
{
    /// <summary>How an upgrade's current value is written in the panel (prototype <c>UPG[i].val</c>).</summary>
    public enum UpgradeValueFormat
    {
        /// <summary>u.items: carry capacity 5 + 2·lv.</summary>
        Items,
        /// <summary>100 + 12·lv %: walk speed.</summary>
        SpeedPercent,
        /// <summary>u.sec: chop time 1.1/(1 + 0.35·lv), 2 decimals.</summary>
        Seconds,
        /// <summary>u.people: lv.</summary>
        People,
        /// <summary>u.bots: lv.</summary>
        Bots,
        /// <summary>u.price: +15·lv %.</summary>
        PriceBonus,
        /// <summary>u.cust: +lv (0 when none).</summary>
        Customers,
        /// <summary>+25·lv %: product quality.</summary>
        QualityPercent,
    }

    /// <summary>Upgrades-panel row (player, workers, staff, business).</summary>
    [CreateAssetMenu(menuName = "FF/Upgrade", fileName = "Upgrade")]
    public sealed class UpgradeDef : ScriptableObject
    {
        public string id;
        public string groupKey;
        public string nameKey;
        public string descriptionKey;
        public UpgradeValueFormat valueFormat;
        public int maxLevel;
        public long baseCost;
        public double costMultiplier;
        [Tooltip("0 = no shop-level requirement.")]
        public int requiresShopLevel;
        public bool requiresPlumbing;
    }
}
