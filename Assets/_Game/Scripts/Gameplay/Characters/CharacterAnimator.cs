using UnityEngine;

namespace FF.Gameplay.Characters
{
    /// <summary>
    /// Procedural walk / carry / chop animation of the prototype's <c>animChar()</c>.
    /// The owner (player or AI) sets the state every frame; this component only poses the rig.
    /// </summary>
    [RequireComponent(typeof(CharacterRig))]
    public sealed class CharacterAnimator : MonoBehaviour
    {
        const float TurnRate = 13f;
        const float PoseRate = 14f;
        const float StrideRate = 11f;
        const float LegSwing = 0.7f;
        const float ArmSwing = 0.55f;
        const float CarryArmAngle = -1.25f;
        const float WalkBob = 0.07f;
        const float IdleBreath = 0.012f;
        const float ChopRate = 14f;

        public bool Moving { get; set; }
        public bool Carrying { get; set; }
        public bool Chopping { get; set; }
        public bool AlwaysShowAxe { get; set; }
        /// <summary>Target heading in degrees around Unity Y (0 = +Z).</summary>
        public float FacingYaw { get; set; }

        CharacterRig _rig;
        // Current limb angles (radians around local X). Kept here because Euler angles read back from a
        // Transform are ambiguous past ±90°, which the chop swing reaches.
        float _hipL, _hipR, _armL, _armR;
        float _stride;
        float _chopPhase;
        float _seed;

        void Awake()
        {
            _rig = GetComponent<CharacterRig>();
            _seed = Random.value * 9f;
            FacingYaw = transform.eulerAngles.y;
        }

        void LateUpdate()
        {
            float dt = Time.deltaTime;
            float k = 1f - Mathf.Exp(-dt * PoseRate);

            float yaw = Mathf.LerpAngle(transform.eulerAngles.y, FacingYaw, 1f - Mathf.Exp(-dt * TurnRate));
            transform.rotation = Quaternion.Euler(0f, yaw, 0f);

            if (Moving) _stride += dt * StrideRate;
            float s = Moving ? Mathf.Sin(_stride) : 0f;

            _hipL = Approach(_hipL, s * LegSwing, k);
            _hipR = Approach(_hipR, -s * LegSwing, k);

            float t = Time.time;
            float bob = _rig.isRobot ? 0.05f + Mathf.Sin(t * 4f + _seed) * 0.04f
                : Moving ? Mathf.Abs(Mathf.Sin(_stride)) * WalkBob
                : Mathf.Sin(t * 2f + _seed) * IdleBreath;
            Vector3 bp = _rig.body.localPosition;
            _rig.body.localPosition = new Vector3(bp.x, bob, bp.z);

            _armL = Approach(_armL, Carrying ? CarryArmAngle : -s * ArmSwing, k);
            if (Chopping)
            {
                _chopPhase += dt * ChopRate;
                _armR = -1.9f + Mathf.Sin(_chopPhase) * 1.05f;
            }
            else _armR = Approach(_armR, Carrying ? CarryArmAngle : s * ArmSwing, k);

            SetX(_rig.hipLeft, _hipL);
            SetX(_rig.hipRight, _hipR);
            SetX(_rig.shoulderLeft, _armL);
            SetX(_rig.shoulderRight, _armR);

            if (_rig.axe != null)
            {
                bool showAxe = Chopping || AlwaysShowAxe;
                if (_rig.axe.activeSelf != showAxe) _rig.axe.SetActive(showAxe);
            }
        }

        static float Approach(float current, float target, float k) => current + (target - current) * k;

        // Prototype angles are radians around X; the rig is built in prototype-local axes, so signs carry over.
        static void SetX(Transform t, float rad)
        {
            if (t != null) t.localRotation = Quaternion.Euler(rad * Mathf.Rad2Deg, 0f, 0f);
        }
    }
}
