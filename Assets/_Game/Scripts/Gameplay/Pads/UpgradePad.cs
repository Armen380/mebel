using FF.Core;
using FF.Data;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using TMPro;
using UnityEngine;

namespace FF.Gameplay.Pads
{
    /// <summary>
    /// A ground pad the player pays into (prototype <c>addPad</c> + <c>drawPad</c>): honey square, green fill rising
    /// with the paid share, glyph and the remaining price. Paying itself is done by <see cref="PadSystem"/>.
    /// </summary>
    public sealed class UpgradePad : MonoBehaviour
    {
        static readonly int BaseMapSt = Shader.PropertyToID("_BaseMap_ST");

        [SerializeField] PadDef def;
        [SerializeField] PadRule rule;
        [Tooltip("Building the rule looks at (saw, saw2, a product id); empty for shop / register pads.")]
        [SerializeField] string owner;
        [SerializeField] GameObject visual;
        [SerializeField] Transform fill;
        [SerializeField] TMP_Text priceLabel;

        const string ShopPadId = "shop", RegisterPadId = "reg";

        EconomyConfig _economy;
        WorldStateSnapshot _state;
        GameProgress _progress;
        int _ownerUnlockLevel;
        int _tutorialSteps;
        GameProgress.PadState _pad;
        MaterialPropertyBlock _block;
        Renderer _fillRenderer;
        float _size;
        long _priceKey = -1;
        int _fillKey = -1;

        public PadDef Def => def;
        public GameProgress.PadState State => _pad;
        public Vector3 Position => transform.position;
        public long Price => _economy.PadPrice(def, _pad.Level);
        public bool IsVisible => PadRules.IsVisible(rule, _pad.Level, def.maxLevel, OwnerDone, _progress.Level, _ownerUnlockLevel,
            _progress.GetLevel(RegisterPadId), _progress.GetLevel(ShopPadId));

        /// <summary>
        /// The owner condition: a building is owned, or for <see cref="PadRule.AfterPad"/> the previous pad (owner) is
        /// bought — with no owner, the tutorial is done.
        /// </summary>
        bool OwnerDone => rule == PadRule.AfterPad
            ? (string.IsNullOrEmpty(owner) ? _progress.QuestStep >= _tutorialSteps : _progress.GetLevel(owner) >= 1)
            : !string.IsNullOrEmpty(owner) && _state.Owns(owner);

        /// <summary>Editor tools only.</summary>
        public void Setup(PadDef padDef, PadRule padRule, string ownerId, GameObject visualRoot, Transform fillQuad, TMP_Text price)
        {
            def = padDef;
            rule = padRule;
            owner = ownerId;
            visual = visualRoot;
            fill = fillQuad;
            priceLabel = price;
        }

        void Awake()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _state = Services.Get<WorldStateSnapshot>();
            _progress = Services.Get<GameProgress>();
            _pad = _progress.Pad(def.id);
            ProductDef product = string.IsNullOrEmpty(owner) ? null : db.Product(owner);
            _ownerUnlockLevel = rule == PadRule.BuyOwner && product != null ? product.unlockLevel : 0;
            _tutorialSteps = db.tutorial != null ? db.tutorial.steps.Count : 0;
            _block = new MaterialPropertyBlock();
            _fillRenderer = fill.GetComponent<Renderer>();
            _size = Services.Get<GameDatabase>().world.production.padSize;
        }

        void LateUpdate()
        {
            bool show = IsVisible;
            if (visual.activeSelf != show) visual.SetActive(show);
            if (!show) return;

            long price = Price, remaining = price - _pad.Paid;
            long key = NumberFormat.CompactChangeKey(remaining);
            if (key != _priceKey)
            {
                _priceKey = key;
                priceLabel.SetText(NumberFormat.Money(remaining));
            }

            // prototype redraws at 1/60 steps of progress
            int fillKey = Mathf.RoundToInt(Mathf.Clamp01((float)_pad.Paid / price) * 60f);
            if (fillKey == _fillKey) return;
            _fillKey = fillKey;
            float k = fillKey / 60f;
            fill.gameObject.SetActive(k > 0f);
            fill.localScale = new Vector3(_size, 1f, _size * k);
            fill.localPosition = new Vector3(0f, fill.localPosition.y, -_size / 2f + _size * k / 2f);
            _fillRenderer.GetPropertyBlock(_block);
            _block.SetVector(BaseMapSt, new Vector4(1f, k, 0f, 0f));
            _fillRenderer.SetPropertyBlock(_block);
        }
    }
}
