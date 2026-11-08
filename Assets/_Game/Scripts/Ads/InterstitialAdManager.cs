using System;
using FF.Core;
using FF.Data;
using Unity.Services.LevelPlay;
using UnityEngine;

namespace FF.Ads
{
    /// <summary>
    /// The one interstitial ad unit (user decision 2026-11-08: a full-screen ad every few levels, see
    /// <see cref="InterstitialScheduler"/>). Same pattern as <see cref="RewardedAdManager"/>: created after LevelPlay init,
    /// kept preloaded, a failed load retries in 30 s, readiness cached (IsAdReady goes through JNI). Sound is paused while
    /// the ad is on screen; <see cref="AdClock"/> records it so ads never follow each other too closely.
    /// </summary>
    public sealed class InterstitialAdManager : MonoBehaviour, IInterstitialAds
    {
        const float RetrySeconds = 30f;
        const float ReadyPollSeconds = 0.5f;

        [SerializeField] AdsConfig config;

        LevelPlayInterstitialAd _ad;
        Action _onClosed;
        bool _closed, _showing, _ready;
        float _nextReadyPoll;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig) => config = adsConfig;

        public bool IsReady
        {
            get
            {
                if (_ad == null || _showing) return false;
                float now = Time.unscaledTime;
                if (now >= _nextReadyPoll)
                {
                    _nextReadyPoll = now + ReadyPollSeconds;
                    _ready = _ad.IsAdReady();
                }
                return _ready;
            }
        }

        void Awake() => Services.Register<IInterstitialAds>(this);

        void Start()
        {
            if (LevelPlayInitializer.Initialized) CreateAd();
            else LevelPlayInitializer.InitSucceeded += CreateAd;
        }

        void CreateAd()
        {
            LevelPlayInitializer.InitSucceeded -= CreateAd;
            if (_ad != null || string.IsNullOrEmpty(config.InterstitialAdUnitId)) return;
            _ad = new LevelPlayInterstitialAd(config.InterstitialAdUnitId);
            _ad.OnAdLoaded += OnAdLoaded;
            _ad.OnAdLoadFailed += OnAdLoadFailed;
            _ad.OnAdDisplayed += OnAdDisplayed;
            _ad.OnAdDisplayFailed += OnAdDisplayFailed;
            _ad.OnAdClosed += OnAdClosed;
            _ad.OnAdClicked += OnAdClicked;
            _ad.OnAdImpressionDataReady += OnImpressionDataReady;
            LoadAd();
        }

        void OnDestroy()
        {
            LevelPlayInitializer.InitSucceeded -= CreateAd;
            if (_showing) Finish();
            if (_ad == null) return;
            _ad.OnAdLoaded -= OnAdLoaded;
            _ad.OnAdLoadFailed -= OnAdLoadFailed;
            _ad.OnAdDisplayed -= OnAdDisplayed;
            _ad.OnAdDisplayFailed -= OnAdDisplayFailed;
            _ad.OnAdClosed -= OnAdClosed;
            _ad.OnAdClicked -= OnAdClicked;
            _ad.OnAdImpressionDataReady -= OnImpressionDataReady;
            _ad.DestroyAd();
            _ad = null;
        }

        void LoadAd()
        {
            if (_ad != null) _ad.LoadAd();
        }

        public void Show(string placement, Action onClosed)
        {
            _nextReadyPoll = 0f;
            if (!IsReady)
            {
                onClosed?.Invoke();
                return;
            }
            string name = config.useDashboardPlacements ? placement : null;
            _onClosed = onClosed;
            _showing = true;
            _closed = false;
            AdClock.Begin();
            AudioListener.pause = true;
            Debug.Log($"[FF] Showing interstitial ad ({placement}).");
            _ad.ShowAd(name);
        }

        // the close is handed back on the next frame, on the main thread
        void Update()
        {
            if (!_closed) return;
            _closed = false;
            Finish();
        }

        void Finish()
        {
            _showing = false;
            AudioListener.pause = false;
            AdClock.End(Time.realtimeSinceStartup);
            Action done = _onClosed;
            _onClosed = null;
            _nextReadyPoll = 0f;
            done?.Invoke();
        }

        void OnAdLoaded(LevelPlayAdInfo info)
        {
            _nextReadyPoll = 0f;
            Debug.Log($"[FF] Interstitial ad loaded ({info.AdNetwork}).");
        }

        void OnAdLoadFailed(LevelPlayAdError error)
        {
            Debug.LogWarning($"[FF] Interstitial ad failed to load: {error.ErrorMessage}; retry in {RetrySeconds} s.");
            CancelInvoke(nameof(LoadAd));
            Invoke(nameof(LoadAd), RetrySeconds);
        }

        void OnAdDisplayed(LevelPlayAdInfo info) => Debug.Log("[FF] Interstitial ad displayed.");

        void OnAdDisplayFailed(LevelPlayAdInfo info, LevelPlayAdError error)
        {
            Debug.LogWarning($"[FF] Interstitial ad failed to display: {error.ErrorMessage}");
            _closed = true;
            LoadAd();
        }

        void OnAdClosed(LevelPlayAdInfo info)
        {
            Debug.Log("[FF] Interstitial ad closed.");
            _closed = true;
            LoadAd();
        }

        void OnAdClicked(LevelPlayAdInfo info) => Debug.Log("[FF] Interstitial ad clicked.");

        // ILRD: runs on a background thread — logging only, no Unity objects
        void OnImpressionDataReady(LevelPlayImpressionData data)
        {
            if (data == null) return;
            Debug.Log($"[FF] ILRD {data.AdNetwork} / {data.AdFormat} / ${data.Revenue}");
        }
    }
}
