using System.Collections.Generic;
using FF.AI;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Zones;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>M6: carrier jobs, robot scoring, register assignment and back-row routes (prototype pickJob / robotJob / assignStaff).</summary>
    public sealed class WorkerTests
    {
        sealed class Pile : IPile
        {
            public int Count { get; set; }
            public int Settled { get; set; }
            public int Capacity { get; set; } = 10;
            public bool IsActive { get; set; } = true;
            public ItemType ItemType { get; set; }
            public Vector3 Position { get; set; }

            public Pile(ItemType type, int count, int capacity = 10, Vector3 at = default)
            {
                ItemType = type;
                Count = Settled = count;
                Capacity = capacity;
                Position = at;
            }
        }

        EconomyConfig _economy;
        WorldLayout _world;

        [SetUp]
        public void SetUp()
        {
            _economy = ScriptableObject.CreateInstance<EconomyConfig>();
            _world = ScriptableObject.CreateInstance<WorldLayout>();
        }

        [TearDown]
        public void TearDown()
        {
            Object.DestroyImmediate(_economy);
            Object.DestroyImmediate(_world);
        }

        static ProductionLine Line(string id, ItemType item, Pile output, Pile shelf, Pile input, bool busy = false, int inputPerCycle = 2) =>
            new ProductionLine
            {
                ProductId = id, ProductNameKey = "p." + id, InputType = ItemType.Plank, InputPerCycle = inputPerCycle,
                Input = input, Output = output, Shelf = shelf, MachineBusy = () => busy,
            };

        // ---------- carrier (pickJob) ----------

        [Test]
        public void Carrier_TakesGoodsFromTheFullestOutput_ToItsShelf()
        {
            var chairOut = new Pile(ItemType.Chair, 2);
            var sofaOut = new Pile(ItemType.Sofa, 5);
            var chairShelf = new Pile(ItemType.Chair, 0, 8);
            var sofaShelf = new Pile(ItemType.Sofa, 3, 8);
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, chairOut, chairShelf, new Pile(ItemType.Plank, 0, 24)),
                Line("sofa", ItemType.Sofa, sofaOut, sofaShelf, new Pile(ItemType.Plank, 0, 24)),
            };
            WorkerJob job = CarrierJobs.Pick(lines, new List<IPile>(), false, new List<ProductionLine>());
            Assert.AreSame(sofaOut, job.From);
            Assert.AreSame(sofaShelf, job.To);
        }

        [Test]
        public void Carrier_SkipsFullShelves_ThenCarriesPlanksToTheEmptiestInput()
        {
            var chairOut = new Pile(ItemType.Chair, 4);
            var fullShelf = new Pile(ItemType.Chair, 8, 8);
            var chairIn = new Pile(ItemType.Plank, 12, 24);
            var sofaIn = new Pile(ItemType.Plank, 3, 24);
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, chairOut, fullShelf, chairIn),
                Line("sofa", ItemType.Sofa, new Pile(ItemType.Sofa, 0), new Pile(ItemType.Sofa, 0, 8), sofaIn),
            };
            var sawOut = new Pile(ItemType.Plank, 6, 30);
            WorkerJob job = CarrierJobs.Pick(lines, new List<IPile> { new Pile(ItemType.Plank, 2, 30), sawOut }, false, new List<ProductionLine>());
            Assert.AreSame(sawOut, job.From, "fullest sawmill output");
            Assert.AreSame(sofaIn, job.To, "emptiest plank input");
        }

        [Test]
        public void Stocker_ShelvesOnly()
        {
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, new Pile(ItemType.Chair, 0), new Pile(ItemType.Chair, 0, 8), new Pile(ItemType.Plank, 0, 24)),
            };
            Assert.IsNull(CarrierJobs.Pick(lines, new List<IPile> { new Pile(ItemType.Plank, 6, 30) }, true, new List<ProductionLine>()));
        }

        [Test]
        public void SawInput_IsTheEmptiestWorkingOne()
        {
            var saw1 = new Pile(ItemType.Log, 5, 24);
            var saw2 = new Pile(ItemType.Log, 2, 24) { IsActive = false };
            Assert.AreSame(saw1, CarrierJobs.SawInput(new List<IPile> { saw1, saw2 }));
            saw2.IsActive = true;
            Assert.AreSame(saw2, CarrierJobs.SawInput(new List<IPile> { saw1, saw2 }));
        }

        [Test]
        public void PlankTarget_NoneWhenEveryInputIsFull()
        {
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, new Pile(ItemType.Chair, 0), new Pile(ItemType.Chair, 0, 8), new Pile(ItemType.Plank, 24, 24)),
            };
            Assert.IsNull(CarrierJobs.PlankTarget(lines));
        }

        // ---------- robot (robotJob) ----------

        [Test]
        public void Robot_PrefersTheEmptyShelfWithWaitingCustomers()
        {
            var chairOut = new Pile(ItemType.Chair, 3, 12);
            var sofaOut = new Pile(ItemType.Sofa, 3, 12);
            var chairShelf = new Pile(ItemType.Chair, 6, 8);
            var sofaShelf = new Pile(ItemType.Sofa, 0, 8);
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, chairOut, chairShelf, new Pile(ItemType.Plank, 20, 24)),
                Line("sofa", ItemType.Sofa, sofaOut, sofaShelf, new Pile(ItemType.Plank, 20, 24)),
            };
            WorkerJob job = RobotScoring.Best(Vector3.zero, lines, new List<IPile>(), p => p == sofaShelf ? 2 : 0, p => 0, _economy);
            Assert.AreSame(sofaShelf, job.To);
            Assert.AreEqual(JobLabel.Shelf, job.Label);
            Assert.IsTrue(job.Urgent);
            // (1 − 0/8) + 2·1.5 + 1 (empty) + 0 (output 25 %) − 0 = 5
            Assert.AreEqual(5f, job.Score, 1e-4f);
            Assert.AreEqual(8, job.Want);
        }

        [Test]
        public void Robot_StarvingFactoryGetsPlanks_AndOtherRobotsLowerTheScore()
        {
            var chairIn = new Pile(ItemType.Plank, 0, 24);
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, new Pile(ItemType.Chair, 0, 12), new Pile(ItemType.Chair, 0, 8), chairIn),
            };
            var sawOut = new Pile(ItemType.Plank, 10, 30);
            WorkerJob job = RobotScoring.Best(Vector3.zero, lines, new List<IPile> { sawOut }, p => 0, p => 0, _economy);
            Assert.AreSame(chairIn, job.To);
            Assert.AreEqual(JobLabel.Planks, job.Label);
            Assert.AreEqual(1.2f + 1.6f, job.Score, 1e-4f, "(1 − 0)·1.2 + starving 1.6");

            WorkerJob shared = RobotScoring.Best(Vector3.zero, lines, new List<IPile> { sawOut }, p => 0, p => 1, _economy);
            Assert.AreEqual(1.2f + 1.6f - 0.9f, shared.Score, 1e-4f);
        }

        [Test]
        public void Robot_DistanceCostsAndLowScoresAreIgnored()
        {
            var chairShelf = new Pile(ItemType.Chair, 7, 8);
            var lines = new List<ProductionLine>
            {
                Line("chair", ItemType.Chair, new Pile(ItemType.Chair, 1, 12, new Vector3(60, 0, 0)), chairShelf, new Pile(ItemType.Plank, 24, 24)),
            };
            // (1 − 7/8) = 0.125, − 60/60 → below 0.15
            Assert.IsNull(RobotScoring.Best(Vector3.zero, lines, new List<IPile>(), p => 0, p => 0, _economy));
        }

        // ---------- cashiers (assignStaff) ----------

        [Test]
        public void Cashiers_TakeRegistersInPrototypeOrder()
        {
            var active = new List<bool> { true, true, true, false, false, false, false, false };
            var assigned = new int[4];
            StaffAssignment.AssignCashiers(active, 4, assigned);
            CollectionAssert.AreEqual(new[] { 0, 1, 2, -1 }, assigned);

            active[6] = true;
            StaffAssignment.AssignCashiers(active, 2, assigned);
            Assert.AreEqual(0, assigned[0]);
            Assert.AreEqual(6, assigned[1], "materials-shop register comes second");
        }

        // ---------- routes ----------

        [Test]
        public void BackRowTrips_GoThroughTheNearestGap()
        {
            var via = new List<Vector3>();
            WorldLayout.WorkerLayoutSettings s = _world.workers;
            // front chair output (1.7, −5.3) → sofa input in the back row (−3.7, −18.8)
            WorkerRoutes.Via(new Vector3(1.7f, 0, 5.3f), new Vector3(-3.7f, 0, 18.8f), s, _world.fenceLineZ, via);
            Assert.AreEqual(2, via.Count);
            // trip midpoint x −1 → nearest gap x 2; front side first, then the back side
            Assert.That(Vector3.Distance(new Vector3(2f, 0, 6.2f), via[0]), Is.LessThan(1e-4f));
            Assert.That(Vector3.Distance(new Vector3(2f, 0, 14.4f), via[1]), Is.LessThan(1e-4f));
        }

        [Test]
        public void FrontYardTrips_GoStraight()
        {
            var via = new List<Vector3>();
            WorkerRoutes.Via(new Vector3(-8.3f, 0, 5.3f), new Vector3(-3.7f, 0, 5.3f), _world.workers, _world.fenceLineZ, via);
            Assert.IsEmpty(via);
        }

        [Test]
        public void Motor_ArrivesWithin6cm()
        {
            var go = new GameObject("agent", typeof(CharacterRig), typeof(CharacterAnimator));
            try
            {
                var anim = go.GetComponent<CharacterAnimator>();
                Assert.IsFalse(AgentMotor.MoveTo(go.transform, anim, new Vector3(1, 0, 0), 0.1f, 3f));
                Assert.That(go.transform.position.x, Is.EqualTo(0.3f).Within(1e-5f));
                Assert.IsTrue(AgentMotor.MoveTo(go.transform, anim, new Vector3(0.35f, 0, 0), 0.1f, 3f));
                Assert.AreEqual(180f, AgentMotor.YawFromPrototype(0f), 1e-4f);
            }
            finally
            {
                Object.DestroyImmediate(go);
            }
        }
    }
}
