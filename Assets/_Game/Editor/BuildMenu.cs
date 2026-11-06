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
    /// <item>Android release AAB for Google Play — signed with the keystore from Player Settings › Publishing Settings,
    /// or else with the upload key in ~/Keystores/FurnitureFactory (outside the public repo; the build stops when neither exists);</item>
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

        /// <summary>The upload key made for the user on 2026-11-06, outside the (public) repo: keystore + properties file.</summary>
        static string KeyProperties =>
            Path.Combine(System.Environment.GetFolderPath(System.Environment.SpecialFolder.UserProfile),
                "Keystores", "FurnitureFactory", "upload.properties");

        [MenuItem("FF/Build/Android Release AAB", priority = 201)]
        public static void AndroidReleaseBundle()
        {
            bool fromFile = false;
            if (!PlayerSettings.Android.useCustomKeystore || string.IsNullOrEmpty(PlayerSettings.Android.keystoreName))
            {
                if (!UseKeyFile())
                {
                    EditorUtility.DisplayDialog("Keystore needed",
                        $"No upload key: {KeyProperties} is missing, and Player Settings › Android › Publishing Settings has no keystore.", "OK");
                    return;
                }
                fromFile = true;
            }
            AndroidSettings();
            EditorUserBuildSettings.buildAppBundle = true;
            try
            {
                Build(BuildTarget.Android, $"{Root}/Android/FurnitureFactory-{PlayerSettings.bundleVersion}.aab", BuildOptions.None);
            }
            finally
            {
                EditorUserBuildSettings.buildAppBundle = false;
                if (fromFile)
                {
                    // keep the user's home path and the passwords out of ProjectSettings
                    PlayerSettings.Android.useCustomKeystore = false;
                    PlayerSettings.Android.keystoreName = "";
                    PlayerSettings.Android.keyaliasName = "";
                    PlayerSettings.Android.keystorePass = "";
                    PlayerSettings.Android.keyaliasPass = "";
                }
            }
        }

        /// <summary>Signs with the key in <see cref="KeyProperties"/> (lines key=value: keystore, keyAlias, storePassword, keyPassword).</summary>
        static bool UseKeyFile()
        {
            if (!File.Exists(KeyProperties)) return false;
            var values = new System.Collections.Generic.Dictionary<string, string>();
            foreach (string line in File.ReadAllLines(KeyProperties))
            {
                int eq = line.IndexOf('=');
                if (line.StartsWith("#") || eq <= 0) continue;
                values[line.Substring(0, eq).Trim()] = line.Substring(eq + 1).Trim();
            }
            if (!values.TryGetValue("keystore", out string keystore) || !File.Exists(keystore)) return false;
            PlayerSettings.Android.useCustomKeystore = true;
            PlayerSettings.Android.keystoreName = keystore;
            PlayerSettings.Android.keystorePass = Value(values, "storePassword", "");
            PlayerSettings.Android.keyaliasName = Value(values, "keyAlias", "upload");
            PlayerSettings.Android.keyaliasPass = Value(values, "keyPassword", "");
            return true;
        }

        static string Value(System.Collections.Generic.Dictionary<string, string> values, string key, string fallback) =>
            values.TryGetValue(key, out string v) ? v : fallback;

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
