using System.Collections.Generic;

namespace FF.Save
{
    /// <summary>
    /// The save file (02_SYSTEMS_SPEC §16, prototype <c>S</c>): money, XP, level, tutorial step, panel upgrade levels,
    /// pad levels with partial payments, owned buildings, announced unlock cards, language and skin, and what lies on each
    /// delivery truck (v4, user decision; the prototype loses it) and the Dream House furnishing (v5, M10). Other item piles and character positions are not saved.
    /// </summary>
    public sealed class SaveData
    {
        public const int CurrentVersion = 5;

        public int version = CurrentVersion;
        public long money;
        public long total;
        public int xp;
        public int level = 1;
        public int quest;
        public Dictionary<string, int> lv = new Dictionary<string, int>();
        public Dictionary<string, PadSave> pads = new Dictionary<string, PadSave>();
        public Dictionary<string, bool> owned = new Dictionary<string, bool>();
        public Dictionary<string, int> seen = new Dictionary<string, int>();
        public string lang;
        public string skin = "lumber";
        /// <summary>Item types on each truck's bed, by truck index (v4; older saves: empty trucks).</summary>
        public List<List<string>> trucks = new List<List<string>>();
        /// <summary>Dream House furnishing (v5; older saves: nothing placed). Stages are the house_* pad levels.</summary>
        public HomeSave home = new HomeSave();
    }

    public sealed class HomeSave
    {
        /// <summary>Slot id → placed item id.</summary>
        public Dictionary<string, string> slots = new Dictionary<string, string>();
        /// <summary>Home Store item id → count in storage.</summary>
        public Dictionary<string, int> storage = new Dictionary<string, int>();
        /// <summary>Areas whose gift was paid.</summary>
        public List<string> rooms = new List<string>();
    }

    public sealed class PadSave
    {
        public int lv;
        public long paid;
    }
}
