using System.Collections.Generic;
using FF.Core;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.UI;

namespace FF.UI.WorldTags
{
    /// <summary>
    /// One screen-space layer for every world tag (prototype <c>labels</c> / <c>updLabels</c>): pooled pills that
    /// follow world positions. Text is rewritten only when a value changes, so there is no per-frame garbage.
    /// Runs after the CinemachineBrain's LateUpdate so tags use this frame's camera.
    /// </summary>
    [DefaultExecutionOrder(10000)]
    public sealed class WorldTagLayer : MonoBehaviour
    {
        const float OffscreenMargin = 0.15f;
        /// <summary>Speed 8 + qty 3: the building is fully grown.</summary>
        const int MaxCombinedLevel = 11;

        [SerializeField] RectTransform pillTemplate;
        [SerializeField] Color counterColor = new Color32(0x2b, 0x1d, 0x14, 0xd6);
        [SerializeField] Color counterText = new Color32(0xfb, 0xf1, 0xde, 0xff);
        [SerializeField] Color fullColor = new Color32(0xd9, 0x57, 0x3b, 0xff);
        [SerializeField] Color fullText = Color.white;
        [SerializeField] Color cashColor = new Color32(0x3d, 0x8a, 0x31, 0xff);
        [SerializeField] Color bubbleColor = Color.white;
        [SerializeField] Color levelColor = new Color32(0xf3, 0xb3, 0x3d, 0xff);
        [SerializeField] Color levelText = new Color32(0x2b, 0x1d, 0x14, 0xff);
        [SerializeField] LocalizedString fullLabel = new LocalizedString("Game", "c.full");
        [SerializeField] LocalizedString maxLabel = new LocalizedString("Game", "ui.max");
        [Tooltip("Bubble icons by id: product ids, \"cash\", \"angry\".")]
        [SerializeField] List<BubbleIcon> icons = new List<BubbleIcon>();

        [System.Serializable]
        public struct BubbleIcon
        {
            public string id;
            public Sprite sprite;
            public Color color;
        }

        sealed class Pill
        {
            public RectTransform Rect;
            public Image Background;
            public TMP_Text Label;
            public Image Icon;
            public WorldTagStyle Style = (WorldTagStyle)(-1);
            public int Count = -1, Capacity = -1;
            public long ValueKey = -1;
            public string IconId;
            public bool TextDirty = true;
        }

        readonly List<Pill> _pills = new List<Pill>();
        RectTransform _rect;
        Camera _camera;
        WorldTagRegistry _registry;
        string _fullText = "FULL";
        string _maxText = "MAX";

        void Awake()
        {
            _rect = (RectTransform)transform;
            pillTemplate.gameObject.SetActive(false);
        }

        void OnEnable()
        {
            fullLabel.StringChanged += OnFullChanged;
            maxLabel.StringChanged += OnMaxChanged;
        }

        void OnDisable()
        {
            fullLabel.StringChanged -= OnFullChanged;
            maxLabel.StringChanged -= OnMaxChanged;
        }

        void OnMaxChanged(string value)
        {
            _maxText = value;
            foreach (Pill p in _pills)
                if (p.Style == WorldTagStyle.Level) p.TextDirty = true;
        }

        void Start()
        {
            _registry = Services.Get<WorldTagRegistry>();
            _camera = Camera.main;
        }

        void OnFullChanged(string value)
        {
            _fullText = value;
            foreach (Pill p in _pills)
                if (p.Style == WorldTagStyle.Full) p.TextDirty = true;
        }

        void LateUpdate()
        {
            if (_camera == null) return;
            IReadOnlyList<IWorldTagSource> sources = _registry.Sources;
            for (int i = 0; i < sources.Count; i++)
            {
                Pill pill = i < _pills.Count ? _pills[i] : CreatePill();
                IWorldTagSource s = sources[i];
                if (!s.TagVisible || !Project(s.TagPosition, out Vector2 local))
                {
                    if (pill.Rect.gameObject.activeSelf) pill.Rect.gameObject.SetActive(false);
                    continue;
                }
                if (!pill.Rect.gameObject.activeSelf) pill.Rect.gameObject.SetActive(true);
                pill.Rect.anchoredPosition = local;
                Refresh(pill, s);
            }
            for (int i = sources.Count; i < _pills.Count; i++)
                if (_pills[i].Rect.gameObject.activeSelf) _pills[i].Rect.gameObject.SetActive(false);
        }

        bool Project(Vector3 world, out Vector2 local)
        {
            Vector3 v = _camera.WorldToViewportPoint(world);
            local = default;
            if (v.z <= 0f || v.x < -OffscreenMargin || v.x > 1f + OffscreenMargin || v.y < -OffscreenMargin || v.y > 1f + OffscreenMargin)
                return false;
            // pills are anchored to the layer's bottom-left corner
            Rect r = _rect.rect;
            local = new Vector2(v.x * r.width, v.y * r.height);
            return true;
        }

        void Refresh(Pill pill, IWorldTagSource s)
        {
            WorldTagStyle style = s.TagStyle;
            if (pill.Style != style)
            {
                pill.Style = style;
                bool full = style == WorldTagStyle.Full, bubble = style == WorldTagStyle.Bubble;
                bool level = style == WorldTagStyle.Level;
                pill.Background.color = full ? fullColor : style == WorldTagStyle.Cash ? cashColor : bubble ? bubbleColor
                    : level ? levelColor : counterColor;
                pill.Label.color = style == WorldTagStyle.Counter ? counterText : level ? levelText : fullText;
                pill.Label.characterSpacing = full ? 6f : 0f;
                pill.Label.gameObject.SetActive(!bubble);
                pill.Icon.gameObject.SetActive(bubble);
                pill.TextDirty = true;
                pill.IconId = null;
                pill.ValueKey = -1;
            }

            if (style == WorldTagStyle.Full)
            {
                if (pill.TextDirty) pill.Label.SetText(_fullText);
            }
            else if (style == WorldTagStyle.Cash)
            {
                long value = s.TagValue, key = NumberFormat.CompactChangeKey(value);
                if (key != pill.ValueKey)
                {
                    pill.ValueKey = key;
                    pill.Label.SetText(NumberFormat.Money(value));
                }
            }
            else if (style == WorldTagStyle.Level)
            {
                int combined = s.TagCount, multiplier = s.TagCapacity;
                if (pill.TextDirty || combined != pill.Count || multiplier != pill.Capacity)
                {
                    pill.Count = combined;
                    pill.Capacity = multiplier;
                    // prototype: (l >= 11 ? MAX : "Lv " + (l + 1)) + " · ×" + (1 + q)
                    if (combined >= MaxCombinedLevel) pill.Label.SetText(_maxText + " · ×{0}", (float)multiplier);
                    else pill.Label.SetText("Lv {0} · ×{1}", (float)(combined + 1), (float)multiplier);
                }
            }
            else if (style == WorldTagStyle.Bubble)
            {
                string id = s.TagIcon;
                if (!ReferenceEquals(id, pill.IconId) && id != pill.IconId)
                {
                    pill.IconId = id;
                    SetIcon(pill.Icon, id);
                }
            }
            else
            {
                int count = s.TagCount, cap = s.TagCapacity;
                if (pill.TextDirty || count != pill.Count || cap != pill.Capacity)
                {
                    pill.Count = count;
                    pill.Capacity = cap;
                    pill.Label.SetText("{0}<alpha=#99>/{1}", (float)count, (float)cap);
                }
            }
            pill.TextDirty = false;
        }

        /// <summary>Editor tools only.</summary>
        public void SetIcons(List<BubbleIcon> list) => icons = list;

        void SetIcon(Image image, string id)
        {
            for (int i = 0; i < icons.Count; i++)
            {
                if (icons[i].id != id) continue;
                image.sprite = icons[i].sprite;
                image.color = icons[i].color;
                return;
            }
            image.sprite = null;
        }

        Pill CreatePill()
        {
            RectTransform rect = Instantiate(pillTemplate, transform);
            rect.name = "Tag";
            var pill = new Pill
            {
                Rect = rect,
                Background = rect.GetComponent<Image>(),
                Label = rect.GetComponentInChildren<TMP_Text>(true),
                Icon = rect.Find("Icon").GetComponent<Image>(),
            };
            _pills.Add(pill);
            return pill;
        }
    }
}
