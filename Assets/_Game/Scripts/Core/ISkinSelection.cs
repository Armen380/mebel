using System;

namespace FF.Core
{
    /// <summary>The player's character look (prototype <c>S.skin / setSkin</c>), for the menu's skin cards.</summary>
    public interface ISkinSelection
    {
        string Current { get; }
        /// <summary>Raised with the new skin id after a switch.</summary>
        event Action<string> Changed;
        /// <summary>Switches to an unlocked skin; returns false for unknown or locked ones.</summary>
        bool Select(string id);
        bool IsUnlocked(string id);
    }
}
