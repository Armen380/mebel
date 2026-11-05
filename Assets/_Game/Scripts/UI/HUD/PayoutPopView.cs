using FF.Core;
using TMPro;
using UnityEngine;

namespace FF.UI.HUD
{
    /// <summary>
    /// Prototype <c>moneyPop</c> / <c>.mpop</c>: a small green chip with a truck icon and "+$12K" to the right of the
    /// balance when a truck delivered; slides in, holds, rises and fades over 2.2 s. A few chips are pooled so pops overlap.
    /// </summary>
    public sealed class PayoutPopView : MonoBehaviour
    {
        const float Seconds = 2.2f;
        const float FadeIn = 0.1f, FadeOut = 0.75f;

        [System.Serializable]
        public sealed class Chip
        {
            public RectTransform rect;
            public CanvasGroup group;
            public TMP_Text label;
            [System.NonSerialized] public float age = -1f;
        }

        [SerializeField] Chip[] chips = System.Array.Empty<Chip>();
        [Tooltip("Slide-in distance (canvas units, prototype 8 px).")]
        [SerializeField] float slide = 22f;

        int _next;

        /// <summary>Editor tools only.</summary>
        public void Setup(Chip[] chipList, float slideDistance)
        {
            chips = chipList;
            slide = slideDistance;
        }

        void Awake()
        {
            foreach (Chip c in chips) c.rect.gameObject.SetActive(false);
        }

        void OnEnable() => GameEvents.TruckDelivered += OnDelivered;

        void OnDisable() => GameEvents.TruckDelivered -= OnDelivered;

        void OnDelivered(long payout)
        {
            if (chips.Length == 0) return;
            Chip c = chips[_next];
            _next = (_next + 1) % chips.Length;
            c.label.SetText("+" + NumberFormat.Money(payout));
            c.age = 0f;
            c.rect.gameObject.SetActive(true);
            c.rect.SetAsLastSibling();
            Apply(c);
        }

        void Update()
        {
            float dt = Time.unscaledDeltaTime;
            for (int i = 0; i < chips.Length; i++)
            {
                Chip c = chips[i];
                if (c.age < 0f) continue;
                c.age += dt;
                if (c.age >= Seconds)
                {
                    c.age = -1f;
                    c.rect.gameObject.SetActive(false);
                    continue;
                }
                Apply(c);
            }
        }

        /// <summary>CSS keyframes: 0 % (opacity 0, −8 px) → 10 % (1, 0) → 75 % (1, 0) → 100 % (0, up by 80 % of its height).</summary>
        void Apply(Chip c)
        {
            float t = c.age / Seconds;
            float alpha, x = 0f, y = 0f;
            if (t < FadeIn)
            {
                float k = t / FadeIn;
                alpha = k;
                x = -slide * (1f - k);
            }
            else if (t < FadeOut) alpha = 1f;
            else
            {
                float k = (t - FadeOut) / (1f - FadeOut);
                alpha = 1f - k;
                y = c.rect.rect.height * 0.8f * k;
            }
            c.group.alpha = alpha;
            c.rect.anchoredPosition = new Vector2(x, y);
        }
    }
}
