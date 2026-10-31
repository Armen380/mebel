using FF.Core;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.HUD
{
    /// <summary>Round Throw button (bottom-right): shown only while the player carries something (prototype <c>#btnThrow</c>).</summary>
    public sealed class ThrowButton : MonoBehaviour
    {
        [SerializeField] Button button;
        [Tooltip("The visible part; hidden while the hands are empty.")]
        [SerializeField] GameObject content;

        ICarrier _carrier;

        void Awake() => button.onClick.AddListener(OnClick);

        void Start()
        {
            _carrier = Services.Get<ICarrier>();
            content.SetActive(false);
        }

        void OnClick() => _carrier?.ThrowAll();

        void LateUpdate()
        {
            bool show = _carrier.CarriedCount > 0;
            if (content.activeSelf != show) content.SetActive(show);
        }
    }
}
