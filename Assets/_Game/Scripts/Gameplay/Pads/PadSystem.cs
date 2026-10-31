using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Items;
using FF.Gameplay.Player;
using FF.Gameplay.Progress;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Pads
{
    /// <summary>
    /// Prototype <c>updPads</c>: the player stands still (0.3 s) on a visible pad and money drains into it
    /// (a full price in 1.4 s), a bill flies to the pad every 0.07 s; when paid, the pad levels up.
    /// Partial payments are kept on the pad.
    /// </summary>
    public sealed class PadSystem : MonoBehaviour
    {
        const string Table = "Game";
        const float BillHeight = 1.3f, PadBillHeight = 0.1f, DoneTextHeight = 1.6f;

        [SerializeField] List<UpgradePad> pads = new List<UpgradePad>();
        [SerializeField] PlayerMover player;

        EconomyConfig _economy;
        GameProgress _progress;
        ItemPool _items;
        ItemFlights _flights;
        float _billTimer;

        public IReadOnlyList<UpgradePad> Pads => pads;

        /// <summary>Editor tools only.</summary>
        public void Setup(List<UpgradePad> padList, PlayerMover playerMover)
        {
            pads = padList;
            player = playerMover;
        }

        public UpgradePad Find(string padId)
        {
            foreach (UpgradePad p in pads)
                if (p.Def.id == padId) return p;
            return null;
        }

        void Start()
        {
            _economy = Services.Get<GameDatabase>().economy;
            _progress = Services.Get<GameProgress>();
            _items = Services.Get<ItemPool>();
            _flights = Services.Get<ItemFlights>();
        }

        void Update()
        {
            float dt = Mathf.Min(Time.deltaTime, 0.05f);
            Vector3 p = player.transform.position;
            UpgradePad on = null;
            for (int i = 0; i < pads.Count; i++)
            {
                UpgradePad pad = pads[i];
                if (pad.IsVisible && Zones.ZoneRegistry.Distance(p, pad.Position) < _economy.padRadius) on = pad;
            }
            if (on == null || player.StillTime < _economy.padStillSeconds || _progress.Money <= 0) return;

            long price = on.Price;
            GameProgress.PadState state = on.State;
            long amount = _economy.PadPayment(_progress.Money, price - state.Paid, price, dt);
            if (amount <= 0 || !_progress.Spend(amount)) return;
            state.Paid += amount;

            _billTimer -= dt;
            if (_billTimer <= 0f)
            {
                _billTimer = _economy.padBillInterval;
                Item bill = _items.Get(ItemType.Bill, new Vector3(p.x, BillHeight, p.z));
                Vector3 target = on.Position;
                target.y = PadBillHeight;
                _flights.FlyAndDespawn(bill, target, _economy.padBillFlightSeconds, _economy.padBillArc);
            }

            if (state.Paid < price) return;
            state.Paid = 0;
            state.Level++;
            Vector3 textAt = on.Position;
            textAt.y = DoneTextHeight;
            GameEvents.RaiseFloatText(textAt, LocalizationSettings.StringDatabase.GetLocalizedString(Table, on.Def.doneKey));
            GameEvents.RaisePadCompleted(on.Def.id, state.Level);
        }
    }
}
