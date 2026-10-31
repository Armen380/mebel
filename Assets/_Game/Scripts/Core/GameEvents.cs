using System;

namespace FF.Core
{
    /// <summary>
    /// Small static event hub so systems do not reference each other directly.
    /// Raise through the methods; subscribers must unsubscribe in OnDisable/OnDestroy.
    /// </summary>
    public static class GameEvents
    {
        public static event Action<long> MoneyChanged;
        public static event Action<int> LevelUp;
        public static event Action<string, int> PadCompleted;
        public static event Action<string> Unlocked;

        /// <summary>The player's axe hit a node (every 0.3 s while chopping) — chop SFX / haptics hook.</summary>
        public static event Action ChopHit;
        /// <summary>The player felled a node (prototype <c>emit('chop')</c>).</summary>
        public static event Action Chopped;
        /// <summary>The player put one item into a zone (prototype <c>emit('drop', zoneId)</c>).</summary>
        public static event Action<string> ZoneDropped;
        /// <summary>The player took one item from a zone (prototype <c>emit('pick', zoneId)</c>).</summary>
        public static event Action<string> ZonePicked;
        /// <summary>The player threw away everything carried — throw SFX hook.</summary>
        public static event Action Thrown;

        public static void RaiseMoneyChanged(long money) => MoneyChanged?.Invoke(money);
        public static void RaiseLevelUp(int level) => LevelUp?.Invoke(level);
        public static void RaisePadCompleted(string padId, int level) => PadCompleted?.Invoke(padId, level);
        public static void RaiseUnlocked(string unlockId) => Unlocked?.Invoke(unlockId);
        public static void RaiseChopHit() => ChopHit?.Invoke();
        public static void RaiseChopped() => Chopped?.Invoke();
        public static void RaiseZoneDropped(string zoneId) => ZoneDropped?.Invoke(zoneId);
        public static void RaiseZonePicked(string zoneId) => ZonePicked?.Invoke(zoneId);
        public static void RaiseThrown() => Thrown?.Invoke();

        /// <summary>Drops all subscribers (domain-reload-free Play Mode and tests).</summary>
        public static void Reset()
        {
            MoneyChanged = null;
            LevelUp = null;
            PadCompleted = null;
            Unlocked = null;
            ChopHit = null;
            Chopped = null;
            ZoneDropped = null;
            ZonePicked = null;
            Thrown = null;
        }
    }
}
