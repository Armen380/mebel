using System.Collections.Generic;
using FF.Data;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Dream House rules (M10 spec): areas open by house stage, factory slots take one carried product each, Home Store
    /// items are bought into storage (capped by the group's slot count) and placed on the slots of their group, comfort
    /// is the sum of what is placed and raises sale prices, a filled area pays its gift once.
    /// </summary>
    public static class HomeRules
    {
        public static bool IsAreaOpen(HomeDef d, string areaId, int stage)
        {
            HomeDef.AreaDef a = d.Area(areaId);
            return a != null && stage >= a.requiresStage;
        }

        public static bool IsSlotOpen(HomeDef d, HomeDef.SlotDef slot, int stage) => IsAreaOpen(d, slot.area, stage);

        public static bool CanPlaceFactory(HomeDef d, HomeState s, HomeDef.SlotDef slot, int stage, ItemType carried) =>
            slot.IsFactory && carried == slot.product && !s.Placed.ContainsKey(slot.id) && IsSlotOpen(d, slot, stage);

        public static void PlaceFactory(HomeState s, HomeDef.SlotDef slot) => s.Placed[slot.id] = ProductId(slot.product);

        /// <summary>Product id of a factory item type ("sofa" for Sofa), as ProductDef ids are.</summary>
        public static string ProductId(ItemType type) => type.ToString().ToLowerInvariant();

        /// <summary>Places the first item of the slot's group (catalog order) that is in storage.</summary>
        public static bool TryPlaceFromStorage(HomeDef d, HomeState s, HomeDef.SlotDef slot, int stage, out string itemId)
        {
            itemId = null;
            if (slot.IsFactory || s.Placed.ContainsKey(slot.id) || !IsSlotOpen(d, slot, stage)) return false;
            foreach (HomeDef.HomeItemDef item in d.items)
            {
                if (item.group != slot.group || Count(s, item.id) <= 0) continue;
                Take(s, item.id);
                s.Placed[slot.id] = item.id;
                itemId = item.id;
                return true;
            }
            return false;
        }

        /// <summary>Storage items of the slot's group other than the placed one; returns how many were added.</summary>
        public static int OtherVariants(HomeDef d, HomeState s, HomeDef.SlotDef slot, List<string> into)
        {
            into.Clear();
            if (slot.IsFactory) return 0;
            s.Placed.TryGetValue(slot.id, out string placed);
            foreach (HomeDef.HomeItemDef item in d.items)
                if (item.group == slot.group && item.id != placed && Count(s, item.id) > 0) into.Add(item.id);
            return into.Count;
        }

        /// <summary>Puts the placed item back into storage and places <paramref name="itemId"/> from storage instead.</summary>
        public static bool Swap(HomeState s, HomeDef.SlotDef slot, string itemId)
        {
            if (slot.IsFactory || !s.Placed.TryGetValue(slot.id, out string placed) || placed == itemId || Count(s, itemId) <= 0)
                return false;
            Take(s, itemId);
            Give(s, placed);
            s.Placed[slot.id] = itemId;
            return true;
        }

        /// <summary>Items of a group in storage plus placed.</summary>
        public static int Owned(HomeDef d, HomeState s, string group)
        {
            int n = 0;
            foreach (HomeDef.HomeItemDef item in d.items)
                if (item.group == group) n += Count(s, item.id);
            foreach (HomeDef.SlotDef slot in d.slots)
                if (!slot.IsFactory && slot.group == group && s.Placed.ContainsKey(slot.id)) n++;
            return n;
        }

        /// <summary>This item in storage plus on slots.</summary>
        public static int OwnedItem(HomeDef d, HomeState s, string itemId)
        {
            int n = Count(s, itemId);
            foreach (string placed in s.Placed.Values)
                if (placed == itemId) n++;
            return n;
        }

        public static int SlotsOf(HomeDef d, string group)
        {
            int n = 0;
            foreach (HomeDef.SlotDef slot in d.slots)
                if (!slot.IsFactory && slot.group == group) n++;
            return n;
        }

        /// <summary>Some slot of the item's group is in an open area.</summary>
        public static bool IsItemAvailable(HomeDef d, HomeDef.HomeItemDef item, int stage)
        {
            foreach (HomeDef.SlotDef slot in d.slots)
                if (!slot.IsFactory && slot.group == item.group && IsSlotOpen(d, slot, stage)) return true;
            return false;
        }

        /// <summary>
        /// Each item can be owned as many times as its group has slots (review fix: a cap on the whole group made the
        /// better variants unbuyable after one cheap pick, so the best house was unreachable).
        /// </summary>
        public static bool IsAtCap(HomeDef d, HomeState s, HomeDef.HomeItemDef item) => OwnedItem(d, s, item.id) >= SlotsOf(d, item.group);

        public static bool CanBuy(HomeDef d, HomeState s, HomeDef.HomeItemDef item, int stage, long money) =>
            money >= item.price && IsItemAvailable(d, item, stage) && !IsAtCap(d, s, item);

        public static void Buy(HomeState s, HomeDef.HomeItemDef item) => Give(s, item.id);

        public static int Comfort(HomeDef d, HomeState s)
        {
            int total = 0;
            foreach (HomeDef.SlotDef slot in d.slots)
            {
                if (!s.Placed.TryGetValue(slot.id, out string placed)) continue;
                if (slot.IsFactory) total += slot.comfort;
                else
                {
                    HomeDef.HomeItemDef item = d.Item(placed);
                    if (item != null) total += item.comfort;
                }
            }
            return total;
        }

        public static double SaleMultiplier(HomeDef d, int comfort) => 1 + d.comfortBonusPerPoint * comfort;

        public static bool IsAreaComplete(HomeDef d, HomeState s, string areaId)
        {
            bool any = false;
            foreach (HomeDef.SlotDef slot in d.slots)
            {
                if (slot.area != areaId) continue;
                any = true;
                if (!s.Placed.ContainsKey(slot.id)) return false;
            }
            return any;
        }

        public static bool TryClaimGift(HomeDef d, HomeState s, string areaId, out long gift)
        {
            gift = 0;
            HomeDef.AreaDef area = d.Area(areaId);
            if (area == null || s.RewardedAreas.Contains(areaId) || !IsAreaComplete(d, s, areaId)) return false;
            s.RewardedAreas.Add(areaId);
            gift = area.gift;
            return true;
        }

        static int Count(HomeState s, string itemId) => itemId != null && s.Storage.TryGetValue(itemId, out int n) ? n : 0;

        static void Give(HomeState s, string itemId) => s.Storage[itemId] = Count(s, itemId) + 1;

        static void Take(HomeState s, string itemId)
        {
            int n = Count(s, itemId) - 1;
            if (n > 0) s.Storage[itemId] = n;
            else s.Storage.Remove(itemId);
        }
    }
}
