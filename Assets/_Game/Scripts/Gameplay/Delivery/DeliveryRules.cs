using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Delivery
{
    /// <summary>What the chip over a truck bay says (prototype bay label in <c>setupLabels</c>).</summary>
    public enum BayTagKind
    {
        Hidden,
        /// <summary>"No truck": only on the first bay, before any truck is bought.</summary>
        NoTruck,
        /// <summary>"Arriving…": a truck holds the bay but is not parked (also while it pulls out, as in the prototype).</summary>
        Arriving,
        /// <summary>"n/8": a truck is parked and loading.</summary>
        Load,
        /// <summary>"Free · N s": the next truck comes back in N seconds.</summary>
        FreeIn,
        /// <summary>"Free": every truck is on the road or at another bay.</summary>
        Free,
    }

    /// <summary>Prototype bay rules: which bay a returning truck takes, the bay chip and the delivery payout.</summary>
    public static class DeliveryRules
    {
        /// <summary>First active bay without a truck (prototype <c>bays.find(b =&gt; b.active() &amp;&amp; !b.truck)</c>); −1 if none.</summary>
        public static int FreeBay(IReadOnlyList<TruckMotion> bayTrucks, int activeBays)
        {
            int n = Mathf.Min(activeBays, bayTrucks.Count);
            for (int i = 0; i < n; i++)
                if (bayTrucks[i] == null) return i;
            return -1;
        }

        /// <param name="bayTruck">The truck holding this bay, or null.</param>
        /// <param name="trucks">All owned trucks (for the "free in" countdown).</param>
        /// <param name="seconds">Countdown for <see cref="BayTagKind.FreeIn"/>.</param>
        public static BayTagKind BayTag(int bay, bool active, TruckMotion bayTruck, IReadOnlyList<TruckMotion> trucks, out int seconds)
        {
            seconds = 0;
            if (!active) return BayTagKind.Hidden;
            if (trucks.Count == 0) return bay == 0 ? BayTagKind.NoTruck : BayTagKind.Hidden;
            if (bayTruck != null) return bayTruck.Phase == TruckPhase.Docked ? BayTagKind.Load : BayTagKind.Arriving;

            // prototype: the away truck with the smallest timer
            TruckMotion next = null;
            for (int i = 0; i < trucks.Count; i++)
            {
                TruckMotion t = trucks[i];
                if (t.Phase == TruckPhase.Away && (next == null || t.Timer < next.Timer)) next = t;
            }
            if (next == null) return BayTagKind.Free;
            seconds = Mathf.Max(0, Mathf.CeilToInt(next.Timer));
            return BayTagKind.FreeIn;
        }

        /// <summary>Σ round(salePrice·1.4) over the bed (prototype <c>t.pay</c>), with the quality level and the Dream House bonus of the moment.</summary>
        public static long Payout(IReadOnlyList<ProductDef> cargo, EconomyConfig e, int qualityLevel, double homeMultiplier = 1.0)
        {
            long pay = 0;
            for (int i = 0; i < cargo.Count; i++) pay += e.TruckItemPayout(e.SalePrice(cargo[i].basePrice, qualityLevel, homeMultiplier));
            return pay;
        }

        /// <summary>Σ XP per sale over the bed (prototype <c>t.xp</c>).</summary>
        public static int PayoutXp(IReadOnlyList<ProductDef> cargo)
        {
            int xp = 0;
            for (int i = 0; i < cargo.Count; i++) xp += cargo[i].xpPerSale;
            return xp;
        }
    }
}
