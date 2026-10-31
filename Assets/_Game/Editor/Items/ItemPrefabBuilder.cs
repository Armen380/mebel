using System.Collections.Generic;
using FF.Data;
using FF.Editor.World;
using FF.Gameplay.Items;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Items
{
    /// <summary>
    /// Builds one prefab per item type from the prototype's <c>PROTO</c> primitives and fills the ItemCatalog
    /// (stack heights = prototype <c>H</c>, pool prewarm counts). Items are built in world convention: their
    /// front faces the camera (Unity −Z) when lying in a pile.
    /// </summary>
    public static class ItemPrefabBuilder
    {
        public const string Folder = "Assets/_Game/Prefabs/Items";
        public const string CatalogPath = DataImporter.DataRoot + "/ItemCatalog.asset";

        // prototype H and how many of each the pool creates up front (M2 loop: logs, planks, chairs)
        static readonly (ItemType type, float height, int prewarm)[] Table =
        {
            (ItemType.Log, 0.3f, 40), (ItemType.Plank, 0.11f, 70), (ItemType.Clay, 0.28f, 4), (ItemType.Iron, 0.24f, 4),
            (ItemType.Material, 0.3f, 4), (ItemType.Bill, 0.055f, 4), (ItemType.Chair, 0.5f, 24), (ItemType.Sofa, 0.44f, 4),
            (ItemType.Wardrobe, 0.84f, 4), (ItemType.Table, 0.5f, 4), (ItemType.Kitchen, 0.58f, 4), (ItemType.Sink, 0.56f, 4),
        };

        [MenuItem("FF/Build Item Prefabs", priority = 22)]
        static void BuildMenu() => Build(true);

        /// <param name="rebuild">False keeps existing prefabs (stable file ids, no git churn) and only adds missing ones.</param>
        public static ItemCatalog Build(bool rebuild)
        {
            DataImporter.EnsureFolder(Folder);
            var catalog = DataImporter.GetOrCreate<ItemCatalog>(CatalogPath);
            var b = new Blockout(mirrorZ: true);
            var entries = new List<ItemCatalog.Entry>();
            foreach ((ItemType type, float height, int prewarm) in Table)
            {
                ItemCatalog.Entry old = catalog.entries.Find(e => e != null && e.type == type);
                string path = $"{Folder}/{type}.prefab";
                GameObject prefab = rebuild ? null : AssetDatabase.LoadAssetAtPath<GameObject>(path);
                if (prefab == null)
                {
                    var root = new GameObject(type.ToString());
                    root.AddComponent<Item>().SetType(type);
                    BuildShape(b, root.transform, type);
                    prefab = PrefabUtility.SaveAsPrefabAsset(root, path);
                    Object.DestroyImmediate(root);
                }
                entries.Add(new ItemCatalog.Entry
                {
                    type = type,
                    stackHeight = height,
                    prefab = prefab,
                    prewarm = old != null ? old.prewarm : prewarm, // keep values tuned in the Inspector
                });
            }
            catalog.entries = entries;
            catalog.ClearCache();
            EditorUtility.SetDirty(catalog);

            var db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            db.items = catalog;
            EditorUtility.SetDirty(db);
            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] Item catalog ready ({entries.Count} types{(rebuild ? ", prefabs rebuilt" : "")}).");
            return catalog;
        }

        static void BuildShape(Blockout b, Transform g, ItemType type)
        {
            switch (type)
            {
                case ItemType.Log:
                    b.RotateZ(b.Cyl(g, 0.16f, 0.16f, 0.9f, 0x8b5a2b, 8, 0, 0, 0, "Bark"), Mathf.PI / 2);
                    b.RotateZ(b.Cyl(g, 0.11f, 0.11f, 0.92f, 0xe0b072, 8, 0, 0, 0, "Core"), Mathf.PI / 2);
                    break;
                case ItemType.Plank:
                    b.Box(g, 0.95f, 0.1f, 0.3f, 0xe2b878, 0, 0.05f, 0);
                    b.Box(g, 0.95f, 0.012f, 0.02f, 0xc9975a, 0, 0.101f, 0, "Grain");
                    break;
                case ItemType.Clay:
                    b.Box(g, 0.42f, 0.26f, 0.34f, 0xb5653d, 0, 0.13f, 0);
                    b.Box(g, 0.3f, 0.04f, 0.24f, 0xd4875c, 0, 0.27f, 0);
                    break;
                case ItemType.Bill:
                    b.Box(g, 0.46f, 0.05f, 0.26f, 0x58a84a, 0, 0.025f, 0);
                    b.Box(g, 0.14f, 0.052f, 0.27f, 0xa6dc8f, 0, 0.026f, 0);
                    break;
                case ItemType.Chair:
                    const int seat = 0xbd6f36, leg = 0x8f4f22;
                    b.Box(g, 0.5f, 0.08f, 0.5f, seat, 0, 0.34f, 0, "Seat");
                    foreach ((float sx, float sz) in new[] { (-0.2f, -0.2f), (0.2f, -0.2f), (-0.2f, 0.2f), (0.2f, 0.2f) })
                        b.Box(g, 0.07f, 0.34f, 0.07f, leg, sx, 0.17f, sz, "Leg");
                    b.Box(g, 0.5f, 0.44f, 0.07f, seat, 0, 0.6f, -0.215f, "Back");
                    b.Box(g, 0.36f, 0.06f, 0.075f, 0xe2a066, 0, 0.68f, -0.215f, "BackRail");
                    break;
                case ItemType.Sofa:
                    b.Box(g, 0.9f, 0.2f, 0.46f, 0x6c4f9a, 0, 0.16f, 0);
                    b.Box(g, 0.78f, 0.1f, 0.38f, 0x9a7fd0, 0, 0.31f, 0.03f);
                    b.Box(g, 0.9f, 0.3f, 0.12f, 0x6c4f9a, 0, 0.4f, -0.17f);
                    b.Box(g, 0.1f, 0.28f, 0.46f, 0x5a4084, -0.45f, 0.3f, 0);
                    b.Box(g, 0.1f, 0.28f, 0.46f, 0x5a4084, 0.45f, 0.3f, 0);
                    b.Box(g, 0.06f, 0.06f, 0.06f, 0x2b1d14, -0.38f, 0.03f, 0.17f);
                    b.Box(g, 0.06f, 0.06f, 0.06f, 0x2b1d14, 0.38f, 0.03f, 0.17f);
                    break;
                case ItemType.Wardrobe:
                    b.Box(g, 0.62f, 0.82f, 0.36f, 0x9c6b3e, 0, 0.41f, 0);
                    b.Box(g, 0.66f, 0.05f, 0.4f, 0x7a4f2a, 0, 0.845f, 0);
                    b.Box(g, 0.015f, 0.74f, 0.005f, 0x5a3a1e, 0, 0.42f, 0.181f);
                    b.Box(g, 0.03f, 0.12f, 0.03f, 0xe0c070, -0.06f, 0.45f, 0.19f);
                    b.Box(g, 0.03f, 0.12f, 0.03f, 0xe0c070, 0.06f, 0.45f, 0.19f);
                    break;
                case ItemType.Table:
                    b.Box(g, 0.82f, 0.06f, 0.56f, 0xc98a4a, 0, 0.45f, 0);
                    foreach ((float sx, float sz) in new[] { (-0.35f, -0.22f), (0.35f, -0.22f), (-0.35f, 0.22f), (0.35f, 0.22f) })
                        b.Box(g, 0.06f, 0.42f, 0.06f, 0x8a5a2e, sx, 0.21f, sz, "Leg");
                    break;
                case ItemType.Kitchen:
                    b.Box(g, 0.7f, 0.5f, 0.44f, 0xece6d8, 0, 0.25f, 0);
                    b.Box(g, 0.74f, 0.05f, 0.48f, 0x3d3d3d, 0, 0.525f, 0);
                    b.Box(g, 0.66f, 0.012f, 0.005f, 0xb9b2a3, 0, 0.36f, 0.221f);
                    b.Box(g, 0.16f, 0.025f, 0.03f, 0x8a8a8a, -0.17f, 0.43f, 0.23f);
                    b.Box(g, 0.16f, 0.025f, 0.03f, 0x8a8a8a, 0.17f, 0.43f, 0.23f);
                    b.Box(g, 0.012f, 0.3f, 0.005f, 0xb9b2a3, 0, 0.17f, 0.221f);
                    break;
                case ItemType.Sink:
                    b.Cyl(g, 0.08f, 0.12f, 0.38f, 0xf2f4f5, 10, 0, 0.19f, 0);
                    b.Box(g, 0.52f, 0.14f, 0.38f, 0xf2f4f5, 0, 0.44f, 0);
                    b.Box(g, 0.4f, 0.04f, 0.26f, 0xbfd3dc, 0, 0.5f, 0.02f);
                    b.Box(g, 0.04f, 0.12f, 0.04f, 0xa5aeb8, 0, 0.56f, -0.13f);
                    b.Box(g, 0.04f, 0.04f, 0.1f, 0xa5aeb8, 0, 0.61f, -0.09f);
                    break;
                case ItemType.Iron:
                    b.Box(g, 0.4f, 0.22f, 0.32f, 0x5b6470, 0, 0.11f, 0);
                    b.Box(g, 0.18f, 0.1f, 0.14f, 0xb5653d, 0.08f, 0.24f, 0.04f);
                    b.Box(g, 0.12f, 0.08f, 0.1f, 0x8a949c, -0.1f, 0.23f, -0.06f);
                    break;
                case ItemType.Material:
                    for (int k = 0; k < 3; k++)
                    {
                        float z = (k - 1) * 0.17f;
                        b.Box(g, 0.92f, 0.03f, 0.14f, 0x8a949c, 0, 0.02f, z);
                        b.Box(g, 0.92f, 0.18f, 0.03f, 0x8a949c, 0, 0.12f, z);
                        b.Box(g, 0.92f, 0.03f, 0.14f, 0x8a949c, 0, 0.22f, z);
                    }
                    b.Box(g, 0.06f, 0.27f, 0.56f, 0xd9573b, -0.28f, 0.12f, 0);
                    b.Box(g, 0.06f, 0.27f, 0.56f, 0xd9573b, 0.28f, 0.12f, 0);
                    break;
            }
        }
    }
}
