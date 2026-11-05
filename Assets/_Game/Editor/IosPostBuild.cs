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
            "Your choice lets us show ads that fit you better. Ads only appear when you choose to watch one for a reward.";

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
