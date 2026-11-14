using FF.Core;
using FF.Data;
using FF.Gameplay.Player;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Home Store counter (M10): standing still at the counter once the foundation is built opens the catalog
    /// (<see cref="GameEvents.HomeStoreOpen"/>), once per visit; walking away closes it.
    /// </summary>
    public sealed class HomeStoreCounter : MonoBehaviour
    {
        const float LeaveFactor = 1.4f;

        [SerializeField] PlayerMover player;

        WorldStateSnapshot _state;
        EconomyConfig _economy;
        bool _visited;

        /// <summary>Editor tools only.</summary>
        public void Setup(PlayerMover playerMover) => player = playerMover;

        void Start()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _economy = Services.Get<GameDatabase>().economy;
        }

        void LateUpdate()
        {
            float d = Zones.ZoneRegistry.Distance(player.transform.position, transform.position);
            if (!_visited)
            {
                if (_state.HouseStage < 1 || d >= _economy.padRadius || player.StillTime < _economy.padStillSeconds) return;
                _visited = true;
                GameEvents.RaiseHomeStoreOpen(true);
            }
            else if (d >= _economy.padRadius * LeaveFactor)
            {
                _visited = false;
                GameEvents.RaiseHomeStoreOpen(false);
            }
        }
    }
}
