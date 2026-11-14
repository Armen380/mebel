using System.Collections.Generic;

namespace FF.Gameplay.Home
{
    /// <summary>What the player has done with the Dream House (saved in SaveData.home, v5).</summary>
    public sealed class HomeState
    {
        /// <summary>Slot id → placed item id (factory slots: the product id, e.g. "sofa").</summary>
        public readonly Dictionary<string, string> Placed = new Dictionary<string, string>();
        /// <summary>Home Store item id → count bought but not placed.</summary>
        public readonly Dictionary<string, int> Storage = new Dictionary<string, int>();
        /// <summary>Areas whose one-time gift was paid.</summary>
        public readonly HashSet<string> RewardedAreas = new HashSet<string>();

        public void Clear()
        {
            Placed.Clear();
            Storage.Clear();
            RewardedAreas.Clear();
        }

        public int StorageCount
        {
            get
            {
                int n = 0;
                foreach (KeyValuePair<string, int> kv in Storage) n += kv.Value;
                return n;
            }
        }
    }
}
