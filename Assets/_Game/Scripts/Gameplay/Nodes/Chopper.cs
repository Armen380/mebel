using FF.Data;
using FF.Gameplay.Items;

namespace FF.Gameplay.Nodes
{
    /// <summary>
    /// Prototype <c>tryChop</c> for one agent. Progress is kept between nodes on purpose: the prototype only
    /// resets it when a node falls, so walking away from a half-chopped tree keeps the progress.
    /// </summary>
    public sealed class Chopper
    {
        public float Progress { get; private set; }
        float _hitTimer;

        public struct Result
        {
            /// <summary>The agent is chopping this frame (axe pose).</summary>
            public bool Chopping;
            /// <summary>Shake + chop SFX this frame.</summary>
            public bool Hit;
            /// <summary>Items the felled node gives this frame (0 while chopping).</summary>
            public int Yield;
        }

        /// <param name="rate">Player 1, lumber workers 0.75.</param>
        /// <param name="chopSeconds">EconomyConfig.ChopSeconds(axe level), before node hardness.</param>
        public Result TryChop(ResourceNodeState node, ItemStack carrier, float dt, float rate, float chopSeconds,
            float hitInterval, int itemsPerChop)
        {
            var r = new Result();
            if (node == null || !node.Alive || !carrier.HasRoom) return r;
            if (carrier.Type != ItemType.None && carrier.Type != node.Type) return r;

            r.Chopping = true;
            Progress += dt * rate;
            _hitTimer += dt;
            if (_hitTimer > hitInterval)
            {
                _hitTimer = 0f;
                node.Hit();
                r.Hit = true;
            }

            if (Progress >= chopSeconds * node.Hardness)
            {
                Progress = 0f;
                node.Fell();
                int room = carrier.Capacity - carrier.Count;
                r.Yield = itemsPerChop < room ? itemsPerChop : room;
            }
            return r;
        }
    }
}
