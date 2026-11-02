using System.Collections.Generic;
using FF.Gameplay.Progress;
using FF.Gameplay.World;

namespace FF.Save
{
    /// <summary>Copies the live game state into a <see cref="SaveData"/> and back.</summary>
    public static class SaveMapper
    {
        public static SaveData Capture(GameProgress progress, WorldStateSnapshot state, string language)
        {
            var data = new SaveData
            {
                money = progress.Money,
                total = progress.TotalEarned,
                xp = progress.Xp,
                level = progress.Level,
                quest = progress.QuestStep,
                lang = language,
            };
            foreach (KeyValuePair<string, int> u in progress.Upgrades) data.lv[u.Key] = u.Value;
            foreach (KeyValuePair<string, GameProgress.PadState> p in progress.Pads)
                if (p.Value.Level > 0 || p.Value.Paid > 0)
                    data.pads[p.Key] = new PadSave { lv = p.Value.Level, paid = p.Value.Paid };
            foreach (string id in state.OwnedProducts) data.owned[id] = true;
            if (state.OwnsSawmill2) data.owned[WorldStateSnapshot.Sawmill2Id] = true;
            foreach (string id in progress.Seen) data.seen[id] = 1;
            return data;
        }

        /// <summary>Restores a save into a fresh new-game state (call before the world reads it).</summary>
        public static void Apply(SaveData data, GameProgress progress, WorldStateSnapshot state)
        {
            progress.Restore(data.money, data.total, data.xp, data.level, data.quest);
            foreach (KeyValuePair<string, int> u in data.lv) progress.SetUpgradeLevel(u.Key, u.Value);
            foreach (KeyValuePair<string, PadSave> p in data.pads)
            {
                GameProgress.PadState pad = progress.Pad(p.Key);
                pad.Level = p.Value.lv;
                pad.Paid = p.Value.paid;
            }
            foreach (KeyValuePair<string, bool> o in data.owned)
            {
                if (o.Key == WorldStateSnapshot.Sawmill2Id) state.OwnsSawmill2 = o.Value;
                else if (o.Value) state.OwnedProducts.Add(o.Key);
                else state.OwnedProducts.Remove(o.Key);
            }
            state.OwnsPlumbing = state.OwnedProducts.Contains("sink");
            foreach (string id in data.seen.Keys) progress.MarkSeen(id);
            WorldStateSync.Apply(state, progress);
        }
    }
}
