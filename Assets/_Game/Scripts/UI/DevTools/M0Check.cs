using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;

namespace FF.UI.DevTools
{
    /// <summary>Temporary Milestone 0 check: shows Armenian + Cyrillic text and logs imported data. Removed in M1.</summary>
    public sealed class M0Check : MonoBehaviour
    {
        [SerializeField] TMP_Text label;

        void Start()
        {
            GameDatabase db = Services.Get<GameDatabase>();
            EconomyConfig e = db.economy;
            ProductDef chair = db.Product("chair");
            ProductDef sofa = db.Product("sofa");
            string report =
                $"products {db.products.Count} · chair {NumberFormat.Money(e.SalePrice(chair.basePrice, 0))} · " +
                $"sofa factory {NumberFormat.Money(sofa.factoryCost)} · xp(Lv1) {e.XpNeeded(1)} · " +
                $"saw_speed Lv0 {NumberFormat.Money(e.PadPrice(db.Pad("saw_speed"), 0))}";
            UnityEngine.Debug.Log("[FF] M0 check: " + report);
            if (label != null) label.text = "Կահույքի Գործարան / Мебельная фабрика\n<size=50%>" + report + "</size>";
        }
    }
}
