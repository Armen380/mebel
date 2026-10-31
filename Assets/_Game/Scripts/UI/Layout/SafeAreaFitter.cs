using UnityEngine;

namespace FF.UI.Layout
{
    /// <summary>Fits this RectTransform to <see cref="Screen.safeArea"/> (notches, home indicator); updates on change.</summary>
    [RequireComponent(typeof(RectTransform))]
    public sealed class SafeAreaFitter : MonoBehaviour
    {
        RectTransform _rect;
        Rect _applied;
        Vector2Int _screen;

        void Awake() => _rect = (RectTransform)transform;

        void OnEnable() => Apply();

        void Update()
        {
            if (Screen.safeArea != _applied || Screen.width != _screen.x || Screen.height != _screen.y) Apply();
        }

        void Apply()
        {
            Rect safe = Screen.safeArea;
            _applied = safe;
            _screen = new Vector2Int(Screen.width, Screen.height);
            if (Screen.width <= 0 || Screen.height <= 0) return;
            _rect.anchorMin = new Vector2(safe.xMin / Screen.width, safe.yMin / Screen.height);
            _rect.anchorMax = new Vector2(safe.xMax / Screen.width, safe.yMax / Screen.height);
            _rect.offsetMin = Vector2.zero;
            _rect.offsetMax = Vector2.zero;
        }
    }
}
