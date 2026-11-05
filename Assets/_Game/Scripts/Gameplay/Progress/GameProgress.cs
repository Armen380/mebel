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
        readonly HashSet<string> _seen = new HashSet<string>();

        public long Money { get; private set; }
        public long TotalEarned { get; private set; }
        /// <summary>Player look (prototype <c>S.skin</c>); validated by the player skin component.</summary>
        public string Skin { get; set; } = "lumber";
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

        /// <summary>Upgrades-panel level (cap, speed, axe, ads, …).</summary>
        public int GetUpgradeLevel(string upgradeId) => _upgrades.TryGetValue(upgradeId, out int level) ? level : 0;

        public void SetUpgradeLevel(string upgradeId, int level) => _upgrades[upgradeId] = level;

        public IReadOnlyDictionary<string, PadState> Pads => _pads;
        public IReadOnlyDictionary<string, int> Upgrades => _upgrades;
        /// <summary>Unlock-card ids already announced (prototype <c>S.seen</c>).</summary>
        public IReadOnlyCollection<string> Seen => _seen;

        public bool IsSeen(string id) => _seen.Contains(id);

        /// <summary>Records an unlock card id; false when it was already seen.</summary>
        public bool MarkSeen(string id)
        {
            if (!_seen.Add(id)) return false;
            GameEvents.RaiseProgressChanged();
            return true;
        }

        /// <summary>Restores the save values (save system only).</summary>
        public void Restore(long money, long totalEarned, int xp, int level, int questStep)
        {
            Money = money;
            TotalEarned = totalEarned;
            Xp = xp;
            Level = level < 1 ? 1 : level;
            QuestStep = questStep < 0 ? 0 : questStep;
        }

        /// <summary>Dev cheat (prototype menu test button): jumps levels without XP; LevelUp fires once for the new level.</summary>
        public void AddLevels(int levels)
        {
            if (levels <= 0) return;
            Level += levels;
            Xp = 0;
            GameEvents.RaiseLevelUp(Level);
        }
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
