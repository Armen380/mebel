using UnityEngine;

namespace FF.Gameplay.Production
{
    /// <summary>Working parts of a building: the saw blade spins, the press hammer bobs while the machine is busy.</summary>
    public sealed class MachineVisual : MonoBehaviour
    {
        const float BladeSpeed = 18f;
        const float PressFrequency = 16f;
        const float PressAngle = 0.7f;
        const float PressSettle = 0.9f;

        [SerializeField] Transform sawBlade;
        [SerializeField] Transform press;

        float _pressAngle;

        public bool Busy { get; set; }

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform blade, Transform pressPart)
        {
            sawBlade = blade;
            press = pressPart;
        }

        void Update()
        {
            float dt = Time.deltaTime;
            if (sawBlade != null && Busy) sawBlade.Rotate(0f, 0f, -BladeSpeed * dt * Mathf.Rad2Deg, Space.Self);
            if (press != null)
            {
                _pressAngle = Busy ? Mathf.Max(0f, Mathf.Sin(Time.time * PressFrequency)) * PressAngle : _pressAngle * PressSettle;
                // prototype rotation.x; X rotations flip sign in Unity space
                press.localRotation = Quaternion.Euler(-_pressAngle * Mathf.Rad2Deg, 0f, 0f);
            }
        }
    }
}
