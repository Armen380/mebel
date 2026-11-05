using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace FF.UI.HUD
{
    /// <summary>
    /// Rewarded-ad offers in the HUD (bottom-left, only while an ad is ready): "▶ ×2 +$4.8K" for a few seconds after a
    /// truck pays (the payout once more), and "▶ +$X" instant cash — two minutes of current income (at least $500), at most
    /// every few minutes. Nothing is shown while no ad is available, so the game never waits on ads.
    /// </summary>
    public sealed class RewardOffersView : MonoBehaviour
    {
        [SerializeField] AdsConfig config;
        [SerializeField] GameObject truckOffer;
        [SerializeField] Button truckButton;
        [SerializeField] TMP_Text truckLabel;
        [SerializeField] GameObject cashOffer;
        [SerializeField] Button cashButton;
        [SerializeField] TMP_Text cashLabel;

        readonly IncomeMeter _income = new IncomeMeter();
        IRewardedAds _ads;
        IWallet _wallet;
        IProgressView _progress;
        long _offerPay, _shownPay = -1, _cashAmount, _shownCash = -1;
        float _offerUntil = -1f, _nextCash;

        /// <summary>Editor tools only.</summary>
        public void Setup(AdsConfig adsConfig, GameObject truck, Button truckTap, TMP_Text truckText, GameObject cash, Button cashTap, TMP_Text cashText)
        {
            config = adsConfig;
            truckOffer = truck;
            truckButton = truckTap;
            truckLabel = truckText;
            cashOffer = cash;
            cashButton = cashTap;
            cashLabel = cashText;
        }

        void Start()
        {
            Services.TryGet(out _ads);
            _wallet = Services.Get<IWallet>();
            _progress = Services.Get<IProgressView>();
            _nextCash = config.instantCashCooldown * 0.5f; // first offer a little after starting
            truckButton.onClick.AddListener(OnTruck);
            cashButton.onClick.AddListener(OnCash);
            truckOffer.SetActive(false);
            cashOffer.SetActive(false);
        }

        void OnEnable() => GameEvents.TruckDelivered += OnTruckDelivered;

        void OnDisable() => GameEvents.TruckDelivered -= OnTruckDelivered;

        void OnTruckDelivered(long payout)
        {
            _offerPay = payout;
            _offerUntil = Time.time + config.doublePayoutWindow;
        }

        void Update()
        {
            float now = Time.time;
            _income.Sample(now, _progress.TotalEarned);
            bool ready = _ads != null && _ads.IsReady;

            bool truck = ready && now < _offerUntil && _offerPay > 0;
            if (truckOffer.activeSelf != truck) truckOffer.SetActive(truck);
            if (truck && _offerPay != _shownPay)
            {
                _shownPay = _offerPay;
                truckLabel.SetText("×2  +" + NumberFormat.Money(_offerPay));
            }

            bool cash = ready && now >= _nextCash;
            if (cashOffer.activeSelf != cash) cashOffer.SetActive(cash);
            if (!cash) return;
            _cashAmount = _income.InstantCash();
            if (_cashAmount == _shownCash) return;
            _shownCash = _cashAmount;
            cashLabel.SetText("+" + NumberFormat.Money(_cashAmount));
        }

        void OnTruck()
        {
            long pay = _offerPay;
            _offerUntil = -1f;
            GameEvents.RaiseSound(SoundCue.Click);
            _ads.Show(AdPlacements.DoublePayout, () => _wallet.AddMoney(pay, true));
        }

        void OnCash()
        {
            long amount = _cashAmount;
            _nextCash = Time.time + config.instantCashCooldown;
            GameEvents.RaiseSound(SoundCue.Click);
            _ads.Show(AdPlacements.InstantCash, () => _wallet.AddMoney(amount, true));
        }
    }
}
