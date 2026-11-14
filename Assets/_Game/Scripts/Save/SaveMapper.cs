using System;
using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.Delivery;
using FF.Gameplay.Home;
using FF.Gameplay.Progress;
using FF.Gameplay.World;

namespace FF.Save
{
    /// <summary>Copies the live game state into a <see cref="SaveData"/> and back.</summary>
    public static class SaveMapper
    {
        public static SaveData Capture(GameProgress progress, WorldStateSnapshot state, DeliveryCargo cargo, string language, HomeState home = null)
        {
            var data = new SaveData
            {
                money = progress.Money,
                total = progress.TotalEarned,
                xp = progress.Xp,
                level = progress.Level,
                quest = progress.QuestStep,
                lang = language,
                skin = progress.Skin,
            };
            foreach (KeyValuePair<string, int> u in progress.Upgrades) data.lv[u.Key] = u.Value;
            foreach (KeyValuePair<string, GameProgress.PadState> p in progress.Pads)
                if (p.Value.Level > 0 || p.Value.Paid > 0)
                    data.pads[p.Key] = new PadSave { lv = p.Value.Level, paid = p.Value.Paid };
            foreach (string id in state.OwnedProducts) data.owned[id] = true;
            if (state.OwnsSawmill2) data.owned[WorldStateSnapshot.Sawmill2Id] = true;
            foreach (string id in progress.Seen) data.seen[id] = 1;
            if (cargo != null)
                foreach (List<ItemType> load in cargo.Loads)
                {
                    var names = new List<string>(load.Count);
                    foreach (ItemType t in load) names.Add(t.ToString());
                    data.trucks.Add(names);
                }
            if (home != null)
            {
                foreach (KeyValuePair<string, string> kv in home.Placed) data.home.slots[kv.Key] = kv.Value;
                foreach (KeyValuePair<string, int> kv in home.Storage)
                    if (kv.Value > 0) data.home.storage[kv.Key] = kv.Value;
                data.home.rooms.AddRange(home.RewardedAreas);
            }
            return data;
        }

        /// <summary>Restores a save into a fresh new-game state (call before the world reads it).</summary>
        public static void Apply(SaveData data, GameProgress progress, WorldStateSnapshot state, DeliveryCargo cargo, HomeState home = null)
        {
            progress.Restore(data.money, data.total, data.xp, data.level, data.quest);
            if (!string.IsNullOrEmpty(data.skin)) progress.Skin = data.skin;
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
            foreach (string id in data.seen.Keys) progress.MarkSeen(id);
            if (cargo != null && data.trucks != null)
            {
                cargo.Loads.Clear();
                for (int i = 0; i < data.trucks.Count; i++)
                {
                    List<ItemType> load = cargo.Of(i);
                    if (data.trucks[i] == null) continue;
                    foreach (string name in data.trucks[i])
                        if (Enum.TryParse(name, out ItemType t) && ItemTypes.IsProduct(t)) load.Add(t);
                }
            }
            if (home != null)
            {
                home.Clear();
                HomeSave h = data.home;
                if (h?.slots != null)
                    foreach (KeyValuePair<string, string> kv in h.slots)
                        if (!string.IsNullOrEmpty(kv.Value)) home.Placed[kv.Key] = kv.Value;
                if (h?.storage != null)
                    foreach (KeyValuePair<string, int> kv in h.storage)
                        if (kv.Value > 0) home.Storage[kv.Key] = kv.Value;
                if (h?.rooms != null)
                    foreach (string room in h.rooms) home.RewardedAreas.Add(room);
            }
            WorldStateSync.Apply(state, progress);
        }
    }
}
