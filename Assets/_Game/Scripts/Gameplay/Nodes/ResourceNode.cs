using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Nodes
{
    /// <summary>A tree (or, in M8, a rock): runs its <see cref="ResourceNodeState"/> and poses the choppable top.</summary>
    public sealed class ResourceNode : MonoBehaviour
    {
        const float ToppleAngle = 1.5f;
        const float ShakeFrequency = 30f;
        const float ShakeAngle = 0.06f;

        [SerializeField] ItemType type = ItemType.Log;
        [Tooltip("Trunk + crowns (tree) or the rock body; rotated / scaled when chopped.")]
        [SerializeField] Transform top;
        [Tooltip("Topple direction ±1 (prototype random per tree; fixed by the scene builder).")]
        [SerializeField] float fallDirection = 1f;

        public ResourceNodeState State { get; private set; }
        public Vector3 Position => transform.position;

        /// <summary>Editor tools only.</summary>
        public void Setup(ItemType nodeType, Transform topPart, float direction)
        {
            type = nodeType;
            top = topPart;
            fallDirection = direction;
        }

        void Awake()
        {
            EconomyConfig e = Services.Get<GameDatabase>().economy;
            switch (type)
            {
                case ItemType.Clay: State = new ResourceNodeState(type, e.clayHardness, e.clayRegrowSeconds, true); break;
                case ItemType.Iron: State = new ResourceNodeState(type, e.ironHardness, e.ironRegrowSeconds, true); break;
                default: State = new ResourceNodeState(type, e.treeHardness, e.treeRegrowSeconds); break;
            }
        }

        void Update()
        {
            bool wasAlive = State.Alive;
            State.Tick(Mathf.Min(Time.deltaTime, 0.05f));
            if (State.Alive && !wasAlive) top.localRotation = Quaternion.identity;

            bool visible = State.TopVisible;
            if (top.gameObject.activeSelf != visible) top.gameObject.SetActive(visible);
            if (!visible) return;

            if (!State.Alive)
            {
                float f = State.Fall;
                if (State.IsRock) top.localScale = Vector3.one * Mathf.Max(0.01f, 1f - f);
                else top.localRotation = Quaternion.Euler(0f, 0f, fallDirection * f * f * ToppleAngle * Mathf.Rad2Deg);
                return;
            }

            top.localScale = Vector3.one * State.GrowScale;
            float shake = State.Shake;
            // prototype rotation.x — X rotations flip sign in Unity space
            float x = shake > 0f ? -Mathf.Sin(shake * ShakeFrequency) * ShakeAngle * shake : 0f;
            top.localRotation = Quaternion.Euler(x * Mathf.Rad2Deg, 0f, 0f);
        }
    }
}
