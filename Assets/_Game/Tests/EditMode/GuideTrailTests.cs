using FF.Gameplay.Tutorial;
using NUnit.Framework;

namespace FF.Tests
{
    /// <summary>Update 1.0.1 floor arrows: placement along the player → target line.</summary>
    public sealed class GuideTrailTests
    {
        static int Build(float toX, float toZ, float phase, GuideMark[] into, out float yaw) =>
            GuideTrailLayout.Build(0f, 0f, toX, toZ, phase, 1f, 1f, 1f, 0.5f, into, out yaw);

        [Test]
        public void ArrowsEverySpacing_BetweenTheGaps_PointingAtTheTarget()
        {
            var marks = new GuideMark[20];
            int n = Build(0f, 6f, 0f, marks, out float yaw);
            Assert.AreEqual(4, n, "d = 1, 2, 3, 4 (end at 6 − 1 = 5, exclusive)");
            Assert.AreEqual(0f, yaw, 1e-4f, "+Z");
            Assert.AreEqual(1f, marks[0].Z, 1e-4f);
            Assert.AreEqual(4f, marks[3].Z, 1e-4f);
            Assert.AreEqual(0f, marks[0].Scale, 1e-4f, "grows in from the start gap");
            Assert.AreEqual(1f, marks[1].Scale, 1e-4f);
        }

        [Test]
        public void PhaseSlidesTheArrowsAndWraps()
        {
            var marks = new GuideMark[20];
            Build(0f, 6f, 0.25f, marks, out _);
            Assert.AreEqual(1.25f, marks[0].Z, 1e-4f);
            Build(0f, 6f, 1.25f, marks, out _);
            Assert.AreEqual(1.25f, marks[0].Z, 1e-4f, "phase wraps at the spacing");
        }

        [Test]
        public void YawFollowsTheDirection()
        {
            var marks = new GuideMark[20];
            Build(5f, 0f, 0f, marks, out float east);
            Assert.AreEqual(90f, east, 1e-3f);
            Build(0f, -5f, 0f, marks, out float south);
            Assert.AreEqual(180f, System.Math.Abs(south), 1e-3f);
        }

        [Test]
        public void NothingWhenTheTargetIsClose_AndThePoolCapsTheCount()
        {
            var marks = new GuideMark[20];
            Assert.AreEqual(0, Build(0f, 1.5f, 0f, marks, out _));
            var few = new GuideMark[3];
            Assert.AreEqual(3, Build(0f, 50f, 0f, few, out _));
        }
    }
}
