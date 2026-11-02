using FF.Core;
using TMPro;
using UnityEngine;
using UnityEngine.Localization.Settings;
using UnityEngine.UI;

namespace FF.UI.DevTools
{
    /// <summary>
    /// Dev buttons until the real menu (M9), shown only in the Editor and development builds: the prototype's
    /// "Test: +25 Lv, +$250K" and "New game" (second tap within 3 s confirms, like the prototype's reset button).
    /// </summary>
    public sealed class DevPanel : MonoBehaviour
    {
        const string Table = "Game";
        const int TestLevels = 25;
        const long TestMoney = 250_000;
        const float ConfirmSeconds = 3f;

        [SerializeField] Button testButton;
        [SerializeField] Button newGameButton;
        [SerializeField] TMP_Text newGameLabel;

        float _armedUntil = -1f;

        /// <summary>Editor tools only.</summary>
        public void Setup(Button test, Button newGame, TMP_Text newGameText)
        {
            testButton = test;
            newGameButton = newGame;
            newGameLabel = newGameText;
        }

        void Awake()
        {
            if (!Debug.isDebugBuild)
            {
                gameObject.SetActive(false);
                return;
            }
            testButton.onClick.AddListener(() => Services.Get<IDevCheats>().AddLevelsAndMoney(TestLevels, TestMoney));
            newGameButton.onClick.AddListener(OnNewGame);
        }

        void OnNewGame()
        {
            if (Time.unscaledTime > _armedUntil)
            {
                _armedUntil = Time.unscaledTime + ConfirmSeconds;
                newGameLabel.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "ui.reset"));
                return;
            }
            Services.Get<ISaveService>().DeleteAndRestart();
        }

        void Update()
        {
            if (_armedUntil < 0f || Time.unscaledTime <= _armedUntil) return;
            _armedUntil = -1f;
            newGameLabel.SetText(LocalizationSettings.StringDatabase.GetLocalizedString(Table, "ui.new"));
        }
    }
}
