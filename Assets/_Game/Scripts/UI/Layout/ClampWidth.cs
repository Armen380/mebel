using UnityEngine;

namespace FF.UI.Layout
{
    /// <summary>CSS <c>width: min(max, 100%)</c>: a centred panel as wide as its parent, at most <see cref="max"/>.</summary>
    [RequireComponent(typeof(RectTransform))]
    public sealed class ClampWidth : MonoBehaviour
    {
        [SerializeField] float max = 560f * 1080f / 390f;

        RectTransform _rect, _parent;
        float _applied = -1f;

        public void Setup(float maxWidth) => max = maxWidth;

        void Awake()
        {
            _rect = (RectTransform)transform;
            _parent = (RectTransform)transform.parent;
        }

        void LateUpdate()
        {
            float w = Mathf.Min(max, _parent.rect.width);
            if (Mathf.Abs(w - _applied) < 0.5f) return;
            _applied = w;
            _rect.anchorMin = new Vector2(0.5f, _rect.anchorMin.y);
            _rect.anchorMax = new Vector2(0.5f, _rect.anchorMax.y);
            _rect.sizeDelta = new Vector2(w, _rect.sizeDelta.y);
        }
    }
}
