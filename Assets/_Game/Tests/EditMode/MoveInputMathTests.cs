using FF.Gameplay.Input;
using NUnit.Framework;
using UnityEngine;

namespace FF.Tests
{
    public sealed class MoveInputMathTests
    {
        [Test] public void Sum_UnderOne_Kept() => Assert.AreEqual(new Vector2(0.3f, 0.4f), MoveInputMath.Combine(new Vector2(0.3f, 0), new Vector2(0, 0.4f)));

        [Test]
        public void Sum_OverOne_Normalised()
        {
            Vector2 v = MoveInputMath.Combine(Vector2.zero, new Vector2(1, 1));
            Assert.AreEqual(1f, v.magnitude, 1e-5f);
            Assert.AreEqual(v.x, v.y, 1e-6f);
        }

        [Test] public void DeadZone_Inactive() => Assert.IsFalse(MoveInputMath.IsActive(new Vector2(0.1f, 0.05f)));
        [Test] public void AboveDeadZone_Active() => Assert.IsTrue(MoveInputMath.IsActive(new Vector2(0.13f, 0)));
    }
}
