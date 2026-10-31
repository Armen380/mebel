using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Zones;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class ItemStackTests
    {
        readonly List<Object> _created = new List<Object>();
        ItemCatalog _catalog;

        [SetUp]
        public void SetUp()
        {
            _catalog = ScriptableObject.CreateInstance<ItemCatalog>();
            _catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Log, stackHeight = 0.3f });
            _catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Plank, stackHeight = 0.11f });
            _catalog.entries.Add(new ItemCatalog.Entry { type = ItemType.Chair, stackHeight = 0.5f });
            _created.Add(_catalog);
        }

        [TearDown]
        public void TearDown()
        {
            foreach (Object o in _created) Object.DestroyImmediate(o);
            _created.Clear();
        }

        ItemStack Stack(int capacity, ItemType fixedType = ItemType.None, IStackLayout layout = null)
        {
            var anchor = new GameObject("Anchor");
            _created.Add(anchor);
            return new ItemStack(anchor.transform, layout ?? CarryLayout.Instance, _catalog, () => capacity, fixedType);
        }

        Item NewItem(ItemType type)
        {
            var go = new GameObject(type.ToString());
            _created.Add(go);
            Item item = go.AddComponent<Item>();
            item.SetType(type);
            return item;
        }

        void Land(ItemStack s, ItemType type)
        {
            s.BeginIncoming(type);
            s.CompleteIncoming(NewItem(type));
        }

        [Test]
        public void NonFixedStack_TakesTypeOfFirstIncomingItem()
        {
            ItemStack s = Stack(5);
            Assert.AreEqual(ItemType.None, s.Type);
            s.BeginIncoming(ItemType.Log);
            Assert.AreEqual(ItemType.Log, s.Type);
            Assert.AreEqual(1, s.Count, "in-flight items count");
            Assert.AreEqual(0, s.Settled);
        }

        [Test]
        public void Pop_LastItem_ClearsTypeOfNonFixedStack()
        {
            ItemStack s = Stack(5);
            Land(s, ItemType.Plank);
            Assert.NotNull(s.Pop());
            Assert.AreEqual(ItemType.None, s.Type);
            Assert.IsNull(s.Pop());
        }

        [Test]
        public void Pop_KeepsTypeWhileItemsAreStillFlyingIn()
        {
            ItemStack s = Stack(5);
            Land(s, ItemType.Log);
            s.BeginIncoming(ItemType.Log);
            s.Pop();
            Assert.AreEqual(ItemType.Log, s.Type);
        }

        [Test]
        public void FixedStack_KeepsItsType()
        {
            ItemStack s = Stack(5, ItemType.Plank);
            Land(s, ItemType.Plank);
            s.Pop();
            Assert.AreEqual(ItemType.Plank, s.Type);
        }

        [Test]
        public void HasRoom_CountsIncomingItems()
        {
            ItemStack s = Stack(2);
            Land(s, ItemType.Log);
            Assert.IsTrue(s.HasRoom);
            s.BeginIncoming(ItemType.Log);
            Assert.IsFalse(s.HasRoom);
        }

        [Test]
        public void Place_PutsItemInItsLayoutSlot()
        {
            ItemStack s = Stack(5);
            Land(s, ItemType.Log);
            Land(s, ItemType.Log);
            Item second = s[1];
            Assert.AreSame(s.Anchor, second.transform.parent);
            Assert.That(Vector3.Distance(new Vector3(0, 0.3f, 0), second.transform.localPosition), Is.LessThan(1e-5f));
            Assert.That(Quaternion.Angle(Quaternion.Euler(0, 180, 0), second.transform.localRotation), Is.LessThan(0.01f));
        }

        [Test]
        public void NextSlotWorld_FollowsSettledCount()
        {
            ItemStack s = Stack(5);
            s.Anchor.position = new Vector3(1, 2, 3);
            Land(s, ItemType.Chair);
            Assert.That(Vector3.Distance(new Vector3(1, 2.5f, 3), s.NextSlotWorld(ItemType.Chair)), Is.LessThan(1e-5f));
        }

        [Test]
        public void TakeAll_EmptiesStack_AndClearsTypeWhenNothingFliesIn()
        {
            ItemStack s = Stack(5);
            Land(s, ItemType.Log);
            Land(s, ItemType.Log);
            var into = new List<Item>();
            s.TakeAll(into);
            Assert.AreEqual(2, into.Count);
            Assert.AreEqual(0, s.Count);
            Assert.AreEqual(ItemType.None, s.Type);
        }

        [Test]
        public void TakeAll_KeepsTypeWhileItemsFlyIn()
        {
            ItemStack s = Stack(5);
            Land(s, ItemType.Log);
            s.BeginIncoming(ItemType.Log);
            s.TakeAll(new List<Item>());
            Assert.AreEqual(ItemType.Log, s.Type);
            Assert.AreEqual(1, s.Count);
        }

        // ---------- layouts (prototype carryLayout / pileLayout, z mirrored to Unity) ----------

        [Test]
        public void CarryLayout_IsAColumn()
        {
            Assert.That(Vector3.Distance(new Vector3(0, 0.33f, 0), CarryLayout.Instance.SlotPosition(3, 0.11f)), Is.LessThan(1e-5f));
        }

        [Test]
        public void PileLayout_OneColumnThreeRows_LogPile()
        {
            var l = new PileLayout(1, 3, 0f, 0.34f);
            Assert.That(Vector3.Distance(new Vector3(0, 0, 0.34f), l.SlotPosition(0, 0.3f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(0, 0, 0f), l.SlotPosition(1, 0.3f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(0, 0, -0.34f), l.SlotPosition(2, 0.3f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(0, 0.3f, 0.34f), l.SlotPosition(3, 0.3f)), Is.LessThan(1e-5f));
        }

        [Test]
        public void PileLayout_TwoByTwo_ProductPile()
        {
            var l = new PileLayout(2, 2, 0.72f, 0.62f);
            Assert.That(Vector3.Distance(new Vector3(-0.36f, 0, 0.31f), l.SlotPosition(0, 0.5f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(0.36f, 0, 0.31f), l.SlotPosition(1, 0.5f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(-0.36f, 0, -0.31f), l.SlotPosition(2, 0.5f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(-0.36f, 0.5f, 0.31f), l.SlotPosition(4, 0.5f)), Is.LessThan(1e-5f));
        }

        [Test]
        public void ItemArc_StartsAndEndsOnTarget_PeaksInTheMiddle()
        {
            Vector3 a = new Vector3(0, 0, 0), b = new Vector3(2, 0, 0);
            Assert.AreEqual(a, ItemArc.Evaluate(a, b, 0f, 1f));
            Assert.That(Vector3.Distance(b, ItemArc.Evaluate(a, b, 1f, 1f)), Is.LessThan(1e-5f));
            Assert.That(Vector3.Distance(new Vector3(1, 1, 0), ItemArc.Evaluate(a, b, 0.5f, 1f)), Is.LessThan(1e-5f));
        }

        // ---------- zone transfer rules (prototype updPlayer zone loop) ----------

        [Test]
        public void CanDrop_NeedsMatchingTypeAndRoom()
        {
            ItemStack hands = Stack(5), zone = Stack(1, ItemType.Log, new PileLayout(1, 3, 0, 0.34f));
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, ItemType.Log, zone), "empty hands");
            Land(hands, ItemType.Plank);
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, ItemType.Log, zone), "wrong type");
            hands.Pop();
            Land(hands, ItemType.Log);
            Assert.IsTrue(ZoneTransferRules.CanDrop(hands, ItemType.Log, zone));
            Land(zone, ItemType.Log);
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, ItemType.Log, zone), "zone full");
        }

        [Test]
        public void CanDrop_IgnoresItemsStillFlyingToTheHands()
        {
            ItemStack hands = Stack(5), zone = Stack(10, ItemType.Log);
            hands.BeginIncoming(ItemType.Log);
            Assert.IsFalse(ZoneTransferRules.CanDrop(hands, ItemType.Log, zone));
        }

        [Test]
        public void CanPickup_EmptyOrSameTypeHandsWithRoom()
        {
            ItemStack zone = Stack(30, ItemType.Plank), hands = Stack(1);
            Assert.IsFalse(ZoneTransferRules.CanPickup(zone, hands), "zone empty");
            Land(zone, ItemType.Plank);
            Assert.IsTrue(ZoneTransferRules.CanPickup(zone, hands));
            Land(hands, ItemType.Log);
            Assert.IsFalse(ZoneTransferRules.CanPickup(zone, hands), "other type in hands");
            hands.Pop();
            Land(hands, ItemType.Plank);
            Assert.IsFalse(ZoneTransferRules.CanPickup(zone, hands), "hands full");
        }
    }
}
