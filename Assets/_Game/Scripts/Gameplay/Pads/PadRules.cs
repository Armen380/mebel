namespace FF.Gameplay.Pads
{
    /// <summary>When a pad shows (prototype <c>addPad({show})</c> of each pad family).</summary>
    public enum PadRule
    {
        /// <summary>Shop expansion: always (until max).</summary>
        Always,
        /// <summary>Speed / qty pads: the owner building is owned.</summary>
        OwnerOwned,
        /// <summary>Buy pads: the owner is not owned yet and the player reached its unlock level.</summary>
        BuyOwner,
        /// <summary>New register: fewer registers bought than the shop level.</summary>
        Register,
        /// <summary>Dream House stage: the previous stage is built (the first stage: the tutorial is done).</summary>
        AfterPad,
    }

    public static class PadRules
    {
        /// <param name="ownerUnlockLevel">Player level that opens a buy pad (0 = none).</param>
        public static bool IsVisible(PadRule rule, int padLevel, int padMaxLevel, bool ownerOwned, int playerLevel,
            int ownerUnlockLevel, int registerLevel, int shopLevel)
        {
            if (padLevel >= padMaxLevel) return false;
            switch (rule)
            {
                case PadRule.OwnerOwned: return ownerOwned;
                case PadRule.BuyOwner: return !ownerOwned && playerLevel >= ownerUnlockLevel;
                case PadRule.Register: return registerLevel < shopLevel;
                case PadRule.AfterPad: return ownerOwned;
                default: return true;
            }
        }
    }
}
