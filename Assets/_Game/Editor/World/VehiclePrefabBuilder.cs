using System.Collections.Generic;
using FF.Gameplay.CarPark;
using FF.Gameplay.Delivery;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.World
{
    /// <summary>
    /// The delivery truck (prototype <c>makeTruck</c>) and one customer car per prototype <c>CAR_COLORS</c> entry
    /// (<c>makeCar</c>), built from boxes and cylinders. Models face +Z (prototype local +z, not mirrored); each wheel
    /// sits under a pivot that the runtime spins about X.
    /// </summary>
    public static class VehiclePrefabBuilder
    {
        public const string Folder = "Assets/_Game/Prefabs/Vehicles";
        public const string TruckPath = Folder + "/Truck.prefab";

        // prototype CAR_COLORS
        static readonly int[] CarColors = { 0xd9573b, 0x3a6ea5, 0xf3b33d, 0x5cae4a, 0xfbf1de, 0x2b1d14, 0x8d5fd3, 0x2a9d8f };

        [MenuItem("FF/Build Vehicle Prefabs", priority = 25)]
        static void BuildMenu()
        {
            BuildTruck(true);
            BuildCars(true);
        }

        /// <param name="rebuild">False keeps an existing prefab (stable file ids).</param>
        public static Truck BuildTruck(bool rebuild)
        {
            DataImporter.EnsureFolder(Folder);
            GameObject prefab = rebuild ? null : AssetDatabase.LoadAssetAtPath<GameObject>(TruckPath);
            if (prefab == null)
            {
                var b = new Blockout(mirrorZ: false);
                var root = new GameObject("Truck");
                b.Box(root.transform, 1.7f, 0.35f, 4.3f, 0x3a3a3a, 0, 0.55f, 0, "Chassis");
                b.Box(root.transform, 1.7f, 1.3f, 1.35f, 0xd9573b, 0, 1.38f, 1.4f, "Cab");
                b.Box(root.transform, 1.5f, 0.5f, 0.05f, 0xbfe3f0, 0, 1.65f, 2.08f, "Windshield");
                b.Box(root.transform, 1.7f, 0.12f, 2.8f, 0x8b5a2b, 0, 0.78f, -0.62f, "Bed");
                b.Box(root.transform, 0.08f, 0.4f, 2.8f, 0x6d4325, 0.82f, 1.02f, -0.62f, "SideR");
                b.Box(root.transform, 0.08f, 0.4f, 2.8f, 0x6d4325, -0.82f, 1.02f, -0.62f, "SideL");
                b.Box(root.transform, 1.7f, 0.4f, 0.08f, 0x6d4325, 0, 1.02f, -2f, "Tailgate");
                Transform[] wheels = Wheels(b, root.transform, 0.38f, 0.28f,
                    new[] { (0.86f, 1.3f), (-0.86f, 1.3f), (0.86f, -1.25f), (-0.86f, -1.25f) });
                Transform anchor = b.Group("BedAnchor", root.transform, 0, -0.62f, 0.84f);
                root.AddComponent<Truck>().Setup(anchor, wheels);
                prefab = PrefabUtility.SaveAsPrefabAsset(root, TruckPath);
                Object.DestroyImmediate(root);
            }
            return prefab.GetComponent<Truck>();
        }

        /// <returns>One prefab per colour, in prototype order.</returns>
        public static List<Car> BuildCars(bool rebuild)
        {
            DataImporter.EnsureFolder(Folder);
            var list = new List<Car>();
            for (int i = 0; i < CarColors.Length; i++)
            {
                string path = $"{Folder}/Car_{i}.prefab";
                GameObject prefab = rebuild ? null : AssetDatabase.LoadAssetAtPath<GameObject>(path);
                if (prefab == null)
                {
                    GameObject go = BuildCar($"Car_{i}", CarColors[i]);
                    prefab = PrefabUtility.SaveAsPrefabAsset(go, path);
                    Object.DestroyImmediate(go);
                }
                list.Add(prefab.GetComponent<Car>());
            }
            return list;
        }

        static GameObject BuildCar(string name, int color)
        {
            var b = new Blockout(mirrorZ: false);
            var root = new GameObject(name);
            Transform t = root.transform;
            b.Box(t, 1.7f, 0.55f, 3.4f, color, 0, 0.6f, 0, "Body");
            b.Box(t, 1.5f, 0.5f, 1.8f, 0x9fc3d6, 0, 1.12f, -0.15f, "Glass");
            b.Box(t, 1.56f, 0.08f, 1.7f, color, 0, 1.4f, -0.15f, "Roof");
            b.Box(t, 1.72f, 0.16f, 0.12f, 0x3a4048, 0, 0.45f, 1.72f, "BumperFront");
            b.Box(t, 1.72f, 0.16f, 0.12f, 0x3a4048, 0, 0.45f, -1.72f, "BumperBack");
            foreach (float x in new[] { -0.6f, 0.6f })
            {
                b.GlowBox(t, 0.32f, 0.14f, 0.04f, 0xfff3c4, x, 0.72f, 1.71f, "Headlight");
                b.GlowBox(t, 0.3f, 0.12f, 0.04f, 0xd9573b, x, 0.72f, -1.71f, "Taillight");
            }
            Transform[] wheels = Wheels(b, t, 0.32f, 0.24f, new[] { (0.86f, 1.1f), (-0.86f, 1.1f), (0.86f, -1.1f), (-0.86f, -1.1f) });
            root.AddComponent<Car>().Setup(wheels);
            return root;
        }

        /// <summary>Prototype wheels: CylinderGeometry(r, r, w, 12) turned onto its side; the pivot rolls about X.</summary>
        static Transform[] Wheels(Blockout b, Transform parent, float radius, float width, (float x, float z)[] at)
        {
            var pivots = new Transform[at.Length];
            for (int i = 0; i < at.Length; i++)
            {
                Transform pivot = b.Group("Wheel" + i, parent, at[i].x, at[i].z, radius);
                GameObject tyre = b.Cyl(pivot, radius, radius, width, 0x222222, 12, 0, 0, 0, "Tyre");
                b.RotateZ(tyre, Mathf.PI / 2f);
                pivots[i] = pivot;
            }
            return pivots;
        }
    }
}
