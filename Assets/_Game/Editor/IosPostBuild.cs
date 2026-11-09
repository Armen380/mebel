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

        [PostProcessBuild(999)]
        public static void OnPostProcessBuild(BuildTarget target, string buildPath)
        {
            if (target != BuildTarget.iOS) return;
            string plistPath = Path.Combine(buildPath, "Info.plist");
            if (!File.Exists(plistPath)) return;
            string plist = File.ReadAllText(plistPath);
            if (plist.Contains($"<key>{Key}</key>")) return;
            int end = plist.LastIndexOf("</dict>", System.StringComparison.Ordinal);
            if (end < 0) return;
            plist = plist.Insert(end, $"  <key>{Key}</key>\n    <string>{TrackingDescription}</string>\n  ");
            File.WriteAllText(plistPath, plist);
            Debug.Log("[FF] iOS: NSUserTrackingUsageDescription written to Info.plist.");
        }
    }
}
