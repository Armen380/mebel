using System.Collections.Generic;
using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>
    /// One pool per item type, prewarmed from the <see cref="ItemCatalog"/>. Released items are deactivated and
    /// parented here; nothing is instantiated in play unless a pool runs dry (logged once per type).
    /// </summary>
    public sealed class ItemPool : MonoBehaviour
    {
        readonly Dictionary<ItemType, Stack<Item>> _free = new Dictionary<ItemType, Stack<Item>>();
        readonly HashSet<ItemType> _warnedEmpty = new HashSet<ItemType>();
        ItemCatalog _catalog;

        public ItemCatalog Catalog => _catalog;

        void Awake()
        {
            _catalog = Services.Get<GameDatabase>().items;
            foreach (ItemCatalog.Entry e in _catalog.entries)
            {
                Stack<Item> free = FreeList(e.type);
                for (int i = free.Count; i < e.prewarm; i++) free.Push(Create(e));
            }
        }

        /// <summary>Takes an item of <paramref name="type"/> and places it at a world position, active.</summary>
        public Item Get(ItemType type, Vector3 position)
        {
            Stack<Item> free = FreeList(type);
            Item item;
            if (free.Count > 0) item = free.Pop();
            else
            {
                if (_warnedEmpty.Add(type)) Debug.LogWarning($"[FF] Item pool '{type}' ran dry; raise its prewarm in ItemCatalog.", this);
                item = Create(_catalog.Find(type));
            }
            Transform t = item.transform;
            t.SetParent(null, false);
            t.SetPositionAndRotation(position, Quaternion.identity);
            t.localScale = Vector3.one;
            item.Value = 0;
            item.gameObject.SetActive(true);
            return item;
        }

        public void Release(Item item)
        {
            item.gameObject.SetActive(false);
            item.transform.SetParent(transform, false);
            FreeList(item.Type).Push(item);
        }

        Stack<Item> FreeList(ItemType type)
        {
            if (!_free.TryGetValue(type, out Stack<Item> list))
            {
                list = new Stack<Item>();
                _free.Add(type, list);
            }
            return list;
        }

        Item Create(ItemCatalog.Entry entry)
        {
            GameObject go = Instantiate(entry.prefab, transform);
            go.name = entry.prefab.name;
            go.SetActive(false);
            return go.GetComponent<Item>();
        }
    }
}
