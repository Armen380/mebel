using FF.Core;
using UnityEngine;
#if UNITY_IOS && !UNITY_EDITOR
using System.Runtime.InteropServices;
#endif

namespace FF.Gameplay.Audio
{
    /// <summary>
    /// Haptic feedback (05_ART_UI_AUDIO): a light tap on pickup batches (items into the hands, cash collected, a node
    /// felled; at most every 0.25 s), a medium one on purchases and level-ups. Off in settings, in the menu and in the Editor.
    /// Android: one-shot vibration with amplitude (API 26+); iOS: UIImpactFeedbackGenerator (Plugins/iOS/FFHaptics.mm).
    /// </summary>
    public sealed class Haptics : MonoBehaviour
    {
        const float LightInterval = 0.25f;

        GameSettings _settings;
        GameMode _mode;
        float _lastLight = -10f;
#if UNITY_ANDROID && !UNITY_EDITOR
        AndroidJavaObject _vibrator;
        AndroidJavaClass _effects;
#endif

        void Start()
        {
            _settings = Services.Get<GameSettings>();
            _mode = Services.Get<GameMode>();
#if UNITY_ANDROID && !UNITY_EDITOR
            try
            {
                using var player = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
                using AndroidJavaObject activity = player.GetStatic<AndroidJavaObject>("currentActivity");
                _vibrator = activity.Call<AndroidJavaObject>("getSystemService", "vibrator");
                _effects = new AndroidJavaClass("android.os.VibrationEffect");
            }
            catch (System.Exception e)
            {
                Debug.LogWarning($"[FF] No vibrator: {e.Message}");
            }
#endif
        }

        void OnEnable()
        {
            GameEvents.ZonePicked += OnPicked;
            GameEvents.CashCollected += OnLight;
            GameEvents.Chopped += OnLight;
            GameEvents.PadCompleted += OnPurchase;
            GameEvents.UpgradeBought += OnPurchase;
            GameEvents.LevelUp += OnLevelUp;
        }

        void OnDisable()
        {
            GameEvents.ZonePicked -= OnPicked;
            GameEvents.CashCollected -= OnLight;
            GameEvents.Chopped -= OnLight;
            GameEvents.PadCompleted -= OnPurchase;
            GameEvents.UpgradeBought -= OnPurchase;
            GameEvents.LevelUp -= OnLevelUp;
        }

        void OnPicked(string zone) => OnLight();
        void OnPurchase(string id, int level) => Tap(false);
        void OnLevelUp(int level) => Tap(false);

        void OnLight()
        {
            if (Time.unscaledTime - _lastLight < LightInterval) return;
            _lastLight = Time.unscaledTime;
            Tap(true);
        }

        void Tap(bool light)
        {
            if (_settings == null || !_settings.Vibration || _mode.InMenu) return;
#if UNITY_ANDROID && !UNITY_EDITOR
            if (_vibrator == null) return;
            try
            {
                using AndroidJavaObject effect = _effects.CallStatic<AndroidJavaObject>("createOneShot", light ? 12L : 28L, light ? 60 : 160);
                _vibrator.Call("vibrate", effect);
            }
            catch (System.Exception)
            {
                Handheld.Vibrate(); // also makes the build add the VIBRATE permission
            }
#elif UNITY_IOS && !UNITY_EDITOR
            FFHapticImpact(light ? 0 : 1);
#endif
        }

#if UNITY_IOS && !UNITY_EDITOR
        [DllImport("__Internal")]
        static extern void FFHapticImpact(int style);
#endif
    }
}
