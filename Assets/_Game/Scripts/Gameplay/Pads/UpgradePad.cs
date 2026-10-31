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
        [Tooltip("Machine that must be owned for the pad to show (saw, saw2, a product id); empty = always.")]
        [SerializeField] string ownerMachine;
        [SerializeField] GameObject visual;
        [SerializeField] Transform fill;
        [SerializeField] TMP_Text priceLabel;

        EconomyConfig _economy;
        WorldStateSnapshot _state;
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
        public bool IsVisible => (string.IsNullOrEmpty(ownerMachine) || _state.Owns(ownerMachine)) && _pad.Level < def.maxLevel;

        /// <summary>Editor tools only.</summary>
        public void Setup(PadDef padDef, string owner, GameObject visualRoot, Transform fillQuad, TMP_Text price)
        {
            def = padDef;
            ownerMachine = owner;
            visual = visualRoot;
            fill = fillQuad;
            priceLabel = price;
        }

        void Awake()
        {
            _economy = Services.Get<GameDatabase>().economy;
            _state = Services.Get<WorldStateSnapshot>();
            _pad = Services.Get<GameProgress>().Pad(def.id);
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
