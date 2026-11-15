using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Effects;
using FF.Gameplay.Items;
using FF.Gameplay.Player;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// Dream House slots at play time (M10), one loop like <see cref="Pads.PadSystem"/>: a product dropped on a factory
    /// slot's zone is placed; standing still on a Home Store slot with a box of its group in the hands unpacks it there
    /// (an empty slot) or swaps it with the placed variant, whose box comes back into the hands — once per visit to the
    /// slot. Also shows the "room complete" toast and confetti.
    /// </summary>
    public sealed class HomeSlotSystem : MonoBehaviour
    {
        const string Table = "Game";

        [SerializeField] List<HomeSlot> slots = new List<HomeSlot>();
        [SerializeField] PlayerMover player;

        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        HomeService _home;
        EconomyConfig _economy;
        ItemPool _pool;
        EffectsSystem _effects;
        HomeBoxes _boxes;
        HomeSlot _acted;
        bool _dirty = true, _started;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<HomeSlot> slotList, PlayerMover playerMover)
        {
            slots = slotList;
            player = playerMover;
        }

        void Start()
        {
            _home = Services.Get<HomeService>();
            _economy = Services.Get<GameDatabase>().economy;
            _pool = Services.Get<ItemPool>();
            Services.TryGet(out _effects);
            _boxes = Services.Get<HomeBoxes>();
            var db = Services.Get<GameDatabase>();
            foreach (HomeSlot slot in slots)
            {
                slot.Def = _home.Def.Slot(slot.SlotId);
                if (slot.Zone == null || slot.Def == null) continue;
                string id = slot.SlotId;
                ItemType product = slot.Def.product;
                slot.Zone.Configure(new PileLayout(1, 1, 0f, 0f), () => 1, () => _home.CanPlaceFactory(id, product), db.items,
                    _economy.zoneRadius, 1.4f);
            }
            Refresh(false);
            _started = true;
        }

        void OnEnable()
        {
            GameEvents.HomeChanged += OnChanged;
            GameEvents.HomeAreaCompleted += OnAreaCompleted;
        }

        void OnDisable()
        {
            GameEvents.HomeChanged -= OnChanged;
            GameEvents.HomeAreaCompleted -= OnAreaCompleted;
        }

        void OnChanged() => _dirty = true;

        void Update()
        {
            if (!_started) return;
            if (_dirty) Refresh(true);

            Vector3 p = player.transform.position;
            HomeSlot near = null;
            for (int i = 0; i < slots.Count; i++)
            {
                HomeSlot slot = slots[i];
                if (slot.Def == null) continue;
                if (slot.Zone != null)
                {
                    if (slot.Zone.Stack != null && slot.Zone.Stack.Settled > 0) PlaceDropped(slot);
                    continue;
                }
                if (near == null && Zones.ZoneRegistry.Distance(p, slot.Position) < _economy.padRadius) near = slot;
            }

            if (near == null || near != _acted) _acted = null;
            if (near == null || near == _acted || player.StillTime < _economy.padStillSeconds) return;
            if (UseBox(near)) _acted = near;
        }

        /// <summary>Unpacks or swaps a carried box on a Home Store slot.</summary>
        bool UseBox(HomeSlot slot)
        {
            int stage = _home.Stage;
            if (!HomeRules.IsSlotOpen(_home.Def, slot.Def, stage)) return false;
            bool placed = _home.State.Placed.TryGetValue(slot.SlotId, out string current);
            int index = _boxes.FindCarried(slot.Def.group, placed ? current : null);
            if (index < 0) return false;
            string itemId = _boxes.Carrier.Stack[index].HomeItemId;
            if (!placed)
            {
                // if placing fails the box is still in storage, and the next reconcile puts it back on the pile
                _boxes.Consume(index, slot.Position);
                _home.TryPlaceItem(slot.SlotId, itemId);
            }
            else
            {
                _boxes.Consume(index, slot.Position);
                _home.Swap(slot.SlotId, itemId);
                _boxes.BoxToHands(current, slot.Position);
            }
            GameEvents.RaiseSound(SoundCue.Click);
            if (_effects != null) _effects.Puff(slot.Position);
            return true;
        }

        void PlaceDropped(HomeSlot slot)
        {
            Item item = slot.Zone.Stack.Pop();
            if (item == null) return;
            ItemType type = item.Type;
            _pool.Release(item);
            if (_home.TryPlaceFactory(slot.SlotId, type) && _effects != null) _effects.Puff(slot.Position);
        }

        void Refresh(bool animate)
        {
            _dirty = false;
            int stage = _home.Stage;
            for (int i = 0; i < slots.Count; i++)
            {
                HomeSlot slot = slots[i];
                if (slot.Def == null) continue;
                _home.State.Placed.TryGetValue(slot.SlotId, out string placed);
                slot.Show(placed, HomeRules.IsSlotOpen(_home.Def, slot.Def, stage), animate);
            }
        }

        void OnAreaCompleted(string areaId, long gift)
        {
            HomeDef.AreaDef area = _home.Def.Area(areaId);
            if (area == null) return;
            _args.Clear();
            _args["gift"] = NumberFormat.Money(gift);
            GameEvents.RaiseToast(LocalizationSettings.StringDatabase.GetLocalizedString(Table, area.nameKey),
                LocalizationSettings.StringDatabase.GetLocalizedString(Table, "t.roomDone", new object[] { _args }));
            if (_effects == null) return;
            Vector3 sum = Vector3.zero;
            int n = 0;
            foreach (HomeSlot slot in slots)
                if (slot.Def != null && slot.Def.area == areaId)
                {
                    sum += slot.Position;
                    n++;
                }
            if (n > 0) _effects.Burst(sum / n + Vector3.up);
        }
    }
}
