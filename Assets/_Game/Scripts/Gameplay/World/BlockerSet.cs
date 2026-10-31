using System.Collections.Generic;
using FF.Core;
using FF.Data;

namespace FF.Gameplay.World
{
    /// <summary>Builds the AABB blocker list of the prototype's <c>refreshBlocks()</c> in Unity space, in the same order.</summary>
    public static class BlockerSet
    {
        public static void Build(WorldLayout layout, EconomyConfig economy, IReadOnlyList<ProductDef> products,
                                 WorldStateSnapshot state, List<Aabb2D> result)
        {
            result.Clear();
            WorldLayout.BlockerSettings b = layout.blockers;
            float wallX = economy.ShopWallX(state.ShopLevel);
            float t = b.shopWallHalfThickness;

            Add(result, b.sawmill1);
            if (state.OwnsSawmill2) Add(result, b.sawmill2);
            Add(result, b.shopLeftWall);
            Add(result, new ProtoRect(wallX - t, wallX + t, b.shopWallZ.min, b.shopWallZ.max));
            Add(result, b.shopFrontLeftWall);
            Add(result, new ProtoRect(b.shopFrontRightMinX, wallX + t, b.shopFrontWallZ.min, b.shopFrontWallZ.max));
            foreach (ProtoRect r in b.dreamPlotFence) Add(result, r);
            if (state.OwnsPlumbing)
                foreach (ProtoRect r in b.materialsShopWalls) Add(result, r);

            foreach (ProductDef p in products)
                if (state.OwnedProducts.Contains(p.id))
                {
                    ProtoRange z = b.FactoryZ(p.factoryRow);
                    Add(result, new ProtoRect(p.factoryX - b.factoryHalfX, p.factoryX + b.factoryHalfX, z.min, z.max));
                }

            float stallZ = layout.mainShop.stallCenterZ;
            float[] mainX = layout.mainShop.registersX;
            for (int i = 0; i < mainX.Length; i++)
                if (i < state.MainRegisters) AddRegister(result, b, mainX[i], stallZ);
            float[] annexX = layout.materialsShop.registersX;
            if (state.OwnsPlumbing && annexX.Length > 0) AddRegister(result, b, annexX[0], stallZ);
            if (state.OwnsPlumbing && state.AnnexSecondRegister && annexX.Length > 1) AddRegister(result, b, annexX[1], stallZ);
        }

        static void AddRegister(List<Aabb2D> result, WorldLayout.BlockerSettings b, float x, float z) =>
            Add(result, new ProtoRect(x - b.registerHalfSize.x, x + b.registerHalfSize.x, z - b.registerHalfSize.y, z + b.registerHalfSize.y));

        static void Add(List<Aabb2D> result, ProtoRect r) => result.Add(ProtoCoords.ToUnityRect(r.x1, r.x2, r.z1, r.z2));
    }
}
