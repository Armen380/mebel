using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.UI.HUD;
using FF.UI.Input;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.Home
{
    /// <summary>
    /// Home Store catalog (M10): a bottom sheet like the Upgrades panel with House / Yard tabs. Opens when the player
    /// stops at the store counter (<see cref="GameEvents.HomeStoreOpen"/>), closes with ✕, the backdrop or walking away.
    /// Rows show the comfort, "Owned ×N" / "Placed" / "Needs: walls", and a buy button with the price.
    /// </summary>
    public sealed class HomeStorePanel : MonoBehaviour
    {
        const string Table = "Game";

        [SerializeField] GameObject sheet;
        [SerializeField] Button closeButton;
        [SerializeField] Button backdrop;
        [SerializeField] TMP_Text balance;
        [SerializeField] Button houseTab;
        [SerializeField] Button yardTab;
        [SerializeField] Image houseTabBg;
        [SerializeField] Image yardTabBg;
        [SerializeField] RectTransform content;
        [SerializeField] HomeStoreRow rowTemplate;
        [SerializeField] VirtualJoystick joystick;
        [SerializeField] string[] iconGroups;
        [SerializeField] Sprite[] iconSprites;

        static readonly Color Grey = new Color32(0x52, 0x3a, 0x27, 0xff);
        static readonly Color GreyLip = new Color32(0x3a, 0x28, 0x1b, 0xff);
        static readonly Color TabOff = new Color32(0x3a, 0x28, 0x1b, 0xff);

        readonly List<HomeStoreRow> _rows = new List<HomeStoreRow>();
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        IHomeStore _store;
        IProgressView _progress;
        HomeDef _def;
        bool _yard, _dirty, _moneyDirty;
        long _balanceKey = -1;

        public bool IsOpen => sheet.activeSelf;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject sheetRoot, Button close, Button backdropButton, TMP_Text balanceText, Button house, Button yard,
            Image houseBg, Image yardBg, RectTransform rowsContent, HomeStoreRow row, VirtualJoystick stick, string[] groups, Sprite[] sprites)
        {
            sheet = sheetRoot;
            closeButton = close;
            backdrop = backdropButton;
            balance = balanceText;
            houseTab = house;
            yardTab = yard;
            houseTabBg = houseBg;
            yardTabBg = yardBg;
            content = rowsContent;
            rowTemplate = row;
            joystick = stick;
            iconGroups = groups;
            iconSprites = sprites;
        }

        void Awake()
        {
            closeButton.onClick.AddListener(Close);
            backdrop.onClick.AddListener(Close);
            houseTab.onClick.AddListener(() => SelectTab(false));
            yardTab.onClick.AddListener(() => SelectTab(true));
            rowTemplate.gameObject.SetActive(false);
            sheet.SetActive(false);
        }

        void Start()
        {
            _store = Services.Get<IHomeStore>();
            _progress = Services.Get<IProgressView>();
            _def = Services.Get<GameDatabase>().home;
            foreach (HomeDef.HomeItemDef item in _def.items)
            {
                HomeStoreRow row = Instantiate(rowTemplate, content);
                row.name = "Row_" + item.id;
                row.ItemId = item.id;
                row.Yard = _def.IsYardGroup(item.group);
                row.SetIcon(Icon(item.group));
                string id = item.id;
                row.Button.onClick.AddListener(() => Buy(id));
                _rows.Add(row);
            }
        }

        void OnEnable()
        {
            GameEvents.HomeStoreOpen += OnStoreOpen;
            GameEvents.MoneyChanged += OnMoney;
            GameEvents.HomeChanged += MarkDirty;
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
        }

        void OnDisable()
        {
            GameEvents.HomeStoreOpen -= OnStoreOpen;
            GameEvents.MoneyChanged -= OnMoney;
            GameEvents.HomeChanged -= MarkDirty;
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
        }

        void OnStoreOpen(bool open)
        {
            if (open) Open();
            else Close();
        }

        void OnMoney(long money, bool bump) => _moneyDirty = true;

        void MarkDirty() => _dirty = true;

        void OnLocale(UnityEngine.Localization.Locale locale) => _dirty = true;

        void Open()
        {
            if (joystick != null) joystick.Release();
            sheet.SetActive(true);
            SelectTab(_yard);
        }

        void Close()
        {
            if (sheet.activeSelf) sheet.SetActive(false);
        }

        void SelectTab(bool yard)
        {
            _yard = yard;
            houseTabBg.color = yard ? TabOff : (Color)UiPalette.Leaf;
            yardTabBg.color = yard ? (Color)UiPalette.Leaf : TabOff;
            foreach (HomeStoreRow row in _rows) row.gameObject.SetActive(row.Yard == yard);
            Refresh();
        }

        void LateUpdate()
        {
            if (!IsOpen) return;
            if (_dirty) Refresh();
            else if (_moneyDirty) RefreshStates();
        }

        void Buy(string itemId)
        {
            GameEvents.RaiseSound(SoundCue.Click);
            if (_store.Buy(itemId)) Refresh();
        }

        /// <summary>Texts and states (open, tab, language, home changed).</summary>
        void Refresh()
        {
            _dirty = false;
            foreach (HomeStoreRow row in _rows)
            {
                if (!row.gameObject.activeSelf) continue;
                HomeDef.HomeItemDef item = _def.Item(row.ItemId);
                string line;
                bool available = _store.IsAvailable(item.id);
                int stored = _store.InStorage(item.id);
                if (!available)
                {
                    int need = _def.RequiredStage(item.group);
                    line = Text("home.needs", "stage", need <= HomeDef.StagePads.Length ? Text(HomeDef.StageNameKey(need)) : "—");
                }
                else if (stored > 0) line = Text("home.owned", "n", stored);
                else if (_store.IsPlaced(item.id)) line = Text("home.placed");
                else line = Text("home.comfort", "n", "+" + item.comfort);
                row.SetTexts(Text(item.nameKey), line, NumberFormat.Money(item.price));
            }
            RefreshStates();
        }

        /// <summary>Balance and buy buttons only (money changes several times a second with workers).</summary>
        void RefreshStates()
        {
            _moneyDirty = false;
            long money = _progress.Money;
            if (money != _balanceKey)
            {
                _balanceKey = money;
                balance.SetText(NumberFormat.Money(money));
            }
            foreach (HomeStoreRow row in _rows)
            {
                if (!row.gameObject.activeSelf) continue;
                HomeDef.HomeItemDef item = _def.Item(row.ItemId);
                bool available = _store.IsAvailable(item.id);
                bool affordable = available && !_store.IsAtCap(item.id) && money >= item.price;
                row.SetState(affordable, affordable ? (Color)UiPalette.Leaf : Grey, affordable ? (Color)UiPalette.LeafDark : GreyLip,
                    available ? 1f : 0.55f);
            }
        }

        Sprite Icon(string group)
        {
            for (int i = 0; i < iconGroups.Length; i++)
                if (iconGroups[i] == group) return iconSprites[i];
            return null;
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
