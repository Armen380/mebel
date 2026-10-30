using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Bootstrap
{
    /// <summary>
    /// Composition root of the game scene: registers services before any other script runs.
    /// Also works when Play is pressed in the game scene directly (without Boot).
    /// </summary>
    [DefaultExecutionOrder(-1000)]
    public sealed class GameInstaller : MonoBehaviour
    {
        [SerializeField] GameDatabase database;

        void Awake()
        {
            AppSettings.Apply();
            GameEvents.Reset();
            Services.Clear();
            Services.Register(database);
        }

        void OnDestroy()
        {
            Services.Clear();
            GameEvents.Reset();
        }
    }
}
