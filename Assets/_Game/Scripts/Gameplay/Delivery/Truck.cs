using System;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using UnityEngine;

namespace FF.Gameplay.Delivery
{
    /// <summary>
    /// A delivery truck (prototype <c>makeTruck</c>): its <see cref="TruckMotion"/>, the bed pile (2×4) and the visuals.
    /// The model faces +Z; on the road it faces east. Driven by <see cref="DeliveryDirector"/>.
    /// </summary>
    public sealed class Truck : MonoBehaviour
    {
        [SerializeField] Transform bed;
        [SerializeField] Transform[] wheels = Array.Empty<Transform>();

        static readonly Quaternion FacingEast = Quaternion.Euler(0f, 90f, 0f);

        float _wheelAngle;

        public TruckMotion Motion { get; } = new TruckMotion();
        public ItemStack Bed { get; private set; }
        /// <summary>Payout fixed when the order was full (prototype <c>t.pay / t.xp</c>).</summary>
        public long PendingPay;
        public int PendingXp;

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform bedAnchor, Transform[] wheelPivots)
        {
            bed = bedAnchor;
            wheels = wheelPivots;
        }

        /// <param name="capacity">Room on the bed right now (the order size only while docked).</param>
        public void Init(ItemCatalog catalog, WorldLayout.PileSettings pile, Func<int> capacity)
        {
            Bed = new ItemStack(bed, new PileLayout(pile), catalog, capacity);
            transform.rotation = FacingEast;
        }

        /// <summary>Moves the model to the motion's position and rolls the wheels.</summary>
        public void Sync()
        {
            transform.position = ProtoCoords.ToUnity(Motion.X, Motion.Z);
            if (Motion.WheelTurn == 0f) return;
            _wheelAngle = Mathf.Repeat(_wheelAngle + Motion.WheelTurn * Mathf.Rad2Deg, 360f);
            Quaternion spin = Quaternion.Euler(_wheelAngle, 0f, 0f);
            for (int i = 0; i < wheels.Length; i++) wheels[i].localRotation = spin;
        }
    }
}
