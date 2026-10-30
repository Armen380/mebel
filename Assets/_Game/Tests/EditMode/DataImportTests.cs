using System.Collections.Generic;
using System.Linq;
using FF.Data;
using FF.Editor;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEditor.Localization;
using UnityEngine;
using UnityEngine.Localization.Tables;

namespace FF.Tests
{
    /// <summary>Checks the imported assets (run FF/Import Design Data first).</summary>
    public sealed class DataImportTests
    {
        GameDatabase _db;

        [OneTimeSetUp]
        public void Load()
        {
            _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            Assert.IsNotNull(_db, "GameDatabase missing — run FF/Import Design Data.");
        }

        [Test]
        public void Products_InPrototypeOrder()
        {
            CollectionAssert.AreEqual(
                new[] { "chair", "sofa", "wardrobe", "table", "kitchen", "sink", "material" },
                _db.products.Select(p => p.id).ToArray());
        }

        [Test]
        public void Products_KeyFields()
        {
            ProductDef chair = _db.Product("chair");
            Assert.IsTrue(chair.OwnedAtStart);
            Assert.AreEqual(ItemType.Plank, chair.input);
            Assert.AreEqual(2, chair.inputPerCycle);
            Assert.AreEqual(2.6f, chair.cycleSeconds, 1e-5f);
            Assert.AreEqual(4.6f, chair.shelfX, 1e-4f);
            Assert.AreEqual(4.6f + 4 * 2.8f, _db.Product("kitchen").shelfX, 1e-4f);

            ProductDef material = _db.Product("material");
            Assert.AreSame(_db.Product("sink"), material.unlocksWith);
            Assert.IsFalse(material.OwnedAtStart);
            Assert.AreEqual(ShopKind.Materials, material.sellsIn);
            Assert.AreEqual(50.6f, material.shelfX, 1e-4f);
            Assert.AreEqual(ItemType.Iron, material.input);
            Assert.AreEqual(1500000, _db.Product("sink").factoryCost);
        }

        [Test]
        public void Pads_AllImported()
        {
            Assert.AreEqual(29, _db.pads.Count);
            Assert.AreEqual(new Vector2(-6f, -11.1f), _db.Pad("saw_speed").protoPos);
            Assert.AreEqual(new Vector2(26.4f, 3.5f), _db.Pad("reg").protoPos);
            Assert.AreEqual(1, _db.Pad("saw2_buy").maxLevel);
        }

        [Test]
        public void SkinsUpgradesTutorial()
        {
            Assert.AreEqual("lumber", _db.DefaultSkin.id);
            Assert.AreEqual(HatType.Crown, _db.Skin("gold").hatType);
            Assert.AreEqual(100000, _db.Skin("gold").unlockTotalEarned);
            Assert.AreEqual(15, _db.upgrades.Count);
            Assert.AreEqual(2, _db.Upgrade("stocker").requiresShopLevel);
            Assert.IsTrue(_db.Upgrade("miner").requiresPlumbing);
            Assert.AreEqual(8, _db.tutorial.steps.Count);
            Assert.AreEqual("q1", _db.tutorial.steps[0].textKey);
        }

        [Test]
        public void World_FromJson()
        {
            WorldLayout w = _db.world;
            Assert.AreEqual(5, w.forest.cols);
            Assert.AreEqual(7, w.forest.rows);
            Assert.AreEqual(5, w.mines.iron.cols);
            Assert.AreEqual(-13.6f, w.fenceLineZ, 1e-5f);
            Assert.AreEqual(-31.5f, w.playerBounds.x.min, 1e-5f);
            Assert.AreEqual(6, w.mainShop.registersX.Length);
            Assert.AreEqual(-4f, w.dreamHouse.accessRoadZ.min, 1e-5f);
            Assert.AreEqual(11.2f, w.dreamHouse.accessRoadZ.max, 1e-5f);
        }

        [Test]
        public void Localization_SameKeysInAllLanguages()
        {
            HashSet<string> hy = Keys("hy");
            CollectionAssert.AreEquivalent(hy, Keys("en"));
            CollectionAssert.AreEquivalent(hy, Keys("ru"));
        }

        [Test]
        public void Localization_TablesContainEveryKey()
        {
            StringTableCollection collection = LocalizationEditorSettings.GetStringTableCollection(LocalizationImporter.TableName);
            Assert.IsNotNull(collection);
            foreach (string code in LocalizationImporter.LocaleCodes)
            {
                var table = (StringTable)collection.GetTable(new UnityEngine.Localization.LocaleIdentifier(code));
                Assert.IsNotNull(table, code);
                JObject json = DataImporter.ReadObject($"localization_{code}.json");
                foreach (KeyValuePair<string, JToken> pair in json)
                    Assert.AreEqual((string)pair.Value, table.GetEntry(pair.Key)?.Value, $"{code}:{pair.Key}");
            }
        }

        static HashSet<string> Keys(string code) =>
            new HashSet<string>(DataImporter.ReadObject($"localization_{code}.json").Properties().Select(p => p.Name));
    }
}
