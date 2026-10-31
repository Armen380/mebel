using System;

namespace FF.Core
{
    /// <summary>JavaScript-compatible math used by the prototype formulas.</summary>
    public static class JsMath
    {
        /// <summary>JavaScript <c>Math.round</c>: halves round toward +∞ (C# rounds to even).</summary>
        public static double Round(double x) => Math.Floor(x + 0.5);

        public static long RoundToLong(double x) => (long)Math.Floor(x + 0.5);
    }
}
