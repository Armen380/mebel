using System;
using System.Collections.Generic;
using System.Text;
using FF.Core;
using FF.Data;
using FF.UI.HUD;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.Menu
{
    /// <summary>
    /// Prototype main menu (<c>#menu</c>, <c>openMenu / startPlay / renderSkins</c>), also the pause screen: kicker with the
    /// version, language switch, skin cards (Golden locked until $100K earned), Play / Continue, "Test" (development
    /// builds only) and New game (second tap within 3 s erases the save). While it is open the HUD is hidden and the game
    /// is paused (<see cref="GameMode"/>).
    /// </summary>
    public sealed class MainMenu : MonoBehaviour
    {
        const string Table = "Game";
        const int TestLevels = 25;
        const long TestMoney = 250_000;
        const float ConfirmSeconds = 3f;
        static readonly Color32 Walnut2 = new Color32(0x3a, 0x28, 0x1b, 0xff);
        static readonly Color32 Muted = new Color32(0xcb, 0xb6, 0x97, 0xff);
        static readonly Color32 WarnText = new Color32(0xff, 0xb1, 0x9f, 0xff);

        [Serializable]
        public struct LanguageButton
        {
            public string code;
            public Button button;
            public Image background;
            public TMP_Text label;
        }

        [Serializable]
        public struct ToggleButton
        {
            public Button button;
            public Image background;
            public Image icon;
        }

        [Serializable]
        public struct QualityButton
        {
            public QualityTier tier;
            public Button button;
            public Image background;
            public TMP_Text label;
        }

        [Serializable]
        public struct SkinCardParts
        {
            public Button button;
            public Image background;
            public Image border;
            public Image shirt;
            public Image hat;
            public TMP_Text name;
            public TMP_Text lockText;
            public CanvasGroup group;
        }

        [SerializeField] GameObject menuRoot;
        [SerializeField] CanvasGroup hud;
        [SerializeField] Button menuButton;
        [SerializeField] TMP_Text kicker;
        [SerializeField] List<LanguageButton> languages = new List<LanguageButton>();
        [SerializeField] RectTransform skinsContent;
        [SerializeField] SkinCardParts skinTemplate;
        [SerializeField] Button playButton;
        [SerializeField] TMP_Text playLabel;
        [SerializeField] Button testButton;
        [SerializeField] TMP_Text testLabel;
        [SerializeField] Button newGameButton;
        [SerializeField] Image newGameBorder;
        [SerializeField] TMP_Text newGameLabel;
        [SerializeField] ToggleButton sound;
        [SerializeField] ToggleButton music;
        [SerializeField] ToggleButton vibration;
        [SerializeField] List<QualityButton> quality = new List<QualityButton>();

        readonly List<(SkinDef skin, SkinCardParts parts)> _cards = new List<(SkinDef, SkinCardParts)>();
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        GameDatabase _db;
        GameMode _mode;
        IProgressView _progress;
        ISkinSelection _skins;
        GameSettings _settings;
        float _armedUntil = -1f;
        long _cardsTotalKey = -1;
        bool _textsDirty;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject root, CanvasGroup hudGroup, Button openButton, TMP_Text kickerText, List<LanguageButton> languageButtons,
            RectTransform skinsParent, SkinCardParts template, Button play, TMP_Text playText, Button test, TMP_Text testText,
            Button newGame, Image newGameFrame, TMP_Text newGameText)
        {
            menuRoot = root;
            hud = hudGroup;
            menuButton = openButton;
            kicker = kickerText;
            languages = languageButtons;
            skinsContent = skinsParent;
            skinTemplate = template;
            playButton = play;
            playLabel = playText;
            testButton = test;
            testLabel = testText;
            newGameButton = newGame;
            newGameBorder = newGameFrame;
            newGameLabel = newGameText;
        }

        /// <summary>Editor tools only.</summary>
        public void SetupSettings(ToggleButton soundToggle, ToggleButton musicToggle, ToggleButton vibrationToggle, List<QualityButton> qualityButtons)
        {
            sound = soundToggle;
            music = musicToggle;
            vibration = vibrationToggle;
            quality = qualityButtons;
        }

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _mode = Services.Get<GameMode>();
            _progress = Services.Get<IProgressView>();
            _skins = Services.Get<ISkinSelection>();
            _settings = Services.Get<GameSettings>();
            sound.button.onClick.AddListener(() => _settings.SetSound(!_settings.Sound));
            music.button.onClick.AddListener(() => _settings.SetMusic(!_settings.Music));
            vibration.button.onClick.AddListener(() => _settings.SetVibration(!_settings.Vibration));
            foreach (QualityButton q in quality)
            {
                QualityTier tier = q.tier;
                q.button.onClick.AddListener(() => _settings.SetQuality(tier));
            }
            _settings.Changed += RefreshSettings;

            kicker.SetText("v" + Application.version);
            foreach (LanguageButton l in languages)
            {
                string code = l.code;
                l.button.onClick.AddListener(() => SelectLanguage(code));
            }
            BuildSkinCards();
            playButton.onClick.AddListener(_mode.Play);
            menuButton.onClick.AddListener(_mode.OpenMenu);
            newGameButton.onClick.AddListener(OnNewGame);
            bool dev = Debug.isDebugBuild;
            testButton.gameObject.SetActive(dev);
            if (dev) testButton.onClick.AddListener(OnTest);

            _mode.Changed += OnModeChanged;
            _skins.Changed += OnSkinChanged;
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
            OnModeChanged(_mode.InMenu);
        }

        void OnDestroy()
        {
            if (_mode != null) _mode.Changed -= OnModeChanged;
            if (_skins != null) _skins.Changed -= OnSkinChanged;
            if (_settings != null) _settings.Changed -= RefreshSettings;
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
        }

        void OnModeChanged(bool inMenu)
        {
            menuRoot.SetActive(inMenu);
            hud.alpha = inMenu ? 0f : 1f;
            hud.interactable = hud.blocksRaycasts = !inMenu;
            if (!inMenu) return;
            // prototype openMenu: Continue, disarm New game, refresh the skins, save
            Disarm();
            RefreshTexts();
            RefreshSkins();
            RefreshLanguages();
            RefreshSettings();
            if (Services.TryGet(out ISaveService save)) save.SaveNow();
        }

        void Update()
        {
            if (!_mode.InMenu) return;
            if (_textsDirty)
            {
                _textsDirty = false;
                RefreshLanguages();
                RefreshTexts();
                RefreshSkins();
            }
            if (_armedUntil >= 0f && Time.unscaledTime > _armedUntil) Disarm();
            // Golden unlocks while the menu is open only through the test button; cheap check on the total
            if (_progress.TotalEarned != _cardsTotalKey) RefreshSkins();
        }

        // ---------- language ----------

        void SelectLanguage(string code)
        {
            Locale locale = LocalizationSettings.AvailableLocales.GetLocale(code);
            if (locale != null) LocalizationSettings.SelectedLocale = locale;
        }

        // texts are fetched synchronously, which must not happen inside the localization callback: next frame
        void OnLocale(Locale locale) => _textsDirty = true;

        void RefreshLanguages()
        {
            Locale current = LocalizationSettings.SelectedLocale;
            string code = current != null ? current.Identifier.Code : null;
            foreach (LanguageButton l in languages)
            {
                bool on = l.code == code;
                l.background.color = on ? (Color)UiPalette.Honey : Color.clear;
                l.label.color = on ? UiPalette.Walnut : Muted;
            }
        }

        // ---------- settings ----------

        void RefreshSettings()
        {
            Style(sound, _settings.Sound);
            Style(music, _settings.Music);
            Style(vibration, _settings.Vibration);
            foreach (QualityButton q in quality)
            {
                bool on = q.tier == _settings.Quality;
                q.background.color = on ? (Color)UiPalette.Honey : Color.clear;
                q.label.color = on ? UiPalette.Walnut : Muted;
            }
        }

        static void Style(ToggleButton t, bool on)
        {
            t.background.color = on ? (Color)UiPalette.Honey : Walnut2;
            t.icon.color = on ? UiPalette.Walnut : Muted;
        }

        // ---------- skins ----------

        void BuildSkinCards()
        {
            skinTemplate.button.gameObject.SetActive(false);
            foreach (SkinDef s in _db.skins)
            {
                GameObject go = Instantiate(skinTemplate.button.gameObject, skinsContent);
                go.name = "Skin_" + s.id;
                go.SetActive(true);
                SkinCardParts parts = Clone(go);
                parts.shirt.color = s.shirt;
                parts.hat.color = s.hat;
                string id = s.id;
                parts.button.onClick.AddListener(() => _skins.Select(id));
                _cards.Add((s, parts));
            }
        }

        /// <summary>The template's parts found again in its clone (same child paths).</summary>
        SkinCardParts Clone(GameObject go)
        {
            Transform t = go.transform;
            Transform root = skinTemplate.button.transform;
            return new SkinCardParts
            {
                button = go.GetComponent<Button>(),
                background = Find<Image>(t, root, skinTemplate.background.transform),
                border = Find<Image>(t, root, skinTemplate.border.transform),
                shirt = Find<Image>(t, root, skinTemplate.shirt.transform),
                hat = Find<Image>(t, root, skinTemplate.hat.transform),
                name = Find<TMP_Text>(t, root, skinTemplate.name.transform),
                lockText = Find<TMP_Text>(t, root, skinTemplate.lockText.transform),
                group = go.GetComponent<CanvasGroup>(),
            };
        }

        static T Find<T>(Transform clone, Transform templateRoot, Transform part) where T : Component
        {
            var path = new StringBuilder();
            for (Transform p = part; p != templateRoot; p = p.parent)
                path.Insert(0, path.Length > 0 ? p.name + "/" : p.name);
            return clone.Find(path.ToString()).GetComponent<T>();
        }

        void OnSkinChanged(string id) => RefreshSkins();

        void RefreshSkins()
        {
            _cardsTotalKey = _progress.TotalEarned;
            foreach ((SkinDef skin, SkinCardParts parts) in _cards)
            {
                bool unlocked = _skins.IsUnlocked(skin.id);
                bool on = _skins.Current == skin.id;
                parts.button.interactable = unlocked;
                parts.group.alpha = unlocked ? 1f : 0.5f;
                parts.border.enabled = on;
                parts.background.color = on ? (Color)UiPalette.Walnut3 : Walnut2;
                parts.name.SetText(Text(skin.nameKey));
                parts.lockText.gameObject.SetActive(!unlocked);
                if (!unlocked) parts.lockText.SetText(Text("ui.earn", "v", NumberFormat.Compact(skin.unlockTotalEarned)));
            }
        }

        // ---------- buttons ----------

        void RefreshTexts()
        {
            playLabel.SetText(Text(_mode.Started ? "ui.continue" : "ui.play"));
            if (_armedUntil < 0f) newGameLabel.SetText(Text("ui.new"));
        }

        void OnTest()
        {
            int from = _progress.Level;
            Services.Get<IDevCheats>().AddLevelsAndMoney(TestLevels, TestMoney);
            // prototype: "Lv 26 · unlocked: Sofas"
            var label = new StringBuilder("Lv ").Append(_progress.Level);
            bool first = true;
            foreach (ProductDef p in _db.products)
            {
                if (p.unlockLevel <= from || p.unlockLevel > _progress.Level) continue;
                label.Append(first ? " · " + Text("ui.unlocked") : ", ").Append(Text(p.nameKey));
                first = false;
            }
            testLabel.SetText(label.ToString());
        }

        void OnNewGame()
        {
            if (_armedUntil < 0f)
            {
                _armedUntil = Time.unscaledTime + ConfirmSeconds;
                newGameLabel.SetText(Text("ui.reset"));
                newGameLabel.color = WarnText;
                newGameBorder.color = UiPalette.Danger;
                return;
            }
            Services.Get<ISaveService>().DeleteAndRestart();
        }

        void Disarm()
        {
            _armedUntil = -1f;
            newGameLabel.SetText(Text("ui.new"));
            newGameLabel.color = Muted;
            newGameBorder.color = UiPalette.Walnut3;
        }

        string Text(string key) => LocalizationSettings.StringDatabase.GetLocalizedString(Table, key);

        string Text(string key, string arg, object value)
        {
            _args.Clear();
            _args[arg] = value;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, key, new object[] { _args });
        }
    }
}
