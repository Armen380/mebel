using System.Collections.Generic;
using FF.Data;
using FF.Editor.Art;
using FF.UI.Home;
using FF.UI.HUD;
using FF.UI.Input;
using FF.UI.Localization;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using static FF.Editor.GameSceneBuilder;
using static FF.Editor.HudBuilder;

namespace FF.Editor
{
    /// <summary>Dream House HUD pieces (M10): the variant picker, the Home Store catalog and the comfort chip.</summary>
    public static class HomeHudBuilder
    {
        static readonly Color Walnut = new Color32(0x2b, 0x1d, 0x14, 0xf0);

        /// <summary>Icons for every catalog group (parallel arrays for the UI components).</summary>
        public static void GroupIcons(HomeDef home, out string[] groups, out Sprite[] sprites)
        {
            var g = new List<string>();
            var s = new List<Sprite>();
            foreach (HomeDef.HomeItemDef item in home.items)
            {
                if (g.Contains(item.group)) continue;
                g.Add(item.group);
                s.Add(TextureFactory.HomeIcon(item.group));
            }
            groups = g.ToArray();
            sprites = s.ToArray();
        }

        /// <summary>Row of up to three variant buttons above the bottom of the screen.</summary>
        public static void BuildVariantPicker(Transform safe, GameDatabase db)
        {
            RectTransform root = Rect("VariantPicker", safe);
            Stretch(root);
            RectTransform panel = Rect("Panel", root);
            panel.anchorMin = panel.anchorMax = panel.pivot = new Vector2(0.5f, 0.24f);
            var row = panel.gameObject.AddComponent<HorizontalLayoutGroup>();
            row.spacing = 10 * Px;
            row.childAlignment = TextAnchor.MiddleCenter;
            row.childControlWidth = row.childControlHeight = true;
            row.childForceExpandWidth = row.childForceExpandHeight = false;
            Fit(panel.gameObject);

            var buttons = new Button[3];
            var icons = new Image[3];
            var labels = new TMP_Text[3];
            for (int i = 0; i < 3; i++)
            {
                RectTransform card = Card("Variant" + i, panel, Walnut, 16);
                card.GetComponent<Image>().raycastTarget = true;
                var v = card.gameObject.AddComponent<VerticalLayoutGroup>();
                v.padding = Scaled(new RectOffset(10, 10, 8, 8));
                v.spacing = 4 * Px;
                v.childAlignment = TextAnchor.MiddleCenter;
                v.childControlWidth = v.childControlHeight = true;
                v.childForceExpandWidth = v.childForceExpandHeight = false;
                Size(card.gameObject, 96, 92);
                RectTransform icon = Rect("Icon", card);
                icons[i] = icon.gameObject.AddComponent<Image>();
                icons[i].color = UiPalette.Honey;
                icons[i].raycastTarget = false;
                Size(icon.gameObject, 40, 40);
                labels[i] = Text("Name", card, "Carpet", 12, UiPalette.Cream, "Bold");
                labels[i].textWrappingMode = TextWrappingModes.Normal;
                labels[i].enableAutoSizing = true;
                labels[i].fontSizeMin = 8 * Px;
                labels[i].fontSizeMax = 12 * Px;
                Size(labels[i].gameObject, 80, 30);
                buttons[i] = card.gameObject.AddComponent<Button>();
            }
            GroupIcons(db.home, out string[] groups, out Sprite[] sprites);
            root.gameObject.AddComponent<VariantPicker>().Setup(panel.gameObject, buttons, icons, labels, groups, sprites);
        }
        static readonly Color Walnut2 = new Color32(0x3a, 0x28, 0x1b, 0xff);
        static readonly Color Muted = new Color32(0xcb, 0xb6, 0x97, 0xff);

        /// <summary>Home Store catalog sheet (Upgrades-panel style) with House / Yard tabs.</summary>
        public static void BuildHomeStorePanel(Transform hud, GameDatabase db, VirtualJoystick joystick)
        {
            RectTransform sheet = Rect("HomeStoreSheet", hud);
            Stretch(sheet);
            RectTransform dimRect = Rect("Backdrop", sheet);
            Stretch(dimRect);
            Image dim = dimRect.gameObject.AddComponent<Image>();
            dim.color = new Color(20 / 255f, 12 / 255f, 8 / 255f, 0.5f);
            var backdrop = dimRect.gameObject.AddComponent<Button>();
            backdrop.transition = Selectable.Transition.None;

            const float corner = 26;
            RectTransform panel = Rect("Panel", sheet);
            panel.anchorMin = new Vector2(0.5f, 0);
            panel.anchorMax = new Vector2(0.5f, 0.78f);
            panel.pivot = new Vector2(0.5f, 0);
            panel.sizeDelta = new Vector2(360 * Px, corner * Px);
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

            RectTransform head = Rect("Head", panel);
            Row(head.gameObject, new RectOffset(20, 16, 18, 8), 12);
            RectTransform titles = Rect("Titles", head);
            var titleColumn = titles.gameObject.AddComponent<VerticalLayoutGroup>();
            titleColumn.childControlWidth = titleColumn.childControlHeight = true;
            titleColumn.childForceExpandWidth = titleColumn.childForceExpandHeight = false;
            titles.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            TMP_Text title = Text("Title", titles, "Տան խանութ", 22, UiPalette.Cream, "Black");
            title.alignment = TextAlignmentOptions.Left;
            title.gameObject.AddComponent<LocalizedTmpText>().SetKey("home.store.title");
            TMP_Text balance = Text("Balance", titles, "", 14, UiPalette.Honey, "ExtraBold");
            balance.alignment = TextAlignmentOptions.Left;

            RectTransform close = Rect("Close", head);
            Image closeBg = close.gameObject.AddComponent<Image>();
            closeBg.sprite = TextureFactory.Rounded();
            closeBg.type = Image.Type.Sliced;
            closeBg.pixelsPerUnitMultiplier = 16f / (14 * Px);
            closeBg.color = Walnut2;
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

            // tabs
            RectTransform tabs = Rect("Tabs", panel);
            Row(tabs.gameObject, new RectOffset(20, 20, 4, 10), 8);
            Button houseTab = Tab(tabs, "home.tab.house", "Տուն", out Image houseBg);
            Button yardTab = Tab(tabs, "home.tab.yard", "Բակ", out Image yardBg);

            RectTransform body = Rect("Body", panel);
            body.gameObject.AddComponent<LayoutElement>().flexibleHeight = 1;
            body.gameObject.AddComponent<RectMask2D>();
            Image hit = body.gameObject.AddComponent<Image>();
            hit.color = Color.clear;
            var scroll = body.gameObject.AddComponent<ScrollRect>();
            scroll.horizontal = false;
            scroll.movementType = ScrollRect.MovementType.Elastic;
            scroll.elasticity = 0.1f;
            scroll.inertia = true;
            scroll.decelerationRate = 0.135f;
            scroll.scrollSensitivity = 60;
            RectTransform content = Rect("Content", body);
            content.anchorMin = new Vector2(0, 1);
            content.anchorMax = new Vector2(1, 1);
            content.pivot = new Vector2(0.5f, 1);
            content.offsetMin = content.offsetMax = Vector2.zero;
            var list = content.gameObject.AddComponent<VerticalLayoutGroup>();
            list.padding = Scaled(new RectOffset(16, 16, 0, 20 + (int)corner));
            list.spacing = 6 * Px;
            list.childControlWidth = list.childControlHeight = true;
            list.childForceExpandWidth = true;
            list.childForceExpandHeight = false;
            content.gameObject.AddComponent<ContentSizeFitter>().verticalFit = ContentSizeFitter.FitMode.PreferredSize;
            scroll.content = content;
            scroll.viewport = body;

            HomeStoreRow row = StoreRow(content);

            GroupIcons(db.home, out string[] groups, out Sprite[] sprites);
            sheet.gameObject.SetActive(true);
            var script = hud.gameObject.AddComponent<HomeStorePanel>();
            script.Setup(sheet.gameObject, closeButton, backdrop, balance, houseTab, yardTab, houseBg, yardBg, content, row, joystick, groups, sprites);
        }

        static Button Tab(Transform parent, string key, string preview, out Image bg)
        {
            RectTransform tab = Card("Tab_" + key, parent, Walnut2, 12);
            bg = tab.GetComponent<Image>();
            bg.raycastTarget = true;
            Row(tab.gameObject, new RectOffset(16, 16, 8, 8), 0);
            tab.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
            tab.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            TMP_Text label = Text("Label", tab, preview, 15, UiPalette.Cream, "Black");
            label.gameObject.AddComponent<LocalizedTmpText>().SetKey(key);
            var button = tab.gameObject.AddComponent<Button>();
            button.targetGraphic = bg;
            button.transition = Selectable.Transition.None;
            return button;
        }

        static HomeStoreRow StoreRow(Transform parent)
        {
            RectTransform row = Card("RowTemplate", parent, Walnut2, 16);
            row.gameObject.AddComponent<CanvasGroup>();
            var h = row.gameObject.AddComponent<HorizontalLayoutGroup>();
            h.padding = Scaled(new RectOffset(12, 12, 10, 10));
            h.spacing = 12 * Px;
            h.childAlignment = TextAnchor.MiddleLeft;
            h.childControlWidth = h.childControlHeight = true;
            h.childForceExpandWidth = h.childForceExpandHeight = false;

            RectTransform icon = Rect("Icon", row);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.color = UiPalette.Honey;
            iconImage.raycastTarget = false;
            Size(icon.gameObject, 40, 40);

            RectTransform info = Rect("Info", row);
            var v = info.gameObject.AddComponent<VerticalLayoutGroup>();
            v.spacing = 2 * Px;
            v.childControlWidth = v.childControlHeight = true;
            v.childForceExpandWidth = true;
            v.childForceExpandHeight = false;
            info.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            TMP_Text name = Text("Name", info, "", 15, UiPalette.Cream, "ExtraBold");
            name.alignment = TextAlignmentOptions.Left;
            name.textWrappingMode = TextWrappingModes.Normal;
            TMP_Text line = Text("Line", info, "", 12, Muted, "Bold");
            line.alignment = TextAlignmentOptions.Left;

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
            Row(buy.gameObject, new RectOffset(10, 10, 0, 0), 0);
            buy.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
            var buySize = buy.gameObject.AddComponent<LayoutElement>();
            buySize.minWidth = 88 * Px;
            buySize.minHeight = buySize.preferredHeight = 42 * Px;
            TMP_Text price = Text("Price", buy, "$0", 15, Color.white, "Black");

            var script = row.gameObject.AddComponent<HomeStoreRow>();
            script.Setup(iconImage, name, line, button, buyBg, price, lip);
            return script;
        }
        /// <summary>Comfort chip under the level pill (TopLeft column): house icon, "Comfort N", "+x% income", storage box.</summary>
        public static void BuildComfortChip(Transform safe)
        {
            Transform column = safe.Find("TopLeft");
            if (column == null)
            {
                Debug.LogWarning("[FF] TopLeft HUD column missing; build it before the comfort chip.");
                return;
            }
            RectTransform chip = Pill("Comfort", column, UiPalette.Walnut, new RectOffset(8, 12, 4, 4), 6);
            RectTransform icon = Rect("Icon", chip);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.sprite = TextureFactory.LineIcon("un_house", 2f,
                TextureFactory.Closed(3, 11, 12, 4, 21, 11, 21, 20, 3, 20), TextureFactory.Poly(9, 20, 9, 14, 15, 14, 15, 20));
            iconImage.color = UiPalette.Honey;
            iconImage.raycastTarget = false;
            Size(icon.gameObject, 18, 18);
            TMP_Text comfort = Text("Comfort", chip, "Comfort 0", 12, UiPalette.Cream, "ExtraBold");
            TMP_Text bonus = Text("Bonus", chip, "+0%", 12, UiPalette.Leaf, "Black");

            RectTransform box = Pill("Box", chip, UiPalette.Honey, new RectOffset(6, 7, 1, 1), 3, false);
            RectTransform boxIcon = Rect("Icon", box);
            Image boxImage = boxIcon.gameObject.AddComponent<Image>();
            boxImage.sprite = TextureFactory.LineIcon("box", 2.2f, TextureFactory.Closed(4, 8, 20, 8, 20, 20, 4, 20),
                TextureFactory.Closed(3, 4, 21, 4, 21, 8, 3, 8), TextureFactory.Poly(10, 12, 14, 12));
            boxImage.color = UiPalette.Walnut;
            boxImage.raycastTarget = false;
            Size(boxIcon.gameObject, 14, 14);
            TMP_Text count = Text("Count", box, "0", 12, UiPalette.Walnut, "Black");

            chip.gameObject.SetActive(false);
            var script = column.gameObject.AddComponent<ComfortChip>();
            script.Setup(chip.gameObject, comfort, bonus, box.gameObject, count);
        }
    }
}
