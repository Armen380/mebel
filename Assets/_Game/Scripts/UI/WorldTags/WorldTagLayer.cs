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

        [SerializeField] RectTransform pillTemplate;
        [SerializeField] Color counterColor = new Color32(0x2b, 0x1d, 0x14, 0xd6);
        [SerializeField] Color counterText = new Color32(0xfb, 0xf1, 0xde, 0xff);
        [SerializeField] Color fullColor = new Color32(0xd9, 0x57, 0x3b, 0xff);
        [SerializeField] Color fullText = Color.white;
        [SerializeField] LocalizedString fullLabel = new LocalizedString("Game", "c.full");

        sealed class Pill
        {
            public RectTransform Rect;
            public Image Background;
            public TMP_Text Label;
            public WorldTagStyle Style = (WorldTagStyle)(-1);
            public int Count = -1, Capacity = -1;
            public bool TextDirty = true;
        }

        readonly List<Pill> _pills = new List<Pill>();
        RectTransform _rect;
        Camera _camera;
        WorldTagRegistry _registry;
        string _fullText = "FULL";

        void Awake()
        {
            _rect = (RectTransform)transform;
            pillTemplate.gameObject.SetActive(false);
        }

        void OnEnable() => fullLabel.StringChanged += OnFullChanged;

        void OnDisable() => fullLabel.StringChanged -= OnFullChanged;

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
                bool full = style == WorldTagStyle.Full;
                pill.Background.color = full ? fullColor : counterColor;
                pill.Label.color = full ? fullText : counterText;
                pill.Label.characterSpacing = full ? 6f : 0f;
                pill.TextDirty = true;
            }

            if (style == WorldTagStyle.Full)
            {
                if (pill.TextDirty) pill.Label.SetText(_fullText);
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

        Pill CreatePill()
        {
            RectTransform rect = Instantiate(pillTemplate, transform);
            rect.name = "Tag";
            var pill = new Pill
            {
                Rect = rect,
                Background = rect.GetComponent<Image>(),
                Label = rect.GetComponentInChildren<TMP_Text>(true),
            };
            _pills.Add(pill);
            return pill;
        }
    }
}
