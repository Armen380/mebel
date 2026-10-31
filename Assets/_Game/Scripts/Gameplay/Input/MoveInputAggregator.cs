using FF.Core;
using UnityEngine;
using UnityEngine.InputSystem;

namespace FF.Gameplay.Input
{
    /// <summary>Joystick (touch) + Move action (keyboard / gamepad) → one movement vector, length ≤ 1.</summary>
    public sealed class MoveInputAggregator : MonoBehaviour, IMoveInput
    {
        [SerializeField] InputActionReference moveAction;
        [Tooltip("Optional on-screen joystick implementing IMoveInput.")]
        [SerializeField] MonoBehaviour joystickSource;

        IMoveInput _joystick;

        public Vector2 Value
        {
            get
            {
                Vector2 keys = moveAction != null ? moveAction.action.ReadValue<Vector2>() : Vector2.zero;
                Vector2 joy = _joystick != null ? _joystick.Value : Vector2.zero;
                return MoveInputMath.Combine(joy, keys);
            }
        }

        void Awake() => _joystick = joystickSource as IMoveInput;

        void OnEnable()
        {
            if (moveAction != null) moveAction.action.Enable();
        }

        void OnDisable()
        {
            if (moveAction != null) moveAction.action.Disable();
        }

        void OnValidate()
        {
            if (joystickSource != null && !(joystickSource is IMoveInput))
            {
                Debug.LogWarning($"{joystickSource.name} does not implement IMoveInput.", this);
                joystickSource = null;
            }
        }
    }
}
