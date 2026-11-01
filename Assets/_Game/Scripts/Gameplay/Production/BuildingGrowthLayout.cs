using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Production
{
    public enum PartShape
    {
        Box,
        FanHousing,
        Tank,
        TankLid,
        /// <summary>Empty transform holding other parts (the spinning fan blades).</summary>
        Group,
    }

    public enum PartRole
    {
        None,
        FanBlades,
        Flag,
    }

    /// <summary>One piece of a building's growth decoration, in prototype-local units and axes (z toward the road).</summary>
    public struct BuildingPart
    {
        public PartShape Shape;
        public Vector3 Size;
        public Vector3 Position;
        /// <summary>Prototype rotation around X / Y in radians.</summary>
        public float RotationX, RotationY;
        public Color32 Color;
        public PartRole Role;
        /// <summary>Index of the parent part in the same list, −1 for the building's deco root.</summary>
        public int Parent;
    }

    /// <summary>
    /// Prototype <c>setBuildingLevel(b, speedLv, qtyLv)</c> as data: qty adds floors of 1.25 m with windows, speed adds
    /// chimneys (s ≥ 1, second at s ≥ 5), a roof fan (s ≥ 3), a tank (s ≥ 7) and the gold flag (s = 8 and q = 3);
    /// the trim colour steps up every 3 combined levels and windows light up from tier 2.
    /// </summary>
    public static class BuildingGrowthLayout
    {
        public const float FloorHeight = 1.25f;
        const float BaseHeight = 2.6f;

        /// <param name="chimneyTops">Receives the smoke spawn points (prototype <c>b.chimneys</c>).</param>
        /// <returns>The building top used for the Lv tag and the confetti (prototype <c>b.top</c>).</returns>
        public static float Build(int speed, int qty, Color32 wall, Color32 roof, BuildingKit kit,
            List<BuildingPart> parts, List<Vector3> chimneyTops)
        {
            parts.Clear();
            chimneyTops.Clear();
            int tier = Tier(speed, qty);
            Color32 trim = kit.trims[tier];
            Color32 window = tier >= 2 ? kit.litWindow : kit.darkWindow;

            Box(parts, 5.5f, 0.16f, 4.1f, trim, 0, BaseHeight, 0);
            if (tier >= 1)
                foreach (float wx in new[] { -1.95f, 1.95f })
                    Box(parts, 0.6f, 0.55f, 0.06f, window, wx, 1.75f, 2.02f);

            float y = BaseHeight;
            for (int i = 0; i < qty; i++)
            {
                float mid = y + FloorHeight / 2f;
                Box(parts, 4.9f, FloorHeight, 3.5f, wall, 0, mid, 0);
                foreach (float wx in new[] { -1.65f, -0.55f, 0.55f, 1.65f })
                {
                    Box(parts, 0.6f, 0.55f, 0.06f, window, wx, mid + 0.05f, 1.77f);
                    Box(parts, 0.7f, 0.08f, 0.1f, trim, wx, mid - 0.27f, 1.79f);
                }
                Box(parts, 5f, 0.12f, 3.6f, trim, 0, y + FloorHeight, 0);
                y += FloorHeight;
            }

            float rw = qty > 0 ? 5.4f : 5.9f, rd = qty > 0 ? 2.2f : 2.5f, rz = qty > 0 ? 0.92f : 1.05f;
            Box(parts, rw, 0.18f, rd, roof, 0, y + 0.45f, -rz, rotX: 0.55f);
            Box(parts, rw, 0.18f, rd, roof, 0, y + 0.45f, rz, rotX: -0.55f);

            int chimneys = ChimneyCount(speed);
            for (int i = 0; i < chimneys; i++)
            {
                float x = -1.9f + i * 0.8f;
                Box(parts, 0.45f, 1.3f, 0.45f, kit.chimney, x, y + 0.95f, -0.75f);
                Box(parts, 0.56f, 0.12f, 0.56f, kit.chimneyCap, x, y + 1.62f, -0.75f);
                chimneyTops.Add(new Vector3(x, y + 1.75f, -0.75f));
            }

            if (speed >= 3)
            {
                int fan = Add(parts, PartShape.Group, Vector3.one, new Vector3(1.75f, y + 1.05f, -0.6f), default, -1);
                Add(parts, PartShape.FanHousing, new Vector3(1f, 0.32f, 1f), Vector3.zero, kit.fanHousing, fan);
                int blades = Add(parts, PartShape.Group, Vector3.one, new Vector3(0, 0.2f, 0), default, fan, PartRole.FanBlades);
                for (int k = 0; k < 4; k++)
                    Add(parts, PartShape.Box, new Vector3(0.8f, 0.04f, 0.16f), Vector3.zero, kit.fanBlade, blades, rotY: k * Mathf.PI / 4f);
            }

            if (speed >= 7)
            {
                Add(parts, PartShape.Tank, new Vector3(1f, 1.3f, 1f), new Vector3(0.15f, y + 1.1f, -0.9f), kit.tank, -1);
                Add(parts, PartShape.TankLid, new Vector3(1f, 0.08f, 1f), new Vector3(0.15f, y + 1.78f, -0.9f), kit.tankLid, -1);
            }

            if (HasFlag(speed, qty))
            {
                Box(parts, 0.08f, 2f, 0.08f, kit.flagPole, 2.35f, y + 1.5f, 1f);
                Add(parts, PartShape.Box, new Vector3(0.9f, 0.55f, 0.04f), new Vector3(2.8f, y + 2.2f, 1f), kit.flag, -1, PartRole.Flag);
            }

            return y + 1.5f;
        }

        public static int Tier(int speed, int qty) => Mathf.Min(3, (speed + qty) / 3);

        public static int ChimneyCount(int speed) => speed >= 5 ? 2 : speed >= 1 ? 1 : 0;

        public static bool HasFlag(int speed, int qty) => speed >= 8 && qty >= 3;

        static void Box(List<BuildingPart> parts, float w, float h, float d, Color32 color, float x, float y, float z, float rotX = 0f) =>
            Add(parts, PartShape.Box, new Vector3(w, h, d), new Vector3(x, y, z), color, -1, PartRole.None, rotX);

        static int Add(List<BuildingPart> parts, PartShape shape, Vector3 size, Vector3 pos, Color32 color, int parent,
            PartRole role = PartRole.None, float rotX = 0f, float rotY = 0f)
        {
            parts.Add(new BuildingPart
            {
                Shape = shape, Size = size, Position = pos, Color = color, Parent = parent, Role = role,
                RotationX = rotX, RotationY = rotY,
            });
            return parts.Count - 1;
        }
    }
}
