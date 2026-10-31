using FF.Core;
using FF.Data;
using FF.Editor.Art;
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
    /// Ground decals shared by the production and shop builders: zones (prototype <c>addZone</c> marker + pile anchor),
    /// textured quads and flat localized TMP texts, and the transparent URP materials they use.
    /// </summary>
    public sealed class ZoneFactory
    {
        // marker canvas: 256 px over the marker side; glyph at y 106, label at y 200 with max width 204
        const float GlyphOffset = (128f - 106f) / 256f, LabelOffset = (128f - 200f) / 256f, LabelWidth = 204f / 256f;

        readonly float _markerSize;
        readonly TMP_FontAsset _font;
        readonly JObject _preview;

        public ZoneFactory(GameDatabase db)
        {
            _markerSize = db.world.production.zoneMarkerSize;
            _font = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(FontSetup.ArmenianAssetPath("Black"));
            _preview = DataImporter.ReadObject("localization_hy.json");
        }

        /// <param name="glyph">Text glyph drawn on the marker (e.g. $); null when the marker texture has its own.</param>
        public Zone Zone(string id, Transform parent, ZoneKind kind, ItemType type, Vector2 protoPos, Vector3 protoPileOffset,
            string labelKey, string glyph, Material markerMaterial)
        {
            float size = _markerSize;
            var go = new GameObject("Zone_" + id);
            go.transform.SetParent(parent, false);
            go.transform.position = ProtoCoords.ToUnity(protoPos);

            var anchor = new GameObject("Pile").transform;
            anchor.SetParent(go.transform, false);
            anchor.localPosition = ProtoCoords.ToUnity(protoPileOffset.x, protoPileOffset.y, protoPileOffset.z);

            var marker = new GameObject("Marker");
            marker.transform.SetParent(go.transform, false);
            Quad(marker.transform, "Quad", markerMaterial, 0.03f, size);
            if (glyph != null)
                FlatText(marker.transform, "Glyph", glyph, null, Color.white, new Vector2(size * 0.8f, size * 0.42f), size * GlyphOffset, size * 4f);
            FlatText(marker.transform, "Label", (string)_preview[labelKey] ?? labelKey, labelKey, Color.white,
                new Vector2(size * LabelWidth, size * 0.17f), size * LabelOffset, size * 3f);

            var zone = go.AddComponent<Zone>();
            zone.Setup(id, kind, type, anchor, marker);
            return zone;
        }

        /// <summary>Text lying flat on the ground, readable from the camera; localized when <paramref name="key"/> is set.</summary>
        public TMP_Text FlatText(Transform parent, string name, string text, string key, Color color, Vector2 rectSize, float z, float maxFontSize)
        {
            var go = new GameObject(name, typeof(RectTransform));
            go.transform.SetParent(parent, false);
            go.transform.localPosition = new Vector3(0, 0.04f, z);
            go.transform.localRotation = Quaternion.Euler(90, 0, 0);
            ((RectTransform)go.transform).sizeDelta = rectSize;
            var tmp = go.AddComponent<TextMeshPro>();
            if (_font != null) tmp.font = _font;
            tmp.text = text;
            tmp.color = color;
            tmp.alignment = TextAlignmentOptions.Center;
            tmp.textWrappingMode = TextWrappingModes.NoWrap;
            tmp.enableAutoSizing = true;
            tmp.fontSizeMin = 0.1f;
            tmp.fontSizeMax = maxFontSize;
            var mr = tmp.GetComponent<MeshRenderer>();
            mr.shadowCastingMode = ShadowCastingMode.Off;
            mr.receiveShadows = false;
            if (key != null) go.AddComponent<LocalizedTmpText>().SetKey(key);
            return tmp;
        }

        /// <summary>Horizontal textured square (no shadows) at height y.</summary>
        public static Transform Quad(Transform parent, string name, Material material, float y, float size)
        {
            var quad = new GameObject(name);
            quad.transform.SetParent(parent, false);
            quad.transform.localPosition = new Vector3(0, y, 0);
            quad.transform.localScale = new Vector3(size, 1, size);
            quad.AddComponent<MeshFilter>().sharedMesh = LowPolyMeshFactory.TexturedQuad();
            var r = quad.AddComponent<MeshRenderer>();
            r.sharedMaterial = material;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            return quad.transform;
        }

        /// <summary>URP Unlit transparent; <paramref name="queueBelowTransparent"/> orders stacked decals under the texts.</summary>
        public static Material TransparentMaterial(string name, Texture2D texture, int queueBelowTransparent)
        {
            string path = $"{MaterialPaletteEditor.Folder}/{name}.mat";
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (m != null) return m;
            m = new Material(Shader.Find("Universal Render Pipeline/Unlit")) { enableInstancing = true };
            m.SetTexture("_BaseMap", texture);
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
            m.renderQueue = (int)RenderQueue.Transparent - queueBelowTransparent;
            AssetDatabase.CreateAsset(m, path);
            return m;
        }
    }
}
