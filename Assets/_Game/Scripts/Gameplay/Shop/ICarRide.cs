using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>The car a customer came in (prototype <c>c.car</c>).</summary>
    public interface ICarRide
    {
        /// <summary>Prototype position where the driver gets out and back in.</summary>
        Vector2 DriverDoor { get; }

        /// <summary>The driver reached the car on the way out: it may drive away.</summary>
        void DriverReturned();
    }
}
