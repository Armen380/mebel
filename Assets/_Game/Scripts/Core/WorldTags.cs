using System.Collections.Generic;
using UnityEngine;

namespace FF.Core
{
    public enum WorldTagStyle
    {
        /// <summary>Dark pill "n/cap" over a pile.</summary>
        Counter,
        /// <summary>Red "FULL" pill over a character.</summary>
        Full,
        /// <summary>Green money pill "$1.2K" over a register's bills (TagValue).</summary>
        Cash,
        /// <summary>White speech bubble with an icon (TagIcon) over a customer.</summary>
        Bubble,
        /// <summary>Honey pill "Lv 3 · ×2" over a building: TagCount = combined level, TagCapacity = output multiplier.</summary>
        Level,
    }

    /// <summary>Anything that shows a screen-space tag above a world position. Read once per frame by the UI.</summary>
    public interface IWorldTagSource
    {
        bool TagVisible { get; }
        Vector3 TagPosition { get; }
        WorldTagStyle TagStyle { get; }
        int TagCount { get; }
        int TagCapacity { get; }
        /// <summary>Money shown by <see cref="WorldTagStyle.Cash"/>.</summary>
        long TagValue { get; }
        /// <summary>Icon id shown by <see cref="WorldTagStyle.Bubble"/>: a product id, "cash" or "angry".</summary>
        string TagIcon { get; }
    }

    /// <summary>List of tag sources; gameplay objects register themselves, the UI layer draws them.</summary>
    public sealed class WorldTagRegistry
    {
        readonly List<IWorldTagSource> _sources = new List<IWorldTagSource>();

        public IReadOnlyList<IWorldTagSource> Sources => _sources;

        public void Register(IWorldTagSource source)
        {
            if (!_sources.Contains(source)) _sources.Add(source);
        }

        public void Unregister(IWorldTagSource source) => _sources.Remove(source);
    }
}
