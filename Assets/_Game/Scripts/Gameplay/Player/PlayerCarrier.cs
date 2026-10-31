using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Items;
using UnityEngine;

namespace FF.Gameplay.Player
{
    /// <summary>
    /// The player's hands: a carry column on the rig's carry anchor (capacity 5 + 2·cap level), the throw
    /// (prototype <c>throwAll</c>) and the red "FULL" tag.
    /// </summary>
    [RequireComponent(typeof(CharacterRig))]
    public sealed class PlayerCarrier : MonoBehaviour, ICarrier, IWorldTagSource
    {
        const string CapUpgradeId = "cap";
        const float FullTagHeight = 2.6f;
        const float FullTagStep = 0.05f;

        readonly List<Item> _throwBuffer = new List<Item>(32);
        EconomyConfig _economy;
        IUpgradeLevels _upgrades;
        ItemFlights _flights;

        public ItemStack Stack { get; private set; }

        void Awake()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _upgrades = Services.Get<IUpgradeLevels>();
            Stack = new ItemStack(GetComponent<CharacterRig>().carryAnchor, CarryLayout.Instance, db.items, Capacity);
            Services.Register<ICarrier>(this);
        }

        void Start()
        {
            _flights = Services.Get<ItemFlights>();
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Register(this);
        }

        void OnDestroy()
        {
            if (Services.TryGet(out WorldTagRegistry tags)) tags.Unregister(this);
        }

        int Capacity() => _economy.CarryCapacity(_upgrades.GetLevel(CapUpgradeId));

        public int CarriedCount => Stack.Count;
        public int CarryCapacity => Stack.Capacity;

        public void ThrowAll()
        {
            if (Stack.Settled == 0) return;
            _throwBuffer.Clear();
            Stack.TakeAll(_throwBuffer);
            Vector3 p = transform.position, forward = transform.forward;
            float spread = _economy.throwSpread;
            for (int i = 0; i < _throwBuffer.Count; i++)
            {
                Vector3 target = p + forward * _economy.throwDistance;
                target.x += (Random.value - 0.5f) * spread;
                target.z += (Random.value - 0.5f) * spread;
                target.y = _economy.throwLandHeight;
                _flights.FlyAndShrink(_throwBuffer[i], target,
                    _economy.throwFlightSeconds + i * _economy.throwFlightStep, _economy.throwArc);
            }
            _throwBuffer.Clear();
            GameEvents.RaiseThrown();
        }

        public bool TagVisible => Stack.Count >= Stack.Capacity;
        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = transform.position;
                p.y = FullTagHeight + Stack.Count * FullTagStep;
                return p;
            }
        }
        public WorldTagStyle TagStyle => WorldTagStyle.Full;
        public int TagCount => Stack.Count;
        public int TagCapacity => Stack.Capacity;
        public long TagValue => 0;
        public string TagIcon => null;
    }
}
