using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.Layout
{
    /// <summary>
    /// CSS <c>width: max-content; max-width: calc(100% − margins)</c> for a TMP text inside an auto-sized panel:
    /// the text keeps its natural width while it fits and wraps onto more lines once it would leave the screen.
    /// Recomputed only when the text or the available width changes.
    /// </summary>
    [RequireComponent(typeof(TMP_Text), typeof(LayoutElement))]
    public sealed class WrapToWidth : MonoBehaviour
    {
        [Tooltip("Area whose width limits the text (usually the safe area).")]
        [SerializeField] RectTransform bounds;
        [Tooltip("Width taken by everything else in the row: margins, paddings, spacing (canvas units).")]
        [SerializeField] float reserved;
        [Tooltip("Optional sibling in the same row whose width is reserved too (e.g. the step chip).")]
        [SerializeField] RectTransform sibling;

        TMP_Text _text;
        LayoutElement _layout;
        string _lastText;
        float _lastMax = -1f;

        /// <summary>Editor tools only.</summary>
        public void Setup(RectTransform area, float reservedWidth, RectTransform siblingRect)
        {
            bounds = area;
            reserved = reservedWidth;
            sibling = siblingRect;
        }

        void Awake()
        {
            _text = GetComponent<TMP_Text>();
            _layout = GetComponent<LayoutElement>();
            _text.textWrappingMode = TextWrappingModes.Normal;
        }

        void LateUpdate()
        {
            float max = bounds.rect.width - reserved - (sibling != null ? sibling.rect.width : 0f);
            string text = _text.text;
            if (ReferenceEquals(text, _lastText) && Mathf.Approximately(max, _lastMax)) return;
            _lastText = text;
            _lastMax = max;
            float natural = _text.GetPreferredValues(text, float.PositiveInfinity, float.PositiveInfinity).x;
            _layout.preferredWidth = Mathf.Max(0f, Mathf.Min(natural, max));
        }
    }
}
