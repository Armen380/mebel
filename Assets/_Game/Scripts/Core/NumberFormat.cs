using System;
using System.Globalization;
using System.Numerics;

namespace FF.Core
{
    /// <summary>
    /// Compact money/number format, an exact port of the prototype's <c>fmt()</c>:
    /// 999, 1.5K, 15K, 1.23M, 12.3M. JavaScript's <c>toFixed</c> rounding is reproduced exactly.
    /// </summary>
    public static class NumberFormat
    {
        public const string Dram = "֏";

        public static string Compact(double value) => Compact((long)Math.Floor(value));

        public static string Compact(long n)
        {
            if (n < 1000) return n.ToString(CultureInfo.InvariantCulture);
            if (n < 1_000_000)
            {
                // (n/1e3).toFixed(n<1e4?1:0).replace('.0','')+'K'
                string s = ToFixed(n, 1000, n < 10_000 ? 1 : 0);
                int i = s.IndexOf(".0", StringComparison.Ordinal);
                if (i >= 0) s = s.Remove(i, 2);
                return s + "K";
            }
            // (n/1e6).toFixed(n<1e7?2:1).replace(/\.?0+$/,'')+'M'
            return TrimTrailingZeros(ToFixed(n, 1_000_000, n < 10_000_000 ? 2 : 1)) + "M";
        }

        public static string Money(long n) => Compact(n) + " " + Dram;

        /// <summary>
        /// A cheap value that changes whenever <see cref="Compact(long)"/> may change: equal keys guarantee equal
        /// text. Lets per-frame UI (money counter, pad price) rebuild the string only when it can differ.
        /// Each range is cut into buckets at its rounding boundaries; boundary values get their own key.
        /// </summary>
        public static long CompactChangeKey(long n)
        {
            if (n < 1000) return n;
            int range;
            long step;
            if (n < 10_000) { range = 1; step = 50; }
            else if (n < 1_000_000) { range = 2; step = 500; }
            else if (n < 10_000_000) { range = 3; step = 5_000; }
            else { range = 4; step = 50_000; }
            long bucket = n / step * 2 + (n % step == 0 ? 1 : 0);
            return ((long)range << 48) | bucket;
        }

        static string TrimTrailingZeros(string s)
        {
            int dot = s.IndexOf('.');
            if (dot < 0) return s;
            int end = s.Length;
            while (end > dot + 1 && s[end - 1] == '0') end--;
            if (end == dot + 1) end = dot;
            return s.Substring(0, end);
        }

        /// <summary>
        /// JavaScript <c>(n / divisor).toFixed(digits)</c> for non-negative integers: the double quotient is
        /// rounded to the nearest representable decimal, ties going up, judged on the double's exact value.
        /// </summary>
        static string ToFixed(long n, long divisor, int digits)
        {
            long pow = 1;
            for (int i = 0; i < digits; i++) pow *= 10;

            BigInteger scaled = new BigInteger(n) * pow;
            BigInteger q = BigInteger.DivRem(scaled, divisor, out BigInteger rem);
            BigInteger twice = rem * 2;
            if (twice > divisor) q += 1;
            else if (twice == divisor && DoubleQuotientIsAboveOrEqual(n, divisor)) q += 1;

            string digitsStr = q.ToString(CultureInfo.InvariantCulture);
            if (digits == 0) return digitsStr;
            digitsStr = digitsStr.PadLeft(digits + 1, '0');
            return digitsStr.Substring(0, digitsStr.Length - digits) + "." + digitsStr.Substring(digitsStr.Length - digits);
        }

        /// <summary>True when the double nearest to n/divisor is ≥ the exact rational n/divisor.</summary>
        static bool DoubleQuotientIsAboveOrEqual(long n, long divisor)
        {
            double d = (double)n / divisor;
            long bits = BitConverter.DoubleToInt64Bits(d);
            int exp = (int)((bits >> 52) & 0x7FF);
            long mantissa = bits & 0xFFFFFFFFFFFFFL;
            if (exp == 0) exp = 1; else mantissa |= 1L << 52;
            exp -= 1075; // d = mantissa * 2^exp

            BigInteger lhs = new BigInteger(mantissa) * divisor; // d * divisor, scaled by 2^-exp
            BigInteger rhs = new BigInteger(n);
            if (exp >= 0) lhs <<= exp; else rhs <<= -exp;
            return lhs >= rhs;
        }
    }
}
