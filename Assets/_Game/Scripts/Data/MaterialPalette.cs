using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// One shared flat-colour material per colour (the prototype's material cache), so renderers can be
    /// GPU-instanced / static-batched. Filled by the Editor tools; read at runtime by building growth etc.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Material Palette", fileName = "MaterialPalette")]
    public sealed class MaterialPalette : ScriptableObject
    {
        [Serializable]
        public struct Entry
        {
            public Color32 color;
            public bool unlit;
            public Material material;
            [Tooltip("Transparent twin (opacity 0.22, no depth write) used when a building fades out of the way.")]
            public Material ghost;
        }

        public List<Entry> entries = new List<Entry>();

        public Material Find(Color32 color, bool unlit = false)
        {
            for (int i = 0; i < entries.Count; i++)
            {
                Entry e = entries[i];
                if (e.unlit == unlit && e.color.r == color.r && e.color.g == color.g && e.color.b == color.b && e.color.a == color.a)
                    return e.material;
            }
            return null;
        }

        Dictionary<Material, Material> _ghostOf;

        /// <summary>Faded twin of a palette material (prototype <c>ghostOf</c>); null for materials without one.</summary>
        public Material GhostOf(Material material)
        {
            if (_ghostOf == null)
            {
                _ghostOf = new Dictionary<Material, Material>(entries.Count);
                foreach (Entry e in entries)
                    if (e.material != null && e.ghost != null) _ghostOf[e.material] = e.ghost;
            }
            return material != null && _ghostOf.TryGetValue(material, out Material g) ? g : null;
        }

        void OnValidate() => _ghostOf = null;
    }
}
