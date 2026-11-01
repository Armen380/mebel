using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.UI.Input;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.Upgrades
{
    /// <summary>
    /// Prototype Upgrades sheet (<c>renderShop / openSheet / closeSheet</c>) and the badge on the Upgrades button
    /// (<c>hudMoney</c>: shown when any upgrade can be bought). Rows are built once from the data; only the groups in
    /// <see cref="visibleGroups"/> are shown (worker groups join with their milestones).
    /// </summary>
    public sealed class UpgradesPanel : MonoBehaviour
    {
        const string Table = "Game";
        const float MaxWidth = 560f * 1080f / 390f;

        [SerializeField] Button openButton;
        [SerializeField] GameObject badge;
        [SerializeField] GameObject sheet;
        [SerializeField] RectTransform panel;
        [SerializeField] Button closeButton;
        [SerializeField] Button backdrop;
        [SerializeField] TMP_Text balance;
        [SerializeField] TMP_Text note;
        [SerializeField] RectTransform content;
        [SerializeField] UpgradeRow rowTemplate;
        [SerializeField] TMP_Text groupTemplate;
        [SerializeField] VirtualJoystick joystick;
        [SerializeField] List<string> visibleGroups = new List<string> { "g.player", "g.biz" };

        static readonly Color Green = new Color32(0x5c, 0xae, 0x4a, 0xff);
        static readonly Color Grey = new Color32(0x52, 0x3a, 0x27, 0xff);
        static readonly Color Honey = new Color32(0xf3, 0xb3, 0x3d, 0xff);
        static readonly Color Muted = new Color32(0xcb, 0xb6, 0x97, 0xff);

        readonly List<UpgradeRow> _rows = new List<UpgradeRow>();
        readonly List<(LocalizedString text, LocalizedString.ChangeHandler handler)> _groupTexts =
            new List<(LocalizedString, LocalizedString.ChangeHandler)>();
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        readonly LocalizedString _note = new LocalizedString(Table, "ui.padNote");
        readonly LocalizedString _max = new LocalizedString(Table, "ui.max");
        IUpgradeShop _shop;
        IProgressView _progress;
        EconomyConfig _economy;
        string _maxText = "MAX";

        public bool IsOpen => sheet.activeSelf;

        /// <summary>Editor tools only.</summary>
        public void Setup(Button open, GameObject badgeObject, GameObject sheetRoot, RectTransform panelRect, Button close, Button backdropButton,
            TMP_Text balanceText, TMP_Text noteText, RectTransform rowsContent, UpgradeRow row, TMP_Text group, VirtualJoystick stick)
        {
            openButton = open;
            badge = badgeObject;
            sheet = sheetRoot;
            panel = panelRect;
            closeButton = close;
            backdrop = backdropButton;
            balance = balanceText;
            note = noteText;
            content = rowsContent;
            rowTemplate = row;
            groupTemplate = group;
            joystick = stick;
        }

        void Awake()
        {
            openButton.onClick.AddListener(Open);
            closeButton.onClick.AddListener(Close);
            backdrop.onClick.AddListener(Close);
            rowTemplate.gameObject.SetActive(false);
            groupTemplate.gameObject.SetActive(false);
            sheet.SetActive(false);
        }

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _shop = Services.Get<IUpgradeShop>();
            _progress = Services.Get<IProgressView>();
            BuildRows(db);
            _note.StringChanged += OnNote;
            _max.StringChanged += OnMax;
            RefreshBadge();
        }

        void OnEnable()
        {
            GameEvents.MoneyChanged += OnMoneyChanged;
            GameEvents.UpgradeBought += OnUpgradeBought;
            LocalizationSettings.SelectedLocaleChanged += OnLocaleChanged;
        }

        void OnDisable()
        {
            GameEvents.MoneyChanged -= OnMoneyChanged;
            GameEvents.UpgradeBought -= OnUpgradeBought;
            LocalizationSettings.SelectedLocaleChanged -= OnLocaleChanged;
        }

        void OnDestroy()
        {
            _note.StringChanged -= OnNote;
            _max.StringChanged -= OnMax;
            foreach ((LocalizedString text, LocalizedString.ChangeHandler handler) in _groupTexts) text.StringChanged -= handler;
        }

        void BuildRows(GameDatabase db)
        {
            string group = null;
            foreach (UpgradeDef u in db.upgrades)
            {
                if (!visibleGroups.Contains(u.groupKey)) continue;
                if (u.groupKey != group)
                {
                    group = u.groupKey;
                    TMP_Text header = Instantiate(groupTemplate, content);
                    header.gameObject.SetActive(true);
                    var text = new LocalizedString(Table, group);
                    LocalizedString.ChangeHandler handler = s => header.SetText(s);
                    text.StringChanged += handler;
                    _groupTexts.Add((text, handler));
                }
                UpgradeRow row = Instantiate(rowTemplate, content);
                row.gameObject.SetActive(true);
                row.Bind(u, Buy);
                _rows.Add(row);
            }
        }

        void Open()
        {
            joystick.Release();
            sheet.SetActive(true);
            FitWidth();
            RefreshRows();
        }

        void LateUpdate()
        {
            if (IsOpen) FitWidth();
        }

        /// <summary>CSS <c>width: min(560px, 100%)</c>; follows rotation and resolution changes.</summary>
        void FitWidth()
        {
            float width = Mathf.Min(MaxWidth, ((RectTransform)sheet.transform).rect.width);
            if (!Mathf.Approximately(panel.sizeDelta.x, width)) panel.sizeDelta = new Vector2(width, panel.sizeDelta.y);
        }

        void Close() => sheet.SetActive(false);

        void Buy(string id)
        {
            if (_shop.TryBuy(id)) RefreshRows();
        }

        void OnMoneyChanged(long money, bool bump)
        {
            RefreshBadge();
            if (IsOpen) RefreshRows();
        }

        void OnUpgradeBought(string id, int level) => RefreshBadge();

        void OnLocaleChanged(Locale locale)
        {
            if (IsOpen) RefreshRows();
        }

        void OnNote(string value) => note.SetText(value.Replace("<b>", "<b><color=#f3b33d>").Replace("</b>", "</color></b>"));

        void OnMax(string value)
        {
            _maxText = value;
            if (IsOpen) RefreshRows();
        }

        void RefreshRows()
        {
            _args.Clear();
            _args["v"] = NumberFormat.Compact(_progress.Money);
            balance.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "ui.balance", new object[] { _args }));
            foreach (UpgradeRow row in _rows) row.Refresh(_shop, _economy, _maxText, Green, Grey, Honey, Muted);
        }

        void RefreshBadge()
        {
            if (_shop == null) return;
            bool any = false;
            foreach (UpgradeRow row in _rows)
                if (_shop.CanBuy(row.Def.id))
                {
                    any = true;
                    break;
                }
            if (badge.activeSelf != any) badge.SetActive(any);
        }
    }
}
