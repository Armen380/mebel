using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>A product shelf: drop zone with a 2×2 pile (capacity 8 + 3·shop level), shown when the product is owned.</summary>
    public sealed class Shelf : MonoBehaviour
    {
        const string ShopPadId = "shop";

        [SerializeField] ProductDef product;
        [SerializeField] Zone zone;
        [Tooltip("Shelf furniture in the blockout; hidden while the product is not owned.")]
        [SerializeField] GameObject visual;

        WorldStateSnapshot _state;

        public ProductDef Product => product;
        public Zone Zone => zone;
        public ItemStack Stack => zone.Stack;
        public bool IsActive => _state.Owns(product.id);

        /// <summary>Editor tools only.</summary>
        public void Setup(ProductDef productDef, Zone shelfZone, GameObject shelfVisual)
        {
            product = productDef;
            zone = shelfZone;
            visual = shelfVisual;
        }

        void Awake() => _state = Services.Get<WorldStateSnapshot>();

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            EconomyConfig economy = db.economy;
            var levels = Services.Get<IUpgradeLevels>();
            WorldLayout.MainShopSettings s = db.world.mainShop;
            zone.Configure(new PileLayout(s.shelfPile), () => economy.ShelfCapacity(levels.GetLevel(ShopPadId)),
                () => IsActive, db.items, economy.zoneRadius, s.shelfCounterHeight);
        }

        void LateUpdate()
        {
            bool show = IsActive;
            if (visual != null && visual.activeSelf != show) visual.SetActive(show);
        }
    }
}
