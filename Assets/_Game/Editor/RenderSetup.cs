using FF.Core;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace FF.Editor
{
    /// <summary>
    /// Mobile URP tiers (03_UNITY_ARCHITECTURE, M9 settings): three quality levels Low / Medium / High, each with its own
    /// URP asset sharing the mobile renderer.
    /// <list type="bullet">
    /// <item>Low: no shadows, no MSAA, render scale 0.75.</item>
    /// <item>Medium: hard shadows 35 m, 1 cascade, MSAA 2×, render scale 0.9.</item>
    /// <item>High: soft shadows 35 m at 2048, MSAA 4×, render scale 1.</item>
    /// </list>
    /// No HDR anywhere. The game picks the level at runtime from the menu setting; Medium is the platform default.
    /// </summary>
    public static class RenderSetup
    {
        const string MediumAssetPath = "Assets/Settings/Mobile_RPAsset.asset";
        const string LowAssetPath = "Assets/Settings/Mobile_Low_RPAsset.asset";
        const string HighAssetPath = "Assets/Settings/Mobile_High_RPAsset.asset";

        [MenuItem("FF/Setup Render Settings", priority = 4)]
        public static void Setup()
        {
            var medium = AssetDatabase.LoadAssetAtPath<UniversalRenderPipelineAsset>(MediumAssetPath);
            Configure(medium, true, false, 2, 0.9f, 2048);
            UniversalRenderPipelineAsset low = CopyOf(medium, LowAssetPath);
            Configure(low, false, false, 1, 0.75f, 1024);
            UniversalRenderPipelineAsset high = CopyOf(medium, HighAssetPath);
            Configure(high, true, true, 4, 1f, 2048);

            var assets = new[] { low, medium, high };
            var quality = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/QualitySettings.asset")[0]);
            SerializedProperty levels = quality.FindProperty("m_QualitySettings");
            while (levels.arraySize < assets.Length) levels.InsertArrayElementAtIndex(levels.arraySize - 1);
            while (levels.arraySize > assets.Length) levels.DeleteArrayElementAtIndex(levels.arraySize - 1);
            for (int i = 0; i < assets.Length; i++)
            {
                SerializedProperty level = levels.GetArrayElementAtIndex(i);
                level.FindPropertyRelative("name").stringValue = QualityRules.LevelNames[i];
                level.FindPropertyRelative("customRenderPipeline").objectReferenceValue = assets[i];
                level.FindPropertyRelative("vSyncCount").intValue = 0;
                level.FindPropertyRelative("excludedTargetPlatforms").ClearArray(); // every tier on every platform
            }
            int defaultLevel = (int)QualityTier.Medium;
            SerializedProperty defaults = quality.FindProperty("m_PerPlatformDefaultQuality");
            for (int i = 0; i < defaults.arraySize; i++)
                defaults.GetArrayElementAtIndex(i).FindPropertyRelative("second").intValue = defaultLevel;
            quality.ApplyModifiedPropertiesWithoutUndo();
            QualitySettings.SetQualityLevel(defaultLevel, true);
            GraphicsSettings.defaultRenderPipeline = medium;

            AssetDatabase.SaveAssets();
            Debug.Log("[FF] Render settings: quality levels Low / Medium / High with their URP assets; default Medium.");
        }

        static UniversalRenderPipelineAsset CopyOf(UniversalRenderPipelineAsset source, string path)
        {
            if (AssetDatabase.LoadAssetAtPath<UniversalRenderPipelineAsset>(path) == null)
                AssetDatabase.CopyAsset(AssetDatabase.GetAssetPath(source), path);
            return AssetDatabase.LoadAssetAtPath<UniversalRenderPipelineAsset>(path);
        }

        static void Configure(UniversalRenderPipelineAsset urp, bool shadows, bool softShadows, int msaa, float renderScale, int shadowResolution)
        {
            urp.supportsHDR = false;
            urp.msaaSampleCount = msaa;
            urp.renderScale = renderScale;
            urp.shadowDistance = 35f;
            urp.shadowCascadeCount = 1;
            var so = new SerializedObject(urp);
            so.FindProperty("m_MainLightShadowsSupported").boolValue = shadows;
            so.FindProperty("m_SoftShadowsSupported").boolValue = softShadows;
            so.FindProperty("m_MainLightShadowmapResolution").intValue = shadowResolution;
            so.ApplyModifiedPropertiesWithoutUndo();
            EditorUtility.SetDirty(urp);
        }
    }
}
