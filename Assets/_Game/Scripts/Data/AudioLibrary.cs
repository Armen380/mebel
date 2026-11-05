using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    public enum Sfx
    {
        Coin,
        Payout,
        Chop,
        Mine,
        Quest,
        Purchase,
        LevelUp,
        Throw,
        CarDoor,
        DoorBell,
        Click,
        TruckPass,
    }

    /// <summary>Every sound of the game with its volume, pitch jitter and repeat cooldown; built by FF/Build Audio Library.</summary>
    [CreateAssetMenu(menuName = "FF/Audio Library", fileName = "AudioLibrary")]
    public sealed class AudioLibrary : ScriptableObject
    {
        [Serializable]
        public sealed class Entry
        {
            public Sfx id;
            [Tooltip("Variants; one is picked at random.")]
            public AudioClip[] clips = Array.Empty<AudioClip>();
            [Range(0f, 1f)] public float volume = 0.7f;
            [Tooltip("Random pitch ± this.")]
            public float pitchJitter = 0.04f;
            [Tooltip("Skip a repeat within this many seconds (prototype coin: 50 ms).")]
            public float cooldown = 0.05f;
        }

        public List<Entry> entries = new List<Entry>();
        public AudioClip music;
        [Range(0f, 1f)] public float musicVolume = 0.35f;
        public AudioClip ambient;
        [Range(0f, 1f)] public float ambientVolume = 0.25f;

        public Entry Find(Sfx id)
        {
            foreach (Entry e in entries)
                if (e.id == id) return e;
            return null;
        }
    }
}
