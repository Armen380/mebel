using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.Editor.Characters;
using FF.Gameplay.Delivery;
using FF.Gameplay.Pads;
using FF.Gameplay.Shop;
using FF.Gameplay.Tutorial;
using FF.Gameplay.Unlocks;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor.World
{
    /// <summary>
    /// Builds World/Shop (shelves + shelf zones, registers + cash zones), World/Delivery (truck bays + dock zones),
    /// World/Pads (sawmill / factory speed and quantity pads, shop, register, truck, parking), the customer variant prefabs
    /// and the tutorial arrow. Prototype ~941–1000, addPad/drawPad.
    /// </summary>
    public static class ShopBuilder
    {
        public const string RootName = "Shop";
        public const string PadsRootName = "Pads";
        public const string CustomersFolder = "Assets/_Game/Prefabs/Characters/Customers";
        const int CustomerVariants = 12;
        const int CustomerSeed = 20261101;
        const int Walnut = 0x2b1d14, Cream = 0xfbf1de, ShelfWood = 0x8a5a32, ShelfBack = 0x6d4325, Honey = 0xf3b33d;

        static readonly Color DropTint = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.30f);
        static readonly Color CashTint = new Color(196 / 255f, 134 / 255f, 26 / 255f, 0.45f);
        // prototype SHIRTS, pants and skin tones of spawnCustomer
        static readonly int[] Shirts = { 0xe76f51, 0x2a9d8f, 0x8d5fd3, 0xf4a261, 0x457b9d, 0xe9c46a, 0xd1495b, 0x6a994e, 0xef8fb5 };
        static readonly int[] Pants = { 0x264653, 0x3d405b, 0x5b4636, 0x22333b };
        static readonly int[] Skins = { 0xf1c27d, 0xe0ac69, 0xc68642, 0xffdbac };
        static readonly HatType[] Hats = { HatType.None, HatType.None, HatType.Cap, HatType.Beanie };

        public sealed class Result
        {
            public readonly List<Zone> Zones = new List<Zone>();
            public readonly List<Shelf> Shelves = new List<Shelf>();
            public readonly List<Register> Registers = new List<Register>();
            public readonly List<UpgradePad> Pads = new List<UpgradePad>();
            public readonly List<TruckBay> Bays = new List<TruckBay>();
            public readonly List<Zone> Docks = new List<Zone>();
        }

        public static Result Build(GameDatabase db)
        {
            var result = new Result();
            Transform world = (GameObject.Find("World") ?? new GameObject("World")).transform;
            Transform root = FreshRoot(world, RootName);
            var ctx = new Context(db);

            Transform blockout = world.Find(LayoutBuilder.RootName);
            foreach (ProductDef p in db.products) result.Shelves.Add(ctx.Shelf(root, p, result.Zones));
            WorldLayout.MainShopSettings main = db.world.mainShop;
            for (int i = 0; i < main.registersX.Length; i++)
                result.Registers.Add(ctx.Register(root, i, main.registersX[i], main.stallCenterZ, blockout?.Find($"MainShop/Registers/Register{i}"), result.Zones));
            float[] annex = db.world.materialsShop.registersX;
            for (int i = 0; i < annex.Length; i++)
            {
                int index = Register.FirstAnnexIndex + i;
                result.Registers.Add(ctx.Register(root, index, annex[i], main.stallCenterZ, blockout?.Find($"MaterialsShop/Registers/Register{index}"), result.Zones));
            }

            Transform delivery = FreshRoot(world, "Delivery");
            for (int i = 0; i < db.world.delivery.baysX.Length; i++)
            {
                TruckBay bay = ctx.Bay(delivery, i, blockout?.Find($"Ground/DeliveryYard/Bay{i}"), result.Zones);
                result.Bays.Add(bay);
                result.Docks.Add(bay.Dock);
            }

            Transform padsRoot = FreshRoot(world, PadsRootName);
            AddPad(result, ctx, padsRoot, db.Pad(PadRewards.Sawmill2BuyPad), PadRule.BuyOwner, WorldStateSnapshot.Sawmill2Id);
            foreach (string machine in MachineIds(db))
            foreach (string suffix in new[] { "_speed", "_qty" })
                AddPad(result, ctx, padsRoot, db.Pad(machine + suffix), PadRule.OwnerOwned, machine);
            // factory buy pads of the main shop's products (Sink / Materials come with plumbing in M8)
            foreach (ProductDef p in db.products)
                if (p.factoryCost > 0 && p.sellsIn == ShopKind.Main)
                    AddPad(result, ctx, padsRoot, db.Pad(p.id + "_buy"), PadRule.BuyOwner, p.id);
            AddPad(result, ctx, padsRoot, db.Pad(WorldStateSync.ShopPadId), PadRule.Always, null);
            UpgradePad reg = AddPad(result, ctx, padsRoot, db.Pad(WorldStateSync.RegisterPadId), PadRule.Register, null);
            if (reg != null)
                reg.gameObject.AddComponent<RegisterPadPlacer>().Setup(result.Registers.GetRange(0, main.registersX.Length));
            AddPad(result, ctx, padsRoot, db.Pad(DeliveryDirector.TruckPadId), PadRule.Always, null);
            AddPad(result, ctx, padsRoot, db.Pad(TruckBay.ParkingPadId), PadRule.Always, null);

            BuildLockedLabels(world, db);

            Debug.Log($"[FF] Shop built: {result.Shelves.Count} shelves, {result.Registers.Count} registers, {result.Bays.Count} truck bays, {result.Pads.Count} pads.");
            return result;
        }

        static UpgradePad AddPad(Result result, Context ctx, Transform root, PadDef def, PadRule rule, string owner)
        {
            if (def == null) return null;
            UpgradePad pad = ctx.Pad(root, def, rule, owner);
            result.Pads.Add(pad);
            return pad;
        }

        /// <summary>
        /// Prototype <c>addLabel(…, 'locked')</c> chips: each factory lot until its level (lk.lv), Sawmill 2's lot until
        /// bought, and "Dream house / Soon" over the dream plot.
        /// </summary>
        static void BuildLockedLabels(Transform world, GameDatabase db)
        {
            Transform root = FreshRoot(world, "LockedLabels");
            WorldLayout w = db.world;
            foreach (ProductDef p in db.products)
                if (p.factoryCost > 0 && p.sellsIn == ShopKind.Main)
                    Label(root, "Lock_" + p.id, LockedLabel.Kind.FactoryLevel, p.id, null,
                        new Vector3(p.factoryX, 2.4f, w.factories.RowZ(p.factoryRow) + 1f));
            Vector2 saw2 = w.sawmill2.building;
            Label(root, "Lock_saw2", LockedLabel.Kind.NotOwned, WorldStateSnapshot.Sawmill2Id, "sign.saw2", new Vector3(saw2.x, 2.2f, saw2.y + 0.5f));
            Label(root, "DreamSoon", LockedLabel.Kind.Fixed, null, "dream.chip", w.dreamHouse.soonChip);
        }

        static void Label(Transform root, string name, LockedLabel.Kind kind, string owner, string key, Vector3 protoPos)
        {
            var go = new GameObject(name);
            go.transform.SetParent(root, false);
            go.transform.position = ProtoCoords.ToUnity(protoPos.x, protoPos.y, protoPos.z);
            go.AddComponent<LockedLabel>().Setup(kind, owner, key);
        }

        static IEnumerable<string> MachineIds(GameDatabase db)
        {
            yield return WorldStateSnapshot.Sawmill1Id;
            yield return WorldStateSnapshot.Sawmill2Id;
            foreach (ProductDef p in db.products) yield return p.id;
        }

        static Transform FreshRoot(Transform parent, string name)
        {
            Transform old = parent.Find(name);
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            return go.transform;
        }

        // ---------- customers ----------

        [MenuItem("FF/Build Customer Prefabs", priority = 23)]
        static void BuildCustomersMenu() => BuildCustomerVariants(true);

        /// <summary>12 colour variants from the prototype palettes (seeded), each a prefab with a Customer component.</summary>
        /// <param name="rebuild">False keeps existing prefabs (stable file ids) and only adds missing ones.</param>
        public static List<Customer> BuildCustomerVariants(bool rebuild)
        {
            DataImporter.EnsureFolder(CustomersFolder);
            var rng = new System.Random(CustomerSeed);
            var list = new List<Customer>();
            for (int i = 0; i < CustomerVariants; i++)
            {
                string path = $"{CustomersFolder}/Customer_{i:00}.prefab";
                var skin = ScriptableObject.CreateInstance<SkinDef>(); // drawn for every variant so the seeded sequence stays the same
                skin.id = $"customer{i:00}";
                skin.shirt = Blockout.Hex(Shirts[rng.Next(Shirts.Length)]);
                skin.pants = Blockout.Hex(Pants[rng.Next(Pants.Length)]);
                skin.skin = Blockout.Hex(Skins[rng.Next(Skins.Length)]);
                skin.hat = Blockout.Hex(Shirts[rng.Next(Shirts.Length)]);
                skin.hatType = Hats[rng.Next(Hats.Length)];
                GameObject prefab = rebuild ? null : AssetDatabase.LoadAssetAtPath<GameObject>(path);
                if (prefab == null)
                {
                    GameObject go = CharacterRigBuilder.Build($"Customer_{i:00}", skin);
                    go.AddComponent<Customer>();
                    prefab = PrefabUtility.SaveAsPrefabAsset(go, path);
                    Object.DestroyImmediate(go);
                }
                Object.DestroyImmediate(skin);
                list.Add(prefab.GetComponent<Customer>());
            }
            return list;
        }

        // ---------- tutorial arrow ----------

        /// <summary>Prototype arrow: ConeGeometry(.34, .7, 4), honey, unlit, pointing down.</summary>
        public static TutorialArrow BuildTutorialArrow(Transform parent, TutorialService service, UnlockService unlocks)
        {
            Transform old = parent.Find("TutorialArrow");
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var go = new GameObject("TutorialArrow");
            go.transform.SetParent(parent, false);
            var cone = new GameObject("Cone");
            cone.transform.SetParent(go.transform, false);
            cone.transform.localScale = new Vector3(1, 0.7f, 1);
            cone.transform.localRotation = Quaternion.Euler(180, 0, 0);
            cone.AddComponent<MeshFilter>().sharedMesh = LowPolyMeshFactory.Cylinder(0, 0.34f, 4);
            var r = cone.AddComponent<MeshRenderer>();
            r.sharedMaterial = MaterialPaletteEditor.Get(Blockout.Hex(Honey), true);
            r.shadowCastingMode = ShadowCastingMode.Off;
            var arrow = go.AddComponent<TutorialArrow>();
            arrow.Setup(service, unlocks, cone);
            return arrow;
        }

        /// <summary>Shared assets while building.</summary>
        sealed class Context
        {
            readonly GameDatabase _db;
            readonly Blockout _b = new Blockout(mirrorZ: true);
            readonly ZoneFactory _zones;
            readonly Material _dropMaterial, _cashMaterial, _padBase, _padFill, _padStroke;

            public Context(GameDatabase db)
            {
                _db = db;
                _zones = new ZoneFactory(db);
                _dropMaterial = ZoneFactory.TransparentMaterial("ZoneMarker_Drop", TextureFactory.ZoneMarker("Drop", DropTint, -1), 10);
                _cashMaterial = ZoneFactory.TransparentMaterial("ZoneMarker_Cash", TextureFactory.ZoneMarker("Cash", CashTint, 0), 10);
                _padBase = ZoneFactory.TransparentMaterial("Pad_Base", TextureFactory.PadLayer("Base"), 15);
                _padFill = ZoneFactory.TransparentMaterial("Pad_Fill", TextureFactory.PadLayer("Fill"), 14);
                _padStroke = ZoneFactory.TransparentMaterial("Pad_Stroke", TextureFactory.PadLayer("Stroke"), 13);
            }

            public Shelf Shelf(Transform root, ProductDef p, List<Zone> zones)
            {
                WorldLayout.MainShopSettings s = _db.world.mainShop;
                var go = new GameObject("Shelf_" + p.id);
                go.transform.SetParent(root, false);

                Transform visual = _b.Group("Visual", go.transform, p.shelfX, s.shelfPileZ);
                _b.Box(visual, 1.9f, 0.14f, 1.3f, ShelfWood, 0, 0.07f, 0, "Base");
                _b.Box(visual, 1.9f, 1.5f, 0.1f, ShelfBack, 0, 0.75f, -0.7f, "Back");
                _b.Sign(visual, p.signKey, 1.8f, Walnut, Cream, 0, 1.75f, -0.64f);

                Zone zone = _zones.Zone("shelf_" + p.id, go.transform, ZoneKind.Drop, p.item, new Vector2(p.shelfX, s.shelfZoneZ),
                    s.shelfPile.offset, "z.shelf", null, _dropMaterial);
                zones.Add(zone);
                var shelf = go.AddComponent<Shelf>();
                shelf.Setup(p, zone, visual.gameObject);
                return shelf;
            }

            public Register Register(Transform root, int index, float x, float z, Transform stall, List<Zone> zones)
            {
                WorldLayout.MainShopSettings s = _db.world.mainShop;
                var go = new GameObject("Register" + index);
                go.transform.SetParent(root, false);
                go.transform.position = ProtoCoords.ToUnity(x, z);
                if (stall == null) Debug.LogWarning($"[FF] Register stall {index} not found; build the world blockout first.");

                Zone zone = _zones.Zone("cash" + index, go.transform, ZoneKind.Cash, ItemType.Bill, new Vector2(x, z) + s.cashZoneOffset,
                    s.cashPile.offset, "z.reg", NumberFormat.Currency, _cashMaterial);
                zones.Add(zone);
                var register = go.AddComponent<Register>();
                register.Setup(index, zone, stall != null ? stall.gameObject : null);
                return register;
            }

            /// <summary>Prototype bay: dock zone "TRUCK" (drop marker, any furniture) in front of the bay asphalt.</summary>
            public TruckBay Bay(Transform root, int index, Transform visual, List<Zone> zones)
            {
                WorldLayout.DeliverySettings d = _db.world.delivery;
                var go = new GameObject("Bay" + index);
                go.transform.SetParent(root, false);
                go.transform.position = ProtoCoords.ToUnity(d.baysX[index], d.truckParkZ);
                if (visual == null) Debug.LogWarning($"[FF] Truck bay {index} not found; build the world blockout first.");

                Zone zone = _zones.Zone("dock" + index, go.transform, ZoneKind.Drop, ItemType.None, new Vector2(d.baysX[index], d.dockZoneZ),
                    Vector3.zero, "z.truck", null, _dropMaterial);
                zone.SetupAnyProduct();
                zones.Add(zone);
                var bay = go.AddComponent<TruckBay>();
                bay.Setup(index, zone, visual != null ? visual.gameObject : null);
                return bay;
            }

            public UpgradePad Pad(Transform root, PadDef def, PadRule rule, string owner)
            {
                float size = _db.world.production.padSize;
                var go = new GameObject("Pad_" + def.id);
                go.transform.SetParent(root, false);
                go.transform.position = ProtoCoords.ToUnity(def.protoPos);

                var visual = new GameObject("Visual");
                visual.transform.SetParent(go.transform, false);
                ZoneFactory.Quad(visual.transform, "Base", _padBase, 0.035f, size);
                Transform fill = ZoneFactory.Quad(visual.transform, "Fill", _padFill, 0.036f, size);
                ZoneFactory.Quad(visual.transform, "Stroke", _padStroke, 0.037f, size);
                // prototype canvas: glyph 78 px at y 82, price ≤ 74 px at y 180 (fit 216 px), 256 px over the pad
                _zones.FlatText(visual.transform, "Glyph", def.glyph, null, Color.white, new Vector2(size * 0.8f, size * 0.42f), size * (128f - 82f) / 256f, size * 6f);
                TMP_Text price = _zones.FlatText(visual.transform, "Price", "$0", null, Blockout.Hex(Walnut),
                    new Vector2(size * 216f / 256f, size * 0.4f), size * (128f - 180f) / 256f, size * 6f);

                var pad = go.AddComponent<UpgradePad>();
                pad.Setup(def, rule, owner, visual, fill, price);
                return pad;
            }
        }
    }
}
