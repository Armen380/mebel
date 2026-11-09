using FF.Data;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.Menu
{
    /// <summary>Menu "Privacy policy" link: opens <see cref="AdsConfig.privacyPolicyUrl"/> in the browser; hidden without a URL.</summary>
    public sealed class PrivacyPolicyLink : MonoBehaviour
    {
        [SerializeField] AdsConfig config;
        [SerializeField] Button button;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig, Button link)
        {
            config = adsConfig;
            button = link;
        }

        public string Url => config != null ? config.privacyPolicyUrl : null;

        void Start()
        {
            if (string.IsNullOrEmpty(Url))
            {
                gameObject.SetActive(false);
                return;
            }
            // click sounds come from the menu (it hooks every button on its canvas)
            button.onClick.AddListener(Open);
        }

        public void Open() => Application.OpenURL(Url);
    }
}
