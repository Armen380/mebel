namespace FF.Core
{
    /// <summary>Current level of an Upgrades-panel item (ids from upgrades.json, e.g. "speed", "cap").</summary>
    public interface IUpgradeLevels
    {
        int GetLevel(string upgradeId);
    }
}
