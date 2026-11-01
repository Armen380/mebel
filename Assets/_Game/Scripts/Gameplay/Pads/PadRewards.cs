using FF.Core;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Pads
{
    /// <summary>
    /// What a completed pad does beyond its level (prototype <c>addPad({onLevel})</c>). Speed / qty pads need nothing
    /// here: machines and buildings read the levels. Factory buy pads, shop, registers and trucks join in M5 / M7 / M8.
    /// </summary>
    public sealed class PadRewards : MonoBehaviour
    {
        public const string Sawmill2BuyPad = "saw2_buy";

        Ownership _ownership;

        void Start() => _ownership = Services.Get<Ownership>();

        void OnEnable() => GameEvents.PadCompleted += OnPadCompleted;

        void OnDisable() => GameEvents.PadCompleted -= OnPadCompleted;

        void OnPadCompleted(string padId, int level)
        {
            if (padId != Sawmill2BuyPad) return;
            _ownership.Own(WorldStateSnapshot.Sawmill2Id);
            GameEvents.RaiseToast("sign.saw2", "t.saw2");
        }
    }
}
