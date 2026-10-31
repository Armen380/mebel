using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>Where item <c>index</c> of a stack sits, relative to the stack anchor (Unity local space).</summary>
    public interface IStackLayout
    {
        Vector3 SlotPosition(int index, float itemHeight);
        Quaternion SlotRotation { get; }
    }

    /// <summary>
    /// Prototype <c>carryLayout</c>: a column above the hands, (0, i·H, 0). Items turn 180° so their front
    /// faces where the character looks (world-built item prefabs face the camera, Unity −Z).
    /// </summary>
    public sealed class CarryLayout : IStackLayout
    {
        public static readonly CarryLayout Instance = new CarryLayout();

        static readonly Quaternion Facing = Quaternion.Euler(0f, 180f, 0f);

        public Vector3 SlotPosition(int index, float itemHeight) => new Vector3(0f, index * itemHeight, 0f);

        public Quaternion SlotRotation => Facing;
    }

    /// <summary>
    /// Prototype <c>pileLayout(cols, rows, sx, sz)</c>: grid layers; item i → layer ⌊i/(cols·rows)⌋.
    /// Prototype z offsets are mirrored to Unity (−z).
    /// </summary>
    public sealed class PileLayout : IStackLayout
    {
        readonly int _cols;
        readonly int _rows;
        readonly float _sx;
        readonly float _sz;

        public PileLayout(int cols, int rows, float spacingX, float spacingZ)
        {
            _cols = Mathf.Max(1, cols);
            _rows = Mathf.Max(1, rows);
            _sx = spacingX;
            _sz = spacingZ;
        }

        public PileLayout(WorldLayout.PileSettings s) : this(s.cols, s.rows, s.spacing.x, s.spacing.y) { }

        public Vector3 SlotPosition(int index, float itemHeight)
        {
            int perLayer = _cols * _rows;
            int layer = index / perLayer;
            int k = index % perLayer;
            float x = (k % _cols - (_cols - 1) / 2f) * _sx;
            float protoZ = (k / _cols - (_rows - 1) / 2f) * _sz;
            return new Vector3(x, layer * itemHeight, -protoZ);
        }

        public Quaternion SlotRotation => Quaternion.identity;
    }
}
