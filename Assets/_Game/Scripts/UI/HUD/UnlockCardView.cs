using System.Collections.Generic;
using FF.Core;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.HUD
{
    /// <summary>
    /// Prototype <c>#unlock</c> card: cream card with a honey border, icon tile, "NEW", title and subtitle; slides in
    /// from 30 px above with a slight overshoot (0.45 s). Timing and the queue live in the gameplay UnlockService.
    /// </summary>
    public sealed class UnlockCardView : MonoBehaviour
    {
        const float SlideSeconds = 0.45f;
        const float SlideFrom = 30f * 1080f / 390f;

        [System.Serializable]
        public struct Icon
        {
            public string id;
            public Sprite sprite;
        }

        [SerializeField] RectTransform card;
        [SerializeField] CanvasGroup group;
        [SerializeField] Image icon;
        [SerializeField] TMP_Text title;
        [SerializeField] TMP_Text subtitle;
        [SerializeField] List<Icon> icons = new List<Icon>();

        Vector2 _restPosition;
        float _time = -1f;

        /// <summary>Editor tools only.</summary>
        public void Setup(RectTransform cardRect, CanvasGroup cardGroup, Image iconImage, TMP_Text titleText, TMP_Text subtitleText, List<Icon> iconList)
        {
            card = cardRect;
            group = cardGroup;
            icon = iconImage;
            title = titleText;
            subtitle = subtitleText;
            icons = iconList;
        }

        void Awake()
        {
            _restPosition = card.anchoredPosition;
            card.gameObject.SetActive(false);
        }

        void OnEnable()
        {
            GameEvents.UnlockCardShown += Show;
            GameEvents.UnlockCardHidden += Hide;
        }

        void OnDisable()
        {
            GameEvents.UnlockCardShown -= Show;
            GameEvents.UnlockCardHidden -= Hide;
        }

        void Show(string iconId, string titleText, string subtitleText)
        {
            foreach (Icon i in icons)
                if (i.id == iconId) icon.sprite = i.sprite;
            title.SetText(titleText);
            subtitle.SetText(subtitleText);
            card.gameObject.SetActive(true);
            _time = 0f;
        }

        void Hide()
        {
            card.gameObject.SetActive(false);
            _time = -1f;
        }

        void LateUpdate()
        {
            if (_time < 0f || _time > SlideSeconds) return;
            _time += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(_time / SlideSeconds);
            // ease-out-back ≈ cubic-bezier(.2, 1.4, .4, 1)
            const float c1 = 1.70158f, c3 = c1 + 1f;
            float eased = 1f + c3 * Mathf.Pow(k - 1f, 3f) + c1 * Mathf.Pow(k - 1f, 2f);
            card.anchoredPosition = _restPosition + new Vector2(0f, SlideFrom * (1f - eased));
            group.alpha = Mathf.Clamp01(k * 2f);
        }
    }
}
