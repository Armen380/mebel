using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.DevTools
{
    /// <summary>Temporary dev button: cycles hy → en → ru until the real language switch arrives with the menu (M9).</summary>
    [RequireComponent(typeof(Button))]
    public sealed class LocaleSwitchButton : MonoBehaviour
    {
        [SerializeField] TMP_Text label;

        void Awake() => GetComponent<Button>().onClick.AddListener(Next);

        void Start() => Refresh();

        void Next()
        {
            List<Locale> locales = LocalizationSettings.AvailableLocales.Locales;
            if (locales.Count == 0) return;
            int i = locales.IndexOf(LocalizationSettings.SelectedLocale);
            LocalizationSettings.SelectedLocale = locales[(i + 1) % locales.Count];
            Refresh();
        }

        void Refresh()
        {
            Locale current = LocalizationSettings.SelectedLocale;
            if (label != null && current != null) label.text = current.Identifier.Code.ToUpperInvariant();
        }
    }
}
