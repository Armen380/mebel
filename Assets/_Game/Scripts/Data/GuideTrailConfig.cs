using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// Floor arrows from the player to the current tutorial / unlock target (update 1.0.1, user request 2026-11-10:
    /// "arrows on the floor so the player finds every point faster").
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Guide Trail Config", fileName = "GuideTrail")]
    public sealed class GuideTrailConfig : ScriptableObject
    {
        [Tooltip("Arrows in the pool; the trail is cut when it needs more.")]
        public int count = 24;
        [Tooltip("Metres between two arrows.")]
        public float spacing = 1.5f;
        [Tooltip("Metres from the player to the first arrow.")]
        public float startGap = 1.2f;
        [Tooltip("Metres before the target where the trail ends.")]
        public float endGap = 1.1f;
        [Tooltip("Arrows grow over this many metres at both ends of the trail.")]
        public float fade = 0.8f;
        [Tooltip("Metres per second the arrows slide toward the target.")]
        public float speed = 1.4f;
        [Tooltip("Arrow width in metres.")]
        public float size = 1f;
        [Tooltip("Height above the ground (above the zone decals).")]
        public float height = 0.04f;
    }
}
