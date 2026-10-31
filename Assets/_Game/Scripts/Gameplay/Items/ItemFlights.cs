using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Progress;
using UnityEngine;

namespace FF.Gameplay.Items
{
    /// <summary>
    /// Runs every item flight of the prototype's <c>fly/sendTo/updTweens</c> and the throw shrink, from one list of
    /// structs — no coroutine or allocation per item. Runs after gameplay so targets are up to date.
    /// </summary>
    [DefaultExecutionOrder(100)]
    public sealed class ItemFlights : MonoBehaviour
    {
        enum Landing
        {
            IntoStack,
            Despawn,
            Shrink,
            Collect,
        }

        struct Flight
        {
            public Item Item;
            public Vector3 Start;
            public Vector3 Target;
            public ItemStack Stack;
            public Transform Follow;
            public float Time;
            public float Duration;
            public float Arc;
            public Landing Landing;
        }

        struct Shrinking
        {
            public Item Item;
            public float Time;
        }

        readonly List<Flight> _flights = new List<Flight>(128);
        readonly List<Shrinking> _shrinking = new List<Shrinking>(32);
        ItemPool _pool;
        EconomyConfig _economy;
        GameProgress _progress;

        public int ActiveFlights => _flights.Count;

        void Awake()
        {
            _pool = Services.Get<ItemPool>();
            _economy = Services.Get<GameDatabase>().economy;
            _progress = Services.Get<GameProgress>();
        }

        /// <summary>Prototype <c>sendTo</c>: the item flies to the stack's live next slot and is placed there.</summary>
        public void FlyToStack(Item item, ItemStack stack, float duration, float arc)
        {
            stack.BeginIncoming(item.Type);
            Add(item, Vector3.zero, stack, duration, arc, Landing.IntoStack);
        }

        /// <summary>The item flies to a point and returns to the pool (into a machine mouth).</summary>
        public void FlyAndDespawn(Item item, Vector3 target, float duration, float arc) =>
            Add(item, target, null, duration, arc, Landing.Despawn);

        /// <summary>The item flies to a point on the ground, shrinks away and returns to the pool (throw).</summary>
        public void FlyAndShrink(Item item, Vector3 target, float duration, float arc) =>
            Add(item, target, null, duration, arc, Landing.Shrink);

        /// <summary>
        /// A bill flies to a moving target (the player, live position + height) and its value is added to the
        /// balance on landing (prototype cash zone: <c>fly(b, ()=>P.pos…, …, addMoney(v))</c>).
        /// </summary>
        public void FlyAndCollect(Item bill, Transform follow, float height, float duration, float arc)
        {
            Add(bill, new Vector3(0f, height, 0f), null, duration, arc, Landing.Collect);
            Flight f = _flights[_flights.Count - 1];
            f.Follow = follow;
            _flights[_flights.Count - 1] = f;
        }

        void Add(Item item, Vector3 target, ItemStack stack, float duration, float arc, Landing landing)
        {
            Transform t = item.transform;
            t.SetParent(transform, true); // prototype scene.attach: keep the world transform
            _flights.Add(new Flight
            {
                Item = item,
                Start = t.position,
                Target = target,
                Stack = stack,
                Duration = Mathf.Max(0.0001f, duration),
                Arc = arc,
                Landing = landing,
            });
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);

            for (int i = _flights.Count - 1; i >= 0; i--)
            {
                Flight f = _flights[i];
                f.Time += dt;
                float k = Mathf.Min(1f, f.Time / f.Duration);
                Vector3 target = f.Landing == Landing.IntoStack ? f.Stack.NextSlotWorld(f.Item.Type)
                    : f.Follow != null ? f.Follow.position + f.Target
                    : f.Target;
                f.Item.transform.position = ItemArc.Evaluate(f.Start, target, k, f.Arc);

                if (k < 1f)
                {
                    _flights[i] = f;
                    continue;
                }
                _flights.RemoveAt(i);
                switch (f.Landing)
                {
                    case Landing.IntoStack: f.Stack.CompleteIncoming(f.Item); break;
                    case Landing.Despawn: _pool.Release(f.Item); break;
                    case Landing.Shrink: _shrinking.Add(new Shrinking { Item = f.Item }); break;
                    case Landing.Collect:
                        long value = f.Item.Value;
                        _pool.Release(f.Item);
                        _progress.AddMoney(value);
                        break;
                }
            }

            for (int i = _shrinking.Count - 1; i >= 0; i--)
            {
                Shrinking s = _shrinking[i];
                s.Time += dt;
                s.Item.transform.localScale = Vector3.one * Mathf.Max(0.01f, 1f - s.Time * _economy.throwShrinkRate);
                if (s.Time >= _economy.throwShrinkSeconds)
                {
                    _shrinking.RemoveAt(i);
                    _pool.Release(s.Item);
                }
                else _shrinking[i] = s;
            }
        }
    }
}
