using System.Collections.Generic;
using FF.Core;
using UnityEngine;

namespace FF.Gameplay.Movement
{
    /// <summary>Circle-vs-AABB push-out on the ground plane, exactly like the prototype's <c>collide()</c> block loop.</summary>
    public static class CollisionResolver
    {
        /// <param name="pos">Ground position (Unity x, z).</param>
        /// <param name="radius">Character radius (prototype 0.3).</param>
        public static void PushOut(ref Vector2 pos, float radius, IReadOnlyList<Aabb2D> blockers)
        {
            for (int i = 0; i < blockers.Count; i++)
            {
                Aabb2D b = blockers[i];
                float minX = b.MinX - radius, maxX = b.MaxX + radius;
                float minZ = b.MinZ - radius, maxZ = b.MaxZ + radius;
                if (pos.x <= minX || pos.x >= maxX || pos.y <= minZ || pos.y >= maxZ) continue;

                // Leave through the nearest side. Ties resolve in the prototype's order: west, east,
                // then the far side (proto min z = Unity max z), then the near side.
                float dl = pos.x - minX, dr = maxX - pos.x, df = maxZ - pos.y, dn = pos.y - minZ;
                float m = Mathf.Min(Mathf.Min(dl, dr), Mathf.Min(df, dn));
                if (m == dl) pos.x = minX;
                else if (m == dr) pos.x = maxX;
                else if (m == df) pos.y = maxZ;
                else pos.y = minZ;
            }
        }
    }
}
