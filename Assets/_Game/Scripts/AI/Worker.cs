using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Shop;
using FF.Gameplay.Zones;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.AI
{
    /// <summary>
    /// One hired worker: its rig, hands and the per-worker fields of the prototype agents (<c>mode, job, phase, cool,
    /// stuck, tree, dst, reg, post, tg</c>). Driven by <see cref="WorkerDirector"/>. Robots show their task tag.
    /// </summary>
    [RequireComponent(typeof(CharacterRig), typeof(CharacterAnimator))]
    public sealed class Worker : MonoBehaviour, IWorldTagSource
    {
        const string Table = "Game";

        [SerializeField] WorkerKind kind;

        readonly List<Vector3> _via = new List<Vector3>(2);
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        int _viaIndex;
        Vector3 _viaFor = new Vector3(float.NaN, 0f, 0f);
        WorkerJob _job;
        string _tagText;
        float _tagHeight, _tagPerItem;

        public WorkerKind Kind => kind;
        public int Index { get; private set; }
        public CharacterAnimator Animator { get; private set; }
        public ItemStack Hands { get; private set; }
        public float Speed { get; private set; }
        public int Capacity { get; private set; }
        public Chopper Chopper { get; } = new Chopper();

        // lumberjack
        public bool Delivering;
        public ResourceNode Tree;
        public IPile Destination;
        // carrier / stocker / robot
        public bool Putting;
        public float Cooldown;
        public float Stuck;
        // cashier / manager
        public Register Register;
        public bool Posted;

        /// <summary>Current carry job; robots rebuild their task tag when it changes.</summary>
        public WorkerJob Job
        {
            get => _job;
            set
            {
                _job = value;
                _tagText = null;
            }
        }

        /// <summary>Editor tools only.</summary>
        public void SetKind(WorkerKind workerKind) => kind = workerKind;

        public void Init(int index, float speed, int capacity, ItemCatalog catalog, float tagHeight, float tagPerItem)
        {
            Index = index;
            Speed = speed;
            Capacity = capacity;
            _tagHeight = tagHeight;
            _tagPerItem = tagPerItem;
            Animator = GetComponent<CharacterAnimator>();
            Hands = new ItemStack(GetComponent<CharacterRig>().carryAnchor, CarryLayout.Instance, catalog, () => Capacity);
            if (kind == WorkerKind.Robot && Services.TryGet(out WorldTagRegistry tags)) tags.Register(this);
        }

        void OnEnable() => LocalizationSettings.SelectedLocaleChanged += OnLocale;

        void OnDisable() => LocalizationSettings.SelectedLocaleChanged -= OnLocale;

        void OnLocale(UnityEngine.Localization.Locale locale) => _tagText = null;

        void OnDestroy()
        {
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        public bool MoveTo(Vector3 target, float dt, float speed) => AgentMotor.MoveTo(transform, Animator, target, dt, speed);

        /// <summary>
        /// Prototype <c>goTo</c>: walks the way-points of the trip first (recomputed when the target changes), then the target.
        /// </summary>
        public bool GoTo(Vector3 target, float dt, WorldLayout.WorkerLayoutSettings layout, float fenceZ)
        {
            if ((target - _viaFor).sqrMagnitude > 1e-4f)
            {
                _viaFor = target;
                WorkerRoutes.Via(transform.position, target, layout, fenceZ, _via);
                _viaIndex = 0;
            }
            if (_viaIndex < _via.Count)
            {
                if (MoveTo(_via[_viaIndex], dt, Speed)) _viaIndex++;
                return false;
            }
            return MoveTo(target, dt, Speed);
        }

        // ---------- robot task tag (prototype .chip.bot) ----------

        public bool TagVisible => _job != null && _job.Label != JobLabel.None;
        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = transform.position;
                p.y = _tagHeight + Hands.Count * _tagPerItem;
                return p;
            }
        }
        public WorldTagStyle TagStyle => WorldTagStyle.Bot;
        public int TagCount => 0;
        public int TagCapacity => 0;
        public long TagValue => 0;
        public string TagIcon => null;
        public string TagText => _tagText ??= BuildTag();

        string BuildTag()
        {
            if (_job == null) return null;
            if (_job.Label == JobLabel.Truck) return LocalizationSettings.StringDatabase.GetLocalizedString(Table, "job.truck");
            _args.Clear();
            _args["name"] = LocalizationSettings.StringDatabase.GetLocalizedString(Table, _job.ProductNameKey);
            string text = LocalizationSettings.StringDatabase.GetLocalizedString(Table, _job.Label == JobLabel.Shelf ? "job.shelf" : "job.planks",
                new object[] { _args });
            return _job.Urgent ? "<b>!</b> " + text : text;
        }
    }
}
