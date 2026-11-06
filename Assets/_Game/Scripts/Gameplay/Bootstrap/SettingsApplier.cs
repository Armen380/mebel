using FF.Core;
using UnityEngine;

namespace FF.Gameplay.Bootstrap
{
    /// <summary>Applies the graphics tier as the project's quality level (each level has its own URP asset).</summary>
    public sealed class SettingsApplier : MonoBehaviour
    {
        GameSettings _settings;

        void Start()
        {
            _settings = Services.Get<GameSettings>();
            _settings.Changed += Apply;
            Apply();
        }

        void OnDestroy()
        {
            if (_settings != null) _settings.Changed -= Apply;
        }

        void Apply()
        {
            int level = System.Array.IndexOf(QualitySettings.names, QualityRules.LevelNames[(int)_settings.Quality]);
            if (level >= 0 && level != QualitySettings.GetQualityLevel()) QualitySettings.SetQualityLevel(level, true);
            // the frame rate belongs to MenuPause (30 in the menu, 60 in play)
        }
    }
}
