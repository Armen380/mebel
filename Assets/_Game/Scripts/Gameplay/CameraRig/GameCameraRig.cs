using FF.Core;
using FF.Data;
using Unity.Cinemachine;
using UnityEngine;

namespace FF.Gameplay.CameraRig
{
    /// <summary>
    /// Applies the prototype play camera (WorldLayout.camera) to the Cinemachine camera: lens, follow offset,
    /// damping, and the ×1.45 pull-back in portrait. Re-applies when the screen size or orientation changes.
    /// </summary>
    [DefaultExecutionOrder(-50)]
    public sealed class GameCameraRig : MonoBehaviour
    {
        // Cinemachine damping reaches ~99% (ln 0.01 ≈ -4.6) of the way after "damping" seconds,
        // so an exponential lerp rate r (prototype: 1 - e^(-r·dt)) maps to damping = 4.6 / r.
        const float NegligibleResidual = 4.6f;

        [SerializeField] CinemachineCamera playCamera;
        [SerializeField] CinemachineFollow follow;
        [SerializeField] CinemachineRotationComposer composer;

        WorldLayout.CameraSettings _settings;
        Vector3 _baseOffset;
        int _width, _height;

        void Start()
        {
            _settings = Services.Get<GameDatabase>().world.camera;
            Vector3 o = _settings.playOffset;
            _baseOffset = ProtoCoords.ToUnity(o.x, o.y, o.z);

            LensSettings lens = playCamera.Lens;
            lens.FieldOfView = _settings.fieldOfView;
            lens.NearClipPlane = _settings.nearClip;
            lens.FarClipPlane = _settings.farClip;
            playCamera.Lens = lens;

            float posDamping = NegligibleResidual / _settings.positionLerpRate;
            follow.TrackerSettings.PositionDamping = new Vector3(posDamping, posDamping, posDamping);
            float lookDamping = NegligibleResidual / _settings.lookLerpRate;
            composer.Damping = new Vector2(lookDamping, lookDamping);
            composer.TargetOffset = new Vector3(0f, _settings.lookAtHeight, 0f);

            ApplyAspect();
        }

        void LateUpdate()
        {
            if (Screen.width != _width || Screen.height != _height) ApplyAspect();
        }

        void ApplyAspect()
        {
            _width = Screen.width;
            _height = Screen.height;
            bool portrait = _height > _width * _settings.portraitAspect;
            follow.FollowOffset = _baseOffset * (portrait ? _settings.portraitMultiplier : 1f);
        }
    }
}
