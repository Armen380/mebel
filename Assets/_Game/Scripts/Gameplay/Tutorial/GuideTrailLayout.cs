using UnityEngine;

namespace FF.Gameplay.Tutorial
{
    /// <summary>One floor arrow of the guide trail: ground position and size factor (0..1).</summary>
    public struct GuideMark
    {
        public float X, Z, Scale;
    }

    /// <summary>Where the guide-trail arrows go along the straight line from the player to the target.</summary>
    public static class GuideTrailLayout
    {
        /// <summary>
        /// Fills <paramref name="into"/> with arrows every <paramref name="spacing"/> metres from
        /// <paramref name="startGap"/> after the start to <paramref name="endGap"/> before the end, shifted by
        /// <paramref name="phase"/> (so they slide toward the target), growing over <paramref name="fade"/> metres at both
        /// ends. Returns how many were placed; <paramref name="yawDegrees"/> points from start to end (Unity yaw, +Z = 0).
        /// </summary>
        public static int Build(float fromX, float fromZ, float toX, float toZ, float phase, float spacing, float startGap,
            float endGap, float fade, GuideMark[] into, out float yawDegrees)
        {
            float dx = toX - fromX, dz = toZ - fromZ;
            float length = Mathf.Sqrt(dx * dx + dz * dz);
            yawDegrees = length > 1e-5f ? Mathf.Atan2(dx, dz) * Mathf.Rad2Deg : 0f;
            float end = length - endGap;
            if (spacing <= 0f || end <= startGap) return 0;
            float ux = dx / length, uz = dz / length;
            phase %= spacing;
            if (phase < 0f) phase += spacing;
            int n = 0;
            for (float d = startGap + phase; d < end && n < into.Length; d += spacing)
            {
                float edge = Mathf.Min(d - startGap, end - d);
                into[n++] = new GuideMark
                {
                    X = fromX + ux * d, Z = fromZ + uz * d, Scale = fade > 0f ? Mathf.Clamp01(edge / fade) : 1f,
                };
            }
            return n;
        }
    }
}
