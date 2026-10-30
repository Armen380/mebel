using System;
using System.Collections.Generic;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.TextCore.LowLevel;

namespace FF.Editor
{
    /// <summary>
    /// Creates dynamic TMP font assets for Noto Sans Armenian (primary) with Noto Sans (Latin + Cyrillic)
    /// as fallback, for each weight, and makes the ExtraBold pair the TMP default.
    /// </summary>
    public static class FontSetup
    {
        public const string FontsDir = "Assets/_Game/Art/Fonts";
        public const string DefaultWeight = "ExtraBold";
        static readonly string[] Weights = { "Bold", "ExtraBold", "Black" };

        public static string ArmenianAssetPath(string weight) => $"{FontsDir}/NotoSansArmenian-{weight} SDF.asset";
        public static string LatinAssetPath(string weight) => $"{FontsDir}/NotoSans-{weight} SDF.asset";

        [MenuItem("FF/Setup Fonts", priority = 2)]
        public static void Setup()
        {
            foreach (string weight in Weights)
            {
                TMP_FontAsset latin = Ensure($"{FontsDir}/NotoSans-{weight}.ttf", LatinAssetPath(weight));
                TMP_FontAsset armenian = Ensure($"{FontsDir}/NotoSansArmenian-{weight}.ttf", ArmenianAssetPath(weight));
                armenian.fallbackFontAssetTable = new List<TMP_FontAsset> { latin };
                EditorUtility.SetDirty(armenian);
            }

            TMP_FontAsset primary = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(ArmenianAssetPath(DefaultWeight));
            TMP_FontAsset fallback = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(LatinAssetPath(DefaultWeight));
            var settings = new SerializedObject(TMP_Settings.instance);
            settings.FindProperty("m_defaultFontAsset").objectReferenceValue = primary;
            SerializedProperty globalFallbacks = settings.FindProperty("m_fallbackFontAssets");
            globalFallbacks.ClearArray();
            globalFallbacks.InsertArrayElementAtIndex(0);
            globalFallbacks.GetArrayElementAtIndex(0).objectReferenceValue = fallback;
            settings.ApplyModifiedPropertiesWithoutUndo();

            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] Fonts ready: default '{primary.name}' → fallback '{fallback.name}'.");
        }

        static TMP_FontAsset Ensure(string fontPath, string assetPath)
        {
            var existing = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(assetPath);
            if (existing != null) return existing;

            var font = AssetDatabase.LoadAssetAtPath<Font>(fontPath);
            if (font == null) throw new InvalidOperationException($"Font file missing: {fontPath}");

            // TMP's own "Create > TextMeshPro > Font Asset > SDF" path: it wires the source font
            // reference that dynamic atlases need in the Editor. It writes "<font> SDF.asset" next to the font.
            Type menu = Type.GetType("TMPro.TMP_FontAsset_CreationMenu, Unity.TextMeshPro.Editor", true);
            MethodInfo create = menu.GetMethod("CreateFontAssetFromSelectedObject", BindingFlags.NonPublic | BindingFlags.Static)
                                ?? throw new MissingMethodException("TMP_FontAsset_CreationMenu.CreateFontAssetFromSelectedObject");
            create.Invoke(null, new object[] { font, GlyphRenderMode.SDFAA });
            AssetDatabase.Refresh();

            var asset = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(assetPath);
            if (asset == null) throw new InvalidOperationException($"TMP did not create {assetPath}");
            return asset;
        }
    }
}
