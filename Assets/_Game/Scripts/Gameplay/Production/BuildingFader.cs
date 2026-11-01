using System.Collections.Generic;
using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Gameplay.Production
{
    /// <summary>
    /// Prototype <c>fadeBuildings / setGhost</c>: while the player is behind this building, its renderers swap to the
    /// palette's transparent twins (opacity 0.22, no shadows) so the player stays visible.
    /// </summary>
    public sealed class BuildingFader : MonoBehaviour
    {
        const float TextAlpha = 0.22f;

        [SerializeField] Transform player;

        readonly List<Renderer> _renderers = new List<Renderer>();
        readonly List<Material> _originals = new List<Material>();
        readonly List<ShadowCastingMode> _shadows = new List<ShadowCastingMode>();
        readonly List<TMP_Text> _texts = new List<TMP_Text>();
        MaterialPalette _palette;

        public bool IsFaded { get; private set; }

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform playerTransform) => player = playerTransform;

        void Awake()
        {
            _palette = Services.Get<GameDatabase>().buildingKit.palette;
            Collect();
        }

        /// <summary>Call after the building's parts changed (growth rebuilt the deco).</summary>
        public void Refresh()
        {
            bool faded = IsFaded;
            if (faded) Apply(false);
            Collect();
            if (faded) Apply(true);
        }

        void LateUpdate()
        {
            bool behind = OcclusionRule.IsBehind(transform.position, player.position);
            if (behind != IsFaded) Apply(behind);
        }

        void OnDisable()
        {
            if (IsFaded) Apply(false);
        }

        void Collect()
        {
            _renderers.Clear();
            _originals.Clear();
            _shadows.Clear();
            foreach (Renderer r in GetComponentsInChildren<Renderer>(true))
            {
                if (r is ParticleSystemRenderer || r.GetComponent<TMP_Text>() != null) continue;
                _renderers.Add(r);
                _originals.Add(r.sharedMaterial);
                _shadows.Add(r.shadowCastingMode);
            }
            _texts.Clear();
            GetComponentsInChildren(true, _texts);
        }

        void Apply(bool faded)
        {
            IsFaded = faded;
            for (int i = 0; i < _renderers.Count; i++)
            {
                Renderer r = _renderers[i];
                if (r == null) continue;
                Material ghost = faded ? _palette.GhostOf(_originals[i]) : null;
                if (faded && ghost == null) continue;
                r.sharedMaterial = faded ? ghost : _originals[i];
                r.shadowCastingMode = faded ? ShadowCastingMode.Off : _shadows[i];
            }
            foreach (TMP_Text t in _texts)
                if (t != null) t.alpha = faded ? TextAlpha : 1f;
        }
    }

    public static class OcclusionRule
    {
        const float HalfWidth = 4.2f, NearBehind = 2.3f, FarBehind = 15f;

        /// <summary>
        /// Prototype <c>fadeBuildings</c> in Unity space: the player stands within 4.2 m sideways and 2.3…15 m behind the
        /// building (further from the camera, +Z), where the building would hide them.
        /// </summary>
        public static bool IsBehind(Vector3 building, Vector3 player) =>
            Mathf.Abs(player.x - building.x) < HalfWidth && player.z > building.z + NearBehind && player.z < building.z + FarBehind;
    }
}
