using FF.Gameplay.Unlocks;
using UnityEngine;

namespace FF.Gameplay.Tutorial
{
    /// <summary>
    /// The bobbing, spinning honey cone (prototype <c>arrow</c>) over the current tutorial target, or, with no tutorial
    /// target, over the guide target of the last unlock card.
    /// </summary>
    public sealed class TutorialArrow : MonoBehaviour
    {
        const float BobFrequency = 4f;
        const float BobHeight = 0.25f;
        const float SpinSpeed = 2f;

        [SerializeField] TutorialService tutorial;
        [SerializeField] UnlockService unlocks;
        [SerializeField] GameObject cone;

        float _spin;
        FF.Core.GameMode _mode;

        /// <summary>Editor tools only.</summary>
        public void Setup(TutorialService service, UnlockService unlockService, GameObject coneObject)
        {
            tutorial = service;
            unlocks = unlockService;
            cone = coneObject;
        }

        void LateUpdate()
        {
            _mode ??= FF.Core.Services.Get<FF.Core.GameMode>();
            Vector3 target = default;
            bool show = !_mode.InMenu && (tutorial.TryGetTarget(out target) || unlocks.TryGetGuide(out target));
            if (cone.activeSelf != show) cone.SetActive(show);
            if (!show) return;
            target.y += Mathf.Sin(Time.time * BobFrequency) * BobHeight;
            _spin += Time.deltaTime * SpinSpeed * Mathf.Rad2Deg;
            transform.SetPositionAndRotation(target, Quaternion.Euler(0f, _spin, 0f));
        }
    }
}
