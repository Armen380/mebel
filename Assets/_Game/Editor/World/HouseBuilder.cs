using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.Gameplay.Home;
using UnityEngine;

namespace FF.Editor.World
{
    /// <summary>
    /// Dream House (M10) world objects under World/DreamHouse, in the Armenian tuff style: the placeholder stakes and
    /// billboard (until the foundation / walls), the four construction stages, and the Home Store building. Each part is a
    /// <see cref="StageVisual"/> holder with a "Visual" child, so it shows and pops in by house stage. Not static: the
    /// stages pop and the cut-away hides the roof and front wall.
    /// </summary>
    public static class HouseBuilder
    {
        public const string RootName = "DreamHouse";

        // Armenian palette (M10 spec)
        public const int Tuff = 0xd9967f, TuffTrim = 0xb9735f, TuffDark = 0x8a5444, Roof = 0xc4643f, RoofEaves = 0xa9532f;
        public const int Walnut = 0x7a4a2b, Pomegranate = 0xb3263a, Vine = 0x5f9a3a, Glass = 0xbfe3f0, Honey = 0xf3b33d;
        const int Danger = 0xe2574c, Stake = 0xd9a066, Wood = 0x9a6a3e, BillboardWalnut = 0x523a27, Cream = 0xf6ecd9;
        const int FloorLiving = 0xc79a6b, FloorKitchen = 0xe8dcc8, FloorBedroom = 0xb98a5e, FloorBath = 0xa9cfd8, Slab = 0xc9b8a6;

        public sealed class Result
        {
            public Transform Root;
            /// <summary>Roof and front-wall parts the cut-away hides while the player is inside.</summary>
            public readonly List<GameObject> Cutaway = new List<GameObject>();
            public Transform Counter;
            public Transform Slots;
        }

        const float SlabTop = 0.3f, WallH = 3f, InnerWallH = 1.4f;

        public static Result Build(GameDatabase db, Transform world)
        {
            WorldLayout.DreamHouseSettings d = db.world.dreamHouse;
            Transform old = world.Find(RootName);
            if (old != null) Object.DestroyImmediate(old.gameObject);

            var b = new Blockout(mirrorZ: true);
            var r = new Result { Root = b.Group(RootName, world) };

            BuildPlaceholder(b, r.Root, d);
            BuildFoundation(b, Stage(b, r.Root, "Stage1_Foundation", 1, 0), d);
            BuildWalls(b, Stage(b, r.Root, "Stage2_Walls", 2, 0), Stage(b, r.Root, "Stage2_FrontWall", 2, 0), db.world, r);
            BuildRoof(b, Stage(b, r.Root, "Stage3_Roof", 3, 0), d, r);
            BuildWindows(b, Stage(b, r.Root, "Stage4_Windows", 4, 0), Stage(b, r.Root, "Stage4_FrontWindows", 4, 0), d, r);
            r.Counter = BuildStore(b, Stage(b, r.Root, "HomeStore", 1, 0), d);
            r.Slots = b.Group("Slots", r.Root);
            return r;
        }

        /// <summary>A StageVisual holder with its "Visual" child (returned).</summary>
        static Transform Stage(Blockout b, Transform root, string name, int from, int until)
        {
            Transform holder = b.Group(name, root);
            Transform visual = b.Group("Visual", holder);
            holder.gameObject.AddComponent<StageVisual>().Setup(from, until, visual.gameObject);
            return visual;
        }

        // ---------- placeholder (stage 0) ----------

        static void BuildPlaceholder(Blockout b, Transform root, WorldLayout.DreamHouseSettings d)
        {
            Transform stakes = Stage(b, root, "Placeholder_Stakes", 0, 1);
            Vector2 fc = d.foundationCenter, fs = d.foundationSize;
            float sx = fs.x / 2 - 0.1f, sz = fs.y / 2 - 0.1f;
            foreach ((float x, float z) in new[] { (fc.x - sx, fc.y + sz), (fc.x + sx, fc.y + sz), (fc.x - sx, fc.y - sz), (fc.x + sx, fc.y - sz) })
                b.Box(stakes, 0.12f, 0.9f, 0.12f, Stake, x, 0.45f, z, "Stake");
            b.Box(stakes, fs.x - 0.2f, 0.03f, 0.03f, Danger, fc.x, 0.75f, fc.y + sz, "String");
            b.Box(stakes, fs.x - 0.2f, 0.03f, 0.03f, Danger, fc.x, 0.75f, fc.y - sz, "String");
            b.Box(stakes, 0.03f, 0.03f, fs.y - 0.2f, Danger, fc.x - sx, 0.75f, fc.y, "String");
            b.Box(stakes, 0.03f, 0.03f, fs.y - 0.2f, Danger, fc.x + sx, 0.75f, fc.y, "String");

            BuildBillboard(b, Stage(b, root, "Placeholder_Billboard", 0, 2), d.billboard);
        }

        /// <summary>The prototype's painted billboard (moved here from LayoutBuilder in M10): hidden once the walls stand.</summary>
        static void BuildBillboard(Blockout b, Transform p, Vector2 at)
        {
            b.Box(p, 0.22f, 3.6f, 0.22f, Wood, at.x - 3.4f, 1.8f, at.y, "Post");
            b.Box(p, 0.22f, 3.6f, 0.22f, Wood, at.x + 3.4f, 1.8f, at.y, "Post");
            b.Box(p, 7.2f, 4.4f, 0.16f, BillboardWalnut, at.x, 3.4f, at.y - 0.12f, "Frame");
            float fz = at.y + 0.02f;
            b.Box(p, 6.9f, 4.3f, 0.02f, 0xcfe9f4, at.x, 3.4f, fz, "Sky");
            b.Box(p, 6.9f, 1.0f, 0.03f, 0x8cc65a, at.x, 1.75f, fz + 0.01f, "Hill");
            b.Box(p, 2.7f, 1.6f, 0.04f, Tuff, at.x - 0.2f, 2.6f, fz + 0.02f, "House");
            GameObject roof = b.Box(p, 2.2f, 0.3f, 0.05f, Roof, at.x - 0.9f, 3.65f, fz + 0.03f, "RoofL");
            roof.transform.localRotation = Quaternion.Euler(0, 0, 33);
            roof = b.Box(p, 2.2f, 0.3f, 0.05f, Roof, at.x + 0.5f, 3.65f, fz + 0.03f, "RoofR");
            roof.transform.localRotation = Quaternion.Euler(0, 0, -33);
            b.Box(p, 0.5f, 0.8f, 0.05f, Walnut, at.x - 0.2f, 2.2f, fz + 0.03f, "Door");
            b.Sign(p, "dream.title", 4.2f, BillboardWalnut, Honey, at.x - 1.2f, 5.0f, fz + 0.05f);
            Transform ribbon = b.Sign(p, "dream.soon", 2.2f, Danger, 0xffffff, at.x + 2.2f, 2.0f, fz + 0.05f);
            ribbon.localRotation = Quaternion.Euler(0, 0, 10);
        }

        // ---------- stage 1: foundation ----------

        static void BuildFoundation(Blockout b, Transform p, WorldLayout.DreamHouseSettings d)
        {
            Vector2 c = d.foundationCenter, s = d.foundationSize;
            b.Box(p, s.x + 0.4f, SlabTop, s.y + 0.4f, Slab, c.x, SlabTop / 2, c.y, "Slab");
            b.Box(p, s.x + 0.5f, 0.08f, s.y + 0.5f, TuffTrim, c.x, SlabTop - 0.04f, c.y, "SlabEdge");
            float x0 = c.x - s.x / 2, z0 = c.y - s.y / 2, hx = s.x / 4, hz = s.y / 4;
            b.Flat(p, s.x / 2 - 0.1f, s.y / 2 - 0.1f, FloorLiving, x0 + hx, z0 + 3 * hz, SlabTop + 0.012f, "FloorLiving");
            b.Flat(p, s.x / 2 - 0.1f, s.y / 2 - 0.1f, FloorKitchen, x0 + 3 * hx, z0 + 3 * hz, SlabTop + 0.012f, "FloorKitchen");
            b.Flat(p, s.x / 2 - 0.1f, s.y / 2 - 0.1f, FloorBedroom, x0 + hx, z0 + hz, SlabTop + 0.012f, "FloorBedroom");
            b.Flat(p, s.x / 2 - 0.1f, s.y / 2 - 0.1f, FloorBath, x0 + 3 * hx, z0 + hz, SlabTop + 0.012f, "FloorBath");
            Vector2 door = d.houseDoorways[0];
            b.Box(p, 2.2f, 0.2f, 0.6f, TuffTrim, door.x, 0.1f, d.houseFrontZ + 0.55f, "Step");
            b.Flat(p, 2.0f, 2.6f, 0xd8c7a8, door.x, d.houseFrontZ + 2.1f, 0.014f, "Path");
        }

        // ---------- stage 2: walls ----------

        static void BuildWalls(Blockout b, Transform walls, Transform front, WorldLayout w, Result r)
        {
            WorldLayout.DreamHouseSettings d = w.dreamHouse;
            float frontZ = d.houseFrontZ;
            foreach (ProtoRect rect in w.blockers.houseWalls)
            {
                float cx = (rect.x1 + rect.x2) / 2, cz = (rect.z1 + rect.z2) / 2, sx = rect.x2 - rect.x1, sz = rect.z2 - rect.z1;
                bool outer = IsOuter(rect, d);
                bool isFront = Mathf.Abs(cz - frontZ) < 0.2f;
                float h = outer ? WallH : InnerWallH;
                Transform parent = isFront ? front : walls;
                b.Box(parent, sx, h, sz, Tuff, cx, SlabTop + h / 2, cz, outer ? "Wall" : "InnerWall");
                if (outer) b.Box(parent, sx + 0.06f, 0.22f, sz + 0.06f, TuffTrim, cx, SlabTop + h - 0.11f, cz, "Cornice");
                else b.Box(parent, sx + 0.04f, 0.08f, sz + 0.04f, TuffTrim, cx, SlabTop + h, cz, "Cap");
            }

            // front door: lintel over the gap and a tuff arch
            Vector2 door = d.houseDoorways[0];
            b.Box(front, 1.6f, WallH - 2.5f, 0.25f, Tuff, door.x, SlabTop + 2.5f + (WallH - 2.5f) / 2, frontZ, "Lintel");
            b.Mesh(front, LowPolyMeshFactory.Arch(), TuffTrim, door.x, SlabTop + 1.75f, frontZ + 0.02f, new Vector3(0.92f, 0.8f, 0.34f), "DoorArch");
            b.Box(front, 0.16f, 1.75f, 0.34f, TuffTrim, door.x - 0.84f, SlabTop + 0.875f, frontZ + 0.02f, "DoorJamb");
            b.Box(front, 0.16f, 1.75f, 0.34f, TuffTrim, door.x + 0.84f, SlabTop + 0.875f, frontZ + 0.02f, "DoorJamb");

            // arched window openings (dark recesses with a trim arch)
            foreach (float x in FrontWindowsX(d)) Window(b, front, x, frontZ, 0f);
            foreach (float z in SideWindowsZ(d))
            {
                Window(b, walls, d.foundationCenter.x - d.foundationSize.x / 2, z, 90f);
                Window(b, walls, d.foundationCenter.x + d.foundationSize.x / 2, z, 90f);
            }
            r.Cutaway.Add(front.parent.gameObject);
        }

        static bool IsOuter(ProtoRect rect, WorldLayout.DreamHouseSettings d)
        {
            float x0 = d.foundationCenter.x - d.foundationSize.x / 2, x1 = d.foundationCenter.x + d.foundationSize.x / 2;
            float z0 = d.foundationCenter.y - d.foundationSize.y / 2, z1 = d.foundationCenter.y + d.foundationSize.y / 2;
            float cx = (rect.x1 + rect.x2) / 2, cz = (rect.z1 + rect.z2) / 2;
            return Mathf.Abs(cx - x0) < 0.3f || Mathf.Abs(cx - x1) < 0.3f || Mathf.Abs(cz - z0) < 0.3f || Mathf.Abs(cz - z1) < 0.3f;
        }

        static float[] FrontWindowsX(WorldLayout.DreamHouseSettings d) => new[] { d.foundationCenter.x - 1.0f, d.foundationCenter.x + 2.7f };

        static float[] SideWindowsZ(WorldLayout.DreamHouseSettings d) => new[] { d.foundationCenter.y + 2f, d.foundationCenter.y - 2f };

        static void Window(Blockout b, Transform p, float x, float z, float yaw)
        {
            Transform g = b.Group("WindowOpening", p, x, z);
            g.localRotation = Quaternion.Euler(0, yaw, 0);
            b.Box(g, 1.1f, 1.2f, 0.3f, TuffDark, 0, SlabTop + 1.55f, 0, "Recess");
            b.Mesh(g, LowPolyMeshFactory.Arch(), TuffTrim, 0, SlabTop + 2.15f, 0, new Vector3(0.66f, 0.5f, 0.32f), "Arch");
            b.Box(g, 1.4f, 0.12f, 0.36f, TuffTrim, 0, SlabTop + 0.9f, 0, "Sill");
        }

        // ---------- stage 3: roof ----------

        static void BuildRoof(Blockout b, Transform p, WorldLayout.DreamHouseSettings d, Result r)
        {
            Vector2 c = d.foundationCenter, s = d.foundationSize;
            float y = SlabTop + WallH;
            b.Box(p, s.x + 1.4f, 0.2f, s.y + 1.4f, RoofEaves, c.x, y + 0.1f, c.y, "Eaves");
            // hipped roof: a 4-sided frustum turned 45° and stretched to the house
            Transform hip = b.Group("Hip", p, c.x, c.y, y + 0.2f + 0.8f);
            hip.localScale = new Vector3((s.x + 1.2f) / 1.414f, 1f, (s.y + 1.2f) / 1.414f);
            GameObject cone = b.Mesh(hip, LowPolyMeshFactory.Cylinder(0.22f, 1f, 4), Roof, 0, 0, 0, new Vector3(1f, 1.6f, 1f), "Tiles");
            cone.transform.localRotation = Quaternion.Euler(0, 45, 0);
            // tuff chimney
            b.Box(p, 0.6f, 1.4f, 0.6f, Tuff, c.x + 3.2f, y + 1.3f, c.y - 1.2f, "Chimney");
            b.Box(p, 0.75f, 0.15f, 0.75f, TuffTrim, c.x + 3.2f, y + 2.05f, c.y - 1.2f, "ChimneyCap");
            r.Cutaway.Add(p.parent.gameObject);
        }

        // ---------- stage 4: windows and doors ----------

        static void BuildWindows(Blockout b, Transform p, Transform front, WorldLayout.DreamHouseSettings d, Result r)
        {
            float frontZ = d.houseFrontZ;
            // double door, both leaves open outward
            Vector2 door = d.houseDoorways[0];
            foreach (float side in new[] { -1f, 1f })
            {
                b.Box(front, 0.08f, 1.9f, 0.72f, Walnut, door.x + side * 0.76f, SlabTop + 0.95f, frontZ + 0.5f, "DoorLeaf");
                b.Box(front, 0.1f, 0.1f, 0.1f, Honey, door.x + side * 0.7f, SlabTop + 1f, frontZ + 0.8f, "Knob");
            }
            foreach (float x in FrontWindowsX(d)) Frame(b, front, x, frontZ + 0.03f, 0f, true);
            foreach (float z in SideWindowsZ(d))
            {
                Frame(b, p, d.foundationCenter.x - d.foundationSize.x / 2 - 0.03f, z, 90f, false);
                Frame(b, p, d.foundationCenter.x + d.foundationSize.x / 2 + 0.03f, z, 90f, false);
            }
            // lanterns by the door
            b.Box(front, 0.18f, 0.32f, 0.18f, Walnut, door.x - 1.15f, SlabTop + 2.2f, frontZ + 0.2f, "Lantern");
            b.GlowBox(front, 0.12f, 0.2f, 0.12f, 0xffe4a3, door.x - 1.15f, SlabTop + 2.2f, frontZ + 0.3f, "LanternLight");
            b.Box(front, 0.18f, 0.32f, 0.18f, Walnut, door.x + 1.15f, SlabTop + 2.2f, frontZ + 0.2f, "Lantern");
            b.GlowBox(front, 0.12f, 0.2f, 0.12f, 0xffe4a3, door.x + 1.15f, SlabTop + 2.2f, frontZ + 0.3f, "LanternLight");
            r.Cutaway.Add(front.parent.gameObject);
        }

        static void Frame(Blockout b, Transform p, float x, float z, float yaw, bool flowers)
        {
            Transform g = b.Group("Window", p, x, z);
            g.localRotation = Quaternion.Euler(0, yaw, 0);
            b.Box(g, 1.0f, 1.1f, 0.34f, Walnut, 0, SlabTop + 1.55f, 0, "Frame");
            b.Box(g, 0.84f, 0.94f, 0.36f, Glass, 0, SlabTop + 1.55f, 0, "Glass");
            b.Box(g, 0.06f, 0.94f, 0.38f, Walnut, 0, SlabTop + 1.55f, 0, "Mullion");
            b.Box(g, 0.84f, 0.06f, 0.38f, Walnut, 0, SlabTop + 1.6f, 0, "Transom");
            if (!flowers) return;
            b.Box(g, 1.2f, 0.24f, 0.32f, Walnut, 0, SlabTop + 0.8f, 0.3f, "FlowerBox");
            for (int i = -2; i <= 2; i++)
            {
                b.Ico(g, 0.13f, Vine, i * 0.22f, SlabTop + 0.98f, 0.3f, "Leaves");
                b.Ico(g, 0.08f, i % 2 == 0 ? Pomegranate : 0xf2c14e, i * 0.22f, SlabTop + 1.08f, 0.36f, "Flower");
            }
        }

        // ---------- Home Store ----------

        /// <summary>Small pink-tuff shop with an arched front and a walnut counter; returns the counter point.</summary>
        static Transform BuildStore(Blockout b, Transform p, WorldLayout.DreamHouseSettings d)
        {
            ProtoRect s = d.homeStore;
            float cx = (s.x1 + s.x2) / 2, cz = (s.z1 + s.z2) / 2, w = s.x2 - s.x1, depth = s.z2 - s.z1, h = 2.8f;
            float frontZ = s.z2 - 0.15f;
            b.Box(p, w, 0.2f, depth, Slab, cx, 0.1f, cz, "Floor");
            b.Box(p, w, h, 0.3f, Tuff, cx, h / 2, s.z1 + 0.15f, "BackWall");
            b.Box(p, 0.3f, h, depth, Tuff, s.x1 + 0.15f, h / 2, cz, "SideWall");
            b.Box(p, 0.3f, h, depth, Tuff, s.x2 - 0.15f, h / 2, cz, "SideWall");
            b.Box(p, 1.0f, h, 0.3f, Tuff, s.x1 + 0.5f, h / 2, frontZ, "Pier");
            b.Box(p, 1.0f, h, 0.3f, Tuff, s.x2 - 0.5f, h / 2, frontZ, "Pier");
            b.Box(p, w - 2f, h - 2.2f, 0.3f, Tuff, cx, 2.2f + (h - 2.2f) / 2, frontZ, "Lintel");
            b.Mesh(p, LowPolyMeshFactory.Arch(), TuffTrim, cx, 1.5f, frontZ + 0.03f, new Vector3(1.05f, 0.7f, 0.36f), "Arch");
            b.Box(p, w + 0.3f, 0.2f, depth + 0.3f, TuffTrim, cx, h + 0.1f, cz, "Cornice");
            Transform hip = b.Group("Roof", p, cx, cz, h + 0.2f + 0.45f);
            hip.localScale = new Vector3((w + 0.6f) / 1.414f, 1f, (depth + 0.6f) / 1.414f);
            GameObject cone = b.Mesh(hip, LowPolyMeshFactory.Cylinder(0.15f, 1f, 4), Roof, 0, 0, 0, new Vector3(1f, 0.9f, 1f), "Tiles");
            cone.transform.localRotation = Quaternion.Euler(0, 45, 0);
            // awning, counter and wares
            b.Box(p, w - 1.6f, 0.08f, 0.7f, Pomegranate, cx, 2.25f, frontZ + 0.45f, "Awning");
            b.Box(p, 2.0f, 1.0f, 0.5f, Walnut, cx, 0.5f, frontZ - 0.35f, "Counter");
            b.Box(p, 2.1f, 0.08f, 0.6f, 0xa7774f, cx, 1.04f, frontZ - 0.35f, "CounterTop");
            b.Box(p, w - 0.8f, 0.08f, 0.5f, Walnut, cx, 1.4f, s.z1 + 0.5f, "Shelf");
            b.Box(p, w - 0.8f, 0.08f, 0.5f, Walnut, cx, 2.0f, s.z1 + 0.5f, "Shelf");
            int[] wares = { Pomegranate, 0x3d6fb0, Honey, Vine, 0xe8dcc8, 0x8a4fa0 };
            for (int i = 0; i < wares.Length; i++)
            {
                GameObject roll = b.Cyl(p, 0.16f, 0.16f, 0.9f, wares[i], 8, s.x1 + 0.8f + i * 0.5f, 1.65f, s.z1 + 0.5f, "Carpet");
                roll.transform.localRotation = Quaternion.Euler(90, 0, 0);
                b.Box(p, 0.3f, 0.3f, 0.3f, wares[(i + 2) % wares.Length], s.x1 + 0.8f + i * 0.5f, 2.2f, s.z1 + 0.5f, "Box");
            }
            b.Sign(p, "sign.homeStore", 3.2f, Walnut, Honey, cx, h + 0.7f, s.z2 + 0.05f);
            Vector2 counter = d.homeStoreCounter;
            b.Flat(p, 1.6f, 1.1f, Pomegranate, counter.x, counter.y, 0.018f, "Rug");
            b.Flat(p, 1.3f, 0.8f, Honey, counter.x, counter.y, 0.02f, "RugInner");
            return b.Group("Counter", p.parent, counter.x, counter.y);
        }
    }
}
