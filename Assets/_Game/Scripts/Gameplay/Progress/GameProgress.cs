using System.Collections.Generic;
using FF.Core;
using FF.Data;

namespace FF.Gameplay.Progress
{
    /// <summary>
    /// The prototype's save state <c>S</c> that M3 needs: money, total earned, XP, level, tutorial step and pad
    /// states. Also the <see cref="IUpgradeLevels"/> source (pad levels by pad id; panel upgrades by upgrade id).
    /// Plain C#; the save system (M5) serializes it.
    /// </summary>
    public sealed class GameProgress : IUpgradeLevels, IProgressView
    {
        public sealed class PadState
        {
            public int Level;
            public long Paid;
        }

        readonly EconomyConfig _economy;
        readonly Dictionary<string, PadState> _pads = new Dictionary<string, PadState>();
        readonly Dictionary<string, int> _upgrades = new Dictionary<string, int>();

        public long Money { get; private set; }
        public long TotalEarned { get; private set; }
        public int Xp { get; private set; }
        public int Level { get; private set; } = 1;
        public int QuestStep { get; private set; }
        public int XpNeeded => _economy.XpNeeded(Level);

        public GameProgress(EconomyConfig economy) => _economy = economy;

        /// <summary>Prototype <c>addMoney(v, quiet)</c>.</summary>
        public void AddMoney(long amount, bool bump = true)
        {
            Money += amount;
            TotalEarned += amount;
            GameEvents.RaiseMoneyChanged(Money, bump);
        }

        /// <summary>Takes money for a payment (pads, upgrades); never below zero.</summary>
        public bool Spend(long amount)
        {
            if (amount <= 0 || amount > Money) return false;
            Money -= amount;
            GameEvents.RaiseMoneyChanged(Money, false);
            return true;
        }

        /// <summary>Prototype <c>addXP</c>: may raise several levels at once; LevelUp fires for each.</summary>
        public void AddXp(int amount)
        {
            int xp = Xp, level = Level;
            int gained = LevelMath.AddXp(ref xp, ref level, amount, _economy);
            Xp = xp;
            for (int i = 0; i < gained; i++)
            {
                Level++;
                GameEvents.RaiseLevelUp(Level);
            }
        }

        public void AdvanceQuest()
        {
            QuestStep++;
            GameEvents.RaiseQuestChanged(QuestStep);
        }

        public PadState Pad(string padId)
        {
            if (!_pads.TryGetValue(padId, out PadState state))
            {
                state = new PadState();
                _pads.Add(padId, state);
            }
            return state;
        }

        public int GetLevel(string id)
        {
            if (_pads.TryGetValue(id, out PadState pad)) return pad.Level;
            return _upgrades.TryGetValue(id, out int level) ? level : 0;
        }

        /// <summary>Upgrades-panel levels (M4); tests and tools.</summary>
        public void SetUpgradeLevel(string upgradeId, int level) => _upgrades[upgradeId] = level;
    }

    public static class LevelMath
    {
        /// <summary>Adds XP and returns how many levels were gained; xp keeps the remainder (prototype <c>addXP</c>).</summary>
        public static int AddXp(ref int xp, ref int level, int amount, EconomyConfig economy)
        {
            xp += amount;
            int gained = 0;
            while (xp >= economy.XpNeeded(level))
            {
                xp -= economy.XpNeeded(level);
                level++;
                gained++;
            }
            return gained;
        }
    }
}
