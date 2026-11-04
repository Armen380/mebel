using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.CarPark
{
    /// <summary>One point of a car's path (prototype coordinates); <see cref="Reverse"/> keeps the heading (backing out).</summary>
    public struct CarWaypoint
    {
        public Vector2 Point;
        public bool Reverse;

        public CarWaypoint(float x, float z, bool reverse = false)
        {
            Point = new Vector2(x, z);
            Reverse = reverse;
        }
    }

    /// <summary>
    /// Prototype car park geometry (<c>LOT</c>, <c>spawnCar</c>, <c>carLeave</c>) and the car customer's walk
    /// (<c>spawnCustomer(…, car)</c>, <c>leave</c>), all in prototype coordinates.
    /// </summary>
    public static class CarRoute
    {
        public static float SlotX(WorldLayout.CarParkSettings c, int slot) => c.slotBaseX + c.slotStepX * slot;

        /// <summary>In from the east on the west lane → driveway → aisle → slot, nose in.</summary>
        public static void Arrive(WorldLayout.CarParkSettings c, WorldLayout.RoadSettings road, int slot, List<CarWaypoint> into)
        {
            float x = SlotX(c, slot);
            into.Clear();
            into.Add(new CarWaypoint(c.drivewayX, road.laneWestboundZ));
            into.Add(new CarWaypoint(c.drivewayX, c.aisleZ));
            into.Add(new CarWaypoint(x, c.aisleZ));
            into.Add(new CarWaypoint(x, c.slotZ));
        }

        /// <summary>Back out to the aisle, drive to the driveway and away east on the east lane.</summary>
        public static void Depart(WorldLayout.CarParkSettings c, WorldLayout.RoadSettings road, int slot, List<CarWaypoint> into)
        {
            into.Clear();
            into.Add(new CarWaypoint(SlotX(c, slot), c.aisleZ, true));
            into.Add(new CarWaypoint(c.drivewayX, c.aisleZ));
            into.Add(new CarWaypoint(c.drivewayX, road.laneEastboundZ));
            into.Add(new CarWaypoint(c.carSpawnX, road.laneEastboundZ));
        }

        /// <summary>Where the car appears (east end of the west lane).</summary>
        public static Vector2 Spawn(WorldLayout.CarParkSettings c, WorldLayout.RoadSettings road) => new Vector2(c.carSpawnX, road.laneWestboundZ);

        /// <summary>Prototype: road speed while the car and its next point are both on the road side, lot speed otherwise.</summary>
        public static float Speed(float z, float targetZ, WorldLayout.CarParkSettings c, EconomyConfig e) =>
            z < c.roadSpeedMaxZ && targetZ < c.roadSpeedMaxZ ? e.carRoadSpeed : e.carLotSpeed;

        /// <summary>Driver's door: beside the parked car.</summary>
        public static Vector2 DriverDoor(WorldLayout.CarParkSettings c, int slot) => new Vector2(SlotX(c, slot) + c.driverSideOffset, c.slotZ);

        /// <summary>From the car to the sidewalk in line with the shop door (then the usual door way-points).</summary>
        public static void WalkToShop(WorldLayout.CarParkSettings c, Vector2 driverDoor, float doorOutX, List<Vector2> into)
        {
            into.Add(new Vector2(driverDoor.x, c.aisleZ));
            into.Add(new Vector2(doorOutX, c.sidewalkZ));
        }

        /// <summary>From the shop door back to the car (after the door way-points).</summary>
        public static void WalkToCar(WorldLayout.CarParkSettings c, Vector2 driverDoor, float doorOutX, List<Vector2> into)
        {
            into.Add(new Vector2(doorOutX, c.sidewalkZ));
            into.Add(new Vector2(driverDoor.x, c.aisleZ));
            into.Add(driverDoor);
        }
    }

    /// <summary>
    /// Prototype <c>updCars</c> movement for one car: follow the way-points at road / lot speed, turn the heading
    /// toward the travel direction (not while reversing) with a smooth lerp, roll the wheels.
    /// </summary>
    public sealed class CarMotion
    {
        public readonly List<CarWaypoint> Path = new List<CarWaypoint>(4);
        /// <summary>Prototype position (x, z).</summary>
        public Vector2 Position;
        /// <summary>Target heading and current heading, prototype radians (atan2(dx, dz), 0 = toward the camera).</summary>
        public float Face, Heading;
        /// <summary>Wheel rotation of the last step (radians, positive = rolling forward).</summary>
        public float WheelTurn;

        public bool Arrived => Path.Count == 0;

        public void Place(Vector2 position, float face)
        {
            Position = position;
            Face = Heading = face;
        }

        public void Step(float dt, WorldLayout.CarParkSettings c, EconomyConfig e)
        {
            WheelTurn = 0f;
            if (Path.Count == 0) return;
            CarWaypoint seg = Path[0];
            Vector2 d = seg.Point - Position;
            float dist = d.magnitude;
            float step = Mathf.Min(dist, CarRoute.Speed(Position.y, seg.Point.y, c, e) * dt);
            if (dist > 0.01f)
            {
                Position += d / dist * step;
                if (!seg.Reverse) Face = Mathf.Atan2(d.x, d.y);
                WheelTurn = (seg.Reverse ? -1f : 1f) * step * e.carWheelSpin;
            }
            Heading = LerpAngle(Heading, Face, 1f - Mathf.Exp(-dt * e.carTurnRate));
            if (dist - step < 0.02f) Path.RemoveAt(0);
        }

        /// <summary>Prototype <c>lerpAng</c>: shortest way round.</summary>
        public static float LerpAngle(float a, float b, float t)
        {
            float diff = Mathf.Repeat(b - a + Mathf.PI, 2f * Mathf.PI) - Mathf.PI;
            return a + diff * t;
        }
    }
}
