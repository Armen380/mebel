using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Progress;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.World
{
    /// <summary>
    /// Dark chip over a closed lot (prototype <c>addLabel(…, 'locked')</c>): "Sofas / Opens at Lv 5" until the player
    /// reaches the factory's level, the sign of a not yet bought building, or a fixed text ("Dream house / Soon").
    /// The text is rebuilt only when the language or the state changes.
    /// </summary>
    public sealed class LockedLabel : MonoBehaviour, IWorldTagSource
    {
        public enum Kind
        {
            /// <summary>lk.lv: product sign + its unlock level, while the player level is below it.</summary>
            FactoryLevel,
            /// <summary>The owner's sign key, while the owner is not owned.</summary>
            NotOwned,
            /// <summary>Always shows <c>textKey</c>.</summary>
            Fixed,
        }

        const string Table = "Game";

        [SerializeField] Kind kind;
        [SerializeField] string ownerId;
        [Tooltip("NotOwned: sign key; Fixed: text key. FactoryLevel uses lk.lv with the product sign.")]
        [SerializeField] string textKey;

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        WorldStateSnapshot _state;
        GameProgress _progress;
        ProductDef _product;
        string _text;

        /// <summary>Editor tools only.</summary>
        public void Setup(Kind labelKind, string owner, string key)
        {
            kind = labelKind;
            ownerId = owner;
            textKey = key;
        }

        void Awake()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _progress = Services.Get<GameProgress>();
            if (kind == Kind.FactoryLevel) _product = Services.Get<GameDatabase>().Product(ownerId);
        }

        void Start() => Services.Get<WorldTagRegistry>().Register(this);

        void OnEnable() => LocalizationSettings.SelectedLocaleChanged += OnLocale;

        void OnDisable() => LocalizationSettings.SelectedLocaleChanged -= OnLocale;

        void OnDestroy()
        {
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        void OnLocale(Locale locale) => _text = null;

        public bool TagVisible
        {
            get
            {
                switch (kind)
                {
                    case Kind.FactoryLevel: return !_state.Owns(ownerId) && _progress.Level < _product.unlockLevel;
                    case Kind.NotOwned: return !_state.Owns(ownerId);
                    default: return true;
                }
            }
        }

        public string TagText => _text ??= Build();

        string Build()
        {
            if (kind != Kind.FactoryLevel) return LocalizationSettings.StringDatabase.GetLocalizedString(Table, textKey);
            _args.Clear();
            _args["sign"] = LocalizationSettings.StringDatabase.GetLocalizedString(Table, _product.signKey);
            _args["n"] = _product.unlockLevel;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, "lk.lv", new object[] { _args });
        }

        public Vector3 TagPosition => transform.position;
        public WorldTagStyle TagStyle => WorldTagStyle.Locked;
        public int TagCount => 0;
        public int TagCapacity => 0;
        public long TagValue => 0;
        public string TagIcon => null;
    }
}
