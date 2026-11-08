using System.Collections;
using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Ads
{
    /// <summary>
    /// Shows an interstitial on every Nth level-up (user decision 2026-11-08) when <see cref="InterstitialRules"/> allow it:
    /// a moment after the level-up so the player sees it first, and only if an ad is loaded — the game never waits on ads.
    /// </summary>
    public sealed class InterstitialScheduler : MonoBehaviour
    {
        [SerializeField] AdsConfig config;

        IInterstitialAds _ads;
        GameMode _mode;
        IProgressView _progress;
        int _tutorialSteps;
        float _sessionStart;
        bool _pending;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig) => config = adsConfig;

        void Start()
        {
            Services.TryGet(out _ads);
            _mode = Services.Get<GameMode>();
            _progress = Services.Get<IProgressView>();
            _tutorialSteps = Services.Get<GameDatabase>().tutorial.steps.Count;
            _sessionStart = Time.realtimeSinceStartup;
        }

        void OnEnable() => GameEvents.LevelUp += OnLevelUp;

        void OnDisable() => GameEvents.LevelUp -= OnLevelUp;

        bool Allowed(int level) =>
            _ads != null && _mode != null &&
            InterstitialRules.CanShow(level, config.levelsPerInterstitial, _mode.InMenu, _progress.QuestStep >= _tutorialSteps,
                AdClock.Showing, Time.realtimeSinceStartup, _sessionStart, config.interstitialSessionDelay,
                AdClock.LastEndedAt, config.interstitialMinGap);

        void OnLevelUp(int level)
        {
            if (_pending || !Allowed(level)) return;
            StartCoroutine(ShowSoon(level));
        }

        IEnumerator ShowSoon(int level)
        {
            _pending = true;
            yield return new WaitForSecondsRealtime(config.interstitialDelay);
            _pending = false;
            if (Allowed(level) && _ads.IsReady) _ads.Show(AdPlacements.LevelUp, null);
        }
    }
}
