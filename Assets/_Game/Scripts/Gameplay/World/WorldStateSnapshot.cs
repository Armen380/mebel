using System.Collections.Generic;
using FF.Data;

namespace FF.Gameplay.World
{
    /// <summary>
    /// The parts of the game state that change the walkable world (blockers, gates).
    /// M1 uses <see cref="NewGame"/>; later milestones build it from the save.
    /// </summary>
    public sealed class WorldStateSnapshot
    {
        public int ShopLevel;
        public bool OwnsSawmill2;
        public bool OwnsPlumbing;
        /// <summary>Main-shop registers in use: 1 + min(register pad level, shop level).</summary>
        public int MainRegisters = 1;
        /// <summary>Second materials-shop register bought (pad reg_annex).</summary>
        public bool AnnexSecondRegister;
        public readonly HashSet<string> OwnedProducts = new HashSet<string>();

        public bool MinesOpen => OwnsPlumbing;

        public static WorldStateSnapshot NewGame(IReadOnlyList<ProductDef> products)
        {
            var s = new WorldStateSnapshot();
            foreach (ProductDef p in products)
                if (p.OwnedAtStart) s.OwnedProducts.Add(p.id);
            return s;
        }
    }
}
