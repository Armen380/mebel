using FF.Core;
using NUnit.Framework;

namespace FF.Tests
{
    /// <summary>Ads rework (user decision 2026-11-08): interstitial every 3 levels, one centered offer per cooldown.</summary>
    public sealed class AdScheduleTests
    {
        const float Gap = 120f, Delay = 60f;

        static bool Can(int level, float now, float lastAd = float.NegativeInfinity, bool menu = false, bool tutorialDone = true,
            bool showing = false) =>
            InterstitialRules.CanShow(level, 3, menu, tutorialDone, showing, now, 0f, Delay, lastAd, Gap);

        [Test]
        public void Interstitial_EveryThirdLevel()
        {
            Assert.IsFalse(InterstitialRules.IsAdLevel(0, 3));
            Assert.IsFalse(InterstitialRules.IsAdLevel(2, 3));
            Assert.IsTrue(InterstitialRules.IsAdLevel(3, 3));
            Assert.IsFalse(InterstitialRules.IsAdLevel(4, 3));
            Assert.IsTrue(InterstitialRules.IsAdLevel(282, 3));
            Assert.IsFalse(InterstitialRules.IsAdLevel(3, 0));
        }

        [Test]
        public void Interstitial_BlockedInMenuTutorialOrWhileAnotherAdShows()
        {
            Assert.IsTrue(Can(6, 500f));
            Assert.IsFalse(Can(6, 500f, menu: true));
            Assert.IsFalse(Can(6, 500f, tutorialDone: false));
            Assert.IsFalse(Can(6, 500f, showing: true));
            Assert.IsFalse(Can(7, 500f));
        }

        [Test]
        public void Interstitial_WaitsAfterSessionStartAndAfterAnyAd()
        {
            Assert.IsFalse(Can(3, 59f));
            Assert.IsTrue(Can(3, 60f));
            Assert.IsFalse(Can(3, 300f, lastAd: 200f));
            Assert.IsTrue(Can(3, 320f, lastAd: 200f));
        }

        [Test]
        public void Offer_NothingWithoutAdOrWhenBlockedOrCoolingDown()
        {
            Assert.AreEqual(AdOfferRules.Offer.None, AdOfferRules.Pick(false, false, 400f, 300f, -1f));
            Assert.AreEqual(AdOfferRules.Offer.None, AdOfferRules.Pick(true, true, 400f, 300f, -1f));
            Assert.AreEqual(AdOfferRules.Offer.None, AdOfferRules.Pick(true, false, 299f, 300f, 305f));
        }

        [Test]
        public void Offer_DoubleRightAfterATruckOtherwiseCash()
        {
            Assert.AreEqual(AdOfferRules.Offer.DoublePayout, AdOfferRules.Pick(true, false, 400f, 300f, 405f));
            Assert.AreEqual(AdOfferRules.Offer.Cash, AdOfferRules.Pick(true, false, 400f, 300f, 399f));
            Assert.AreEqual(AdOfferRules.Offer.Cash, AdOfferRules.Pick(true, false, 300f, 300f, -1f));
        }

        [Test]
        public void AdClock_BeginEnd()
        {
            AdClock.Reset();
            Assert.IsFalse(AdClock.Showing);
            AdClock.Begin();
            Assert.IsTrue(AdClock.Showing);
            AdClock.End(42f);
            Assert.IsFalse(AdClock.Showing);
            Assert.AreEqual(42f, AdClock.LastEndedAt);
            AdClock.Reset();
        }
    }
}
