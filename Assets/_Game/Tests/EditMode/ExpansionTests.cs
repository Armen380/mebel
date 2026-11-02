using System;
using System.Collections.Generic;
using System.IO;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Pads;
using FF.Gameplay.Progress;
using FF.Gameplay.Unlocks;
using FF.Gameplay.World;
using FF.Save;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M5: pad visibility, registers, unlock cards, save round trip and file handling.</summary>
    public sealed class ExpansionTests
    {
        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        [SetUp]
        public void SetUp() => GameEvents.Reset();

        // ---------- pads ----------

        [Test]
        public void PadRules_EachFamily()
        {
            // speed / qty: owner owned
            Assert.IsTrue(PadRules.IsVisible(PadRule.OwnerOwned, 0, 8, true, 1, 0, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.OwnerOwned, 0, 8, false, 1, 0, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.OwnerOwned, 8, 8, true, 1, 0, 0, 0), "max");
            // buy: not owned and level reached
            Assert.IsFalse(PadRules.IsVisible(PadRule.BuyOwner, 0, 1, false, 4, 5, 0, 0), "Lv 4 < 5");
            Assert.IsTrue(PadRules.IsVisible(PadRule.BuyOwner, 0, 1, false, 5, 5, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.BuyOwner, 0, 1, true, 9, 5, 0, 0), "owned");
            // register: fewer registers than the shop level
            Assert.IsFalse(PadRules.IsVisible(PadRule.Register, 0, 5, false, 1, 0, 0, 0));
            Assert.IsTrue(PadRules.IsVisible(PadRule.Register, 0, 5, false, 1, 0, 0, 1));
            Assert.IsFalse(PadRules.IsVisible(PadRule.Register, 2, 5, false, 1, 0, 2, 2));
            // shop: always until max
            Assert.IsTrue(PadRules.IsVisible(PadRule.Always, 4, 5, false, 1, 0, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.Always, 5, 5, false, 1, 0, 0, 0));
        }

        [TestCase(0, 0, 1)]
        [TestCase(3, 0, 1)]
        [TestCase(0, 3, 1)]
        [TestCase(2, 3, 3)]
        [TestCase(5, 5, 6)]
        public void MainRegisters_OnePlusMinOfRegisterAndShop(int reg, int shop, int expected) =>
            Assert.AreEqual(expected, WorldStateSync.MainRegisters(reg, shop));

        [Test]
        public void ShopWall_MovesBy4_2PerLevel_AndBlockersFollow()
        {
            Assert.AreEqual(25f, _db.economy.ShopWallX(0), 1e-5f);
            Assert.AreEqual(46f, _db.economy.ShopWallX(5), 1e-4f);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            var collision = new WorldCollision(_db, state);
            var progress = new GameProgress(_db.economy);
            progress.Pad("shop").Level = 2;
            progress.Pad("reg").Level = 2;
            WorldStateSync.Apply(state, progress);
            collision.Rebuild(state);
            Assert.AreEqual(2, state.ShopLevel);
            Assert.AreEqual(3, state.MainRegisters);
            Aabb2D wall = ProtoCoords.ToUnityRect(33.25f, 33.55f, 0.4f, 9.85f); // wall at 25 + 2·4.2
            bool found = false;
            foreach (Aabb2D b in collision.Blockers)
                found |= Mathf.Abs(b.MinX - wall.MinX) < 1e-3f && Mathf.Abs(b.MaxX - wall.MaxX) < 1e-3f && Mathf.Abs(b.MinZ - wall.MinZ) < 1e-3f;
            Assert.IsTrue(found, "right shop wall blocker at x 33.4");
        }

        // ---------- unlock cards ----------

        List<UnlockCard> Cards(int level, int reg, int shop, bool tutorialDone, params string[] owned)
        {
            var set = new HashSet<string>(owned) { "chair" };
            var cards = new List<UnlockCard>();
            UnlockRules.Collect(_db.products, set.Contains, id => id != "sink", level, reg, shop, tutorialDone, cards);
            return cards;
        }

        static List<string> Ids(List<UnlockCard> cards) => cards.ConvertAll(c => c.Id);

        [Test]
        public void Unlocks_NewGame_Nothing() => Assert.IsEmpty(Cards(1, 0, 0, false));

        [Test]
        public void Unlocks_FactoriesAtTheirLevels_NotOwnedOnes()
        {
            CollectionAssert.AreEquivalent(new[] { "fac_sofa" }, Ids(Cards(5, 0, 0, false)));
            CollectionAssert.AreEquivalent(new[] { "fac_wardrobe", "fac_table" }, Ids(Cards(22, 0, 0, false, "sofa")));
            CollectionAssert.DoesNotContain(Ids(Cards(150, 0, 0, false)), "fac_sink", "sink buy pad comes in M8");
        }

        [Test]
        public void Unlocks_RegisterSlot_Sawmill2_DreamPlot()
        {
            CollectionAssert.AreEquivalent(new[] { "reg_2" }, Ids(Cards(1, 1, 2, false)));
            CollectionAssert.AreEquivalent(new[] { "saw2", "dream" }, Ids(Cards(1, 0, 0, true)));
            CollectionAssert.AreEquivalent(new[] { "dream" }, Ids(Cards(1, 0, 0, true, "saw2")));
        }

        [Test]
        public void MarkSeen_OnlyOnce()
        {
            var p = new GameProgress(_db.economy);
            Assert.IsTrue(p.MarkSeen("fac_sofa"));
            Assert.IsFalse(p.MarkSeen("fac_sofa"));
        }

        // ---------- save ----------

        [Test]
        public void Save_RoundTrip_RestoresEverything()
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            progress.AddMoney(123_456);
            progress.Spend(456);
            progress.AddXp(20);
            for (int i = 0; i < 3; i++) progress.AdvanceQuest();
            progress.SetUpgradeLevel("cap", 3);
            progress.Pad("saw_speed").Level = 4;
            progress.Pad("saw_speed").Paid = 1234;
            progress.Pad("shop").Level = 2;
            progress.Pad("reg").Level = 1;
            progress.MarkSeen("fac_sofa");
            state.OwnedProducts.Add("sofa");
            state.OwnsSawmill2 = true;

            string json = SaveSerializer.ToJson(SaveMapper.Capture(progress, state, "ru"));
            SaveData data = SaveSerializer.FromJson(json);
            Assert.AreEqual("ru", data.lang);

            var loaded = new GameProgress(_db.economy);
            WorldStateSnapshot loadedState = WorldStateSnapshot.NewGame(_db.products);
            SaveMapper.Apply(data, loaded, loadedState);

            Assert.AreEqual(123_000, loaded.Money);
            Assert.AreEqual(123_456, loaded.TotalEarned);
            Assert.AreEqual(progress.Level, loaded.Level);
            Assert.AreEqual(progress.Xp, loaded.Xp);
            Assert.AreEqual(3, loaded.QuestStep);
            Assert.AreEqual(3, loaded.GetLevel("cap"));
            Assert.AreEqual(4, loaded.GetLevel("saw_speed"));
            Assert.AreEqual(1234, loaded.Pad("saw_speed").Paid);
            Assert.IsFalse(loaded.MarkSeen("fac_sofa"), "seen restored");
            Assert.IsTrue(loadedState.Owns("sofa"));
            Assert.IsTrue(loadedState.Owns("chair"));
            Assert.IsTrue(loadedState.OwnsSawmill2);
            Assert.AreEqual(2, loadedState.ShopLevel);
            Assert.AreEqual(2, loadedState.MainRegisters);
        }

        [Test]
        public void Save_MigratesPrototypeReg2Pad()
        {
            SaveData data = SaveSerializer.FromJson("{\"version\":3,\"money\":5,\"pads\":{\"reg2\":{\"lv\":2,\"paid\":10}}}");
            Assert.IsTrue(data.pads.ContainsKey("reg"));
            Assert.IsFalse(data.pads.ContainsKey("reg2"));
            Assert.AreEqual(2, data.pads["reg"].lv);
            Assert.AreEqual(1, data.level, "missing fields keep their defaults");
        }

        [Test]
        public void Save_BrokenText_IsAFormatError()
        {
            Assert.Throws<FormatException>(() => SaveSerializer.FromJson("{ not json"));
        }

        [Test]
        public void Save_WriteIsAtomic_AndReadable()
        {
            string dir = Path.Combine(Path.GetTempPath(), "ff_save_test_" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(dir);
            string path = Path.Combine(dir, SaveService.FileName);
            try
            {
                SaveService.Write(path, SaveSerializer.ToJson(new SaveData { money = 7 }));
                SaveService.Write(path, SaveSerializer.ToJson(new SaveData { money = 9 }));
                Assert.IsFalse(File.Exists(path + ".tmp"));
                Assert.AreEqual(9, SaveSerializer.FromJson(File.ReadAllText(path)).money);
            }
            finally
            {
                Directory.Delete(dir, true);
            }
        }
    }
}
