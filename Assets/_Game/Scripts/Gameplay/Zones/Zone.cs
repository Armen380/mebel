using System;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using UnityEngine;

namespace FF.Gameplay.Zones
{
    /// <summary>
    /// Prototype <c>addZone</c>: a ground marker with a pile. The owner (machine, shelf, register) calls
    /// <see cref="Configure"/> once; the player and AI query zones through the <see cref="ZoneRegistry"/>.
    /// </summary>
    public sealed class Zone : MonoBehaviour, IWorldTagSource
    {
        [SerializeField] string id;
        [SerializeField] ZoneKind kind;
        [Tooltip("Item type this zone accepts (drop) or holds (pickup).")]
        [SerializeField] ItemType itemType;
        [SerializeField] Transform pileAnchor;
        [SerializeField] GameObject marker;
        [SerializeField] bool showCounter = true;
        [Tooltip("Counter = n/cap over the pile; Cash = sum of the bills on it.")]
        [SerializeField] WorldTagStyle tagStyle = WorldTagStyle.Counter;

        Func<bool> _active;
        bool _markerShown = true;
        float _counterHeight;

        public string Id => id;
        public ZoneKind Kind => kind;
        public ItemType ItemType => itemType;
        public ItemStack Stack { get; private set; }
        public float Radius { get; private set; } = 1.3f;
        public bool IsActive => Stack != null && (_active == null || _active());
        public Vector3 Position => transform.position;

        /// <summary>Editor tools only.</summary>
        public void Setup(string zoneId, ZoneKind zoneKind, ItemType type, Transform anchor, GameObject markerObject)
        {
            id = zoneId;
            kind = zoneKind;
            itemType = type;
            pileAnchor = anchor;
            marker = markerObject;
            tagStyle = zoneKind == ZoneKind.Cash ? WorldTagStyle.Cash : WorldTagStyle.Counter;
        }

        public void Configure(IStackLayout layout, Func<int> capacity, Func<bool> active, ItemCatalog catalog, float radius, float counterHeight)
        {
            Stack = new ItemStack(pileAnchor, layout, catalog, capacity, itemType);
            _active = active;
            Radius = radius;
            _counterHeight = counterHeight;
            if (showCounter && Services.TryGet(out WorldTagRegistry tags)) tags.Register(this);
        }

        void LateUpdate()
        {
            bool shown = IsActive;
            if (shown == _markerShown || marker == null) return;
            _markerShown = shown;
            marker.SetActive(shown);
        }

        void OnDestroy()
        {
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        public bool TagVisible => IsActive && (tagStyle != WorldTagStyle.Cash || Stack.Settled > 0);
        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = pileAnchor.position;
                p.y = _counterHeight;
                return p;
            }
        }
        public WorldTagStyle TagStyle => tagStyle;
        public int TagCount => Stack.Count;
        public int TagCapacity => Stack.Capacity;
        public string TagIcon => null;

        /// <summary>Sum of the bills lying on the pile (prototype register chip).</summary>
        public long TagValue
        {
            get
            {
                long sum = 0;
                for (int i = 0; i < Stack.Settled; i++) sum += Stack[i].Value;
                return sum;
            }
        }
    }
}
