using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// Per item type: stack height (prototype <c>H</c> table — not in Design/data JSON), prefab and how many
    /// instances the pool creates up front. Filled by FF/Build Item Prefabs.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Item Catalog", fileName = "ItemCatalog")]
    public sealed class ItemCatalog : ScriptableObject
    {
        [Serializable]
        public sealed class Entry
        {
            public ItemType type;
            [Tooltip("Height of one item in a column/pile layer (m).")]
            public float stackHeight;
            public GameObject prefab;
            public int prewarm;
        }

        public List<Entry> entries = new List<Entry>();

        Entry[] _byType;

        public float Height(ItemType type) => Find(type)?.stackHeight ?? 0f;

        public GameObject Prefab(ItemType type) => Find(type)?.prefab;

        public Entry Find(ItemType type)
        {
            if (_byType == null)
            {
                _byType = new Entry[Enum.GetValues(typeof(ItemType)).Length];
                foreach (Entry e in entries)
                    if (e != null) _byType[(int)e.type] = e;
            }
            int i = (int)type;
            return i >= 0 && i < _byType.Length ? _byType[i] : null;
        }

        void OnValidate() => _byType = null;

        public void ClearCache() => _byType = null;
    }
}
