using System.IO;
using UnityEditor;
using UnityEditor.Build.Reporting;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// Player builds into <c>Builds/</c> (git-ignored), never into the project root:
    /// <list type="bullet">
    /// <item>Android development APK (debug key, Profiler connection) for testing on a phone;</item>
    /// <item>Android release AAB for Google Play — signed with the user's own keystore, set up in Player Settings ›
    /// Publishing Settings (the user creates it and types the passwords; the build stops when it is missing);</item>
    /// <item>iOS Xcode project — the user signs and archives the IPA in Xcode with their team.</item>
    /// </list>
    /// IL2CPP, ARM64; Android target API = highest installed.
    /// </summary>
    public static class BuildMenu
    {
        const string Root = "Builds";

        static string[] Scenes()
        {
            var list = new System.Collections.Generic.List<string>();
            foreach (EditorBuildSettingsScene s in EditorBuildSettings.scenes)
                if (s.enabled) list.Add(s.path);
            return list.ToArray();
        }

        static void AndroidSettings()
        {
            PlayerSettings.SetScriptingBackend(UnityEditor.Build.NamedBuildTarget.Android, ScriptingImplementation.IL2CPP);
            PlayerSettings.Android.targetArchitectures = AndroidArchitecture.ARM64;
            PlayerSettings.Android.targetSdkVersion = AndroidSdkVersions.AndroidApiLevelAuto;
            PlayerSettings.Android.minSdkVersion = AndroidSdkVersions.AndroidApiLevel26;
        }

        [MenuItem("FF/Build/Android Development APK", priority = 200)]
        public static void AndroidDevelopmentApk()
        {
            AndroidSettings();
            EditorUserBuildSettings.buildAppBundle = false;
            Build(BuildTarget.Android, $"{Root}/Android/FurnitureFactory-dev.apk",
                BuildOptions.Development | BuildOptions.ConnectWithProfiler);
        }

        [MenuItem("FF/Build/Android Release AAB", priority = 201)]
        public static void AndroidReleaseBundle()
        {
            if (!PlayerSettings.Android.useCustomKeystore || string.IsNullOrEmpty(PlayerSettings.Android.keystoreName))
            {
                EditorUtility.DisplayDialog("Keystore needed",
                    "Create or select your upload keystore in Player Settings › Android › Publishing Settings (Keystore Manager), " +
                    "enter its passwords there, then run this again.", "OK");
                return;
            }
            AndroidSettings();
            EditorUserBuildSettings.buildAppBundle = true;
            Build(BuildTarget.Android, $"{Root}/Android/FurnitureFactory-{PlayerSettings.bundleVersion}.aab", BuildOptions.None);
            EditorUserBuildSettings.buildAppBundle = false;
        }

        [MenuItem("FF/Build/iOS Xcode Project", priority = 202)]
        public static void IosXcodeProject()
        {
            // export with iOS already active: iOS-only post-build steps (LevelPlay SKAdNetwork ids) are compiled for it
            if (EditorUserBuildSettings.activeBuildTarget != BuildTarget.iOS)
            {
                EditorUserBuildSettings.SwitchActiveBuildTarget(BuildTargetGroup.iOS, BuildTarget.iOS);
                EditorUtility.DisplayDialog("Switched to iOS", "The platform is iOS now. Run FF › Build › iOS Xcode Project again.", "OK");
                return;
            }
            PlayerSettings.SetScriptingBackend(UnityEditor.Build.NamedBuildTarget.iOS, ScriptingImplementation.IL2CPP);
            Build(BuildTarget.iOS, $"{Root}/iOS", BuildOptions.None);
        }

        static void Build(BuildTarget target, string path, BuildOptions options)
        {
            Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(path)));
            var report = BuildPipeline.BuildPlayer(new BuildPlayerOptions
            {
                scenes = Scenes(),
                locationPathName = path,
                target = target,
                options = options,
            });
            BuildSummary s = report.summary;
            Debug.Log($"[FF] Build {target} → {path}: {s.result}, {s.totalErrors} errors, {s.totalSize / (1024f * 1024f):0.0} MB, {s.totalTime.TotalMinutes:0.0} min.");
        }
    }
}
