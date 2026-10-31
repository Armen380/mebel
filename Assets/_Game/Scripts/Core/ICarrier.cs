namespace FF.Core
{
    /// <summary>What the HUD needs to know about the player's hands (Throw button, "FULL" tag).</summary>
    public interface ICarrier
    {
        /// <summary>Items in hand plus items flying toward the hands.</summary>
        int CarriedCount { get; }
        int CarryCapacity { get; }
        /// <summary>Throws away every item already in hand (prototype <c>throwAll()</c>).</summary>
        void ThrowAll();
    }
}
