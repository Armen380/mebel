using System.Collections.Generic;
using FF.Data;

namespace FF.Gameplay.Delivery
{
    /// <summary>
    /// What is on each truck's bed, by truck index, so a save keeps it (user decision 2026-11-02; the prototype loses it).
    /// The save fills <see cref="Loads"/> before the world starts; <see cref="DeliveryDirector"/> docks the trucks with
    /// it and then keeps it current. A truck keeps its entry until it has delivered, so a quit on the way pays later.
    /// </summary>
    public sealed class DeliveryCargo
    {
        public readonly List<List<ItemType>> Loads = new List<List<ItemType>>();

        /// <summary>The list of truck <paramref name="truck"/>, created on demand.</summary>
        public List<ItemType> Of(int truck)
        {
            while (Loads.Count <= truck) Loads.Add(new List<ItemType>());
            return Loads[truck];
        }
    }
}
