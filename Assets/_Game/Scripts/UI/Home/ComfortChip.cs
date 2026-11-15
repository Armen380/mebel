using System.Collections.Generic;
using FF.Core;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.UI.Home
{
    /// <summary>
    /// Dream House HUD chip (M10) under the level pill: house icon, comfort, income bonus and the count of bought but
    /// not placed items. Shown from the foundation on; refreshed when the home or the language changes.
    /// </summary>
    public sealed class ComfortChip : MonoBehaviour
    {
        const string Table = "Game";

        [SerializeField] GameObject root;
        [SerializeField] TMP_Text comfort;
        [SerializeField] TMP_Text bonus;
        [SerializeField] GameObject box;
        [SerializeField] TMP_Text boxCount;

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        IHomeStore _store;
        IHomeBonus _bonus;
        bool _dirty = true;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject chipRoot, TMP_Text comfortText, TMP_Text bonusText, GameObject boxRoot, TMP_Text boxText)
        {
            root = chipRoot;
            comfort = comfortText;
            bonus = bonusText;
            box = boxRoot;
            boxCount = boxText;
        }

        void Start()
        {
            _store = Services.Get<IHomeStore>();
            _bonus = Services.Get<IHomeBonus>();
            Refresh();
        }

        void OnEnable()
        {
            GameEvents.HomeChanged += MarkDirty;
            LocalizationSettings.SelectedLocaleChanged += OnLocale;
        }

        void OnDisable()
        {
            GameEvents.HomeChanged -= MarkDirty;
            LocalizationSettings.SelectedLocaleChanged -= OnLocale;
        }

        void MarkDirty() => _dirty = true;

        void OnLocale(UnityEngine.Localization.Locale locale) => _dirty = true;

        void LateUpdate()
        {
            if (_dirty && _store != null) Refresh();
        }

        void Refresh()
        {
            _dirty = false;
            bool shown = _store.Stage >= 1;
            if (root.activeSelf != shown) root.SetActive(shown);
            if (!shown) return;
            // the house icon stands for "comfort": the number alone keeps the chip short in Armenian
            comfort.SetText("{0}", _store.Comfort);
            int percent = Mathf.RoundToInt((float)((_bonus.SaleMultiplier - 1.0) * 100.0));
            bonus.text = Text("home.bonus", "p", percent);
            int stored = _store.StorageCount;
            box.SetActive(stored > 0);
            if (stored > 0) boxCount.text = stored.ToString();
        }

        string Text(string key, string arg, object value)
        {
            _args.Clear();
            _args[arg] = value;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, key, new object[] { _args });
        }
    }
}
