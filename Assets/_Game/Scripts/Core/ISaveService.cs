namespace FF.Core
{
    /// <summary>Save file access for menus and dev tools.</summary>
    public interface ISaveService
    {
        /// <summary>Writes the save now (purchases, leaving the game).</summary>
        void SaveNow();
        /// <summary>Deletes the save and restarts the game scene from a new game.</summary>
        void DeleteAndRestart();
    }

    /// <summary>Development shortcuts (prototype menu "Test: +25 Lv, +250K").</summary>
    public interface IDevCheats
    {
        void AddLevelsAndMoney(int levels, long money);
    }
}
