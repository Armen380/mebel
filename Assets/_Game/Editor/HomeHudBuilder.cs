using System.Collections.Generic;
using FF.Data;
using FF.Editor.Art;
using FF.UI.Home;
using FF.UI.HUD;
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
    }
}
