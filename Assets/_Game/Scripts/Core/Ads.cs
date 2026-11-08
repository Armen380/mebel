using System;
using UnityEngine;

namespace FF.Core
{
    /// <summary>Rewarded video ads (M9): always user-initiated, from the centered offer popup.</summary>
    public interface IRewardedAds
    {
        /// <summary>An ad is loaded and can be shown now.</summary>
        bool IsReady { get; }
        /// <summary>Shows an ad; <paramref name="onRewarded"/> runs on the main thread once the user earned the reward.</summary>
        void Show(string placement, Action onRewarded);
    }

    /// <summary>
    /// Full-screen ads without a reward (user decision 2026-11-08): every few levels, see <see cref="InterstitialRules"/>.
    /// </summary>
    public interface IInterstitialAds
    {
        /// <summary>An ad is loaded and can be shown now.</summary>
        bool IsReady { get; }
        /// <summary>Shows an ad; <paramref name="onClosed"/> runs on the main thread once it is gone (also when it failed).</summary>
        void Show(string placement, Action onClosed);
    }

    /// <summary>
    /// When any ad (rewarded or interstitial) is on screen and when the last one ended, in real time — shared by the ad
    /// managers, the interstitial schedule and the offer popup so ads never follow each other too closely.
    /// </summary>
    public static class AdClock
    {
        public static bool Showing { get; private set; }
        public static float LastEndedAt { get; private set; } = float.NegativeInfinity;
        public static event Action<bool> ShowingChanged;

        public static void Begin()
        {
            Showing = true;
            ShowingChanged?.Invoke(true);
        }

        public static void End(float realtime)
        {
            Showing = false;
            LastEndedAt = realtime;
            ShowingChanged?.Invoke(false);
        }

        /// <summary>Tests and a new play session.</summary>
        public static void Reset()
        {
            Showing = false;
            LastEndedAt = float.NegativeInfinity;
            ShowingChanged = null;
        }
    }

    /// <summary>
    /// Interstitial schedule (user decision 2026-11-08): on every Nth level-up (N = 3), never in the menu or the tutorial,
    /// not in the first minute of a session and not within two minutes after any other ad. Times are real seconds.
    /// </summary>
    public static class InterstitialRules
    {
        public static bool IsAdLevel(int level, int every) => every > 0 && level > 0 && level % every == 0;

        public static bool CanShow(int level, int every, bool inMenu, bool tutorialDone, bool adShowing,
            float now, float sessionStart, float sessionDelay, float lastAdEnded, float minGap) =>
            IsAdLevel(level, every) && !inMenu && tutorialDone && !adShowing
            && now - sessionStart >= sessionDelay && now - lastAdEnded >= minGap;
    }

    /// <summary>
    /// The centered rewarded-ad popup (replaces the M9 corner buttons; user decision 2026-11-08): at most one offer per
    /// cooldown (5 min) — "×2 payout" when a truck has just paid, otherwise "bonus cash"; nothing while no ad is ready,
    /// another ad is on screen or the menu is open.
    /// </summary>
    public static class AdOfferRules
    {
        public enum Offer { None, DoublePayout, Cash }

        public static Offer Pick(bool adReady, bool blocked, float now, float nextOfferAt, float doubleUntil)
        {
            if (!adReady || blocked || now < nextOfferAt) return Offer.None;
            return now < doubleUntil ? Offer.DoublePayout : Offer.Cash;
        }
    }

    /// <summary>Adds money from outside the gameplay layer (ad rewards).</summary>
    public interface IWallet
    {
        void AddMoney(long amount, bool bump);
    }

    /// <summary>Rewarded placements of the game (also the LevelPlay dashboard placement names when used).</summary>
    public static class AdPlacements
    {
        public const string DoublePayout = "double_payout";
        public const string InstantCash = "instant_cash";
        public const string LevelUp = "level_up";
    }

    /// <summary>
    /// The player's answer to "personalized ads?" (GDPR consent; also the CCPA opt-out when refused), per device.
    /// Ads are initialized only once it is known.
    /// </summary>
    public static class AdsConsent
    {
        const string Key = "ff.adsConsent";

        public static event Action Changed;

        public static bool Known => PlayerPrefs.HasKey(Key);
        public static bool Personalized => PlayerPrefs.GetInt(Key, 0) == 1;

        public static void Set(bool personalized)
        {
            PlayerPrefs.SetInt(Key, personalized ? 1 : 0);
            PlayerPrefs.Save();
            Changed?.Invoke();
        }
    }

    /// <summary>
    /// Recent income from total-earned samples (every few seconds over a few minutes) for the "instant cash" reward:
    /// two minutes of current income, at least $500, rounded to $10.
    /// </summary>
    public sealed class IncomeMeter
    {
        readonly float[] _times;
        readonly long[] _totals;
        readonly float _interval;
        int _count, _head;
        float _lastSample = float.NegativeInfinity;

        public IncomeMeter(float windowSeconds = 300f, float intervalSeconds = 5f)
        {
            int n = Mathf.Max(2, Mathf.CeilToInt(windowSeconds / intervalSeconds) + 1);
            _times = new float[n];
            _totals = new long[n];
            _interval = intervalSeconds;
        }

        /// <summary>Records the total earned at a time (ignored until the interval has passed).</summary>
        public void Sample(float time, long totalEarned)
        {
            if (time - _lastSample < _interval) return;
            _lastSample = time;
            _times[_head] = time;
            _totals[_head] = totalEarned;
            _head = (_head + 1) % _times.Length;
            if (_count < _times.Length) _count++;
        }

        /// <summary>Money per second over the window (0 until two samples exist).</summary>
        public double PerSecond
        {
            get
            {
                if (_count < 2) return 0;
                int newest = (_head - 1 + _times.Length) % _times.Length;
                int oldest = (_head - _count + _times.Length) % _times.Length;
                float dt = _times[newest] - _times[oldest];
                return dt > 0f ? (_totals[newest] - _totals[oldest]) / (double)dt : 0;
            }
        }

        public const long MinimumReward = 500;
        public const float RewardSeconds = 120f;

        /// <summary>Instant-cash reward: two minutes of income, at least $500, rounded to $10.</summary>
        public long InstantCash() => Math.Max(MinimumReward, (long)Math.Round(PerSecond * RewardSeconds / 10.0) * 10);
    }
}
