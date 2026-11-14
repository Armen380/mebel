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

        /// <summary>The Plumbing factory is owned: opens the mines yard, the materials shop and the section staff.</summary>
        public bool OwnsPlumbing
        {
            get => OwnedProducts.Contains(PlumbingId);
            set
            {
                if (value) OwnedProducts.Add(PlumbingId);
                else OwnedProducts.Remove(PlumbingId);
            }
        }
        /// <summary>Main-shop registers in use: 1 + min(register pad level, shop level).</summary>
        public int MainRegisters = 1;
        /// <summary>Second materials-shop register bought (pad reg_annex).</summary>
        public bool AnnexSecondRegister;
        /// <summary>Dream House stages built, 0 … 4 (leading house_* pads with level ≥ 1, see WorldStateSync).</summary>
        public int HouseStage;
        public readonly HashSet<string> OwnedProducts = new HashSet<string>();

        public bool MinesOpen => OwnsPlumbing;

        public const string Sawmill1Id = "saw";
        public const string Sawmill2Id = "saw2";
        /// <summary>Product id of the Plumbing factory (prototype <c>S.owned.sink</c>).</summary>
        public const string PlumbingId = "sink";
        /// <summary>Dream House stage pads in build order (M10).</summary>
        public static readonly string[] HouseStagePads = HomeDef.StagePads;

        /// <summary>Is a machine (sawmill id or product id) owned and working?</summary>
        public bool Owns(string machineId) =>
            machineId == Sawmill1Id || (machineId == Sawmill2Id ? OwnsSawmill2 : OwnedProducts.Contains(machineId));

        public static WorldStateSnapshot NewGame(IReadOnlyList<ProductDef> products)
        {
            var s = new WorldStateSnapshot();
            foreach (ProductDef p in products)
                if (p.OwnedAtStart) s.OwnedProducts.Add(p.id);
            return s;
        }
    }
}
