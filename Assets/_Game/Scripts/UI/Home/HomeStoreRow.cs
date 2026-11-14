using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.Home
{
    /// <summary>One Home Store catalog row: icon, name, comfort and status line, buy button with the price.</summary>
    public sealed class HomeStoreRow : MonoBehaviour
    {
        [SerializeField] Image icon;
        [SerializeField] TMP_Text title;
        [SerializeField] TMP_Text info;
        [SerializeField] Button button;
        [SerializeField] Image buttonBg;
        [SerializeField] TMP_Text price;
        [SerializeField] UnityEngine.UI.Shadow lip;

        public string ItemId { get; set; }
        public bool Yard { get; set; }
        public Button Button => button;

        /// <summary>Editor tools only.</summary>
        public void Setup(Image iconImage, TMP_Text name, TMP_Text infoText, Button buy, Image buyBg, TMP_Text priceText, UnityEngine.UI.Shadow buyLip)
        {
            icon = iconImage;
            title = name;
            info = infoText;
            button = buy;
            buttonBg = buyBg;
            price = priceText;
            lip = buyLip;
        }

        public void SetIcon(Sprite sprite) => icon.sprite = sprite;

        public void SetTexts(string name, string line, string priceText)
        {
            title.text = name;
            info.text = line;
            price.text = priceText;
        }

        public void SetState(bool interactable, Color face, Color lipColor, float alpha)
        {
            button.interactable = interactable;
            buttonBg.color = face;
            lip.effectColor = lipColor;
            var group = GetComponent<CanvasGroup>();
            if (group != null) group.alpha = alpha;
        }
    }
}
