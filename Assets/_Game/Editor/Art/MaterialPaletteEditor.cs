using FF.Data;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Art
{
    /// <summary>Creates the shared flat-colour URP materials on demand and records them in the MaterialPalette asset.</summary>
    public static class MaterialPaletteEditor
    {
        public const string Folder = "Assets/_Game/Art/Materials";
        public const string PalettePath = Folder + "/MaterialPalette.asset";
        const string LitShader = "Universal Render Pipeline/Simple Lit";
        const string UnlitShader = "Universal Render Pipeline/Unlit";

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
            palette.entries.Add(new MaterialPalette.Entry { color = color, unlit = unlit, material = material });
            EditorUtility.SetDirty(palette);
            return material;
        }
    }
}
