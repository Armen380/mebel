using System.Collections;
using FF.Core;
using UnityEngine;
using UnityEngine.Localization.Settings;
using UnityEngine.SceneManagement;

namespace FF.Gameplay.Bootstrap
{
    /// <summary>Boot scene entry point: applies app settings, waits for localization, then loads the game scene.</summary>
    public sealed class BootLoader : MonoBehaviour
    {
        IEnumerator Start()
        {
            AppSettings.Apply();
            yield return LocalizationSettings.InitializationOperation;
            SceneManager.LoadScene(AppSettings.GameScene);
        }
    }
}
