using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>Prototype <c>updTweens</c> path: straight lerp start → target plus a sine bump of <c>arc</c> metres.</summary>
    public static class ItemArc
    {
        public static Vector3 Evaluate(Vector3 start, Vector3 target, float k, float arc)
        {
            k = Mathf.Clamp01(k);
            Vector3 p = Vector3.LerpUnclamped(start, target, k);
            p.y += Mathf.Sin(k * Mathf.PI) * arc;
            return p;
        }
    }
}
