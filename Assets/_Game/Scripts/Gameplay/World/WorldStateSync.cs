using FF.Core;
using UnityEngine;

namespace FF.Gameplay.World
{
    /// <summary>Copies the pad levels that shape the world (shop width, register count) into the world state.</summary>
    public static class WorldStateSync
    {
        public const string ShopPadId = "shop";
        public const string RegisterPadId = "reg";
        /// <summary>Second materials-shop register (register 7).</summary>
        public const string AnnexRegisterPadId = "reg_annex";
        public const int MainRegisterSlots = 6;

        /// <summary>Main registers in use: 1 + min(register pad level, shop level), at most 6 (prototype register active rule).</summary>
        public static int MainRegisters(int registerLevel, int shopLevel) =>
            Mathf.Min(MainRegisterSlots, 1 + Mathf.Min(registerLevel, shopLevel));

        public static void Apply(WorldStateSnapshot state, IUpgradeLevels levels)
        {
            state.ShopLevel = levels.GetLevel(ShopPadId);
            state.MainRegisters = MainRegisters(levels.GetLevel(RegisterPadId), state.ShopLevel);
            state.AnnexSecondRegister = levels.GetLevel(AnnexRegisterPadId) > 0;
        }
    }
}
