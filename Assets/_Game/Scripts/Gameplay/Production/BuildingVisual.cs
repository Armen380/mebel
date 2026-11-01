using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Effects;
using FF.Gameplay.World;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Production
{
    /// <summary>
    /// A factory building that grows with its speed / qty pad levels (prototype <c>setBuildingLevel</c>, building part of
    /// <c>updMachine</c>, <c>refreshBuilding</c>): rebuilds the deco, pops in when bought, bounces with confetti and an
    /// output text on upgrades, spins fans, sways the flag, puffs chimney smoke, and shows the "Lv 3 · ×2" tag.
    /// </summary>
    public sealed class BuildingVisual : MonoBehaviour, IWorldTagSource
    {
        const string Table = "Game";
        const float PopRate = 2.2f, BounceDecay = 1.8f;
        const float FanIdleSpeed = 2.5f, FanBusySpeed = 14f;
        const float SmokeInterval = 0.45f, SmokeIdleRate = 0.3f, SmokePerSpeedLevel = 0.2f;
        const float FlagSwing = 0.25f, FlagFrequency = 3f;
        const float TagAboveTop = 0.4f, TagBehind = 0.6f;
        const float UpgradeTextAbove = 1.2f;

        [SerializeField] Machine machine;
        [SerializeField] Transform deco;
        [SerializeField] Color wall;
        [SerializeField] Color roof;
        [SerializeField] BuildingFader fader;

        readonly List<BuildingPart> _parts = new List<BuildingPart>(64);
        readonly List<Vector3> _chimneys = new List<Vector3>(2);
        readonly List<Transform> _spawned = new List<Transform>(64);
        readonly List<Transform> _fans = new List<Transform>(1);
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        BuildingKit _kit;
        IUpgradeLevels _levels;
        EffectsSystem _effects;
        Transform _flag;
        string _speedId, _qtyId;
        int _speed = -1, _qty = -1;
        float _top, _pop = 1f, _bounce, _smokeTimer;

        public int Speed => _speed;
        public int Qty => _qty;
        public float Top => _top;

        /// <summary>Editor tools only.</summary>
        public void Setup(Machine machineRef, Transform decoRoot, Color wallColor, Color roofColor, BuildingFader buildingFader)
        {
            machine = machineRef;
            deco = decoRoot;
            wall = wallColor;
            roof = roofColor;
            fader = buildingFader;
        }

        void Awake()
        {
            _kit = Services.Get<GameDatabase>().buildingKit;
            _levels = Services.Get<IUpgradeLevels>();
            _speedId = machine.Id + "_speed";
            _qtyId = machine.Id + "_qty";
        }

        void Start()
        {
            _effects = Services.Get<EffectsSystem>();
            Services.Get<WorldTagRegistry>().Register(this);
            Rebuild();
        }

        void OnEnable() => GameEvents.PadCompleted += OnPadCompleted;

        void OnDisable() => GameEvents.PadCompleted -= OnPadCompleted;

        void OnDestroy()
        {
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        /// <summary>Prototype <c>b.pop = 0</c>: the building scales in elastically (just bought).</summary>
        public void PlayPop() => _pop = 0f;

        void OnPadCompleted(string padId, int level)
        {
            if (padId != _speedId && padId != _qtyId) return;
            Rebuild();
            _bounce = 1f;
            Vector3 top = transform.position;
            top.y = _top;
            _effects.Burst(top);
            _args.Clear();
            _args["k"] = 1 + _qty;
            _args["c"] = machine.OutputZone.Stack.Capacity;
            top.y = _top + UpgradeTextAbove;
            GameEvents.RaiseFloatText(top, LocalizationSettings.StringDatabase.GetLocalizedString(Table, "f.cap", new object[] { _args }));
        }

        void LateUpdate()
        {
            if (_levels.GetLevel(_speedId) != _speed || _levels.GetLevel(_qtyId) != _qty) Rebuild();
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            Animate(dt);
            if (!machine.IsActive) return;

            bool busy = machine.Core.Busy;
            float fanSpeed = (busy ? FanBusySpeed : FanIdleSpeed) * Mathf.Rad2Deg * dt;
            for (int i = 0; i < _fans.Count; i++) _fans[i].Rotate(0f, -fanSpeed, 0f, Space.Self);
            if (_flag != null) _flag.localRotation = Quaternion.Euler(0f, -Mathf.Sin(Time.time * FlagFrequency) * FlagSwing * Mathf.Rad2Deg, 0f);

            if (_chimneys.Count == 0) return;
            _smokeTimer -= dt * (busy ? 1f : SmokeIdleRate) * (1f + SmokePerSpeedLevel * _speed);
            if (_smokeTimer > 0f) return;
            _smokeTimer = SmokeInterval;
            for (int i = 0; i < _chimneys.Count; i++) _effects.Puff(transform.TransformPoint(_chimneys[i]));
        }

        /// <summary>Prototype pop (elastic scale-in) and bounce (y +16 %, xz −6 %, decaying sine).</summary>
        void Animate(float dt)
        {
            if (_pop < 1f)
            {
                _pop = Mathf.Min(1f, _pop + dt * PopRate);
                float k = _pop - 1f;
                transform.localScale = Vector3.one * Mathf.Max(0.01f, 1f + 2.2f * k * k * k + 1.2f * k * k);
            }
            else if (_bounce > 0f)
            {
                _bounce = Mathf.Max(0f, _bounce - dt * BounceDecay);
                float w = Mathf.Sin((1f - _bounce) * Mathf.PI * 4f) * _bounce;
                transform.localScale = new Vector3(1f - 0.06f * w, 1f + 0.16f * w, 1f - 0.06f * w);
            }
        }

        void Rebuild()
        {
            _speed = _levels.GetLevel(_speedId);
            _qty = _levels.GetLevel(_qtyId);
            for (int i = deco.childCount - 1; i >= 0; i--) Destroy(deco.GetChild(i).gameObject);
            _spawned.Clear();
            _fans.Clear();
            _flag = null;

            _top = BuildingGrowthLayout.Build(_speed, _qty, wall, roof, _kit, _parts, _chimneys);
            // layout works in prototype axes; the deco lives under the building in Unity axes (z mirrored)
            for (int i = 0; i < _chimneys.Count; i++) _chimneys[i] = Mirror(_chimneys[i]);
            for (int i = 0; i < _parts.Count; i++) _spawned.Add(Spawn(_parts[i]));
            if (fader != null) fader.Refresh();
        }

        Transform Spawn(BuildingPart part)
        {
            var go = new GameObject(part.Shape.ToString());
            Transform t = go.transform;
            t.SetParent(part.Parent < 0 ? deco : _spawned[part.Parent], false);
            t.localPosition = Mirror(part.Position);
            t.localRotation = Quaternion.Euler(-part.RotationX * Mathf.Rad2Deg, -part.RotationY * Mathf.Rad2Deg, 0f);
            if (part.Shape != PartShape.Group)
            {
                t.localScale = part.Size;
                go.AddComponent<MeshFilter>().sharedMesh = MeshOf(part.Shape);
                go.AddComponent<MeshRenderer>().sharedMaterial = _kit.palette.Find(part.Color);
            }
            if (part.Role == PartRole.FanBlades) _fans.Add(t);
            else if (part.Role == PartRole.Flag) _flag = t;
            return t;
        }

        Mesh MeshOf(PartShape shape)
        {
            switch (shape)
            {
                case PartShape.FanHousing: return _kit.fanCylinder;
                case PartShape.Tank: return _kit.tankCylinder;
                case PartShape.TankLid: return _kit.tankLidCylinder;
                default: return _kit.cube;
            }
        }

        static Vector3 Mirror(Vector3 proto) => new Vector3(proto.x, proto.y, -proto.z);

        // ---------- Lv tag (prototype chip: "Lv 3 · ×2", MAX at 11 combined levels) ----------

        public bool TagVisible => machine.IsActive && (fader == null || !fader.IsFaded) && isActiveAndEnabled;
        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = transform.position;
                p.y = _top * transform.localScale.y + TagAboveTop;
                p.z += TagBehind;
                return p;
            }
        }
        public WorldTagStyle TagStyle => WorldTagStyle.Level;
        /// <summary>Combined level s + q.</summary>
        public int TagCount => _speed + _qty;
        /// <summary>Output multiplier 1 + q.</summary>
        public int TagCapacity => 1 + _qty;
        public long TagValue => 0;
        public string TagIcon => null;
    }
}
