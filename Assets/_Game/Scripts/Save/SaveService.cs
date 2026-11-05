using System;
using System.IO;
using FF.Core;
using FF.Gameplay.Delivery;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;
using UnityEngine.SceneManagement;

namespace FF.Save
{
    /// <summary>
    /// Loads <c>persistentDataPath/save.json</c> right after the services exist and before the world reads them, and
    /// writes it: every 3 s when something changed, right after every purchase, and when the app pauses, loses focus
    /// or quits (prototype <c>save()</c> + <c>visibilitychange</c>). Writes are atomic (temp file, then replace);
    /// a file that cannot be read is kept as <c>save.broken.json</c> and the game starts new.
    /// </summary>
    [DefaultExecutionOrder(-900)]
    public sealed class SaveService : MonoBehaviour, ISaveService
    {
        public const string FileName = "save.json";
        const float AutosaveSeconds = 3f;

        GameProgress _progress;
        WorldStateSnapshot _state;
        DeliveryCargo _cargo;
        string _path;
        string _language;
        float _timer;
        bool _dirty, _deleted;

        public static string DefaultPath => Path.Combine(Application.persistentDataPath, FileName);

        void Awake()
        {
            _path = DefaultPath;
            _progress = Services.Get<GameProgress>();
            _state = Services.Get<WorldStateSnapshot>();
            Services.TryGet(out _cargo);
            Services.Register<ISaveService>(this);
            Load();
            Services.Get<WorldCollision>().Rebuild(_state);
        }

        void OnEnable()
        {
            GameEvents.MoneyChanged += OnMoney;
            GameEvents.LevelUp += OnChanged;
            GameEvents.QuestChanged += OnChanged;
            GameEvents.Unlocked += OnChanged;
            GameEvents.ProgressChanged += MarkDirty;
            GameEvents.PadCompleted += OnPurchase;
            GameEvents.UpgradeBought += OnPurchase;
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
        }

        void OnDisable()
        {
            GameEvents.MoneyChanged -= OnMoney;
            GameEvents.LevelUp -= OnChanged;
            GameEvents.QuestChanged -= OnChanged;
            GameEvents.Unlocked -= OnChanged;
            GameEvents.ProgressChanged -= MarkDirty;
            GameEvents.PadCompleted -= OnPurchase;
            GameEvents.UpgradeBought -= OnPurchase;
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
        }

        void OnMoney(long money, bool bump) => MarkDirty();
        void OnChanged(int value) => MarkDirty();
        void OnChanged(string value) => MarkDirty();
        void OnPurchase(string id, int level) => SaveNow();
        void MarkDirty() => _dirty = true;

        void OnLocale(Locale locale)
        {
            if (locale == null) return;
            _language = locale.Identifier.Code;
            MarkDirty();
        }

        void Update()
        {
            _timer += Time.unscaledDeltaTime;
            if (_timer < AutosaveSeconds) return;
            _timer = 0f;
            if (_dirty) SaveNow();
        }

        void OnApplicationPause(bool paused)
        {
            if (paused) SaveNow();
        }

        void OnApplicationFocus(bool focused)
        {
            if (!focused) SaveNow();
        }

        void OnApplicationQuit() => SaveNow();

        public void SaveNow()
        {
            if (_deleted || _progress == null) return;
            _dirty = false;
            Write(_path, SaveSerializer.ToJson(SaveMapper.Capture(_progress, _state, _cargo, _language ?? CurrentLanguage())));
        }

        public void DeleteAndRestart()
        {
            _deleted = true;
            Delete(_path);
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        }

        void Load()
        {
#if UNITY_EDITOR || UNITY_STANDALONE_OSX
            if (!File.Exists(_path)) MigrateLegacySave();
#endif
            if (!File.Exists(_path)) return;
            try
            {
                SaveData data = SaveSerializer.FromJson(File.ReadAllText(_path));
                SaveMapper.Apply(data, _progress, _state, _cargo);
                ApplyLanguage(data.lang);
            }
            catch (Exception e) when (e is FormatException || e is IOException || e is Newtonsoft.Json.JsonException)
            {
                Debug.LogWarning($"[FF] Save file could not be read ({e.Message}); starting a new game. Kept as save.broken.json.");
                try
                {
                    File.Copy(_path, Path.ChangeExtension(_path, ".broken.json"), true);
                    File.Delete(_path);
                }
                catch (IOException) { }
            }
        }

#if UNITY_EDITOR || UNITY_STANDALONE_OSX
        /// <summary>
        /// M9 renamed the app (DefaultCompany / Mebel → Armen380 / Furniture Factory), which moved the desktop save folder:
        /// copy a save from the old folder once (the old file stays). Phones are unaffected — the new bundle id is a new app.
        /// </summary>
        void MigrateLegacySave()
        {
            string root = Path.GetDirectoryName(Path.GetDirectoryName(Application.persistentDataPath));
            if (string.IsNullOrEmpty(root)) return;
            string legacy = Path.Combine(root, "DefaultCompany", "Mebel", FileName);
            if (!File.Exists(legacy)) return;
            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(_path));
                File.Copy(legacy, _path, false);
                Debug.Log($"[FF] Save copied from the old app folder: {legacy}");
            }
            catch (IOException e)
            {
                Debug.LogWarning($"[FF] Could not copy the old save: {e.Message}");
            }
        }
#endif

        void ApplyLanguage(string code)
        {
            if (string.IsNullOrEmpty(code)) return;
            _language = code;
            if (LocalizationSettings.InitializationOperation.IsDone) Select(code);
            else LocalizationSettings.InitializationOperation.Completed += _ => Select(code);
        }

        static void Select(string code)
        {
            Locale locale = LocalizationSettings.AvailableLocales.GetLocale(code);
            if (locale != null) LocalizationSettings.SelectedLocale = locale;
        }

        static string CurrentLanguage()
        {
            if (!LocalizationSettings.InitializationOperation.IsDone) return null;
            Locale locale = LocalizationSettings.SelectedLocale;
            return locale != null ? locale.Identifier.Code : null;
        }

        /// <summary>Atomic write: temp file next to the save, then replace.</summary>
        public static void Write(string path, string json)
        {
            string temp = path + ".tmp";
            File.WriteAllText(temp, json);
            if (File.Exists(path)) File.Delete(path);
            File.Move(temp, path);
        }

        public static void Delete(string path)
        {
            if (File.Exists(path)) File.Delete(path);
        }
    }
}
