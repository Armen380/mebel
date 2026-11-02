using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Zones
{
    /// <summary>What workers need to know about a pile (zone): fill, room, type and where it is.</summary>
    public interface IPile
    {
        /// <summary>Items in place plus items flying in.</summary>
        int Count { get; }
        /// <summary>Items in place (can be taken).</summary>
        int Settled { get; }
        int Capacity { get; }
        bool IsActive { get; }
        ItemType ItemType { get; }
        Vector3 Position { get; }
    }
}
