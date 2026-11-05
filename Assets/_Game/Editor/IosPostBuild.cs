using UnityEditor;
using UnityEditor.Callbacks;
using UnityEngine;
#if UNITY_IOS
using System.IO;
using UnityEditor.iOS.Xcode;
#endif

namespace FF.Editor
{
    /// <summary>Writes the App Tracking Transparency description into the exported Xcode project's Info.plist.</summary>
    public static class IosPostBuild
    {
        const string TrackingDescription =
            "Your choice lets us show ads that fit you better. Ads only appear when you choose to watch one for a reward.";

        [PostProcessBuild(999)]
        public static void OnPostProcessBuild(BuildTarget target, string buildPath)
        {
            if (target != BuildTarget.iOS) return;
#if UNITY_IOS
            string plistPath = Path.Combine(buildPath, "Info.plist");
            var plist = new PlistDocument();
            plist.ReadFromFile(plistPath);
            plist.root.SetString("NSUserTrackingUsageDescription", TrackingDescription);
            plist.WriteToFile(plistPath);
            Debug.Log("[FF] iOS: NSUserTrackingUsageDescription written to Info.plist.");
#endif
        }
    }
}
