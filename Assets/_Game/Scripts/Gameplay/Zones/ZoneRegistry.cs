using System.Collections.Generic;
using UnityEngine;

namespace FF.Gameplay.Zones
{
    /// <summary>
    /// All zones in creation order (the prototype's <c>zones</c> array: the first matching zone acts per tick).
    /// Filled by the scene builder; short list, plain distance checks, no physics.
    /// </summary>
    public sealed class ZoneRegistry : MonoBehaviour
    {
        [SerializeField] List<Zone> zones = new List<Zone>();

        public IReadOnlyList<Zone> Zones => zones;

        /// <summary>Editor tools only.</summary>
        public void SetZones(List<Zone> ordered) => zones = ordered;

        /// <summary>Horizontal distance (prototype <c>d2</c>).</summary>
        public static float Distance(Vector3 a, Vector3 b)
        {
            float dx = a.x - b.x, dz = a.z - b.z;
            return Mathf.Sqrt(dx * dx + dz * dz);
        }
    }
}
