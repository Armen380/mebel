using UnityEngine;

namespace FF.Data
{
    /// <summary>
    /// Meshes and colours that building growth (prototype <c>setBuildingLevel</c>) builds from at runtime.
    /// The materials come from the <see cref="MaterialPalette"/>, which also holds their faded twins.
    /// </summary>
    [CreateAssetMenu(menuName = "FF/Building Kit", fileName = "BuildingKit")]
    public sealed class BuildingKit : ScriptableObject
    {
        public MaterialPalette palette;
        public Mesh cube;
        [Tooltip("CylinderGeometry(.48, .48, 1, 10) — roof fan housing.")]
        public Mesh fanCylinder;
        [Tooltip("CylinderGeometry(.42, .42, 1, 12) — water tank.")]
        public Mesh tankCylinder;
        [Tooltip("CylinderGeometry(.46, .46, 1, 12) — water tank lid.")]
        public Mesh tankLidCylinder;
        [Tooltip("Icosahedron r = 1 — smoke puffs.")]
        public Mesh icosahedron;

        [Header("Colours (prototype setBuildingLevel)")]
        public Color32[] trims =
        {
            new Color32(0x6d, 0x43, 0x25, 0xff), new Color32(0xa2, 0x3b, 0x2b, 0xff),
            new Color32(0x3d, 0x6f, 0x8a, 0xff), new Color32(0xd9, 0xa5, 0x20, 0xff),
        };
        public Color32 litWindow = new Color32(0xff, 0xe3, 0x9a, 0xff);
        public Color32 darkWindow = new Color32(0xbf, 0xe3, 0xf0, 0xff);
        public Color32 chimney = new Color32(0x8a, 0x4b, 0x3a, 0xff);
        public Color32 chimneyCap = new Color32(0x3b, 0x2a, 0x1e, 0xff);
        public Color32 fanHousing = new Color32(0x8a, 0x94, 0x9c, 0xff);
        public Color32 fanBlade = new Color32(0x55, 0x60, 0x6a, 0xff);
        public Color32 tank = new Color32(0xc9, 0xd1, 0xd8, 0xff);
        public Color32 tankLid = new Color32(0x8a, 0x94, 0x9c, 0xff);
        public Color32 flagPole = new Color32(0x6d, 0x43, 0x25, 0xff);
        public Color32 flag = new Color32(0xf3, 0xb3, 0x3d, 0xff);
    }
}
