using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// App identity (M9, user decision 2026-11-05): "Furniture Factory", com.armen380.furniturefactory, company Armen380,
    /// version 1.0.0 (build 1); a generated icon in the game's palette (honey background, walnut low-poly chair) for every
    /// platform plus the Android adaptive layers; no Unity splash, launch background in the game's sky colour.
    /// </summary>
    public static class AppIdentity
    {
        public const string ProductName = "Furniture Factory";
        public const string CompanyName = "Armen380";
        public const string BundleId = "com.armen380.furniturefactory";
        public const string Version = "1.0.0";
        const string Folder = "Assets/_Game/Art/AppIcon";
        static readonly Color Honey = new Color32(0xf3, 0xb3, 0x3d, 0xff);
        static readonly Color HoneyDark = new Color32(0xc4, 0x86, 0x1a, 0xff);
        static readonly Color Walnut = new Color32(0x2b, 0x1d, 0x14, 0xff);
        static readonly Color Wood = new Color32(0xa0, 0x62, 0x2f, 0xff);
        static readonly Color WoodLight = new Color32(0xd9, 0xa0, 0x66, 0xff);
        static readonly Color Sky = new Color32(0xbf, 0xe3, 0xf0, 0xff);

        [MenuItem("FF/Setup App Identity", priority = 5)]
        public static void Setup()
        {
            PlayerSettings.productName = ProductName;
            PlayerSettings.companyName = CompanyName;
            PlayerSettings.bundleVersion = Version;
            PlayerSettings.Android.bundleVersionCode = 1;
            PlayerSettings.iOS.buildNumber = "1";
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.Android, BundleId);
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.iOS, BundleId);
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.Standalone, BundleId);

            Texture2D full = Icon("AppIcon.png", true, 1f);
            Texture2D background = Icon("AppIcon_Background.png", false, 1f);
            Texture2D foreground = Icon("AppIcon_Foreground.png", true, 0.62f, transparent: true);
            PlayerSettings.SetIcons(NamedBuildTarget.Unknown, new[] { full }, IconKind.Any);
            PlatformIcon[] adaptive = PlayerSettings.GetPlatformIcons(NamedBuildTarget.Android, UnityEditor.Android.AndroidPlatformIconKind.Adaptive);
            foreach (PlatformIcon icon in adaptive)
            {
                icon.SetTexture(background, 0);
                icon.SetTexture(foreground, 1);
            }
            PlayerSettings.SetPlatformIcons(NamedBuildTarget.Android, UnityEditor.Android.AndroidPlatformIconKind.Adaptive, adaptive);
            PlayerSettings.SplashScreen.show = false;
            PlayerSettings.SplashScreen.showUnityLogo = false;
            PlayerSettings.SplashScreen.backgroundColor = Sky;
            PlayerSettings.Android.splashScreenScale = AndroidSplashScreenScale.Center;
            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] App identity: {ProductName} {Version} ({BundleId}), icons in {Folder}, no splash.");
        }

        /// <summary>1024 px icon: honey background with a darker ring, walnut-outlined wooden chair.</summary>
        static Texture2D Icon(string file, bool chair, float scale, bool transparent = false)
        {
            string path = $"{Folder}/{file}";
            const int size = 1024;
            DataImporter.EnsureFolder(Folder);
            var tex = new Texture2D(size, size, TextureFormat.RGBA32, false);
            var pixels = new Color[size * size];
            for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
            {
                // normalised coordinates, origin at the centre, +y up, chair drawn in a 1×1 box scaled by "scale"
                float u = (x + 0.5f) / size - 0.5f, v = (y + 0.5f) / size - 0.5f;
                Color c = transparent ? new Color(0, 0, 0, 0) : Background(u, v);
                if (chair)
                {
                    Color top = Chair(u / scale, v / scale, size * scale);
                    c = Color.Lerp(c, new Color(top.r, top.g, top.b, 1f), top.a);
                    if (transparent) c.a = Mathf.Max(c.a, top.a);
                }
                pixels[y * size + x] = c;
            }
            tex.SetPixels(pixels);
            File.WriteAllBytes(path, tex.EncodeToPNG());
            Object.DestroyImmediate(tex);
            AssetDatabase.ImportAsset(path);
            var importer = (TextureImporter)AssetImporter.GetAtPath(path);
            importer.textureType = TextureImporterType.Default;
            importer.mipmapEnabled = false;
            importer.alphaIsTransparency = transparent;
            importer.textureCompression = TextureImporterCompression.Uncompressed;
            importer.SaveAndReimport();
            return AssetDatabase.LoadAssetAtPath<Texture2D>(path);
        }

        static Color Background(float u, float v)
        {
            float r = Mathf.Sqrt(u * u + v * v);
            // soft darker ring behind the chair
            float ring = Mathf.Clamp01((0.36f - r) * 200f) * 0.25f;
            return Color.Lerp(Honey, HoneyDark, ring);
        }

        /// <summary>Low-poly chair like the game's item: back, seat, four legs; walnut outline, two wood tones.</summary>
        static Color Chair(float u, float v, float pixels)
        {
            float aa = 1.5f / pixels;
            float outline = 0.022f;
            // parts: (centre x, centre y, half w, half h, colour)
            (float cx, float cy, float hw, float hh, Color col)[] parts =
            {
                (-0.08f, -0.21f, 0.03f, 0.12f, Wood),    // back legs, then front legs (painted over by the seat)
                (0.08f, -0.21f, 0.03f, 0.12f, Wood),
                (-0.2f, -0.24f, 0.035f, 0.15f, Wood),
                (0.2f, -0.24f, 0.035f, 0.15f, Wood),
                (0f, 0.17f, 0.2f, 0.17f, Wood),          // back
                (0f, -0.04f, 0.26f, 0.06f, WoodLight),   // seat
            };
            float bestOutline = 0f;
            Color fill = new Color(Walnut.r, Walnut.g, Walnut.b, 0f);
            foreach ((float cx, float cy, float hw, float hh, Color col) in parts)
            {
                float d = Box(u - cx, v - cy, hw, hh);
                float inside = Mathf.Clamp01(0.5f - d / aa);
                float edge = Mathf.Clamp01(0.5f - (d - outline) / aa);
                bestOutline = Mathf.Max(bestOutline, edge);
                // a later part covers the earlier ones, its outline included
                if (edge > 0f && inside < 1f) fill = Color.Lerp(fill, Walnut, edge - inside);
                if (inside > 0f) fill = Color.Lerp(fill, col, inside);
                fill.a = Mathf.Max(fill.a, edge);
            }
            // back slats: two walnut stripes across the back
            foreach (float sy in new[] { 0.12f, 0.22f })
            {
                float d = Box(u, v - sy, 0.17f, 0.012f);
                float s = Mathf.Clamp01(0.5f - d / aa);
                if (s > 0f) fill = Color.Lerp(fill, Walnut, s * 0.8f);
            }
            fill.a = Mathf.Max(bestOutline, fill.a);
            return fill;
        }

        static float Box(float x, float y, float hw, float hh)
        {
            float dx = Mathf.Abs(x) - hw, dy = Mathf.Abs(y) - hh;
            return new Vector2(Mathf.Max(dx, 0f), Mathf.Max(dy, 0f)).magnitude + Mathf.Min(Mathf.Max(dx, dy), 0f);
        }
    }
}
