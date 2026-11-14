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
    /// slot's zone is placed; standing still on an empty Home Store slot places an item of its group from storage;
    /// standing still on a placed slot with other variants in storage opens the variant picker. Also shows the
    /// "room complete" toast and confetti.
    /// </summary>
    public sealed class HomeSlotSystem : MonoBehaviour
    {
        const string Table = "Game";
        const float PickerStillSeconds = 0.5f;

        [SerializeField] List<HomeSlot> slots = new List<HomeSlot>();
        [SerializeField] PlayerMover player;

        readonly List<string> _variants = new List<string>(4);
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        HomeService _home;
        EconomyConfig _economy;
        ItemPool _pool;
        EffectsSystem _effects;
        HomeSlot _picker;
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

            HomeSlot picker = null;
            if (near != null)
            {
                bool placed = _home.State.Placed.ContainsKey(near.SlotId);
                if (!placed && player.StillTime >= _economy.padStillSeconds)
                {
                    if (_home.TryPlaceFromStorage(near.SlotId))
                    {
                        GameEvents.RaiseSound(SoundCue.Click);
                        if (_effects != null) _effects.Puff(near.Position);
                    }
                }
                else if (placed && player.StillTime >= PickerStillSeconds &&
                         HomeRules.OtherVariants(_home.Def, _home.State, near.Def, _variants) > 0)
                    picker = near;
            }
            if (picker != _picker)
            {
                _picker = picker;
                GameEvents.RaiseHomeVariantPicker(picker != null ? picker.SlotId : null);
            }
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
