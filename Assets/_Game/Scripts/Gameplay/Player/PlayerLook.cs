using System;
using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Player
{
    /// <summary>
    /// The player's look per skin (prototype <c>setSkin</c> rebuilds the character; here the rig stays and only the shirt,
    /// trousers and hat change): shirt / trouser parts get the skin's palette materials, the matching hat shows.
    /// Materials are resolved by the editor builder, so switching costs nothing at runtime.
    /// </summary>
    public sealed class PlayerLook : MonoBehaviour
    {
        [Serializable]
        public struct Look
        {
            public string id;
            public HatType hat;
            public Material shirt;
            public Material pants;
            public Material hatMaterial;
        }

        [SerializeField] Renderer[] shirt = Array.Empty<Renderer>();
        [SerializeField] Renderer[] pants = Array.Empty<Renderer>();
        [Tooltip("Index = (int)HatType; None has no object.")]
        [SerializeField] GameObject[] hats = Array.Empty<GameObject>();
        [SerializeField] List<Look> looks = new List<Look>();

        Renderer[][] _hatRenderers;

        /// <summary>Editor tools only.</summary>
        public void Setup(Renderer[] shirtParts, Renderer[] pantsParts, GameObject[] hatObjects, List<Look> lookList)
        {
            shirt = shirtParts;
            pants = pantsParts;
            hats = hatObjects;
            looks = lookList;
        }

        public bool Has(string id) => IndexOf(id) >= 0;

        /// <returns>False when the id is unknown (the look stays as it was).</returns>
        public bool Apply(string id)
        {
            int i = IndexOf(id);
            if (i < 0) return false;
            Look look = looks[i];
            _hatRenderers ??= HatRenderers();
            foreach (Renderer r in shirt) r.sharedMaterial = look.shirt;
            foreach (Renderer r in pants) r.sharedMaterial = look.pants;
            for (int h = 0; h < hats.Length; h++)
            {
                if (hats[h] == null) continue;
                bool on = h == (int)look.hat;
                hats[h].SetActive(on);
                if (!on) continue;
                foreach (Renderer r in _hatRenderers[h]) r.sharedMaterial = look.hatMaterial;
            }
            return true;
        }

        int IndexOf(string id)
        {
            for (int i = 0; i < looks.Count; i++)
                if (looks[i].id == id) return i;
            return -1;
        }

        Renderer[][] HatRenderers()
        {
            var result = new Renderer[hats.Length][];
            for (int h = 0; h < hats.Length; h++)
                result[h] = hats[h] != null ? hats[h].GetComponentsInChildren<Renderer>(true) : Array.Empty<Renderer>();
            return result;
        }
    }
}
