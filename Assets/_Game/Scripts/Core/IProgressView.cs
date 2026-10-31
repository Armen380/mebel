namespace FF.Core
{
    /// <summary>Read-only player progress for the HUD (money, level bar, tutorial bar).</summary>
    public interface IProgressView
    {
        long Money { get; }
        int Level { get; }
        int Xp { get; }
        /// <summary>XP needed to reach the next level from the current one.</summary>
        int XpNeeded { get; }
        /// <summary>Current tutorial step index; ≥ step count when the tutorial is finished.</summary>
        int QuestStep { get; }
    }
}
