using System.Collections.Generic;
using System.Globalization;
using FF.Data;
using UnityEngine.Localization.Settings;

namespace FF.UI.Upgrades
{
    /// <summary>Prototype <c>UPG[i].val(lv)</c>: the value an upgrade gives at a level ("7 items", "112%", "0.81 s", …).</summary>
    public static class UpgradeValueText
    {
        const string Table = "Game";
        static readonly Dictionary<string, object> Args = new Dictionary<string, object>();

        /// <summary>Key and {n} argument; key is null for texts without a localized template (percentages).</summary>
        public static (string key, string n) Parts(UpgradeDef u, int level, EconomyConfig economy)
        {
            switch (u.valueFormat)
            {
                case UpgradeValueFormat.Items: return ("u.items", economy.CarryCapacity(level).ToString(CultureInfo.InvariantCulture));
                case UpgradeValueFormat.SpeedPercent: return (null, (100 + 12 * level).ToString(CultureInfo.InvariantCulture) + "%");
                case UpgradeValueFormat.Seconds:
                    // (1.1/(1+.35·lv)).toFixed(2)
                    double seconds = economy.chopSecondsBase / (1.0 + economy.axeSpeedPerLevel * (double)level);
                    return ("u.sec", seconds.ToString("0.00", CultureInfo.InvariantCulture));
                case UpgradeValueFormat.Bots: return ("u.bots", level.ToString(CultureInfo.InvariantCulture));
                case UpgradeValueFormat.PriceBonus: return ("u.price", (15 * level).ToString(CultureInfo.InvariantCulture));
                case UpgradeValueFormat.Customers: return ("u.cust", level > 0 ? "+" + level.ToString(CultureInfo.InvariantCulture) : "0");
                case UpgradeValueFormat.QualityPercent: return (null, "+" + (25 * level).ToString(CultureInfo.InvariantCulture) + "%");
                default: return ("u.people", level.ToString(CultureInfo.InvariantCulture));
            }
        }

        public static string Format(UpgradeDef u, int level, EconomyConfig economy)
        {
            (string key, string n) = Parts(u, level, economy);
            if (key == null) return n;
            Args.Clear();
            Args["n"] = n;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, key, new object[] { Args });
        }
    }
}
