using System.Collections.Generic;

namespace FF.Save
{
    /// <summary>
    /// The save file (02_SYSTEMS_SPEC §16, prototype <c>S</c>): money, XP, level, tutorial step, panel upgrade levels,
    /// pad levels with partial payments, owned buildings, announced unlock cards, language and skin. Item piles and
    /// character positions are not saved (as in the prototype).
    /// </summary>
    public sealed class SaveData
    {
        public const int CurrentVersion = 3;

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
    }

    public sealed class PadSave
    {
        public int lv;
        public long paid;
    }
}
