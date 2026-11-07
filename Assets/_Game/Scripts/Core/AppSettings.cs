using UnityEngine;

namespace FF.Core
{
    /// <summary>Process-wide player settings applied once at startup.</summary>
    public static class AppSettings
    {
        public const int TargetFrameRate = 60;
        /// <summary>The menu shows only the slow orbit camera (simulation paused): half the frames, less battery and heat.</summary>
        public const int MenuFrameRate = 30;

        public static int FrameRate(bool inMenu) => inMenu ? MenuFrameRate : TargetFrameRate;
        public const string GameScene = "Game";

        public static void Apply()
        {
            Application.targetFrameRate = TargetFrameRate;
            QualitySettings.vSyncCount = 0;
        }
    }
}
