using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.HUD
{
    /// <summary>
    /// Rewarded-ad offer in the middle of the screen (user decision 2026-11-08, replaces the M9 corner buttons): a card with
    /// a title, the amount, a "Watch ad" button, a ✕ and a bar that runs out. At most one offer per cooldown (5 min, see
    /// <see cref="AdOfferRules"/>): "×2 payout" when a truck has just paid, otherwise "bonus" — two minutes of income
    /// (≥ $500). Closing it, ignoring it or watching starts the cooldown. The game keeps running; only the card takes taps.
    /// </summary>
    public sealed class AdOfferPopup : MonoBehaviour
    {
        const float PopSeconds = 0.18f;

        [SerializeField] AdsConfig config;
        [SerializeField] CanvasGroup card;
        [SerializeField] GameObject doubleTitle;
        [SerializeField] GameObject cashTitle;
        [SerializeField] TMP_Text amountLabel;
        [SerializeField] Button watchButton;
        [SerializeField] Button closeButton;
        [SerializeField] Image timerFill;

        readonly IncomeMeter _income = new IncomeMeter();
        IRewardedAds _ads;
        IWallet _wallet;
        IProgressView _progress;
        GameMode _mode;
        AdOfferRules.Offer _offer;
        long _payout, _amount, _shownAmount = -1;
        float _doubleUntil = -1f, _nextOfferAt, _offerUntil, _offerLength, _shownAt;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig, CanvasGroup cardGroup, GameObject doubleText, GameObject cashText, TMP_Text amount,
            Button watch, Button close, Image timer)
        {
            config = adsConfig;
            card = cardGroup;
            doubleTitle = doubleText;
            cashTitle = cashText;
            amountLabel = amount;
            watchButton = watch;
            closeButton = close;
            timerFill = timer;
        }

        void Start()
        {
            Services.TryGet(out _ads);
            _wallet = Services.Get<IWallet>();
            _progress = Services.Get<IProgressView>();
            _mode = Services.Get<GameMode>();
            _nextOfferAt = Time.time + config.instantCashCooldown * 0.5f; // the first offer a little after starting
            watchButton.onClick.AddListener(OnWatch);
            closeButton.onClick.AddListener(OnClose);
            card.gameObject.SetActive(false);
        }

        void OnEnable() => GameEvents.TruckDelivered += OnTruckDelivered;

        void OnDisable() => GameEvents.TruckDelivered -= OnTruckDelivered;

        void OnTruckDelivered(long payout)
        {
            _payout = payout;
            _doubleUntil = Time.time + config.doublePayoutWindow;
        }

        void Update()
        {
            float now = Time.time;
            _income.Sample(now, _progress.TotalEarned);
            bool ready = _ads != null && _ads.IsReady;
            bool blocked = _mode.InMenu || AdClock.Showing;

            if (_offer == AdOfferRules.Offer.None)
            {
                _offer = AdOfferRules.Pick(ready, blocked, now, _nextOfferAt, _doubleUntil);
                if (_offer != AdOfferRules.Offer.None) Open(now);
                return;
            }
            // the menu or another ad hides it for now (no cooldown); a lost ad or the time running out ends it
            if (blocked)
            {
                Hide();
                return;
            }
            if (!ready || now >= _offerUntil)
            {
                End(now);
                return;
            }
            if (_offer == AdOfferRules.Offer.Cash)
            {
                _amount = _income.InstantCash();
                ShowAmount();
            }
            timerFill.fillAmount = Mathf.Clamp01((_offerUntil - now) / _offerLength);
            float pop = Mathf.Clamp01((Time.unscaledTime - _shownAt) / PopSeconds);
            card.transform.localScale = Vector3.one * Mathf.Lerp(0.85f, 1f, 1f - (1f - pop) * (1f - pop));
        }

        void Open(float now)
        {
            bool isDouble = _offer == AdOfferRules.Offer.DoublePayout;
            _offerLength = isDouble ? Mathf.Max(1f, _doubleUntil - now) : config.cashOfferWindow;
            _offerUntil = now + _offerLength;
            _amount = isDouble ? _payout : _income.InstantCash();
            doubleTitle.SetActive(isDouble);
            cashTitle.SetActive(!isDouble);
            _shownAmount = -1;
            ShowAmount();
            timerFill.fillAmount = 1f;
            _shownAt = Time.unscaledTime;
            card.transform.localScale = Vector3.one * 0.85f;
            card.gameObject.SetActive(true);
        }

        void ShowAmount()
        {
            if (_amount == _shownAmount) return;
            _shownAmount = _amount;
            amountLabel.SetText("+" + NumberFormat.Money(_amount));
        }

        /// <summary>Gone for now; the same offer may come back once nothing blocks it.</summary>
        void Hide()
        {
            _offer = AdOfferRules.Offer.None;
            card.gameObject.SetActive(false);
        }

        /// <summary>Watched, closed or ignored: the next offer waits a full cooldown.</summary>
        void End(float now)
        {
            if (_offer == AdOfferRules.Offer.DoublePayout) _doubleUntil = -1f;
            _nextOfferAt = now + config.instantCashCooldown;
            Hide();
        }

        void OnWatch()
        {
            if (_offer == AdOfferRules.Offer.None) return;
            long amount = _amount;
            string placement = _offer == AdOfferRules.Offer.DoublePayout ? AdPlacements.DoublePayout : AdPlacements.InstantCash;
            GameEvents.RaiseSound(SoundCue.Click);
            End(Time.time);
            _ads.Show(placement, () => _wallet.AddMoney(amount, true));
        }

        void OnClose()
        {
            GameEvents.RaiseSound(SoundCue.Click);
            End(Time.time);
        }
    }
}
