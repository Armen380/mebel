using System;
using FF.Core;
using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// All economy numbers and the prototype formulas (Design/data/economy.json, prototype <c>ECON</c>, <c>st</c>,
    /// <c>xpNeed</c>, <c>upPrice</c>, <c>capMul</c>, <c>shopW</c>, <c>shopCap</c>). Defaults equal the prototype;
    /// the importer overwrites the values that economy.json carries as plain numbers.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Economy Config", fileName = "EconomyConfig")]
    public sealed class EconomyConfig : ScriptableObject
    {
        [Header("ECON multipliers")]
        public double priceMultiplier = 0.85;
        public double costMultiplier = 1.25;
        public double truckMultiplier = 1.4;

        [Header("Levels: xp(level) = round(base + perLevel*level)")]
        public double xpBase = 8;
        public double xpPerLevel = 4.5;

        [Header("Sale price")]
        public double qualityBonusPerLevel = 0.25;
        public double consultantBonusPerLevel = 0.15;

        [Header("Player")]
        public float playerBaseSpeed = 4.4f;
        public float playerSpeedPerLevel = 0.12f;
        public int carryCapacityBase = 5;
        public int carryCapacityPerLevel = 2;
        public float chopSecondsBase = 1.1f;
        public float axeSpeedPerLevel = 0.35f;
        public int itemsPerChop = 2;
        public float transferInterval = 0.075f;
        public float cashTransferInterval = 0.035f;
        public float zoneRadius = 1.3f;
        public float padRadius = 0.95f;

        [Header("Factories")]
        public float factorySpeedPerLevel = 0.35f;
        public float storagePerQtyLevel = 0.6f;
        public float storagePerSpeedLevel = 0.1f;
        public float sawmillCycleSeconds = 1.6f;
        public int sawmillLogsIn = 1;
        public int sawmillPlanksOut = 2;
        public int sawmillInStorage = 24;
        public int sawmillOutStorage = 30;
        public int plankFactoryInStorage = 24;
        public int plankFactoryOutStorage = 12;
        public int mineFactoryInStorage = 16;
        public int mineFactoryOutStorage = 12;

        [Header("Shop")]
        public int shelfCapBase = 8;
        public int shelfCapPerShopLevel = 3;
        public float shopWallBaseX = 25f;
        public float shopWallPerLevel = 4.2f;
        public float serveSeconds = 0.9f;

        [Header("Delivery")]
        public int truckOrderSize = 8;
        public float truckAwaySeconds = 10f;

        [Header("Resource nodes")]
        public float treeRegrowSeconds = 9f;
        public float clayRegrowSeconds = 12f;
        public float ironRegrowSeconds = 12f;

        // ---------- formulas ----------

        public int XpNeeded(int level) => (int)JsMath.Round(xpBase + xpPerLevel * level);

        /// <summary>round(base·ECON.price·(1+0.25·quality)/10)·10.</summary>
        public long SalePrice(int basePrice, int qualityLevel) =>
            JsMath.RoundToLong(basePrice * priceMultiplier * (1 + qualityBonusPerLevel * qualityLevel) / 10) * 10;

        /// <summary>Panel upgrades and ground pads share the prototype price: round(base·ECON.cost·mul^lv/50)·50.</summary>
        public long UpgradePrice(long baseCost, double multiplier, int level) =>
            PriceFormula(baseCost, costMultiplier, multiplier, level);

        public long UpgradePrice(UpgradeDef u, int level) => UpgradePrice(u.baseCost, u.costMultiplier, level);

        public long PadPrice(PadDef p, int level) => UpgradePrice(p.baseCost, p.costMultiplier, level);

        /// <summary>round(base·econ·mul^lv/50)·50 — evaluated in the same order as the prototype.</summary>
        public static long PriceFormula(long baseCost, double econCost, double multiplier, int level) =>
            JsMath.RoundToLong(baseCost * econCost * Math.Pow(multiplier, level) / 50) * 50;

        public long TruckItemPayout(long salePrice) => JsMath.RoundToLong(salePrice * truckMultiplier);

        public float PlayerSpeed(int speedLevel) => playerBaseSpeed * (1 + playerSpeedPerLevel * speedLevel);

        public int CarryCapacity(int capLevel) => carryCapacityBase + carryCapacityPerLevel * capLevel;

        public float ChopSeconds(int axeLevel) => chopSecondsBase / (1 + axeSpeedPerLevel * axeLevel);

        public float FactoryCycleSeconds(float baseCycle, int speedLevel) => baseCycle / (1 + factorySpeedPerLevel * speedLevel);

        public int ParallelBatches(int qtyLevel) => 1 + qtyLevel;

        public float StorageMultiplier(int qtyLevel, int speedLevel) =>
            1 + storagePerQtyLevel * qtyLevel + storagePerSpeedLevel * speedLevel;

        public int ShelfCapacity(int shopLevel) => shelfCapBase + shelfCapPerShopLevel * shopLevel;

        /// <summary>Prototype x of the shop's right wall at a shop level.</summary>
        public float ShopWallX(int shopLevel) => shopWallBaseX + shopWallPerLevel * shopLevel;
    }
}
