using FF.Core;
using TMPro;
using UnityEngine;

namespace FF.UI.HUD
{
    /// <summary>Money pill (prototype <c>#moneyBox</c>): balance in <c>fmt</c> form, a short bump on gains.</summary>
    public sealed class MoneyView : MonoBehaviour
    {
        const float BumpScale = 1.08f;
        const float BumpSeconds = 0.11f;

        [SerializeField] TMP_Text amount;
        [SerializeField] RectTransform bumpTarget;

        IProgressView _progress;
        long _key = -1;
        float _bump;

        void Start()
        {
            _progress = Services.Get<IProgressView>();
            Refresh();
        }

        void OnEnable() => GameEvents.MoneyChanged += OnMoneyChanged;

        void OnDisable() => GameEvents.MoneyChanged -= OnMoneyChanged;

        void OnMoneyChanged(long money, bool bump)
        {
            if (bump) _bump = BumpSeconds;
        }

        void LateUpdate()
        {
            Refresh();
            if (_bump <= 0f) return;
            _bump -= Time.unscaledDeltaTime;
            bumpTarget.localScale = Vector3.one * (_bump > 0f ? BumpScale : 1f);
        }

        void Refresh()
        {
            long money = _progress.Money;
            long key = NumberFormat.CompactChangeKey(money);
            if (key == _key) return;
            _key = key;
            amount.SetText(NumberFormat.Compact(money));
        }
    }
}
