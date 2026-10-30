using UnityEngine;

namespace FF.Data
{
    [CreateAssetMenu(menuName = "FF/Product", fileName = "Product")]
    public sealed class ProductDef : ScriptableObject
    {
        public string id;
        public ItemType item;
        public string nameKey;
        public string signKey;

        [Header("Production")]
        public ItemType input;
        public int inputPerCycle;
        public float cycleSeconds;

        [Header("Economy")]
        public int basePrice;
        public int xpPerSale;
        public int unlockLevel;
        public long factoryCost;
        [Tooltip("Opens for free together with this product's factory (material opens with sink).")]
        public ProductDef unlocksWith;

        [Header("World (prototype coordinates)")]
        public float factoryX;
        [Tooltip("Shelf x in its shop. Prototype: 4.6 + index*2.8 in the main shop; sink 48, material 50.6.")]
        public float shelfX;
        public ShopKind sellsIn;
        public Color wallColor;
        public Color roofColor;

        public bool OwnedAtStart => factoryCost == 0 && unlocksWith == null;
    }
}
