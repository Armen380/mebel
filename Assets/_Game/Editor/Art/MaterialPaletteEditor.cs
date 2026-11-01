using FF.Data;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor.Art
{
    /// <summary>
    /// Creates the shared flat-colour URP materials on demand and records them in the MaterialPalette asset, each lit
    /// colour with a transparent "ghost" twin for building fading (made here so the transparent variant ships).
    /// </summary>
    public static class MaterialPaletteEditor
    {
        public const string Folder = "Assets/_Game/Art/Materials";
        public const string PalettePath = Folder + "/MaterialPalette.asset";
        const string LitShader = "Universal Render Pipeline/Simple Lit";
        const string UnlitShader = "Universal Render Pipeline/Unlit";
        const float GhostOpacity = 0.22f;

        public static MaterialPalette Palette => DataImporter.GetOrCreate<MaterialPalette>(PalettePath);

        public static Material Get(Color32 color, bool unlit = false)
        {
            MaterialPalette palette = Palette;
            Material existing = palette.Find(color, unlit);
            if (existing != null) return existing;

            string hex = ColorUtility.ToHtmlStringRGB(color).ToLowerInvariant();
            string path = $"{Folder}/{(unlit ? "Unlit" : "Flat")}_{hex}.mat";
            var material = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (material == null)
            {
                material = new Material(Shader.Find(unlit ? UnlitShader : LitShader)) { enableInstancing = true };
                material.SetColor("_BaseColor", color);
                if (!unlit) material.SetFloat("_Smoothness", 0.1f);
                AssetDatabase.CreateAsset(material, path);
            }
            palette.entries.Add(new MaterialPalette.Entry { color = color, unlit = unlit, material = material, ghost = unlit ? null : Ghost(color) });
            EditorUtility.SetDirty(palette);
            return material;
        }

        /// <summary>Adds missing ghost twins to every lit palette entry (palettes made before M4).</summary>
        public static void EnsureGhosts()
        {
            MaterialPalette palette = Palette;
            for (int i = 0; i < palette.entries.Count; i++)
            {
                MaterialPalette.Entry e = palette.entries[i];
                if (e.unlit || e.ghost != null) continue;
                e.ghost = Ghost(e.color);
                palette.entries[i] = e;
            }
            EditorUtility.SetDirty(palette);
        }

        /// <summary>Prototype <c>ghostOf</c>: same colour, transparent, opacity 0.22, no depth write.</summary>
        static Material Ghost(Color32 color)
        {
            string path = $"{Folder}/Ghost/Ghost_{ColorUtility.ToHtmlStringRGB(color).ToLowerInvariant()}.mat";
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (m != null) return m;
            DataImporter.EnsureFolder(Folder + "/Ghost");
            m = new Material(Shader.Find(LitShader)) { enableInstancing = true };
            Color c = color;
            c.a = GhostOpacity;
            m.SetColor("_BaseColor", c);
            m.SetFloat("_Smoothness", 0.1f);
            m.SetFloat("_Surface", 1);
            m.SetFloat("_Blend", 0);
            m.SetFloat("_SrcBlend", (float)BlendMode.SrcAlpha);
            m.SetFloat("_DstBlend", (float)BlendMode.OneMinusSrcAlpha);
            m.SetFloat("_SrcBlendAlpha", (float)BlendMode.One);
            m.SetFloat("_DstBlendAlpha", (float)BlendMode.OneMinusSrcAlpha);
            m.SetFloat("_ZWrite", 0);
            m.SetOverrideTag("RenderType", "Transparent");
            m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
            m.renderQueue = (int)RenderQueue.Transparent;
            AssetDatabase.CreateAsset(m, path);
            return m;
        }
    }
}
