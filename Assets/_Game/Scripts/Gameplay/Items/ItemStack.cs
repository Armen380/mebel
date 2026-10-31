using System;
using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>
    /// Prototype <c>class Stack</c>: items parented to an anchor in a layout, plus a count of items still flying in.
    /// <see cref="Count"/> includes the incoming ones, so capacity checks are race-free. A non-fixed stack takes the
    /// type of its first item and becomes untyped again when it empties.
    /// </summary>
    public sealed class ItemStack
    {
        readonly List<Item> _items = new List<Item>();
        readonly ItemCatalog _catalog;
        readonly bool _fixedType;
        readonly Func<int> _capacity;

        public Transform Anchor { get; }
        public IStackLayout Layout { get; }
        public ItemType Type { get; private set; }
        public int Incoming { get; private set; }

        /// <summary>Settled items plus items in flight toward this stack (prototype <c>n</c>).</summary>
        public int Count => _items.Count + Incoming;
        /// <summary>Items already in place (prototype <c>items.length</c>).</summary>
        public int Settled => _items.Count;
        public int Capacity => _capacity();
        public bool HasRoom => Count < Capacity;

        /// <param name="fixedType">Pass <see cref="ItemType.None"/> for a stack that takes the type of its items.</param>
        public ItemStack(Transform anchor, IStackLayout layout, ItemCatalog catalog, Func<int> capacity, ItemType fixedType = ItemType.None)
        {
            Anchor = anchor;
            Layout = layout;
            _catalog = catalog;
            _capacity = capacity ?? throw new ArgumentNullException(nameof(capacity));
            _fixedType = fixedType != ItemType.None;
            Type = fixedType;
        }

        public Item this[int index] => _items[index];

        /// <summary>World position of the next free slot for an item of <paramref name="type"/> (live flight target).</summary>
        public Vector3 NextSlotWorld(ItemType type) =>
            Anchor.TransformPoint(Layout.SlotPosition(_items.Count, _catalog.Height(type)));

        /// <summary>An item starts flying here (prototype <c>sendTo</c> start).</summary>
        public void BeginIncoming(ItemType type)
        {
            Incoming++;
            if (!_fixedType) Type = type;
        }

        /// <summary>A flight landed: parent the item to the anchor in its layout slot (prototype <c>sendTo</c> end).</summary>
        public void CompleteIncoming(Item item)
        {
            Incoming = Mathf.Max(0, Incoming - 1);
            Place(item);
        }

        /// <summary>Puts an item straight into its slot (no flight).</summary>
        public void Place(Item item)
        {
            _items.Add(item);
            Transform t = item.transform;
            t.SetParent(Anchor, false);
            t.localPosition = Layout.SlotPosition(_items.Count - 1, _catalog.Height(item.Type));
            t.localRotation = Layout.SlotRotation;
            t.localScale = Vector3.one;
        }

        /// <summary>Removes the top item (prototype <c>pop</c>); the item stays where it is in the hierarchy.</summary>
        public Item Pop()
        {
            if (_items.Count == 0) return null;
            int last = _items.Count - 1;
            Item item = _items[last];
            _items.RemoveAt(last);
            if (!_fixedType && Count == 0) Type = ItemType.None;
            return item;
        }

        /// <summary>Moves every settled item into <paramref name="into"/> (prototype <c>throwAll</c> splice).</summary>
        public void TakeAll(List<Item> into)
        {
            into.AddRange(_items);
            _items.Clear();
            if (!_fixedType && Incoming == 0) Type = ItemType.None;
        }
    }
}
