using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>Root asset that references every data asset; the scene installer registers it as a service.</summary>
    [CreateAssetMenu(menuName = "FF/Game Database", fileName = "GameDatabase")]
    public sealed class GameDatabase : ScriptableObject
    {
        public EconomyConfig economy;
        public WorldLayout world;
        public TutorialDef tutorial;
        public ItemCatalog items;
        public BuildingKit buildingKit;
        [Tooltip("In prototype order (shelf index = list index for the main shop).")]
        public List<ProductDef> products = new List<ProductDef>();
        public List<UpgradeDef> upgrades = new List<UpgradeDef>();
        public List<PadDef> pads = new List<PadDef>();
        public List<SkinDef> skins = new List<SkinDef>();

        Dictionary<string, ProductDef> _productsById;
        Dictionary<string, UpgradeDef> _upgradesById;
        Dictionary<string, PadDef> _padsById;
        Dictionary<string, SkinDef> _skinsById;

        public ProductDef Product(string id) => Lookup(ref _productsById, products, id, p => p.id);
        public UpgradeDef Upgrade(string id) => Lookup(ref _upgradesById, upgrades, id, u => u.id);
        public PadDef Pad(string id) => Lookup(ref _padsById, pads, id, p => p.id);
        public SkinDef Skin(string id) => Lookup(ref _skinsById, skins, id, s => s.id);

        public SkinDef DefaultSkin => skins.Count > 0 ? skins[0] : null;

        void OnValidate() => ClearCaches();

        public void ClearCaches()
        {
            _productsById = null;
            _upgradesById = null;
            _padsById = null;
            _skinsById = null;
        }

        static T Lookup<T>(ref Dictionary<string, T> cache, List<T> list, string id, System.Func<T, string> key) where T : Object
        {
            if (cache == null)
            {
                cache = new Dictionary<string, T>(list.Count);
                foreach (T item in list)
                    if (item != null) cache[key(item)] = item;
            }
            return cache.TryGetValue(id, out T found) ? found : null;
        }
    }
}
