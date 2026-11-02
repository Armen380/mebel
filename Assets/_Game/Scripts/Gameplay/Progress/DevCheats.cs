using FF.Core;

namespace FF.Gameplay.Progress
{
    /// <summary>Prototype menu test button: "+25 Lv, +250K" (Editor and development builds only, via the dev panel).</summary>
    public sealed class DevCheats : IDevCheats
    {
        readonly GameProgress _progress;

        public DevCheats(GameProgress progress) => _progress = progress;

        public void AddLevelsAndMoney(int levels, long money)
        {
            _progress.AddLevels(levels);
            _progress.AddMoney(money);
        }
    }
}
