using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
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
        [SerializeField] ItemPool itemPool;
        [SerializeField] ItemFlights itemFlights;
        [SerializeField] ZoneRegistry zones;
        [SerializeField] NodeRegistry nodes;

        void Awake()
        {
            AppSettings.Apply();
            GameEvents.Reset();
            Services.Clear();

            WorldStateSnapshot state = WorldStateSnapshot.NewGame(database.products);
            Services.Register(database);
            Services.Register<IUpgradeLevels>(new NewGameUpgradeLevels());
            Services.Register(state);
            Services.Register(new WorldCollision(database, state));
            Services.Register(new WorldTagRegistry());
            Services.Register(itemPool);
            Services.Register(itemFlights);
            Services.Register(zones);
            Services.Register(nodes);
        }

        void OnDestroy()
        {
            Services.Clear();
            GameEvents.Reset();
        }
    }
}
