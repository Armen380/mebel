using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Audio
{
    /// <summary>
    /// All game audio, driven by <see cref="GameEvents"/> (gameplay code has no audio calls): pooled 2D one-shots with
    /// per-sound cooldowns (prototype <c>sfx(k)</c>, coin at most every 50 ms), a music loop and an ambient loop. Settings:
    /// Sound mutes effects and ambience, Music mutes the music. Effects other than clicks stay quiet while the menu is open.
    /// </summary>
    public sealed class AudioService : MonoBehaviour
    {
        const int Voices = 8;

        [SerializeField] AudioLibrary library;

        readonly AudioSource[] _voices = new AudioSource[Voices];
        float[] _lastPlayed;
        AudioSource _music, _ambient;
        GameSettings _settings;
        GameMode _mode;
        long _money = -1;
        int _next;
        AudioClip _truck;

        /// <summary>Editor tools only.</summary>
        public void Setup(AudioLibrary audioLibrary) => library = audioLibrary;

        void Awake()
        {
            _lastPlayed = new float[System.Enum.GetValues(typeof(Sfx)).Length];
            for (int i = 0; i < _lastPlayed.Length; i++) _lastPlayed[i] = -10f;
            for (int i = 0; i < Voices; i++) _voices[i] = Source(false);
            _music = Source(true);
            _ambient = Source(true);
            _truck = EngineSynth.TruckPass();
        }

        AudioSource Source(bool loop)
        {
            var s = gameObject.AddComponent<AudioSource>();
            s.playOnAwake = false;
            s.loop = loop;
            s.spatialBlend = 0f;
            s.ignoreListenerPause = true;
            return s;
        }

        void Start()
        {
            _settings = Services.Get<GameSettings>();
            _mode = Services.Get<GameMode>();
            _settings.Changed += ApplyLoops;
            _music.clip = library.music;
            _ambient.clip = library.ambient;
            ApplyLoops();
        }

        void OnDestroy()
        {
            if (_settings != null) _settings.Changed -= ApplyLoops;
        }

        void OnEnable()
        {
            GameEvents.MoneyChanged += OnMoney;
            GameEvents.ChopHit += OnChopHit;
            GameEvents.QuestChanged += OnQuest;
            GameEvents.PadCompleted += OnPurchase;
            GameEvents.UpgradeBought += OnPurchase;
            GameEvents.LevelUp += OnLevelUp;
            GameEvents.Thrown += OnThrown;
            GameEvents.TruckDelivered += OnTruckDelivered;
            GameEvents.Sound += OnSound;
        }

        void OnDisable()
        {
            GameEvents.MoneyChanged -= OnMoney;
            GameEvents.ChopHit -= OnChopHit;
            GameEvents.QuestChanged -= OnQuest;
            GameEvents.PadCompleted -= OnPurchase;
            GameEvents.UpgradeBought -= OnPurchase;
            GameEvents.LevelUp -= OnLevelUp;
            GameEvents.Thrown -= OnThrown;
            GameEvents.TruckDelivered -= OnTruckDelivered;
            GameEvents.Sound -= OnSound;
        }

        void ApplyLoops()
        {
            Loop(_music, _settings.Music, library.musicVolume);
            Loop(_ambient, _settings.Sound, library.ambientVolume);
        }

        static void Loop(AudioSource s, bool on, float volume)
        {
            s.volume = volume;
            if (s.clip == null) return;
            if (on && !s.isPlaying) s.Play();
            else if (!on && s.isPlaying) s.Stop();
        }

        // prototype addMoney: a coin unless the sale was far away (quiet)
        void OnMoney(long money, bool bump)
        {
            bool gained = _money >= 0 && money > _money;
            _money = money;
            if (gained && bump) Play(Sfx.Coin);
        }

        void OnChopHit(bool rock) => Play(rock ? Sfx.Mine : Sfx.Chop);
        void OnQuest(int step) => Play(Sfx.Quest);
        void OnPurchase(string id, int level) => Play(Sfx.Purchase);
        void OnLevelUp(int level) => Play(Sfx.LevelUp);
        void OnThrown() => Play(Sfx.Throw);
        void OnTruckDelivered(long payout) => Play(Sfx.Payout);

        void OnSound(SoundCue cue)
        {
            switch (cue)
            {
                case SoundCue.Click: Play(Sfx.Click); break;
                case SoundCue.CarDoor: Play(Sfx.CarDoor); break;
                case SoundCue.DoorBell: Play(Sfx.DoorBell); break;
                case SoundCue.TruckPass: Play(Sfx.TruckPass); break;
            }
        }

        public void Play(Sfx id)
        {
            if (_settings == null || !_settings.Sound) return;
            if (_mode.InMenu && id != Sfx.Click) return;
            AudioLibrary.Entry e = library.Find(id);
            AudioClip clip = id == Sfx.TruckPass ? _truck : null;
            if (e == null && clip == null) return;
            float now = Time.unscaledTime;
            float cooldown = e != null ? e.cooldown : 1f;
            if (now - _lastPlayed[(int)id] < cooldown) return;
            if (clip == null)
            {
                if (e.clips.Length == 0) return;
                clip = e.clips[Random.Range(0, e.clips.Length)];
            }
            _lastPlayed[(int)id] = now;
            AudioSource v = _voices[_next];
            _next = (_next + 1) % Voices;
            v.pitch = 1f + (e != null ? Random.Range(-e.pitchJitter, e.pitchJitter) : 0f);
            v.PlayOneShot(clip, e != null ? e.volume : 0.35f);
        }
    }

    /// <summary>The truck engine pass, made in code: a low two-tone hum that swells and fades with a slight pitch drop.</summary>
    public static class EngineSynth
    {
        public static AudioClip TruckPass(int sampleRate = 22050, float seconds = 2.6f)
        {
            int n = Mathf.RoundToInt(sampleRate * seconds);
            var data = new float[n];
            float phase1 = 0f, phase2 = 0f;
            var rng = new System.Random(7);
            float noise = 0f;
            for (int i = 0; i < n; i++)
            {
                float t = (float)i / n;
                float f = Mathf.Lerp(78f, 62f, t); // doppler-ish drop
                phase1 += 2f * Mathf.PI * f / sampleRate;
                phase2 += 2f * Mathf.PI * f * 2.02f / sampleRate;
                noise = Mathf.Lerp(noise, (float)rng.NextDouble() * 2f - 1f, 0.08f);
                float hum = Mathf.Sin(phase1) * 0.6f + Mathf.Sin(phase2) * 0.25f + noise * 0.35f;
                float envelope = Mathf.Sin(Mathf.PI * t); // swell and fade
                data[i] = hum * envelope * envelope * 0.5f;
            }
            AudioClip clip = AudioClip.Create("TruckPass", n, 1, sampleRate, false);
            clip.SetData(data, 0);
            return clip;
        }
    }
}
