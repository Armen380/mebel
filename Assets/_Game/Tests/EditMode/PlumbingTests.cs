using System.Collections.Generic;
using FF.AI;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Progress;
using FF.Gameplay.Unlocks;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using FF.Save;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M8: Plumbing ownership, the materials shop, rocks, section workers and their unlock cards.</summary>
    public sealed class PlumbingTests
    {
        sealed class Pile : IPile
        {
            public int Count { get; set; }
            public int Settled { get; set; }
            public int Capacity { get; set; } = 10;
            public bool IsActive { get; set; } = true;
            public ItemType ItemType { get; set; }
            public Vector3 Position { get; set; }

            public Pile(ItemType type, int count, int capacity = 10)
            {
                ItemType = type;
                Count = Settled = count;
                Capacity = capacity;
            }
        }

        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        [TearDown]
        public void ResetEvents() => GameEvents.Reset();

        // ---------- ownership ----------

        [Test]
        public void BuyingPlumbing_AlsoOwnsBuildingMaterials_AndOpensTheMines()
        {
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            var collision = new WorldCollision(_db, state);
            int before = collision.Blockers.Count;
            var unlocked = new List<string>();
            GameEvents.Unlocked += unlocked.Add;
            Assert.IsFalse(state.OwnsPlumbing);
            Assert.IsFalse(state.MinesOpen);

            new Ownership(state, collision, _db.products).Own("sink");

            Assert.IsTrue(state.OwnsPlumbing);
            Assert.IsTrue(state.MinesOpen);
            Assert.IsTrue(state.Owns("material"), "Building materials opens with Plumbing (prototype with: 'sink')");
            CollectionAssert.AreEqual(new[] { "sink", "material" }, unlocked);
            // two factories, four materials-shop walls and register 6
            Assert.AreEqual(before + 2 + 4 + 1, collision.Blockers.Count);
        }

        [Test]
        public void BuyingAnotherFactory_OwnsOnlyIt()
        {
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            new Ownership(state, new WorldCollision(_db, state), _db.products).Own("sofa");
            Assert.IsTrue(state.Owns("sofa"));
            Assert.IsFalse(state.Owns("material"));
            Assert.IsFalse(state.OwnsPlumbing);
        }

        [Test]
        public void AnnexRegisterPad_OpensRegister7()
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            WorldStateSync.Apply(state, progress);
            Assert.IsFalse(state.AnnexSecondRegister);
            progress.Pad(WorldStateSync.AnnexRegisterPadId).Level = 1;
            WorldStateSync.Apply(state, progress);
            Assert.IsTrue(state.AnnexSecondRegister);
        }

        [Test]
        public void PlumbingPads_InData()
        {
            PadDef buy = _db.Pad("sink_buy");
            Assert.AreEqual(new Vector2(40f, -9.6f), buy.protoPos);
            Assert.AreEqual(1_875_000, _db.economy.PadPrice(buy, 0));
            Assert.AreEqual(150, _db.Product("sink").unlockLevel);
            Assert.AreSame(_db.Product("sink"), _db.Product("material").unlocksWith);
            PadDef annex = _db.Pad(WorldStateSync.AnnexRegisterPadId);
            Assert.AreEqual(new Vector2(58.2f, 3.5f), annex.protoPos);
            Assert.AreEqual(500_000, _db.economy.PadPrice(annex, 0));
        }

        [Test]
        public void Save_PlumbingFollowsTheOwnedSink()
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            new Ownership(state, new WorldCollision(_db, state), _db.products).Own("sink");
            progress.Pad(WorldStateSync.AnnexRegisterPadId).Level = 1;
            SaveData data = SaveSerializer.FromJson(SaveSerializer.ToJson(SaveMapper.Capture(progress, state, null, "en")));

            WorldStateSnapshot loaded = WorldStateSnapshot.NewGame(_db.products);
            SaveMapper.Apply(data, new GameProgress(_db.economy), loaded, null);
            Assert.IsTrue(loaded.OwnsPlumbing);
            Assert.IsTrue(loaded.Owns("material"));
            Assert.IsTrue(loaded.AnnexSecondRegister);

            WorldStateSnapshot fresh = WorldStateSnapshot.NewGame(_db.products);
            SaveMapper.Apply(SaveSerializer.FromJson("{\"version\":4}"), new GameProgress(_db.economy), fresh, null);
            Assert.IsFalse(fresh.OwnsPlumbing);
        }

        // ---------- mines ----------

        [Test]
        public void Rocks_PrototypeGridsAndNumbers()
        {
            WorldLayout.MinesSettings m = _db.world.mines;
            Assert.AreEqual(4, m.clay.cols);
            Assert.AreEqual(4, m.clay.rows);
            Assert.AreEqual(new Vector2(36.5f, -15.8f), m.clay.origin);
            Assert.AreEqual(5, m.iron.cols);
            Assert.AreEqual(4, m.iron.rows);
            Assert.AreEqual(new Vector2(47f, -15.8f), m.iron.origin);
            Assert.AreEqual(new Vector2(2.4f, -2.4f), m.iron.step);
            Assert.AreEqual(1.5f, _db.economy.clayHardness, 1e-5f);
            Assert.AreEqual(1.8f, _db.economy.ironHardness, 1e-5f);
            Assert.AreEqual(12f, _db.economy.clayRegrowSeconds, 1e-5f);
            Assert.AreEqual(12f, _db.economy.ironRegrowSeconds, 1e-5f);
        }

        [Test]
        public void Region_MinesYardOnlyWithPlumbing()
        {
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            var rules = new FF.Gameplay.Movement.PlayerRegionRules(_db.world.playerBounds);
            Vector2 inYard = new Vector2(47f, 18f); // Unity x, z = proto (47, −18)
            Vector2 closed = inYard;
            rules.Apply(ref closed, state.MinesOpen);
            Assert.Less(closed.y, 13.7f, "kept out of the yard while it is closed");
            state.OwnsPlumbing = true;
            Vector2 open = inYard;
            rules.Apply(ref open, state.MinesOpen);
            Assert.AreEqual(inYard, open);
        }

        // ---------- miner ----------

        [Test]
        public void Miner_DigsWhatTheEmptierInputNeeds()
        {
            Assert.AreEqual(ItemType.Clay, MinerRules.ChooseResource(new Pile(ItemType.Clay, 2), new Pile(ItemType.Iron, 2)), "tie → clay");
            Assert.AreEqual(ItemType.Iron, MinerRules.ChooseResource(new Pile(ItemType.Clay, 6), new Pile(ItemType.Iron, 2)));
            Assert.AreEqual(ItemType.Clay, MinerRules.ChooseResource(new Pile(ItemType.Clay, 5, 20), new Pile(ItemType.Iron, 3)), "by fill ratio");
        }

        [Test]
        public void Miner_GoesThroughTheFactoryGap()
        {
            WorldLayout.WorkerLayoutSettings s = new WorldLayout.WorkerLayoutSettings();
            Assert.IsFalse(MinerRules.InYard(-5f, s));
            Assert.IsTrue(MinerRules.InYard(-16f, s));
            var way = new List<Vector3>();
            MinerRules.GapWay(true, s, way);
            CollectionAssert.AreEqual(new[] { ProtoCoords.ToUnity(44f, -6.2f), ProtoCoords.ToUnity(44f, -14.6f) }, way);
            MinerRules.GapWay(false, s, way);
            CollectionAssert.AreEqual(new[] { ProtoCoords.ToUnity(44f, -14.6f), ProtoCoords.ToUnity(44f, -6.2f) }, way);
        }

        // ---------- section carrier ----------

        static ProductionLine Line(string id, ItemType item, ItemType input, int outCount, bool section) =>
            new ProductionLine
            {
                ProductId = id, ProductNameKey = "p." + id, InputType = input, InputPerCycle = 2,
                Input = new Pile(input, 0, 20), Output = new Pile(item, outCount, 12), Shelf = new Pile(item, 0, 8),
                Section = section, MachineBusy = () => false,
            };

        [Test]
        public void SectionCarrier_OnlyPlumbingAndMaterials_NoPlanks()
        {
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, ItemType.Plank, 9, false),
                Line("sink", ItemType.Sink, ItemType.Clay, 2, true),
            };
            var saws = new List<IPile> { new Pile(ItemType.Plank, 10) };
            var docks = new List<IPile>();
            var scratch = new List<ProductionLine>();

            WorkerJob stocker = CarrierJobs.Pick(lines, saws, CarrierRole.Goods, docks, scratch);
            Assert.AreSame(lines[0].Output, stocker.From, "stockers take the fullest output");
            WorkerJob section = CarrierJobs.Pick(lines, saws, CarrierRole.Section, docks, scratch);
            Assert.AreSame(lines[1].Output, section.From);
            Assert.AreSame(lines[1].Shelf, section.To);

            ((Pile)lines[1].Output).Settled = 0;
            Assert.IsNull(CarrierJobs.Pick(lines, saws, CarrierRole.Section, docks, scratch), "section carriers never take planks");
        }

        [Test]
        public void ClayAndIronInHand_GoToTheirFactory()
        {
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, ItemType.Plank, 0, false),
                Line("sink", ItemType.Sink, ItemType.Clay, 0, true),
                Line("material", ItemType.Material, ItemType.Iron, 0, true),
            };
            var none = new List<IPile>();
            Assert.AreSame(lines[1].Input, CarrierJobs.LeftoverTarget(ItemType.Clay, lines, none, false, none));
            Assert.AreSame(lines[2].Input, CarrierJobs.LeftoverTarget(ItemType.Iron, lines, none, true, none));
        }

        // ---------- section cashier ----------

        [Test]
        public void SectionCashiers_TakeTheMaterialsShopRegistersFirst()
        {
            var active = new List<bool> { true, true, false, false, false, false, true, true };
            int[] section = new int[2], cashiers = new int[4];
            StaffAssignment.AssignStaff(active, 1, section, 3, cashiers);
            Assert.AreEqual(6, section[0]);
            CollectionAssert.AreEqual(new[] { 0, 1, 7 }, new[] { cashiers[0], cashiers[1], cashiers[2] }, "order 0, 6, 1, 2, 7 without 6");

            StaffAssignment.AssignStaff(active, 2, section, 3, cashiers);
            CollectionAssert.AreEqual(new[] { 6, 7 }, section);
            CollectionAssert.AreEqual(new[] { 0, 1, -1 }, new[] { cashiers[0], cashiers[1], cashiers[2] });

            active[7] = false;
            StaffAssignment.AssignStaff(active, 2, section, 1, cashiers);
            CollectionAssert.AreEqual(new[] { 6, -1 }, section, "only register 6 without the annex pad");
        }

        [Test]
        public void SectionWorkers_AreHiredByTheirUpgrades()
        {
            Assert.AreEqual("miner", WorkerKinds.UpgradeId(WorkerKind.Miner));
            Assert.AreEqual("secCarrier", WorkerKinds.UpgradeId(WorkerKind.SectionCarrier));
            Assert.AreEqual("secCashier", WorkerKinds.UpgradeId(WorkerKind.SectionCashier));
            Assert.IsTrue(WorkerKinds.TryFromUpgrade("secCashier", out WorkerKind k));
            Assert.AreEqual(WorkerKind.SectionCashier, k);
            for (int i = 0; i < WorkerKinds.All.Length; i++) Assert.AreEqual(i, (int)WorkerKinds.All[i], "prefab list follows the enum");
            foreach (string id in new[] { "miner", "secCarrier", "secCashier" })
                Assert.IsTrue(_db.Upgrade(id).requiresPlumbing, id);
        }

        // ---------- unlock cards ----------

        List<string> Cards(bool plumbing)
        {
            var owned = new HashSet<string> { "chair" };
            if (plumbing)
            {
                owned.Add("sink");
                owned.Add("material");
            }
            var cards = new List<UnlockCard>();
            UnlockRules.Collect(_db.products, _db.upgrades, owned.Contains, id => true, 150, 0, 0, plumbing, false, cards);
            return cards.ConvertAll(c => c.Id);
        }

        [Test]
        public void Unlocks_PlumbingFactoryAtLevel150()
        {
            List<string> cards = Cards(false);
            CollectionAssert.Contains(cards, "fac_sink");
            CollectionAssert.DoesNotContain(cards, "mines");
            CollectionAssert.DoesNotContain(cards, "staff_miner");
        }

        [Test]
        public void Unlocks_WithPlumbing_MaterialsMinesShopAndSectionStaff()
        {
            List<string> cards = Cards(true);
            CollectionAssert.DoesNotContain(cards, "fac_sink", "owned");
            foreach (string id in new[] { "fac_material", "mines", "matshop", "staff_miner", "staff_secCarrier", "staff_secCashier" })
                CollectionAssert.Contains(cards, id);
            Assert.Less(cards.IndexOf("staff_miner"), cards.IndexOf("mines"), "prototype order: staff before mines");
            Assert.Less(cards.IndexOf("mines"), cards.IndexOf("matshop"));
        }
    }
}
