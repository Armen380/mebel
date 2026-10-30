using FF.Data;
using FF.Editor;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class EconomyConfigTests
    {
        EconomyConfig _e;

        [SetUp]
        public void SetUp() => _e = ScriptableObject.CreateInstance<EconomyConfig>();

        [TearDown]
        public void TearDown() => Object.DestroyImmediate(_e);

        [TestCase(1, 13)] // round(12.5) = 13 in JS (C# would give 12)
        [TestCase(2, 17)]
        [TestCase(3, 22)] // round(21.5)
        [TestCase(10, 53)]
        [TestCase(149, 679)] // round(678.5)
        public void XpNeeded_UsesJsRounding(int level, int expected) => Assert.AreEqual(expected, _e.XpNeeded(level));

        [Test]
        public void XpToLevel150_IsAbout51K()
        {
            long total = 0;
            for (int l = 1; l < 150; l++) total += _e.XpNeeded(l);
            Assert.That(total, Is.InRange(51000, 52000));
        }

        [TestCase(500, 0, 430)]   // round(42.5)*10
        [TestCase(1500, 0, 1280)] // round(127.5)*10
        [TestCase(500, 1, 530)]
        [TestCase(24000, 8, 61200)]
        public void SalePrice_MatchesPrototype(int basePrice, int quality, long expected) =>
            Assert.AreEqual(expected, _e.SalePrice(basePrice, quality));

        [Test]
        public void PriceFormula_MatchesPadsJsonTable() => AssertCostTables((JArray)DataImporter.ReadObject("pads.json")["pads"], "maxLevel");

        [Test]
        public void PriceFormula_MatchesUpgradesJsonTable() => AssertCostTables(DataImporter.ReadArray("upgrades.json"), "max");

        // pads.json's informational tables were generated with banker's rounding; the prototype's
        // Math.round rounds these .5 ties up. The prototype wins (noted in PLAN.md).
        static readonly System.Collections.Generic.Dictionary<string, long> PrototypeOverrides =
            new System.Collections.Generic.Dictionary<string, long>
            {
                { "saw_speed:1", 2650 },
                { "chair_speed:1", 2650 },
                { "table_speed:2", 55150 },
            };

        static void AssertCostTables(JArray rows, string maxField)
        {
            foreach (JObject row in rows)
            {
                var table = (JArray)row["costPerLevel_beforeECON"];
                double mul = row["costMultiplier"]?.Type is JTokenType.Float or JTokenType.Integer ? (double)row["costMultiplier"] : 1;
                for (int lv = 0; lv < table.Count; lv++)
                {
                    long expected = PrototypeOverrides.TryGetValue($"{row["id"]}:{lv}", out long fixedValue) ? fixedValue : (long)table[lv];
                    Assert.AreEqual(expected, EconomyConfig.PriceFormula((long)row["baseCost"], 1, mul, lv), $"{row["id"]} lv {lv}");
                }
                Assert.AreEqual((int)row[maxField], table.Count, $"{row["id"]} table length");
            }
        }

        [Test]
        public void UpgradePrice_AppliesEconCost() => Assert.AreEqual(1900, _e.UpgradePrice(1500, 1.75, 0));

        [Test]
        public void PlayerAndFactoryFormulas()
        {
            Assert.AreEqual(4.4f, _e.PlayerSpeed(0), 1e-5f);
            Assert.AreEqual(4.4f * 1.72f, _e.PlayerSpeed(6), 1e-4f);
            Assert.AreEqual(5, _e.CarryCapacity(0));
            Assert.AreEqual(21, _e.CarryCapacity(8));
            Assert.AreEqual(1.1f / 3.1f, _e.ChopSeconds(6), 1e-5f);
            Assert.AreEqual(2.6f / 3.8f, _e.FactoryCycleSeconds(2.6f, 8), 1e-5f);
            Assert.AreEqual(1f + 1.8f + 0.8f, _e.StorageMultiplier(3, 8), 1e-5f);
            Assert.AreEqual(23, _e.ShelfCapacity(5));
            Assert.AreEqual(46f, _e.ShopWallX(5), 1e-4f);
            Assert.AreEqual(602, _e.TruckItemPayout(430));
        }
    }
}
