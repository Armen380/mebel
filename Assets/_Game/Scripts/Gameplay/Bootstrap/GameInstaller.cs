using FF.Core;
using FF.Data;
using FF.Gameplay.World;
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
            Services.Register<IUpgradeLevels>(new NewGameUpgradeLevels());
            Services.Register(new WorldCollision(database, WorldStateSnapshot.NewGame(database.products)));
        }

        void OnDestroy()
        {
            Services.Clear();
            GameEvents.Reset();
        }
    }
}
