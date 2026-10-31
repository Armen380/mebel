using UnityEngine;

namespace FF.Gameplay.Input
{
    public static class MoveInputMath
    {
        /// <summary>Below this length the stick counts as released (prototype <c>mag &gt; .12</c>).</summary>
        public const float DeadZone = 0.12f;

        /// <summary>Sum of joystick and keyboard, normalised when longer than 1 (prototype <c>inputVec()</c>).</summary>
        public static Vector2 Combine(Vector2 joystick, Vector2 keys)
        {
            Vector2 v = joystick + keys;
            float m = v.magnitude;
            return m > 1f ? v / m : v;
        }

        public static bool IsActive(Vector2 input) => input.magnitude > DeadZone;
    }
}
