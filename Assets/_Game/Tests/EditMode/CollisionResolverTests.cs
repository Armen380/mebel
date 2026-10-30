using System.Collections.Generic;
using FF.Core;
using FF.Gameplay.Movement;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class CollisionResolverTests
    {
        static readonly List<Aabb2D> Box = new List<Aabb2D> { new Aabb2D(0, 4, 0, 2) };
        const float R = 0.3f;

        static Vector2 Push(float x, float z)
        {
            var p = new Vector2(x, z);
            CollisionResolver.PushOut(ref p, R, Box);
            return p;
        }

        [Test] public void Outside_Unchanged() => Assert.AreEqual(new Vector2(-1, 1), Push(-1, 1));
        [Test] public void OnExpandedEdge_Unchanged() => Assert.AreEqual(new Vector2(-0.3f, 1), Push(-0.3f, 1));
        [Test] public void West() => Assert.AreEqual(new Vector2(-0.3f, 1), Push(0.1f, 1));
        [Test] public void East() => Assert.AreEqual(new Vector2(4.3f, 1), Push(3.9f, 1));
        [Test] public void Near() => Assert.AreEqual(new Vector2(2, -0.3f), Push(2, 0.1f));
        [Test] public void Far() => Assert.AreEqual(new Vector2(2, 2.3f), Push(2, 1.9f));

        [Test]
        public void Corner_LeavesThroughNearestSide()
        {
            Vector2 p = Push(-0.2f, 0.05f); // 0.1 to the west edge, 0.35 to the near edge
            Assert.AreEqual(-0.3f, p.x, 1e-6f);
            Assert.AreEqual(0.05f, p.y, 1e-6f);
        }
    }
}
