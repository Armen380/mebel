using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Progress;
using FF.Gameplay.Shop;
using FF.Gameplay.Tutorial;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M3: money / XP (addMoney, addXP), customer numbers, queue slots, pad payment and tutorial matching.</summary>
    public sealed class ShopTests
    {
        EconomyConfig _economy;
        WorldLayout _world;

        [SetUp]
        public void SetUp()
        {
            GameEvents.Reset();
            _economy = ScriptableObject.CreateInstance<EconomyConfig>();
            _world = ScriptableObject.CreateInstance<WorldLayout>();
        }

        [TearDown]
        public void TearDown()
        {
            Object.DestroyImmediate(_economy);
            Object.DestroyImmediate(_world);
            GameEvents.Reset();
        }

        // ---------- progress ----------

        [Test]
        public void FiveChairSales_RaiseLevelTwo_WithRemainder()
        {
            var p = new GameProgress(_economy);
            int levelUps = 0;
            GameEvents.LevelUp += _ => levelUps++;
            for (int i = 0; i < 5; i++) p.AddXp(3);
            Assert.AreEqual(2, p.Level);
            Assert.AreEqual(2, p.Xp, "15 − xpNeed(1) = 15 − 13");
            Assert.AreEqual(17, p.XpNeeded, "round(8 + 4.5·2)");
            Assert.AreEqual(1, levelUps);
        }

        [Test]
        public void BigXpGain_RaisesSeveralLevels()
        {
            int xp = 0, level = 1;
            // 13 + 17 + 22 (round(21.5)) = 52
            int gained = LevelMath.AddXp(ref xp, ref level, 53, _economy);
            Assert.AreEqual(3, gained);
            Assert.AreEqual(4, level);
            Assert.AreEqual(1, xp);
        }

        [Test]
        public void Money_AddCountsTotal_SpendNeverGoesNegative()
        {
            var p = new GameProgress(_economy);
            bool bumped = false;
            GameEvents.MoneyChanged += (m, bump) => bumped = bump;
            p.AddMoney(430);
            Assert.IsTrue(bumped);
            Assert.IsFalse(p.Spend(500));
            Assert.IsTrue(p.Spend(400));
            Assert.IsFalse(bumped, "payments do not bump the counter");
            Assert.AreEqual(30, p.Money);
            Assert.AreEqual(430, p.TotalEarned);
        }

        [Test]
        public void Levels_ComeFromPadsThenUpgrades()
        {
            var p = new GameProgress(_economy);
            p.Pad("saw_speed").Level = 2;
            p.SetUpgradeLevel("cap", 3);
            Assert.AreEqual(2, p.GetLevel("saw_speed"));
            Assert.AreEqual(3, p.GetLevel("cap"));
            Assert.AreEqual(0, p.GetLevel("ads"));
        }

        // ---------- customers ----------

        [TestCase(0, 0, 5f)]
        [TestCase(3, 5, 2f)]
        [TestCase(10, 5, 1.1f)]
        public void SpawnInterval(int ads, int shop, float expected) =>
            Assert.AreEqual(expected, _economy.CustomerSpawnInterval(ads, shop), 1e-5f);

        [Test]
        public void WalkInLimit_AndPatience()
        {
            Assert.AreEqual(4, _economy.MaxWalkIns(0, 0));
            Assert.AreEqual(9, _economy.MaxWalkIns(1, 2));
            Assert.AreEqual(45f, _economy.CustomerPatience(0));
            Assert.AreEqual(72f, _economy.CustomerPatience(1), 1e-4f);
        }

        [Test]
        public void ChairSale_Is430_AndBillFormula()
        {
            long chair = _economy.SalePrice(500, 0);
            Assert.AreEqual(430, chair);
            Assert.AreEqual(430, _economy.BillValue(chair, 0, 1, false));
            Assert.AreEqual(490, _economy.BillValue(chair, 1, 1, false), "494.5 → round(49.45)·10");
            Assert.AreEqual(1480, _economy.BillValue(chair, 0, 3, true), "1483.5 → 1480");
        }

        [Test]
        public void ShelfQueue_FrontCentred_OthersAlternate()
        {
            WorldLayout.MainShopSettings s = _world.mainShop;
            Vector3 zone = ProtoCoords.ToUnity(4.6f, 3.3f);
            AssertNear(ProtoCoords.ToUnity(4.6f, 4.75f), CustomerQueues.ShelfSlot(zone, 0, s));
            AssertNear(ProtoCoords.ToUnity(4.95f, 5.6f), CustomerQueues.ShelfSlot(zone, 1, s));
            AssertNear(ProtoCoords.ToUnity(4.25f, 6.45f), CustomerQueues.ShelfSlot(zone, 2, s));
        }

        [Test]
        public void RegisterQueue_BesideTheCounter()
        {
            WorldLayout.MainShopSettings s = _world.mainShop;
            Vector3 reg = ProtoCoords.ToUnity(22.2f, 3.5f);
            AssertNear(ProtoCoords.ToUnity(23.45f, 3f), CustomerQueues.RegisterSlot(reg, 0, s));
            AssertNear(ProtoCoords.ToUnity(23.45f, 4.05f), CustomerQueues.RegisterSlot(reg, 1, s));
            AssertNear(ProtoCoords.ToUnity(23.45f, 6.6f), CustomerQueues.RegisterApproach(reg, s));
        }

        [Test]
        public void LeastBusyRegister_TiesGoToTheFirst()
        {
            int[] load = { 2, 1, 1, 0 };
            Assert.AreEqual(1, CustomerQueues.LeastBusy(new[] { 0, 1, 2 }, load));
            Assert.AreEqual(3, CustomerQueues.LeastBusy(new[] { 0, 1, 2, 3 }, load));
            Assert.AreEqual(-1, CustomerQueues.LeastBusy(new int[0], load));
        }

        // ---------- pads ----------

        [Test]
        public void PadPayment_DrainsPriceIn1_4Seconds()
        {
            Assert.AreEqual(22, _economy.PadPayment(10_000, 1900, 1900, 0.016f), "⌈1900·0.016/1.4⌉");
            Assert.AreEqual(5, _economy.PadPayment(5, 1900, 1900, 0.016f), "limited by money");
            Assert.AreEqual(3, _economy.PadPayment(10_000, 3, 1900, 0.016f), "limited by the remaining price");
            Assert.AreEqual(1, _economy.PadPayment(10_000, 100, 10, 0.001f), "at least 1");
        }

        [Test]
        public void SawSpeedPad_Costs1900Then3300()
        {
            var pad = ScriptableObject.CreateInstance<PadDef>();
            pad.baseCost = 1500;
            pad.costMultiplier = 1.75;
            Assert.AreEqual(1900, _economy.PadPrice(pad, 0));
            Assert.AreEqual(3300, _economy.PadPrice(pad, 1));
            Object.DestroyImmediate(pad);
        }

        // ---------- tutorial ----------

        [Test]
        public void TutorialSteps_ParsedFromDesignSentences()
        {
            var drop = new TutorialDef.Step { completeOn = "drop chairs on shelf_chair", arrowTarget = "shelf_chair zone" };
            DataImporter.ParseTutorialStep(drop);
            Assert.AreEqual(TutorialTrigger.Drop, drop.trigger);
            Assert.AreEqual("shelf_chair", drop.triggerId);
            Assert.AreEqual(TutorialTarget.Zone, drop.target);

            var pick = new TutorialDef.Step { completeOn = "pick planks from sawOut", arrowTarget = "sawOut zone" };
            DataImporter.ParseTutorialStep(pick);
            Assert.AreEqual("saw_out", pick.triggerId);
            Assert.AreEqual("saw_out", pick.targetId);

            var pad = new TutorialDef.Step { completeOn = "complete any upgrade pad", arrowTarget = "saw_speed pad" };
            DataImporter.ParseTutorialStep(pad);
            Assert.AreEqual(TutorialTrigger.Pad, pad.trigger);
            Assert.AreEqual(TutorialTarget.Pad, pad.target);
            Assert.AreEqual("saw_speed", pad.targetId);

            Assert.AreEqual("chair_in", DataImporter.ZoneId("in_chair"));
            Assert.AreEqual("chair_out", DataImporter.ZoneId("out_chair"));
        }

        [Test]
        public void TutorialRules_NeedSameEventAndZone()
        {
            var step = new TutorialDef.Step { trigger = TutorialTrigger.Drop, triggerId = "saw_in" };
            Assert.IsTrue(TutorialRules.Matches(step, TutorialTrigger.Drop, "saw_in"));
            Assert.IsFalse(TutorialRules.Matches(step, TutorialTrigger.Drop, "chair_in"));
            Assert.IsFalse(TutorialRules.Matches(step, TutorialTrigger.Pick, "saw_in"));
            var anyPad = new TutorialDef.Step { trigger = TutorialTrigger.Pad, triggerId = "" };
            Assert.IsTrue(TutorialRules.Matches(anyPad, TutorialTrigger.Pad, "chair_qty"));
        }

        // ---------- number format change key ----------

        [Test]
        public void CompactChangeKey_EqualKeysMeanEqualText()
        {
            CheckRange(0, 120_000);
            CheckRange(990_000, 1_060_000);
            CheckRange(9_990_000, 10_120_000);
        }

        static void CheckRange(long from, long to)
        {
            string prevText = NumberFormat.Compact(from);
            long prevKey = NumberFormat.CompactChangeKey(from);
            for (long n = from + 1; n <= to; n++)
            {
                long key = NumberFormat.CompactChangeKey(n);
                if (key == prevKey)
                {
                    string text = NumberFormat.Compact(n);
                    if (text != prevText) Assert.Fail($"Key {key} covers both {n - 1} ('{prevText}') and {n} ('{text}').");
                    continue;
                }
                prevKey = key;
                prevText = NumberFormat.Compact(n);
            }
        }

        static void AssertNear(Vector3 expected, Vector3 actual) =>
            Assert.That(Vector3.Distance(expected, actual), Is.LessThan(1e-4f), $"expected {expected}, got {actual}");
    }
}
