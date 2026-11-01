using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Production;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using FF.UI.Upgrades;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M4: building growth layout, fading rule, Sawmill 2 purchase, upgrade prices / locks / buying / value texts.</summary>
    public sealed class UpgradeTests
    {
        GameDatabase _db;
        BuildingKit _kit;
        readonly List<BuildingPart> _parts = new List<BuildingPart>();
        readonly List<Vector3> _chimneys = new List<Vector3>();

        [OneTimeSetUp]
        public void Load()
        {
            _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            _kit = ScriptableObject.CreateInstance<BuildingKit>();
        }

        [OneTimeTearDown]
        public void Unload() => Object.DestroyImmediate(_kit);

        [SetUp]
        public void SetUp() => GameEvents.Reset();

        float Grow(int speed, int qty) => BuildingGrowthLayout.Build(speed, qty, Color.white, Color.gray, _kit, _parts, _chimneys);

        int Count(PartShape shape)
        {
            int n = 0;
            foreach (BuildingPart p in _parts) if (p.Shape == shape) n++;
            return n;
        }

        bool Has(PartRole role)
        {
            foreach (BuildingPart p in _parts) if (p.Role == role) return true;
            return false;
        }

        // ---------- growth (prototype setBuildingLevel) ----------

        [Test]
        public void NewBuilding_TrimBandAndTwoRoofs()
        {
            float top = Grow(0, 0);
            Assert.AreEqual(3, _parts.Count);
            Assert.AreEqual(0, _chimneys.Count);
            Assert.AreEqual(2.6f + 1.5f, top, 1e-5f);
            Assert.AreEqual((Color)_kit.trims[0], (Color)_parts[0].Color);
        }

        [Test]
        public void Qty_AddsFloorsWithFourWindows_AndLiftsTheRoof()
        {
            float top = Grow(0, 2);
            // band + 2 floors × (floor + 4 windows + 4 sills + floor trim) + 2 roofs
            Assert.AreEqual(1 + 2 * 10 + 2, _parts.Count);
            Assert.AreEqual(2.6f + 2 * 1.25f + 1.5f, top, 1e-5f);
        }

        [Test]
        public void Tier_StepsEveryThreeLevels_WindowsLightFromTierTwo()
        {
            Assert.AreEqual(0, BuildingGrowthLayout.Tier(1, 1));
            Assert.AreEqual(1, BuildingGrowthLayout.Tier(2, 1));
            Assert.AreEqual(2, BuildingGrowthLayout.Tier(4, 2));
            Assert.AreEqual(3, BuildingGrowthLayout.Tier(8, 3));
            Grow(4, 2);
            Assert.AreEqual((Color)_kit.trims[2], (Color)_parts[0].Color);
            Assert.AreEqual((Color)_kit.litWindow, (Color)_parts[1].Color, "side windows lit from tier 2");
        }

        [TestCase(0, 0, false, false, false)]
        [TestCase(1, 1, false, false, false)]
        [TestCase(3, 1, true, false, false)]
        [TestCase(5, 2, true, false, false)]
        [TestCase(7, 2, true, true, false)]
        [TestCase(8, 2, true, true, false)]
        [TestCase(8, 3, true, true, true)]
        public void Speed_AddsChimneysFanTankAndFlag(int speed, int qty, bool fan, bool tank, bool flag)
        {
            Grow(speed, qty);
            Assert.AreEqual(BuildingGrowthLayout.ChimneyCount(speed), _chimneys.Count);
            Assert.AreEqual(fan, Has(PartRole.FanBlades));
            Assert.AreEqual(tank, Count(PartShape.Tank) == 1);
            Assert.AreEqual(flag, Has(PartRole.Flag));
        }

        [Test]
        public void ChimneyCount_OneFromSpeed1_TwoFromSpeed5()
        {
            Assert.AreEqual(0, BuildingGrowthLayout.ChimneyCount(0));
            Assert.AreEqual(1, BuildingGrowthLayout.ChimneyCount(1));
            Assert.AreEqual(1, BuildingGrowthLayout.ChimneyCount(4));
            Assert.AreEqual(2, BuildingGrowthLayout.ChimneyCount(5));
        }

        // ---------- occlusion fade ----------

        [Test]
        public void Fade_OnlyWhenThePlayerIsBehindTheBuilding()
        {
            var building = new Vector3(0, 0, 10);
            Assert.IsTrue(OcclusionRule.IsBehind(building, new Vector3(1, 0, 13)));
            Assert.IsFalse(OcclusionRule.IsBehind(building, new Vector3(0, 0, 12)), "closer than 2.3 m");
            Assert.IsFalse(OcclusionRule.IsBehind(building, new Vector3(5, 0, 13)), "beside it");
            Assert.IsFalse(OcclusionRule.IsBehind(building, new Vector3(0, 0, 26)), "further than 15 m");
            Assert.IsFalse(OcclusionRule.IsBehind(building, new Vector3(0, 0, 5)), "in front of it");
        }

        // ---------- Sawmill 2 ----------

        [Test]
        public void OwningSawmill2_AddsItsBlocker()
        {
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            var collision = new WorldCollision(_db, state);
            int before = collision.Blockers.Count;
            string unlocked = null;
            GameEvents.Unlocked += id => unlocked = id;
            new Ownership(state, collision).Own(WorldStateSnapshot.Sawmill2Id);
            Assert.IsTrue(state.OwnsSawmill2);
            Assert.AreEqual(before + 1, collision.Blockers.Count);
            Assert.AreEqual("saw2", unlocked);
        }

        // ---------- upgrades panel ----------

        [Test]
        public void PanelPrices_MatchUpgradesJson()
        {
            foreach (JObject j in DataImporter.ReadArray("upgrades.json"))
            {
                UpgradeDef u = _db.Upgrade((string)j["id"]);
                var beforeEcon = (JArray)j["costPerLevel_beforeECON"];
                for (int lv = 0; lv < beforeEcon.Count; lv++)
                {
                    long price = _db.economy.UpgradePrice(u, lv);
                    Assert.AreEqual(EconomyConfig.PriceFormula(u.baseCost, _db.economy.costMultiplier, u.costMultiplier, lv), price);
                    // the JSON table is rounded before ECON.cost; the prototype rounds after it → within one 50 step
                    Assert.That(System.Math.Abs(price - (long)beforeEcon[lv] * 1.25), Is.LessThanOrEqualTo(50 * 1.25 + 1e-6),
                        $"{u.id} lv {lv}");
                }
            }
        }

        [Test]
        public void Locks_ShopLevelAndPlumbing()
        {
            UpgradeDef stocker = _db.Upgrade("stocker"), miner = _db.Upgrade("miner"), cap = _db.Upgrade("cap");
            Assert.IsTrue(UpgradeRules.IsLocked(stocker, 1, false, out int needShop, out _));
            Assert.AreEqual(2, needShop);
            Assert.IsFalse(UpgradeRules.IsLocked(stocker, 2, false, out _, out _));
            Assert.IsTrue(UpgradeRules.IsLocked(miner, 5, false, out _, out bool needPlumbing));
            Assert.IsTrue(needPlumbing);
            Assert.IsFalse(UpgradeRules.IsLocked(miner, 0, true, out _, out _));
            Assert.IsFalse(UpgradeRules.IsLocked(cap, 0, false, out _, out _));
        }

        [Test]
        public void Buying_SpendsMoney_RaisesTheLevel_UntilMax()
        {
            var progress = new GameProgress(_db.economy);
            var shop = new UpgradeShop(_db, progress, WorldStateSnapshot.NewGame(_db.products));
            Assert.IsFalse(shop.CanBuy("cap"), "no money");
            progress.AddMoney(1_000_000);
            string bought = null;
            GameEvents.UpgradeBought += (id, lv) => bought = id + lv;
            Assert.IsTrue(shop.TryBuy("cap"));
            Assert.AreEqual("cap1", bought);
            Assert.AreEqual(1, progress.GetLevel("cap"));
            Assert.AreEqual(1_000_000 - 1250, progress.Money, "round(1000·1.25/50)·50");
            while (shop.TryBuy("cap")) { }
            Assert.AreEqual(8, shop.GetLevel("cap"));
            Assert.IsFalse(shop.CanBuy("cap"), "max");
            Assert.IsFalse(shop.TryBuy("stocker"), "locked until shop Lv 2");
        }

        [TestCase("cap", 0, "u.items", "5")]
        [TestCase("cap", 3, "u.items", "11")]
        [TestCase("speed", 1, null, "112%")]
        [TestCase("axe", 1, "u.sec", "0.81")]
        [TestCase("axe", 6, "u.sec", "0.35")]
        [TestCase("ads", 0, "u.cust", "0")]
        [TestCase("ads", 2, "u.cust", "+2")]
        [TestCase("quality", 3, null, "+75%")]
        [TestCase("consult", 1, "u.price", "15")]
        [TestCase("robot", 2, "u.bots", "2")]
        [TestCase("cashier", 4, "u.people", "4")]
        public void ValueTexts_LikeThePrototype(string id, int level, string key, string n)
        {
            (string gotKey, string gotN) = UpgradeValueText.Parts(_db.Upgrade(id), level, _db.economy);
            Assert.AreEqual(key, gotKey);
            Assert.AreEqual(n, gotN);
        }
    }
}
