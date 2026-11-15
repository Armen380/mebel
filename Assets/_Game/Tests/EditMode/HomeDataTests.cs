using System.Collections.Generic;
using System.IO;
using FF.Data;
using FF.Editor;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEditor;

namespace FF.Tests
{
    /// <summary>Dream-house data (M10): imported HomeDef, stage pads and strings (run FF/Import Design Data first).</summary>
    public sealed class HomeDataTests
    {
        GameDatabase _db;
        HomeDef _home;

        [OneTimeSetUp]
        public void Load()
        {
            _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            Assert.IsNotNull(_db, "GameDatabase missing — run FF/Import Design Data.");
            _home = _db.home;
            Assert.IsNotNull(_home, "GameDatabase.home missing — run FF/Import Design Data.");
        }

        [Test]
        public void Import_HasAreasSlotsItems()
        {
            Assert.AreEqual(5, _home.areas.Count);
            Assert.AreEqual(32, _home.slots.Count);
            Assert.AreEqual(ItemType.Sofa, _home.Slot("living_sofa").product);
            Assert.AreEqual(ItemType.None, _home.Slot("living_carpet").product);
            Assert.AreEqual("carpet", _home.Slot("living_carpet").group);
            Assert.AreEqual(2, _home.Area("living").requiresStage);
            Assert.AreEqual(1, _home.Area("yard").requiresStage);
            Assert.AreEqual(1200000, _home.Item("pool").price);
            Assert.AreEqual(0.001, _home.comfortBonusPerPoint, 1e-9);
        }

        [Test]
        public void EverySlotIsInAKnownArea()
        {
            foreach (HomeDef.SlotDef s in _home.slots)
                Assert.IsNotNull(_home.Area(s.area), s.id);
        }

        [Test]
        public void EveryStoreSlotGroupHasAnItem()
        {
            foreach (HomeDef.SlotDef s in _home.slots)
            {
                if (s.product != ItemType.None) continue;
                bool found = false;
                foreach (HomeDef.HomeItemDef i in _home.items) found |= i.group == s.group;
                Assert.IsTrue(found, $"No catalog item for slot group '{s.group}' ({s.id}).");
            }
        }

        [Test]
        public void BestHouseComfortIs200()
        {
            int total = 0;
            foreach (HomeDef.SlotDef s in _home.slots)
            {
                if (s.product != ItemType.None) { total += s.comfort; continue; }
                int best = 0;
                foreach (HomeDef.HomeItemDef i in _home.items)
                    if (i.group == s.group && i.comfort > best) best = i.comfort;
                total += best;
            }
            Assert.AreEqual(200, total);
        }

        [Test]
        public void HousePadsExist()
        {
            Assert.AreEqual(1600, _db.Pad("house_found").baseCost);
            Assert.AreEqual(8000, _db.Pad("house_walls").baseCost);
            Assert.AreEqual(24000, _db.Pad("house_roof").baseCost);
            Assert.AreEqual(60000, _db.Pad("house_windows").baseCost);
            Assert.AreEqual(1, _db.Pad("house_roof").maxLevel);
            Assert.AreEqual("done.house", _db.Pad("house_walls").doneKey);
        }

        [Test]
        public void HomeKeysInAllLocales()
        {
            var keys = new List<string> { "home.store.title", "home.tab.house", "home.tab.yard", "home.buy", "home.owned",
                "home.placed", "home.needs", "home.comfort", "home.bonus", "t.roomDone", "sign.homeStore", "done.house" };
            foreach (HomeDef.AreaDef a in _home.areas) keys.Add(a.nameKey);
            foreach (HomeDef.HomeItemDef i in _home.items) keys.Add(i.nameKey);
            foreach (string pad in new[] { "house_found", "house_walls", "house_roof", "house_windows" }) keys.Add("home.stage." + pad);

            foreach (string code in new[] { "en", "ru", "hy" })
            {
                JObject table = JObject.Parse(File.ReadAllText(Path.Combine(DataImporter.DesignDataDir, $"localization_{code}.json")));
                foreach (string key in keys)
                    Assert.IsFalse(string.IsNullOrEmpty((string)table[key]), $"'{key}' missing in {code}");
            }
        }
    }
}
