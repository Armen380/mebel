using UnityEngine;

namespace FF.Gameplay.Tutorial
{
    /// <summary>The bobbing, spinning honey cone over the current tutorial target (prototype <c>arrow</c>).</summary>
    public sealed class TutorialArrow : MonoBehaviour
    {
        const float BobFrequency = 4f;
        const float BobHeight = 0.25f;
        const float SpinSpeed = 2f;

        [SerializeField] TutorialService tutorial;
        [SerializeField] GameObject cone;

        float _spin;

        /// <summary>Editor tools only.</summary>
        public void Setup(TutorialService service, GameObject coneObject)
        {
            tutorial = service;
            cone = coneObject;
        }

        void LateUpdate()
        {
            bool show = tutorial.TryGetTarget(out Vector3 target);
            if (cone.activeSelf != show) cone.SetActive(show);
            if (!show) return;
            target.y += Mathf.Sin(Time.time * BobFrequency) * BobHeight;
            _spin += Time.deltaTime * SpinSpeed * Mathf.Rad2Deg;
            transform.SetPositionAndRotation(target, Quaternion.Euler(0f, _spin, 0f));
        }
    }
}
