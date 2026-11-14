using System.Collections.Generic;
using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.Home
{
    /// <summary>
    /// Dream House variant picker (M10): standing on a placed Home Store slot with other variants in storage shows up to
    /// three buttons (icon + name); a tap swaps the placed item. Opened and closed by <see cref="GameEvents.HomeVariantPicker"/>.
    /// </summary>
    public sealed class VariantPicker : MonoBehaviour
    {
        const string Table = "Game";

        [SerializeField] GameObject panel;
        [SerializeField] Button[] buttons;
        [SerializeField] Image[] icons;
        [SerializeField] TMP_Text[] labels;
        [Tooltip("Icon per catalog group (parallel arrays).")]
        [SerializeField] string[] iconGroups;
        [SerializeField] Sprite[] iconSprites;

        readonly List<string> _ids = new List<string>(4);
        IHomeStore _store;
        HomeDef _def;
        string _slot;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject panelRoot, Button[] buttonList, Image[] iconList, TMP_Text[] labelList, string[] groups, Sprite[] sprites)
        {
            panel = panelRoot;
            buttons = buttonList;
            icons = iconList;
            labels = labelList;
            iconGroups = groups;
            iconSprites = sprites;
        }

        void Awake()
        {
            for (int i = 0; i < buttons.Length; i++)
            {
                int index = i;
                buttons[i].onClick.AddListener(() => Pick(index));
            }
            panel.SetActive(false);
        }

        void Start()
        {
            _store = Services.Get<IHomeStore>();
            _def = Services.Get<GameDatabase>().home;
        }

        void OnEnable()
        {
            GameEvents.HomeVariantPicker += Show;
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
        }

        void OnDisable()
        {
            GameEvents.HomeVariantPicker -= Show;
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
        }

        void OnLocale(UnityEngine.Localization.Locale locale)
        {
            if (_slot != null) Show(_slot);
        }

        void Show(string slotId)
        {
            _slot = slotId;
            if (slotId == null || _store == null || _store.Variants(slotId, _ids) == 0)
            {
                panel.SetActive(false);
                return;
            }
            for (int i = 0; i < buttons.Length; i++)
            {
                bool on = i < _ids.Count;
                buttons[i].gameObject.SetActive(on);
                if (!on) continue;
                HomeDef.HomeItemDef item = _def.Item(_ids[i]);
                icons[i].sprite = Icon(item != null ? item.group : null);
                labels[i].text = item != null ? LocalizationSettings.StringDatabase.GetLocalizedString(Table, item.nameKey) : _ids[i];
            }
            panel.SetActive(true);
        }

        void Pick(int index)
        {
            if (_slot == null || index >= _ids.Count) return;
            GameEvents.RaiseSound(SoundCue.Click);
            _store.Swap(_slot, _ids[index]);
            Show(_slot);
        }

        Sprite Icon(string group)
        {
            for (int i = 0; i < iconGroups.Length; i++)
                if (iconGroups[i] == group) return iconSprites[i];
            return null;
        }
    }
}
