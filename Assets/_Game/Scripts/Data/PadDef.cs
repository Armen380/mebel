using UnityEngine;

namespace FF.Data
{
    /// <summary>Yellow ground pad that the player pays into.</summary>
    [CreateAssetMenu(menuName = "FF/Pad", fileName = "Pad")]
    public sealed class PadDef : ScriptableObject
    {
        public string id;
        [Tooltip("Prototype coordinates (x, z). Convert with ProtoCoords.")]
        public Vector2 protoPos;
        public string glyph;
        public long baseCost;
        public double costMultiplier = 1;
        public int maxLevel;
        [TextArea] public string effect;
        public string visibleWhen;
        [Tooltip("Localization key of the floating text when a level is bought (prototype addPad done).")]
        public string doneKey = "done.generic";
    }
}
