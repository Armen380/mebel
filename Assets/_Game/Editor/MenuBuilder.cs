using System.Collections.Generic;
using FF.Editor.Art;
using FF.UI.HUD;
using FF.UI.Layout;
using FF.UI.Localization;
using FF.UI.Menu;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;
using static FF.Editor.GameSceneBuilder;
using static FF.Editor.HudBuilder;

namespace FF.Editor
{
    /// <summary>
    /// Prototype <c>#menu</c> (screenshot 01): its own canvas over the HUD with a fading backdrop and a walnut bottom card —
    /// kicker + language switch, two-tone title, intro, skin cards, Play, Test / New game, controls hint; plus the HUD's
    /// pause button (prototype <c>#btnMenu</c>) and the HUD canvas group the menu hides.
    /// </summary>
    public static class MenuBuilder
    {
        const string CanvasName = "Menu";
        static readonly Color32 Walnut2 = new Color32(0x3a, 0x28, 0x1b, 0xff);
        static readonly Color32 Muted = new Color32(0xcb, 0xb6, 0x97, 0xff);

        public static void Build(Transform ui, Transform hud, Transform safe)
        {
            if (!hud.TryGetComponent(out CanvasGroup hudGroup)) hudGroup = hud.gameObject.AddComponent<CanvasGroup>();
            Button menuButton = BuildMenuButton(safe);

            Transform old = ui.Find(CanvasName);
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var canvasGo = new GameObject(CanvasName, typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
            canvasGo.transform.SetParent(ui, false);
            var canvas = canvasGo.GetComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = 10;
            var hudScaler = hud.GetComponent<CanvasScaler>();
            var scaler = canvasGo.GetComponent<CanvasScaler>();
            scaler.uiScaleMode = hudScaler.uiScaleMode;
            scaler.referenceResolution = hudScaler.referenceResolution;
            scaler.matchWidthOrHeight = hudScaler.matchWidthOrHeight;

            // .menu: linear-gradient(to bottom, transparent 35 %, walnut 50 %)
            RectTransform root = Rect("Root", canvasGo.transform);
            Stretch(root);
            Image fade = root.gameObject.AddComponent<Image>();
            fade.sprite = TextureFactory.VerticalFade();
            fade.color = new Color(43 / 255f, 29 / 255f, 20 / 255f, 1f);
            fade.raycastTarget = true; // the world under the menu takes no touches

            RectTransform area = Rect("SafeArea", root);
            Stretch(area);
            area.gameObject.AddComponent<SafeAreaFitter>();

            const float corner = 26;
            RectTransform card = Rect("Card", area);
            card.anchorMin = new Vector2(0.5f, 0);
            card.anchorMax = new Vector2(0.5f, 0);
            card.pivot = new Vector2(0.5f, 0);
            card.anchoredPosition = new Vector2(0, -corner * Px);
            card.gameObject.AddComponent<ClampWidth>().Setup(560 * Px);
            Image bg = card.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (corner * Px);
            bg.color = UiPalette.Walnut;
            var column = card.gameObject.AddComponent<VerticalLayoutGroup>();
            column.padding = Scaled(new RectOffset(20, 20, 22, 20 + (int)corner));
            column.spacing = 16 * Px;
            column.childControlWidth = column.childControlHeight = true;
            column.childForceExpandWidth = true;
            column.childForceExpandHeight = false;
            var fit = card.gameObject.AddComponent<ContentSizeFitter>();
            fit.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

            // head: kicker + languages, title, intro
            RectTransform head = Rect("Head", card);
            VerticalColumn(head, 4);
            RectTransform top = Rect("Top", head);
            Row(top.gameObject, new RectOffset(0, 0, 0, 0), 10);
            TMP_Text kicker = Text("Kicker", top, "v1.0.0", 11, UiPalette.Honey, "ExtraBold");
            kicker.alignment = TextAlignmentOptions.Left;
            kicker.characterSpacing = 16;
            kicker.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            List<MainMenu.LanguageButton> languages = BuildLanguages(top);

            TMP_Text title = Text("Title", head, "Կահույքի Գործարան", 36, UiPalette.Cream, "Black");
            title.alignment = TextAlignmentOptions.Left;
            title.textWrappingMode = TextWrappingModes.Normal;
            title.lineSpacing = -10;
            title.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.h1", LocalizedTmpText.DefaultTable, true);
            TMP_Text intro = Text("Intro", head, "", 14, Muted, "Bold");
            intro.alignment = TextAlignmentOptions.Left;
            intro.textWrappingMode = TextWrappingModes.Normal;
            intro.lineSpacing = 10;
            intro.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.intro");

            // skins
            RectTransform skins = Rect("Skins", card);
            VerticalColumn(skins, 8);
            TMP_Text label = Text("Label", skins, "", 12, Muted, "ExtraBold");
            label.alignment = TextAlignmentOptions.Left;
            label.fontStyle = FontStyles.UpperCase;
            label.characterSpacing = 12;
            label.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.skin");
            RectTransform cards = BuildSkinStrip(skins, out MainMenu.SkinCardParts template);

            // settings: sound, music, vibration toggles and the graphics tier
            RectTransform settings = Rect("Settings", card);
            Row(settings.gameObject, new RectOffset(0, 0, 0, 0), 6);
            MainMenu.ToggleButton sound = IconToggle(settings, "Sound", TextureFactory.LineIcon("sound", 2.2f,
                TextureFactory.Closed(4, 9, 8, 9, 13, 5, 13, 19, 8, 15, 4, 15),
                TextureFactory.Cubic(new Vector2(16, 8.5f), new Vector2(17.5f, 9.5f), new Vector2(17.5f, 14.5f), new Vector2(16, 15.5f)),
                TextureFactory.Cubic(new Vector2(18.5f, 6), new Vector2(21.5f, 8.5f), new Vector2(21.5f, 15.5f), new Vector2(18.5f, 18))));
            MainMenu.ToggleButton music = IconToggle(settings, "Music", TextureFactory.LineIcon("music", 2.2f,
                TextureFactory.Poly(9, 17, 9, 5, 19, 3, 19, 15), TextureFactory.Circle(7, 17, 2.2f), TextureFactory.Circle(17, 15, 2.2f)));
            MainMenu.ToggleButton vibration = IconToggle(settings, "Vibration", TextureFactory.LineIcon("vibration", 2.2f,
                TextureFactory.RoundRect(8, 4, 8, 16, 2), TextureFactory.Poly(4, 9, 4, 15), TextureFactory.Poly(20, 9, 20, 15)));
            RectTransform spacer = Rect("Spacer", settings);
            spacer.gameObject.AddComponent<LayoutElement>().flexibleWidth = 1;
            List<MainMenu.QualityButton> quality = BuildQuality(settings);

            // actions
            RectTransform actions = Rect("Actions", card);
            VerticalColumn(actions, 10);
            Button play = Primary(actions, out TMP_Text playLabel);
            RectTransform row2 = Rect("Row2", actions);
            var h = row2.gameObject.AddComponent<HorizontalLayoutGroup>();
            h.spacing = 10 * Px;
            h.childControlWidth = h.childControlHeight = true;
            h.childForceExpandWidth = true;
            h.childForceExpandHeight = false;
            Button test = Ghost(row2, "Test", "ui.test", out TMP_Text testLabel, out _);
            Button newGame = Ghost(row2, "NewGame", null, out TMP_Text newGameLabel, out Image newGameBorder);

            TMP_Text controls = Text("Controls", card, "", 12, Muted, "Bold");
            controls.textWrappingMode = TextWrappingModes.Normal;
            controls.alpha = 0.8f;
            controls.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.controls");

            var menu = canvasGo.AddComponent<MainMenu>();
            menu.Setup(root.gameObject, hudGroup, menuButton, kicker, languages, cards, template, play, playLabel, test, testLabel,
                newGame, newGameBorder, newGameLabel);
            menu.SetupSettings(sound, music, vibration, quality);
        }

        /// <summary>Prototype <c>.icon-btn#btnMenu</c>: 44 px walnut square with the pause bars, top-right.</summary>
        static Button BuildMenuButton(Transform safe)
        {
            RectTransform r = Rect("MenuButton", safe);
            r.anchorMin = r.anchorMax = r.pivot = new Vector2(1, 1);
            r.anchoredPosition = new Vector2(-16 * Px, -12 * Px);
            r.sizeDelta = new Vector2(44 * Px, 44 * Px);
            Image bg = r.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Rounded();
            bg.type = Image.Type.Sliced;
            bg.pixelsPerUnitMultiplier = 16f / (14 * Px);
            bg.color = UiPalette.Walnut;
            var shadow = r.gameObject.AddComponent<Shadow>();
            shadow.effectColor = new Color(0, 0, 0, 0.28f);
            shadow.effectDistance = new Vector2(0, -4 * Px);
            var button = r.gameObject.AddComponent<Button>();
            button.targetGraphic = bg;
            RectTransform icon = Rect("Icon", r);
            icon.anchorMin = icon.anchorMax = new Vector2(0.5f, 0.5f);
            icon.sizeDelta = new Vector2(22 * Px, 22 * Px);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.sprite = TextureFactory.LineIcon("pause", 2.6f, TextureFactory.Poly(9, 6, 9, 18), TextureFactory.Poly(15, 6, 15, 18));
            iconImage.color = UiPalette.Cream;
            iconImage.raycastTarget = false;
            return button;
        }

        /// <summary>Prototype <c>.langs</c>: segmented control Հայ / EN / RU.</summary>
        static List<MainMenu.LanguageButton> BuildLanguages(Transform parent)
        {
            RectTransform group = Card("Languages", parent, Walnut2, 12);
            Row(group.gameObject, new RectOffset(3, 3, 3, 3), 2);
            var list = new List<MainMenu.LanguageButton>();
            foreach ((string code, string text) in new[] { ("hy", "Հայ"), ("en", "EN"), ("ru", "RU") })
            {
                RectTransform b = Card("Lang_" + code, group, Color.clear, 9);
                Image image = b.GetComponent<Image>();
                image.raycastTarget = true;
                var button = b.gameObject.AddComponent<Button>();
                button.targetGraphic = image;
                button.transition = Selectable.Transition.None;
                var size = b.gameObject.AddComponent<LayoutElement>();
                size.minWidth = 44 * Px;
                size.preferredHeight = size.minHeight = 34 * Px;
                Row(b.gameObject, new RectOffset(10, 10, 0, 0), 0);
                b.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
                TMP_Text label = Text("Label", b, text, 13, Muted, "ExtraBold");
                list.Add(new MainMenu.LanguageButton { code = code, button = button, background = image, label = label });
            }
            return list;
        }

        /// <summary>44 px rounded square with a line icon; honey when on, walnut when off.</summary>
        static MainMenu.ToggleButton IconToggle(Transform parent, string name, Sprite iconSprite)
        {
            RectTransform r = Card(name, parent, UiPalette.Honey, 12);
            Image bg = r.GetComponent<Image>();
            bg.raycastTarget = true;
            var button = r.gameObject.AddComponent<Button>();
            button.targetGraphic = bg;
            button.transition = Selectable.Transition.None;
            Size(r.gameObject, 40, 40);
            RectTransform icon = Rect("Icon", r);
            icon.anchorMin = icon.anchorMax = new Vector2(0.5f, 0.5f);
            icon.sizeDelta = new Vector2(22 * Px, 22 * Px);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.sprite = iconSprite;
            iconImage.color = UiPalette.Walnut;
            iconImage.raycastTarget = false;
            return new MainMenu.ToggleButton { button = button, background = bg, icon = iconImage };
        }

        /// <summary>Graphics tier as a segmented control like the languages.</summary>
        static List<MainMenu.QualityButton> BuildQuality(Transform parent)
        {
            RectTransform group = Card("Quality", parent, Walnut2, 12);
            Row(group.gameObject, new RectOffset(3, 3, 3, 3), 2);
            var list = new List<MainMenu.QualityButton>();
            foreach ((FF.Core.QualityTier tier, string key) in new[]
                     { (FF.Core.QualityTier.Low, "ui.gLow"), (FF.Core.QualityTier.Medium, "ui.gMed"), (FF.Core.QualityTier.High, "ui.gHigh") })
            {
                RectTransform b = Card("Quality_" + tier, group, Color.clear, 9);
                Image image = b.GetComponent<Image>();
                image.raycastTarget = true;
                var button = b.gameObject.AddComponent<Button>();
                button.targetGraphic = image;
                button.transition = Selectable.Transition.None;
                var size = b.gameObject.AddComponent<LayoutElement>();
                size.minWidth = 40 * Px;
                size.preferredHeight = size.minHeight = 34 * Px;
                Row(b.gameObject, new RectOffset(5, 5, 0, 0), 0);
                b.GetComponent<HorizontalLayoutGroup>().childAlignment = TextAnchor.MiddleCenter;
                TMP_Text label = Text("Label", b, "", 11, Muted, "ExtraBold");
                label.gameObject.AddComponent<LocalizedTmpText>().SetKey(key);
                list.Add(new MainMenu.QualityButton { tier = tier, button = button, background = image, label = label });
            }
            return list;
        }

        /// <summary>Prototype <c>.skins</c>: horizontal strip of 92 px cards; one hidden template the menu clones per skin.</summary>
        static RectTransform BuildSkinStrip(Transform parent, out MainMenu.SkinCardParts template)
        {
            RectTransform viewport = Rect("Strip", parent);
            viewport.gameObject.AddComponent<RectMask2D>();
            Image hit = viewport.gameObject.AddComponent<Image>();
            hit.color = Color.clear;
            var height = viewport.gameObject.AddComponent<LayoutElement>();
            height.preferredHeight = height.minHeight = 118 * Px;
            var scroll = viewport.gameObject.AddComponent<ScrollRect>();
            scroll.vertical = false;
            scroll.movementType = ScrollRect.MovementType.Clamped;
            scroll.inertia = true;
            RectTransform content = Rect("Content", viewport);
            content.anchorMin = new Vector2(0, 0);
            content.anchorMax = new Vector2(0, 1);
            content.pivot = new Vector2(0, 0.5f);
            content.offsetMin = content.offsetMax = Vector2.zero;
            var row = content.gameObject.AddComponent<HorizontalLayoutGroup>();
            row.padding = Scaled(new RectOffset(2, 2, 4, 8));
            row.spacing = 10 * Px;
            row.childControlWidth = row.childControlHeight = true;
            row.childForceExpandWidth = false;
            row.childForceExpandHeight = true;
            var fit = content.gameObject.AddComponent<ContentSizeFitter>();
            fit.horizontalFit = ContentSizeFitter.FitMode.PreferredSize;
            scroll.content = content;
            scroll.viewport = viewport;

            // card: transparent hit area, honey ring (selected), walnut fill inset 3 px, swatch, name, lock
            RectTransform cardRect = Rect("SkinTemplate", content);
            Image hitImage = cardRect.gameObject.AddComponent<Image>();
            hitImage.color = Color.clear;
            var button = cardRect.gameObject.AddComponent<Button>();
            button.transition = Selectable.Transition.None;
            CanvasGroup group = cardRect.gameObject.AddComponent<CanvasGroup>();
            var cardSize = cardRect.gameObject.AddComponent<LayoutElement>();
            cardSize.preferredWidth = cardSize.minWidth = 92 * Px;

            RectTransform ring = Card("Border", cardRect, UiPalette.Honey, 16);
            Stretch(ring);
            ring.gameObject.AddComponent<LayoutElement>().ignoreLayout = true;
            RectTransform fill = Card("Fill", cardRect, Walnut2, 13);
            Stretch(fill);
            fill.offsetMin = new Vector2(3 * Px, 3 * Px);
            fill.offsetMax = new Vector2(-3 * Px, -3 * Px);
            fill.gameObject.AddComponent<LayoutElement>().ignoreLayout = true;

            var column = cardRect.gameObject.AddComponent<VerticalLayoutGroup>();
            column.padding = Scaled(new RectOffset(6, 6, 12, 10));
            column.spacing = 7 * Px;
            column.childAlignment = TextAnchor.UpperCenter;
            column.childControlWidth = column.childControlHeight = true;
            column.childForceExpandWidth = column.childForceExpandHeight = false;

            // .sw: conic-gradient(hat 0 35 %, shirt 35 % 100 %) with a faint inner ring
            RectTransform swatch = Rect("Swatch", cardRect);
            Size(swatch.gameObject, 46, 46);
            Image shirt = swatch.gameObject.AddComponent<Image>();
            shirt.sprite = TextureFactory.Circle();
            shirt.raycastTarget = false;
            RectTransform hatRect = Rect("Hat", swatch);
            Stretch(hatRect);
            Image hat = hatRect.gameObject.AddComponent<Image>();
            hat.sprite = TextureFactory.Circle();
            hat.type = Image.Type.Filled;
            hat.fillMethod = Image.FillMethod.Radial360;
            hat.fillOrigin = (int)Image.Origin360.Top;
            hat.fillClockwise = true;
            hat.fillAmount = 0.35f;
            hat.raycastTarget = false;
            RectTransform gloss = Rect("Ring", swatch);
            Stretch(gloss);
            Image glossImage = gloss.gameObject.AddComponent<Image>();
            glossImage.sprite = TextureFactory.Ring();
            glossImage.color = new Color(1, 1, 1, 0.18f);
            glossImage.raycastTarget = false;

            TMP_Text name = Text("Name", cardRect, "", 12, UiPalette.Cream, "Bold");
            name.textWrappingMode = TextWrappingModes.Normal;
            TMP_Text lockText = Text("Lock", cardRect, "", 10, UiPalette.Honey, "ExtraBold");
            lockText.textWrappingMode = TextWrappingModes.Normal;

            template = new MainMenu.SkinCardParts
            {
                button = button, background = fill.GetComponent<Image>(), border = ring.GetComponent<Image>(),
                shirt = shirt, hat = hat, name = name, lockText = lockText, group = group,
            };
            return content;
        }

        /// <summary>Prototype <c>.primary</c>: 56 px honey button with a honey-dark lip.</summary>
        static Button Primary(Transform parent, out TMP_Text label)
        {
            RectTransform r = Card("Play", parent, UiPalette.Honey, 16);
            Image bg = r.GetComponent<Image>();
            bg.raycastTarget = true;
            var shadow = r.gameObject.AddComponent<Shadow>();
            shadow.effectColor = UiPalette.HoneyDark;
            shadow.effectDistance = new Vector2(0, -5 * Px);
            var button = r.gameObject.AddComponent<Button>();
            button.targetGraphic = bg;
            var size = r.gameObject.AddComponent<LayoutElement>();
            size.preferredHeight = size.minHeight = 56 * Px;
            label = Text("Label", r, "", 19, UiPalette.Walnut, "Black");
            Stretch((RectTransform)label.transform);
            return button;
        }

        /// <summary>Prototype <c>.ghost</c>: outlined button (2 px walnut-3 border), muted text.</summary>
        static Button Ghost(Transform parent, string name, string key, out TMP_Text label, out Image border)
        {
            RectTransform r = Card(name, parent, UiPalette.Walnut3, 14);
            border = r.GetComponent<Image>();
            border.raycastTarget = true;
            RectTransform inner = Card("Inner", r, UiPalette.Walnut, 12);
            Stretch(inner);
            inner.offsetMin = new Vector2(2 * Px, 2 * Px);
            inner.offsetMax = new Vector2(-2 * Px, -2 * Px);
            var button = r.gameObject.AddComponent<Button>();
            button.targetGraphic = border;
            var size = r.gameObject.AddComponent<LayoutElement>();
            size.preferredHeight = size.minHeight = 44 * Px;
            label = Text("Label", r, "", 13, Muted, "Bold");
            label.textWrappingMode = TextWrappingModes.Normal;
            var lr = (RectTransform)label.transform;
            Stretch(lr);
            lr.offsetMin = new Vector2(10 * Px, 6 * Px);
            lr.offsetMax = new Vector2(-10 * Px, -6 * Px);
            if (key != null) label.gameObject.AddComponent<LocalizedTmpText>().SetKey(key);
            return button;
        }

        static void VerticalColumn(RectTransform r, float spacing)
        {
            var v = r.gameObject.AddComponent<VerticalLayoutGroup>();
            v.spacing = spacing * Px;
            v.childControlWidth = v.childControlHeight = true;
            v.childForceExpandWidth = true;
            v.childForceExpandHeight = false;
        }
    }
}
