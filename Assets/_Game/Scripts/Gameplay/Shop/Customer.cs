using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Characters;
using FF.Gameplay.Items;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>
    /// One walk-in customer: the per-customer fields of the prototype (<c>state, want, wait, patience, serve,
    /// takeT, qi, partial, waitReg, angry</c>) plus a carry stack and the speech bubble. Driven by <see cref="CustomerDirector"/>.
    /// </summary>
    [RequireComponent(typeof(CharacterRig), typeof(CharacterAnimator))]
    public sealed class Customer : MonoBehaviour, IWorldTagSource
    {
        public enum Phase
        {
            Shelf,
            Register,
            Out,
        }

        const float BubbleHeight = 2.45f;
        const float ArriveDistance = 0.06f;

        public const string CashIcon = "cash";
        public const string AngryIcon = "angry";

        readonly List<Vector3> _way = new List<Vector3>(6);
        int _wayIndex;

        public CharacterAnimator Animator { get; private set; }
        public ItemStack Hands { get; private set; }
        public int PoolIndex { get; set; }

        public Phase State;
        public ProductDef Want;
        public Shelf Shelf;
        public Register Register;
        public int Need = 1;
        public float Wait, Patience, Serve, Partial, WaitRegister;
        public float TakeTimer = -1f;
        public int QueueIndex;
        public bool Angry;

        float _cashBubbleDelay, _shelfBubbleDelay;

        public bool HasWay => _wayIndex < _way.Count;

        public void Init(ItemCatalog catalog, float cashBubbleDelay, float shelfBubbleDelay)
        {
            Animator = GetComponent<CharacterAnimator>();
            Hands = new ItemStack(GetComponent<CharacterRig>().carryAnchor, CarryLayout.Instance, catalog, () => Need);
            _cashBubbleDelay = cashBubbleDelay;
            _shelfBubbleDelay = shelfBubbleDelay;
        }

        /// <summary>Fresh state for a new visit (prototype <c>spawnCustomer</c> fields).</summary>
        public void Begin(ProductDef want, Shelf shelf, float patience)
        {
            State = Phase.Shelf;
            Want = want;
            Shelf = shelf;
            Register = null;
            Need = 1;
            Wait = Serve = Partial = WaitRegister = 0f;
            TakeTimer = -1f;
            QueueIndex = 0;
            Angry = false;
            Patience = patience;
            ClearWay();
        }

        public void ClearWay()
        {
            _way.Clear();
            _wayIndex = 0;
        }

        public void AddWaypoint(Vector3 p) => _way.Add(p);

        /// <summary>Walks the next way-point; returns true when the whole way is done.</summary>
        public bool FollowWay(float dt, float speed)
        {
            if (MoveTo(_way[_wayIndex], dt, speed)) _wayIndex++;
            return !HasWay;
        }

        /// <summary>Prototype <c>moveTo</c>: straight step toward the target, faces the walking direction.</summary>
        public bool MoveTo(Vector3 target, float dt, float speed)
        {
            Vector3 p = transform.position;
            float dx = target.x - p.x, dz = target.z - p.z, d = Mathf.Sqrt(dx * dx + dz * dz);
            if (d < ArriveDistance)
            {
                Animator.Moving = false;
                return true;
            }
            float step = Mathf.Min(d, speed * dt);
            p.x += dx / d * step;
            p.z += dz / d * step;
            transform.position = p;
            Animator.FacingYaw = Mathf.Atan2(dx, dz) * Mathf.Rad2Deg;
            Animator.Moving = true;
            return d - step < ArriveDistance;
        }

        public bool TagVisible => TagIcon != null;
        public Vector3 TagPosition
        {
            get
            {
                Vector3 p = transform.position;
                p.y = BubbleHeight;
                return p;
            }
        }
        public WorldTagStyle TagStyle => WorldTagStyle.Bubble;
        public int TagCount => 0;
        public int TagCapacity => 0;
        public long TagValue => 0;

        /// <summary>Prototype bubble rules: angry face; cash icon at a register nobody serves; wanted product at an empty shelf.</summary>
        public string TagIcon
        {
            get
            {
                if (Angry) return AngryIcon;
                if (HasWay) return null;
                if (State == Phase.Register && QueueIndex == 0 && WaitRegister > _cashBubbleDelay) return CashIcon;
                if (State == Phase.Shelf && QueueIndex == 0 && Wait > _shelfBubbleDelay && TakeTimer < 0f && Shelf.Stack.Settled == 0)
                    return Want.id;
                return null;
            }
        }
    }
}
