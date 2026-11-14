using System.IO;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Art
{
    /// <summary>
    /// Small generated textures that replace the prototype's canvas drawing: UI circle and pill sprites, the
    /// trash icon of the Throw button and the dashed ground markers of zones (<c>drawGround</c>). Saved as PNG
    /// once; delete a file to regenerate it.
    /// </summary>
    public static class TextureFactory
    {
        public const string UiFolder = "Assets/_Game/Art/UI";
        public const string TextureFolder = "Assets/_Game/Art/Textures";

        public static Sprite Circle() => Sprite($"{UiFolder}/Circle.png", 256, Vector4.zero, (x, y, s) =>
        {
            float r = s / 2f, d = Vector2.Distance(new Vector2(x + 0.5f, y + 0.5f), new Vector2(r, r));
            return new Color(1, 1, 1, Mathf.Clamp01(r - d));
        });

        /// <summary>
        /// Large anti-aliased disc for the virtual joystick (1.0.1: the built-in 16 px "Knob" sprite stretched to 330 px
        /// looked pixelated and lumpy — user report 2026-11-10).
        /// </summary>
        public static Sprite JoystickCircle() => Sprite($"{UiFolder}/JoystickCircle.png", 512, Vector4.zero, (x, y, s) =>
        {
            float r = s / 2f - 1f, c = s / 2f, d = Vector2.Distance(new Vector2(x + 0.5f, y + 0.5f), new Vector2(c, c));
            return new Color(1, 1, 1, Mathf.Clamp01((r - d) / 1.5f + 0.5f));
        });

        /// <summary>Prototype <c>.menu</c> backdrop: transparent down to 35 % of the height, then to 50 % black (tinted by the Image).</summary>
        public static Sprite VerticalFade() => Sprite($"{UiFolder}/VerticalFade.png", 64, Vector4.zero, (x, y, s) =>
        {
            float fromTop = 1f - (y + 0.5f) / s;
            return new Color(1, 1, 1, fromTop < 0.35f ? 0f : (fromTop - 0.35f) / 0.65f * 0.5f);
        });

        /// <summary>Inner ring of the skin swatch (CSS inset 3 px on a 46 px circle).</summary>
        public static Sprite Ring() => Sprite($"{UiFolder}/Ring.png", 256, Vector4.zero, (x, y, s) =>
        {
            float r = s / 2f, d = Vector2.Distance(new Vector2(x + 0.5f, y + 0.5f), new Vector2(r, r));
            float width = s * 3f / 46f;
            return new Color(1, 1, 1, Mathf.Clamp01(r - d) * Mathf.Clamp01(d - (r - width)));
        });

        /// <summary>Fully rounded 9-sliced pill (prototype <c>.chip</c>, border-radius 999px).</summary>
        public static Sprite Pill() => Sprite($"{UiFolder}/Pill.png", 64, new Vector4(31, 31, 31, 31),
            (x, y, s) => new Color(1, 1, 1, Mathf.Clamp01(-RoundedRectSdf(x + 0.5f, y + 0.5f, s, s, 0, s / 2f) + 0.5f)));

        /// <summary>Trash icon of the Throw button (prototype SVG, 24×24 viewBox, stroke 2.2, round caps).</summary>
        public static Sprite TrashIcon()
        {
            // M4 7h16  M9 7V4.5h6V7  M6.5 7l1 13h9l1-13  M10 11v5  M14 11v5
            Vector2[][] paths =
            {
                new[] { new Vector2(4, 7), new Vector2(20, 7) },
                new[] { new Vector2(9, 7), new Vector2(9, 4.5f), new Vector2(15, 4.5f), new Vector2(15, 7) },
                new[] { new Vector2(6.5f, 7), new Vector2(7.5f, 20), new Vector2(16.5f, 20), new Vector2(17.5f, 7) },
                new[] { new Vector2(10, 11), new Vector2(10, 16) },
                new[] { new Vector2(14, 11), new Vector2(14, 16) },
            };
            const float halfStroke = 1.1f;
            return Sprite($"{UiFolder}/IconTrash.png", 128, Vector4.zero, (x, y, s) =>
            {
                float scale = 24f / s;
                // texture rows grow upward, SVG rows grow downward
                var p = new Vector2((x + 0.5f) * scale, (s - y - 0.5f) * scale);
                float d = float.MaxValue;
                foreach (Vector2[] path in paths)
                    for (int i = 0; i + 1 < path.Length; i++)
                        d = Mathf.Min(d, SegmentDistance(p, path[i], path[i + 1]));
                return new Color(1, 1, 1, Mathf.Clamp01((halfStroke - d) / scale + 0.5f));
            });
        }

        /// <summary>Rounded 9-sliced panel (radius 16 px at 64 px) for toast, quest bar and buttons.</summary>
        public static Sprite Rounded() => Sprite($"{UiFolder}/Rounded.png", 64, new Vector4(20, 20, 20, 20),
            (x, y, s) => new Color(1, 1, 1, Mathf.Clamp01(-RoundedRectSdf(x + 0.5f, y + 0.5f, s, s, 0, 16) + 0.5f)));

        /// <summary>Money coin (prototype <c>.coin</c>): honey radial gradient with a faint inner ring.</summary>
        public static Sprite Coin() => Sprite($"{UiFolder}/Coin.png", 128, Vector4.zero, (x, y, s) =>
        {
            float r = s / 2f;
            var p = new Vector2(x + 0.5f, y + 0.5f);
            float d = Vector2.Distance(p, new Vector2(r, r));
            // radial-gradient(circle at 35% 30%, #ffe7a3, honey 55%, honey-d)
            var focus = new Vector2(0.35f * s, (1 - 0.3f) * s);
            float t = Vector2.Distance(p, focus) / (s * 0.85f);
            Color light = new Color32(0xff, 0xe7, 0xa3, 0xff), honey = new Color32(0xf3, 0xb3, 0x3d, 0xff), dark = new Color32(0xc4, 0x86, 0x1a, 0xff);
            Color c = t < 0.55f ? Color.Lerp(light, honey, t / 0.55f) : Color.Lerp(honey, dark, Mathf.Clamp01((t - 0.55f) / 0.45f));
            float ring = r - d < 3f * s / 32f ? 0.15f : 0f; // inset 0 0 0 3px rgba(43,29,20,.15) at 32 px
            c = Color.Lerp(c, new Color32(0x2b, 0x1d, 0x14, 0xff), ring);
            c.a = Mathf.Clamp01(r - d);
            return c;
        });

        /// <summary>
        /// Line icon from the prototype's inline SVGs (24×24 viewBox, round caps): bubbles show the wanted product,
        /// the cash icon or the angry face. Drawn white; the UI tints it.
        /// </summary>
        public static Sprite LineIcon(string name, float strokeWidth, params Vector2[][] paths)
        {
            float half = strokeWidth / 2f;
            return Sprite($"{UiFolder}/Icon_{name}.png", 96, Vector4.zero, (x, y, s) =>
            {
                float scale = 24f / s;
                var p = new Vector2((x + 0.5f) * scale, (s - y - 0.5f) * scale);
                float d = float.MaxValue;
                foreach (Vector2[] path in paths)
                    for (int i = 0; i + 1 < path.Length; i++)
                        d = Mathf.Min(d, SegmentDistance(p, path[i], path[i + 1]));
                return new Color(1, 1, 1, Mathf.Clamp01((half - d) / scale + 0.5f));
            });
        }

        public static Vector2[] Poly(params float[] xy)
        {
            var pts = new Vector2[xy.Length / 2];
            for (int i = 0; i < pts.Length; i++) pts[i] = new Vector2(xy[2 * i], xy[2 * i + 1]);
            return pts;
        }

        public static Vector2[] Closed(params float[] xy)
        {
            Vector2[] open = Poly(xy);
            var pts = new Vector2[open.Length + 1];
            open.CopyTo(pts, 0);
            pts[open.Length] = open[0];
            return pts;
        }

        public static Vector2[] Circle(float cx, float cy, float r, int segments = 48)
        {
            var pts = new Vector2[segments + 1];
            for (int i = 0; i <= segments; i++)
            {
                float a = i * Mathf.PI * 2f / segments;
                pts[i] = new Vector2(cx + Mathf.Cos(a) * r, cy + Mathf.Sin(a) * r);
            }
            return pts;
        }

        public static Vector2[] RoundRect(float x, float y, float w, float h, float r, int arcSegments = 6)
        {
            var pts = new System.Collections.Generic.List<Vector2>();
            void Arc(float cx, float cy, float from)
            {
                for (int i = 0; i <= arcSegments; i++)
                {
                    float a = from + i * Mathf.PI / 2f / arcSegments;
                    pts.Add(new Vector2(cx + Mathf.Cos(a) * r, cy + Mathf.Sin(a) * r));
                }
            }
            Arc(x + w - r, y + r, -Mathf.PI / 2f);
            Arc(x + w - r, y + h - r, 0f);
            Arc(x + r, y + h - r, Mathf.PI / 2f);
            Arc(x + r, y + r, Mathf.PI);
            pts.Add(pts[0]);
            return pts.ToArray();
        }

        public static Vector2[] Cubic(Vector2 a, Vector2 c1, Vector2 c2, Vector2 b, int segments = 16)
        {
            var pts = new Vector2[segments + 1];
            for (int i = 0; i <= segments; i++)
            {
                float t = i / (float)segments, u = 1 - t;
                pts[i] = u * u * u * a + 3 * u * u * t * c1 + 3 * u * t * t * c2 + t * t * t * b;
            }
            return pts;
        }

        /// <summary>
        /// Upgrade pad layers (prototype <c>drawPad</c>, 256 px canvas, rounded square 10..246 with radius 44):
        /// "Base" honey fill, "Fill" green fill (shown from the bottom by the paid share), "Stroke" white outline 8 px.
        /// </summary>
        public static Texture2D PadLayer(string layer)
        {
            Color honey = new Color(196 / 255f, 134 / 255f, 26 / 255f, 0.95f), green = new Color(61 / 255f, 138 / 255f, 49 / 255f, 0.9f);
            return Texture($"{TextureFolder}/Pad_{layer}.png", 256, (x, y, s) =>
            {
                float sdf = RoundedRectSdf(x + 0.5f - 10, y + 0.5f - 10, 236, 236, 0, 44);
                switch (layer)
                {
                    case "Base": { Color c = honey; c.a *= Mathf.Clamp01(0.5f - sdf); return c; }
                    case "Fill": { Color c = green; c.a *= Mathf.Clamp01(0.5f - sdf); return c; }
                    default: return new Color(1, 1, 1, 0.9f * Mathf.Clamp01(0.5f - (Mathf.Abs(sdf) - 4f)));
                }
            });
        }

        /// <summary>
        /// Zone ground marker (prototype <c>drawGround</c>): tinted rounded square 228 px with radius 46 on a
        /// 256 px canvas and a dashed white outline (10 px, dash 26 / gap 16). The ↓ / ↑ glyph is drawn in (Noto Sans
        /// has no arrows); <paramref name="arrow"/> = −1 down, +1 up, 0 none. The label is a separate TMP text.
        /// </summary>
        public static Texture2D ZoneMarker(string name, Color tint, int arrow)
        {
            const int size = 256;
            const float x0 = 14, side = 228, radius = 46, stroke = 10, dash = 26, gap = 16;
            // glyph centred at canvas y 106 (prototype fillText(glyph, 128, 106)), ~80 px tall, heavy stroke
            const float arrowHalf = 40, arrowHead = 30, arrowStroke = 7.5f;
            var tip = new Vector2(128, 106 - arrow * arrowHalf);
            var tail = new Vector2(128, 106 + arrow * arrowHalf);
            var headL = new Vector2(128 - arrowHead, tip.y + arrow * arrowHead);
            var headR = new Vector2(128 + arrowHead, tip.y + arrow * arrowHead);
            return Texture($"{TextureFolder}/ZoneMarker_{name}.png", size, (x, y, s) =>
            {
                // canvas coordinates: origin top-left
                float cx = x + 0.5f, cy = s - y - 0.5f;
                float sdf = RoundedRectSdf(cx - x0, cy - x0, side, side, 0, radius);
                Color fill = tint;
                fill.a *= Mathf.Clamp01(0.5f - sdf);
                float edge = Mathf.Abs(sdf) - stroke / 2f;
                float onStroke = Mathf.Clamp01(0.5f - edge);
                if (onStroke > 0f)
                {
                    float along = Mathf.Repeat(PerimeterPosition(cx - x0, cy - x0, side, radius), dash + gap);
                    float inDash = Mathf.Clamp01(Mathf.Min(along, dash - along) + 0.5f);
                    onStroke *= inDash;
                }
                Color white = new Color(1, 1, 1, 0.95f * onStroke);
                Color c = Over(white, fill);
                if (arrow != 0)
                {
                    var p = new Vector2(cx, cy);
                    float d = Mathf.Min(SegmentDistance(p, tail, tip), Mathf.Min(SegmentDistance(p, tip, headL), SegmentDistance(p, tip, headR)));
                    c = Over(new Color(1, 1, 1, Mathf.Clamp01(arrowStroke - d + 0.5f)), c);
                }
                return c;
            });
        }

        // ---------- drawing helpers ----------

        static float SegmentDistance(Vector2 p, Vector2 a, Vector2 b)
        {
            Vector2 ab = b - a;
            float t = Mathf.Clamp01(Vector2.Dot(p - a, ab) / Vector2.Dot(ab, ab));
            return Vector2.Distance(p, a + ab * t);
        }

        /// <summary>Signed distance to a rounded rectangle [0,w]×[0,h] (negative inside).</summary>
        static float RoundedRectSdf(float x, float y, float w, float h, float inset, float r)
        {
            float hx = w / 2f - inset, hy = h / 2f - inset;
            float px = Mathf.Abs(x - w / 2f) - (hx - r), py = Mathf.Abs(y - h / 2f) - (hy - r);
            float outside = new Vector2(Mathf.Max(px, 0), Mathf.Max(py, 0)).magnitude;
            return outside + Mathf.Min(Mathf.Max(px, py), 0) - r;
        }

        /// <summary>Arc-length position of the nearest outline point, clockwise from the top edge start.</summary>
        static float PerimeterPosition(float x, float y, float side, float r)
        {
            float straight = side - 2 * r, arc = Mathf.PI / 2f * r;
            float lo = r, hi = side - r;
            float qx = Mathf.Clamp(x, lo, hi), qy = Mathf.Clamp(y, lo, hi);
            bool cornerX = x < lo || x > hi, cornerY = y < lo || y > hi;
            if (cornerX && cornerY)
            {
                float a = Mathf.Atan2(y - qy, x - qx); // canvas: y down, so clockwise = increasing angle
                if (x > hi && y < lo) return straight + arc * ((a + Mathf.PI / 2f) / (Mathf.PI / 2f));                   // top-right
                if (x > hi && y > hi) return 2 * straight + arc + arc * (a / (Mathf.PI / 2f));                             // bottom-right
                if (x < lo && y > hi) return 3 * straight + 2 * arc + arc * ((a - Mathf.PI / 2f) / (Mathf.PI / 2f));      // bottom-left
                return 4 * straight + 3 * arc + arc * (Mathf.Repeat(a + Mathf.PI, 2 * Mathf.PI) / (Mathf.PI / 2f));      // top-left
            }
            // nearest straight edge
            float dTop = y - 0, dRight = side - x, dBottom = side - y, dLeft = x;
            float m = Mathf.Min(Mathf.Min(dTop, dRight), Mathf.Min(dBottom, dLeft));
            if (m == dTop) return qx - lo;
            if (m == dRight) return straight + arc + (qy - lo);
            if (m == dBottom) return 2 * (straight + arc) + (hi - qx);
            return 3 * (straight + arc) + (hi - qy);
        }

        static Color Over(Color top, Color bottom)
        {
            float a = top.a + bottom.a * (1 - top.a);
            if (a <= 0f) return new Color(0, 0, 0, 0);
            Color c = (top * top.a + bottom * bottom.a * (1 - top.a)) / a;
            c.a = a;
            return c;
        }

        // ---------- Dream House (M10) ----------

        static Color C(int rgb) => new Color(((rgb >> 16) & 255) / 255f, ((rgb >> 8) & 255) / 255f, (rgb & 255) / 255f, 1f);

        /// <summary>
        /// Armenian-style carpet patterns (256 px, geometric medallions and borders): vishap (red field, navy border, gold
        /// diamonds), garden (green compartments with red flowers), star (navy field, red border, gold eight-point star).
        /// </summary>
        public static Texture2D CarpetTexture(string id) => Texture($"{TextureFolder}/Carpet_{id}.png", 256, (x, y, s) =>
        {
            float u = (x + 0.5f) / s, v = (y + 0.5f) / s;
            float edge = Mathf.Min(Mathf.Min(u, 1 - u), Mathf.Min(v, 1 - v));
            float cu = u - 0.5f, cv = v - 0.5f;
            switch (id)
            {
                case "carpet_garden":
                {
                    if (edge < 0.06f) return C(0xb3263a);
                    if (edge < 0.075f) return C(0xf2c14e);
                    float gu = Mathf.Repeat((u - 0.075f) * 4f, 1f), gv = Mathf.Repeat((v - 0.075f) * 4f, 1f);
                    if (gu < 0.06f || gv < 0.06f) return C(0xf6ecd9);
                    float fd = Vector2.Distance(new Vector2(gu, gv), new Vector2(0.53f, 0.53f));
                    if (fd < 0.12f) return C(0xb3263a);
                    if (fd < 0.2f && Mathf.Abs(gu - 0.53f) < 0.04f) return C(0x2f5e36);
                    return C(0x3f7d4a);
                }
                case "carpet_star":
                {
                    if (edge < 0.08f) return Mathf.Repeat((u + v) * 14f, 1f) < 0.5f ? C(0xb3263a) : C(0x8c1d2d);
                    if (edge < 0.095f) return C(0xf2c14e);
                    float a = Mathf.Abs(cu) + Mathf.Abs(cv), b = Mathf.Max(Mathf.Abs(cu), Mathf.Abs(cv));
                    if (a < 0.3f && b < 0.21f) return a < 0.12f ? C(0xb3263a) : C(0xf2c14e);
                    float corner = Mathf.Abs(Mathf.Abs(cu) - 0.32f) + Mathf.Abs(Mathf.Abs(cv) - 0.32f);
                    if (corner < 0.06f) return C(0xf2c14e);
                    return C(0x23345e);
                }
                default: // carpet_vishap
                {
                    if (edge < 0.07f) return Mathf.Repeat(Mathf.Abs(u - v) * 18f, 1f) < 0.3f ? C(0xf2c14e) : C(0x1f3a6b);
                    if (edge < 0.085f) return C(0xf6ecd9);
                    for (int i = -1; i <= 1; i++)
                    {
                        float d = Mathf.Abs(cu - i * 0.26f) * 1.3f + Mathf.Abs(cv);
                        if (d < 0.08f) return C(0xa82c2a);
                        if (d < 0.14f) return C(0x1f3a6b);
                        if (d < 0.2f) return C(0xf2c14e);
                    }
                    if (Mathf.Repeat(u * 9f, 1f) < 0.08f && Mathf.Repeat(v * 9f, 1f) < 0.08f) return C(0xf6ecd9);
                    return C(0xa82c2a);
                }
            }
        });

        /// <summary>Small canvases for the house paintings (128 px): Mount Ararat (Masis and Sis) and the Garni temple.</summary>
        public static Texture2D PaintingTexture(string id) => Texture($"{TextureFolder}/Painting_{id}.png", 128, (x, y, s) =>
        {
            float u = (x + 0.5f) / s, v = (y + 0.5f) / s;
            Color sky = Color.Lerp(C(0xf7d9a8), C(0x7fb3e0), v);
            if (id == "painting_garni")
            {
                if (v < 0.22f) return C(0x6f9a3e);
                if (v < 0.28f && u > 0.18f && u < 0.82f) return C(0xd9c7a6);
                if (v >= 0.28f && v < 0.62f && u > 0.24f && u < 0.76f && Mathf.Repeat((u - 0.24f) * 12.5f, 1f) < 0.55f) return C(0xeadcc1);
                if (v >= 0.62f && v < 0.67f && u > 0.2f && u < 0.8f) return C(0xd9c7a6);
                if (v >= 0.67f && v < 0.67f + 0.2f * (1 - Mathf.Abs(u - 0.5f) / 0.3f)) return C(0xeadcc1);
                return v < 0.4f ? Color.Lerp(C(0x8bb35a), sky, (v - 0.22f) * 3f) : sky;
            }
            // Ararat: Masis on the left, Sis on the right, snow above 0.6
            float masis = 0.78f - Mathf.Abs(u - 0.38f) * 1.5f, sis = 0.55f - Mathf.Abs(u - 0.78f) * 1.6f;
            if (v < 0.18f) return C(0x6f9a3e);
            if (v < masis) return v > 0.6f ? C(0xffffff) : C(0x8b6f8e);
            if (v < sis) return v > 0.47f ? C(0xf1eef4) : C(0x9a7f9c);
            return sky;
        });

        /// <summary>Home Store catalog / variant picker icons (M10), one per item group, in the product-icon line style.</summary>
        public static Sprite HomeIcon(string group)
        {
            const float w = 2.1f;
            switch (group)
            {
                case "carpet": return LineIcon("home_" + group, w, Closed(3, 7, 21, 7, 21, 17, 3, 17), Closed(7, 10, 17, 10, 17, 14, 7, 14), Poly(5, 17, 5, 20), Poly(9, 17, 9, 20), Poly(15, 17, 15, 20), Poly(19, 17, 19, 20));
                case "lamp": return LineIcon("home_" + group, w, Closed(8, 4, 16, 4, 18, 11, 6, 11), Poly(12, 11, 12, 19), Poly(8, 20, 16, 20));
                case "tv": return LineIcon("home_" + group, w, RoundRect(3, 5, 18, 12, 1.5f), Poly(12, 17, 12, 20), Poly(8, 20, 16, 20));
                case "painting": return LineIcon("home_" + group, w, Closed(4, 5, 20, 5, 20, 19, 4, 19), Poly(6, 16, 11, 9, 14, 13, 16, 11, 18, 16));
                case "plant": return LineIcon("home_" + group, w, Closed(8, 14, 16, 14, 15, 20, 9, 20), Poly(12, 14, 12, 6), Poly(12, 11, 8, 7), Poly(12, 9, 16, 5));
                case "fridge": return LineIcon("home_" + group, w, Closed(7, 3, 17, 3, 17, 21, 7, 21), Poly(7, 9, 17, 9), Poly(9.5f, 5, 9.5f, 7), Poly(9.5f, 11, 9.5f, 14));
                case "stove": return LineIcon("home_" + group, w, Closed(4, 8, 20, 8, 20, 20, 4, 20), Circle(9, 14, 2.5f, 16), Circle(15, 14, 2.5f, 16), Poly(6, 5, 18, 5));
                case "bowl": return LineIcon("home_" + group, w, Poly(4, 12, 20, 12), Poly(5, 12, 8, 18, 16, 18, 19, 12), Circle(9, 9, 2.4f, 16), Circle(14.5f, 8.5f, 2.4f, 16));
                case "bed": return LineIcon("home_" + group, w, Poly(3, 19, 3, 7), Poly(3, 14, 21, 14, 21, 19), Closed(5, 10, 10, 10, 10, 14, 5, 14), Poly(10, 11, 21, 11, 21, 14));
                case "nightstand": return LineIcon("home_" + group, w, Closed(6, 8, 18, 8, 18, 19, 6, 19), Poly(6, 13.5f, 18, 13.5f), Poly(11, 10.5f, 13, 10.5f), Poly(11, 16, 13, 16));
                case "tub": return LineIcon("home_" + group, w, Poly(3, 11, 21, 11), Poly(4, 11, 5, 17, 19, 17, 20, 11), Poly(6, 17, 6, 20), Poly(18, 17, 18, 20), Poly(6, 11, 6, 5, 9, 5));
                case "mirror": return LineIcon("home_" + group, w, RoundRect(7, 3, 10, 18, 4), Poly(10, 9, 13, 6), Poly(10, 12, 15, 7));
                case "towel": return LineIcon("home_" + group, w, Poly(4, 5, 20, 5), Closed(7, 5, 17, 5, 17, 19, 7, 19), Poly(7, 15, 17, 15));
                case "pergola": return LineIcon("home_" + group, w, Poly(5, 21, 5, 7), Poly(19, 21, 19, 7), Poly(3, 7, 21, 7), Poly(4, 10, 20, 10), Circle(10.5f, 13.5f, 1.5f, 12), Circle(13.5f, 13.5f, 1.5f, 12), Circle(12, 16, 1.5f, 12));
                case "tree": return LineIcon("home_" + group, w, Circle(12, 9, 6, 32), Poly(12, 15, 12, 21), Circle(10, 8, 1.2f, 10), Circle(14.5f, 10, 1.2f, 10));
                case "flowers": return LineIcon("home_" + group, w, Poly(4, 19, 20, 19), Poly(8, 19, 8, 12), Poly(12, 19, 12, 10), Poly(16, 19, 16, 12), Circle(8, 10, 2, 12), Circle(12, 8, 2, 12), Circle(16, 10, 2, 12));
                case "bench": return LineIcon("home_" + group, w, Poly(4, 7, 20, 7), Poly(4, 10, 20, 10), Poly(3, 13, 21, 13), Poly(5, 7, 5, 19), Poly(19, 7, 19, 19));
                case "fountain": return LineIcon("home_" + group, w, Poly(4, 14, 6, 19, 18, 19, 20, 14, 4, 14), Poly(12, 14, 12, 8), Poly(8, 8, 16, 8), Poly(9, 4, 9, 6), Poly(15, 4, 15, 6), Poly(12, 2.5f, 12, 4.5f));
                case "pool": return LineIcon("home_" + group, w, RoundRect(3, 8, 18, 12, 2), Poly(6, 14, 8, 13, 10, 14, 12, 13, 14, 14, 16, 13, 18, 14), Poly(16, 4, 16, 10), Poly(19, 4, 19, 10), Poly(16, 6, 19, 6));
                case "lampposts": return LineIcon("home_" + group, w, Poly(8, 21, 8, 7), Poly(16, 21, 16, 7), Closed(6, 3, 10, 3, 10, 7, 6, 7), Closed(14, 3, 18, 3, 18, 7, 14, 7));
                default:
                    Debug.LogWarning($"[FF] No home icon for group '{group}'.");
                    return null;
            }
        }

        // ---------- assets ----------

        delegate Color Pixel(int x, int y, int size);

        static Sprite Sprite(string path, int size, Vector4 border, Pixel pixel)
        {
            Write(path, size, pixel, out bool created);
            if (created)
            {
                var importer = (TextureImporter)AssetImporter.GetAtPath(path);
                importer.textureType = TextureImporterType.Sprite;
                importer.spriteImportMode = SpriteImportMode.Single;
                importer.spriteBorder = border;
                importer.alphaIsTransparency = true;
                importer.mipmapEnabled = false;
                importer.wrapMode = TextureWrapMode.Clamp;
                importer.SaveAndReimport();
            }
            return AssetDatabase.LoadAssetAtPath<Sprite>(path);
        }

        static Texture2D Texture(string path, int size, Pixel pixel)
        {
            Write(path, size, pixel, out bool created);
            if (created)
            {
                var importer = (TextureImporter)AssetImporter.GetAtPath(path);
                importer.textureType = TextureImporterType.Default;
                importer.alphaIsTransparency = true;
                importer.mipmapEnabled = true;
                importer.wrapMode = TextureWrapMode.Clamp;
                importer.anisoLevel = 4;
                importer.SaveAndReimport();
            }
            return AssetDatabase.LoadAssetAtPath<Texture2D>(path);
        }

        static void Write(string path, int size, Pixel pixel, out bool created)
        {
            created = !File.Exists(path);
            if (!created) return;
            DataImporter.EnsureFolder(Path.GetDirectoryName(path).Replace('\\', '/'));
            var tex = new Texture2D(size, size, TextureFormat.RGBA32, false);
            var pixels = new Color[size * size];
            for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                pixels[y * size + x] = pixel(x, y, size);
            tex.SetPixels(pixels);
            File.WriteAllBytes(path, tex.EncodeToPNG());
            Object.DestroyImmediate(tex);
            AssetDatabase.ImportAsset(path);
        }
    }
}
