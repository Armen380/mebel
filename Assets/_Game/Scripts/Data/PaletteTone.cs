using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// Colour grade of the flat world colours (update 1.0.1, user 2026-11-10: "bright, saturated, pleasant and
    /// attractive, like every game of this kind" — a muted first try was rejected). Key surfaces get hand-picked
    /// replacements, everything else a saturation / brightness grade. Applied by the Editor tools to the lit palette
    /// materials; the palette keys keep the prototype colours. No runtime cost.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Palette Tone", fileName = "PaletteTone")]
    public sealed class PaletteTone : ScriptableObject
    {
        [Tooltip("Saturation multiplier (1 = prototype colours).")]
        [Range(0f, 1.5f)] public float saturation = 0.8f;
        [Tooltip("Brightness multiplier for the brightest colours; dark colours are left almost as they are.")]
        [Range(0.5f, 1.2f)] public float highlights = 0.92f;
        [Tooltip("How far to tint toward the warm colour (0 = none, 1 = multiplied by it).")]
        [Range(0f, 1f)] public float warmth = 0.15f;
        public Color warmColor = new Color(1f, 0.93f, 0.8f);

        [Serializable]
        public struct Override
        {
            public Color32 from;
            public Color32 to;
        }

        [Tooltip("Hand-picked replacements for the big surfaces (grass, paving, road…), used as they are.")]
        public List<Override> overrides = new List<Override>();

        /// <summary>The toned colour of a prototype palette colour.</summary>
        public Color Apply(Color32 key)
        {
            for (int i = 0; i < overrides.Count; i++)
            {
                Color32 f = overrides[i].from;
                if (f.r == key.r && f.g == key.g && f.b == key.b) return (Color)overrides[i].to;
            }
            Color c = key;
            Color.RGBToHSV(c, out float h, out float s, out float v);
            s = Mathf.Clamp01(s * saturation);
            v = Mathf.Clamp01(v * Mathf.Lerp(1f, highlights, v * v));
            Color o = Color.HSVToRGB(h, s, v);
            o = Color.Lerp(o, o * warmColor, warmth);
            o.a = c.a;
            return o;
        }
    }
}
