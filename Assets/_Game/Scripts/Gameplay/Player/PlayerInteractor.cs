using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Zones;
using UnityEngine;
using UnityEngine.InputSystem;

namespace FF.Gameplay.Player
{
    /// <summary>
    /// The non-movement part of the prototype's <c>updPlayer</c>: chop the nearest node, then the zone loop
    /// (one item per 0.075 s, a bill per 0.035 s on cash zones, first matching zone only), plus the Throw action. Runs after <see cref="PlayerMover"/>.
    /// </summary>
    [DefaultExecutionOrder(10)]
    public sealed class PlayerInteractor : MonoBehaviour
    {
        const string AxeUpgradeId = "axe";
        const float PlayerChopRate = 1f;

        [SerializeField] PlayerMover mover;
        [SerializeField] PlayerCarrier carrier;
        [SerializeField] CharacterAnimator animator;
        [SerializeField] InputActionReference throwAction;

        readonly Chopper _chopper = new Chopper();
        EconomyConfig _economy;
        IUpgradeLevels _upgrades;
        NodeRegistry _nodes;
        ZoneRegistry _zones;
        ItemPool _pool;
        ItemFlights _flights;
        float _cooldown;

        void Start()
        {
            _economy = Services.Get<GameDatabase>().economy;
            _upgrades = Services.Get<IUpgradeLevels>();
            _nodes = Services.Get<NodeRegistry>();
            _zones = Services.Get<ZoneRegistry>();
            _pool = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
        }

        void OnEnable()
        {
            if (throwAction != null) throwAction.action.Enable();
        }

        void OnDisable()
        {
            if (throwAction != null) throwAction.action.Disable();
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            if (throwAction != null && throwAction.action.WasPressedThisFrame()) carrier.ThrowAll();

            animator.Chopping = Chop(dt);
            Transfer(dt);
            animator.Carrying = carrier.Stack.Count > 0;
        }

        bool Chop(float dt)
        {
            Vector3 p = transform.position;
            ResourceNode node = _nodes.Nearest(p);
            if (node == null || ZoneRegistry.Distance(p, node.Position) >= _economy.chopRange) return false;

            ItemStack stack = carrier.Stack;
            Chopper.Result r = _chopper.TryChop(node.State, stack, dt, PlayerChopRate,
                _economy.ChopSeconds(_upgrades.GetLevel(AxeUpgradeId)), _economy.chopHitInterval, _economy.itemsPerChop);
            if (!r.Chopping) return false;

            if (!mover.Moving)
            {
                Vector3 d = node.Position - p;
                animator.FacingYaw = Mathf.Atan2(d.x, d.z) * Mathf.Rad2Deg;
            }
            if (r.Hit) GameEvents.RaiseChopHit();
            if (r.Yield > 0)
            {
                Vector3 at = node.Position;
                for (int i = 0; i < r.Yield; i++)
                {
                    at.y = _economy.chopSpawnHeight + i * _economy.chopSpawnStep;
                    _flights.FlyToStack(_pool.Get(node.State.Type, at), stack, _economy.chopFlightSeconds, _economy.flightArc);
                }
                GameEvents.RaiseChopped();
            }
            return true;
        }

        void Transfer(float dt)
        {
            _cooldown -= dt;
            if (_cooldown > 0f) return;

            Vector3 p = transform.position;
            ItemStack hands = carrier.Stack;
            var zones = _zones.Zones;
            for (int i = 0; i < zones.Count; i++)
            {
                Zone z = zones[i];
                if (!z.IsActive || ZoneRegistry.Distance(p, z.Position) > z.Radius) continue;

                if (z.Kind == ZoneKind.Drop && ZoneTransferRules.CanDrop(hands, z.ItemType, z.Stack))
                {
                    _flights.FlyToStack(hands.Pop(), z.Stack, _economy.transferFlightSeconds, _economy.flightArc);
                    GameEvents.RaiseZoneDropped(z.Id);
                }
                else if (z.Kind == ZoneKind.Pickup && ZoneTransferRules.CanPickup(z.Stack, hands))
                {
                    _flights.FlyToStack(z.Stack.Pop(), hands, _economy.transferFlightSeconds, _economy.flightArc);
                    GameEvents.RaiseZonePicked(z.Id);
                }
                else if (z.Kind == ZoneKind.Cash && z.Stack.Settled > 0)
                {
                    _flights.FlyAndCollect(z.Stack.Pop(), transform, _economy.cashTargetHeight,
                        _economy.cashFlightSeconds, _economy.cashFlightArc);
                    GameEvents.RaiseCashCollected();
                    _cooldown = _economy.cashTransferInterval;
                    return;
                }
                else continue;

                _cooldown = _economy.transferInterval;
                return;
            }
        }
    }
}
