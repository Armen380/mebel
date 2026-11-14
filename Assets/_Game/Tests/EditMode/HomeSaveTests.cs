using FF.Data;
using FF.Editor;
using FF.Gameplay.Home;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using FF.Save;
using NUnit.Framework;
using UnityEditor;

namespace FF.Tests
{
    /// <summary>Save v5 (M10): the Dream House state survives a save and older saves load with an empty home.</summary>
    public sealed class HomeSaveTests
    {
        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        HomeState RoundTrip(HomeState home)
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            string json = SaveSerializer.ToJson(SaveMapper.Capture(progress, state, null, "en", home));
            var loaded = new HomeState();
            SaveMapper.Apply(SaveSerializer.FromJson(json), new GameProgress(_db.economy), WorldStateSnapshot.NewGame(_db.products), null, loaded);
            return loaded;
        }

        [Test]
        public void V4Save_LoadsWithEmptyHome()
        {
            SaveData data = SaveSerializer.FromJson("{\"version\":4,\"money\":5}");
            Assert.AreEqual(5, SaveData.CurrentVersion);
            Assert.AreEqual(5, data.version);
            Assert.IsNotNull(data.home);
            Assert.AreEqual(0, data.home.slots.Count);

            var home = new HomeState();
            home.Placed["x"] = "y";
            SaveMapper.Apply(data, new GameProgress(_db.economy), WorldStateSnapshot.NewGame(_db.products), null, home);
            Assert.AreEqual(0, home.Placed.Count, "Apply starts from an empty home");
        }

        [Test]
        public void Home_RoundTrip()
        {
            var home = new HomeState();
            home.Placed["living_sofa"] = "sofa";
            home.Placed["living_carpet"] = "carpet_star";
            home.Storage["lamp_brass"] = 2;
            HomeState loaded = RoundTrip(home);
            Assert.AreEqual("sofa", loaded.Placed["living_sofa"]);
            Assert.AreEqual("carpet_star", loaded.Placed["living_carpet"]);
            Assert.AreEqual(2, loaded.Storage["lamp_brass"]);
        }

        [Test]
        public void RewardedRooms_RoundTrip()
        {
            var home = new HomeState();
            home.RewardedAreas.Add("living");
            home.RewardedAreas.Add("yard");
            HomeState loaded = RoundTrip(home);
            Assert.IsTrue(loaded.RewardedAreas.Contains("living"));
            Assert.IsTrue(loaded.RewardedAreas.Contains("yard"));
            Assert.AreEqual(2, loaded.RewardedAreas.Count);
        }
    }
}
