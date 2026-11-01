using FF.Data;
using FF.Editor.Art;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.World
{
    /// <summary>
    /// Creates the BuildingKit asset (meshes + palette for runtime building growth), makes sure every growth colour and
    /// every product wall / roof colour has a palette material, and gives all lit colours their ghost twins.
    /// </summary>
    public static class BuildingKitBuilder
    {
        public const string KitPath = DataImporter.DataRoot + "/BuildingKit.asset";

        public static BuildingKit Build(GameDatabase db)
        {
            var kit = DataImporter.GetOrCreate<BuildingKit>(KitPath);
            kit.palette = MaterialPaletteEditor.Palette;
            kit.cube = LowPolyMeshFactory.Cube;
            kit.fanCylinder = LowPolyMeshFactory.Cylinder(0.48f, 0.48f, 10);
            kit.tankCylinder = LowPolyMeshFactory.Cylinder(0.42f, 0.42f, 12);
            kit.tankLidCylinder = LowPolyMeshFactory.Cylinder(0.46f, 0.46f, 12);
            kit.icosahedron = LowPolyMeshFactory.Icosahedron();

            foreach (Color32 c in kit.trims) MaterialPaletteEditor.Get(c);
            foreach (Color32 c in new[] { kit.litWindow, kit.darkWindow, kit.chimney, kit.chimneyCap, kit.fanHousing, kit.fanBlade,
                         kit.tank, kit.tankLid, kit.flagPole, kit.flag })
                MaterialPaletteEditor.Get(c);
            foreach (ProductDef p in db.products)
            {
                MaterialPaletteEditor.Get(p.wallColor);
                MaterialPaletteEditor.Get(p.roofColor);
            }
            MaterialPaletteEditor.EnsureGhosts();

            EditorUtility.SetDirty(kit);
            db.buildingKit = kit;
            EditorUtility.SetDirty(db);
            AssetDatabase.SaveAssets();
            return kit;
        }
    }
}
