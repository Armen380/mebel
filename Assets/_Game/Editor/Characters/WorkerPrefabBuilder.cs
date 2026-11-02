using System.Collections.Generic;
using FF.AI;
using FF.Data;
using FF.Editor.World;
using FF.Gameplay.Characters;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Characters
{
    /// <summary>
    /// One prefab per worker kind: the blocky character in the prototype's <c>WORKER_SKIN</c> colours, and the robot of
    /// <c>makeRobot()</c> (wheel base, glowing ring, chest screen, visor head, antenna).
    /// </summary>
    public static class WorkerPrefabBuilder
    {
        public const string Folder = "Assets/_Game/Prefabs/Characters/Workers";

        // prototype WORKER_SKIN: shirt, pants, hat, hat type
        static readonly Dictionary<WorkerKind, (int shirt, int pants, int hat, HatType type)> Skins =
            new Dictionary<WorkerKind, (int, int, int, HatType)>
            {
                { WorkerKind.Lumber, (0xe07a1f, 0x3b4a3a, 0xf0a020, HatType.Hard) },
                { WorkerKind.Carrier, (0x2b8c8c, 0x34404f, 0x1f6b6b, HatType.Cap) },
                { WorkerKind.Cashier, (0xfbf1de, 0x2b1d14, 0xd9573b, HatType.Cap) },
                { WorkerKind.Stocker, (0x5cae4a, 0x2a3a2a, 0x3d8a31, HatType.Cap) },
                { WorkerKind.Manager, (0x34495e, 0x1f2a36, 0x1f2a36, HatType.None) },
                { WorkerKind.Consultant, (0x8d5fd3, 0x2b1d14, 0x8d5fd3, HatType.None) },
            };

        [MenuItem("FF/Build Worker Prefabs", priority = 24)]
        static void BuildMenu() => Build(true);

        /// <param name="rebuild">False keeps existing prefabs (stable file ids) and only adds missing ones.</param>
        /// <returns>Prefabs in <see cref="WorkerKind"/> order.</returns>
        public static List<Worker> Build(bool rebuild)
        {
            DataImporter.EnsureFolder(Folder);
            var list = new List<Worker>();
            foreach (WorkerKind kind in WorkerKinds.All)
            {
                string path = $"{Folder}/Worker_{kind}.prefab";
                GameObject prefab = rebuild ? null : AssetDatabase.LoadAssetAtPath<GameObject>(path);
                if (prefab == null)
                {
                    GameObject go = kind == WorkerKind.Robot ? BuildRobot($"Worker_{kind}") : BuildHuman(kind);
                    go.AddComponent<Worker>().SetKind(kind);
                    prefab = PrefabUtility.SaveAsPrefabAsset(go, path);
                    Object.DestroyImmediate(go);
                }
                list.Add(prefab.GetComponent<Worker>());
            }
            return list;
        }

        static GameObject BuildHuman(WorkerKind kind)
        {
            (int shirt, int pants, int hat, HatType type) = Skins[kind];
            var skin = ScriptableObject.CreateInstance<SkinDef>();
            skin.id = kind.ToString();
            skin.shirt = Blockout.Hex(shirt);
            skin.pants = Blockout.Hex(pants);
            skin.hat = Blockout.Hex(hat);
            skin.hatType = type;
            GameObject go = CharacterRigBuilder.Build($"Worker_{kind}", skin);
            Object.DestroyImmediate(skin);
            return go;
        }

        /// <summary>Prototype <c>makeRobot()</c>; the torus ring is a thin glowing disc.</summary>
        static GameObject BuildRobot(string name)
        {
            const int white = 0xdfe6ea, dark = 0x55606a, cyan = 0x4fd1e8;
            var b = new Blockout(mirrorZ: false);
            var root = new GameObject(name);
            Transform body = b.Group("Body", root.transform);
            b.Cyl(body, 0.3f, 0.4f, 0.28f, dark, 10, 0, 0.2f, 0, "Base");
            GameObject ring = b.Cyl(body, 0.4f, 0.4f, 0.04f, cyan, 16, 0, 0.08f, 0, "Ring");
            ring.GetComponent<MeshRenderer>().sharedMaterial = Art.MaterialPaletteEditor.Get(Blockout.Hex(cyan), true);
            b.Box(body, 0.62f, 0.62f, 0.46f, white, 0, 0.72f, 0, "Torso");
            b.GlowBox(body, 0.32f, 0.2f, 0.02f, cyan, 0, 0.8f, 0.24f, "Screen");
            b.Box(body, 0.08f, 0.08f, 0.02f, 0xf3b33d, 0.2f, 0.62f, 0.24f, "Button");
            b.Cyl(body, 0.08f, 0.1f, 0.12f, dark, 8, 0, 1.08f, 0, "Neck");
            b.Box(body, 0.48f, 0.36f, 0.4f, white, 0, 1.3f, 0, "Head");
            b.GlowBox(body, 0.38f, 0.12f, 0.02f, cyan, 0, 1.32f, 0.21f, "Visor");
            b.Cyl(body, 0.02f, 0.02f, 0.24f, dark, 6, 0, 1.6f, 0, "Antenna");
            b.Ico(body, 0.07f, 0xd9573b, 0, 1.75f, 0, "AntennaTip");

            Transform hipL = b.Group("HipL", body);
            Transform hipR = b.Group("HipR", body);
            Transform shL = b.Group("ShoulderL", body, -0.4f, 0, 0.95f);
            Transform shR = b.Group("ShoulderR", body, 0.4f, 0, 0.95f);
            foreach (Transform sh in new[] { shL, shR })
            {
                b.Box(sh, 0.14f, 0.42f, 0.14f, dark, 0, -0.2f, 0, "Arm");
                b.Box(sh, 0.18f, 0.1f, 0.18f, white, 0, -0.44f, 0, "Hand");
            }
            Transform axe = b.Group("Axe", shR);
            axe.gameObject.SetActive(false);
            Transform anchor = b.Group("CarryAnchor", root.transform, 0, 0.56f, 0.92f);

            var rig = root.AddComponent<CharacterRig>();
            rig.body = body;
            rig.hipLeft = hipL;
            rig.hipRight = hipR;
            rig.shoulderLeft = shL;
            rig.shoulderRight = shR;
            rig.axe = axe.gameObject;
            rig.carryAnchor = anchor;
            rig.isRobot = true;
            root.AddComponent<CharacterAnimator>();
            return root;
        }
    }
}
