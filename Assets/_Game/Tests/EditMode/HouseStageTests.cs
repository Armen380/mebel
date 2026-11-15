using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.Movement;
using FF.Gameplay.Pads;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;

namespace FF.Tests
{
    /// <summary>Dream House stages (M10): stage pads, world state, house walls and the Home Store blocker.</summary>
    public sealed class HouseStageTests
    {
        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        List<Aabb2D> Blockers(int stage)
        {
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            state.HouseStage = stage;
            var got = new List<Aabb2D>();
            BlockerSet.Build(_db.world, _db.economy, _db.products, state, got);
            return got;
        }

        static bool Inside(Vector2 p, Aabb2D r) => p.x > r.MinX && p.x < r.MaxX && p.y > r.MinZ && p.y < r.MaxZ;

        [Test]
        public void HouseStage_CountsLeadingStagePads()
        {
            var progress = new GameProgress(_db.economy);
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(_db.products);
            WorldStateSync.Apply(state, progress);
            Assert.AreEqual(0, state.HouseStage);
            progress.Pad("house_found").Level = 1;
            progress.Pad("house_roof").Level = 1;
            WorldStateSync.Apply(state, progress);
            Assert.AreEqual(1, state.HouseStage, "walls missing: the roof does not count");
            progress.Pad("house_walls").Level = 1;
            progress.Pad("house_windows").Level = 1;
            WorldStateSync.Apply(state, progress);
            Assert.AreEqual(4, state.HouseStage);
            CollectionAssert.AreEqual(new[] { "house_found", "house_walls", "house_roof", "house_windows" }, WorldStateSnapshot.HouseStagePads);
        }

        [Test]
        public void HouseWalls_OnlyFromWallsStage()
        {
            int before = Blockers(1).Count;
            int walls = _db.world.blockers.houseWalls.Length;
            Assert.AreEqual(11, walls);
            Assert.AreEqual(before + walls, Blockers(2).Count);
            Assert.AreEqual(Blockers(2).Count, Blockers(4).Count);
        }

        [Test]
        public void HomeStore_BlocksFromFoundation()
        {
            ProtoRect s = _db.world.dreamHouse.homeStore;
            Aabb2D store = ProtoCoords.ToUnityRect(s.x1, s.x2, s.z1, s.z2);
            CollectionAssert.DoesNotContain(Blockers(0), store);
            CollectionAssert.Contains(Blockers(1), store);
        }

        [Test]
        public void HouseWalls_DoorGapIsWalkable()
        {
            List<Aabb2D> blockers = Blockers(4);
            float r = _db.world.playerBounds.collisionRadius;
            foreach (Vector2 door in _db.world.dreamHouse.houseDoorways)
            {
                Vector3 u = ProtoCoords.ToUnity(door.x, door.y);
                var p = new Vector2(u.x, u.z);
                Vector2 before = p;
                CollisionResolver.PushOut(ref p, r, blockers);
                Assert.AreEqual(before.x, p.x, 1e-4f, $"door {door} pushes the player (x)");
                Assert.AreEqual(before.y, p.y, 1e-4f, $"door {door} pushes the player (z)");
            }
        }

        [Test]
        public void HouseWalls_PlayerInsideAWallIsPushedOut()
        {
            List<Aabb2D> blockers = Blockers(2);
            float r = _db.world.playerBounds.collisionRadius;
            Vector3 u = ProtoCoords.ToUnity(84f, -13f); // middle of the front-right wall
            var p = new Vector2(u.x, u.z);
            CollisionResolver.PushOut(ref p, r, blockers);
            foreach (Aabb2D b in blockers) Assert.IsFalse(Inside(p, b), $"still inside {b}");
        }

        [Test]
        public void Cutaway_FromWallsStage()
        {
            Assert.IsFalse(FF.Gameplay.Home.HouseCutaway.ShouldCut(1, true), "no walls yet");
            Assert.IsTrue(FF.Gameplay.Home.HouseCutaway.ShouldCut(2, true), "the front wall hides the player at stage 2");
            Assert.IsTrue(FF.Gameplay.Home.HouseCutaway.ShouldCut(4, true));
            Assert.IsFalse(FF.Gameplay.Home.HouseCutaway.ShouldCut(4, false));
        }

        [Test]
        public void AfterPad_VisibleOnlyAfterPrevious()
        {
            Assert.IsTrue(PadRules.IsVisible(PadRule.AfterPad, 0, 1, true, 1, 0, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.AfterPad, 0, 1, false, 1, 0, 0, 0));
            Assert.IsFalse(PadRules.IsVisible(PadRule.AfterPad, 1, 1, true, 1, 0, 0, 0), "built");
        }
    }
}
