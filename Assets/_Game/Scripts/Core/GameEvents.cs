using System;
using UnityEngine;

namespace FF.Core
{
    /// <summary>
    /// Small static event hub so systems do not reference each other directly.
    /// Raise through the methods; subscribers must unsubscribe in OnDisable/OnDestroy.
    /// </summary>
    public static class GameEvents
    {
        /// <summary>New balance; <c>bump</c> = an audible/visible gain (prototype addMoney without quiet).</summary>
        public static event Action<long, bool> MoneyChanged;
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
        /// <summary>The player collected a bill at a register (prototype <c>emit('cash')</c>).</summary>
        public static event Action CashCollected;
        /// <summary>The tutorial moved to step index (prototype <c>S.quest</c>); equals the step count when finished.</summary>
        public static event Action<int> QuestChanged;
        /// <summary>Floating world text such as "+$430" (prototype <c>floatText</c>).</summary>
        public static event Action<Vector3, string> FloatText;

        public static void RaiseMoneyChanged(long money, bool bump) => MoneyChanged?.Invoke(money, bump);
        public static void RaiseLevelUp(int level) => LevelUp?.Invoke(level);
        public static void RaisePadCompleted(string padId, int level) => PadCompleted?.Invoke(padId, level);
        public static void RaiseUnlocked(string unlockId) => Unlocked?.Invoke(unlockId);
        public static void RaiseChopHit() => ChopHit?.Invoke();
        public static void RaiseChopped() => Chopped?.Invoke();
        public static void RaiseZoneDropped(string zoneId) => ZoneDropped?.Invoke(zoneId);
        public static void RaiseZonePicked(string zoneId) => ZonePicked?.Invoke(zoneId);
        public static void RaiseThrown() => Thrown?.Invoke();
        public static void RaiseCashCollected() => CashCollected?.Invoke();
        public static void RaiseQuestChanged(int step) => QuestChanged?.Invoke(step);
        public static void RaiseFloatText(Vector3 position, string text) => FloatText?.Invoke(position, text);

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
            CashCollected = null;
            QuestChanged = null;
            FloatText = null;
        }
    }
}
