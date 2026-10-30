using System.Collections.Generic;
using System.Globalization;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Art
{
    /// <summary>
    /// Flat-shaded low-poly meshes matching the prototype's three.js geometries (flatShading: true).
    /// Each mesh is saved once as an asset in <see cref="Folder"/> and reused.
    /// </summary>
    public static class LowPolyMeshFactory
    {
        public const string Folder = "Assets/_Game/Art/Meshes";

        /// <summary>Unit cube (Unity built-in).</summary>
        public static Mesh Cube => Resources.GetBuiltinResource<Mesh>("Cube.fbx");

        /// <summary>1×1 horizontal quad facing up, centred on the origin.</summary>
        public static Mesh Plane() => GetOrCreate("Plane", () =>
        {
            var b = new Builder();
            Vector3 a = new Vector3(-0.5f, 0, -0.5f), c = new Vector3(0.5f, 0, 0.5f);
            b.Tri(a, new Vector3(-0.5f, 0, 0.5f), c, Vector3.up);
            b.Tri(a, c, new Vector3(0.5f, 0, -0.5f), Vector3.up);
            return b;
        });

        /// <summary>Icosahedron of radius 1 (three.js IcosahedronGeometry, detail 0).</summary>
        public static Mesh Icosahedron() => GetOrCreate("Icosahedron", () =>
        {
            float t = (1f + Mathf.Sqrt(5f)) / 2f;
            Vector3[] v =
            {
                new(-1, t, 0), new(1, t, 0), new(-1, -t, 0), new(1, -t, 0),
                new(0, -1, t), new(0, 1, t), new(0, -1, -t), new(0, 1, -t),
                new(t, 0, -1), new(t, 0, 1), new(-t, 0, -1), new(-t, 0, 1),
            };
            int[] f =
            {
                0, 11, 5, 0, 5, 1, 0, 1, 7, 0, 7, 10, 0, 10, 11, 1, 5, 9, 5, 11, 4, 11, 10, 2, 10, 7, 6, 7, 1, 8,
                3, 9, 4, 3, 4, 2, 3, 2, 6, 3, 6, 8, 3, 8, 9, 4, 9, 5, 2, 4, 11, 6, 2, 10, 8, 6, 7, 9, 8, 1,
            };
            var b = new Builder();
            for (int i = 0; i < f.Length; i += 3)
                b.TriOutward(v[f[i]].normalized, v[f[i + 1]].normalized, v[f[i + 2]].normalized, Vector3.zero);
            return b;
        });

        /// <summary>Capped cylinder/cone of height 1 centred on the origin (three.js CylinderGeometry). Scale Y for height.</summary>
        public static Mesh Cylinder(float radiusTop, float radiusBottom, int segments)
        {
            string name = string.Format(CultureInfo.InvariantCulture, "Cylinder_{0:0.###}_{1:0.###}_{2}", radiusTop, radiusBottom, segments);
            return GetOrCreate(name, () =>
            {
                var b = new Builder();
                Vector3 top = new Vector3(0, 0.5f, 0), bottom = new Vector3(0, -0.5f, 0);
                for (int i = 0; i < segments; i++)
                {
                    float a0 = i * Mathf.PI * 2f / segments, a1 = (i + 1) * Mathf.PI * 2f / segments;
                    Vector3 d0 = new Vector3(Mathf.Sin(a0), 0, Mathf.Cos(a0)), d1 = new Vector3(Mathf.Sin(a1), 0, Mathf.Cos(a1));
                    Vector3 t0 = top + d0 * radiusTop, t1 = top + d1 * radiusTop;
                    Vector3 b0 = bottom + d0 * radiusBottom, b1 = bottom + d1 * radiusBottom;
                    b.TriOutward(t0, b0, b1, Vector3.zero);
                    b.TriOutward(t0, b1, t1, Vector3.zero);
                    if (radiusTop > 0) b.Tri(top, t1, t0, Vector3.up);
                    if (radiusBottom > 0) b.Tri(bottom, b0, b1, Vector3.down);
                }
                return b;
            });
        }

        /// <summary>Upper half of a sphere of radius 1 (three.js SphereGeometry(r, 10, 6, 0, 2π, 0, π/2)), open at the bottom.</summary>
        public static Mesh Hemisphere() => GetOrCreate("Hemisphere", () =>
        {
            const int w = 10, h = 3; // 6 rows over π → 3 rows over π/2
            var b = new Builder();
            for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
            {
                Vector3 p00 = Sphere(x, y), p10 = Sphere(x + 1, y), p01 = Sphere(x, y + 1), p11 = Sphere(x + 1, y + 1);
                if (y > 0) b.TriOutward(p00, p10, p11, Vector3.zero);
                b.TriOutward(p00, p11, p01, Vector3.zero);
            }
            return b;

            static Vector3 Sphere(int x, int y)
            {
                float phi = x * Mathf.PI * 2f / w, theta = y * (Mathf.PI / 2f) / h;
                return new Vector3(-Mathf.Cos(phi) * Mathf.Sin(theta), Mathf.Cos(theta), Mathf.Sin(phi) * Mathf.Sin(theta));
            }
        });

        static Mesh GetOrCreate(string name, System.Func<Builder> build)
        {
            string path = $"{Folder}/{name}.asset";
            var mesh = AssetDatabase.LoadAssetAtPath<Mesh>(path);
            if (mesh != null) return mesh;
            DataImporter.EnsureFolder(Folder);
            mesh = build().ToMesh(name);
            AssetDatabase.CreateAsset(mesh, path);
            return mesh;
        }

        /// <summary>Triangle soup with one face normal per triangle (flat shading).</summary>
        sealed class Builder
        {
            readonly List<Vector3> _v = new List<Vector3>();
            readonly List<Vector3> _n = new List<Vector3>();
            readonly List<int> _t = new List<int>();

            /// <summary>Adds a triangle whose front side faces <paramref name="facing"/>.</summary>
            public void Tri(Vector3 a, Vector3 b, Vector3 c, Vector3 facing)
            {
                Vector3 n = Vector3.Cross(b - a, c - a);
                if (n.sqrMagnitude < 1e-12f) return;
                if (Vector3.Dot(n, facing) < 0) (b, c) = (c, b);
                Vector3 normal = Vector3.Cross(b - a, c - a).normalized;
                int i = _v.Count;
                _v.Add(a); _v.Add(b); _v.Add(c);
                _n.Add(normal); _n.Add(normal); _n.Add(normal);
                _t.Add(i); _t.Add(i + 1); _t.Add(i + 2);
            }

            /// <summary>Adds a triangle facing away from <paramref name="center"/> (convex shapes).</summary>
            public void TriOutward(Vector3 a, Vector3 b, Vector3 c, Vector3 center) => Tri(a, b, c, (a + b + c) / 3f - center);

            public Mesh ToMesh(string name)
            {
                var m = new Mesh { name = name };
                m.SetVertices(_v);
                m.SetNormals(_n);
                m.SetTriangles(_t, 0);
                m.RecalculateBounds();
                return m;
            }
        }
    }
}
