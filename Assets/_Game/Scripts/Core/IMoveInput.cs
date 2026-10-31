using UnityEngine;

namespace FF.Core
{
    /// <summary>A source of movement input on the ground plane: x = right, y = forward (screen up). Length ≤ 1.</summary>
    public interface IMoveInput
    {
        Vector2 Value { get; }
    }
}
