using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;

namespace FF.Editor
{
    /// <summary>
    /// Mobile URP settings from 03_UNITY_ARCHITECTURE: no HDR, MSAA 2x, shadow distance 35, one cascade.
    /// The Editor and Standalone use the Mobile quality level too, so what you see matches the phone.
    /// Low/Medium/High tiers come in M9.
    /// </summary>
    public static class RenderSetup
    {
        const string MobileAssetPath = "Assets/Settings/Mobile_RPAsset.asset";
        const string MobileLevelName = "Mobile";

        [MenuItem("FF/Setup Render Settings", priority = 4)]
        public static void Setup()
        {
            var urp = AssetDatabase.LoadAssetAtPath<UniversalRenderPipelineAsset>(MobileAssetPath);
            urp.supportsHDR = false;
            urp.msaaSampleCount = 2;
            urp.shadowDistance = 35f;
            urp.shadowCascadeCount = 1;
            EditorUtility.SetDirty(urp);

            int mobile = System.Array.IndexOf(QualitySettings.names, MobileLevelName);
            var quality = new SerializedObject(AssetDatabase.LoadAllAssetsAtPath("ProjectSettings/QualitySettings.asset")[0]);
            SerializedProperty defaults = quality.FindProperty("m_PerPlatformDefaultQuality");
            for (int i = 0; i < defaults.arraySize; i++)
            {
                SerializedProperty entry = defaults.GetArrayElementAtIndex(i);
                string platform = entry.FindPropertyRelative("first").stringValue;
                if (platform == "Standalone" || platform == "Android" || platform == "iPhone")
                    entry.FindPropertyRelative("second").intValue = mobile;
            }
            quality.ApplyModifiedPropertiesWithoutUndo();
            QualitySettings.SetQualityLevel(mobile, true);
            GraphicsSettings.defaultRenderPipeline = urp;

            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] Render settings: {urp.name} HDR off, MSAA 2x, shadows 35 m / 1 cascade; quality '{MobileLevelName}'.");
        }
    }
}
