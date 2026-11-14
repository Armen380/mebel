namespace FF.Core
{
    /// <summary>Dream House comfort bonus on sale prices (M10): 1 + bonus per point · comfort.</summary>
    public interface IHomeBonus
    {
        double SaleMultiplier { get; }
    }

    /// <summary>What the Home Store catalog, the comfort chip and the variant picker need from the Dream House (M10).</summary>
    public interface IHomeStore
    {
        /// <summary>House stages built (0 none … 4 windows and doors).</summary>
        int Stage { get; }
        int Comfort { get; }
        /// <summary>Items bought but not placed yet.</summary>
        int StorageCount { get; }
        /// <summary>Some slot of the item's group is open.</summary>
        bool IsAvailable(string itemId);
        bool CanBuy(string itemId);
        /// <summary>The group's slot count is reached (storage + placed).</summary>
        bool IsAtCap(string itemId);
        /// <summary>This item in storage.</summary>
        int InStorage(string itemId);
        /// <summary>This item stands on some slot.</summary>
        bool IsPlaced(string itemId);
        bool Buy(string itemId);
        /// <summary>Storage items that could replace the slot's placed item; returns how many.</summary>
        int Variants(string slotId, System.Collections.Generic.List<string> into);
        /// <summary>Puts the slot's item back into storage and places <paramref name="itemId"/> instead.</summary>
        bool Swap(string slotId, string itemId);
    }
}
