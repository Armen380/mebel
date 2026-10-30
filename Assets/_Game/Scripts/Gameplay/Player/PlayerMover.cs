using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Input;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Player
{
    /// <summary>
    /// Kinematic player movement (prototype <c>updPlayer()</c> movement part): input → walk speed →
    /// region rules → blocker push-out. No physics.
    /// </summary>
    public sealed class PlayerMover : MonoBehaviour
    {
        const string SpeedUpgradeId = "speed";
        const float MaxStep = 0.05f;

        [SerializeField] MoveInputAggregator input;
        [SerializeField] CharacterAnimator animator;

        EconomyConfig _economy;
        WorldCollision _collision;
        IUpgradeLevels _upgrades;

        public bool Moving { get; private set; }
        /// <summary>Seconds without moving; pads start charging after 0.3 s (M4).</summary>
        public float StillTime { get; private set; }

        void Start()
        {
            _economy = Services.Get<GameDatabase>().economy;
            _collision = Services.Get<WorldCollision>();
            _upgrades = Services.Get<IUpgradeLevels>();
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, MaxStep);
            Vector2 move = input.Value;
            Vector3 p = transform.position;

            Moving = MoveInputMath.IsActive(move);
            if (Moving)
            {
                float magnitude = move.magnitude;
                float speed = _economy.PlayerSpeed(_upgrades.GetLevel(SpeedUpgradeId)) * Mathf.Min(1f, magnitude);
                Vector2 dir = move / magnitude;
                p.x += dir.x * speed * dt;
                p.z += dir.y * speed * dt;
                animator.FacingYaw = Mathf.Atan2(dir.x, dir.y) * Mathf.Rad2Deg;
            }
            StillTime = Moving ? 0f : StillTime + dt;

            Vector2 resolved = _collision.ResolvePlayer(new Vector2(p.x, p.z));
            transform.position = new Vector3(resolved.x, p.y, resolved.y);
            animator.Moving = Moving;
        }
    }
}
