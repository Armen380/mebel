using System.Collections.Generic;
using FF.Data;
using UnityEditor;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// Builds <c>Data/AudioLibrary.asset</c> from <c>Audio/Sfx</c> and <c>Audio/Music</c> (see Audio/CREDITS.md) and sets
    /// mobile import settings: effects mono, decompressed on load; music and ambience streamed (Vorbis).
    /// </summary>
    public static class AudioLibraryBuilder
    {
        public const string LibraryPath = "Assets/_Game/Data/AudioLibrary.asset";
        const string Sfx = "Assets/_Game/Audio/Sfx/", Music = "Assets/_Game/Audio/Music/";

        // id, files, volume, pitch jitter, cooldown
        static readonly (FF.Data.Sfx id, string[] files, float volume, float jitter, float cooldown)[] Table =
        {
            (FF.Data.Sfx.Coin, new[] { "coin" }, 0.45f, 0.06f, 0.05f),
            (FF.Data.Sfx.Payout, new[] { "payout" }, 0.7f, 0.03f, 0.3f),
            (FF.Data.Sfx.Chop, new[] { "chop_0", "chop_1", "chop_2" }, 0.55f, 0.06f, 0.1f),
            (FF.Data.Sfx.Mine, new[] { "mine_0", "mine_1", "mine_2" }, 0.5f, 0.06f, 0.1f),
            (FF.Data.Sfx.Quest, new[] { "quest" }, 0.6f, 0f, 0.2f),
            (FF.Data.Sfx.Purchase, new[] { "purchase" }, 0.55f, 0f, 0.15f),
            (FF.Data.Sfx.LevelUp, new[] { "levelup" }, 0.6f, 0f, 0.5f),
            (FF.Data.Sfx.Throw, new[] { "throw" }, 0.6f, 0.05f, 0.2f),
            (FF.Data.Sfx.CarDoor, new[] { "car_door" }, 0.3f, 0.08f, 0.4f),
            (FF.Data.Sfx.DoorBell, new[] { "door_bell" }, 0.25f, 0.05f, 0.6f),
            (FF.Data.Sfx.Click, new[] { "click" }, 0.5f, 0.03f, 0.03f),
            (FF.Data.Sfx.TruckPass, new string[0], 0.35f, 0.04f, 1.5f),
        };

        [MenuItem("FF/Build Audio Library", priority = 26)]
        public static AudioLibrary Build()
        {
            var lib = AssetDatabase.LoadAssetAtPath<AudioLibrary>(LibraryPath);
            if (lib == null)
            {
                lib = ScriptableObject.CreateInstance<AudioLibrary>();
                AssetDatabase.CreateAsset(lib, LibraryPath);
            }
            lib.entries = new List<AudioLibrary.Entry>();
            foreach ((FF.Data.Sfx id, string[] files, float volume, float jitter, float cooldown) in Table)
            {
                var clips = new List<AudioClip>();
                foreach (string f in files)
                {
                    string path = Sfx + f + ".ogg";
                    Import(path, false);
                    AudioClip clip = AssetDatabase.LoadAssetAtPath<AudioClip>(path);
                    if (clip != null) clips.Add(clip);
                    else Debug.LogWarning($"[FF] Missing sound {path}");
                }
                lib.entries.Add(new AudioLibrary.Entry { id = id, clips = clips.ToArray(), volume = volume, pitchJitter = jitter, cooldown = cooldown });
            }
            string music = Music + "music_happy_clappy.wav", ambient = Music + "ambient_birds.ogg";
            Import(music, true);
            Import(ambient, true);
            lib.music = AssetDatabase.LoadAssetAtPath<AudioClip>(music);
            lib.ambient = AssetDatabase.LoadAssetAtPath<AudioClip>(ambient);
            EditorUtility.SetDirty(lib);
            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] Audio library: {lib.entries.Count} sounds, music {(lib.music != null)}, ambience {(lib.ambient != null)}.");
            return lib;
        }

        static void Import(string path, bool loop)
        {
            if (!(AssetImporter.GetAtPath(path) is AudioImporter importer)) return;
            importer.forceToMono = !loop;
            importer.loadInBackground = loop;
            AudioImporterSampleSettings s = importer.defaultSampleSettings;
            s.loadType = loop ? AudioClipLoadType.Streaming : AudioClipLoadType.DecompressOnLoad;
            s.compressionFormat = AudioCompressionFormat.Vorbis;
            s.quality = loop ? 0.45f : 0.6f;
            s.sampleRateSetting = AudioSampleRateSetting.OptimizeSampleRate;
            importer.defaultSampleSettings = s;
            importer.SaveAndReimport();
        }
    }
}
