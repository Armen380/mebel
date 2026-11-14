using FF.Core;
using FF.Data;
using FF.Gameplay.CameraRig;
using FF.Gameplay.Player;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Dream House inside view (M10): while the player stands inside the house footprint and the roof is built, the
    /// front wall sinks to the ground (0.25 s) and the roof and front windows hide; the camera moves in (×0.75).
    /// </summary>
    public sealed class HouseCutaway : MonoBehaviour
    {
        const float SinkSeconds = 0.25f, Zoom = 0.75f, Margin = 0.15f;
        const int RoofStage = 3;

        [Tooltip("Hidden at once (roof, front window frames).")]
        [SerializeField] GameObject[] hide;
        [Tooltip("Sinks to the ground (front wall).")]
        [SerializeField] Transform[] sink;
        [SerializeField] PlayerMover player;

        WorldStateSnapshot _state;
        GameCameraRig _rig;
        Aabb2D _inside;
        bool _in;
        float _k = 1f;

        /// <summary>Editor tools only.</summary>
        public void Setup(GameObject[] hideObjects, Transform[] sinkObjects, PlayerMover playerMover)
        {
            hide = hideObjects;
            sink = sinkObjects;
            player = playerMover;
        }

        void Start()
        {
            _state = Services.Get<WorldStateSnapshot>();
            _rig = FindFirstObjectByType<GameCameraRig>();
            WorldLayout.DreamHouseSettings d = Services.Get<GameDatabase>().world.dreamHouse;
            Vector2 c = d.foundationCenter, s = d.foundationSize;
            _inside = ProtoCoords.ToUnityRect(c.x - s.x / 2 + Margin, c.x + s.x / 2 - Margin, c.y - s.y / 2 + Margin, c.y + s.y / 2 - Margin);
        }

        public static bool IsInside(Vector3 p, Aabb2D r) => p.x > r.MinX && p.x < r.MaxX && p.z > r.MinZ && p.z < r.MaxZ;

        void LateUpdate()
        {
            bool inside = _state.HouseStage >= RoofStage && IsInside(player.transform.position, _inside);
            if (inside != _in)
            {
                _in = inside;
                foreach (GameObject go in hide) go.SetActive(!inside);
                if (_rig != null) _rig.SetZoom(inside ? Zoom : 1f);
                if (!inside) SetSink(true);
            }
            float target = inside ? 0f : 1f;
            if (Mathf.Approximately(_k, target)) return;
            _k = Mathf.MoveTowards(_k, target, Time.deltaTime / SinkSeconds);
            foreach (Transform t in sink) t.localScale = new Vector3(1f, Mathf.Max(0.001f, _k), 1f);
            if (_k <= 0f) SetSink(false);
        }

        void SetSink(bool active)
        {
            foreach (Transform t in sink)
                if (t.gameObject.activeSelf != active) t.gameObject.SetActive(active);
        }
    }
}
