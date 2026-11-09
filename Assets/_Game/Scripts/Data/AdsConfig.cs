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
        public string androidInterstitialAdUnitId = "";
        public string iosInterstitialAdUnitId = "";
        [Tooltip("Pass the placement names (double_payout, instant_cash) to LevelPlay — only once they exist in the dashboard.")]
        public bool useDashboardPlacements;
        [Tooltip("Development builds only: opens the LevelPlay Test Suite after init. Turn off for release.")]
        public bool launchTestSuite;
        [Tooltip("Seconds between offer popups (×2 payout or bonus cash), counted from when the last one went away.")]
        public float instantCashCooldown = 300f;
        [Tooltip("Seconds after a truck pays during which the popup offers ×2 instead of bonus cash.")]
        public float doublePayoutWindow = 8f;
        [Tooltip("Seconds the popup stays when the player neither watches nor closes it.")]
        public float cashOfferWindow = 12f;

        [Header("Interstitial (every N levels, user decision 2026-11-08)")]
        [Tooltip("An interstitial on every Nth level-up.")]
        public int levelsPerInterstitial = 3;
        [Tooltip("Real seconds after any ad before an interstitial may show.")]
        public float interstitialMinGap = 120f;
        [Tooltip("Real seconds after the game starts before the first interstitial.")]
        public float interstitialSessionDelay = 60f;
        [Tooltip("Real seconds between the level-up and the interstitial, so the level-up is seen first.")]
        public float interstitialDelay = 1.5f;

        [Header("Privacy")]
        [Tooltip("Public privacy policy page (stores require a link inside the app too); opened from the menu.")]
        public string privacyPolicyUrl = "https://armen380.github.io/mebel/privacy/";

        const string EditorPlaceholder = "editor-mock";

        public string AppKey => Pick(androidAppKey, iosAppKey);
        public string RewardedAdUnitId => Pick(androidRewardedAdUnitId, iosRewardedAdUnitId);
        public string InterstitialAdUnitId => Pick(androidInterstitialAdUnitId, iosInterstitialAdUnitId);

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
