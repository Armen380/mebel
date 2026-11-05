using System;

namespace FF.Core
{
    /// <summary>
    /// Prototype <c>mode</c>: the game opens in the menu (also the pause screen) and switches to play with Play / Continue.
    /// While the menu is open the simulation is paused, the HUD and the joystick are hidden and the camera orbits the player.
    /// </summary>
    public sealed class GameMode
    {
        public bool InMenu { get; private set; } = true;
        /// <summary>Play was pressed at least once this session (the menu then says "Continue").</summary>
        public bool Started { get; private set; }

        /// <summary>Raised with <see cref="InMenu"/> after every switch.</summary>
        public event Action<bool> Changed;

        public void OpenMenu()
        {
            if (InMenu) return;
            InMenu = true;
            Changed?.Invoke(true);
        }

        public void Play()
        {
            if (!InMenu) return;
            InMenu = false;
            Started = true;
            Changed?.Invoke(false);
        }
    }
}
