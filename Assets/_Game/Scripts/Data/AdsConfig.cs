using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// LevelPlay credentials from the dashboard (https://platform.ironsrc.com/ → Apps / Ad units). Empty keys: no ads in
    /// device builds; the Editor shows LevelPlay mock ads with placeholder ids.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Ads Config", fileName = "AdsConfig")]
    public sealed class AdsConfig : ScriptableObject
    {
        public string androidAppKey = "";
        public string iosAppKey = "";
        public string androidRewardedAdUnitId = "";
        public string iosRewardedAdUnitId = "";
        [Tooltip("Pass the placement names (double_payout, instant_cash) to LevelPlay — only once they exist in the dashboard.")]
        public bool useDashboardPlacements;
        [Tooltip("Development builds only: opens the LevelPlay Test Suite after init. Turn off for release.")]
        public bool launchTestSuite;
        [Tooltip("Seconds between instant-cash offers.")]
        public float instantCashCooldown = 300f;
        [Tooltip("Seconds the ×2 offer stays after a truck pays.")]
        public float doublePayoutWindow = 8f;

        const string EditorPlaceholder = "editor-mock";

        public string AppKey => Pick(androidAppKey, iosAppKey);
        public string RewardedAdUnitId => Pick(androidRewardedAdUnitId, iosRewardedAdUnitId);

        static string Pick(string android, string ios)
        {
#if UNITY_EDITOR
            string id = Application.platform == RuntimePlatform.IPhonePlayer ? ios : android;
            return string.IsNullOrEmpty(id) ? EditorPlaceholder : id;
#elif UNITY_IOS
            return ios;
#else
            return android;
#endif
        }
    }
}
