using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Movement;
using UnityEngine;

namespace FF.Gameplay.World
{
    /// <summary>Service: the current blockers and region rules. Call <see cref="Rebuild"/> whenever the world state changes.</summary>
    public sealed class WorldCollision
    {
        readonly GameDatabase _db;
        readonly PlayerRegionRules _rules;
        readonly List<Aabb2D> _blockers = new List<Aabb2D>(32);
        bool _minesOpen;

        public WorldCollision(GameDatabase db, WorldStateSnapshot state)
        {
            _db = db;
            _rules = new PlayerRegionRules(db.world.playerBounds);
            Rebuild(state);
        }

        public IReadOnlyList<Aabb2D> Blockers => _blockers;
        public float PlayerRadius => _db.world.playerBounds.collisionRadius;

        public void Rebuild(WorldStateSnapshot state)
        {
            BlockerSet.Build(_db.world, _db.economy, _db.products, state, _blockers);
            _minesOpen = state.MinesOpen;
        }

        /// <summary>Region rules then blocker push-out for the player at a ground position (Unity x, z).</summary>
        public Vector2 ResolvePlayer(Vector2 pos)
        {
            _rules.Apply(ref pos, _minesOpen);
            CollisionResolver.PushOut(ref pos, PlayerRadius, _blockers);
            return pos;
        }
    }
}
