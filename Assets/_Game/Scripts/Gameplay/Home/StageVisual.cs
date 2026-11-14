using FF.Core;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Shows a Dream House part while the house stage is in [minStage, maxStage) (maxStage 0 = no upper bound) and pops it
    /// in when it appears during play (the factories' pop: scale 0 → 1 with a small overshoot).
    /// </summary>
    public sealed class StageVisual : MonoBehaviour
    {
        const float PopRate = 2.2f, Overshoot = 1.7f;

        [SerializeField] int minStage;
        [Tooltip("Hidden from this stage on (0 = never hidden).")]
        [SerializeField] int maxStage;
        [SerializeField] GameObject root;

        WorldStateSnapshot _state;
        bool _shown;
        float _pop = 1f;

        /// <summary>Editor tools only.</summary>
        public void Setup(int fromStage, int untilStage, GameObject visual)
        {
            minStage = fromStage;
            maxStage = untilStage;
            root = visual;
        }

        public static bool IsShown(int stage, int fromStage, int untilStage) =>
            stage >= fromStage && (untilStage <= 0 || stage < untilStage);

        void Awake()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _shown = IsShown(_state.HouseStage, minStage, maxStage);
            root.SetActive(_shown);
        }

        void LateUpdate()
        {
            bool shown = IsShown(_state.HouseStage, minStage, maxStage);
            if (shown != _shown)
            {
                _shown = shown;
                root.SetActive(shown);
                if (shown) _pop = 0f;
            }
            if (_pop >= 1f) return;
            _pop = Mathf.Min(1f, _pop + Time.deltaTime * PopRate);
            // easeOutBack
            float k = _pop - 1f;
            float s = 1f + (Overshoot + 1f) * k * k * k + Overshoot * k * k;
            root.transform.localScale = new Vector3(1f, Mathf.Max(0.01f, s), 1f);
        }
    }
}
