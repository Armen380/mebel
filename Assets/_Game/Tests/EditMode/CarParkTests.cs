using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.CarPark;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M7: car park slots, car paths and speeds (prototype LOT / spawnCar / carLeave / updCars), driver walk.</summary>
    public sealed class CarParkTests
    {
        EconomyConfig _e;
        WorldLayout _w;

        [SetUp]
        public void SetUp()
        {
            _e = ScriptableObject.CreateInstance<EconomyConfig>();
            _w = ScriptableObject.CreateInstance<WorldLayout>();
        }

        [TearDown]
        public void TearDown()
        {
            Object.DestroyImmediate(_e);
            Object.DestroyImmediate(_w);
        }

        static void AreNear(Vector2 expected, Vector2 actual, string message = null) =>
            Assert.That(Vector2.Distance(expected, actual), Is.LessThan(1e-4f), $"{message} expected {expected} got {actual}");

        [Test]
        public void Slots_GrowWithTheShop()
        {
            Assert.AreEqual(4, _e.CarSlots(0));
            Assert.AreEqual(6, _e.CarSlots(2));
            Assert.AreEqual(8, _e.CarSlots(4));
            Assert.AreEqual(8, _e.CarSlots(5), "8 slots at most");
            Assert.AreEqual(11.5f, CarRoute.SlotX(_w.carPark, 0), 1e-5f);
            Assert.AreEqual(29.7f, CarRoute.SlotX(_w.carPark, 7), 1e-4f);
        }

        [Test]
        public void Arrive_DrivewayAisleSlotNoseIn()
        {
            var path = new List<CarWaypoint>();
            CarRoute.Arrive(_w.carPark, _w.road, 2, path);
            Assert.AreEqual(4, path.Count);
            AreNear(new Vector2(33f, 12.3f), path[0].Point, "driveway on the west lane");
            AreNear(new Vector2(33f, 19.6f), path[1].Point, "aisle");
            AreNear(new Vector2(16.7f, 19.6f), path[2].Point, "slot column");
            AreNear(new Vector2(16.7f, 22.6f), path[3].Point, "nose in");
            foreach (CarWaypoint p in path) Assert.IsFalse(p.Reverse);
            AreNear(new Vector2(140f, 12.3f), CarRoute.Spawn(_w.carPark, _w.road));
        }

        [Test]
        public void Depart_ReversesThenDrivesEast()
        {
            var path = new List<CarWaypoint>();
            CarRoute.Depart(_w.carPark, _w.road, 2, path);
            Assert.AreEqual(4, path.Count);
            AreNear(new Vector2(16.7f, 19.6f), path[0].Point);
            Assert.IsTrue(path[0].Reverse, "backs out");
            AreNear(new Vector2(33f, 19.6f), path[1].Point);
            AreNear(new Vector2(33f, 14.6f), path[2].Point, "east lane");
            AreNear(new Vector2(140f, 14.6f), path[3].Point);
        }

        [Test]
        public void Speed_RoadOnlyWhileBothEndsAreOnTheRoad()
        {
            WorldLayout.CarParkSettings c = _w.carPark;
            Assert.AreEqual(10f, CarRoute.Speed(12.3f, 12.3f, c, _e));
            Assert.AreEqual(3.4f, CarRoute.Speed(12.3f, 19.6f, c, _e), "turning into the lot");
            Assert.AreEqual(3.4f, CarRoute.Speed(19.6f, 14.6f, c, _e), "leaving the lot");
            Assert.AreEqual(10f, CarRoute.Speed(14.6f, 14.6f, c, _e));
        }

        [Test]
        public void Motion_DrivesTheWholeWayAndKeepsHeadingWhenReversing()
        {
            var m = new CarMotion();
            m.Place(CarRoute.Spawn(_w.carPark, _w.road), -Mathf.PI / 2f);
            CarRoute.Arrive(_w.carPark, _w.road, 2, m.Path);
            float time = 0f;
            while (!m.Arrived && time < 60f)
            {
                m.Step(0.05f, _w.carPark, _e);
                time += 0.05f;
            }
            Assert.IsTrue(m.Arrived, "parked");
            AreNear(new Vector2(16.7f, 22.6f), m.Position);
            // 107 m road at 10 m/s + 7.3 + 16.3 + 3 m in the lot at 3.4 m/s ≈ 18.6 s
            Assert.AreEqual(18.6f, time, 0.4f);
            Assert.AreEqual(0f, m.Face, 1e-4f, "nose toward +z (into the slot)");

            CarRoute.Depart(_w.carPark, _w.road, 2, m.Path);
            m.Step(0.05f, _w.carPark, _e);
            Assert.AreEqual(0f, m.Face, 1e-4f, "reversing keeps the heading");
            Assert.That(m.WheelTurn, Is.LessThan(0f), "wheels roll backwards");
        }

        [Test]
        public void LerpAngle_TakesTheShortWayRound()
        {
            float a = CarMotion.LerpAngle(Mathf.PI * 0.9f, -Mathf.PI * 0.9f, 0.5f);
            Assert.AreEqual(Mathf.PI, a, 1e-4f);
        }

        [Test]
        public void Driver_WalksOverTheZebraToTheDoorAndBack()
        {
            WorldLayout.CarParkSettings c = _w.carPark;
            Vector2 door = CarRoute.DriverDoor(c, 2);
            AreNear(new Vector2(17.85f, 22.6f), door, "beside the car");
            var way = new List<Vector2>();
            CarRoute.WalkToShop(c, door, _w.customerPaths.mainDoorOut.x, way);
            Assert.AreEqual(2, way.Count);
            AreNear(new Vector2(17.85f, 19.6f), way[0]);
            AreNear(new Vector2(20f, 18f), way[1], "in line with the zebra and the door");

            way.Clear();
            CarRoute.WalkToCar(c, door, _w.customerPaths.mainDoorOut.x, way);
            Assert.AreEqual(3, way.Count);
            AreNear(new Vector2(20f, 18f), way[0]);
            AreNear(new Vector2(17.85f, 19.6f), way[1]);
            AreNear(door, way[2]);
        }
    }
}
