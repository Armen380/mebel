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
    }

    /// <summary>One "NEW" card candidate; <see cref="Id"/> is what <c>S.seen</c> remembers.</summary>
    public readonly struct UnlockCard
    {
        public readonly string Id;
        public readonly UnlockKind Kind;
        /// <summary>Product id for factory cards.</summary>
        public readonly string ProductId;

        public UnlockCard(string id, UnlockKind kind, string productId = null)
        {
            Id = id;
            Kind = kind;
            ProductId = productId;
        }
    }

    /// <summary>
    /// Prototype <c>checkUnlocks</c> for the features that exist so far: a factory the player can now buy, a new register
    /// slot, Sawmill 2 and the dream plot after the tutorial. Staff, mines, materials shop and skins join in M6 / M8 / M9.
    /// </summary>
    public static class UnlockRules
    {
        public const int MaxRegisterPads = 5;

        /// <param name="hasBuyPad">Whether the factory's buy pad exists in the game yet (sink's comes in M8).</param>
        public static void Collect(IReadOnlyList<ProductDef> products, Func<string, bool> owns, Func<string, bool> hasBuyPad,
            int playerLevel, int registerLevel, int shopLevel, bool tutorialDone, List<UnlockCard> into)
        {
            into.Clear();
            foreach (ProductDef p in products)
                if (p.factoryCost > 0 && playerLevel >= p.unlockLevel && !owns(p.id) && hasBuyPad(p.id))
                    into.Add(new UnlockCard("fac_" + p.id, UnlockKind.Factory, p.id));
            if (registerLevel < shopLevel && registerLevel < MaxRegisterPads)
                into.Add(new UnlockCard("reg_" + shopLevel, UnlockKind.Register));
            if (tutorialDone && !owns(World.WorldStateSnapshot.Sawmill2Id))
                into.Add(new UnlockCard("saw2", UnlockKind.Sawmill2));
            if (tutorialDone)
                into.Add(new UnlockCard("dream", UnlockKind.DreamPlot));
        }
    }
}
