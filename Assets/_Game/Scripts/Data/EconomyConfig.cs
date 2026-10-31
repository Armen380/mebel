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
        [Tooltip("Chop when the nearest node is closer than this (prototype d2 < 1.6).")]
        public float chopRange = 1.6f;
        [Tooltip("Shake + chop SFX every this many seconds while chopping.")]
        public float chopHitInterval = 0.3f;

        [Header("Item flights (prototype sendTo / fly durations, sine arc height)")]
        public float transferFlightSeconds = 0.24f;
        public float chopFlightSeconds = 0.32f;
        [Tooltip("Chopped item i spawns at node + (0, base + i·step, 0).")]
        public float chopSpawnHeight = 1.1f;
        public float chopSpawnStep = 0.35f;
        public float machineInFlightSeconds = 0.3f;
        public float machineInFlightStep = 0.02f;
        public float machineInArc = 0.5f;
        public float machineOutFlightSeconds = 0.35f;
        public float machineOutFlightStep = 0.05f;
        public float flightArc = 1f;

        [Header("Throw (prototype throwAll)")]
        public float throwDistance = 1.5f;
        public float throwSpread = 1.2f;
        public float throwFlightSeconds = 0.3f;
        public float throwFlightStep = 0.03f;
        public float throwArc = 0.9f;
        public float throwLandHeight = 0.05f;
        [Tooltip("Thrown items shrink at this rate per second and vanish after shrinkSeconds.")]
        public float throwShrinkRate = 4f;
        public float throwShrinkSeconds = 0.25f;

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

        [Header("Customers (prototype spawnCustomer / updCustomers)")]
        [Tooltip("Spawn interval = max(min, base − perAds·ads − perShop·shopLv).")]
        public float customerSpawnBase = 5f;
        public float customerSpawnPerAds = 0.5f;
        public float customerSpawnPerShop = 0.3f;
        public float customerSpawnMin = 1.1f;
        public float customerFirstSpawn = 1.5f;
        [Tooltip("Walk-ins at once = base + ads + perShop·shopLv.")]
        public int maxWalkInsBase = 4;
        public int maxWalkInsPerShop = 2;
        public float customerWalkSpeed = 2.9f;
        public float customerPatience = 45f;
        public float consultantPatienceMultiplier = 1.6f;
        [Tooltip("The front customer waits this long at the shelf before taking an item.")]
        public float customerTakeDelay = 0.3f;
        public float customerTakeSeconds = 0.35f;
        public float customerTakeFlightSeconds = 0.3f;
        [Tooltip("With some items in hand and an empty shelf, go to the register after this many seconds.")]
        public float customerPartialWait = 5f;
        public float playerServeRate = 1.4f;
        public float cashierServeRate = 1f;
        public float robotServeRate = 1.7f;
        public float billFlightSeconds = 0.35f;
        public float billSpawnHeight = 1.4f;
        [Tooltip("Bubbles: cash icon after waiting at a register with nobody serving; product icon at an empty shelf.")]
        public float cashBubbleDelay = 1f;
        public float shelfBubbleDelay = 0.5f;

        [Header("Cash collection (player on a register cash zone)")]
        public float cashFlightSeconds = 0.22f;
        public float cashFlightArc = 0.6f;
        public float cashTargetHeight = 1.3f;

        [Header("Upgrade pads (prototype updPads)")]
        public float padStillSeconds = 0.3f;
        [Tooltip("A full price drains in this many seconds: amt = max(1, ⌈price·dt/payTime⌉).")]
        public float padPaySeconds = 1.4f;
        public float padBillInterval = 0.07f;
        public float padBillFlightSeconds = 0.25f;
        public float padBillArc = 0.6f;

        [Header("Floating texts")]
        public float floatTextRise = 1.4f;
        public float floatTextSeconds = 1f;

        [Header("Delivery")]
        public int truckOrderSize = 8;
        public float truckAwaySeconds = 10f;

        [Header("Resource nodes")]
        public float treeRegrowSeconds = 9f;
        public float clayRegrowSeconds = 12f;
        public float ironRegrowSeconds = 12f;
        [Tooltip("Chop time multiplier per node type (economy.json chopSeconds note).")]
        public float treeHardness = 1f;
        public float clayHardness = 1.5f;
        public float ironHardness = 1.8f;

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

        /// <summary>Machine pile capacity: round(base·capMul) (prototype capFn after setup).</summary>
        public int StorageCapacity(int baseCapacity, int qtyLevel, int speedLevel) =>
            (int)JsMath.RoundToLong(baseCapacity * (1 + (double)storagePerQtyLevel * qtyLevel + (double)storagePerSpeedLevel * speedLevel));

        public float CustomerSpawnInterval(int adsLevel, int shopLevel) =>
            Mathf.Max(customerSpawnMin, customerSpawnBase - customerSpawnPerAds * adsLevel - customerSpawnPerShop * shopLevel);

        public int MaxWalkIns(int adsLevel, int shopLevel) => maxWalkInsBase + adsLevel + maxWalkInsPerShop * shopLevel;

        public float CustomerPatience(int consultantLevel) =>
            customerPatience * (consultantLevel > 0 ? consultantPatienceMultiplier : 1f);

        /// <summary>Bill of one sale: round(salePrice·(1 + 0.15·consult)·n·(bulk ? 1.15 : 1)/10)·10.</summary>
        public long BillValue(long salePrice, int consultantLevel, int items, bool bulk) =>
            JsMath.RoundToLong(salePrice * (1 + consultantBonusPerLevel * consultantLevel) * items * (bulk ? 1.15 : 1) / 10) * 10;

        /// <summary>One frame of paying into a pad: min(money, remaining, max(1, ⌈price·dt/payTime⌉)).</summary>
        public long PadPayment(long money, long remaining, long price, float dt)
        {
            long rate = Math.Max(1L, (long)Math.Ceiling(price * (double)dt / padPaySeconds));
            return Math.Max(0L, Math.Min(money, Math.Min(remaining, rate)));
        }

        public int ShelfCapacity(int shopLevel) => shelfCapBase + shelfCapPerShopLevel * shopLevel;

        /// <summary>Prototype x of the shop's right wall at a shop level.</summary>
        public float ShopWallX(int shopLevel) => shopWallBaseX + shopWallPerLevel * shopLevel;
    }
}
