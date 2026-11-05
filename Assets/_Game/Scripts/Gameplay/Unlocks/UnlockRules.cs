using System;
using System.Collections.Generic;
using FF.Data;

namespace FF.Gameplay.Unlocks
{
    public enum UnlockKind
    {
        Factory,
        Register,
        Sawmill2,
        DreamPlot,
        Staff,
        /// <summary>A product that opened together with another one (prototype <c>un.with.s</c>).</summary>
        FactoryWith,
        Mines,
        MaterialsShop,
        /// <summary>A skin unlocked by total earnings (prototype <c>skin_gold</c>).</summary>
        Skin,
    }

    /// <summary>One "NEW" card candidate; <see cref="Id"/> is what <c>S.seen</c> remembers.</summary>
    public readonly struct UnlockCard
    {
        public readonly string Id;
        public readonly UnlockKind Kind;
        /// <summary>Product id for factory cards, upgrade id for staff cards, skin id for skin cards.</summary>
        public readonly string ProductId;

        public UnlockCard(string id, UnlockKind kind, string productId = null)
        {
            Id = id;
            Kind = kind;
            ProductId = productId;
        }
    }

    /// <summary>
    /// Prototype <c>checkUnlocks</c> (in its order): a factory the player can now buy or one that opened with another,
    /// staff that the shop level (or plumbing) opens, a new register slot, Sawmill 2, the mines and the materials shop with
    /// plumbing, the dream plot after the tutorial, skins unlocked by total earnings.
    /// </summary>
    public static class UnlockRules
    {
        public const int MaxRegisterPads = 5;

        public static string SkinCardId(string skinId) => "skin_" + skinId;

        /// <param name="hasBuyPad">Whether the factory's buy pad exists in the scene.</param>
        public static void Collect(IReadOnlyList<ProductDef> products, IReadOnlyList<UpgradeDef> upgrades, Func<string, bool> owns,
            Func<string, bool> hasBuyPad, int playerLevel, int registerLevel, int shopLevel, bool ownsPlumbing, bool tutorialDone,
            List<UnlockCard> into, IReadOnlyList<SkinDef> skins = null, long totalEarned = 0)
        {
            into.Clear();
            foreach (ProductDef p in products)
            {
                if (p.factoryCost > 0 && playerLevel >= p.unlockLevel && !owns(p.id) && hasBuyPad(p.id))
                    into.Add(new UnlockCard("fac_" + p.id, UnlockKind.Factory, p.id));
                if (p.unlocksWith != null && owns(p.id))
                    into.Add(new UnlockCard("fac_" + p.id, UnlockKind.FactoryWith, p.id));
            }
            foreach (UpgradeDef u in upgrades)
                if ((u.requiresShopLevel > 0 && shopLevel >= u.requiresShopLevel) || (u.requiresPlumbing && ownsPlumbing))
                    into.Add(new UnlockCard("staff_" + u.id, UnlockKind.Staff, u.id));
            if (registerLevel < shopLevel && registerLevel < MaxRegisterPads)
                into.Add(new UnlockCard("reg_" + shopLevel, UnlockKind.Register));
            if (tutorialDone && !owns(World.WorldStateSnapshot.Sawmill2Id))
                into.Add(new UnlockCard("saw2", UnlockKind.Sawmill2));
            if (ownsPlumbing)
            {
                into.Add(new UnlockCard("mines", UnlockKind.Mines));
                into.Add(new UnlockCard("matshop", UnlockKind.MaterialsShop));
            }
            if (tutorialDone)
                into.Add(new UnlockCard("dream", UnlockKind.DreamPlot));
            if (skins == null) return;
            foreach (SkinDef s in skins)
                if (s.unlockTotalEarned > 0 && totalEarned >= s.unlockTotalEarned)
                    into.Add(new UnlockCard(SkinCardId(s.id), UnlockKind.Skin, s.id));
        }
    }
}
