using FF.Core;
using UnityEngine;

namespace FF.Gameplay.Bootstrap
{
    /// <summary>
    /// The menu pauses the simulation (prototype frame loop runs workers, machines, customers, cars, trucks, pads and
    /// autosave only in play): time scale 0 in the menu, 1 in play. The player's animation and the menu camera use real time.
    /// </summary>
    public sealed class MenuPause : MonoBehaviour
    {
        GameMode _mode;

        void Start()
        {
            _mode = Services.Get<GameMode>();
            _mode.Changed += Apply;
            Apply(_mode.InMenu);
        }

        void OnDestroy()
        {
            if (_mode != null) _mode.Changed -= Apply;
            Time.timeScale = 1f;
        }

        static void Apply(bool inMenu) => Time.timeScale = inMenu ? 0f : 1f;
    }
}
