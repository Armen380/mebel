using UnityEngine;

namespace FF.Gameplay.Characters
{
    /// <summary>References to the animated parts of a blocky character (built by the Editor CharacterRigBuilder).</summary>
    public sealed class CharacterRig : MonoBehaviour
    {
        public Transform body;
        public Transform hipLeft;
        public Transform hipRight;
        public Transform shoulderLeft;
        public Transform shoulderRight;
        public GameObject axe;
        [Tooltip("Carried items stack on this anchor (prototype (0, 0.92, 0.56)).")]
        public Transform carryAnchor;
        public bool isRobot;
    }
}
