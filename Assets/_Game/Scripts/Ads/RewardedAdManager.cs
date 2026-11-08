using System;
using FF.Core;
using FF.Data;
using Unity.Services.LevelPlay;
using UnityEngine;

namespace FF.Ads
{
    /// <summary>
    /// The one rewarded ad unit (placements: ×2 delivery payout, instant cash). Created after LevelPlay init and kept
    /// preloaded on purpose — the HUD only offers a reward while an ad is ready — so it loads right after init and after
    /// every show; a failed load retries in 30 s. The reward is granted in <c>OnAdRewarded</c> (on the main thread), never
    /// in <c>OnAdClosed</c>. Impression revenue (ILRD, SDK 9.5+ per-ad event) is logged for a future analytics hookup.
    /// </summary>
    public sealed class RewardedAdManager : MonoBehaviour, IRewardedAds
    {
        const float RetrySeconds = 30f;

        [SerializeField] AdsConfig config;

        LevelPlayRewardedAd _ad;
        Action _pendingReward;
        volatile bool _rewardEarned;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig) => config = adsConfig;

        const float ReadyPollSeconds = 0.5f;
        bool _ready;
        float _nextReadyPoll;

        /// <summary>
        /// The HUD asks every frame; the SDK's IsAdReady() goes through JNI and allocates, so its answer is cached and
        /// refreshed twice a second (real time — the menu runs at time scale 0).
        /// </summary>
        public bool IsReady
        {
            get
            {
                if (_ad == null || _pendingReward != null) return false;
                float now = Time.unscaledTime;
                if (now >= _nextReadyPoll)
                {
                    _nextReadyPoll = now + ReadyPollSeconds;
                    _ready = _ad.IsAdReady();
                }
                return _ready;
            }
        }

        /// <summary>Asks the SDK on the next <see cref="IsReady"/> (after a load, a show or a failure).</summary>
        void RefreshReady() => _nextReadyPoll = 0f;

        void Awake() => Services.Register<IRewardedAds>(this);

        void Start()
        {
            if (LevelPlayInitializer.Initialized) CreateAd();
            else LevelPlayInitializer.InitSucceeded += CreateAd;
        }

        void CreateAd()
        {
            LevelPlayInitializer.InitSucceeded -= CreateAd;
            if (_ad != null) return;
            _ad = new LevelPlayRewardedAd(config.RewardedAdUnitId);
            _ad.OnAdLoaded += OnAdLoaded;
            _ad.OnAdLoadFailed += OnAdLoadFailed;
            _ad.OnAdDisplayed += OnAdDisplayed;
            _ad.OnAdDisplayFailed += OnAdDisplayFailed;
            _ad.OnAdRewarded += OnAdRewarded;
            _ad.OnAdClosed += OnAdClosed;
            _ad.OnAdClicked += OnAdClicked;
            _ad.OnAdImpressionDataReady += OnImpressionDataReady;
            LoadAd();
        }

        void OnDestroy()
        {
            LevelPlayInitializer.InitSucceeded -= CreateAd;
            if (_ad == null) return;
            _ad.OnAdLoaded -= OnAdLoaded;
            _ad.OnAdLoadFailed -= OnAdLoadFailed;
            _ad.OnAdDisplayed -= OnAdDisplayed;
            _ad.OnAdDisplayFailed -= OnAdDisplayFailed;
            _ad.OnAdRewarded -= OnAdRewarded;
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

        public void Show(string placement, Action onRewarded)
        {
            RefreshReady();
            if (!IsReady)
            {
                Debug.LogWarning("[FF] Rewarded ad is not ready.");
                return;
            }
            string name = config.useDashboardPlacements ? placement : null;
            if (name != null && LevelPlayRewardedAd.IsPlacementCapped(name))
            {
                Debug.LogWarning($"[FF] Rewarded placement '{name}' is capped.");
                return;
            }
            _pendingReward = onRewarded;
            _rewardEarned = false;
            Debug.Log($"[FF] Showing rewarded ad ({placement}).");
            AdClock.Begin();
            _ad.ShowAd(name);
        }

        // OnAdRewarded / OnAdClosed may arrive in either order: the reward is handed out on the next frame
        void Update()
        {
            if (!_rewardEarned) return;
            _rewardEarned = false;
            Action reward = _pendingReward;
            _pendingReward = null;
            reward?.Invoke();
        }

        void OnAdLoaded(LevelPlayAdInfo info)
        {
            RefreshReady();
            Debug.Log($"[FF] Rewarded ad loaded ({info.AdNetwork}).");
        }

        void OnAdLoadFailed(LevelPlayAdError error)
        {
            Debug.LogWarning($"[FF] Rewarded ad failed to load: {error.ErrorMessage}; retry in {RetrySeconds} s.");
            CancelInvoke(nameof(LoadAd));
            Invoke(nameof(LoadAd), RetrySeconds);
        }

        void OnAdDisplayed(LevelPlayAdInfo info)
        {
            RefreshReady();
            Debug.Log("[FF] Rewarded ad displayed.");
        }

        void OnAdDisplayFailed(LevelPlayAdInfo info, LevelPlayAdError error)
        {
            Debug.LogWarning($"[FF] Rewarded ad failed to display: {error.ErrorMessage}");
            AdClock.End(Time.realtimeSinceStartup);
            _pendingReward = null;
            RefreshReady();
            LoadAd();
        }

        void OnAdRewarded(LevelPlayAdInfo info, LevelPlayReward reward)
        {
            Debug.Log($"[FF] Rewarded: {reward.Amount} {reward.Name}");
            _rewardEarned = true;
        }

        void OnAdClosed(LevelPlayAdInfo info)
        {
            Debug.Log("[FF] Rewarded ad closed.");
            AdClock.End(Time.realtimeSinceStartup);
            if (!_rewardEarned) Invoke(nameof(DropUnearned), 1f); // the reward event can trail the close a little
            RefreshReady();
            LoadAd();
        }

        void DropUnearned()
        {
            if (!_rewardEarned) _pendingReward = null;
        }

        void OnAdClicked(LevelPlayAdInfo info) => Debug.Log("[FF] Rewarded ad clicked.");

        // ILRD: runs on a background thread — logging only, no Unity objects
        void OnImpressionDataReady(LevelPlayImpressionData data)
        {
            if (data == null) return;
            Debug.Log($"[FF] ILRD {data.AdNetwork} / {data.AdFormat} / ${data.Revenue}");
        }
    }
}
