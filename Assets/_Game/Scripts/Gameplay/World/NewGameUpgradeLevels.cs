using FF.Core;

namespace FF.Gameplay.World
{
    /// <summary>All upgrades at level 0 — the state of a new game until the save system (M5) provides real levels.</summary>
    public sealed class NewGameUpgradeLevels : IUpgradeLevels
    {
        public int GetLevel(string upgradeId) => 0;
    }
}
