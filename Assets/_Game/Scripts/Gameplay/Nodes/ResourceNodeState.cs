using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Nodes
{
    /// <summary>
    /// Prototype resource node {alive, regrow, fall, grow, shake, reserved} and <c>updNode</c> timing.
    /// Plain C#; <see cref="ResourceNode"/> turns the values into a pose of the node's top.
    /// </summary>
    public sealed class ResourceNodeState
    {
        const float FallRate = 2.6f;
        const float GrowRate = 1.8f;
        const float ShakeDecay = 4f;

        public ItemType Type { get; }
        public float Hardness { get; }
        public float RegrowSeconds { get; }
        /// <summary>Rocks shrink when mined; trees topple.</summary>
        public bool IsRock { get; }

        public bool Alive { get; private set; } = true;
        /// <summary>0 → 1 while falling after being felled; 1 = finished (top hidden).</summary>
        public float Fall { get; private set; } = 1f;
        /// <summary>0 → 1 while growing back; 1 = full size.</summary>
        public float Grow { get; private set; } = 1f;
        public float Shake { get; private set; }
        public float RegrowTimer { get; private set; }
        /// <summary>Agent that reserved this node (workers, M6); cleared when felled.</summary>
        public object ReservedBy { get; set; }

        public ResourceNodeState(ItemType type, float hardness, float regrowSeconds, bool isRock = false)
        {
            Type = type;
            Hardness = hardness;
            RegrowSeconds = regrowSeconds;
            IsRock = isRock;
        }

        public bool TopVisible => Alive || Fall < 1f;

        /// <summary>Elastic scale-in while growing back (prototype 1 + 2.7(k−1)³ + 1.7(k−1)²).</summary>
        public float GrowScale
        {
            get
            {
                float k = Grow - 1f;
                return Mathf.Max(0.01f, 1f + 2.7f * k * k * k + 1.7f * k * k);
            }
        }

        public void Hit() => Shake = 1f;

        public void Fell()
        {
            Alive = false;
            Fall = 0f;
            RegrowTimer = RegrowSeconds;
            ReservedBy = null;
        }

        public void Tick(float dt)
        {
            if (!Alive)
            {
                if (Fall < 1f) Fall = Mathf.Min(1f, Fall + dt * FallRate);
                RegrowTimer -= dt;
                if (RegrowTimer <= 0f)
                {
                    Alive = true;
                    Grow = 0f;
                }
            }
            if (Grow < 1f) Grow = Mathf.Min(1f, Grow + dt * GrowRate);
            if (Shake > 0f) Shake = Mathf.Max(0f, Shake - dt * ShakeDecay);
        }
    }
}
