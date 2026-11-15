using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Player;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Home Store boxes (M10 play-test change): every bought, not yet placed item is a <see cref="ItemType.HomeBox"/> in
    /// the world — on the pickup pile at the store counter, in the player's hands or flying. The boxes follow the home
    /// storage (spawned on the pile when bought or loaded); unpacking or swapping on a slot consumes a box; thrown boxes
    /// fly back to the pile.
    /// </summary>
    public sealed class HomeBoxes : MonoBehaviour
    {
        const float SpawnHeight = 1.2f;

        [SerializeField] Zone pile;
        [SerializeField] PlayerCarrier carrier;

        readonly List<Item> _boxes = new List<Item>();
        readonly List<string> _ids = new List<string>();
        readonly List<string> _spawn = new List<string>();
        readonly List<int> _extra = new List<int>();
        HomeService _home;
        HomeDef _def;
        ItemPool _pool;
        ItemFlights _flights;
        EconomyConfig _economy;
        WorldStateSnapshot _state;
        bool _dirty = true, _started;
        int _sortedCount = -1;

        public PlayerCarrier Carrier => carrier;

        /// <summary>Editor tools only.</summary>
        public void Setup(Zone pileZone, PlayerCarrier playerCarrier)
        {
            pile = pileZone;
            carrier = playerCarrier;
        }

        void Awake() => Services.Register(this);

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            _home = Services.Get<HomeService>();
            _def = db.home;
            _pool = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
            _economy = db.economy;
            _state = Services.Get<WorldStateSnapshot>();
            pile.Configure(new PileLayout(3, 3, 0.55f, 0.55f), () => 64, () => _state.HouseStage >= 1, db.items, _economy.zoneRadius, 1.6f);
            _started = true;
        }

        void OnEnable() => GameEvents.HomeChanged += MarkDirty;

        void OnDisable() => GameEvents.HomeChanged -= MarkDirty;

        void MarkDirty() => _dirty = true;

        void Update()
        {
            if (!_started) return;
            if (_dirty) Reconcile();
            // boxes land on the pile after their flight: sort again whenever the pile changes
            if (pile.Stack.Settled != _sortedCount) SortPile();
        }

        /// <summary>Spawns boxes for storage items that have none and removes boxes whose item is gone.</summary>
        void Reconcile()
        {
            _dirty = false;
            for (int i = _boxes.Count - 1; i >= 0; i--)
                if (_boxes[i] == null || !_boxes[i].gameObject.activeInHierarchy) _boxes.RemoveAt(i);
            _ids.Clear();
            foreach (Item b in _boxes) _ids.Add(b.HomeItemId);
            HomeRules.BoxDiff(_home.State.Storage, _ids, _spawn, _extra);
            for (int i = _extra.Count - 1; i >= 0; i--)
            {
                Item box = _boxes[_extra[i]];
                if (!TakeOut(box)) continue;
                _boxes.RemoveAt(_extra[i]);
                _pool.Release(box);
            }
            Vector3 at = pile.Position + Vector3.up * SpawnHeight;
            foreach (string id in _spawn)
            {
                Item box = Make(id, at);
                _flights.FlyToStack(box, pile.Stack, _economy.transferFlightSeconds, _economy.flightArc);
            }
            SortPile();
        }

        /// <summary>
        /// The hands take the top box, one at a time: boxes that have a free slot go on top, so the player is not handed a
        /// box that can only be swapped (play-test 2026-11-15: "I took a box but can't place it anywhere").
        /// </summary>
        void SortPile()
        {
            ItemStack s = pile.Stack;
            int stage = _home.Stage;
            int n = s.Settled;
            _sortedCount = n;
            for (int i = 0, moved = 0; i < n - moved; )
            {
                HomeDef.HomeItemDef item = _def.Item(s[i].HomeItemId);
                if (item != null && HomeRules.HasFreeSlot(_def, _home.State, item.group, stage))
                {
                    s.Place(s.RemoveAt(i));
                    moved++;
                }
                else i++;
            }
        }

        /// <summary>Removes a settled box from the pile or the hands (false while it is flying).</summary>
        bool TakeOut(Item box)
        {
            ItemStack[] stacks = { pile.Stack, carrier.Stack };
            foreach (ItemStack s in stacks)
                for (int i = 0; i < s.Settled; i++)
                    if (s[i] == box)
                    {
                        s.RemoveAt(i);
                        return true;
                    }
            return false;
        }

        Item Make(string itemId, Vector3 at)
        {
            Item box = _pool.Get(ItemType.HomeBox, at);
            box.HomeItemId = itemId;
            HomeDef.HomeItemDef item = _def.Item(itemId);
            Sprite icon = item != null ? _def.Icon(item.group) : null;
            if (box.TryGetComponent(out HomeBoxLabel label)) label.SetIcon(icon != null ? icon.texture : null);
            _boxes.Add(box);
            return box;
        }

        /// <summary>Floor-arrow target while a box is in the hands: its slot (nearest free, else a swap).</summary>
        public bool TryGetGuide(out Vector3 target)
        {
            target = default;
            ItemStack hands = carrier.Stack;
            if (!_started || hands.Type != ItemType.HomeBox || hands.Settled == 0) return false;
            Vector3 p = carrier.transform.position;
            HomeDef.SlotDef slot = HomeRules.TargetSlot(_def, _home.State, hands[hands.Settled - 1].HomeItemId, _home.Stage,
                new Vector2(p.x, -p.z)); // Unity → prototype (z mirrored)
            if (slot == null) return false;
            target = ProtoCoords.ToUnity(slot.protoPos.x, slot.protoPos.y);
            return true;
        }

        /// <summary>The top-most carried box of a group (optionally not of one item); -1 if none.</summary>
        public int FindCarried(string group, string notItem)
        {
            ItemStack hands = carrier.Stack;
            if (hands.Type != ItemType.HomeBox) return -1;
            for (int i = hands.Settled - 1; i >= 0; i--)
            {
                string id = hands[i].HomeItemId;
                HomeDef.HomeItemDef item = _def.Item(id);
                if (item != null && item.group == group && id != notItem) return i;
            }
            return -1;
        }

        /// <summary>Unpacks a carried box: it flies to the slot and disappears (its item is placed there by the caller).</summary>
        public void Consume(int handIndex, Vector3 slot)
        {
            Item box = carrier.Stack.RemoveAt(handIndex);
            if (box == null) return;
            _boxes.Remove(box);
            box.HomeItemId = null;
            _flights.FlyAndDespawn(box, slot + Vector3.up * 0.4f, _economy.transferFlightSeconds, _economy.flightArc);
        }

        /// <summary>The swapped-out item comes back as a box into the hands (or to the pile when the hands are full).</summary>
        public void BoxToHands(string itemId, Vector3 from)
        {
            Item box = Make(itemId, from + Vector3.up * 0.6f);
            ItemStack hands = carrier.Stack;
            bool fits = (hands.Type == ItemType.None || hands.Type == ItemType.HomeBox) && hands.HasRoom;
            _flights.FlyToStack(box, fits ? hands : pile.Stack, _economy.transferFlightSeconds, _economy.flightArc);
        }

        /// <summary>A thrown box flies back onto the pile instead of vanishing.</summary>
        public void Return(Item box) =>
            _flights.FlyToStack(box, pile.Stack, _economy.throwFlightSeconds * 2f, _economy.throwArc);
    }
}
