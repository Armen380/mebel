using FF.Core;
using FF.Data;
using FF.Gameplay.Unlocks;
using UnityEngine;

namespace FF.Gameplay.Tutorial
{
    /// <summary>
    /// Floor arrows sliding from the player to the target of <see cref="TutorialArrow"/> (tutorial step, else the last
    /// unlock guide). A fixed pool of arrow objects built by the Editor tools; hidden in the menu and without a target.
    /// </summary>
    public sealed class GuideTrail : MonoBehaviour
    {
        [SerializeField] TutorialService tutorial;
        [SerializeField] UnlockService unlocks;
        [SerializeField] Transform player;
        [SerializeField] GuideTrailConfig config;
        [SerializeField] Transform[] marks;

        GuideMark[] _layout;
        bool[] _shown;
        float _phase;
        GameMode _mode;

        /// <summary>Editor tools only.</summary>
        public void Setup(TutorialService service, UnlockService unlockService, Transform playerTransform, GuideTrailConfig settings,
            Transform[] arrows)
        {
            tutorial = service;
            unlocks = unlockService;
            player = playerTransform;
            config = settings;
            marks = arrows;
        }

        void Awake()
        {
            _layout = new GuideMark[marks.Length];
            _shown = new bool[marks.Length];
            for (int i = 0; i < marks.Length; i++) marks[i].gameObject.SetActive(false);
        }

        void LateUpdate()
        {
            _mode ??= Services.Get<GameMode>();
            int n = 0;
            float yaw = 0f;
            if (!_mode.InMenu && (tutorial.TryGetTarget(out Vector3 target) || unlocks.TryGetGuide(out target)))
            {
                _phase = (_phase + Time.deltaTime * config.speed) % config.spacing;
                Vector3 p = player.position;
                n = GuideTrailLayout.Build(p.x, p.z, target.x, target.z, _phase, config.spacing, config.startGap, config.endGap,
                    config.fade, _layout, out yaw);
            }

            Quaternion rotation = Quaternion.Euler(0f, yaw, 0f);
            for (int i = 0; i < marks.Length; i++)
            {
                bool show = i < n;
                if (show != _shown[i])
                {
                    _shown[i] = show;
                    marks[i].gameObject.SetActive(show);
                }
                if (!show) continue;
                GuideMark m = _layout[i];
                marks[i].SetPositionAndRotation(new Vector3(m.X, config.height, m.Z), rotation);
                float s = m.Scale * config.size;
                marks[i].localScale = new Vector3(s, 1f, s);
            }
        }
    }
}
