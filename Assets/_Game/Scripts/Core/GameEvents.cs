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

        public static void RaiseMoneyChanged(long money) => MoneyChanged?.Invoke(money);
        public static void RaiseLevelUp(int level) => LevelUp?.Invoke(level);
        public static void RaisePadCompleted(string padId, int level) => PadCompleted?.Invoke(padId, level);
        public static void RaiseUnlocked(string unlockId) => Unlocked?.Invoke(unlockId);

        /// <summary>Drops all subscribers (domain-reload-free Play Mode and tests).</summary>
        public static void Reset()
        {
            MoneyChanged = null;
            LevelUp = null;
            PadCompleted = null;
            Unlocked = null;
        }
    }
}
