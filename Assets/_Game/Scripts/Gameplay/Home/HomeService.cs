using FF.Core;
using FF.Data;
using FF.Gameplay.Progress;
using FF.Gameplay.World;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// The Dream House service (M10): owns the <see cref="HomeState"/>, buys Home Store items, places items on slots and
    /// pays area gifts (announced through <see cref="GameEvents.HomeAreaCompleted"/>), and gives the comfort bonus on sale
    /// prices. The house stage comes from the world state (house_* pad levels).
    /// </summary>
    public sealed class HomeService : IHomeStore, IHomeBonus
    {
        readonly HomeDef _def;
        readonly GameProgress _progress;
        readonly WorldStateSnapshot _state;

        public HomeService(HomeDef def, GameProgress progress, WorldStateSnapshot state)
        {
            _def = def;
            _progress = progress;
            _state = state;
        }

        public HomeDef Def => _def;
        public HomeState State { get; } = new HomeState();

        public int Stage => _state.HouseStage;
        public int Comfort => HomeRules.Comfort(_def, State);
        public int StorageCount => State.StorageCount;
        public double SaleMultiplier => HomeRules.SaleMultiplier(_def, Comfort);

        public bool IsAvailable(string itemId)
        {
            HomeDef.HomeItemDef item = _def.Item(itemId);
            return item != null && HomeRules.IsItemAvailable(_def, item, Stage);
        }

        public bool CanBuy(string itemId)
        {
            HomeDef.HomeItemDef item = _def.Item(itemId);
            return item != null && HomeRules.CanBuy(_def, State, item, Stage, _progress.Money);
        }

        public bool IsAtCap(string itemId)
        {
            HomeDef.HomeItemDef item = _def.Item(itemId);
            return item != null && HomeRules.IsAtCap(_def, State, item);
        }

        public int InStorage(string itemId) => itemId != null && State.Storage.TryGetValue(itemId, out int n) ? n : 0;

        public bool IsPlaced(string itemId)
        {
            foreach (string placed in State.Placed.Values)
                if (placed == itemId) return true;
            return false;
        }

        public bool Buy(string itemId)
        {
            HomeDef.HomeItemDef item = _def.Item(itemId);
            if (item == null || !HomeRules.CanBuy(_def, State, item, Stage, _progress.Money) || !_progress.Spend(item.price)) return false;
            HomeRules.Buy(State, item);
            GameEvents.RaiseHomeChanged();
            return true;
        }

        public bool Swap(string slotId, string itemId)
        {
            HomeDef.SlotDef slot = _def.Slot(slotId);
            if (slot == null || !HomeRules.Swap(State, slot, itemId)) return false;
            GameEvents.RaiseHomeChanged();
            return true;
        }

        public bool CanPlaceFactory(string slotId, ItemType carried)
        {
            HomeDef.SlotDef slot = _def.Slot(slotId);
            return slot != null && HomeRules.CanPlaceFactory(_def, State, slot, Stage, carried);
        }

        public bool TryPlaceFactory(string slotId, ItemType carried)
        {
            HomeDef.SlotDef slot = _def.Slot(slotId);
            if (slot == null || !HomeRules.CanPlaceFactory(_def, State, slot, Stage, carried)) return false;
            HomeRules.PlaceFactory(State, slot);
            Placed(slot);
            return true;
        }

        public bool TryPlaceFromStorage(string slotId)
        {
            HomeDef.SlotDef slot = _def.Slot(slotId);
            if (slot == null || !HomeRules.TryPlaceFromStorage(_def, State, slot, Stage, out _)) return false;
            Placed(slot);
            return true;
        }

        void Placed(HomeDef.SlotDef slot)
        {
            if (HomeRules.TryClaimGift(_def, State, slot.area, out long gift))
            {
                if (gift > 0) _progress.AddMoney(gift);
                GameEvents.RaiseHomeAreaCompleted(slot.area, gift);
            }
            GameEvents.RaiseHomeChanged();
        }
    }
}
