using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.UI.HUD;
using FF.UI.Layout;
using FF.UI.Localization;
using FF.UI.WorldTags;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;
using static FF.Editor.GameSceneBuilder;

namespace FF.Editor
{
    /// <summary>
    /// HUD pieces of the prototype markup/CSS (sizes in CSS px × <see cref="GameSceneBuilder.Px"/>): money and level
    /// pills (top-left), tutorial bar and hint, level-up toast, and the bubble icons of the world tags.
    /// </summary>
    public static class HudBuilder
    {
        public static readonly Color32 Honey = UiPalette.Honey;
        static readonly Color Shadow = new Color(0, 0, 0, 0.28f);

        public static TMP_FontAsset Font(string weight) => AssetDatabase.LoadAssetAtPath<TMP_FontAsset>(FontSetup.ArmenianAssetPath(weight));

        /// <summary>Prototype <c>.hud-top .left</c>: money pill, level pill under it.</summary>
        public static void BuildTopLeft(Transform safe)
        {
            RectTransform column = Rect("TopLeft", safe);
            column.anchorMin = column.anchorMax = column.pivot = new Vector2(0, 1);
            column.anchoredPosition = new Vector2(16 * Px, -12 * Px);
            var v = column.gameObject.AddComponent<VerticalLayoutGroup>();
            v.spacing = 8 * Px;
            v.childAlignment = TextAnchor.UpperLeft;
            v.childControlWidth = v.childControlHeight = true;
            v.childForceExpandWidth = v.childForceExpandHeight = false;
            Fit(column.gameObject);

            // money: walnut pill, padding 5 16 5 5, coin 32 px, 20 px black digits
            RectTransform money = Pill("Money", column, UiPalette.Walnut, new RectOffset(5, 16, 5, 5), 8);
            RectTransform coin = Rect("Coin", money);
            Image coinImage = coin.gameObject.AddComponent<Image>();
            coinImage.sprite = TextureFactory.Coin();
            coinImage.raycastTarget = false;
            Size(coin.gameObject, 32, 32);
            TMP_Text sign = Text("Sign", coin, NumberFormat.Currency, 17, UiPalette.Walnut, "Black");
            Stretch((RectTransform)sign.transform);
            TMP_Text amount = Text("Amount", money, "0", 20, UiPalette.Cream, "Black");
            var moneyView = money.gameObject.AddComponent<MoneyView>();
            Wire(moneyView, "amount", amount);
            Wire(moneyView, "bumpTarget", money);

            // level: walnut pill, padding 4 12 4 4, green "Lv 1" chip + 74×7 bar
            RectTransform level = Pill("Level", column, UiPalette.Walnut, new RectOffset(4, 12, 4, 4), 8);
            RectTransform chip = Pill("Chip", level, UiPalette.Leaf, new RectOffset(9, 9, 3, 3), 0, false);
            TMP_Text lvText = Text("Text", chip, "Lv 1", 12, Color.white, "Black");
            RectTransform bar = Rect("Bar", level);
            Image barBg = bar.gameObject.AddComponent<Image>();
            barBg.sprite = TextureFactory.Pill();
            barBg.type = Image.Type.Sliced;
            barBg.color = UiPalette.Walnut3;
            barBg.raycastTarget = false;
            Size(bar.gameObject, 74, 7);
            RectTransform fill = Rect("Fill", bar);
            fill.anchorMin = Vector2.zero;
            fill.anchorMax = new Vector2(0, 1);
            fill.offsetMin = fill.offsetMax = Vector2.zero;
            Image fillImage = fill.gameObject.AddComponent<Image>();
            fillImage.sprite = TextureFactory.Pill();
            fillImage.type = Image.Type.Sliced;
            fillImage.color = UiPalette.Leaf;
            fillImage.raycastTarget = false;
            var levelView = level.gameObject.AddComponent<LevelView>();
            Wire(levelView, "level", lvText);
            Wire(levelView, "fill", fill);
        }

        /// <summary>Prototype <c>.quest</c> (top centre, 108 px below the safe top) and <c>.hint</c> (bottom centre).</summary>
        public static void BuildQuestBar(Transform safe)
        {
            RectTransform bar = Rect("QuestBar", safe);
            bar.anchorMin = bar.anchorMax = bar.pivot = new Vector2(0.5f, 1);
            bar.anchoredPosition = new Vector2(0, -108 * Px);
            Image bg = bar.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (14 * Px);
            bg.color = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.86f);
            bg.raycastTarget = false;
            Row(bar.gameObject, new RectOffset(8, 14, 8, 8), 10);
            Fit(bar.gameObject);

            RectTransform step = Pill("Step", bar, UiPalette.Leaf, new RectOffset(8, 8, 4, 4), 0, false);
            ((Image)step.GetComponent<Image>()).sprite = TextureFactory.Rounded();
            step.GetComponent<Image>().pixelsPerUnitMultiplier = 16f / (9 * Px);
            TMP_Text stepText = Text("Text", step, "1/8", 12, Color.white, "Black");
            TMP_Text text = Text("Text", bar, "", 14, UiPalette.Cream, "Bold");
            text.alignment = TextAlignmentOptions.Left;
            // .quest max-width: calc(100% - 32px), minus its own padding (8 + 14) and gap (10)
            Wrap(text, safe, (32 + 8 + 14 + 10) * Px, step);

            RectTransform hint = Rect("Hint", safe);
            hint.anchorMin = hint.anchorMax = hint.pivot = new Vector2(0.5f, 0);
            hint.anchoredPosition = new Vector2(0, 18 * Px);
            hint.sizeDelta = new Vector2(360 * Px, 18 * Px);
            TMP_Text hintText = hint.gameObject.AddComponent<TextMeshProUGUI>();
            hintText.font = Font("Bold");
            hintText.fontSize = 12 * Px;
            hintText.color = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.6f);
            hintText.alignment = TextAlignmentOptions.Center;
            hintText.textWrappingMode = TextWrappingModes.NoWrap;
            hintText.raycastTarget = false;
            hintText.text = "Քաշիր էկրանի վրա կամ սեղմիր WASD";
            hint.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.hint");

            var quest = safe.gameObject.AddComponent<QuestBar>();
            Wire(quest, "bar", bar.gameObject);
            Wire(quest, "stepLabel", stepText);
            Wire(quest, "text", text);
            Wire(quest, "hint", hint.gameObject);
        }

        /// <summary>Prototype <c>.toast</c>: centred at 34 % from the top, honey title 26 px, subtitle 14 px.</summary>
        public static void BuildToast(Transform safe)
        {
            RectTransform root = Rect("Toast", safe);
            Stretch(root);
            RectTransform panel = Rect("Panel", root);
            panel.anchorMin = panel.anchorMax = panel.pivot = new Vector2(0.5f, 0.66f);
            Image bg = panel.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (18 * Px);
            bg.color = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.92f);
            bg.raycastTarget = false;
            var shadow = panel.gameObject.AddComponent<UnityEngine.UI.Shadow>();
            shadow.effectColor = new Color(0, 0, 0, 0.25f);
            shadow.effectDistance = new Vector2(0, -6 * Px);
            var v = panel.gameObject.AddComponent<VerticalLayoutGroup>();
            v.padding = Scaled(new RectOffset(22, 22, 14, 14));
            v.spacing = 4 * Px;
            v.childAlignment = TextAnchor.MiddleCenter;
            v.childControlWidth = v.childControlHeight = true;
            v.childForceExpandWidth = v.childForceExpandHeight = false;
            Fit(panel.gameObject);
            var group = panel.gameObject.AddComponent<CanvasGroup>();
            group.blocksRaycasts = false;
            group.interactable = false;

            TMP_Text title = Text("Title", panel, "Level 2", 26, Honey, "Black");
            TMP_Text subtitle = Text("Subtitle", panel, "", 14, UiPalette.Cream, "Bold");
            // .toast max-width: calc(100% - 32px), minus its padding 22 + 22
            Wrap(subtitle, safe, (32 + 44) * Px, null);

            var toast = root.gameObject.AddComponent<LevelToast>();
            Wire(toast, "panel", panel);
            Wire(toast, "group", group);
            Wire(toast, "title", title);
            Wire(toast, "subtitle", subtitle);
        }

        /// <summary>Bubble icons from the prototype SVGs: one per product, the cash note and the angry face.</summary>
        public static List<WorldTagLayer.BubbleIcon> BubbleIcons(GameDatabase db)
        {
            Color walnut = UiPalette.Walnut;
            var list = new List<WorldTagLayer.BubbleIcon>();
            void Add(string id, Sprite sprite, Color color) => list.Add(new WorldTagLayer.BubbleIcon { id = id, sprite = sprite, color = color });

            foreach (ProductDef p in db.products)
            {
                Sprite s = ProductIcon(p.id);
                if (s != null) Add(p.id, s, walnut);
            }
            Add("cash", TextureFactory.LineIcon("cash", 2.1f,
                TextureFactory.RoundRect(3, 7, 18, 11, 2), TextureFactory.Circle(12, 12.5f, 2.4f),
                TextureFactory.Poly(6, 10, 6, 15), TextureFactory.Poly(18, 10, 18, 15)), UiPalette.LeafDark);
            Add("angry", TextureFactory.LineIcon("angry", 2.2f,
                TextureFactory.Circle(12, 12, 9), TextureFactory.Poly(8, 9, 10, 10), TextureFactory.Poly(16, 9, 14, 10),
                TextureFactory.Cubic(new Vector2(8.5f, 16.5f), new Vector2(10.5f, 14.9f), new Vector2(13.5f, 14.9f), new Vector2(15.5f, 16.5f))),
                UiPalette.Danger);
            return list;
        }

        /// <summary>Prototype <c>ICON</c> paths (stroke 2.1).</summary>
        static Sprite ProductIcon(string id)
        {
            const float w = 2.1f;
            switch (id)
            {
                case "chair":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Poly(8, 3, 8, 21), TextureFactory.Poly(8, 12, 17, 12, 17, 21));
                case "sofa":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Poly(5, 10, 5, 7, 19, 7, 19, 10),
                        TextureFactory.Closed(3, 10, 6, 10, 6, 14, 18, 14, 18, 10, 21, 10, 21, 17, 3, 17),
                        TextureFactory.Poly(5, 17, 5, 19), TextureFactory.Poly(19, 17, 19, 19));
                case "wardrobe":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Closed(6, 3, 18, 3, 18, 20, 6, 20), TextureFactory.Poly(12, 3, 12, 20),
                        TextureFactory.Poly(10, 11, 10, 13), TextureFactory.Poly(14, 11, 14, 13), TextureFactory.Poly(7, 20, 7, 21), TextureFactory.Poly(17, 20, 17, 21));
                case "table":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Poly(3, 9, 21, 9), TextureFactory.Poly(5, 9, 5, 20),
                        TextureFactory.Poly(19, 9, 19, 20), TextureFactory.Poly(7, 9, 7, 8, 17, 8, 17, 9));
                case "kitchen":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Closed(4, 9, 20, 9, 20, 20, 4, 20), TextureFactory.Poly(3, 9, 21, 9),
                        TextureFactory.Poly(12, 9, 12, 20), TextureFactory.Poly(9, 13, 7, 13), TextureFactory.Poly(17, 13, 15, 13), TextureFactory.Poly(8, 5, 11, 5, 11, 9));
                case "sink":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Closed(5, 9, 19, 9, 17, 14, 7, 14), TextureFactory.Poly(12, 14, 12, 20),
                        TextureFactory.Poly(9, 20, 15, 20), TextureFactory.Poly(12, 9, 12, 5, 15, 5));
                case "material":
                    return TextureFactory.LineIcon(id, w, TextureFactory.Poly(3, 8, 21, 8), TextureFactory.Poly(3, 12, 21, 12),
                        TextureFactory.Poly(3, 16, 21, 16), TextureFactory.Poly(7, 6, 7, 18), TextureFactory.Poly(17, 6, 17, 18));
                default:
                    Debug.LogWarning($"[FF] No bubble icon for product '{id}'.");
                    return null;
            }
        }

        // ---------- helpers ----------

        static RectTransform Pill(string name, Transform parent, Color color, RectOffset padding, float spacing, bool shadow = true)
        {
            RectTransform r = Rect(name, parent);
            Image bg = r.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Pill();
            bg.type = Image.Type.Sliced;
            bg.color = color;
            bg.raycastTarget = false;
            if (shadow)
            {
                var s = r.gameObject.AddComponent<UnityEngine.UI.Shadow>();
                s.effectColor = Shadow;
                s.effectDistance = new Vector2(0, -3 * Px);
            }
            Row(r.gameObject, padding, spacing);
            Fit(r.gameObject);
            return r;
        }

        static void Wrap(TMP_Text text, Transform bounds, float reserved, RectTransform sibling)
        {
            text.gameObject.AddComponent<LayoutElement>();
            text.gameObject.AddComponent<WrapToWidth>().Setup((RectTransform)bounds, reserved, sibling);
        }

        static void Row(GameObject go, RectOffset padding, float spacing)
        {
            var h = go.AddComponent<HorizontalLayoutGroup>();
            h.padding = Scaled(padding);
            h.spacing = spacing * Px;
            h.childAlignment = TextAnchor.MiddleLeft;
            h.childControlWidth = h.childControlHeight = true;
            h.childForceExpandWidth = h.childForceExpandHeight = false;
        }

        static void Fit(GameObject go)
        {
            var f = go.AddComponent<ContentSizeFitter>();
            f.horizontalFit = f.verticalFit = ContentSizeFitter.FitMode.PreferredSize;
        }

        static void Size(GameObject go, float w, float h)
        {
            var e = go.AddComponent<LayoutElement>();
            e.preferredWidth = e.minWidth = w * Px;
            e.preferredHeight = e.minHeight = h * Px;
        }

        static RectOffset Scaled(RectOffset p) =>
            new RectOffset(Mathf.RoundToInt(p.left * Px), Mathf.RoundToInt(p.right * Px), Mathf.RoundToInt(p.top * Px), Mathf.RoundToInt(p.bottom * Px));

        static TMP_Text Text(string name, Transform parent, string text, float cssPx, Color color, string weight)
        {
            RectTransform r = Rect(name, parent);
            var t = r.gameObject.AddComponent<TextMeshProUGUI>();
            t.font = Font(weight);
            t.text = text;
            t.fontSize = cssPx * Px;
            t.color = color;
            t.alignment = TextAlignmentOptions.Center;
            t.textWrappingMode = TextWrappingModes.NoWrap;
            t.raycastTarget = false;
            return t;
        }
    }
}
