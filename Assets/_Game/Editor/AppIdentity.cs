using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// App identity (M9, user decision 2026-11-05): "Furniture Factory", com.armen380.furniturefactory (iOS) / com.incode.furniturefactory (Android, 2026-11-09), company Armen380,
    /// version 1.0.0 (build 1); no Unity splash, launch background in the game's sky colour.
    /// Icon (user decision 2026-11-09): the user's artwork, cropped to <c>Art/AppIcon/AppIcon.png</c> (1024 px, source in
    /// Design/reference/app_icon). iOS and the default icon use it as it is; the Android adaptive icon gets it as the
    /// background layer, scaled into the 72/108 part launchers show (edge pixels stretched outward for the parallax margin),
    /// with an empty foreground — so the whole picture stays visible and the launcher mask only rounds its corners.
    /// </summary>
    public static class AppIdentity
    {
        public const string ProductName = "Furniture Factory";
        public const string CompanyName = "Armen380";
        /// <summary>Android package (Play Console app record, 2026-11-09) and iOS bundle id (user's choice for App Store Connect, 2026-11-10).</summary>
        public const string BundleId = "com.incode.furniturefactory";
        public const string Version = "1.0.1";
        /// <summary>Google Play needs a higher code on every upload: 1 = first internal test, 2 = privacy policy link (2026-11-09), 3 = 1.0.1.</summary>
        public const int AndroidVersionCode = 3;
        /// <summary>App Store Connect needs a new build number per upload: 1 = iPhone only, 2 = iPhone + iPad (2026-11-10), 3 = 1.0.1.</summary>
        public const string IosBuildNumber = "3";
        public const string AppleTeamId = "F83UUGVD8Y";
        const string Folder = "Assets/_Game/Art/AppIcon";
        const string ArtPath = Folder + "/AppIcon.png";
        const int Size = 1024;
        /// <summary>Adaptive icons: 108 dp layers, of which launchers show the middle 72 dp.</summary>
        const float AdaptiveVisible = 72f / 108f;
        static readonly Color Sky = new Color32(0xbf, 0xe3, 0xf0, 0xff);

        [MenuItem("FF/Setup App Identity", priority = 5)]
        public static void Setup()
        {
            PlayerSettings.productName = ProductName;
            PlayerSettings.companyName = CompanyName;
            PlayerSettings.bundleVersion = Version;
            PlayerSettings.Android.bundleVersionCode = AndroidVersionCode;
            PlayerSettings.iOS.buildNumber = IosBuildNumber;
            // the user's Apple developer team (already signed in to Xcode); Xcode manages profiles automatically
            PlayerSettings.iOS.appleDeveloperTeamID = AppleTeamId;
            PlayerSettings.iOS.appleEnableAutomaticSigning = true;
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.Android, BundleId);
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.iOS, BundleId);
            PlayerSettings.SetApplicationIdentifier(NamedBuildTarget.Standalone, BundleId);
            // iPhone and iPad (user decision 2026-11-10); full screen, so iPad multitasking does not resize the game
            PlayerSettings.iOS.targetDevice = iOSTargetDevice.iPhoneAndiPad;

            Texture2D full = Import(ArtPath, false);
            if (full == null)
            {
                Debug.LogError($"[FF] App icon missing: {ArtPath}");
                return;
            }
            Color[] art = ReadPixels(ArtPath);
            full = Write("AppIcon.png", art, false); // re-saved as RGB, no alpha
            Texture2D background = Write("AppIcon_Background.png", Adaptive(art), false);
            Texture2D foreground = Write("AppIcon_Foreground.png", new Color[Size * Size], true);
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
            Debug.Log($"[FF] App identity: {ProductName} {Version} ({BundleId}, iPhone + iPad), icon {ArtPath}, no splash.");
        }

        /// <summary>The art (any size, read straight from the PNG so import settings don't matter) resampled to Size².</summary>
        static Color[] ReadPixels(string path)
        {
            var tex = new Texture2D(2, 2, TextureFormat.RGBA32, false);
            tex.LoadImage(File.ReadAllBytes(path));
            var pixels = new Color[Size * Size];
            for (int y = 0; y < Size; y++)
            for (int x = 0; x < Size; x++)
            {
                Color c = tex.GetPixelBilinear((x + 0.5f) / Size, (y + 0.5f) / Size);
                c.a = 1f;
                pixels[y * Size + x] = c;
            }
            Object.DestroyImmediate(tex);
            return pixels;
        }

        /// <summary>
        /// Adaptive background: the art fills the visible 72/108 square; around it (seen only while launchers animate the
        /// icon) a blurred copy of the whole art, so no hard edge or streaks show.
        /// </summary>
        static Color[] Adaptive(Color[] art)
        {
            const int Blur = 24; // 1024 / 24 ≈ 43 px blocks, bilinear between them
            var small = new Texture2D(Blur, Blur, TextureFormat.RGBAFloat, false) { wrapMode = TextureWrapMode.Clamp, filterMode = FilterMode.Bilinear };
            var blocks = new Color[Blur * Blur];
            for (int y = 0; y < Size; y++)
            for (int x = 0; x < Size; x++)
                blocks[y * Blur / Size * Blur + x * Blur / Size] += art[y * Size + x];
            float perBlock = (float)Size * Size / (Blur * Blur);
            for (int i = 0; i < blocks.Length; i++) blocks[i] /= perBlock;
            small.SetPixels(blocks);
            small.Apply();

            var pixels = new Color[Size * Size];
            float inner = Size * AdaptiveVisible, offset = (Size - inner) * 0.5f;
            for (int y = 0; y < Size; y++)
            for (int x = 0; x < Size; x++)
            {
                float ix = x + 0.5f - offset, iy = y + 0.5f - offset;
                Color c;
                if (ix >= 0f && iy >= 0f && ix < inner && iy < inner)
                    c = art[Mathf.Min(Size - 1, (int)(iy / inner * Size)) * Size + Mathf.Min(Size - 1, (int)(ix / inner * Size))];
                else
                    c = small.GetPixelBilinear((x + 0.5f) / Size, (y + 0.5f) / Size) * 0.85f;
                c.a = 1f;
                pixels[y * Size + x] = c;
            }
            Object.DestroyImmediate(small);
            return pixels;
        }

        static Texture2D Write(string file, Color[] pixels, bool transparent)
        {
            string path = $"{Folder}/{file}";
            DataImporter.EnsureFolder(Folder);
            // App Store rejects icons with an alpha channel: opaque layers are saved as RGB
            var tex = new Texture2D(Size, Size, transparent ? TextureFormat.RGBA32 : TextureFormat.RGB24, false);
            tex.SetPixels(pixels);
            File.WriteAllBytes(path, tex.EncodeToPNG());
            Object.DestroyImmediate(tex);
            return Import(path, transparent);
        }

        static Texture2D Import(string path, bool transparent)
        {
            if (!File.Exists(path)) return null;
            AssetDatabase.ImportAsset(path);
            var importer = (TextureImporter)AssetImporter.GetAtPath(path);
            importer.textureType = TextureImporterType.Default;
            importer.mipmapEnabled = false;
            importer.alphaIsTransparency = transparent;
            importer.textureCompression = TextureImporterCompression.Uncompressed;
            importer.SaveAndReimport();
            return AssetDatabase.LoadAssetAtPath<Texture2D>(path);
        }
    }
}
