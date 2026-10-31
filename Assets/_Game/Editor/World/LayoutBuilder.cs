using FF.Data;
using FF.Gameplay.Nodes;
using FF.Gameplay.World;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

namespace FF.Editor.World
{
    /// <summary>
    /// Builds the primitive world blockout under World/Blockout in Game.unity from WorldLayout + ProductDef data.
    /// Shapes, sizes and colours follow the prototype's <c>buildWorld()</c>, <c>makeBuilding()</c>, <c>makeLot()</c>,
    /// <c>buildLot()</c>, <c>buildDreamPlot()</c> and <c>makeTree()</c>. Rebuilding replaces the previous blockout.
    /// State-dependent parts (other factories, sawmill 2, more registers, materials shop) are built inactive and
    /// switched on by gameplay later; the active set matches a new game.
    /// </summary>
    public static class LayoutBuilder
    {
        public const string RootName = "Blockout";
        const int ForestSeed = 20261031;

        // Palette (05_ART_UI_AUDIO + prototype literals)
        const int Grass = 0x9cce68, Paving = 0xe8d29f, Road = 0x5d5a57, Sidewalk = 0xd8d0c0, Marking = 0xf3efe4;
        const int ShopFloor = 0xcfa877, ShopStripe = 0xb58f5f, Fence = 0xa77447, Walnut = 0x2b1d14, Honey = 0xf3b33d;
        const int Cream = 0xfbf1de, Danger = 0xd9573b, Wood = 0x6d4325, Leaf = 0x3f8f3a, LeafLight = 0x52a845, Bush = 0x4f9c3e;
        const int Trunk = 0x8b5a2b, Pot = 0xb5653d, Wall = 0xefe3c8, Trim = 0x8a5a32, Steel = 0x3a4048, Lamp = 0xffe39a;
        const int SawWall = 0xb5703c, SawRoof = 0x7a3b2e;
        static readonly int[] TrimTiers = { 0x6d4325, 0xa23b2b, 0x3d6f8a, 0xd9a520 };

        [MenuItem("FF/Build World Blockout", priority = 20)]
        public static void BuildMenu()
        {
            Build();
            EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
            EditorSceneManager.SaveOpenScenes();
        }

        public static GameObject Build()
        {
            var db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            WorldLayout w = db.world;
            WorldStateSnapshot state = WorldStateSnapshot.NewGame(db.products);

            GameObject worldRoot = GameObject.Find("World") ?? new GameObject("World");
            Transform old = worldRoot.transform.Find(RootName);
            if (old != null) Object.DestroyImmediate(old.gameObject);

            var b = new Blockout(mirrorZ: true);
            Transform root = b.Group(RootName, worldRoot.transform);

            Transform ground = b.Group("Ground", root);
            BuildGround(b, ground, w, db.economy.ShopWallX(state.ShopLevel));
            BuildRoads(b, ground, w);
            BuildCarPark(b, ground, w);
            BuildFences(b, ground, w);
            BuildMinesYard(b, root, w, state);
            BuildDreamPlot(b, ground, w);
            BuildDelivery(b, ground, w);
            BuildProps(b, ground);
            Blockout.SetStaticRecursive(ground.gameObject);

            BuildSawmills(b, root, w, state);
            BuildFactoryRow(b, root, w, db, state);
            BuildMainShop(b, root, w, db.economy.ShopWallX(state.ShopLevel), state);
            BuildMaterialsShop(b, root, w, state);
            BuildForest(b, root, w);

            Debug.Log($"[FF] World blockout built: {root.GetComponentsInChildren<MeshRenderer>(true).Length} renderers.");
            return root.gameObject;
        }

        // ---------- ground, roads, fences ----------

        static void BuildGround(Blockout b, Transform p, WorldLayout w, float wallX)
        {
            b.Flat(p, 300, 140, Grass, 25, 0, 0, "Grass");
            b.Flat(p, 62, 8.4f, Paving, 15, -3.6f, 0.012f, "FactoryYard");
            b.Flat(p, 10, 3, Paving, -17, -3, 0.011f, "ForestPath");
            b.Flat(p, 5.6f, 8.6f, Paving, -15.8f, -9.6f, 0.0115f, "BackYardRoad");
            b.Flat(p, w.sawmill2.yardX.Size, w.sawmill2.yardZ.Size, Paving, w.sawmill2.yardX.Center, w.sawmill2.yardZ.Center, 0.012f, "SawYard");
        }

        static void BuildRoads(Blockout b, Transform p, WorldLayout w)
        {
            Transform roads = b.Group("Roads", p);
            float roadZ = w.road.z.Center;
            b.Flat(roads, 300, w.road.z.Size, Road, 25, roadZ, 0.014f, "MainRoad");
            Transform dashes = b.Group("LaneDashes", roads);
            for (float x = -120; x < 170; x += 3) b.Flat(dashes, 1.4f, 0.14f, Marking, x, roadZ, 0.016f, "Dash");
            b.Flat(roads, 300, w.road.sidewalkZ.Size, Sidewalk, 25, w.road.sidewalkZ.Center, 0.013f, "Sidewalk");
            Transform zebra = b.Group("Zebra", roads);
            for (float z = 11.7f; z < 15.6f; z += 0.8f) b.Flat(zebra, 3, 0.42f, Marking, w.road.zebraX, z, 0.017f, "Stripe");
        }

        static void BuildCarPark(Blockout b, Transform p, WorldLayout w)
        {
            WorldLayout.CarParkSettings c = w.carPark;
            Transform lot = b.Group("CarPark", p);
            float cx = c.x.Center, cz = c.z.Center;
            b.Flat(lot, 25.2f, 6.6f, Road, cx, cz, 0.014f, "Asphalt");
            b.Flat(lot, 25.8f, 7.2f, Sidewalk, cx, cz, 0.013f, "Kerb");
            b.Flat(lot, 3.6f, 3.2f, Road, c.drivewayX, 17.2f, 0.0145f, "Driveway");
            for (int i = 0; i <= c.slotCount; i++) b.Flat(lot, 0.1f, 3.8f, Marking, c.slotBaseX - 1.3f + i * c.slotStepX, 22.7f, 0.016f, "SlotLine");
            b.Sign(lot, "sign.lot", 2.4f, 0x3a6ea5, Cream, 36.2f, 1.7f, 19.1f);
            b.Box(lot, 0.12f, 1.6f, 0.12f, Steel, 36.2f, 0.8f, 19f, "SignPost");
            foreach (float x in new[] { 10.5f, 16f, 24f, 30f }) b.Ico(lot, 0.55f, Bush, x, 0.45f, 25.8f, "Bush");
        }

        static void BuildFences(Blockout b, Transform p, WorldLayout w)
        {
            Transform f = b.Group("Fences", p);
            float fz = w.fenceLineZ;
            for (float x = -31.5f; x <= 34f; x += 1.6f)
                if (x < w.sawmill2.accessRoadX.min || x > -1.4f) Post(b, f, x, fz);
            foreach ((float len, float cx) in new[] { (13f, -25f), (35.5f, 16.25f) }) Rails(b, f, len, cx, fz);

            // sawmill back yard (always open; sawmill 2 is bought later)
            Transform yard = b.Group("SawYardFence", f);
            ProtoRange yx = w.sawmill2.yardX, yz = w.sawmill2.yardZ;
            for (float x = yx.min; x <= yx.max + 0.01f; x += 1.7f) Post(b, yard, x, yz.min);
            for (float z = yz.min; z <= yz.max + 0.01f; z += 1.75f) { Post(b, yard, yx.min, z); Post(b, yard, yx.max, z); }
            b.Box(yard, yx.Size, 0.1f, 0.08f, Fence, yx.Center, 0.75f, yz.min, "Rail");
            b.Box(yard, 0.08f, 0.1f, yz.Size, Fence, yx.min, 0.75f, yz.Center, "Rail");
            b.Box(yard, 0.08f, 0.1f, yz.Size, Fence, yx.max, 0.75f, yz.Center, "Rail");
        }

        static void Post(Blockout b, Transform p, float x, float z) => b.Box(p, 0.12f, 0.9f, 0.12f, Fence, x, 0.45f, z, "Post");

        static void Rails(Blockout b, Transform p, float len, float cx, float z)
        {
            b.Box(p, len, 0.1f, 0.08f, Fence, cx, 0.75f, z, "Rail");
            b.Box(p, len, 0.1f, 0.08f, Fence, cx, 0.4f, z, "Rail");
        }

        // ---------- mines yard (opens with plumbing; rocks come in M8) ----------

        static void BuildMinesYard(Blockout b, Transform root, WorldLayout w, WorldStateSnapshot state)
        {
            Transform yard = b.Group("MinesYard", root);
            ProtoRange x = w.mines.x, z = w.mines.z;
            b.Flat(yard, x.Size, z.Size, 0x9a7a62, x.Center, z.Center, 0.012f, "Ground");
            for (float px = x.min; px <= x.max + 0.01f; px += 1.6f) Post(b, yard, px, z.min);
            for (float pz = z.min; pz <= z.max + 0.01f; pz += 1.6f) { Post(b, yard, x.min, pz); Post(b, yard, x.max, pz); }
            b.Box(yard, x.Size, 0.1f, 0.08f, Fence, x.Center, 0.75f, z.min, "Rail");
            b.Box(yard, 0.08f, 0.1f, z.Size, Fence, x.min, 0.75f, z.Center, "Rail");
            b.Box(yard, 0.08f, 0.1f, z.Size, Fence, x.max, 0.75f, z.Center, "Rail");
            b.Sign(yard, "sign.clay", 2.6f, 0xb5653d, Cream, 40, 1.6f, -14.4f);
            b.Box(yard, 0.12f, 1.6f, 0.12f, Wood, 40, 0.8f, -14.5f, "SignPost");
            b.Sign(yard, "sign.iron", 2.6f, Steel, Cream, 52, 1.6f, -14.4f);
            b.Box(yard, 0.12f, 1.6f, 0.12f, Wood, 52, 0.8f, -14.5f, "SignPost");
            Blockout.SetStaticRecursive(yard.gameObject);

            // gate segment of the factory fence: closes the yard until plumbing is bought
            Transform gate = b.Group("Gate", root);
            for (float px = 35.6f; px <= 60f; px += 1.6f) Post(b, gate, px, w.fenceLineZ);
            Rails(b, gate, 26, 47, w.fenceLineZ);
            gate.gameObject.SetActive(!state.MinesOpen);
        }

        // ---------- dream house plot (placeholder) ----------

        static void BuildDreamPlot(Blockout b, Transform p, WorldLayout w)
        {
            WorldLayout.DreamHouseSettings d = w.dreamHouse;
            Transform g = b.Group("DreamHousePlot", p);
            float cx = d.accessRoadX;
            b.Flat(g, d.plotX.Size, d.plotZ.Size, 0x92cc62, d.plotX.Center, d.plotZ.Center, 0.011f, "Lawn");
            b.Flat(g, 4.4f, 15.6f, Road, cx, 3.4f, 0.0145f, "Road");
            b.Flat(g, 5.2f, 15.6f, Sidewalk, cx, 3.4f, 0.0135f, "Kerb");
            for (float z = 9.6f; z > -4; z -= 2.2f) b.Flat(g, 0.14f, 1, Marking, cx, z, 0.016f, "Dash");
            foreach (float x in new[] { cx - 3, cx + 3 })
            foreach (float z in new[] { 6.5f, 0.5f })
            {
                b.Box(g, 0.12f, 3, 0.12f, Steel, x, 1.5f, z, "LampPost");
                b.Box(g, 0.5f, 0.14f, 0.5f, Steel, x, 3.02f, z, "LampHead");
                b.GlowBox(g, 0.36f, 0.16f, 0.36f, Lamp, x, 2.88f, z, "LampLight");
            }

            // arch
            b.Box(g, 0.3f, 3.6f, 0.3f, Wood, cx - 2.6f, 1.8f, d.archZ, "ArchPost");
            b.Box(g, 0.3f, 3.6f, 0.3f, Wood, cx + 2.6f, 1.8f, d.archZ, "ArchPost");
            b.Box(g, 5.6f, 0.3f, 0.34f, Wood, cx, 3.6f, d.archZ, "ArchBeam");
            b.Sign(g, "dream.title", 4.6f, Walnut, Honey, cx, 3.1f, d.archZ + 0.2f);

            // fence with a gap for the road
            for (float x = d.plotX.min; x <= d.plotX.max + 0.01f; x += 1.6f)
            {
                if (x < cx - 2.4f || x > cx + 2.4f) Post(b, g, x, d.plotZ.max);
                Post(b, g, x, d.plotZ.min);
            }
            for (float z = d.plotZ.min; z <= d.plotZ.max + 0.01f; z += 1.6f) { Post(b, g, d.plotX.min, z); Post(b, g, d.plotX.max, z); }
            b.Box(g, d.plotX.Size, 0.1f, 0.08f, Fence, d.plotX.Center, 0.75f, d.plotZ.min, "Rail");
            b.Box(g, 0.08f, 0.1f, d.plotZ.Size, Fence, d.plotX.min, 0.75f, d.plotZ.Center, "Rail");
            b.Box(g, 0.08f, 0.1f, d.plotZ.Size, Fence, d.plotX.max, 0.75f, d.plotZ.Center, "Rail");
            b.Box(g, 10.6f, 0.1f, 0.08f, Fence, 77.3f, 0.75f, d.plotZ.max, "Rail");
            b.Box(g, 10.6f, 0.1f, 0.08f, Fence, 92.7f, 0.75f, d.plotZ.max, "Rail");

            // paths, foundation with stakes and strings
            b.Flat(g, 3, 6, Paving, cx, -7, 0.012f, "Path");
            b.Flat(g, 9, 3, Paving, 81.5f, -11.5f, 0.012f, "Path");
            Vector2 fc = d.foundationCenter, fs = d.foundationSize;
            b.Flat(g, fs.x, fs.y, 0xcfc6b8, fc.x, fc.y, 0.016f, "Foundation");
            b.Flat(g, fs.x - 0.6f, fs.y - 0.6f, 0xb9b0a1, fc.x, fc.y, 0.017f, "FoundationInner");
            float sx = fs.x / 2 - 0.1f, sz = fs.y / 2 - 0.1f;
            foreach ((float x, float z) in new[] { (fc.x - sx, fc.y + sz), (fc.x + sx, fc.y + sz), (fc.x - sx, fc.y - sz), (fc.x + sx, fc.y - sz) })
                b.Box(g, 0.12f, 0.9f, 0.12f, 0xd9a066, x, 0.45f, z, "Stake");
            b.Box(g, fs.x - 0.2f, 0.03f, 0.03f, Danger, fc.x, 0.75f, fc.y + sz, "String");
            b.Box(g, fs.x - 0.2f, 0.03f, 0.03f, Danger, fc.x, 0.75f, fc.y - sz, "String");
            b.Box(g, 0.03f, 0.03f, fs.y - 0.2f, Danger, fc.x - sx, 0.75f, fc.y, "String");
            b.Box(g, 0.03f, 0.03f, fs.y - 0.2f, Danger, fc.x + sx, 0.75f, fc.y, "String");

            BuildBillboard(b, g, d.billboard);

            // owner's work area (empty for now)
            b.Flat(g, 7, 9, Paving, d.workArea.x, d.workArea.y, 0.016f, "WorkArea");
            b.Sign(g, "sign.sales", 2.6f, Walnut, Honey, d.workArea.x, 1.7f, -10.2f);
            b.Box(g, 0.12f, 1.6f, 0.12f, Wood, d.workArea.x, 0.8f, -10.3f, "SignPost");

            foreach ((float x, float z) in new[] { (70f, -8f), (70f, -20f), (100f, -10f), (100f, -22f), (76f, -28f), (92f, -28f) })
            {
                b.Cyl(g, 0.18f, 0.24f, 1.4f, Trunk, 7, x, 0.7f, z, "Trunk");
                b.Ico(g, 0.95f, Leaf, x, 1.9f, z, "Crown");
            }
        }

        /// <summary>Blockout of the prototype's painted billboard: sky panel, simple house, title and "Coming soon" ribbon.</summary>
        static void BuildBillboard(Blockout b, Transform p, Vector2 at)
        {
            Transform g = b.Group("Billboard", p);
            b.Box(g, 0.22f, 3.6f, 0.22f, Wood, at.x - 3.4f, 1.8f, at.y, "Post");
            b.Box(g, 0.22f, 3.6f, 0.22f, Wood, at.x + 3.4f, 1.8f, at.y, "Post");
            b.Box(g, 7.2f, 4.4f, 0.16f, Walnut, at.x, 3.4f, at.y - 0.12f, "Frame");
            float fz = at.y + 0.02f; // panel face, toward the camera
            b.Box(g, 6.9f, 4.3f, 0.02f, 0xcfe9f4, at.x, 3.4f, fz, "Sky");
            b.Box(g, 6.9f, 1.0f, 0.03f, 0x8cc65a, at.x, 1.75f, fz + 0.01f, "Hill");
            b.Box(g, 2.7f, 1.6f, 0.04f, Cream, at.x - 0.2f, 2.6f, fz + 0.02f, "House");
            GameObject roof = b.Box(g, 2.2f, 0.3f, 0.05f, Danger, at.x - 0.9f, 3.65f, fz + 0.03f, "RoofL");
            roof.transform.localRotation = Quaternion.Euler(0, 0, 33);
            roof = b.Box(g, 2.2f, 0.3f, 0.05f, Danger, at.x + 0.5f, 3.65f, fz + 0.03f, "RoofR");
            roof.transform.localRotation = Quaternion.Euler(0, 0, -33);
            b.Box(g, 0.5f, 0.8f, 0.05f, Wood, at.x - 0.2f, 2.2f, fz + 0.03f, "Door");
            b.Sign(g, "dream.title", 4.2f, Walnut, Honey, at.x - 1.2f, 5.0f, fz + 0.05f);
            Transform ribbon = b.Sign(g, "dream.soon", 2.2f, Danger, 0xffffff, at.x + 2.2f, 2.0f, fz + 0.05f);
            ribbon.localRotation = Quaternion.Euler(0, 0, 10);
        }

        // ---------- delivery yard ----------

        static void BuildDelivery(Blockout b, Transform p, WorldLayout w)
        {
            Transform g = b.Group("DeliveryYard", p);
            for (int i = 0; i < w.delivery.baysX.Length; i++)
            {
                Transform bay = b.Group("Bay" + i, g, w.delivery.baysX[i]);
                b.Box(bay, 3.6f, 0.16f, 1.3f, Fence, 0, 0.08f, 11.2f, "Dock");
                b.Flat(bay, 4.6f, 2.2f, Marking, 0, w.delivery.truckParkZ, 0.015f, "BayLines");
                b.Flat(bay, 4.4f, 2, Road, 0, w.delivery.truckParkZ, 0.016f, "BayAsphalt");
            }
            b.Sign(g, "sign.delivery", 2.2f, Walnut, Honey, 1.6f, 2.35f, 8.4f);
            b.Box(g, 0.14f, 2.2f, 0.14f, Wood, 1.6f, 1.1f, 8.36f, "SignPost");
        }

        static void BuildProps(Blockout b, Transform p)
        {
            Transform g = b.Group("Bushes", p);
            var rng = new System.Random(ForestSeed + 1);
            foreach ((float x, float z) in new[] { (-11f, 7f), (-13f, 9f), (-20f, 8f), (65f, 9f), (66f, 3f), (-26f, 8f) })
                b.Ico(g, 0.7f + (float)rng.NextDouble() * 0.4f, Bush, x, 0.55f, z, "Bush");
        }

        // ---------- buildings ----------

        static void BuildSawmills(Blockout b, Transform root, WorldLayout w, WorldStateSnapshot state)
        {
            Vector2 c1 = w.sawmill1.center;
            Building(b, root, "Sawmill1", c1.x, c1.y, SawWall, SawRoof, "sign.saw", saw: true).gameObject.SetActive(true);

            Vector2 c2 = w.sawmill2.building;
            Building(b, root, "Sawmill2", c2.x, c2.y, SawWall, SawRoof, "sign.saw2", saw: true).gameObject.SetActive(state.OwnsSawmill2);
            Lot(b, root, "Sawmill2Lot", c2.x, c2.y, w).gameObject.SetActive(!state.OwnsSawmill2);
        }

        static void BuildFactoryRow(Blockout b, Transform root, WorldLayout w, GameDatabase db, WorldStateSnapshot state)
        {
            Transform row = b.Group("FactoryRow", root);
            foreach (ProductDef p in db.products)
            {
                bool owned = state.OwnedProducts.Contains(p.id);
                Transform slot = b.Group(p.id, row);
                Building(b, slot, "Building", p.factoryX, w.factories.rowZ, ToHex(p.wallColor), ToHex(p.roofColor), p.signKey, saw: false)
                    .gameObject.SetActive(owned);
                Lot(b, slot, "Lot", p.factoryX, w.factories.rowZ, w).gameObject.SetActive(!owned);
            }
        }

        /// <summary>Prototype <c>makeBuilding()</c> at upgrade level 0 (growth decorations arrive in M4).</summary>
        static Transform Building(Blockout b, Transform parent, string name, float cx, float cz, int wall, int roof, string signKey, bool saw)
        {
            Transform g = b.Group(name, parent, cx, cz);
            b.Box(g, 5.4f, 2.6f, 4, wall, 0, 1.3f, 0, "Shell");
            b.Box(g, 1.8f, 0.8f, 0.8f, Wood, 0, 0.4f, 2.4f, "Intake");
            if (saw)
            {
                Transform blade = b.Group("SawBlade", g, 0, 2.42f, 1.25f);
                GameObject disc = b.Cyl(blade, 0.62f, 0.62f, 0.06f, 0xc9d1d8, 14, 0, 0, 0, "Disc");
                b.RotateX(disc, Mathf.PI / 2);
                GameObject hub = b.Cyl(blade, 0.14f, 0.14f, 0.1f, 0x55606a, 8, 0, 0, 0, "Hub");
                b.RotateX(hub, Mathf.PI / 2);
            }
            else
            {
                Transform press = b.Group("Press", g, 0.3f, 2.15f, 1.05f);
                b.Box(press, 0.08f, 0.08f, 0.7f, Trunk, 0, 0, 0.35f, "Arm");
                b.Box(press, 0.32f, 0.2f, 0.22f, 0x55606a, 0, 0, 0.7f, "Hammer");
            }
            b.Sign(g, signKey, 3.2f, Walnut, Honey, 0, 2.25f, 2.04f);

            Transform deco = b.Group("Deco", g);
            b.Box(deco, 5.5f, 0.16f, 4.1f, TrimTiers[0], 0, 2.6f, 0, "TrimBand");
            const float y = 2.6f, rw = 5.9f, rd = 2.5f, rz = 1.05f;
            GameObject back = b.Box(deco, rw, 0.18f, rd, roof, 0, y + 0.45f, -rz, "RoofBack");
            b.RotateX(back, 0.55f);
            GameObject front = b.Box(deco, rw, 0.18f, rd, roof, 0, y + 0.45f, rz, "RoofFront");
            b.RotateX(front, -0.55f);
            return g;
        }

        /// <summary>Prototype <c>makeLot()</c>: fenced empty plot where a factory will stand.</summary>
        static Transform Lot(Blockout b, Transform parent, string name, float cx, float cz, WorldLayout w)
        {
            Transform g = b.Group(name, parent, cx, cz);
            Vector2 fp = w.factories.footprint;
            b.Flat(g, fp.x, fp.y, 0xb08a5a, 0, 0, 0.015f, "Ground");
            float hx = fp.x / 2, hz = fp.y / 2;
            for (int i = 0; i < 8; i++) b.Box(g, 0.12f, 0.7f, 0.12f, Fence, -hx + i * (fp.x / 7), 0.35f, -hz, "Post");
            for (int i = 1; i < 5; i++)
            {
                b.Box(g, 0.12f, 0.7f, 0.12f, Fence, -hx, 0.35f, -hz + i, "Post");
                b.Box(g, 0.12f, 0.7f, 0.12f, Fence, hx, 0.35f, -hz + i, "Post");
            }
            b.Box(g, fp.x + 0.1f, 0.08f, 0.06f, Fence, 0, 0.55f, -hz, "Rail");
            return g;
        }

        // ---------- shops ----------

        static void BuildMainShop(Blockout b, Transform root, WorldLayout w, float wallX, WorldStateSnapshot state)
        {
            WorldLayout.MainShopSettings s = w.mainShop;
            Transform shop = b.Group("MainShop", root);
            float floorZ = 5.1f, floorD = 9.2f;
            b.Flat(shop, wallX - s.floorMinX, floorD, ShopFloor, (s.floorMinX + wallX) / 2, floorZ, 0.013f, "Floor");
            Transform stripes = b.Group("FloorStripes", shop);
            for (float x = 3.2f; x < 46; x += 1.2f)
                b.Flat(stripes, 0.04f, floorD, ShopStripe, x, floorZ, 0.014f, "Stripe").SetActive(x < wallX - 0.15f);

            // low walls, the right wall moves out when the shop is expanded (M5)
            b.Box(shop, 0.22f, 1, 9.4f, Wall, s.floorMinX, 0.5f, floorZ, "LeftWall");
            b.Box(shop, 0.24f, 0.1f, 9.5f, Trim, s.floorMinX, 1.05f, floorZ, "LeftTrim");
            b.Box(shop, 15.1f, 1, 0.22f, Wall, 10.35f, 0.5f, s.doorZ, "FrontLeftWall");
            b.Box(shop, 15.2f, 0.1f, 0.24f, Trim, 10.35f, 1.05f, s.doorZ, "FrontLeftTrim");
            Transform right = b.Group("RightWall", shop, wallX);
            b.Box(right, 0.22f, 1, 9.4f, Wall, 0, 0.5f, floorZ, "Wall");
            b.Box(right, 0.24f, 0.1f, 9.5f, Trim, 0, 1.05f, floorZ, "Trim");
            foreach (float z in new[] { 9f, 0.9f }) Plant(b, right, -0.7f, z);
            float fw = wallX - s.doorX.max;
            b.Box(shop, fw, 1, 0.22f, Wall, s.doorX.max + fw / 2, 0.5f, s.doorZ, "FrontRightWall");
            b.Box(shop, fw + 0.1f, 0.1f, 0.24f, Trim, s.doorX.max + fw / 2, 1.05f, s.doorZ, "FrontRightTrim");

            // entrance
            b.Box(shop, 0.3f, 2.8f, 0.3f, Trim, s.doorX.min, 1.4f, s.doorZ, "DoorPost");
            b.Box(shop, 0.3f, 2.8f, 0.3f, Trim, s.doorX.max, 1.4f, s.doorZ, "DoorPost");
            b.Box(shop, 4.5f, 0.32f, 0.34f, Trim, s.doorX.Center, 2.8f, s.doorZ, "DoorBeam");
            b.Sign(shop, "sign.shop", 3.4f, Danger, Cream, s.doorX.Center, 3.4f, s.doorZ + 0.02f);
            b.Flat(shop, 3.4f, 1.6f, 0x9c3b2b, s.doorX.Center, 8.7f, 0.018f, "Mat");
            b.Flat(shop, 3, 1.2f, 0xc8553f, s.doorX.Center, 8.7f, 0.019f, "MatInner");
            foreach ((float x, float z) in new[] { (3.6f, 9f), (17.2f, 9f), (22.8f, 9f) }) Plant(b, shop, x, z);

            Transform regs = b.Group("Registers", shop);
            for (int i = 0; i < s.registersX.Length; i++)
                RegisterStall(b, regs, "Register" + i, s.registersX[i], s.stallCenterZ).gameObject.SetActive(i < state.MainRegisters);
        }

        static void BuildMaterialsShop(Blockout b, Transform root, WorldLayout w, WorldStateSnapshot state)
        {
            WorldLayout.MaterialsShopSettings m = w.materialsShop;
            Transform a = b.Group("MaterialsShop", root);
            float floorZ = 5.1f;
            b.Flat(a, 14.2f, 9.2f, 0xc3c8cc, m.x.Center, floorZ, 0.013f, "Floor");
            for (float x = 47; x < 60.4f; x += 1.2f) b.Flat(a, 0.04f, 9.2f, 0x9aa1a8, x, floorZ, 0.014f, "Stripe");
            b.Box(a, 0.22f, 1, 9.4f, Wall, m.x.min, 0.5f, floorZ, "LeftWall");
            b.Box(a, 0.22f, 1, 9.4f, Wall, m.x.max, 0.5f, floorZ, "RightWall");
            b.Box(a, 3.6f, 1, 0.22f, Wall, 48.2f, 0.5f, m.z.max, "FrontLeftWall");
            b.Box(a, 7.6f, 1, 0.22f, Wall, 56.8f, 0.5f, m.z.max, "FrontRightWall");
            b.Box(a, 0.24f, 0.1f, 9.5f, 0x5a6470, m.x.min, 1.05f, floorZ, "Trim");
            b.Box(a, 0.24f, 0.1f, 9.5f, 0x5a6470, m.x.max, 1.05f, floorZ, "Trim");
            b.Box(a, 0.3f, 2.8f, 0.3f, 0x5a6470, m.doorX.min, 1.4f, m.z.max, "DoorPost");
            b.Box(a, 0.3f, 2.8f, 0.3f, 0x5a6470, m.doorX.max, 1.4f, m.z.max, "DoorPost");
            b.Box(a, 3.5f, 0.32f, 0.34f, 0x5a6470, m.doorX.Center, 2.8f, m.z.max, "DoorBeam");
            b.Sign(a, "s.material", 3, Steel, Honey, m.doorX.Center, 3.4f, m.z.max + 0.02f);
            b.Flat(a, 2.6f, 1.4f, Steel, m.doorX.Center, 8.7f, 0.018f, "Mat");
            Transform regs = b.Group("Registers", a);
            for (int i = 0; i < m.registersX.Length; i++)
            {
                bool active = state.OwnsPlumbing && (i == 0 || state.AnnexSecondRegister);
                RegisterStall(b, regs, "Register" + (6 + i), m.registersX[i], w.mainShop.stallCenterZ).gameObject.SetActive(active);
            }
            a.gameObject.SetActive(state.OwnsPlumbing);
        }

        /// <summary>Register stall: counter running front-to-back with a striped awning (prototype register loop).</summary>
        static Transform RegisterStall(Blockout b, Transform parent, string name, float x, float z)
        {
            Transform g = b.Group(name, parent, x, z);
            b.Box(g, 1.1f, 1, 3, 0xa0622f, 0, 0.5f, 0, "Counter");
            b.Box(g, 1.25f, 0.1f, 3.15f, 0xd9a066, 0, 1.04f, 0, "CounterTop");
            foreach ((float px, float pz) in new[] { (-0.55f, -1.5f), (0.55f, -1.5f), (-0.55f, 1.5f), (0.55f, 1.5f) })
                b.Box(g, 0.12f, 2.7f, 0.12f, Wood, px, 1.35f, pz, "AwningPost");
            for (int k = 0; k < 5; k++) b.Box(g, 1.6f, 0.12f, 0.63f, k % 2 == 1 ? Cream : Danger, 0, 2.75f, -1.26f + k * 0.63f, "AwningStripe");
            return g;
        }

        static void Plant(Blockout b, Transform p, float x, float z)
        {
            b.Cyl(p, 0.28f, 0.22f, 0.5f, Pot, 8, x, 0.25f, z, "Pot");
            b.Ico(p, 0.42f, Leaf, x, 0.78f, z, "Leaves");
        }

        // ---------- forest ----------

        static void BuildForest(Blockout b, Transform root, WorldLayout w)
        {
            Transform forest = b.Group("Forest", root);
            WorldLayout.GridSettings f = w.forest;
            var rng = new System.Random(ForestSeed);
            var fallRng = new System.Random(ForestSeed + 2); // separate stream: keeps the M1 tree positions
            for (int c = 0; c < f.cols; c++)
            for (int r = 0; r < f.rows; r++)
            {
                float x = f.origin.x + c * f.step.x + ((float)rng.NextDouble() - 0.5f) * f.jitter;
                float z = f.origin.y + r * f.step.y + ((float)rng.NextDouble() - 0.5f) * f.jitter;
                Tree(b, forest, x, z, 0.9f + (float)rng.NextDouble() * 0.3f, fallRng.NextDouble() < 0.5 ? 1f : -1f);
            }
        }

        /// <summary>Prototype <c>makeTree()</c>: stump + "Top" (trunk and two crowns) that topples when chopped.</summary>
        static void Tree(Blockout b, Transform parent, float x, float z, float crown, float fallDirection)
        {
            Transform g = b.Group("Tree", parent, x, z);
            b.Cyl(g, 0.26f, 0.32f, 0.3f, 0x7a4a24, 8, 0, 0.15f, 0, "Stump");
            Transform top = b.Group("Top", g);
            b.Cyl(top, 0.2f, 0.27f, 1.7f, Trunk, 7, 0, 0.85f, 0, "Trunk");
            b.Ico(top, 1f * crown, Leaf, 0, 2.05f, 0, "Crown");
            b.Ico(top, 0.7f * crown, LeafLight, 0.1f, 2.75f, 0.05f, "CrownTop");
            g.gameObject.AddComponent<ResourceNode>().Setup(ItemType.Log, top, fallDirection);
        }

        static int ToHex(Color c)
        {
            Color32 c32 = c;
            return (c32.r << 16) | (c32.g << 8) | c32.b;
        }
    }
}
