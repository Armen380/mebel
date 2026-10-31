using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Editor.Art;
using FF.Gameplay.Production;
using FF.Gameplay.World;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Editor.World
{
    /// <summary>
    /// Builds World/Production: one Machine per sawmill / product factory with its input and output zones,
    /// ground markers and pile anchors (prototype ~905–933). Runs after <see cref="LayoutBuilder"/>, whose
    /// buildings provide the saw blades and presses. Returns the zones in prototype order.
    /// </summary>
    public static class ProductionBuilder
    {
        public const string RootName = "Production";
        // prototype T_DROP / T_PICK
        static readonly Color DropTint = new Color(43 / 255f, 29 / 255f, 20 / 255f, 0.30f);
        static readonly Color PickupTint = new Color(61 / 255f, 138 / 255f, 49 / 255f, 0.42f);

        public static List<Zone> Build(GameDatabase db)
        {
            WorldLayout w = db.world;
            GameObject worldRoot = GameObject.Find("World") ?? new GameObject("World");
            Transform old = worldRoot.transform.Find(RootName);
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var root = new GameObject(RootName).transform;
            root.SetParent(worldRoot.transform, false);

            var ctx = new Context(db, root);
            Transform blockout = worldRoot.transform.Find(LayoutBuilder.RootName);

            ctx.Machine(WorldStateSnapshot.Sawmill1Id, null, w.sawmill1.sawIn, w.sawmill1.sawOut, w.sawmill1.machineMouth,
                ItemType.Log, ItemType.Plank, "in.log", "in.plank", Part(blockout, "Sawmill1/SawBlade"), null);
            ctx.Machine(WorldStateSnapshot.Sawmill2Id, null, w.sawmill2.saw2In, w.sawmill2.saw2Out, w.sawmill2.machineMouth,
                ItemType.Log, ItemType.Plank, "in.log", "in.plank", Part(blockout, "Sawmill2/SawBlade"), null);

            WorldLayout.FactoryRowSettings f = w.factories;
            foreach (ProductDef p in db.products)
            {
                var mouth = new Vector3(p.factoryX, w.production.factoryMouthY, w.production.factoryMouthZ);
                ctx.Machine(p.id, p, new Vector2(p.factoryX + f.inZoneDx, f.zoneZ), new Vector2(p.factoryX + f.outZoneDx, f.zoneZ), mouth,
                    p.input, p.item, "in." + p.input.ToString().ToLowerInvariant(), p.signKey, null,
                    Part(blockout, $"FactoryRow/{p.id}/Building/Press"));
            }

            Debug.Log($"[FF] Production built: {ctx.Zones.Count / 2} machines, {ctx.Zones.Count} zones.");
            return ctx.Zones;
        }

        static Transform Part(Transform blockout, string path)
        {
            Transform t = blockout != null ? blockout.Find(path) : null;
            if (t == null) Debug.LogWarning($"[FF] Building part '{path}' not found; build the world blockout first.");
            return t;
        }

        /// <summary>Shared assets and the zone list while building.</summary>
        sealed class Context
        {
            public readonly List<Zone> Zones = new List<Zone>();
            readonly GameDatabase _db;
            readonly Transform _root;
            readonly ZoneFactory _zones;
            readonly Material _dropMaterial, _pickupMaterial;

            public Context(GameDatabase db, Transform root)
            {
                _db = db;
                _root = root;
                _zones = new ZoneFactory(db);
                // the ↓ / ↑ glyph is drawn into the texture (Noto Sans has no arrows)
                _dropMaterial = ZoneFactory.TransparentMaterial("ZoneMarker_Drop", TextureFactory.ZoneMarker("Drop", DropTint, -1), 10);
                _pickupMaterial = ZoneFactory.TransparentMaterial("ZoneMarker_Pickup", TextureFactory.ZoneMarker("Pickup", PickupTint, 1), 10);
            }

            public void Machine(string id, ProductDef product, Vector2 inPos, Vector2 outPos, Vector3 protoMouth,
                ItemType inType, ItemType outType, string inLabel, string outLabel, Transform blade, Transform press)
            {
                WorldLayout.ProductionSettings s = _db.world.production;
                var go = new GameObject("Machine_" + id);
                go.transform.SetParent(_root, false);
                var mouth = new GameObject("Mouth").transform;
                mouth.SetParent(go.transform, false);
                mouth.position = ProtoCoords.ToUnity(protoMouth.x, protoMouth.y, protoMouth.z);

                bool saw = product == null;
                WorldLayout.PileSettings inPile = saw ? s.sawIn : inType == ItemType.Plank ? s.plankIn : s.mineIn;
                WorldLayout.PileSettings outPile = saw ? s.sawOut : s.productOut;
                Zone input = _zones.Zone(id + "_in", go.transform, ZoneKind.Drop, inType, inPos, inPile.offset, inLabel, null, _dropMaterial);
                Zone output = _zones.Zone(id + "_out", go.transform, ZoneKind.Pickup, outType, outPos, outPile.offset, outLabel, null, _pickupMaterial);
                Zones.Add(input);
                Zones.Add(output);

                MachineVisual visual = null;
                if (blade != null || press != null)
                {
                    visual = go.AddComponent<MachineVisual>();
                    visual.Setup(blade, press);
                }
                go.AddComponent<Machine>().Setup(id, product, input, output, mouth, visual);
            }
        }
    }
}
