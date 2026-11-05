using System;
using UnityEngine;

namespace FF.Core
{
    /// <summary>Rewarded video ads (M9, user decision: rewarded only, always user-initiated).</summary>
    public interface IRewardedAds
    {
        /// <summary>An ad is loaded and can be shown now.</summary>
        bool IsReady { get; }
        /// <summary>Shows an ad; <paramref name="onRewarded"/> runs on the main thread once the user earned the reward.</summary>
        void Show(string placement, Action onRewarded);
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
