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
    }
}
