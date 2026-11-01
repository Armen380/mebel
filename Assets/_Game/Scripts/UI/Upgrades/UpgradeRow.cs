using System;
using System.Collections.Generic;
using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.UI;

namespace FF.UI.Upgrades
{
    /// <summary>
    /// One row of the Upgrades panel (prototype <c>.up</c>): name, description, level pips, "now → next" and the buy
    /// button in one of four looks — affordable (green), too expensive (grey), locked (honey text) or MAX.
    /// </summary>
    public sealed class UpgradeRow : MonoBehaviour
    {
        const string Table = "Game";

        [SerializeField] TMP_Text title;
        [SerializeField] TMP_Text description;
        [SerializeField] TMP_Text value;
        [Tooltip("\"→\" between the current and the next value (Noto Sans has no arrow glyph) and the next value.")]
        [SerializeField] GameObject arrow;
        [SerializeField] TMP_Text nextValue;
        [SerializeField] Transform pips;
        [SerializeField] Button button;
        [SerializeField] Image buttonImage;
        [SerializeField] TMP_Text buttonLabel;
        [SerializeField] UnityEngine.UI.Shadow buttonShadow;
        [Tooltip("Price / MAX text size and the smaller size of lock texts (prototype .buy 15 px, .buy.locked 12.5 px).")]
        [SerializeField] float labelSize = 41f;
        [SerializeField] float lockedLabelSize = 35f;

        readonly List<Image> _pips = new List<Image>(8);
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        LocalizedString _name, _description;
        LocalizedString.ChangeHandler _onName, _onDescription;
        UpgradeDef _def;

        public UpgradeDef Def => _def;

        /// <summary>Editor tools only.</summary>
        public void Setup(TMP_Text titleText, TMP_Text descriptionText, TMP_Text valueText, GameObject arrowIcon, TMP_Text nextText,
            Transform pipRow, Button buy,
            Image buyImage, TMP_Text buyLabel, UnityEngine.UI.Shadow buyShadow, float size, float lockedSize)
        {
            title = titleText;
            description = descriptionText;
            value = valueText;
            arrow = arrowIcon;
            nextValue = nextText;
            pips = pipRow;
            button = buy;
            buttonImage = buyImage;
            buttonLabel = buyLabel;
            buttonShadow = buyShadow;
            labelSize = size;
            lockedLabelSize = lockedSize;
        }

        public void Bind(UpgradeDef def, Action<string> onBuy)
        {
            _def = def;
            pips.GetComponentsInChildren(true, _pips);
            for (int i = 0; i < _pips.Count; i++) _pips[i].gameObject.SetActive(i < def.maxLevel);
            _name = new LocalizedString(Table, def.nameKey);
            _description = new LocalizedString(Table, def.descriptionKey);
            _onName = s => title.SetText(s);
            _onDescription = s => description.SetText(s);
            _name.StringChanged += _onName;
            _description.StringChanged += _onDescription;
            button.onClick.AddListener(() => onBuy(def.id));
        }

        void OnDestroy()
        {
            if (_name != null) _name.StringChanged -= _onName;
            if (_description != null) _description.StringChanged -= _onDescription;
        }

        public void Refresh(IUpgradeShop shop, EconomyConfig economy, string maxText, Color green, Color grey, Color honey, Color muted)
        {
            string id = _def.id;
            int level = shop.GetLevel(id);
            bool maxed = level >= _def.maxLevel;
            for (int i = 0; i < _pips.Count && i < _def.maxLevel; i++) _pips[i].color = i < level ? green : grey;

            value.SetText(UpgradeValueText.Format(_def, level, economy));
            arrow.SetActive(!maxed);
            nextValue.gameObject.SetActive(!maxed);
            if (!maxed) nextValue.SetText(UpgradeValueText.Format(_def, level + 1, economy));

            if (maxed)
            {
                SetButton(maxText, Color.clear, honey, false, false);
                return;
            }
            if (shop.IsLocked(id, out int needShop, out bool needPlumbing))
            {
                _args.Clear();
                _args["n"] = needShop;
                string text = needPlumbing
                    ? UnityEngine.Localization.Settings.LocalizationSettings.StringDatabase.GetLocalizedString(Table, "ui.lockSink")
                    : UnityEngine.Localization.Settings.LocalizationSettings.StringDatabase.GetLocalizedString(Table, "ui.lockShop", new object[] { _args });
                SetButton(text, grey, honey, false, false, true);
                return;
            }
            bool affordable = shop.CanBuy(id);
            SetButton(NumberFormat.Money(shop.GetPrice(id)), affordable ? green : grey, affordable ? Color.white : muted, affordable, affordable);
        }

        void SetButton(string text, Color background, Color textColor, bool interactable, bool shadow, bool small = false)
        {
            buttonLabel.SetText(text);
            buttonLabel.color = textColor;
            buttonLabel.fontSize = small ? lockedLabelSize : labelSize;
            buttonImage.color = background;
            button.interactable = interactable;
            buttonShadow.enabled = shadow;
        }
    }
}
