using FF.Core;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class ProtoCoordsTests
    {
        [Test]
        public void ToUnity_MirrorsZ()
        {
            Assert.AreEqual(new Vector3(-10f, 0f, 10f), ProtoCoords.ToUnity(-10f, -10f));
            Assert.AreEqual(new Vector3(1f, 2f, -3f), ProtoCoords.ToUnity(1f, 2f, 3f));
            Assert.AreEqual(new Vector3(20f, 0f, -11.4f), ProtoCoords.ToUnity(new Vector2(20f, 11.4f)));
            Assert.AreEqual(new Vector2(5f, -7f), ProtoCoords.ToUnityXZ(5f, 7f));
        }

        [Test]
        public void ToUnityRect_SwapsAndMirrorsZRange()
        {
            Aabb2D r = ProtoCoords.ToUnityRect(-12.7f, -7.3f, -12f, -7.2f);
            Assert.AreEqual(new Aabb2D(-12.7f, -7.3f, 7.2f, 12f), r);
        }

        [Test]
        public void NorthOfFence_IsPositiveUnityZ() => Assert.Greater(ProtoCoords.ToUnityZ(-13.6f), 0f);
    }
}
