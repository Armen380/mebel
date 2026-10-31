using System.Collections.Generic;
using System.Text;
using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.UI.HUD
{
    /// <summary>
    /// Level-up toast (prototype <c>onLevel → toast</c>): "Level N" and either the factories that open at this level
    /// or "keep going"; pops in, stays 2.4 s.
    /// </summary>
    public sealed class LevelToast : MonoBehaviour
    {
        const string Table = "Game";
        const float ShowSeconds = 2.4f;
        const float PopSeconds = 0.3f;
        const float PopFromScale = 0.7f;

        [SerializeField] RectTransform panel;
        [SerializeField] CanvasGroup group;
        [SerializeField] TMP_Text title;
        [SerializeField] TMP_Text subtitle;

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        readonly StringBuilder _list = new StringBuilder();
        GameDatabase _db;
        float _time = -1f;

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            panel.gameObject.SetActive(false);
        }

        void OnEnable() => GameEvents.LevelUp += Show;

        void OnDisable() => GameEvents.LevelUp -= Show;

        void Show(int level)
        {
            _args.Clear();
            _args["n"] = level;
            title.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "t.level", new object[] { _args }));

            _list.Clear();
            foreach (ProductDef p in _db.products)
            {
                if (p.unlockLevel != level || p.factoryCost <= 0) continue;
                if (_list.Length > 0) _list.Append(", ");
                _list.Append(LocalizationSettings.StringDatabase.GetLocalizedString(Table, p.nameKey));
            }
            if (_list.Length > 0)
            {
                _args.Clear();
                _args["list"] = _list.ToString();
                subtitle.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "t.newFactory", new object[] { _args }));
            }
            else subtitle.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "t.keepGoing"));

            _time = 0f;
            panel.gameObject.SetActive(true);
        }

        void LateUpdate()
        {
            if (_time < 0f) return;
            _time += Time.unscaledDeltaTime;
            if (_time >= ShowSeconds)
            {
                _time = -1f;
                panel.gameObject.SetActive(false);
                return;
            }
            float k = Mathf.Clamp01(_time / PopSeconds);
            float eased = 1f - (1f - k) * (1f - k); // ease-out
            panel.localScale = Vector3.one * Mathf.Lerp(PopFromScale, 1f, eased);
            group.alpha = eased;
        }
    }
}
