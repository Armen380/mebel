using System.Collections.Generic;
using FF.Core;
using FF.Gameplay.Shop;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Pads
{
    /// <summary>Prototype <c>placeRegPad</c>: the register pad stands on the next register stall to be opened.</summary>
    [RequireComponent(typeof(UpgradePad))]
    public sealed class RegisterPadPlacer : MonoBehaviour
    {
        [Tooltip("Main-shop registers 0…5 in order.")]
        [SerializeField] List<Register> registers = new List<Register>();

        IUpgradeLevels _levels;
        int _placedFor = -1;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<Register> mainRegisters) => registers = mainRegisters;

        void Awake()
        {
            _levels = Services.Get<IUpgradeLevels>();
            Place();
        }

        void LateUpdate() => Place();

        void Place()
        {
            int next = 1 + _levels.GetLevel(WorldStateSync.RegisterPadId);
            if (next == _placedFor || next >= registers.Count) return;
            _placedFor = next;
            transform.position = registers[next].Position;
        }
    }
}
