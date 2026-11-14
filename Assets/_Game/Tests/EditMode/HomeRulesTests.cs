using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.Home;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>Dream House rules (M10): slots, storage, buying caps, comfort, room gifts.</summary>
    public sealed class HomeRulesTests
    {
        HomeDef _def;
        HomeState _state;

        [SetUp]
        public void Build()
        {
            _def = ScriptableObject.CreateInstance<HomeDef>();
            _def.comfortBonusPerPoint = 0.001;
            _def.areas.Add(new HomeDef.AreaDef { id = "living", requiresStage = 2, gift = 5000 });
            _def.areas.Add(new HomeDef.AreaDef { id = "yard", requiresStage = 1, gift = 100 });
            _def.slots.Add(new HomeDef.SlotDef { id = "living_sofa", area = "living", product = ItemType.Sofa, comfort = 10 });
            _def.slots.Add(new HomeDef.SlotDef { id = "living_chair1", area = "living", product = ItemType.Chair, comfort = 4 });
            _def.slots.Add(new HomeDef.SlotDef { id = "living_carpet", area = "living", group = "carpet" });
            _def.slots.Add(new HomeDef.SlotDef { id = "yard_carpet", area = "yard", group = "carpet" });
            _def.slots.Add(new HomeDef.SlotDef { id = "yard_bed", area = "yard", group = "bench" });
            _def.items.Add(new HomeDef.HomeItemDef { id = "carpet_a", group = "carpet", price = 600, comfort = 4 });
            _def.items.Add(new HomeDef.HomeItemDef { id = "carpet_b", group = "carpet", price = 900, comfort = 6 });
            _def.items.Add(new HomeDef.HomeItemDef { id = "bench", group = "bench", price = 1200, comfort = 3 });
            _def.items.Add(new HomeDef.HomeItemDef { id = "bed", group = "bed", price = 12000, comfort = 10 });
            _state = new HomeState();
        }

        [TearDown]
        public void Destroy() => Object.DestroyImmediate(_def);

        HomeDef.SlotDef Slot(string id) => _def.Slot(id);
        HomeDef.HomeItemDef Item(string id) => _def.Item(id);

        [Test]
        public void FactorySlot_AcceptsOnlyItsProduct_OnePerSlot()
        {
            Assert.IsFalse(HomeRules.CanPlaceFactory(_def, _state, Slot("living_sofa"), 2, ItemType.Chair));
            Assert.IsTrue(HomeRules.CanPlaceFactory(_def, _state, Slot("living_sofa"), 2, ItemType.Sofa));
            HomeRules.PlaceFactory(_state, Slot("living_sofa"));
            Assert.AreEqual("sofa", _state.Placed["living_sofa"]);
            Assert.IsFalse(HomeRules.CanPlaceFactory(_def, _state, Slot("living_sofa"), 2, ItemType.Sofa));
            Assert.IsFalse(HomeRules.CanPlaceFactory(_def, _state, Slot("living_carpet"), 2, ItemType.Sofa), "store slot");
        }

        [Test]
        public void Slots_ClosedUntilAreaStage()
        {
            Assert.IsFalse(HomeRules.CanPlaceFactory(_def, _state, Slot("living_sofa"), 1, ItemType.Sofa));
            Assert.IsTrue(HomeRules.CanPlaceFactory(_def, _state, Slot("living_sofa"), 2, ItemType.Sofa));
            Assert.IsFalse(HomeRules.IsAreaOpen(_def, "yard", 0));
            Assert.IsTrue(HomeRules.IsAreaOpen(_def, "yard", 1));
            Assert.IsFalse(HomeRules.IsAreaOpen(_def, "nowhere", 4));
        }

        [Test]
        public void Buy_CappedPerItemBySlotCount()
        {
            // each variant can be owned as many times as its group has slots, so every slot can hold the best variant
            Assert.IsTrue(HomeRules.CanBuy(_def, _state, Item("carpet_a"), 2, 10000));
            HomeRules.Buy(_state, Item("carpet_a"));
            HomeRules.Buy(_state, Item("carpet_a"));
            Assert.AreEqual(2, HomeRules.OwnedItem(_def, _state, "carpet_a"));
            Assert.IsFalse(HomeRules.CanBuy(_def, _state, Item("carpet_a"), 2, 10000), "two carpet slots, two of this carpet owned");
            Assert.IsTrue(HomeRules.CanBuy(_def, _state, Item("carpet_b"), 2, 10000), "another variant is still buyable");
            HomeRules.TryPlaceFromStorage(_def, _state, Slot("living_carpet"), 2, out _);
            Assert.AreEqual(2, HomeRules.OwnedItem(_def, _state, "carpet_a"), "placed ones count too");
            Assert.IsFalse(HomeRules.CanBuy(_def, _state, Item("carpet_a"), 2, 10000));
        }

        [Test]
        public void Buy_NeedsMoney()
        {
            Assert.IsFalse(HomeRules.CanBuy(_def, _state, Item("carpet_b"), 2, 899));
            Assert.IsTrue(HomeRules.CanBuy(_def, _state, Item("carpet_b"), 2, 900));
        }

        [Test]
        public void Buy_RefusedWhenAreaClosed()
        {
            Assert.IsFalse(HomeRules.IsItemAvailable(_def, Item("bed"), 4), "no slot for the group at all");
            Assert.IsFalse(HomeRules.IsItemAvailable(_def, Item("bench"), 0));
            Assert.IsTrue(HomeRules.IsItemAvailable(_def, Item("bench"), 1));
            Assert.IsFalse(HomeRules.CanBuy(_def, _state, Item("bench"), 0, 100000));
        }

        [Test]
        public void StorageItem_PlacedThenSwapped_ComfortFollowsPlacedItem()
        {
            HomeRules.Buy(_state, Item("carpet_a"));
            HomeRules.Buy(_state, Item("carpet_b"));
            Assert.IsFalse(HomeRules.TryPlaceFromStorage(_def, _state, Slot("living_carpet"), 1, out _), "living closed at stage 1");
            Assert.IsTrue(HomeRules.TryPlaceFromStorage(_def, _state, Slot("living_carpet"), 2, out string placed));
            Assert.AreEqual("carpet_a", placed, "catalog order");
            Assert.AreEqual(0, _state.Storage.TryGetValue("carpet_a", out int a) ? a : 0);
            Assert.AreEqual(4, HomeRules.Comfort(_def, _state));

            var others = new List<string>();
            Assert.AreEqual(1, HomeRules.OtherVariants(_def, _state, Slot("living_carpet"), others));
            Assert.AreEqual("carpet_b", others[0]);

            Assert.IsTrue(HomeRules.Swap(_state, Slot("living_carpet"), "carpet_b"));
            Assert.AreEqual("carpet_b", _state.Placed["living_carpet"]);
            Assert.AreEqual(1, _state.Storage["carpet_a"]);
            Assert.AreEqual(6, HomeRules.Comfort(_def, _state));
            Assert.IsFalse(HomeRules.Swap(_state, Slot("living_carpet"), "bench"), "not in storage");
        }

        [Test]
        public void EmptySlot_NothingInStorage_NotPlaced()
        {
            Assert.IsFalse(HomeRules.TryPlaceFromStorage(_def, _state, Slot("yard_carpet"), 2, out _));
            HomeRules.Buy(_state, Item("bench"));
            Assert.IsFalse(HomeRules.TryPlaceFromStorage(_def, _state, Slot("yard_carpet"), 2, out _), "wrong group");
        }

        [Test]
        public void Comfort_CountsFactorySlots()
        {
            HomeRules.PlaceFactory(_state, Slot("living_sofa"));
            HomeRules.PlaceFactory(_state, Slot("living_chair1"));
            Assert.AreEqual(14, HomeRules.Comfort(_def, _state));
        }

        [Test]
        public void RoomGift_PaidOnce_EvenAfterSwap()
        {
            HomeRules.Buy(_state, Item("carpet_a"));
            HomeRules.Buy(_state, Item("carpet_b"));
            HomeRules.PlaceFactory(_state, Slot("living_sofa"));
            Assert.IsFalse(HomeRules.TryClaimGift(_def, _state, "living", out _), "not complete");
            HomeRules.PlaceFactory(_state, Slot("living_chair1"));
            HomeRules.TryPlaceFromStorage(_def, _state, Slot("living_carpet"), 2, out _);
            Assert.IsTrue(HomeRules.IsAreaComplete(_def, _state, "living"));
            Assert.IsTrue(HomeRules.TryClaimGift(_def, _state, "living", out long gift));
            Assert.AreEqual(5000, gift);
            HomeRules.Swap(_state, Slot("living_carpet"), "carpet_b");
            Assert.IsFalse(HomeRules.TryClaimGift(_def, _state, "living", out _));
            Assert.IsTrue(_state.RewardedAreas.Contains("living"));
        }

        [Test]
        public void SaleMultiplier_200Comfort_Is1_2()
        {
            Assert.AreEqual(1.2, HomeRules.SaleMultiplier(_def, 200), 1e-9);
            Assert.AreEqual(1.0, HomeRules.SaleMultiplier(_def, 0), 1e-9);
        }
    }
}
