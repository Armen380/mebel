using System;
using FF.Core;
using UnityEngine;

namespace FF.Gameplay.World
{
    /// <summary>
    /// Parts of the world that open with Plumbing (prototype <c>BACK.g / SHOP.annex visible = owned.sink</c>,
    /// <c>BACK.gate visible = !owned.sink</c>): the mines yard and the materials shop show, the gate in the factory fence
    /// goes. Sits on an always-active root; switches on load and when Plumbing is bought.
    /// </summary>
    public sealed class PlumbingSwitch : MonoBehaviour
    {
        [SerializeField] GameObject[] showWithPlumbing = Array.Empty<GameObject>();
        [SerializeField] GameObject[] hideWithPlumbing = Array.Empty<GameObject>();

        WorldStateSnapshot _state;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject[] show, GameObject[] hide)
        {
            showWithPlumbing = show;
            hideWithPlumbing = hide;
        }

        void Awake()
        {
            _state = Services.Get<WorldStateSnapshot>();
            Apply();
        }

        void OnEnable() => GameEvents.Unlocked += OnUnlocked;

        void OnDisable() => GameEvents.Unlocked -= OnUnlocked;

        void OnUnlocked(string id)
        {
            if (id == WorldStateSnapshot.PlumbingId) Apply();
        }

        void Apply()
        {
            bool open = _state.OwnsPlumbing;
            foreach (GameObject go in showWithPlumbing)
                if (go != null) go.SetActive(open);
            foreach (GameObject go in hideWithPlumbing)
                if (go != null) go.SetActive(!open);
        }
    }
}
