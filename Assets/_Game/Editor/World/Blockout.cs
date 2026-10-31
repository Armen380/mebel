using FF.Editor.Art;
using FF.UI.Localization;
using Newtonsoft.Json.Linq;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor.World
{
    /// <summary>
    /// The prototype's primitive helpers (<c>box, cyl, flat, signMesh</c>) for Editor scene building.
    /// All arguments are in prototype units and prototype-local axes; with <see cref="mirrorZ"/> (world objects)
    /// z is converted to Unity (−z) and X/Y rotations flip sign; without it (character rigs) local axes are kept.
    /// </summary>
    public sealed class Blockout
    {
        readonly bool mirrorZ;
        readonly JObject _previewStrings;
        readonly TMP_FontAsset _signFont;

        public Blockout(bool mirrorZ)
        {
            this.mirrorZ = mirrorZ;
            _previewStrings = DataImporter.ReadObject("localization_hy.json");
            _signFont = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(FontSetup.ArmenianAssetPath("Black"));
        }

        public static Color32 Hex(int rgb) => new Color32((byte)(rgb >> 16), (byte)(rgb >> 8), (byte)rgb, 255);

        public Vector3 Pos(float x, float y, float z) => new Vector3(x, y, mirrorZ ? -z : z);

        public Transform Group(string name, Transform parent, float x = 0, float z = 0, float y = 0)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            go.transform.localPosition = Pos(x, y, z);
            return go.transform;
        }

        public GameObject Box(Transform parent, float w, float h, float d, int color, float x, float y, float z, string name = "Box") =>
            Make(name, parent, LowPolyMeshFactory.Cube, MaterialPaletteEditor.Get(Hex(color)), Pos(x, y, z), new Vector3(w, h, d), true);

        public GameObject Cyl(Transform parent, float radiusTop, float radiusBottom, float h, int color, int segments, float x, float y, float z, string name = "Cylinder") =>
            Make(name, parent, LowPolyMeshFactory.Cylinder(radiusTop, radiusBottom, segments), MaterialPaletteEditor.Get(Hex(color)), Pos(x, y, z), new Vector3(1, h, 1), true);

        public GameObject Ico(Transform parent, float radius, int color, float x, float y, float z, string name = "Icosahedron") =>
            Make(name, parent, LowPolyMeshFactory.Icosahedron(), MaterialPaletteEditor.Get(Hex(color)), Pos(x, y, z), Vector3.one * radius, true);

        public GameObject Hemisphere(Transform parent, float radius, int color, float x, float y, float z, string name = "Hemisphere") =>
            Make(name, parent, LowPolyMeshFactory.Hemisphere(), MaterialPaletteEditor.Get(Hex(color)), Pos(x, y, z), Vector3.one * radius, true);

        /// <summary>Horizontal ground decal (prototype <c>flat()</c>): receives shadows, casts none.</summary>
        public GameObject Flat(Transform parent, float w, float d, int color, float x, float z, float y = 0.01f, string name = "Flat") =>
            Make(name, parent, LowPolyMeshFactory.Plane(), MaterialPaletteEditor.Get(Hex(color)), Pos(x, y, z), new Vector3(w, 1, d), false);

        /// <summary>Self-lit box (prototype MeshBasicMaterial), e.g. lamp bulbs.</summary>
        public GameObject GlowBox(Transform parent, float w, float h, float d, int color, float x, float y, float z, string name = "Glow")
        {
            GameObject go = Make(name, parent, LowPolyMeshFactory.Cube, MaterialPaletteEditor.Get(Hex(color), true), Pos(x, y, z), new Vector3(w, h, d), false);
            go.GetComponent<MeshRenderer>().shadowCastingMode = ShadowCastingMode.Off;
            return go;
        }

        /// <summary>Rotation around X in prototype radians.</summary>
        public void RotateX(GameObject go, float rad) => go.transform.localRotation = Quaternion.Euler((mirrorZ ? -rad : rad) * Mathf.Rad2Deg, 0, 0);

        /// <summary>Rotation around Y in prototype radians.</summary>
        public void RotateY(GameObject go, float rad) => go.transform.localRotation = Quaternion.Euler(0, (mirrorZ ? -rad : rad) * Mathf.Rad2Deg, 0);

        /// <summary>
        /// Sign board facing the camera (prototype <c>signMesh(text, w, bg, fg)</c>: a w × w/4 panel) with a
        /// localized 3D TextMeshPro label that follows the selected language.
        /// </summary>
        public Transform Sign(Transform parent, string key, float w, int background, int foreground, float x, float y, float z)
        {
            Transform sign = Group("Sign_" + key, parent, x, z, y);
            float h = w / 4f;
            GameObject board = Make("Board", sign, LowPolyMeshFactory.Cube, MaterialPaletteEditor.Get(Hex(background)), Vector3.zero, new Vector3(w, h, 0.04f), true);
            board.GetComponent<MeshRenderer>().shadowCastingMode = ShadowCastingMode.Off;

            var textGo = new GameObject("Text", typeof(RectTransform));
            textGo.transform.SetParent(sign, false);
            // TMP text reads correctly from −Z; world signs face the camera (Unity −Z) so they sit just in front of the board.
            textGo.transform.localPosition = new Vector3(0, 0, mirrorZ ? -0.025f : 0.025f);
            if (!mirrorZ) textGo.transform.localRotation = Quaternion.Euler(0, 180, 0);
            var rect = (RectTransform)textGo.transform;
            rect.sizeDelta = new Vector2(w * 0.9f, h * 0.8f);
            var tmp = textGo.AddComponent<TextMeshPro>();
            if (_signFont != null) tmp.font = _signFont;
            tmp.text = (string)_previewStrings[key] ?? key;
            tmp.color = Hex(foreground);
            tmp.alignment = TextAlignmentOptions.Center;
            tmp.textWrappingMode = TextWrappingModes.NoWrap;
            tmp.enableAutoSizing = true;
            tmp.fontSizeMin = 0.1f;
            tmp.fontSizeMax = h * 10f;
            tmp.GetComponent<MeshRenderer>().shadowCastingMode = ShadowCastingMode.Off;
            textGo.AddComponent<LocalizedTmpText>().SetKey(key);
            return sign;
        }

        /// <summary>Rotation around Z in prototype radians (unchanged by the Z mirror).</summary>
        public void RotateZ(GameObject go, float rad) => go.transform.localRotation = Quaternion.Euler(0, 0, rad * Mathf.Rad2Deg);

        public static void SetStaticRecursive(GameObject root)
        {
            foreach (Transform t in root.GetComponentsInChildren<Transform>(true))
                GameObjectUtility.SetStaticEditorFlags(t.gameObject, StaticEditorFlags.BatchingStatic);
        }

        static GameObject Make(string name, Transform parent, Mesh mesh, Material material, Vector3 localPos, Vector3 scale, bool castShadows)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            go.transform.localPosition = localPos;
            go.transform.localScale = scale;
            go.AddComponent<MeshFilter>().sharedMesh = mesh;
            var r = go.AddComponent<MeshRenderer>();
            r.sharedMaterial = material;
            r.shadowCastingMode = castShadows ? ShadowCastingMode.On : ShadowCastingMode.Off;
            r.receiveShadows = true;
            return go;
        }
    }
}
