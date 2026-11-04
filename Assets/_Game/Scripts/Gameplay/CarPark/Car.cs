using System;
using FF.Core;
using FF.Gameplay.Characters;
using FF.Gameplay.Shop;
using UnityEngine;

namespace FF.Gameplay.CarPark
{
    /// <summary>
    /// A customer's car (prototype <c>makeCar</c>, states <c>in → parked → leave</c>): drives into its slot, lets the driver
    /// out, waits for them and drives away. The model faces +Z. Pooled by <see cref="CarDirector"/>.
    /// </summary>
    public sealed class Car : MonoBehaviour, ICarRide
    {
        public enum Phase
        {
            Arriving,
            Parked,
            Leaving,
            Gone,
        }

        [SerializeField] Transform[] wheels = Array.Empty<Transform>();

        float _wheelAngle;

        public CarMotion Motion { get; } = new CarMotion();
        public Phase State { get; set; }
        public int Slot { get; set; } = -1;
        public int PoolIndex { get; set; }
        /// <summary>Seconds in the current state (soak-test watchdog).</summary>
        public float StateTime { get; set; }
        public Vector2 DriverDoor { get; set; }
        /// <summary>Set when the driver is back at the car.</summary>
        public bool DriverBack { get; private set; }

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform[] wheelPivots) => wheels = wheelPivots;

        public void ResetRide()
        {
            DriverBack = false;
            StateTime = 0f;
            _wheelAngle = 0f;
        }

        void ICarRide.DriverReturned() => DriverBack = true;

        public void Sync()
        {
            transform.SetPositionAndRotation(ProtoCoords.ToUnity(Motion.Position),
                Quaternion.Euler(0f, AgentMotor.YawFromPrototype(Motion.Heading), 0f));
            if (Motion.WheelTurn == 0f) return;
            _wheelAngle = Mathf.Repeat(_wheelAngle + Motion.WheelTurn * Mathf.Rad2Deg, 360f);
            Quaternion spin = Quaternion.Euler(_wheelAngle, 0f, 0f);
            for (int i = 0; i < wheels.Length; i++) wheels[i].localRotation = spin;
        }
    }
}
