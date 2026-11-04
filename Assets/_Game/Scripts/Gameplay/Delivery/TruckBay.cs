using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Zones;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Delivery
{
    /// <summary>
    /// One truck bay (prototype <c>bays[i]</c>): shown while i &lt; 1 + parking level, its "TRUCK" dock zone lends the parked
    /// truck's bed as its pile, the marker is bright only with a truck, and the chip says what the bay is waiting for.
    /// </summary>
    public sealed class TruckBay : MonoBehaviour, IWorldTagSource
    {
        const string Table = "Game";
        public const string ParkingPadId = "parking";
        static readonly int BaseColor = Shader.PropertyToID("_BaseColor");

        [SerializeField] int index;
        [SerializeField] Zone dock;
        [Tooltip("Bay asphalt, lines and dock in the blockout; hidden while the bay is closed.")]
        [SerializeField] GameObject visual;

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        MaterialPropertyBlock _block;
        Renderer[] _markerRenderers;
        TMP_Text[] _markerTexts;
        IUpgradeLevels _levels;
        DeliveryDirector _director;
        WorldLayout.DeliverySettings _settings;
        int _bays;
        float _markerAlpha = -1f;
        BayTagKind _tagKind = BayTagKind.Hidden;
        int _tagSeconds = -1;
        string _tagText;

        public int Index => index;
        public Zone Dock => dock;
        public float ProtoX => _settings.baysX[index];
        public bool IsActive => index < EconomyConfig.ActiveBays(_levels.GetLevel(ParkingPadId), _bays);
        /// <summary>The truck holding the bay (arriving, parked or pulling out), or null.</summary>
        public Truck Truck { get; set; }

        /// <summary>Editor tools only.</summary>
        public void Setup(int bayIndex, Zone dockZone, GameObject bayVisual)
        {
            index = bayIndex;
            dock = dockZone;
            visual = bayVisual;
        }

        public void Init(DeliveryDirector director, int bayCount)
        {
            _director = director;
            _bays = bayCount;
        }

        void Awake()
        {
            var db = Services.Get<GameDatabase>();
            _settings = db.world.delivery;
            _levels = Services.Get<IUpgradeLevels>();
            dock.Configure(new PileLayout(_settings.truckBed), () => 0, () => IsActive, db.items, db.economy.zoneRadius, 0f);
            _block = new MaterialPropertyBlock();
            _markerTexts = dock.Marker.GetComponentsInChildren<TMP_Text>(true);
            var quads = new List<Renderer>();
            foreach (MeshRenderer r in dock.Marker.GetComponentsInChildren<MeshRenderer>(true))
                if (r.GetComponent<TMP_Text>() == null) quads.Add(r);
            _markerRenderers = quads.ToArray();
        }

        void OnEnable()
        {
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Register(this);
        }

        void OnDisable()
        {
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        void OnLocale(UnityEngine.Localization.Locale locale) => _tagText = null;

        void LateUpdate()
        {
            bool active = IsActive;
            if (visual != null && visual.activeSelf != active) visual.SetActive(active);
            SetMarkerAlpha(Truck != null && Truck.Motion.Phase == TruckPhase.Docked ? 1f : _settings.idleDockOpacity);
        }

        /// <summary>Prototype: the dock marker is opaque with a parked truck, faded otherwise (the TMP texts follow).</summary>
        void SetMarkerAlpha(float alpha)
        {
            if (Mathf.Approximately(alpha, _markerAlpha)) return;
            _markerAlpha = alpha;
            for (int i = 0; i < _markerRenderers.Length; i++)
            {
                Renderer r = _markerRenderers[i];
                r.GetPropertyBlock(_block);
                _block.SetColor(BaseColor, new Color(1f, 1f, 1f, alpha));
                r.SetPropertyBlock(_block);
            }
            for (int i = 0; i < _markerTexts.Length; i++) _markerTexts[i].alpha = alpha;
        }

        // ---------- chip ----------

        BayTagKind Kind(out int seconds) =>
            DeliveryRules.BayTag(index, IsActive, Truck != null ? Truck.Motion : null, _director.Motions, out seconds);

        public bool TagVisible => _director != null && Kind(out _) != BayTagKind.Hidden;

        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = dock.Position;
                p.y = _settings.bayTagHeight;
                return p;
            }
        }

        public WorldTagStyle TagStyle => Kind(out _) == BayTagKind.Load ? WorldTagStyle.Counter : WorldTagStyle.Note;
        public int TagCount => Truck != null ? Truck.Bed.Count : 0;
        public int TagCapacity => _director.OrderSize;
        public long TagValue => 0;
        public string TagIcon => null;

        public string TagText
        {
            get
            {
                BayTagKind kind = Kind(out int seconds);
                if (_tagText != null && kind == _tagKind && (kind != BayTagKind.FreeIn || seconds == _tagSeconds)) return _tagText;
                _tagKind = kind;
                _tagSeconds = seconds;
                switch (kind)
                {
                    case BayTagKind.NoTruck: _tagText = Text("c.noTruck"); break;
                    case BayTagKind.Arriving: _tagText = Text("c.arriving"); break;
                    case BayTagKind.Free: _tagText = Text("c.free"); break;
                    case BayTagKind.FreeIn:
                        _args.Clear();
                        _args["n"] = seconds;
                        _tagText = LocalizationSettings.StringDatabase.GetLocalizedString(Table, "c.freeIn", new object[] { _args });
                        break;
                    default: _tagText = null; break;
                }
                return _tagText;
            }
        }

        static string Text(string key) => LocalizationSettings.StringDatabase.GetLocalizedString(Table, key);
    }
}
