using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Delivery
{
    /// <summary>Prototype truck states: <c>away → in → park → bay → unpark → out → away</c>.</summary>
    public enum TruckPhase
    {
        /// <summary>Off-screen, waiting for its timer and a free bay.</summary>
        Away,
        /// <summary>Driving east along the lane, slowing down toward the bay.</summary>
        Arriving,
        /// <summary>Moving sideways from the lane into the bay.</summary>
        Parking,
        /// <summary>At the bay, taking furniture until the order is full.</summary>
        Docked,
        /// <summary>Moving sideways back onto the lane; the bay is still taken.</summary>
        Unparking,
        /// <summary>Accelerating east off-screen; the payout comes when it is gone.</summary>
        Departing,
    }

    /// <summary>What one <see cref="TruckMotion.Step"/> changed.</summary>
    public enum TruckEvent
    {
        None,
        /// <summary>Reached the bay: the dock opens.</summary>
        Docked,
        /// <summary>The order was full long enough: the truck starts to leave (payout is fixed now).</summary>
        Full,
        /// <summary>Back on the lane: the bay is free again.</summary>
        LeftBay,
        /// <summary>Past the edge of the world: pay out, empty the bed, wait.</summary>
        Delivered,
    }

    /// <summary>
    /// Prototype <c>updTrucks</c> for one truck, in prototype coordinates (x along the road, z toward the camera).
    /// Plain C#: the bay choice and the cargo live in <see cref="DeliveryDirector"/>.
    /// </summary>
    public sealed class TruckMotion
    {
        public TruckPhase Phase = TruckPhase.Away;
        public float X, Z;
        /// <summary>Speed while departing (prototype <c>t.v</c>).</summary>
        public float Speed;
        /// <summary>Away: seconds until it may come back (may go below 0 while every bay is taken). Docked: seconds full.</summary>
        public float Timer;
        /// <summary>Bay index from dispatch until it is back on the lane; −1 otherwise.</summary>
        public int Bay = -1;
        /// <summary>Wheel rotation of the last step (radians about the axle, positive = rolling forward).</summary>
        public float WheelTurn;

        /// <summary>Holds a bay from <see cref="TruckPhase.Arriving"/> through <see cref="TruckPhase.Unparking"/>.</summary>
        public bool HoldsBay => Bay >= 0;

        public bool CanDispatch => Phase == TruckPhase.Away && Timer <= 0f;

        /// <summary>Prototype: the truck takes bay <paramref name="bay"/> and appears at the west end of the lane.</summary>
        public void Dispatch(int bay, WorldLayout.DeliverySettings d)
        {
            Bay = bay;
            Phase = TruckPhase.Arriving;
            X = d.truckStartX;
            Z = d.truckLaneZ;
            Speed = 0f;
        }

        /// <summary>Restored from a save: already parked at the bay.</summary>
        public void DockAt(int bay, float bayX, WorldLayout.DeliverySettings d)
        {
            Bay = bay;
            Phase = TruckPhase.Docked;
            X = bayX;
            Z = d.truckParkZ;
            Timer = 0f;
            Speed = 0f;
        }

        /// <param name="bayX">Prototype x of the bay this truck holds (ignored when it holds none).</param>
        /// <param name="loaded">Items settled on the bed.</param>
        public TruckEvent Step(float dt, float bayX, int loaded, EconomyConfig e, WorldLayout.DeliverySettings d)
        {
            WheelTurn = 0f;
            switch (Phase)
            {
                case TruckPhase.Away:
                    Timer -= dt;
                    return TruckEvent.None;

                case TruckPhase.Arriving:
                {
                    float sp = Mathf.Clamp((bayX - X) * e.truckArriveSpeedFactor, e.truckArriveMinSpeed, e.truckMaxSpeed);
                    float before = X;
                    X = Mathf.Min(bayX, X + sp * dt);
                    WheelTurn = (X - before) * e.truckWheelSpin;
                    if (X >= bayX) Phase = TruckPhase.Parking;
                    return TruckEvent.None;
                }

                case TruckPhase.Parking:
                    Z = Mathf.Max(d.truckParkZ, Z - dt * e.truckParkSpeed);
                    if (Z > d.truckParkZ) return TruckEvent.None;
                    Phase = TruckPhase.Docked;
                    Timer = 0f;
                    return TruckEvent.Docked;

                case TruckPhase.Docked:
                    if (loaded < e.truckOrderSize) return TruckEvent.None;
                    Timer += dt;
                    if (Timer <= e.truckFullWaitSeconds) return TruckEvent.None;
                    Phase = TruckPhase.Unparking;
                    return TruckEvent.Full;

                case TruckPhase.Unparking:
                    Z = Mathf.Min(d.truckLaneZ, Z + dt * e.truckParkSpeed);
                    if (Z < d.truckLaneZ) return TruckEvent.None;
                    Phase = TruckPhase.Departing;
                    Speed = 0f;
                    Bay = -1;
                    return TruckEvent.LeftBay;

                case TruckPhase.Departing:
                    Speed = Mathf.Min(e.truckMaxSpeed, Speed + dt * e.truckAcceleration);
                    X += Speed * dt;
                    WheelTurn = Speed * dt * e.truckWheelSpin;
                    if (X <= d.truckDespawnX) return TruckEvent.None;
                    Phase = TruckPhase.Away;
                    Timer = e.truckAwaySeconds;
                    return TruckEvent.Delivered;
            }
            return TruckEvent.None;
        }
    }
}
