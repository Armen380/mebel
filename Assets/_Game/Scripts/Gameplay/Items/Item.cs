using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>A pooled carryable item (log, plank, chair, bill, …). Holds no logic: stacks and flights move it.</summary>
    public sealed class Item : MonoBehaviour
    {
        [SerializeField] ItemType type;

        public ItemType Type => type;
        /// <summary>Money value of a bill (M3); 0 for goods.</summary>
        public long Value { get; set; }

        /// <summary>Editor tools only (prefab building).</summary>
        public void SetType(ItemType itemType) => type = itemType;
    }
}
