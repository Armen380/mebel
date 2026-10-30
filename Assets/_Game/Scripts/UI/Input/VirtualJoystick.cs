using FF.Core;
using UnityEngine;
using UnityEngine.EventSystems;

namespace FF.UI.Input
{
    /// <summary>
    /// Floating joystick: touching anywhere on this (full-screen, transparent) area shows the base there;
    /// dragging moves the knob up to <see cref="radius"/>. Value: x = right, y = up/forward, length ≤ 1.
    /// Other UI above this area (buttons) receives touches first. Works with the mouse in the Editor.
    /// </summary>
    [RequireComponent(typeof(RectTransform))]
    public sealed class VirtualJoystick : MonoBehaviour, IMoveInput, IPointerDownHandler, IDragHandler, IPointerUpHandler
    {
        [SerializeField] RectTransform stickBase;
        [SerializeField] RectTransform knob;
        [Tooltip("Knob travel in canvas units (prototype: 52 CSS px).")]
        [SerializeField] float radius = 140f;

        RectTransform _area;
        int _pointerId = int.MinValue;
        Vector2 _origin;

        public Vector2 Value { get; private set; }

        void Awake()
        {
            _area = (RectTransform)transform;
            Show(false);
        }

        void OnDisable() => Release();

        public void OnPointerDown(PointerEventData e)
        {
            if (_pointerId != int.MinValue) return;
            if (!ToLocal(e, out _origin)) return;
            _pointerId = e.pointerId;
            stickBase.anchoredPosition = _origin;
            knob.anchoredPosition = Vector2.zero;
            Value = Vector2.zero;
            Show(true);
        }

        public void OnDrag(PointerEventData e)
        {
            if (e.pointerId != _pointerId || !ToLocal(e, out Vector2 p)) return;
            Vector2 d = Vector2.ClampMagnitude(p - _origin, radius);
            knob.anchoredPosition = d;
            Value = d / radius;
        }

        public void OnPointerUp(PointerEventData e)
        {
            if (e.pointerId == _pointerId) Release();
        }

        /// <summary>Drops the current touch (e.g. when a panel opens over the game).</summary>
        public void Release()
        {
            _pointerId = int.MinValue;
            Value = Vector2.zero;
            Show(false);
        }

        bool ToLocal(PointerEventData e, out Vector2 local) =>
            RectTransformUtility.ScreenPointToLocalPointInRectangle(_area, e.position, e.pressEventCamera, out local);

        void Show(bool visible)
        {
            if (stickBase != null) stickBase.gameObject.SetActive(visible);
        }
    }
}
