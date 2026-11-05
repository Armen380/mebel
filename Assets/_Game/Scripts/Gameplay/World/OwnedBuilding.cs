using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Production;
using UnityEngine;

namespace FF.Gameplay.World
{
    /// <summary>
    /// Shows a building once its owner id (saw2, a product id) is owned and its empty lot before that; a building that
    /// appears during play pops in (prototype <c>b.g.visible = true; b.pop = 0; lot.visible = false</c>).
    /// </summary>
    public sealed class OwnedBuilding : MonoBehaviour
    {
        [SerializeField] string ownerId;
        [SerializeField] GameObject building;
        [SerializeField] GameObject lot;

        WorldStateSnapshot _state;
        bool _owned;

        public string OwnerId => ownerId;

        /// <summary>Editor tools only.</summary>
        public void Setup(string owner, GameObject buildingObject, GameObject lotObject)
        {
            ownerId = owner;
            building = buildingObject;
            lot = lotObject;
        }

        void Awake()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _owned = _state.Owns(ownerId);
            Show(_owned);
        }

        void LateUpdate()
        {
            bool owned = _state.Owns(ownerId);
            if (owned == _owned) return;
            _owned = owned;
            Show(owned);
            if (owned && building.TryGetComponent(out BuildingVisual visual)) visual.PlayPop();
        }

        void Show(bool owned)
        {
            building.SetActive(owned);
            if (lot != null) lot.SetActive(!owned);
        }
    }

    /// <summary>
    /// Buying a building: updates the world state, rebuilds the blockers and announces the unlock. A product that opens
    /// with another one (prototype <c>with</c>: Building materials with Plumbing) is owned together with it.
    /// </summary>
    public sealed class Ownership
    {
        readonly WorldStateSnapshot _state;
        readonly WorldCollision _collision;
        readonly IReadOnlyList<ProductDef> _products;

        public Ownership(WorldStateSnapshot state, WorldCollision collision, IReadOnlyList<ProductDef> products = null)
        {
            _state = state;
            _collision = collision;
            _products = products;
        }

        public void Own(string id)
        {
            if (_state.Owns(id)) return;
            if (id == WorldStateSnapshot.Sawmill2Id) _state.OwnsSawmill2 = true;
            else _state.OwnedProducts.Add(id);
            if (_products != null)
                foreach (ProductDef p in _products)
                    if (p.unlocksWith != null && p.unlocksWith.id == id) _state.OwnedProducts.Add(p.id);
            _collision.Rebuild(_state);
            GameEvents.RaiseUnlocked(id);
            if (_products == null) return;
            foreach (ProductDef p in _products)
                if (p.unlocksWith != null && p.unlocksWith.id == id) GameEvents.RaiseUnlocked(p.id);
        }
    }
}
