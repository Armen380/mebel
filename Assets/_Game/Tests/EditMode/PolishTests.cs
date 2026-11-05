using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Player;
using FF.Gameplay.Progress;
using FF.Gameplay.Unlocks;
using FF.Gameplay.World;
using FF.Save;
using FF.UI.Localization;
using NUnit.Framework;
using UnityEditor;

namespace FF.Tests
{
    /// <summary>M9: menu mode, settings, quality tiers, skins, instant-cash income, menu title markup.</summary>
    public sealed class PolishTests
    {
        sealed class MemoryStore : ISettingsStore
        {
            public readonly Dictionary<string, int> Values = new Dictionary<string, int>();
            public int Saves;
            public bool Has(string key) => Values.ContainsKey(key);
            public int Get(string key, int fallback) => Values.TryGetValue(key, out int v) ? v : fallback;
            public void Set(string key, int value) => Values[key] = value;
            public void Save() => Saves++;
        }

        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        [TearDown]
        public void ResetEvents() => GameEvents.Reset();

        // ---------- menu ----------

        [Test]
        public void GameMode_OpensInTheMenu_PlayThenContinue()
        {
            var mode = new GameMode();
            var changes = new List<bool>();
            mode.Changed += changes.Add;
            Assert.IsTrue(mode.InMenu);
            Assert.IsFalse(mode.Started, "first launch says Play");
            mode.Play();
            mode.Play();
            Assert.IsFalse(mode.InMenu);
            Assert.IsTrue(mode.Started, "after Play the menu says Continue");
            mode.OpenMenu();
            CollectionAssert.AreEqual(new[] { false, true }, changes, "repeated calls change nothing");
        }

        // ---------- settings ----------

        [Test]
        public void Settings_DefaultsOn_DeviceTier_Persisted()
        {
            var store = new MemoryStore();
            var settings = new GameSettings(store, QualityTier.Low);
            Assert.IsTrue(settings.Sound && settings.Music && settings.Vibration);
            Assert.AreEqual(QualityTier.Low, settings.Quality, "first launch takes the device tier");
            int changed = 0;
            settings.Changed += () => changed++;
            settings.SetMusic(false);
            settings.SetQuality(QualityTier.High);
            settings.SetQuality(QualityTier.High);
            Assert.AreEqual(2, changed);
            var reloaded = new GameSettings(store, QualityTier.Medium);
            Assert.IsFalse(reloaded.Music);
            Assert.AreEqual(QualityTier.High, reloaded.Quality, "a saved tier wins over the device default");
        }

        [TestCase(2048, 8, QualityTier.Low)]
        [TestCase(8192, 4, QualityTier.Low)]
        [TestCase(4096, 8, QualityTier.Medium)]
        [TestCase(8192, 8, QualityTier.High)]
        [TestCase(0, 0, QualityTier.High)]
        public void QualityTier_ByDevice(int ramMb, int cores, QualityTier expected) =>
            Assert.AreEqual(expected, QualityRules.DefaultTier(ramMb, cores));

        [Test]
        public void QualityLevels_ExistOnEveryPlatform()
        {
            CollectionAssert.AreEqual(QualityRules.LevelNames, UnityEngine.QualitySettings.names);
        }

        // ---------- skins ----------

        [Test]
        public void Skins_GoldenNeedsTotalEarnings()
        {
            SkinDef gold = _db.Skin("gold"), lumber = _db.Skin("lumber");
            Assert.IsTrue(SkinRules.IsUnlocked(lumber, 0));
            Assert.IsFalse(SkinRules.IsUnlocked(gold, 99_999));
            Assert.IsTrue(SkinRules.IsUnlocked(gold, 100_000));
            Assert.IsFalse(SkinRules.IsUnlocked(null, 1_000_000));
        }

        [Test]
        public void Skins_GoldenCardAtThreshold()
        {
            var cards = new List<UnlockCard>();
            UnlockRules.Collect(_db.products, _db.upgrades, id => id == "chair", id => true, 1, 0, 0, false, false, cards, _db.skins, 99_999);
            Assert.IsFalse(cards.Exists(c => c.Kind == UnlockKind.Skin));
            UnlockRules.Collect(_db.products, _db.upgrades, id => id == "chair", id => true, 1, 0, 0, false, false, cards, _db.skins, 100_000);
            UnlockCard card = cards.Find(c => c.Kind == UnlockKind.Skin);
            Assert.AreEqual("skin_gold", card.Id);
            Assert.AreEqual("gold", card.ProductId);
        }

        [Test]
        public void Save_KeepsTheSkin()
        {
            var progress = new GameProgress(_db.economy) { Skin = "night" };
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            SaveData data = SaveSerializer.FromJson(SaveSerializer.ToJson(SaveMapper.Capture(progress, state, null, "en")));
            var loaded = new GameProgress(_db.economy);
            SaveMapper.Apply(data, loaded, WorldStateSnapshot.NewGame(_db.products), null);
            Assert.AreEqual("night", loaded.Skin);
        }

        // ---------- rewarded ads ----------

        [Test]
        public void InstantCash_TwoMinutesOfIncome_AtLeast500()
        {
            var meter = new IncomeMeter(60f, 5f);
            Assert.AreEqual(500, meter.InstantCash(), "no income yet");
            for (int i = 0; i <= 12; i++) meter.Sample(i * 5f, i * 5 * 10); // $10 / s
            Assert.AreEqual(10.0, meter.PerSecond, 1e-6);
            Assert.AreEqual(1200, meter.InstantCash());
            meter.Sample(61f, 600); // too soon after the last sample: ignored
            Assert.AreEqual(10.0, meter.PerSecond, 1e-6);
        }

        [Test]
        public void IncomeMeter_ForgetsOldSamples()
        {
            var meter = new IncomeMeter(20f, 5f); // 5 samples
            for (int i = 0; i < 4; i++) meter.Sample(i * 5f, 0);
            for (int i = 4; i < 10; i++) meter.Sample(i * 5f, (i - 3) * 100);
            Assert.AreEqual(20.0, meter.PerSecond, 1e-6, "only the last 20 s count");
        }

        // ---------- menu texts ----------

        [Test]
        public void MenuTitle_EmphasisInHoney()
        {
            Assert.AreEqual("Furniture <color=#F3B33D>Factory</color>", LocalizedTmpText.FromHtml("Furniture <em>Factory</em>"));
            Assert.AreEqual("a\nb", LocalizedTmpText.FromHtml("a<br>b"));
        }
    }
}
