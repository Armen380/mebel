using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.Gameplay.Home;
using FF.Gameplay.Zones;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor.World
{
    /// <summary>
    /// Dream House slots (M10): one <see cref="HomeSlot"/> per <see cref="HomeDef.SlotDef"/> with a ghost and the models of
    /// every item it can hold. Factory slots show the product's own item model at furniture size and get a drop zone;
    /// Home Store items are built from primitives (carpets and paintings with generated textures).
    /// Model fronts face the camera (Unity −Z); the slot's yaw turns them.
    /// </summary>
    public static class HomeSlotBuilder
    {
        const string MaterialFolder = "Assets/_Game/Art/Materials/Home";
        const int Walnut = HouseBuilder.Walnut, Tuff = HouseBuilder.Tuff, TuffTrim = HouseBuilder.TuffTrim, Pom = HouseBuilder.Pomegranate;
        const int Vine = HouseBuilder.Vine, Honey = HouseBuilder.Honey, Cream = 0xf6ecd9, White = 0xf2f2f0, Steel = 0x9aa3ad;
        const int Water = 0x4fb3d9, Leaf = 0x3f8f3a, Terracotta = 0xc4643f, Brass = 0xd2a64a, Ink = 0x2b2d33;
        static readonly Color DropTint = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.30f);

        public sealed class Result
        {
            public readonly List<HomeSlot> Slots = new List<HomeSlot>();
            public readonly List<Zone> Zones = new List<Zone>();
        }

        /// <summary>Furniture size of the carried product models (item prefabs are hand-size).</summary>
        static float ProductScale(ItemType t)
        {
            switch (t)
            {
                case ItemType.Chair: return 1.15f;
                case ItemType.Sofa: return 1.7f;
                case ItemType.Wardrobe: return 2.1f;
                case ItemType.Table: return 1.5f;
                case ItemType.Kitchen: return 1.8f;
                case ItemType.Sink: return 1.45f;
                default: return 1.5f;
            }
        }

        public static Result Build(GameDatabase db, Transform slotsRoot)
        {
            var result = new Result();
            HomeDef home = db.home;
            var zones = new ZoneFactory(db);
            Material drop = ZoneFactory.TransparentMaterial("ZoneMarker_Drop", TextureFactory.ZoneMarker("Drop", DropTint, -1), 10);
            var b = new Blockout(mirrorZ: true);

            foreach (HomeDef.SlotDef s in home.slots)
            {
                var go = new GameObject("Slot_" + s.id);
                go.transform.SetParent(slotsRoot, false);
                go.transform.position = ProtoCoords.ToUnity(s.protoPos.x, s.protoPos.y);
                Transform turn = new GameObject("Turn").transform;
                turn.SetParent(go.transform, false);
                turn.localRotation = Quaternion.Euler(0, s.yaw, 0);

                var ids = new List<string>();
                var models = new List<GameObject>();
                Zone zone = null;
                GameObject ghost;
                if (s.IsFactory)
                {
                    string id = HomeRules.ProductId(s.product);
                    GameObject model = ProductModel(db, s.product, turn, "Model_" + id);
                    ids.Add(id);
                    models.Add(model);
                    ghost = ProductModel(db, s.product, turn, "Ghost");
                    ProductDef product = db.Product(id);
                    zone = zones.Zone("home_" + s.id, go.transform, ZoneKind.Drop, s.product, Vector2.zero, Vector3.zero,
                        product != null ? product.nameKey : "z.shelf", null, drop);
                    zone.transform.localPosition = Vector3.zero;
                    zone.HideCounter();
                    result.Zones.Add(zone);
                }
                else
                {
                    HomeDef.HomeItemDef first = null;
                    foreach (HomeDef.HomeItemDef item in home.items)
                    {
                        if (item.group != s.group) continue;
                        first ??= item;
                        Transform m = b.Group("Model_" + item.id, turn);
                        ItemModel(b, m, item.id);
                        ids.Add(item.id);
                        models.Add(m.gameObject);
                    }
                    Transform g = b.Group("Ghost", turn);
                    if (first != null) ItemModel(b, g, first.id);
                    ghost = g.gameObject;
                }
                MakeGhost(ghost);
                foreach (GameObject m in models) m.SetActive(false);

                var slot = go.AddComponent<HomeSlot>();
                slot.Setup(s.id, ghost, zone, ids.ToArray(), models.ToArray());
                result.Slots.Add(slot);
            }
            return result;
        }

        // ---------- factory products ----------

        static GameObject ProductModel(GameDatabase db, ItemType type, Transform parent, string name)
        {
            var root = new GameObject(name);
            root.transform.SetParent(parent, false);
            root.transform.localScale = Vector3.one * ProductScale(type);
            GameObject prefab = db.items.Prefab(type);
            if (prefab != null) CopyVisual(prefab.transform, root.transform);
            return root;
        }

        /// <summary>Copies only the transforms and mesh renderers (no Item / pool components).</summary>
        static void CopyVisual(Transform src, Transform dst)
        {
            for (int i = 0; i < src.childCount; i++)
            {
                Transform c = src.GetChild(i);
                var go = new GameObject(c.name);
                go.transform.SetParent(dst, false);
                go.transform.localPosition = c.localPosition;
                go.transform.localRotation = c.localRotation;
                go.transform.localScale = c.localScale;
                if (c.TryGetComponent(out MeshFilter mf) && c.TryGetComponent(out MeshRenderer mr))
                {
                    go.AddComponent<MeshFilter>().sharedMesh = mf.sharedMesh;
                    var r = go.AddComponent<MeshRenderer>();
                    r.sharedMaterials = mr.sharedMaterials;
                    r.shadowCastingMode = ShadowCastingMode.On;
                }
                CopyVisual(c, go.transform);
            }
            if (src.TryGetComponent(out MeshFilter rootMf) && src.TryGetComponent(out MeshRenderer rootMr) && dst.GetComponent<MeshFilter>() == null)
            {
                dst.gameObject.AddComponent<MeshFilter>().sharedMesh = rootMf.sharedMesh;
                dst.gameObject.AddComponent<MeshRenderer>().sharedMaterials = rootMr.sharedMaterials;
            }
        }

        /// <summary>Ghost twin materials, no shadows (prototype ghostOf).</summary>
        static void MakeGhost(GameObject root)
        {
            MaterialPalette palette = MaterialPaletteEditor.Palette;
            foreach (MeshRenderer r in root.GetComponentsInChildren<MeshRenderer>(true))
            {
                Material ghost = null;
                foreach (MaterialPalette.Entry e in palette.entries)
                    if (e.material == r.sharedMaterial) ghost = e.ghost;
                r.sharedMaterial = ghost != null ? ghost : MaterialPaletteEditor.GetGhost(Blockout.Hex(Cream));
                r.shadowCastingMode = ShadowCastingMode.Off;
                r.receiveShadows = false;
            }
        }

        // ---------- Home Store items ----------

        static void ItemModel(Blockout b, Transform m, string id)
        {
            switch (id)
            {
                case "carpet_vishap":
                case "carpet_garden":
                case "carpet_star":
                    Textured(m, id, TextureFactory.CarpetTexture(id), new Vector3(2.2f, 1f, 1.5f), 0.33f, false);
                    break;
                case "lamp_clay":
                    b.Cyl(m, 0.18f, 0.24f, 0.4f, Terracotta, 8, 0, 0.2f, 0, "Base");
                    b.Box(m, 0.05f, 0.9f, 0.05f, Walnut, 0, 0.85f, 0, "Pole");
                    b.Cyl(m, 0.18f, 0.32f, 0.36f, Cream, 8, 0, 1.4f, 0, "Shade");
                    b.GlowBox(m, 0.12f, 0.1f, 0.12f, 0xffe4a3, 0, 1.28f, 0, "Bulb");
                    break;
                case "lamp_brass":
                    b.Cyl(m, 0.2f, 0.22f, 0.06f, Brass, 8, 0, 0.03f, 0, "Base");
                    b.Box(m, 0.04f, 1.45f, 0.04f, Brass, 0, 0.75f, 0, "Pole");
                    b.Cyl(m, 0.14f, 0.28f, 0.3f, Brass, 8, 0, 1.55f, 0, "Shade");
                    b.GlowBox(m, 0.12f, 0.08f, 0.12f, 0xffe4a3, 0, 1.42f, 0, "Bulb");
                    break;
                case "tv":
                    b.Box(m, 1.4f, 0.5f, 0.45f, Walnut, 0, 0.25f, 0, "Stand");
                    b.Box(m, 1.2f, 0.7f, 0.06f, Ink, 0, 0.92f, -0.05f, "Screen");
                    b.Box(m, 1.1f, 0.6f, 0.02f, 0x3b6e8f, 0, 0.92f, -0.01f, "Picture");
                    break;
                case "painting_ararat":
                case "painting_garni":
                    b.Box(m, 1.2f, 0.85f, 0.06f, Walnut, 0, 1.6f, -0.12f, "Frame");
                    Transform canvas = b.Group("Canvas", m, 0, -0.08f, 1.6f);
                    canvas.localRotation = Quaternion.Euler(-90, 0, 0);
                    Textured(canvas, id, TextureFactory.PaintingTexture(id), new Vector3(1.05f, 1f, 0.7f), 0f, true);
                    break;
                case "plant":
                    b.Cyl(m, 0.26f, 0.2f, 0.45f, Terracotta, 8, 0, 0.23f, 0, "Pot");
                    b.Box(m, 0.05f, 0.7f, 0.05f, Walnut, 0, 0.75f, 0, "Stem");
                    b.Ico(m, 0.32f, Leaf, 0, 1.15f, 0, "Leaves");
                    b.Ico(m, 0.24f, Vine, 0.18f, 0.95f, 0.1f, "Leaves");
                    b.Ico(m, 0.22f, Leaf, -0.16f, 1.0f, -0.08f, "Leaves");
                    break;
                case "fridge":
                    b.Box(m, 0.75f, 1.85f, 0.65f, White, 0, 0.93f, 0, "Body");
                    b.Box(m, 0.72f, 0.03f, 0.67f, Steel, 0, 1.25f, 0, "Gap");
                    b.Box(m, 0.04f, 0.4f, 0.06f, Steel, -0.25f, 1.5f, 0.35f, "Handle");
                    b.Box(m, 0.04f, 0.35f, 0.06f, Steel, -0.25f, 0.95f, 0.35f, "Handle");
                    break;
                case "stove":
                    b.Box(m, 0.8f, 0.9f, 0.62f, White, 0, 0.45f, 0, "Body");
                    b.Box(m, 0.8f, 0.03f, 0.62f, Ink, 0, 0.915f, 0, "Top");
                    foreach ((float x, float z) in new[] { (-0.2f, -0.15f), (0.2f, -0.15f), (-0.2f, 0.15f), (0.2f, 0.15f) })
                        b.Cyl(m, 0.1f, 0.1f, 0.02f, Steel, 8, x, 0.94f, z, "Burner");
                    b.Box(m, 0.6f, 0.35f, 0.02f, Ink, 0, 0.42f, 0.31f, "Oven");
                    break;
                case "bowl":
                    b.Cyl(m, 0.38f, 0.38f, 0.05f, Walnut, 10, 0, 0.72f, 0, "TableTop");
                    b.Cyl(m, 0.05f, 0.08f, 0.7f, Walnut, 6, 0, 0.35f, 0, "Leg");
                    b.Cyl(m, 0.22f, 0.13f, 0.12f, Cream, 10, 0, 0.81f, 0, "Bowl");
                    b.Ico(m, 0.09f, Pom, -0.07f, 0.92f, 0, "Pomegranate");
                    b.Ico(m, 0.09f, Pom, 0.08f, 0.92f, 0.04f, "Pomegranate");
                    b.Ico(m, 0.08f, 0x8c1d2d, 0.01f, 0.99f, -0.05f, "Pomegranate");
                    break;
                case "bed":
                    b.Box(m, 1.7f, 0.35f, 2.1f, Walnut, 0, 0.18f, 0, "Frame");
                    b.Box(m, 1.7f, 1.0f, 0.12f, Walnut, 0, 0.5f, -1.0f, "Headboard");
                    b.Box(m, 1.55f, 0.18f, 1.95f, Cream, 0, 0.44f, 0.02f, "Mattress");
                    b.Box(m, 1.6f, 0.06f, 1.3f, Pom, 0, 0.55f, 0.35f, "Blanket");
                    b.Box(m, 1.6f, 0.07f, 0.12f, Honey, 0, 0.56f, 0.0f, "Ornament");
                    b.Box(m, 0.55f, 0.14f, 0.35f, White, -0.38f, 0.6f, -0.72f, "Pillow");
                    b.Box(m, 0.55f, 0.14f, 0.35f, White, 0.38f, 0.6f, -0.72f, "Pillow");
                    break;
                case "nightstand":
                    b.Box(m, 0.55f, 0.55f, 0.45f, Walnut, 0, 0.28f, 0, "Body");
                    b.Box(m, 0.45f, 0.02f, 0.02f, Honey, 0, 0.36f, 0.23f, "Drawer");
                    b.Box(m, 0.45f, 0.02f, 0.02f, Honey, 0, 0.2f, 0.23f, "Drawer");
                    b.Cyl(m, 0.08f, 0.12f, 0.12f, Cream, 8, 0.1f, 0.62f, 0, "Vase");
                    break;
                case "tub":
                    b.Box(m, 1.7f, 0.6f, 0.85f, White, 0, 0.3f, 0, "Tub");
                    b.Flat(m, 1.5f, 0.65f, Water, 0, 0, 0.58f, "Water");
                    b.Box(m, 0.06f, 0.3f, 0.06f, Steel, 0.7f, 0.75f, -0.3f, "Tap");
                    break;
                case "mirror":
                    b.Box(m, 0.75f, 1.05f, 0.05f, Brass, 0, 1.35f, -0.12f, "Frame");
                    b.Box(m, 0.62f, 0.92f, 0.06f, 0xd8eef5, 0, 1.35f, -0.11f, "Glass");
                    b.Mesh(m, LowPolyMeshFactory.Arch(), Brass, 0, 1.85f, -0.12f, new Vector3(0.37f, 0.3f, 0.06f), "Arch");
                    break;
                case "towel":
                    b.Box(m, 0.9f, 0.04f, 0.04f, Steel, 0, 1.1f, 0, "Rail");
                    b.Box(m, 0.04f, 1.1f, 0.04f, Steel, -0.43f, 0.55f, 0, "Post");
                    b.Box(m, 0.04f, 1.1f, 0.04f, Steel, 0.43f, 0.55f, 0, "Post");
                    b.Box(m, 0.5f, 0.6f, 0.06f, Pom, 0, 0.82f, 0.02f, "Towel");
                    b.Box(m, 0.5f, 0.06f, 0.07f, Honey, 0, 0.65f, 0.02f, "Stripe");
                    break;
                case "pergola":
                    foreach ((float x, float z) in new[] { (-1.4f, -1.1f), (1.4f, -1.1f), (-1.4f, 1.1f), (1.4f, 1.1f) })
                        b.Box(m, 0.16f, 2.5f, 0.16f, Walnut, x, 1.25f, z, "Post");
                    for (int i = -2; i <= 2; i++) b.Box(m, 0.08f, 0.1f, 2.6f, Walnut, i * 0.7f, 2.55f, 0, "Beam");
                    b.Box(m, 3.1f, 0.12f, 0.12f, Walnut, 0, 2.45f, -1.1f, "Rail");
                    b.Box(m, 3.1f, 0.12f, 0.12f, Walnut, 0, 2.45f, 1.1f, "Rail");
                    for (int i = 0; i < 9; i++)
                        b.Ico(m, 0.42f, i % 2 == 0 ? Vine : Leaf, -1.3f + (i % 5) * 0.65f, 2.7f, i < 5 ? -0.5f : 0.6f, "Vine");
                    foreach ((float x, float z) in new[] { (-0.7f, -0.6f), (0.5f, 0.7f), (1.1f, -0.2f) })
                    {
                        b.Ico(m, 0.12f, 0x6b3a7a, x, 2.35f, z, "Grapes");
                        b.Ico(m, 0.09f, 0x6b3a7a, x, 2.2f, z, "Grapes");
                    }
                    b.Box(m, 1.4f, 0.08f, 0.8f, Walnut, 0, 0.75f, 0, "TableTop");
                    b.Box(m, 0.1f, 0.75f, 0.1f, Walnut, 0, 0.38f, 0, "TableLeg");
                    break;
                case "tree":
                    b.Cyl(m, 0.14f, 0.2f, 1.4f, 0x8a5a33, 7, 0, 0.7f, 0, "Trunk");
                    b.Ico(m, 0.95f, 0x2f6e35, 0, 1.9f, 0, "Crown");
                    b.Ico(m, 0.6f, Leaf, 0.55f, 1.6f, 0.2f, "Crown");
                    foreach ((float x, float y, float z) in new[] { (0.5f, 1.9f, 0.6f), (-0.6f, 1.7f, 0.4f), (0.2f, 2.4f, 0.55f), (-0.3f, 2.1f, -0.7f), (0.8f, 1.4f, -0.2f) })
                        b.Ico(m, 0.13f, Pom, x, y, z, "Pomegranate");
                    break;
                case "flowers_rose":
                case "flowers_tulip":
                {
                    b.Box(m, 1.8f, 0.3f, 0.9f, TuffTrim, 0, 0.15f, 0, "Bed");
                    b.Flat(m, 1.6f, 0.7f, 0x5a3d2b, 0, 0, 0.31f, "Soil");
                    int bloom = id == "flowers_rose" ? Pom : 0xf28c28;
                    int alt = id == "flowers_rose" ? 0xe85d75 : 0xf2c14e;
                    for (int i = 0; i < 8; i++)
                    {
                        float x = -0.65f + (i % 4) * 0.43f, z = i < 4 ? -0.18f : 0.18f;
                        b.Ico(m, 0.12f, Leaf, x, 0.42f, z, "Leaves");
                        b.Ico(m, 0.1f, i % 3 == 0 ? alt : bloom, x, 0.56f, z, "Bloom");
                    }
                    break;
                }
                case "bench":
                    b.Box(m, 1.6f, 0.08f, 0.45f, Walnut, 0, 0.45f, 0, "Seat");
                    b.Box(m, 1.6f, 0.4f, 0.06f, Walnut, 0, 0.75f, -0.2f, "Back");
                    b.Box(m, 0.08f, 0.45f, 0.4f, Ink, -0.7f, 0.22f, 0, "Leg");
                    b.Box(m, 0.08f, 0.45f, 0.4f, Ink, 0.7f, 0.22f, 0, "Leg");
                    break;
                case "fountain":
                    b.Cyl(m, 1.25f, 1.3f, 0.45f, Tuff, 12, 0, 0.23f, 0, "Basin");
                    b.Cyl(m, 1.05f, 1.05f, 0.02f, Water, 12, 0, 0.42f, 0, "Water");
                    b.Cyl(m, 0.18f, 0.24f, 1.1f, TuffTrim, 8, 0, 0.9f, 0, "Pillar");
                    b.Cyl(m, 0.55f, 0.3f, 0.2f, Tuff, 10, 0, 1.5f, 0, "Bowl");
                    b.Cyl(m, 0.45f, 0.45f, 0.02f, Water, 10, 0, 1.6f, 0, "TopWater");
                    b.Ico(m, 0.12f, 0xbfe3f0, 0, 1.75f, 0, "Spout");
                    break;
                case "pool":
                    b.Box(m, 4.2f, 0.25f, 3.0f, Tuff, 0, 0.12f, 0, "Rim");
                    b.Box(m, 3.7f, 0.02f, 2.5f, Water, 0, 0.255f, 0, "Water");
                    b.Box(m, 0.05f, 0.7f, 0.05f, Steel, 1.5f, 0.55f, 1.2f, "Ladder");
                    b.Box(m, 0.05f, 0.7f, 0.05f, Steel, 1.8f, 0.55f, 1.2f, "Ladder");
                    b.Box(m, 0.9f, 0.08f, 0.5f, White, -2.6f, 0.3f, 0.6f, "Lounger");
                    b.Box(m, 0.9f, 0.06f, 0.5f, Pom, -2.6f, 0.36f, 0.6f, "Towel");
                    break;
                case "lampposts":
                    foreach (float x in new[] { -1.6f, 1.6f })
                    {
                        b.Box(m, 0.1f, 2.6f, 0.1f, Ink, x, 1.3f, 0, "Post");
                        b.Box(m, 0.36f, 0.4f, 0.36f, Ink, x, 2.75f, 0, "Head");
                        b.GlowBox(m, 0.26f, 0.3f, 0.26f, 0xffe4a3, x, 2.75f, 0, "Light");
                    }
                    break;
                default:
                    Debug.LogWarning($"[FF] No model for home item '{id}'.");
                    b.Box(m, 0.5f, 0.5f, 0.5f, Cream, 0, 0.25f, 0, "Missing");
                    break;
            }
        }

        /// <summary>A textured quad lying flat (carpet) or turned upright by its parent (painting).</summary>
        static void Textured(Transform parent, string id, Texture2D texture, Vector3 size, float y, bool upright)
        {
            var go = new GameObject("Textured");
            go.transform.SetParent(parent, false);
            go.transform.localPosition = new Vector3(0, y + 0.012f, 0);
            go.transform.localScale = size;
            go.AddComponent<MeshFilter>().sharedMesh = LowPolyMeshFactory.TexturedQuad();
            var r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = TexturedMaterial(id, texture);
            r.shadowCastingMode = ShadowCastingMode.Off;
        }

        static Material TexturedMaterial(string id, Texture2D texture)
        {
            DataImporter.EnsureFolder(MaterialFolder);
            string path = $"{MaterialFolder}/Home_{id}.mat";
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (m != null) return m;
            m = new Material(Shader.Find("Universal Render Pipeline/Simple Lit")) { enableInstancing = true };
            m.SetTexture("_BaseMap", texture);
            m.SetColor("_BaseColor", Color.white);
            m.SetFloat("_Smoothness", 0.05f);
            AssetDatabase.CreateAsset(m, path);
            return m;
        }
    }
}
