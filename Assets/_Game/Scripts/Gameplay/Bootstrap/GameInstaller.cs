using FF.Core;
using FF.Data;
using FF.Gameplay.Delivery;
using FF.Gameplay.Effects;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Pads;
using FF.Gameplay.Progress;
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
        [SerializeField] PadSystem pads;
        [SerializeField] EffectsSystem effects;

        void Awake()
        {
            AppSettings.Apply();
            GameEvents.Reset();
            Services.Clear();

            WorldStateSnapshot state = WorldStateSnapshot.NewGame(database.products);
            Services.Register(database);
            var progress = new GameProgress(database.economy);
            Services.Register(progress);
            Services.Register<IUpgradeLevels>(progress);
            Services.Register<IProgressView>(progress);
            Services.Register<IWallet>(progress);
            Services.Register<IUpgradeShop>(new UpgradeShop(database, progress, state));
            Services.Register<IDevCheats>(new DevCheats(progress));
            Services.Register(state);
            var collision = new WorldCollision(database, state);
            Services.Register(collision);
            Services.Register(new Ownership(state, collision, database.products));
            Services.Register(new WorldTagRegistry());
            Services.Register(new GameMode());
            Services.Register(new GameSettings(new PlayerPrefsSettingsStore(),
                Application.isEditor ? QualityTier.High : QualityRules.DefaultTier(SystemInfo.systemMemorySize, SystemInfo.processorCount)));
            Services.Register(new DeliveryCargo());
            Services.Register(itemPool);
            Services.Register(itemFlights);
            Services.Register(zones);
            Services.Register(nodes);
            Services.Register(pads);
            Services.Register(effects);
        }

        void OnDestroy()
        {
            Services.Clear();
            GameEvents.Reset();
        }
    }
}
