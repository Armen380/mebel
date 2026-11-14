using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Delivery;
using FF.Gameplay.Items;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using FF.Save;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M7: truck states and timings (prototype updTrucks), bays, bay chip, payout, docks and the cargo save.</summary>
    public sealed class DeliveryTests
    {
        const float Dt = 0.05f;

        readonly List<Object> _created = new List<Object>();
        GameDatabase _db;
        EconomyConfig _e;
        WorldLayout.DeliverySettings _d;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        [SetUp]
        public void SetUp()
        {
            _e = ScriptableObject.CreateInstance<EconomyConfig>();
            var w = ScriptableObject.CreateInstance<WorldLayout>();
            _d = w.delivery;
            _created.Add(_e);
            _created.Add(w);
        }

        [TearDown]
        public void TearDown()
        {
            foreach (Object o in _created) Object.DestroyImmediate(o);
            _created.Clear();
        }

        /// <summary>Steps until the phase changes; returns the seconds it took.</summary>
        float RunPhase(TruckMotion t, float bayX, int loaded, out TruckEvent last, int maxSteps = 10000)
        {
            TruckPhase phase = t.Phase;
            last = TruckEvent.None;
            for (int i = 1; i <= maxSteps; i++)
            {
                last = t.Step(Dt, bayX, loaded, _e, _d);
                if (t.Phase != phase) return i * Dt;
            }
            Assert.Fail($"stuck in {phase}");
            return 0f;
        }

        // ---------- truck cycle ----------

        [Test]
        public void Truck_DrivesInParksLoadsAndLeaves()
        {
            var t = new TruckMotion();
            Assert.IsTrue(t.CanDispatch, "a new truck comes at once (prototype t = 0)");
            float bayX = _d.baysX[1];
            t.Dispatch(1, _d);
            Assert.AreEqual(-80f, t.X);
            Assert.AreEqual(14.6f, t.Z, 1e-5f);

            RunPhase(t, bayX, 0, out _);
            Assert.AreEqual(TruckPhase.Parking, t.Phase);
            Assert.AreEqual(bayX, t.X, 1e-5f, "stops exactly at the bay");

            float park = RunPhase(t, bayX, 0, out TruckEvent docked);
            Assert.AreEqual(TruckEvent.Docked, docked);
            Assert.AreEqual(12.3f, t.Z, 1e-5f);
            Assert.AreEqual(2.3f / 3f, park, Dt + 1e-4f, "sideways at 3 m/s from the lane to z 12.3");

            for (int i = 0; i < 200; i++) Assert.AreEqual(TruckEvent.None, t.Step(Dt, bayX, 7, _e, _d), "7 of 8: keeps waiting");
            Assert.AreEqual(TruckPhase.Docked, t.Phase);

            float wait = RunPhase(t, bayX, 8, out TruckEvent full);
            Assert.AreEqual(TruckEvent.Full, full);
            Assert.That(wait, Is.GreaterThanOrEqualTo(0.6f - 1e-4f).And.LessThanOrEqualTo(0.6f + 2 * Dt), "0.6 s after the order is full");
            Assert.AreEqual(1, t.Bay, "still holds the bay while pulling out");

            RunPhase(t, bayX, 8, out TruckEvent left);
            Assert.AreEqual(TruckEvent.LeftBay, left);
            Assert.AreEqual(-1, t.Bay);
            Assert.AreEqual(TruckPhase.Departing, t.Phase);

            RunPhase(t, bayX, 8, out TruckEvent delivered);
            Assert.AreEqual(TruckEvent.Delivered, delivered);
            Assert.That(t.X, Is.GreaterThan(80f));
            Assert.AreEqual(TruckPhase.Away, t.Phase);
            Assert.AreEqual(10f, t.Timer, 1e-5f);
            Assert.IsFalse(t.CanDispatch);
            for (int i = 0; i < 201; i++) t.Step(Dt, bayX, 0, _e, _d); // the away timer only counts down
            Assert.AreEqual(TruckPhase.Away, t.Phase, "an away truck waits for the director to dispatch it");
            Assert.IsTrue(t.CanDispatch, "back after 10 s");
        }

        [Test]
        public void Truck_SlowsDownNearTheBay()
        {
            var t = new TruckMotion();
            t.Dispatch(0, _d);
            t.X = -5f; // 1 m before bay 0: clamp(1 · 1.6, 3, 18) = 3 m/s
            t.Step(0.1f, -4f, 0, _e, _d);
            Assert.AreEqual(-4.7f, t.X, 1e-5f);
            t.X = -60f; // far: 18 m/s
            t.Step(0.1f, -4f, 0, _e, _d);
            Assert.AreEqual(-58.2f, t.X, 1e-4f);
            Assert.That(t.WheelTurn, Is.GreaterThan(0f), "wheels roll forward");
        }

        [Test]
        public void Truck_DepartAcceleratesToTopSpeed()
        {
            var t = new TruckMotion { Phase = TruckPhase.Departing, X = 0f, Z = 14.6f };
            for (int i = 0; i < 100; i++) t.Step(Dt, 0f, 0, _e, _d);
            Assert.AreEqual(18f, t.Speed, 1e-4f, "9 m/s² up to 18 m/s");
        }

        [Test]
        public void Truck_RestoredFromSaveStandsAtItsBay()
        {
            var t = new TruckMotion();
            t.DockAt(2, -14.4f, _d);
            Assert.AreEqual(TruckPhase.Docked, t.Phase);
            Assert.AreEqual(2, t.Bay);
            Assert.AreEqual(-14.4f, t.X);
            Assert.AreEqual(12.3f, t.Z, 1e-5f);
        }

        // ---------- bays ----------

        [Test]
        public void Bays_OpenWithTheParkingPad()
        {
            Assert.AreEqual(1, EconomyConfig.ActiveBays(0, 3));
            Assert.AreEqual(2, EconomyConfig.ActiveBays(1, 3));
            Assert.AreEqual(3, EconomyConfig.ActiveBays(2, 3));
            Assert.AreEqual(3, EconomyConfig.ActiveBays(9, 3));
        }

        [Test]
        public void FreeBay_IsTheFirstOpenBayWithoutATruck()
        {
            var a = new TruckMotion();
            var bays = new List<TruckMotion> { null, null, null };
            Assert.AreEqual(0, DeliveryRules.FreeBay(bays, 1));
            bays[0] = a;
            Assert.AreEqual(-1, DeliveryRules.FreeBay(bays, 1), "the second bay is not bought");
            Assert.AreEqual(1, DeliveryRules.FreeBay(bays, 3));
        }

        [Test]
        public void BayTag_FollowsThePrototypeChip()
        {
            var none = new List<TruckMotion>();
            Assert.AreEqual(BayTagKind.NoTruck, DeliveryRules.BayTag(0, true, null, none, out _));
            Assert.AreEqual(BayTagKind.Hidden, DeliveryRules.BayTag(1, true, null, none, out _), "only bay 0 says 'No truck'");
            Assert.AreEqual(BayTagKind.Hidden, DeliveryRules.BayTag(0, false, null, none, out _));

            var t = new TruckMotion();
            var trucks = new List<TruckMotion> { t };
            t.Dispatch(0, _d);
            Assert.AreEqual(BayTagKind.Arriving, DeliveryRules.BayTag(0, true, t, trucks, out _));
            t.DockAt(0, -4f, _d);
            Assert.AreEqual(BayTagKind.Load, DeliveryRules.BayTag(0, true, t, trucks, out _));

            t.Phase = TruckPhase.Away;
            t.Timer = 6.2f;
            Assert.AreEqual(BayTagKind.FreeIn, DeliveryRules.BayTag(0, true, null, trucks, out int s));
            Assert.AreEqual(7, s, "ceil");
            t.Timer = -3f;
            DeliveryRules.BayTag(0, true, null, trucks, out s);
            Assert.AreEqual(0, s, "never below 0");
            t.Phase = TruckPhase.Departing;
            Assert.AreEqual(BayTagKind.Free, DeliveryRules.BayTag(1, true, null, trucks, out _));
        }

        // ---------- payout ----------

        [Test]
        public void Payout_IsSalePriceTimes1_4PerItem()
        {
            ProductDef chair = _db.Product("chair");
            var cargo = new List<ProductDef>();
            for (int i = 0; i < 8; i++) cargo.Add(chair);
            // chair sale price round(500·0.85/10)·10 = 430 → round(430·1.4) = 602 per item
            Assert.AreEqual(8 * 602, DeliveryRules.Payout(cargo, _db.economy, 0));
            Assert.AreEqual(8 * chair.xpPerSale, DeliveryRules.PayoutXp(cargo));
            // quality 1: round(500·0.85·1.25/10)·10 = 530 → 742
            Assert.AreEqual(8 * 742, DeliveryRules.Payout(cargo, _db.economy, 1));
        }

        [Test]
        public void TruckPayout_UsesHomeMultiplier()
        {
            ProductDef chair = _db.Product("chair");
            var cargo = new List<ProductDef> { chair, chair };
            // +20 % comfort: round(500·0.85·1.2/10)·10 = 510 → round(510·1.4) = 714 per item
            Assert.AreEqual(2 * 714, DeliveryRules.Payout(cargo, _db.economy, 0, 1.2));
            Assert.AreEqual(2 * 602, DeliveryRules.Payout(cargo, _db.economy, 0, 1.0));
        }

        // ---------- docks ----------

        [Test]
        public void Dock_TakesAnyFurnitureOnlyWhileATruckLendsItsBed()
        {
            var catalog = ScriptableObject.CreateInstance<ItemCatalog>();
            catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Chair, stackHeight = 0.5f });
            catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Sofa, stackHeight = 0.5f });
            _created.Add(catalog);
            var go = new GameObject("Dock");
            _created.Add(go);
            var marker = new GameObject("Marker");
            marker.transform.SetParent(go.transform);
            Zone dock = go.AddComponent<Zone>();
            dock.Setup("dock0", ZoneKind.Drop, ItemType.None, go.transform, marker);
            dock.SetupAnyProduct();
            dock.Configure(new PileLayout(2, 4, 0.66f, 0.64f), () => 0, null, catalog, 1.3f, 0f);

            Assert.IsTrue(dock.Accepts(ItemType.Chair));
            Assert.IsTrue(dock.Accepts(ItemType.Kitchen));
            Assert.IsFalse(dock.Accepts(ItemType.Plank));
            Assert.IsFalse(dock.Accepts(ItemType.Bill));

            ItemStack hands = Stack(go.transform, catalog, 5);
            hands.BeginIncoming(ItemType.Sofa);
            hands.CompleteIncoming(NewItem(ItemType.Sofa));
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, dock), "no truck: no room");

            bool docked = true;
            ItemStack bed = Stack(go.transform, catalog, 8, () => docked);
            dock.UsePile(bed);
            Assert.IsTrue(ZoneTransferRules.CanDrop(hands, dock));
            docked = false;
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, dock), "pulling out: closed");
            dock.UsePile(null);
            Assert.AreNotSame(bed, dock.Stack);
        }

        ItemStack Stack(Transform anchor, ItemCatalog catalog, int capacity, System.Func<bool> open = null) =>
            new ItemStack(anchor, CarryLayout.Instance, catalog, () => open == null || open() ? capacity : 0);

        Item NewItem(ItemType type)
        {
            var go = new GameObject(type.ToString());
            _created.Add(go);
            Item item = go.AddComponent<Item>();
            item.SetType(type);
            return item;
        }

        // ---------- save ----------

        [Test]
        public void Save_KeepsWhatLiesOnEachTruck()
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            var cargo = new DeliveryCargo();
            cargo.Of(0).AddRange(new[] { ItemType.Chair, ItemType.Sofa, ItemType.Chair });
            cargo.Of(2).Add(ItemType.Table);

            SaveData data = SaveSerializer.FromJson(SaveSerializer.ToJson(SaveMapper.Capture(progress, state, cargo, "en")));
            Assert.AreEqual(SaveData.CurrentVersion, data.version);

            var loaded = new DeliveryCargo();
            SaveMapper.Apply(data, new GameProgress(_db.economy), WorldStateSnapshot.NewGame(_db.products), loaded);
            Assert.AreEqual(3, loaded.Loads.Count);
            CollectionAssert.AreEqual(new[] { ItemType.Chair, ItemType.Sofa, ItemType.Chair }, loaded.Loads[0]);
            Assert.IsEmpty(loaded.Loads[1]);
            CollectionAssert.AreEqual(new[] { ItemType.Table }, loaded.Loads[2]);
        }

        [Test]
        public void Save_OlderFilesAndUnknownItemsGiveEmptyTrucks()
        {
            var cargo = new DeliveryCargo();
            SaveMapper.Apply(SaveSerializer.FromJson("{\"version\":3,\"money\":5}"), new GameProgress(_db.economy),
                WorldStateSnapshot.NewGame(_db.products), cargo);
            Assert.IsEmpty(cargo.Loads);

            SaveMapper.Apply(SaveSerializer.FromJson("{\"version\":4,\"trucks\":[[\"Chair\",\"Plank\",\"Bogus\"]]}"),
                new GameProgress(_db.economy), WorldStateSnapshot.NewGame(_db.products), cargo);
            CollectionAssert.AreEqual(new[] { ItemType.Chair }, cargo.Loads[0], "only furniture is kept");
        }

        [Test]
        public void Events_ResetClearsTruckDelivered()
        {
            long got = 0;
            GameEvents.TruckDelivered += v => got = v;
            GameEvents.RaiseTruckDelivered(12);
            Assert.AreEqual(12, got);
            GameEvents.Reset();
            GameEvents.RaiseTruckDelivered(99);
            Assert.AreEqual(12, got);
        }
    }
}
