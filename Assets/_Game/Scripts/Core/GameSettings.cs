using System;
using UnityEngine;

namespace FF.Core
{
    public enum QualityTier
    {
        Low,
        Medium,
        High,
    }

    /// <summary>Where device settings live (PlayerPrefs in the game, a dictionary in tests).</summary>
    public interface ISettingsStore
    {
        bool Has(string key);
        int Get(string key, int fallback);
        void Set(string key, int value);
        void Save();
    }

    public sealed class PlayerPrefsSettingsStore : ISettingsStore
    {
        public bool Has(string key) => PlayerPrefs.HasKey(key);
        public int Get(string key, int fallback) => PlayerPrefs.GetInt(key, fallback);
        public void Set(string key, int value) => PlayerPrefs.SetInt(key, value);
        public void Save() => PlayerPrefs.Save();
    }

    /// <summary>
    /// Menu settings, per device (not in the game save): sound, music, vibration and the graphics tier. The first launch
    /// picks the tier from the device (<see cref="QualityRules.DefaultTier"/>).
    /// </summary>
    public sealed class GameSettings
    {
        const string SoundKey = "ff.sound", MusicKey = "ff.music", VibrationKey = "ff.vibration", QualityKey = "ff.quality";

        readonly ISettingsStore _store;

        public bool Sound { get; private set; }
        public bool Music { get; private set; }
        public bool Vibration { get; private set; }
        public QualityTier Quality { get; private set; }

        /// <summary>Raised after any change.</summary>
        public event Action Changed;

        public GameSettings(ISettingsStore store, QualityTier deviceDefault)
        {
            _store = store;
            Sound = store.Get(SoundKey, 1) != 0;
            Music = store.Get(MusicKey, 1) != 0;
            Vibration = store.Get(VibrationKey, 1) != 0;
            int q = store.Has(QualityKey) ? store.Get(QualityKey, (int)deviceDefault) : (int)deviceDefault;
            Quality = q >= (int)QualityTier.Low && q <= (int)QualityTier.High ? (QualityTier)q : deviceDefault;
        }

        public void SetSound(bool on)
        {
            if (Sound == on) return;
            Sound = on;
            Write(SoundKey, on ? 1 : 0);
        }

        public void SetMusic(bool on)
        {
            if (Music == on) return;
            Music = on;
            Write(MusicKey, on ? 1 : 0);
        }

        public void SetVibration(bool on)
        {
            if (Vibration == on) return;
            Vibration = on;
            Write(VibrationKey, on ? 1 : 0);
        }

        public void SetQuality(QualityTier tier)
        {
            if (Quality == tier) return;
            Quality = tier;
            Write(QualityKey, (int)tier);
        }

        void Write(string key, int value)
        {
            _store.Set(key, value);
            _store.Save();
            Changed?.Invoke();
        }
    }

    public static class QualityRules
    {
        /// <summary>
        /// Default graphics tier for a device: little RAM or few cores → Low (no shadows, lower resolution), mid-range →
        /// Medium, the rest → High.
        /// </summary>
        public static QualityTier DefaultTier(int systemMemoryMb, int processorCount)
        {
            if (systemMemoryMb > 0 && systemMemoryMb < 3500) return QualityTier.Low;
            if (processorCount > 0 && processorCount < 6) return QualityTier.Low;
            if (systemMemoryMb > 0 && systemMemoryMb < 6500) return QualityTier.Medium;
            return QualityTier.High;
        }

        /// <summary>Quality level names in the project settings, in tier order.</summary>
        public static readonly string[] LevelNames = { "Low", "Medium", "High" };
    }
}
