using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// Dream House (M10, Design/data/dream_house.json): rooms and the yard (areas), the fixed furniture slots, the Home
    /// Store catalog and the comfort bonus. Construction stages are pads (house_found … house_windows in pads.json).
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Home", fileName = "Home")]
    public sealed class HomeDef : ScriptableObject
    {
        [Tooltip("Sale price bonus per comfort point (0.001 · 200 = +20 % for the best house).")]
        public double comfortBonusPerPoint = 0.001;
        public List<AreaDef> areas = new List<AreaDef>();
        public List<SlotDef> slots = new List<SlotDef>();
        [Tooltip("Home Store catalog, in display order (also the order storage items are placed in).")]
        public List<HomeItemDef> items = new List<HomeItemDef>();

        Dictionary<string, AreaDef> _areas;
        Dictionary<string, SlotDef> _slots;
        Dictionary<string, HomeItemDef> _items;

        public AreaDef Area(string id) => Lookup(ref _areas, areas, id, a => a.id);
        public SlotDef Slot(string id) => Lookup(ref _slots, slots, id, s => s.id);
        public HomeItemDef Item(string id) => Lookup(ref _items, items, id, i => i.id);

        void OnValidate() => ClearCaches();

        public void ClearCaches()
        {
            _areas = null;
            _slots = null;
            _items = null;
        }

        static T Lookup<T>(ref Dictionary<string, T> cache, List<T> list, string id, Func<T, string> key) where T : class
        {
            if (cache == null)
            {
                cache = new Dictionary<string, T>(list.Count);
                foreach (T item in list)
                    if (item != null) cache[key(item)] = item;
            }
            return id != null && cache.TryGetValue(id, out T found) ? found : null;
        }

        [Serializable]
        public sealed class AreaDef
        {
            public string id;
            public string nameKey;
            [Tooltip("House stages needed before the area's slots open (1 foundation, 2 walls).")]
            public int requiresStage;
            [Tooltip("One-time cash gift when every slot of the area is filled.")]
            public long gift;
        }

        [Serializable]
        public sealed class SlotDef
        {
            public string id;
            public string area;
            [Tooltip("Factory slot: the product carried in. None = Home Store slot (see group).")]
            public ItemType product;
            [Tooltip("Home Store slot: the catalog group it accepts (carpet, lamp, …). Empty for factory slots.")]
            public string group;
            [Tooltip("Comfort of a factory slot; Home Store slots take the comfort of the placed item.")]
            public int comfort;
            [Tooltip("Prototype coordinates (x, z).")]
            public Vector2 protoPos;
            [Tooltip("Facing, degrees around y (0 = toward the camera / road).")]
            public float yaw;

            public bool IsFactory => product != ItemType.None;
        }

        [Serializable]
        public sealed class HomeItemDef
        {
            public string id;
            public string group;
            public string nameKey;
            [Tooltip("Final dollars (no ECON multiplier).")]
            public long price;
            public int comfort;
        }
    }
}
