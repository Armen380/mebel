using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Production;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>Machines (prototype updMachine), chopping (tryChop) and resource nodes (updNode).</summary>
    public sealed class ProductionTests
    {
        readonly List<Object> _created = new List<Object>();
        EconomyConfig _economy;
        ItemCatalog _catalog;

        [SetUp]
        public void SetUp()
        {
            _economy = ScriptableObject.CreateInstance<EconomyConfig>();
            _catalog = ScriptableObject.CreateInstance<ItemCatalog>();
            _catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Log, stackHeight = 0.3f });
            _created.Add(_economy);
            _created.Add(_catalog);
        }

        [TearDown]
        public void TearDown()
        {
            foreach (Object o in _created) Object.DestroyImmediate(o);
            _created.Clear();
        }

        ItemStack Hands(int capacity)
        {
            var anchor = new GameObject("Hands");
            _created.Add(anchor);
            return new ItemStack(anchor.transform, CarryLayout.Instance, _catalog, () => capacity);
        }

        // ---------- machines ----------

        [Test]
        public void Sawmill_StartsOneBatchPerCycle_AtQuantityLevel0()
        {
            var saw = new MachineCore(1, 2);
            Assert.AreEqual(1, saw.BatchesAvailable(5, 0, 30, _economy.ParallelBatches(0)));
        }

        [Test]
        public void Batches_LimitedByQuantityLevelInputAndOutputRoom()
        {
            var saw = new MachineCore(1, 2);
            Assert.AreEqual(3, saw.BatchesAvailable(5, 0, 30, _economy.ParallelBatches(2)));
            Assert.AreEqual(2, saw.BatchesAvailable(2, 0, 30, 4), "input");
            Assert.AreEqual(1, saw.BatchesAvailable(5, 27, 30, 4), "output room ⌊3/2⌋");
            Assert.AreEqual(0, saw.BatchesAvailable(5, 29, 30, 4), "no room for two planks");
            Assert.AreEqual(0, saw.BatchesAvailable(5, 31, 30, 4), "over capacity");
        }

        [Test]
        public void ChairFactory_NeedsTwoPlanksPerChair()
        {
            var chair = new MachineCore(2, 1);
            Assert.AreEqual(0, chair.BatchesAvailable(1, 0, 12, 1));
            Assert.AreEqual(1, chair.BatchesAvailable(3, 0, 12, 1));
        }

        [Test]
        public void Cycle_SpawnsBatchTimesOutput_WhenTimeIsUp()
        {
            var saw = new MachineCore(1, 2);
            saw.Start(3);
            Assert.AreEqual(0, saw.BatchesAvailable(5, 0, 30, 4), "busy");
            float cycle = _economy.FactoryCycleSeconds(1.6f, 0);
            Assert.AreEqual(0, saw.Tick(1.5f, cycle));
            Assert.IsTrue(saw.Busy);
            Assert.AreEqual(6, saw.Tick(0.1f, cycle));
            Assert.IsFalse(saw.Busy);
            Assert.AreEqual(0, saw.Tick(1f, cycle));
        }

        [Test]
        public void CycleTime_ShrinksWithSpeedLevel()
        {
            Assert.AreEqual(1.6f, _economy.FactoryCycleSeconds(1.6f, 0), 1e-6f);
            Assert.AreEqual(1.6f / 1.35f, _economy.FactoryCycleSeconds(1.6f, 1), 1e-6f);
            Assert.AreEqual(2.6f / (1 + 0.35f * 8), _economy.FactoryCycleSeconds(2.6f, 8), 1e-6f);
        }

        [TestCase(24, 0, 0, 24)]
        [TestCase(24, 0, 1, 26)]  // 26.4
        [TestCase(24, 1, 0, 38)]  // 38.4
        [TestCase(30, 1, 1, 51)]
        [TestCase(24, 3, 7, 84)]  // screenshot 06 "0/84"
        [TestCase(12, 3, 8, 43)]  // screenshot 06 "0/43" (43.2)
        public void StorageCapacity_IsRoundedBaseTimesMultiplier(int baseCap, int qty, int speed, int expected)
        {
            Assert.AreEqual(expected, _economy.StorageCapacity(baseCap, qty, speed));
        }

        // ---------- chopping ----------

        static ResourceNodeState Tree() => new ResourceNodeState(ItemType.Log, 1f, 9f);

        [Test]
        public void Chop_FellsTreeAfterChopTime_AndYieldsTwoLogs()
        {
            var chopper = new Chopper();
            ResourceNodeState tree = Tree();
            ItemStack hands = Hands(5);
            float chop = _economy.ChopSeconds(0);
            Chopper.Result r = default;
            int frames = 0;
            while (tree.Alive && frames++ < 1000) r = chopper.TryChop(tree, hands, 0.01f, 1f, chop, 0.3f, 2);
            Assert.That(frames * 0.01f, Is.EqualTo(1.1f).Within(0.011f));
            Assert.AreEqual(2, r.Yield);
            Assert.IsTrue(r.Chopping);
            Assert.AreEqual(0f, chopper.Progress);
        }

        [Test]
        public void Chop_YieldIsLimitedByRoomInHands()
        {
            var chopper = new Chopper();
            ItemStack hands = Hands(5);
            for (int i = 0; i < 4; i++) hands.BeginIncoming(ItemType.Log);
            Chopper.Result r = chopper.TryChop(Tree(), hands, 2f, 1f, 1.1f, 0.3f, 2);
            Assert.AreEqual(1, r.Yield);
        }

        [Test]
        public void Chop_RefusesFullHandsOrOtherItems()
        {
            var chopper = new Chopper();
            ItemStack full = Hands(1);
            full.BeginIncoming(ItemType.Log);
            Assert.IsFalse(chopper.TryChop(Tree(), full, 0.1f, 1f, 1.1f, 0.3f, 2).Chopping);

            ItemStack planks = Hands(5);
            planks.BeginIncoming(ItemType.Plank);
            Assert.IsFalse(chopper.TryChop(Tree(), planks, 0.1f, 1f, 1.1f, 0.3f, 2).Chopping);
        }

        [Test]
        public void Chop_HitsEveryThreeTenths_AndHardnessSlowsIt()
        {
            var chopper = new Chopper();
            var rock = new ResourceNodeState(ItemType.Clay, 1.5f, 12f, true);
            ItemStack hands = Hands(5);
            int hits = 0, frames = 0;
            while (rock.Alive && frames++ < 1000)
                if (chopper.TryChop(rock, hands, 0.01f, 1f, 1.1f, 0.3f, 2).Hit) hits++;
            Assert.That(frames * 0.01f, Is.EqualTo(1.65f).Within(0.011f));
            Assert.AreEqual(5, hits);
        }

        [Test]
        public void Chop_ProgressCarriesOverToAnotherTree_LikeThePrototype()
        {
            var chopper = new Chopper();
            ItemStack hands = Hands(5);
            chopper.TryChop(Tree(), hands, 1.0f, 1f, 1.1f, 0.3f, 2);
            ResourceNodeState second = Tree();
            chopper.TryChop(second, hands, 0.2f, 1f, 1.1f, 0.3f, 2);
            Assert.IsFalse(second.Alive);
        }

        // ---------- node regrow ----------

        [Test]
        public void Node_FallsRegrowsAndScalesBackIn()
        {
            ResourceNodeState tree = Tree();
            tree.ReservedBy = this;
            tree.Fell();
            Assert.IsFalse(tree.Alive);
            Assert.IsNull(tree.ReservedBy);
            Assert.IsTrue(tree.TopVisible);

            tree.Tick(0.4f);
            Assert.AreEqual(1f, tree.Fall);
            Assert.IsFalse(tree.TopVisible);

            float t = 0.4f;
            while (!tree.Alive && t < 20f)
            {
                tree.Tick(0.01f);
                t += 0.01f;
            }
            Assert.That(t, Is.EqualTo(9f).Within(0.02f), "regrow time");
            Assert.That(tree.Grow, Is.LessThan(0.05f));
            Assert.That(tree.GrowScale, Is.LessThan(0.2f));

            tree.Tick(0.6f);
            Assert.AreEqual(1f, tree.Grow);
            Assert.AreEqual(1f, tree.GrowScale, 1e-6f);
        }

        [Test]
        public void Node_ShakeDecays()
        {
            ResourceNodeState tree = Tree();
            tree.Hit();
            Assert.AreEqual(1f, tree.Shake);
            tree.Tick(0.125f);
            Assert.AreEqual(0.5f, tree.Shake, 1e-5f);
            tree.Tick(1f);
            Assert.AreEqual(0f, tree.Shake);
        }
    }
}
