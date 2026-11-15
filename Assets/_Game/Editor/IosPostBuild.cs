using System.IO;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// Writes the App Tracking Transparency description into the exported Xcode project's Info.plist. Plain text edit, no
    /// <c>#if UNITY_IOS</c>: an export that switches the platform during the build still runs this.
    /// </summary>
    public static class IosPostBuild
    {
        const string Key = "NSUserTrackingUsageDescription";
        const string EncryptionKey = "ITSAppUsesNonExemptEncryption";
        const string TrackingDescription =
            "Your choice lets us show ads that fit you better. The game shows ads between levels and short videos you choose to watch for a reward.";

        const string MinimumIos = "15.0";
        const string PodfileMarker = "# FF: minimum iOS for every pod";

        /// <summary>
        /// Xcode 27 rejects pods whose deployment target is below iOS 15 (IronSource / Unity Ads declare 12–13): a
        /// post_install block in the Podfile raises them. Runs between the dependency resolver's Podfile generation (40)
        /// and its pod install (50).
        /// </summary>
        [PostProcessBuild(45)]
        public static void RaisePodsDeploymentTarget(BuildTarget target, string buildPath)
        {
            if (target != BuildTarget.iOS) return;
            string podfile = Path.Combine(buildPath, "Podfile");
            if (!File.Exists(podfile)) return;
            string text = File.ReadAllText(podfile);
            if (text.Contains(PodfileMarker)) return;
            text += $@"
{PodfileMarker}
post_install do |installer|
  installer.pods_project.targets.each do |t|
    t.build_configurations.each do |c|
      c.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '{MinimumIos}'
    end
  end
end
";
            File.WriteAllText(podfile, text);
            Debug.Log($"[FF] iOS: pods raised to iOS {MinimumIos} in the Podfile.");
        }

        /// <summary>
        /// Writes the App Tracking Transparency description and the export-compliance answer into Info.plist. The game
        /// only uses HTTPS through iOS (exempt encryption), so <c>ITSAppUsesNonExemptEncryption = false</c> lets App Store
        /// Connect skip the encryption question for every build.
        /// </summary>
        [PostProcessBuild(999)]
        public static void OnPostProcessBuild(BuildTarget target, string buildPath)
        {
            if (target != BuildTarget.iOS) return;
            string plistPath = Path.Combine(buildPath, "Info.plist");
            if (!File.Exists(plistPath)) return;
            string plist = File.ReadAllText(plistPath);
            string updated = WithKey(plist, Key, $"<string>{TrackingDescription}</string>");
            updated = WithKey(updated, EncryptionKey, "<false/>");
            if (updated == plist) return;
            File.WriteAllText(plistPath, updated);
            Debug.Log("[FF] iOS: NSUserTrackingUsageDescription and ITSAppUsesNonExemptEncryption written to Info.plist.");
        }

        /// <summary>Adds <paramref name="key"/> with <paramref name="valueXml"/> to the root dict; unchanged if the key exists.</summary>
        public static string WithKey(string plist, string key, string valueXml)
        {
            if (plist.Contains($"<key>{key}</key>")) return plist;
            int end = plist.LastIndexOf("</dict>", System.StringComparison.Ordinal);
            if (end < 0) return plist;
            return plist.Insert(end, $"  <key>{key}</key>\n    {valueXml}\n  ");
        }
    }
}
