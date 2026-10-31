using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.Gameplay.Production;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using FF.UI.Localization;
using Newtonsoft.Json.Linq;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor.World
{
    /// <summary>
    /// Builds World/Production: one Machine per sawmill / product factory with its input and output zones,
    /// ground markers and pile anchors (prototype ~905–933). Runs after <see cref="LayoutBuilder"/>, whose
    /// buildings provide the saw blades and presses. Returns the zones in prototype order.
    /// </summary>
    public static class ProductionBuilder
    {
        public const string RootName = "Production";
        // prototype T_DROP / T_PICK
        static readonly Color DropTint = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.30f);
        static readonly Color PickupTint = new Color(61 / 255f, 138 / 255f, 49 / 255f, 0.42f);

        // marker canvas (256 px over the marker side): label at y 200, max width 204 (the arrow glyph is in the texture)
        const float LabelOffset = (128f - 200f) / 256f, LabelWidth = 204f / 256f;

        public static List<Zone> Build(GameDatabase db)
        {
            WorldLayout w = db.world;
            GameObject worldRoot = GameObject.Find("World") ?? new GameObject("World");
            Transform old = worldRoot.transform.Find(RootName);
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var root = new GameObject(RootName).transform;
            root.SetParent(worldRoot.transform, false);

            var ctx = new Context(db, root);
            Transform blockout = worldRoot.transform.Find(LayoutBuilder.RootName);

            ctx.Machine(WorldStateSnapshot.Sawmill1Id, null, w.sawmill1.sawIn, w.sawmill1.sawOut, w.sawmill1.machineMouth,
                ItemType.Log, ItemType.Plank, "in.log", "in.plank", Part(blockout, "Sawmill1/SawBlade"), null);
            ctx.Machine(WorldStateSnapshot.Sawmill2Id, null, w.sawmill2.saw2In, w.sawmill2.saw2Out, w.sawmill2.machineMouth,
                ItemType.Log, ItemType.Plank, "in.log", "in.plank", Part(blockout, "Sawmill2/SawBlade"), null);

            WorldLayout.FactoryRowSettings f = w.factories;
            foreach (ProductDef p in db.products)
            {
                var mouth = new Vector3(p.factoryX, w.production.factoryMouthY, w.production.factoryMouthZ);
                ctx.Machine(p.id, p, new Vector2(p.factoryX + f.inZoneDx, f.zoneZ), new Vector2(p.factoryX + f.outZoneDx, f.zoneZ), mouth,
                    p.input, p.item, "in." + p.input.ToString().ToLowerInvariant(), p.signKey, null,
                    Part(blockout, $"FactoryRow/{p.id}/Building/Press"));
            }

            Debug.Log($"[FF] Production built: {ctx.Zones.Count / 2} machines, {ctx.Zones.Count} zones.");
            return ctx.Zones;
        }

        static Transform Part(Transform blockout, string path)
        {
            Transform t = blockout != null ? blockout.Find(path) : null;
            if (t == null) Debug.LogWarning($"[FF] Building part '{path}' not found; build the world blockout first.");
            return t;
        }

        /// <summary>Shared assets and the zone list while building.</summary>
        sealed class Context
        {
            public readonly List<Zone> Zones = new List<Zone>();
            readonly GameDatabase _db;
            readonly Transform _root;
            readonly Material _dropMaterial, _pickupMaterial;
            readonly TMP_FontAsset _font;
            readonly JObject _preview;

            public Context(GameDatabase db, Transform root)
            {
                _db = db;
                _root = root;
                _dropMaterial = MarkerMaterial("Drop", DropTint, -1);
                _pickupMaterial = MarkerMaterial("Pickup", PickupTint, 1);
                _font = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(FontSetup.ArmenianAssetPath("Black"));
                _preview = DataImporter.ReadObject("localization_hy.json");
            }

            public void Machine(string id, ProductDef product, Vector2 inPos, Vector2 outPos, Vector3 protoMouth,
                ItemType inType, ItemType outType, string inLabel, string outLabel, Transform blade, Transform press)
            {
                WorldLayout.ProductionSettings s = _db.world.production;
                var go = new GameObject("Machine_" + id);
                go.transform.SetParent(_root, false);
                var mouth = new GameObject("Mouth").transform;
                mouth.SetParent(go.transform, false);
                mouth.position = ProtoCoords.ToUnity(protoMouth.x, protoMouth.y, protoMouth.z);

                bool saw = product == null;
                WorldLayout.PileSettings inPile = saw ? s.sawIn : inType == ItemType.Plank ? s.plankIn : s.mineIn;
                WorldLayout.PileSettings outPile = saw ? s.sawOut : s.productOut;
                Zone input = ZoneObject(id + "_in", go.transform, ZoneKind.Drop, inType, inPos, inPile, inLabel, _dropMaterial);
                Zone output = ZoneObject(id + "_out", go.transform, ZoneKind.Pickup, outType, outPos, outPile, outLabel, _pickupMaterial);

                MachineVisual visual = null;
                if (blade != null || press != null)
                {
                    visual = go.AddComponent<MachineVisual>();
                    visual.Setup(blade, press);
                }
                go.AddComponent<Machine>().Setup(id, product, input, output, mouth, visual);
            }

            Zone ZoneObject(string id, Transform parent, ZoneKind kind, ItemType type, Vector2 protoPos,
                WorldLayout.PileSettings pile, string labelKey, Material markerMaterial)
            {
                float size = _db.world.production.zoneMarkerSize;
                var go = new GameObject("Zone_" + id);
                go.transform.SetParent(parent, false);
                go.transform.position = ProtoCoords.ToUnity(protoPos);

                var anchor = new GameObject("Pile").transform;
                anchor.SetParent(go.transform, false);
                anchor.localPosition = ProtoCoords.ToUnity(pile.offset.x, pile.offset.y, pile.offset.z);

                var marker = new GameObject("Marker");
                marker.transform.SetParent(go.transform, false);
                var quad = new GameObject("Quad");
                quad.transform.SetParent(marker.transform, false);
                quad.transform.localPosition = new Vector3(0, 0.03f, 0);
                quad.transform.localScale = new Vector3(size, 1, size);
                quad.AddComponent<MeshFilter>().sharedMesh = LowPolyMeshFactory.TexturedQuad();
                var r = quad.AddComponent<MeshRenderer>();
                r.sharedMaterial = markerMaterial;
                r.shadowCastingMode = ShadowCastingMode.Off;
                r.receiveShadows = false;

                FlatText(marker.transform, "Label", (string)_preview[labelKey] ?? labelKey, labelKey,
                    new Vector2(size * LabelWidth, size * 0.17f), size * LabelOffset, size * 3f);

                var zone = go.AddComponent<Zone>();
                zone.Setup(id, kind, type, anchor, marker);
                Zones.Add(zone);
                return zone;
            }

            void FlatText(Transform parent, string name, string text, string key, Vector2 rectSize, float z, float maxFontSize)
            {
                var go = new GameObject(name, typeof(RectTransform));
                go.transform.SetParent(parent, false);
                go.transform.localPosition = new Vector3(0, 0.035f, z);
                go.transform.localRotation = Quaternion.Euler(90, 0, 0); // lying flat, readable from the camera side
                ((RectTransform)go.transform).sizeDelta = rectSize;
                var tmp = go.AddComponent<TextMeshPro>();
                if (_font != null) tmp.font = _font;
                tmp.text = text;
                tmp.color = Color.white;
                tmp.alignment = TextAlignmentOptions.Center;
                tmp.textWrappingMode = TextWrappingModes.NoWrap;
                tmp.enableAutoSizing = true;
                tmp.fontSizeMin = 0.1f;
                tmp.fontSizeMax = maxFontSize;
                var mr = tmp.GetComponent<MeshRenderer>();
                mr.shadowCastingMode = ShadowCastingMode.Off;
                mr.receiveShadows = false;
                go.AddComponent<LocalizedTmpText>().SetKey(key);
            }

        }

        /// <summary>URP Unlit, transparent, drawn before TMP texts on top of it.</summary>
        static Material MarkerMaterial(string name, Color tint, int arrow)
        {
            string path = $"{MaterialPaletteEditor.Folder}/ZoneMarker_{name}.mat";
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (m != null) return m;
            m = new Material(Shader.Find("Universal Render Pipeline/Unlit")) { enableInstancing = true };
            m.SetTexture("_BaseMap", TextureFactory.ZoneMarker(name, tint, arrow));
            m.SetColor("_BaseColor", Color.white);
            m.SetFloat("_Surface", 1);
            m.SetFloat("_Blend", 0);
            m.SetFloat("_SrcBlend", (float)BlendMode.SrcAlpha);
            m.SetFloat("_DstBlend", (float)BlendMode.OneMinusSrcAlpha);
            m.SetFloat("_SrcBlendAlpha", (float)BlendMode.One);
            m.SetFloat("_DstBlendAlpha", (float)BlendMode.OneMinusSrcAlpha);
            m.SetFloat("_ZWrite", 0);
            m.SetOverrideTag("RenderType", "Transparent");
            m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
            m.renderQueue = (int)RenderQueue.Transparent - 10;
            AssetDatabase.CreateAsset(m, path);
            return m;
        }
    }
}
