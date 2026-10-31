using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor;
using FF.Gameplay.World;
using NUnit.Framework;
using UnityEditor;

namespace FF.Tests
{
    public sealed class BlockerSetTests
    {
        GameDatabase _db;

        [OneTimeSetUp]
        public void Load() => _db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

        static Aabb2D P(float x1, float x2, float z1, float z2) => ProtoCoords.ToUnityRect(x1, x2, z1, z2);

        [Test]
        public void NewGame_MatchesPrototypeRefreshBlocks()
        {
            // refreshBlocks() on a fresh save: shop lv 0 → w = 25; chair owned; register 0 active.
            var expected = new List<Aabb2D>
            {
                P(-12.7f, -7.3f, -12, -7.2f),
                P(2.75f, 3.05f, .4f, 9.85f), P(24.85f, 25.15f, .4f, 9.85f), P(2.75f, 17.95f, 9.55f, 9.85f), P(22.05f, 25.15f, 9.55f, 9.85f),
                P(71.85f, 72.15f, -26, -4), P(97.85f, 98.15f, -26, -4), P(72, 98, -26.15f, -25.85f), P(72, 82.6f, -4.15f, -3.85f), P(87.4f, 98, -4.15f, -3.85f),
                P(-4.7f, 0.7f, -12, -7.2f),
                P(22.2f - .62f, 22.2f + .62f, 3.5f - 1.55f, 3.5f + 1.55f),
            };
            var got = new List<Aabb2D>();
            BlockerSet.Build(_db.world, _db.economy, _db.products, WorldStateSnapshot.NewGame(_db.products), got);
            AssertRects(expected, got);
        }

        [Test]
        public void LateGame_AddsSawmill2_Plumbing_Factories_Registers()
        {
            var state = WorldStateSnapshot.NewGame(_db.products);
            state.ShopLevel = 5;
            state.MainRegisters = 6;
            state.OwnsSawmill2 = true;
            state.OwnsPlumbing = true;
            state.AnnexSecondRegister = true;
            foreach (ProductDef p in _db.products) state.OwnedProducts.Add(p.id);

            var got = new List<Aabb2D>();
            BlockerSet.Build(_db.world, _db.economy, _db.products, state, got);
            // saw1, saw2, 4 shop walls, 5 dream fence, 4 annex walls, 7 factories, 6 + 2 registers
            Assert.AreEqual(1 + 1 + 4 + 5 + 4 + 7 + 8, got.Count);
            Assert.Contains(P(45.85f, 46.15f, .4f, 9.85f), got); // right wall at 25 + 4.2*5 = 46
            Assert.Contains(P(-12.7f, -7.3f, -25.5f, -20.7f), got);
            // two-row layout: wardrobe in front, table and kitchen in the back row
            Assert.Contains(P(3.3f, 8.7f, -12, -7.2f), got);
            Assert.Contains(P(3.3f, 8.7f, -25.5f, -20.7f), got);
            Assert.Contains(P(11.3f, 16.7f, -25.5f, -20.7f), got);
        }

        static void AssertRects(List<Aabb2D> expected, List<Aabb2D> got)
        {
            Assert.AreEqual(expected.Count, got.Count, "blocker count");
            for (int i = 0; i < expected.Count; i++)
            {
                Assert.AreEqual(expected[i].MinX, got[i].MinX, 1e-4f, $"#{i} minX");
                Assert.AreEqual(expected[i].MaxX, got[i].MaxX, 1e-4f, $"#{i} maxX");
                Assert.AreEqual(expected[i].MinZ, got[i].MinZ, 1e-4f, $"#{i} minZ");
                Assert.AreEqual(expected[i].MaxZ, got[i].MaxZ, 1e-4f, $"#{i} maxZ");
            }
        }
    }
}
