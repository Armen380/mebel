using UnityEngine;

namespace FF.Core
{
    /// <summary>
    /// The single place where prototype coordinates (three.js: +x east, +z south, y up)
    /// become Unity coordinates (x, y, -z). Everything at runtime works in Unity space.
    /// </summary>
    public static class ProtoCoords
    {
        public static Vector3 ToUnity(float x, float z) => new Vector3(x, 0f, -z);

        public static Vector3 ToUnity(float x, float y, float z) => new Vector3(x, y, -z);

        /// <summary>Proto ground point stored as Vector2(x, z).</summary>
        public static Vector3 ToUnity(Vector2 protoXZ) => new Vector3(protoXZ.x, 0f, -protoXZ.y);

        /// <summary>Proto ground point → Unity ground point as Vector2(x, z).</summary>
        public static Vector2 ToUnityXZ(float x, float z) => new Vector2(x, -z);

        public static float ToUnityZ(float protoZ) => -protoZ;

        /// <summary>Proto rectangle [x1..x2] × [z1..z2] → Unity rectangle (z range is mirrored).</summary>
        public static Aabb2D ToUnityRect(float x1, float x2, float z1, float z2) => new Aabb2D(x1, x2, -z2, -z1);
    }
}
