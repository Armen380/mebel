using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Nodes
{
    /// <summary>All resource nodes; prototype <c>nearestNode(p, type, forAgent)</c>. Filled by the scene builder.</summary>
    public sealed class NodeRegistry : MonoBehaviour
    {
        [SerializeField] List<ResourceNode> nodes = new List<ResourceNode>();

        public IReadOnlyList<ResourceNode> Nodes => nodes;

        /// <summary>Editor tools only.</summary>
        public void SetNodes(List<ResourceNode> list) => nodes = list;

        /// <summary>Nearest alive node on the ground plane; optional type filter and reservation check.</summary>
        public ResourceNode Nearest(Vector3 p, ItemType type = ItemType.None, object forAgent = null)
        {
            ResourceNode best = null;
            float bestSq = float.MaxValue;
            for (int i = 0; i < nodes.Count; i++)
            {
                ResourceNode n = nodes[i];
                if (!n.isActiveAndEnabled) continue;
                ResourceNodeState s = n.State;
                if (!s.Alive) continue;
                if (type != ItemType.None && s.Type != type) continue;
                if (forAgent != null && s.ReservedBy != null && s.ReservedBy != forAgent) continue;
                Vector3 q = n.Position;
                float dx = q.x - p.x, dz = q.z - p.z, d = dx * dx + dz * dz;
                if (d < bestSq)
                {
                    bestSq = d;
                    best = n;
                }
            }
            return best;
        }
    }
}
