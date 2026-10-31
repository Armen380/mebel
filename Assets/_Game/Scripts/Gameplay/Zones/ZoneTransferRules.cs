using FF.Data;
using FF.Gameplay.Items;

namespace FF.Gameplay.Zones
{
    public enum ZoneKind
    {
        /// <summary>Carrier unloads matching items here.</summary>
        Drop,
        /// <summary>Carrier loads items from here.</summary>
        Pickup,
        /// <summary>Bills on a register counter (M3).</summary>
        Cash,
    }

    /// <summary>The conditions of the prototype's <c>updPlayer</c> zone loop, one item per transfer.</summary>
    public static class ZoneTransferRules
    {
        /// <summary>Drop: the carrier holds items, the zone accepts their type and has room.</summary>
        public static bool CanDrop(ItemStack carrier, ItemType zoneAccepts, ItemStack zone) =>
            carrier.Settled > 0 && carrier.Type == zoneAccepts && zone.HasRoom;

        /// <summary>Pickup: the zone holds items, the carrier is empty-typed or the same type and has room.</summary>
        public static bool CanPickup(ItemStack zone, ItemStack carrier) =>
            zone.Settled > 0 && (carrier.Type == ItemType.None || carrier.Type == zone.Type) && carrier.HasRoom;
    }
}
