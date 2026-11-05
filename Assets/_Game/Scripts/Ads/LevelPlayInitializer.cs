using System.Collections;
using FF.Core;
using FF.Data;
using Unity.Services.LevelPlay;
using UnityEngine;
#if UNITY_IOS && !UNITY_EDITOR
using System.Runtime.InteropServices;
#endif

namespace FF.Ads
{
    /// <summary>
    /// Starts LevelPlay once the privacy answers are in: the player's personalized-ads choice (GDPR consent; refusing also
    /// sets the CCPA opt-out), then on iOS the App Tracking Transparency prompt, then <c>LevelPlay.Init</c>. Without an app
    /// key (device build not configured yet) ads stay off. Child-directed (COPPA) is not set: the game is not for children.
    /// </summary>
    public sealed class LevelPlayInitializer : MonoBehaviour
    {
        [SerializeField] AdsConfig config;

        public static bool Initialized { get; private set; }
        public static event System.Action InitSucceeded;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig) => config = adsConfig;

#if UNITY_IOS && !UNITY_EDITOR
        delegate void AttCallback(int status);

        [DllImport("__Internal")] static extern int _ATT_GetStatus();
        [DllImport("__Internal")] static extern void _ATT_RequestPermission(AttCallback callback);

        const int AttNotDetermined = 0;
        static bool _attDone;

        [AOT.MonoPInvokeCallback(typeof(AttCallback))]
        static void OnAttCallback(int status)
        {
            Debug.Log($"[FF] ATT answered: status {status}");
            _attDone = true;
        }

        IEnumerator RequestAtt()
        {
            if (_ATT_GetStatus() != AttNotDetermined) yield break;
            _attDone = false;
            _ATT_RequestPermission(OnAttCallback);
            yield return new WaitUntil(() => _attDone);
        }
#endif

        IEnumerator Start()
        {
            string appKey = config != null ? config.AppKey : null;
            if (string.IsNullOrEmpty(appKey))
            {
                Debug.Log("[FF] LevelPlay: no app key for this platform yet — ads are off.");
                yield break;
            }
            // the menu's consent dialog asks on first launch
            yield return new WaitUntil(() => AdsConsent.Known);
#if UNITY_IOS && !UNITY_EDITOR
            yield return RequestAtt();
#endif
            InitializeLevelPlay(appKey);
        }

        void OnEnable() => AdsConsent.Changed += ApplyPrivacy;

        void OnDisable() => AdsConsent.Changed -= ApplyPrivacy;

        static void ApplyPrivacy()
        {
            bool personalized = AdsConsent.Personalized;
            LevelPlayPrivacySettings.SetGDPRConsent(personalized);
            LevelPlayPrivacySettings.SetCCPA(!personalized);
        }

        void InitializeLevelPlay(string appKey)
        {
            ApplyPrivacy(); // before Init
            if (config.launchTestSuite && Debug.isDebugBuild) LevelPlay.SetMetaData("is_test_suite", "enable");
            LevelPlay.OnInitSuccess += OnInitSuccess;
            LevelPlay.OnInitFailed += OnInitFailed;
            LevelPlay.Init(appKey);
        }

        void OnInitSuccess(LevelPlayConfiguration configuration)
        {
            Debug.Log("[FF] LevelPlay SDK initialized successfully");
            Initialized = true;
            InitSucceeded?.Invoke();
            if (config.launchTestSuite && Debug.isDebugBuild) LevelPlay.LaunchTestSuite();
        }

        void OnInitFailed(LevelPlayInitError error)
        {
            Debug.LogWarning($"[FF] LevelPlay initialization failed: {error.ErrorMessage} — ads stay off this session.");
        }

        void OnDestroy()
        {
            LevelPlay.OnInitSuccess -= OnInitSuccess;
            LevelPlay.OnInitFailed -= OnInitFailed;
            Initialized = false;
            InitSucceeded = null;
        }
    }
}
