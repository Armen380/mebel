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
