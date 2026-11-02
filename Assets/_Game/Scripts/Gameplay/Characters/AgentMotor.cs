using UnityEngine;

namespace FF.Gameplay.Characters
{
    /// <summary>Prototype <c>moveTo(a, target, dt, speed)</c> for customers and workers: straight step, face the walking direction.</summary>
    public static class AgentMotor
    {
        public const float ArriveDistance = 0.06f;

        /// <returns>True when the agent is (now) within <see cref="ArriveDistance"/> of the target.</returns>
        public static bool MoveTo(Transform agent, CharacterAnimator animator, Vector3 target, float dt, float speed)
        {
            Vector3 p = agent.position;
            float dx = target.x - p.x, dz = target.z - p.z, d = Mathf.Sqrt(dx * dx + dz * dz);
            if (d < ArriveDistance)
            {
                animator.Moving = false;
                return true;
            }
            float step = Mathf.Min(d, speed * dt);
            p.x += dx / d * step;
            p.z += dz / d * step;
            agent.position = p;
            animator.FacingYaw = Mathf.Atan2(dx, dz) * Mathf.Rad2Deg;
            animator.Moving = true;
            return d - step < ArriveDistance;
        }

        /// <summary>Prototype facing angle (radians, proto axes) → Unity yaw in degrees.</summary>
        public static float YawFromPrototype(float protoRadians) => 180f - protoRadians * Mathf.Rad2Deg;
    }
}
