using FF.Core;
using FF.Gameplay.Characters;
using Unity.Cinemachine;
using UnityEngine;

namespace FF.Gameplay.CameraRig
{
    /// <summary>
    /// Prototype menu camera (<c>updCamera</c>, mode 'menu'): orbits the player at 0.22 rad/s, radius 6.2 in portrait /
    /// 5.4 in landscape, 1.7 m high, looking at the player's feet (y −0.55 / −0.05); the player turns to the camera.
    /// Real time, so it moves while the menu pauses the game. Its Cinemachine camera is enabled only while the menu is
    /// open (a disabled camera never competes with the play camera); the brain blends between the two.
    /// </summary>
    public sealed class MenuCameraOrbit : MonoBehaviour
    {
        const float AngularSpeed = 0.22f;
        const float RadiusPortrait = 6.2f, RadiusLandscape = 5.4f;
        const float Height = 1.7f;
        const float LookYPortrait = -0.55f, LookYLandscape = -0.05f;

        [SerializeField] CinemachineCamera menuCamera;
        [SerializeField] Transform player;
        [SerializeField] CharacterAnimator playerAnimator;

        GameMode _mode;
        float _angle;

        /// <summary>Editor tools only.</summary>
        public void Setup(CinemachineCamera camera, Transform playerTransform, CharacterAnimator animator)
        {
            menuCamera = camera;
            player = playerTransform;
            playerAnimator = animator;
        }

        void Start()
        {
            _mode = Services.Get<GameMode>();
            LensSettings lens = menuCamera.Lens;
            lens.FieldOfView = Services.Get<FF.Data.GameDatabase>().world.camera.fieldOfView;
            menuCamera.Lens = lens;
            _mode.Changed += OnModeChanged;
            OnModeChanged(_mode.InMenu);
            Place();
        }

        void OnDestroy()
        {
            if (_mode != null) _mode.Changed -= OnModeChanged;
        }

        void OnModeChanged(bool inMenu)
        {
            if (inMenu) Place(); // start the blend from the orbit spot, not from where the menu camera was left
            menuCamera.enabled = inMenu;
        }

        void LateUpdate()
        {
            if (!_mode.InMenu) return;
            _angle += Mathf.Min(Time.unscaledDeltaTime, 0.05f) * AngularSpeed;
            Place();
            playerAnimator.FacingYaw = AgentMotor.YawFromPrototype(_angle);
        }

        void Place()
        {
            bool portrait = Screen.height > Screen.width;
            float r = portrait ? RadiusPortrait : RadiusLandscape;
            Vector3 p = player.position;
            // prototype offset (sin a, cos a)·r in proto x / z; proto +z is Unity −z
            var eye = new Vector3(p.x + Mathf.Sin(_angle) * r, Height, p.z - Mathf.Cos(_angle) * r);
            var look = new Vector3(p.x, portrait ? LookYPortrait : LookYLandscape, p.z);
            menuCamera.transform.SetPositionAndRotation(eye, Quaternion.LookRotation(look - eye, Vector3.up));
        }
    }
}
