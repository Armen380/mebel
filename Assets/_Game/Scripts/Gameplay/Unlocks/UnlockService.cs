using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.Pads;
using FF.Gameplay.Progress;
using FF.Gameplay.World;
using UnityEngine;
using UnityEngine.Localization.Settings;

namespace FF.Gameplay.Unlocks
{
    /// <summary>
    /// Prototype <c>notify / checkUnlocks / updUnlock</c>: every newly available thing gets one "NEW" card (each id once,
    /// remembered in the save); cards queue and show one at a time for 4.6 s; a card with a target points the guide
    /// arrow there for 12 s or until the player is within 1.5 m. On boot the check is silent (marks without showing).
    /// </summary>
    public sealed class UnlockService : MonoBehaviour
    {
        const string Table = "Game";
        const float CardSeconds = 4.6f, GuideSeconds = 12f, GuideReach = 1.5f, GuideHeight = 3f;
        const string BuySuffix = "_buy";

        [SerializeField] Transform player;

        readonly List<UnlockCard> _candidates = new List<UnlockCard>(8);
        readonly Queue<UnlockCard> _queue = new Queue<UnlockCard>();
        readonly Dictionary<string, object> _args = new Dictionary<string, object>();
        GameDatabase _db;
        GameProgress _progress;
        WorldStateSnapshot _state;
        PadSystem _pads;
        float _cardTimer = -1f, _guideUntil;
        Vector3 _guide;
        bool _hasGuide;
        GameMode _mode;
        // skins unlocked by earnings: card id and threshold, so the money check allocates nothing
        readonly List<(string card, long threshold)> _skinCards = new List<(string, long)>();

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform playerTransform) => player = playerTransform;

        void Start()
        {
            _db = Services.Get<GameDatabase>();
            _progress = Services.Get<GameProgress>();
            _state = Services.Get<WorldStateSnapshot>();
            _pads = Services.Get<PadSystem>();
            _mode = Services.Get<GameMode>();
            foreach (SkinDef s in _db.skins)
                if (s.unlockTotalEarned > 0) _skinCards.Add((UnlockRules.SkinCardId(s.id), s.unlockTotalEarned));
            Check(true);
        }

        void OnEnable()
        {
            GameEvents.LevelUp += OnLevelUp;
            GameEvents.PadCompleted += OnPadCompleted;
            GameEvents.QuestChanged += OnQuestChanged;
            GameEvents.MoneyChanged += OnMoneyChanged;
        }

        void OnDisable()
        {
            GameEvents.LevelUp -= OnLevelUp;
            GameEvents.PadCompleted -= OnPadCompleted;
            GameEvents.QuestChanged -= OnQuestChanged;
            GameEvents.MoneyChanged -= OnMoneyChanged;
        }

        /// <summary>Prototype <c>addMoney</c>: total ≥ 100K and skin_gold not seen → checkUnlocks.</summary>
        void OnMoneyChanged(long money, bool bump)
        {
            if (_progress == null) return;
            for (int i = 0; i < _skinCards.Count; i++)
                if (_progress.TotalEarned >= _skinCards[i].threshold && !_progress.IsSeen(_skinCards[i].card))
                {
                    Check(false);
                    return;
                }
        }

        void OnLevelUp(int level) => Check(false);

        void OnPadCompleted(string padId, int level)
        {
            if (padId == WorldStateSync.ShopPadId || padId.EndsWith(BuySuffix)) Check(false);
        }

        void OnQuestChanged(int step)
        {
            if (step >= _db.tutorial.steps.Count) Check(false);
        }

        /// <summary>Prototype <c>checkUnlocks(silent)</c>.</summary>
        public void Check(bool silent)
        {
            UnlockRules.Collect(_db.products, _db.upgrades, _state.Owns, HasBuyPad, _progress.Level,
                _progress.GetLevel(WorldStateSync.RegisterPadId), _progress.GetLevel(WorldStateSync.ShopPadId),
                _state.OwnsPlumbing, _progress.QuestStep >= _db.tutorial.steps.Count, _candidates, _db.skins, _progress.TotalEarned);
            foreach (UnlockCard card in _candidates)
                if (_progress.MarkSeen(card.Id) && !silent)
                    _queue.Enqueue(card);
        }

        bool HasBuyPad(string productId) => _pads.Find(productId + BuySuffix) != null;

        void Update()
        {
            if (_mode != null && _mode.InMenu) return; // cards wait for play (prototype updUnlock)
            if (_cardTimer >= 0f)
            {
                _cardTimer -= Time.deltaTime;
                if (_cardTimer < 0f) GameEvents.RaiseUnlockCardHidden();
                return;
            }
            if (_queue.Count == 0) return;
            Show(_queue.Dequeue());
        }

        void Show(UnlockCard card)
        {
            _cardTimer = CardSeconds;
            string icon, title, subtitle;
            Vector3? target = null;
            switch (card.Kind)
            {
                case UnlockKind.Factory:
                    ProductDef p = _db.Product(card.ProductId);
                    UpgradePad pad = _pads.Find(p.id + BuySuffix);
                    icon = "fac";
                    title = Text("un.fac.t", "name", Text(p.nameKey));
                    subtitle = Text("un.fac.s", "price", NumberFormat.Compact(pad.Price - pad.State.Paid));
                    target = pad.Position;
                    break;
                case UnlockKind.FactoryWith:
                    ProductDef with = _db.Product(card.ProductId);
                    icon = "fac";
                    title = Text("un.fac.t", "name", Text(with.nameKey));
                    subtitle = Text("un.with.s");
                    target = ProtoCoords.ToUnity(with.factoryX, _db.world.factories.ZoneZ(with.factoryRow));
                    break;
                case UnlockKind.Mines:
                    icon = "mine";
                    title = Text("un.mines.t");
                    subtitle = Text("un.mines.s");
                    target = ProtoCoords.ToUnity(_db.world.mines.cardTarget);
                    break;
                case UnlockKind.MaterialsShop:
                    icon = "shop";
                    title = Text("un.matshop.t");
                    subtitle = Text("un.matshop.s");
                    target = ProtoCoords.ToUnity(_db.world.materialsShop.cardTarget);
                    break;
                case UnlockKind.Skin:
                    icon = "skin";
                    title = Text("un.skin.t", "name", Text(_db.Skin(card.ProductId).nameKey));
                    subtitle = Text("un.skin.s");
                    break;
                case UnlockKind.Register:
                    icon = "reg";
                    title = Text("un.reg.t");
                    subtitle = Text("un.reg.s");
                    UpgradePad reg = _pads.Find(WorldStateSync.RegisterPadId);
                    if (reg != null) target = reg.Position;
                    break;
                case UnlockKind.Staff:
                    icon = "staff";
                    title = Text("un.staff.t", "name", Text(_db.Upgrade(card.ProductId).nameKey));
                    subtitle = Text("un.staff.s");
                    break;
                case UnlockKind.Sawmill2:
                    icon = "saw";
                    title = Text("un.saw2.t");
                    subtitle = Text("un.saw2.s");
                    UpgradePad buy = _pads.Find(PadRewards.Sawmill2BuyPad);
                    if (buy != null) target = buy.Position;
                    break;
                default:
                    icon = "house";
                    title = Text("un.dream.t");
                    subtitle = Text("un.dream.s");
                    target = ProtoCoords.ToUnity(_db.world.dreamHouse.cardTarget);
                    break;
            }
            GameEvents.RaiseUnlockCardShown(icon, title, subtitle);
            if (target == null) return;
            _guide = target.Value;
            _guide.y = GuideHeight;
            _guideUntil = Time.time + GuideSeconds;
            _hasGuide = true;
        }

        /// <summary>Guide arrow point of the last card (prototype <c>guide</c>); the tutorial arrow takes precedence.</summary>
        public bool TryGetGuide(out Vector3 target)
        {
            target = _guide;
            if (!_hasGuide) return false;
            Vector3 p = player.position;
            float dx = p.x - _guide.x, dz = p.z - _guide.z;
            if (Time.time < _guideUntil && dx * dx + dz * dz > GuideReach * GuideReach) return true;
            _hasGuide = false;
            return false;
        }

        string Text(string key) => LocalizationSettings.StringDatabase.GetLocalizedString(Table, key);

        string Text(string key, string arg, object value)
        {
            _args.Clear();
            _args[arg] = value;
            return LocalizationSettings.StringDatabase.GetLocalizedString(Table, key, new object[] { _args });
        }
    }
}
