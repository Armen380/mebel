using FF.Core;
using FF.Data;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.Menu
{
    /// <summary>
    /// "Personalized ads?" over the menu: opens by itself on the first launch (ads wait for the answer) and from the
    /// menu's "Ad privacy" link; Allow = GDPR consent, No = no consent and the CCPA opt-out (<see cref="AdsConsent"/>).
    /// Not shown when no ads are configured for the platform.
    /// </summary>
    public sealed class AdsConsentDialog : MonoBehaviour
    {
        [SerializeField] AdsConfig config;
        [SerializeField] GameObject dialog;
        [SerializeField] Button allow;
        [SerializeField] Button deny;
        [SerializeField] Button openLink;

        GameMode _mode;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig, GameObject dialogRoot, Button allowButton, Button denyButton, Button link)
        {
            config = adsConfig;
            dialog = dialogRoot;
            allow = allowButton;
            deny = denyButton;
            openLink = link;
        }

        bool AdsConfigured => config != null && !string.IsNullOrEmpty(config.AppKey);

        void Start()
        {
            _mode = Services.Get<GameMode>();
            allow.onClick.AddListener(() => Answer(true));
            deny.onClick.AddListener(() => Answer(false));
            openLink.onClick.AddListener(Open);
            openLink.gameObject.SetActive(AdsConfigured);
            dialog.SetActive(false);
        }

        void Update()
        {
            // first launch: ask once the menu is up
            if (!dialog.activeSelf && _mode.InMenu && AdsConfigured && !AdsConsent.Known) Open();
        }

        // click sounds come from the menu (it hooks every button on its canvas)
        void Open() => dialog.SetActive(true);

        void Answer(bool personalized)
        {
            AdsConsent.Set(personalized);
            dialog.SetActive(false);
        }
    }
}
