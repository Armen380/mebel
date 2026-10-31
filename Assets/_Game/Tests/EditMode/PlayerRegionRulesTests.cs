using System;
using FF.Core;
using FF.Data;
using FF.Gameplay.Movement;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class PlayerRegionRulesTests
    {
        WorldLayout _layout;
        PlayerRegionRules _rules;

        [SetUp]
        public void SetUp()
        {
            _layout = ScriptableObject.CreateInstance<WorldLayout>();
            _rules = new PlayerRegionRules(_layout.playerBounds);
        }

        [TearDown]
        public void TearDown() => UnityEngine.Object.DestroyImmediate(_layout);

        // Factory back yard: the prototype's sawmill yard (x −18.2…−1.8, split at 15) widened for the user's two-row
        // factory layout (2026-10-31): x −18.2…20.2, split halfway to the mines yard.
        const float YardMinX = -18.2f, YardMaxX = 20.2f, SplitX = (20.5f + 34.4f) / 2f;

        /// <summary>Port of the prototype's collide() region part (prototype coordinates) with the widened back yard.</summary>
        static void PrototypeCollide(ref float x, ref float z, bool sink)
        {
            x = Mathf.Clamp(x, -31.5f, 100f);
            z = Mathf.Clamp(z, -39.4f, 25.6f);
            if (z < -13.2f && x >= 62) { if (z < -25.6f) z = -25.6f; }
            else if (z < -13.2f)
            {
                if (x <= SplitX && z < -27.2f) z = -27.2f;
                if (x > SplitX && z < -24.6f) z = -24.6f;
                bool sk = x > SplitX, ok = !sk || sink;
                float a = sk ? 34.4f : YardMinX, b = sk ? 59.6f : YardMaxX;
                if (!ok) z = -13.2f;
                else if (x < a || x > b) { if (z > -13.9f) z = -13.2f; else x = Mathf.Clamp(x, a, b); }
            }
        }

        Vector2 ApplyProto(float protoX, float protoZ, bool minesOpen)
        {
            Vector2 p = ProtoCoords.ToUnityXZ(protoX, protoZ);
            _rules.Apply(ref p, minesOpen);
            return new Vector2(p.x, -p.y); // back to proto for readable asserts
        }

        [Test]
        public void MatchesPrototype_OnRandomPoints([Values(false, true)] bool minesOpen)
        {
            var rng = new System.Random(42);
            for (int i = 0; i < 20000; i++)
            {
                float x = (float)(rng.NextDouble() * 150 - 40);
                float z = (float)(rng.NextDouble() * 80 - 50);
                float ex = x, ez = z;
                PrototypeCollide(ref ex, ref ez, minesOpen);
                Vector2 got = ApplyProto(x, z, minesOpen);
                Assert.AreEqual(ex, got.x, 1e-4f, $"x for ({x}, {z})");
                Assert.AreEqual(ez, got.y, 1e-4f, $"z for ({x}, {z})");
            }
        }

        [Test] public void FrontYard_Free() => Assert.AreEqual(new Vector2(10, 0), ApplyProto(10, 0, false));
        [Test] public void InFenceGap_PushedBackToFence() => Assert.AreEqual(-13.2f, ApplyProto(25, -13.5f, false).y, 1e-5f);
        [Test] public void DeepBehindFence_SlidesToBackYardWall() => Assert.AreEqual(new Vector2(20.2f, -20), ApplyProto(25, -20, false));
        [Test] public void SawBackYard_Allowed() => Assert.AreEqual(new Vector2(-10, -20), ApplyProto(-10, -20, false));
        [Test] public void BackRowFactories_Reachable() => Assert.AreEqual(new Vector2(14, -18.8f), ApplyProto(14, -18.8f, false));
        [Test] public void MinesYard_ClosedWithoutPlumbing() => Assert.AreEqual(-13.2f, ApplyProto(45, -20, false).y, 1e-5f);
        [Test] public void MinesYard_OpenWithPlumbing() => Assert.AreEqual(new Vector2(45, -20), ApplyProto(45, -20, true));
        [Test] public void DreamPlot_Allowed() => Assert.AreEqual(new Vector2(85, -20), ApplyProto(85, -20, false));
        [Test] public void DreamPlot_BackLimit() => Assert.AreEqual(-25.6f, ApplyProto(85, -30, false).y, 1e-5f);
    }
}
