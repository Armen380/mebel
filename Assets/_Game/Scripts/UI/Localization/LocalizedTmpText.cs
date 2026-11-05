using TMPro;
using UnityEngine;
using UnityEngine.Localization;

namespace FF.UI.Localization
{
    /// <summary>Keeps a TextMeshPro text (UI or 3D world sign) in sync with a localized string; updates live on language change.</summary>
    [RequireComponent(typeof(TMP_Text))]
    public sealed class LocalizedTmpText : MonoBehaviour
    {
        public const string DefaultTable = "Game";

        [SerializeField] LocalizedString text = new LocalizedString();
        [Tooltip("Prototype HTML in the text: <em>…</em> in honey (menu title), <br> as a line break.")]
        [SerializeField] bool html;

        TMP_Text _label;

        /// <summary>Editor/tools: point this text at a key of the game table.</summary>
        public void SetKey(string key, string table = DefaultTable, bool convertHtml = false)
        {
            text = new LocalizedString(table, key);
            html = convertHtml;
        }

        void Awake() => _label = GetComponent<TMP_Text>();

        void OnEnable()
        {
            if (text.IsEmpty) return;
            text.StringChanged += OnStringChanged;
        }

        void OnDisable() => text.StringChanged -= OnStringChanged;

        void OnStringChanged(string value) => _label.text = html ? FromHtml(value) : value;

        public static string FromHtml(string value) =>
            value.Replace("<em>", "<color=#F3B33D>").Replace("</em>", "</color>").Replace("<br>", "\n");
    }
}
