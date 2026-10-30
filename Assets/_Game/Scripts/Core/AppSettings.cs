using UnityEngine;

namespace FF.Core
{
    /// <summary>Process-wide player settings applied once at startup.</summary>
    public static class AppSettings
    {
        public const int TargetFrameRate = 60;
        public const string GameScene = "Game";

        public static void Apply()
        {
            Application.targetFrameRate = TargetFrameRate;
            QualitySettings.vSyncCount = 0;
        }
    }
}
