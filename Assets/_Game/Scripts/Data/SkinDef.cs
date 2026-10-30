using UnityEngine;

namespace FF.Data
{
    [CreateAssetMenu(menuName = "FF/Skin", fileName = "Skin")]
    public sealed class SkinDef : ScriptableObject
    {
        public string id;
        public string nameKey;
        public Color shirt;
        public Color pants;
        public Color hat;
        public HatType hatType;
        public Color skin = new Color32(0xf1, 0xc2, 0x7d, 0xff);
        public long unlockTotalEarned;
    }
}
