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

        /// <summary>The player's axe hit a node (every 0.3 s while chopping), true for a rock — chop SFX / haptics hook.</summary>
        public static event Action<bool> ChopHit;
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
        /// <summary>Centre toast with an already localized title and subtitle (prototype <c>toast</c>).</summary>
        public static event Action<string, string> Toast;
        /// <summary>An Upgrades-panel item was bought: id and its new level.</summary>
        public static event Action<string, int> UpgradeBought;
        /// <summary>Something worth saving changed that has no event of its own (e.g. an unlock card was marked seen).</summary>
        public static event Action ProgressChanged;
        /// <summary>An unlock card appears: icon id, title, subtitle (prototype <c>updUnlock</c>).</summary>
        public static event Action<string, string, string> UnlockCardShown;
        public static event Action UnlockCardHidden;
        /// <summary>A delivery truck left the world with its order: payout already added (HUD pop next to the balance).</summary>
        public static event Action<long> TruckDelivered;
        /// <summary>A world or UI sound with no event of its own (car doors, the shop bell, trucks, clicks).</summary>
        public static event Action<SoundCue> Sound;

        public static void RaiseMoneyChanged(long money, bool bump) => MoneyChanged?.Invoke(money, bump);
        public static void RaiseLevelUp(int level) => LevelUp?.Invoke(level);
        public static void RaisePadCompleted(string padId, int level) => PadCompleted?.Invoke(padId, level);
        public static void RaiseUnlocked(string unlockId) => Unlocked?.Invoke(unlockId);
        public static void RaiseChopHit(bool rock) => ChopHit?.Invoke(rock);
        public static void RaiseChopped() => Chopped?.Invoke();
        public static void RaiseZoneDropped(string zoneId) => ZoneDropped?.Invoke(zoneId);
        public static void RaiseZonePicked(string zoneId) => ZonePicked?.Invoke(zoneId);
        public static void RaiseThrown() => Thrown?.Invoke();
        public static void RaiseCashCollected() => CashCollected?.Invoke();
        public static void RaiseQuestChanged(int step) => QuestChanged?.Invoke(step);
        public static void RaiseFloatText(Vector3 position, string text) => FloatText?.Invoke(position, text);
        public static void RaiseToast(string title, string subtitle) => Toast?.Invoke(title, subtitle);
        public static void RaiseUpgradeBought(string id, int level) => UpgradeBought?.Invoke(id, level);
        public static void RaiseProgressChanged() => ProgressChanged?.Invoke();
        public static void RaiseUnlockCardShown(string icon, string title, string subtitle) => UnlockCardShown?.Invoke(icon, title, subtitle);
        public static void RaiseUnlockCardHidden() => UnlockCardHidden?.Invoke();
        public static void RaiseTruckDelivered(long payout) => TruckDelivered?.Invoke(payout);
        public static void RaiseSound(SoundCue cue) => Sound?.Invoke(cue);

        /// <summary>Dream House furnishing or stage changed (M10).</summary>
        public static event Action HomeChanged;
        /// <summary>Show the variant picker for a slot id; null hides it.</summary>
        public static event Action<string> HomeVariantPicker;
        /// <summary>The player arrived at (true) or left (false) the Home Store counter.</summary>
        public static event Action<bool> HomeStoreOpen;
        /// <summary>An area was filled for the first time: area id, gift paid.</summary>
        public static event Action<string, long> HomeAreaCompleted;

        public static void RaiseHomeChanged() => HomeChanged?.Invoke();
        public static void RaiseHomeVariantPicker(string slotId) => HomeVariantPicker?.Invoke(slotId);
        public static void RaiseHomeStoreOpen(bool open) => HomeStoreOpen?.Invoke(open);
        public static void RaiseHomeAreaCompleted(string areaId, long gift) => HomeAreaCompleted?.Invoke(areaId, gift);

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
            Toast = null;
            UpgradeBought = null;
            ProgressChanged = null;
            UnlockCardShown = null;
            UnlockCardHidden = null;
            Sound = null;
            TruckDelivered = null;
            HomeChanged = null;
            HomeVariantPicker = null;
            HomeStoreOpen = null;
            HomeAreaCompleted = null;
        }
    }

    /// <summary>Sounds raised through <see cref="GameEvents.Sound"/>.</summary>
    public enum SoundCue
    {
        Click,
        CarDoor,
        DoorBell,
        TruckPass,
    }
}
