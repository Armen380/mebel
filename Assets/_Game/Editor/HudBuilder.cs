using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.UI.HUD;
using FF.UI.Input;
using FF.UI.Layout;
using FF.UI.Upgrades;
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
        static readonly Color Walnut2 = new Color32(0x3a, 0x28, 0x1b, 0xff);
        static readonly Color Muted = new Color32(0xcb, 0xb6, 0x97, 0xff);

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

            var toast = root.gameObject.AddComponent<ToastView>();
            Wire(toast, "panel", panel);
            Wire(toast, "group", group);
            Wire(toast, "title", title);
            Wire(toast, "subtitle", subtitle);
        }

        /// <summary>Prototype <c>.btn-up</c>: honey 44 px button top-right with the upgrade icon, label and red badge.</summary>
        public static RectTransform BuildUpgradesButton(Transform safe, out GameObject badge)
        {
            RectTransform root = Rect("UpgradesButton", safe);
            root.anchorMin = root.anchorMax = root.pivot = new Vector2(1, 1);
            root.anchoredPosition = new Vector2(-16 * Px, -12 * Px);
            Image bg = root.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (14 * Px);
            bg.color = UiPalette.Honey;
            var shadow = root.gameObject.AddComponent<UnityEngine.UI.Shadow>();
            shadow.effectColor = UiPalette.HoneyDark;
            shadow.effectDistance = new Vector2(0, -4 * Px);
            var button = root.gameObject.AddComponent<Button>();
            button.targetGraphic = bg;
            Row(root.gameObject, new RectOffset(10, 14, 0, 0), 6);
            root.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
            Fit(root.gameObject);
            var height = root.gameObject.AddComponent<LayoutElement>();
            height.minHeight = height.preferredHeight = 44 * Px;

            RectTransform icon = Rect("Icon", root);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.sprite = UpgradeIcon();
            iconImage.color = UiPalette.Walnut;
            iconImage.raycastTarget = false;
            Size(icon.gameObject, 22, 22);
            TMP_Text label = Text("Label", root, "Բարելավել", 14, UiPalette.Walnut, "Black");
            label.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.upgrade");

            // .badge: 14 px red dot with a 2 px cream ring, top/right −5 px
            RectTransform ring = Rect("Badge", root);
            ring.gameObject.AddComponent<LayoutElement>().ignoreLayout = true;
            ring.anchorMin = ring.anchorMax = new Vector2(1, 1);
            ring.anchoredPosition = new Vector2(-2 * Px, -2 * Px);
            ring.sizeDelta = new Vector2(14 * Px, 14 * Px);
            Image ringImage = ring.gameObject.AddComponent<Image>();
            ringImage.sprite = TextureFactory.Circle();
            ringImage.color = UiPalette.Cream;
            ringImage.raycastTarget = false;
            RectTransform dot = Rect("Dot", ring);
            dot.anchorMin = dot.anchorMax = new Vector2(0.5f, 0.5f);
            dot.sizeDelta = new Vector2(10 * Px, 10 * Px);
            Image dotImage = dot.gameObject.AddComponent<Image>();
            dotImage.sprite = TextureFactory.Circle();
            dotImage.color = UiPalette.Danger;
            dotImage.raycastTarget = false;
            badge = ring.gameObject;
            return root;
        }

        /// <summary>
        /// Prototype <c>.sheet</c>: dimmed backdrop and a walnut bottom sheet (max 560 px wide, 84 % high) with the
        /// title, balance, close button and a scrolling list (pad note, group headers, upgrade rows).
        /// </summary>
        public static void BuildUpgradesPanel(Transform hud, GameDatabase db, Button openButton, GameObject badge, VirtualJoystick joystick)
        {
            RectTransform sheet = Rect("UpgradesSheet", hud);
            Stretch(sheet);
            Image dim = sheet.gameObject.AddComponent<Image>();
            dim.color = new Color(20 / 255f, 12 / 255f, 8 / 255f, 0.5f);
            var backdrop = sheet.gameObject.AddComponent<Button>();
            backdrop.transition = Selectable.Transition.None;

            const float corner = 26;
            RectTransform panel = Rect("Panel", sheet);
            panel.anchorMin = new Vector2(0.5f, 0);
            panel.anchorMax = new Vector2(0.5f, 0.84f);
            panel.pivot = new Vector2(0.5f, 0);
            panel.sizeDelta = new Vector2(560 * Px, corner * Px); // bottom corners hang below the screen
            panel.anchoredPosition = new Vector2(0, -corner * Px);
            Image panelBg = panel.gameObject.AddComponent<Image>();
            panelBg.sprite = TextureFactory.Rounded();
            panelBg.type = Image.Type.Sliced;
            panelBg.pixelsPerUnitMultiplier = 16f / (corner * Px);
            panelBg.color = UiPalette.Walnut;
            var column = panel.gameObject.AddComponent<VerticalLayoutGroup>();
            column.childControlWidth = column.childControlHeight = true;
            column.childForceExpandWidth = true;
            column.childForceExpandHeight = false;

            // head: title + balance, close button
            RectTransform head = Rect("Head", panel);
            Row(head.gameObject, new RectOffset(20, 16, 18, 10), 12);
            RectTransform titles = Rect("Titles", head);
            var titleColumn = titles.gameObject.AddComponent<VerticalLayoutGroup>();
            titleColumn.childControlWidth = titleColumn.childControlHeight = true;
            titleColumn.childForceExpandWidth = titleColumn.childForceExpandHeight = false;
            titles.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            TMP_Text title = Text("Title", titles, "Բարելավումներ", 22, UiPalette.Cream, "Black");
            title.alignment = TextAlignmentOptions.Left;
            title.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.upTitle");
            TMP_Text balance = Text("Balance", titles, "", 14, UiPalette.Honey, "ExtraBold");
            balance.alignment = TextAlignmentOptions.Left;

            RectTransform close = Rect("Close", head);
            Image closeBg = close.gameObject.AddComponent<Image>();
            closeBg.sprite = TextureFactory.Rounded();
            closeBg.type = Image.Type.Sliced;
            closeBg.pixelsPerUnitMultiplier = 16f / (14 * Px);
            closeBg.color = UiPalette.Walnut;
            var closeShadow = close.gameObject.AddComponent<UnityEngine.UI.Shadow>();
            closeShadow.effectColor = Shadow;
            closeShadow.effectDistance = new Vector2(0, -4 * Px);
            var closeButton = close.gameObject.AddComponent<Button>();
            closeButton.targetGraphic = closeBg;
            Size(close.gameObject, 44, 44);
            RectTransform x = Rect("Icon", close);
            x.anchorMin = x.anchorMax = new Vector2(0.5f, 0.5f);
            x.sizeDelta = new Vector2(22 * Px, 22 * Px);
            Image xImage = x.gameObject.AddComponent<Image>();
            xImage.sprite = TextureFactory.LineIcon("close", 2.6f, TextureFactory.Poly(6, 6, 18, 18), TextureFactory.Poly(18, 6, 6, 18));
            xImage.color = UiPalette.Cream;
            xImage.raycastTarget = false;

            // body: scrolling list
            RectTransform body = Rect("Body", panel);
            body.gameObject.AddComponent<LayoutElement>().flexibleHeight = 1;
            body.gameObject.AddComponent<RectMask2D>();
            var scroll = body.gameObject.AddComponent<ScrollRect>();
            scroll.horizontal = false;
            scroll.movementType = ScrollRect.MovementType.Clamped;
            scroll.scrollSensitivity = 30;
            RectTransform content = Rect("Content", body);
            content.anchorMin = new Vector2(0, 1);
            content.anchorMax = new Vector2(1, 1);
            content.pivot = new Vector2(0.5f, 1);
            content.offsetMin = content.offsetMax = Vector2.zero;
            var list = content.gameObject.AddComponent<VerticalLayoutGroup>();
            list.padding = Scaled(new RectOffset(20, 20, 0, 20 + (int)corner));
            list.spacing = 6 * Px;
            list.childControlWidth = list.childControlHeight = true;
            list.childForceExpandWidth = true;
            list.childForceExpandHeight = false;
            var listFit = content.gameObject.AddComponent<ContentSizeFitter>();
            listFit.verticalFit = ContentSizeFitter.FitMode.PreferredSize;
            scroll.content = content;
            scroll.viewport = body;

            // .note
            RectTransform noteBox = Card("Note", content, Walnut2, 12);
            Row(noteBox.gameObject, new RectOffset(12, 12, 10, 10), 0);
            TMP_Text note = Text("Text", noteBox, "", 12.5f, Muted, "Bold");
            note.alignment = TextAlignmentOptions.Left;
            note.textWrappingMode = TextWrappingModes.Normal;
            note.lineSpacing = 8;

            // .grp
            TMP_Text group = Text("GroupTemplate", content, "GROUP", 12, Muted, "ExtraBold");
            group.alignment = TextAlignmentOptions.Left;
            group.fontStyle = FontStyles.UpperCase;
            group.characterSpacing = 12;
            group.margin = new Vector4(0, 12 * Px, 0, 0);

            UpgradeRow row = Row(content);

            // on the always-active HUD root: the sheet itself is hidden while closed, the badge must keep updating
            foreach (UpgradesPanel old in hud.GetComponents<UpgradesPanel>()) Object.DestroyImmediate(old);
            var panelScript = hud.gameObject.AddComponent<UpgradesPanel>();
            panelScript.Setup(openButton, badge, sheet.gameObject, panel, closeButton, backdrop, balance, note, content, row, group, joystick);
        }

        /// <summary>Prototype <c>.up</c> row: name, description, pips + value, buy button.</summary>
        static UpgradeRow Row(Transform parent)
        {
            RectTransform row = Card("RowTemplate", parent, Walnut2, 16);
            var h = row.gameObject.AddComponent<HorizontalLayoutGroup>();
            h.padding = Scaled(new RectOffset(14, 12, 12, 12));
            h.spacing = 12 * Px;
            h.childAlignment = TextAnchor.MiddleLeft;
            h.childControlWidth = h.childControlHeight = true;
            h.childForceExpandWidth = h.childForceExpandHeight = false;

            RectTransform left = Rect("Info", row);
            var v = left.gameObject.AddComponent<VerticalLayoutGroup>();
            v.spacing = 2 * Px;
            v.childControlWidth = v.childControlHeight = true;
            v.childForceExpandWidth = true;
            v.childForceExpandHeight = false;
            left.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            TMP_Text name = Text("Name", left, "", 16, UiPalette.Cream, "ExtraBold");
            name.alignment = TextAlignmentOptions.Left;
            TMP_Text desc = Text("Description", left, "", 12.5f, Muted, "Bold");
            desc.alignment = TextAlignmentOptions.Left;
            desc.textWrappingMode = TextWrappingModes.Normal;

            // .v: pips, then "now → next" on its own line (one line does not fit a phone row)
            RectTransform valueBlock = Rect("Value", left);
            var valueColumn = valueBlock.gameObject.AddComponent<VerticalLayoutGroup>();
            valueColumn.padding = Scaled(new RectOffset(0, 0, 6, 0));
            valueColumn.spacing = 4 * Px;
            valueColumn.childControlWidth = valueColumn.childControlHeight = true;
            valueColumn.childForceExpandWidth = valueColumn.childForceExpandHeight = false;
            RectTransform pips = Rect("Pips", valueBlock);
            Row(pips.gameObject, new RectOffset(0, 0, 0, 0), 3);
            for (int i = 0; i < 8; i++)
            {
                RectTransform pip = Rect("Pip", pips);
                Image pipImage = pip.gameObject.AddComponent<Image>();
                pipImage.sprite = TextureFactory.Rounded();
                pipImage.type = Image.Type.Sliced;
                pipImage.pixelsPerUnitMultiplier = 16f / (2 * Px);
                pipImage.color = UiPalette.Walnut3;
                pipImage.raycastTarget = false;
                Size(pip.gameObject, 10, 6);
            }
            RectTransform valueRow = Rect("Texts", valueBlock);
            Row(valueRow.gameObject, new RectOffset(0, 0, 0, 0), 8);
            TMP_Text value = Text("Now", valueRow, "", 12, UiPalette.Cream, "Bold");
            value.alignment = TextAlignmentOptions.Left;
            RectTransform arrow = Rect("Arrow", valueRow);
            Image arrowImage = arrow.gameObject.AddComponent<Image>();
            arrowImage.sprite = TextureFactory.LineIcon("arrow", 2.6f, TextureFactory.Poly(4, 12, 19, 12), TextureFactory.Poly(13, 6, 19, 12, 13, 18));
            arrowImage.color = UiPalette.Cream;
            arrowImage.raycastTarget = false;
            Size(arrow.gameObject, 12, 12);
            TMP_Text next = Text("Next", valueRow, "", 12, UiPalette.Cream, "Bold");
            next.alignment = TextAlignmentOptions.Left;

            // .buy: min 96 × 44, radius 12, green with a darker 4 px lip
            RectTransform buy = Rect("Buy", row);
            Image buyBg = buy.gameObject.AddComponent<Image>();
            buyBg.sprite = TextureFactory.Rounded();
            buyBg.type = Image.Type.Sliced;
            buyBg.pixelsPerUnitMultiplier = 16f / (12 * Px);
            buyBg.color = UiPalette.Leaf;
            var lip = buy.gameObject.AddComponent<UnityEngine.UI.Shadow>();
            lip.effectColor = UiPalette.LeafDark;
            lip.effectDistance = new Vector2(0, -4 * Px);
            var button = buy.gameObject.AddComponent<Button>();
            button.targetGraphic = buyBg;
            button.transition = Selectable.Transition.None;
            Row(buy.gameObject, new RectOffset(12, 12, 0, 0), 0);
            buy.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
            var buySize = buy.gameObject.AddComponent<LayoutElement>();
            buySize.minWidth = 96 * Px;
            buySize.minHeight = buySize.preferredHeight = 44 * Px;
            TMP_Text label = Text("Label", buy, "$0", 15, Color.white, "Black");

            var upgradeRow = row.gameObject.AddComponent<UpgradeRow>();
            upgradeRow.Setup(name, desc, value, arrow.gameObject, next, pips, button, buyBg, label, lip, 15 * Px, 12.5f * Px);
            return upgradeRow;
        }

        static RectTransform Card(string name, Transform parent, Color color, float radius)
        {
            RectTransform r = Rect(name, parent);
            Image bg = r.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (radius * Px);
            bg.color = color;
            bg.raycastTarget = false;
            return r;
        }

        /// <summary>Prototype upgrade button icon: person + plus (stroke 2.4).</summary>
        static Sprite UpgradeIcon()
        {
            var head = TextureFactory.Circle(9, 8, 3.2f);
            // M3.5 19c.6-3.2 2.8-5 5.5-5s4.9 1.8 5.5 5
            var shoulders1 = TextureFactory.Cubic(new Vector2(3.5f, 19), new Vector2(4.1f, 15.8f), new Vector2(6.3f, 14), new Vector2(9, 14));
            var shoulders2 = TextureFactory.Cubic(new Vector2(9, 14), new Vector2(11.7f, 14), new Vector2(13.9f, 15.8f), new Vector2(14.5f, 19));
            return TextureFactory.LineIcon("upgrade", 2.4f, head, shoulders1, shoulders2, TextureFactory.Poly(17, 8, 17, 14), TextureFactory.Poly(14, 11, 20, 11));
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
