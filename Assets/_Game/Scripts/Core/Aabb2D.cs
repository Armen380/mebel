using System;

namespace FF.Core
{
    /// <summary>Axis-aligned rectangle on the ground plane (Unity X/Z, metres).</summary>
    [Serializable]
    public struct Aabb2D : IEquatable<Aabb2D>
    {
        public float MinX;
        public float MaxX;
        public float MinZ;
        public float MaxZ;

        public Aabb2D(float minX, float maxX, float minZ, float maxZ)
        {
            MinX = minX;
            MaxX = maxX;
            MinZ = minZ;
            MaxZ = maxZ;
        }

        public bool Equals(Aabb2D o) =>
            MinX == o.MinX && MaxX == o.MaxX && MinZ == o.MinZ && MaxZ == o.MaxZ;

        public override bool Equals(object obj) => obj is Aabb2D o && Equals(o);

        public override int GetHashCode() => HashCode.Combine(MinX, MaxX, MinZ, MaxZ);

        public override string ToString() => $"[x {MinX}..{MaxX}, z {MinZ}..{MaxZ}]";
    }
}
