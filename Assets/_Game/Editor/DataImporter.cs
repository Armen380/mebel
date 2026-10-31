using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using FF.Data;
using Newtonsoft.Json.Linq;
using UnityEditor;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>
    /// Reads Design/data/*.json and creates/updates the ScriptableObjects in Assets/_Game/Data.
    /// Idempotent: assets are matched by id and updated in place, so references stay valid.
    /// </summary>
    public static class DataImporter
    {
        public const string DataRoot = "Assets/_Game/Data";
        public const string DatabasePath = DataRoot + "/GameDatabase.asset";

        public static string DesignDataDir => Path.GetFullPath(Path.Combine(Application.dataPath, "../Design/data"));

        [MenuItem("FF/Import Design Data", priority = 0)]
        public static void ImportAll()
        {
            GameDatabase db = Import();
            LocalizationImporter.Import();
            Selection.activeObject = db;
            Debug.Log($"[FF] Design data imported: {db.products.Count} products, {db.upgrades.Count} upgrades, " +
                      $"{db.pads.Count} pads, {db.skins.Count} skins, {db.tutorial.steps.Count} tutorial steps.");
        }

        public static GameDatabase Import()
        {
            EnsureFolder(DataRoot);
            var db = GetOrCreate<GameDatabase>(DatabasePath);

            db.economy = ImportEconomy(ReadObject("economy.json"));
            db.world = ImportWorld(ReadObject("world_layout.json"));
            db.products = ImportProducts(ReadArray("products.json"), db.world);
            db.upgrades = ImportUpgrades(ReadArray("upgrades.json"));
            db.pads = ImportPads((JArray)ReadObject("pads.json")["pads"], db.world);
            db.skins = ImportSkins(ReadArray("skins.json"));
            db.tutorial = ImportTutorial(ReadArray("tutorial_quest.json"));
            db.ClearCaches();

            EditorUtility.SetDirty(db);
            AssetDatabase.SaveAssets();
            return db;
        }

        // ---------- economy ----------

        static EconomyConfig ImportEconomy(JObject j)
        {
            var e = GetOrCreate<EconomyConfig>(DataRoot + "/EconomyConfig.asset");
            e.priceMultiplier = (double)j["ECON"]["price"];
            e.costMultiplier = (double)j["ECON"]["cost"];
            e.truckMultiplier = (double)j["ECON"]["truck"];
            e.truckOrderSize = (int)j["truckOrderSize"];
            e.truckAwaySeconds = (float)j["truckAwaySeconds"];

            JObject player = (JObject)j["player"];
            e.itemsPerChop = (int)player["itemsPerChop"];
            e.zoneRadius = (float)player["zoneRadius"];
            e.padRadius = (float)player["padRadius"];

            JObject storage = (JObject)j["factoryBaseStorage"];
            e.sawmillInStorage = (int)storage["sawmill"]["in_logs"];
            e.sawmillOutStorage = (int)storage["sawmill"]["out_planks"];
            e.plankFactoryInStorage = (int)storage["plank_factories"]["in"];
            e.plankFactoryOutStorage = (int)storage["plank_factories"]["out"];
            e.mineFactoryInStorage = (int)storage["clay_iron_factories"]["in"];
            e.mineFactoryOutStorage = (int)storage["clay_iron_factories"]["out"];
            e.sawmillCycleSeconds = (float)j["sawmill"]["baseCycle"];
            e.serveSeconds = (float)j["shop"]["serveSeconds"];

            JObject regrow = (JObject)j["nodeRegrowSeconds"];
            e.treeRegrowSeconds = (float)regrow["tree"];
            e.clayRegrowSeconds = (float)regrow["clay"];
            e.ironRegrowSeconds = (float)regrow["iron"];

            EditorUtility.SetDirty(e);
            return e;
        }

        // ---------- world ----------

        static WorldLayout ImportWorld(JObject j)
        {
            var w = GetOrCreate<WorldLayout>(DataRoot + "/WorldLayout.asset");
            w.fenceLineZ = (float)j["fenceLine_z"];

            JObject s1 = (JObject)j["sawmill1"];
            w.sawmill1.center = V2(s1["center"]);
            w.sawmill1.footprint = V2(s1["footprint"]);
            w.sawmill1.sawIn = V2(s1["zones"]["sawIn"]);
            w.sawmill1.sawOut = V2(s1["zones"]["sawOut"]);
            w.sawmill1.machineMouth = V3(s1["machineMouth"]);

            JObject s2 = (JObject)j["sawmill2_backyard"];
            w.sawmill2.yardX = Range(s2["yard"]["x"]);
            w.sawmill2.yardZ = Range(s2["yard"]["z"]);
            w.sawmill2.accessRoadX = Range(s2["accessRoad"]["x"]);
            w.sawmill2.accessRoadZ = Range(s2["accessRoad"]["z"]);
            w.sawmill2.building = V2(s2["building"]);
            w.sawmill2.saw2In = V2(s2["zones"]["saw2In"]);
            w.sawmill2.saw2Out = V2(s2["zones"]["saw2Out"]);

            JObject pf = (JObject)j["productFactories"];
            w.factories.rowZ = (float)pf["row_z"];
            w.factories.footprint = V2(pf["footprint"]);

            JObject forest = (JObject)j["forest"];
            ParseGrid((string)forest["grid"], out w.forest.cols, out w.forest.rows);
            w.forest.origin = V2(forest["origin"]);
            w.forest.step = V2(forest["step"]);
            w.forest.jitter = (float)forest["jitter"];

            JObject mines = (JObject)j["minesYard"];
            w.mines.x = Range(mines["x"]);
            w.mines.z = Range(mines["z"]);
            ImportRockGrid((JObject)mines["clay"], w.mines.clay);
            ImportRockGrid((JObject)mines["iron"], w.mines.iron);

            JObject shop = (JObject)j["mainShop"];
            w.mainShop.floorZ = Range(shop["floor"]["z"]);
            w.mainShop.doorX = Range(shop["door"]["x"]);
            w.mainShop.doorZ = (float)shop["door"]["z"];
            w.mainShop.shelfPileZ = (float)shop["shelves"]["pileZ"];
            w.mainShop.shelfZoneZ = (float)shop["shelves"]["zoneZ"];
            w.mainShop.registersX = Floats(shop["registers"]["x"]);
            w.mainShop.stallCenterZ = (float)shop["registers"]["stallCenterZ"];
            w.mainShop.expansionPad = V2(shop["expansionPad"]);

            JObject annex = (JObject)j["materialsShop"];
            w.materialsShop.x = Range(annex["x"]);
            w.materialsShop.z = Range(annex["z"]);
            w.materialsShop.doorX = Range(annex["door"]["x"]);
            w.materialsShop.shelfSinkX = (float)annex["shelves"]["sink"];
            w.materialsShop.shelfMaterialX = (float)annex["shelves"]["material"];
            w.materialsShop.registersX = Floats(annex["registers"]);

            JObject del = (JObject)j["delivery"];
            w.delivery.baysX = Floats(del["bays_x"]);
            w.delivery.truckParkZ = (float)del["truckParkZ"];
            w.delivery.truckLaneZ = (float)del["truckLaneZ"];
            w.delivery.dockZoneZ = (float)del["dockZoneZ"];
            w.delivery.truckPad = V2(del["truckPad"]);
            w.delivery.parkingPad = V2(del["parkingPad"]);

            JObject road = (JObject)j["road"];
            w.road.z = Range(road["z"]);
            w.road.laneWestboundZ = (float)road["laneWestbound_z"];
            w.road.laneEastboundZ = (float)road["laneEastbound_z"];
            w.road.sidewalkZ = Range(road["sidewalk_z"]);
            w.road.zebraX = (float)road["zebraCrossing_x"];

            JObject park = (JObject)j["carPark"];
            w.carPark.x = Range(park["x"]);
            w.carPark.z = Range(park["z"]);
            w.carPark.aisleZ = (float)park["aisleZ"];
            w.carPark.slotZ = (float)park["slotZ"];
            w.carPark.drivewayX = (float)park["drivewayX"];

            JObject paths = (JObject)j["customerPaths"];
            w.customerPaths.spawn = V2(paths["spawn"]);
            w.customerPaths.exit = V2(paths["exit"]);
            w.customerPaths.mainDoorOut = V2(paths["mainDoorOut"]);
            w.customerPaths.mainDoorIn = V2(paths["mainDoorIn"]);
            w.customerPaths.annexDoorOut = V2(paths["annexDoorOut"]);
            w.customerPaths.annexDoorIn = V2(paths["annexDoorIn"]);

            JObject dream = (JObject)j["dreamHouse"];
            w.dreamHouse.plotX = Range(dream["plot"]["x"]);
            w.dreamHouse.plotZ = Range(dream["plot"]["z"]);
            w.dreamHouse.accessRoadX = (float)dream["accessRoad"]["x"];
            w.dreamHouse.accessRoadZ = Range(dream["accessRoad"]["z"]);
            w.dreamHouse.archZ = (float)dream["arch_z"];
            w.dreamHouse.foundationCenter = V2(dream["foundation"]["center"]);
            w.dreamHouse.foundationSize = V2(dream["foundation"]["size"]);
            w.dreamHouse.billboard = V2(dream["billboard"]);
            w.dreamHouse.workArea = V2(dream["workArea"]);

            JObject bounds = (JObject)j["playerBounds"];
            w.playerBounds.x = Range(bounds["x"]);
            w.playerBounds.z = Range(bounds["z"]);

            EditorUtility.SetDirty(w);
            return w;
        }

        static void ImportRockGrid(JObject j, WorldLayout.GridSettings grid)
        {
            ParseGrid((string)j["grid"], out grid.cols, out grid.rows);
            grid.origin = V2(j["origin"]);
            grid.step = V2(j["step"]);
        }

        /// <summary>"5 cols x 7 rows" or "4x4" → (cols, rows).</summary>
        static void ParseGrid(string text, out int cols, out int rows)
        {
            MatchCollection m = Regex.Matches(text, @"\d+");
            if (m.Count < 2) throw new InvalidDataException($"Cannot parse grid '{text}'.");
            cols = int.Parse(m[0].Value);
            rows = int.Parse(m[1].Value);
        }

        // ---------- products ----------

        static List<ProductDef> ImportProducts(JArray items, WorldLayout world)
        {
            var list = new List<ProductDef>();
            var byId = new Dictionary<string, ProductDef>();
            for (int i = 0; i < items.Count; i++)
            {
                JObject j = (JObject)items[i];
                string id = (string)j["id"];
                var p = GetOrCreate<ProductDef>($"{DataRoot}/Products/{id}.asset");
                p.id = id;
                p.item = ParseItem(id);
                p.nameKey = (string)j["nameKey"];
                p.signKey = (string)j["signKey"];
                p.input = ParseItem((string)j["input"]);
                p.inputPerCycle = (int)j["inputPerCycle"];
                p.cycleSeconds = (float)j["cycleSeconds"];
                p.basePrice = (int)j["basePrice"];
                p.xpPerSale = (int)j["xpPerSale"];
                p.unlockLevel = (int)j["unlockLevel"];
                p.factoryCost = (long)j["factoryCost"];
                p.factoryX = (float)j["factoryX"];
                p.sellsIn = (string)j["sellsIn"] == "materials_shop" ? ShopKind.Materials : ShopKind.Main;
                p.wallColor = Hex((string)j["wallColor"]);
                p.roofColor = Hex((string)j["roofColor"]);
                // prototype: p.shelfX = sink ? 48 : material ? 50.6 : 4.6 + i*2.8
                p.shelfX = id == "sink" ? world.materialsShop.shelfSinkX
                    : id == "material" ? world.materialsShop.shelfMaterialX
                    : world.mainShop.shelfBaseX + i * world.mainShop.shelfStepX;
                byId[id] = p;
                list.Add(p);
            }
            for (int i = 0; i < items.Count; i++)
            {
                string with = (string)items[i]["unlocksWith"];
                list[i].unlocksWith = string.IsNullOrEmpty(with) ? null : byId[with];
                EditorUtility.SetDirty(list[i]);
            }
            return list;
        }

        // ---------- upgrades, pads, skins, tutorial ----------

        static List<UpgradeDef> ImportUpgrades(JArray items)
        {
            var list = new List<UpgradeDef>();
            foreach (JObject j in items)
            {
                string id = (string)j["id"];
                var u = GetOrCreate<UpgradeDef>($"{DataRoot}/Upgrades/{id}.asset");
                u.id = id;
                u.groupKey = (string)j["group"];
                u.maxLevel = (int)j["max"];
                u.baseCost = (long)j["baseCost"];
                u.costMultiplier = (double)j["costMultiplier"];
                u.requiresShopLevel = j["requiresShopLevel"]?.Type == JTokenType.Integer ? (int)j["requiresShopLevel"] : 0;
                u.requiresPlumbing = (bool)j["requiresPlumbing"];
                EditorUtility.SetDirty(u);
                list.Add(u);
            }
            return list;
        }

        static List<PadDef> ImportPads(JArray items, WorldLayout world)
        {
            var list = new List<PadDef>();
            foreach (JObject j in items)
            {
                string id = (string)j["id"];
                var p = GetOrCreate<PadDef>($"{DataRoot}/Pads/{id}.asset");
                p.id = id;
                // "reg" has a text position: it sits on the next free register slot (prototype placeRegPad()),
                // which on a fresh save is register 1.
                p.protoPos = j["pos"].Type == JTokenType.Array
                    ? V2(j["pos"])
                    : new Vector2(world.mainShop.registersX[1], world.mainShop.stallCenterZ);
                p.glyph = (string)j["glyph"];
                p.baseCost = (long)j["baseCost"];
                p.costMultiplier = j["costMultiplier"]?.Type is JTokenType.Float or JTokenType.Integer ? (double)j["costMultiplier"] : 1;
                p.maxLevel = (int)j["maxLevel"];
                p.effect = (string)j["effect"];
                p.visibleWhen = (string)j["visibleWhen"];
                p.doneKey = PadDoneKey(id);
                EditorUtility.SetDirty(p);
                list.Add(p);
            }
            return list;
        }

        /// <summary>Prototype addPad({done}) per pad family; pads.json does not carry it.</summary>
        static string PadDoneKey(string id)
        {
            if (id.EndsWith("_speed")) return "done.speed";
            if (id.EndsWith("_qty")) return "done.floor";
            if (id == "saw2_buy") return "done.saw";
            if (id.EndsWith("_buy")) return "done.factory";
            switch (id)
            {
                case "reg":
                case "reg_annex": return "done.reg";
                case "shop": return "done.shop";
                case "truck": return "done.truck";
                case "parking": return "done.parking";
                default: return "done.generic";
            }
        }

        static List<SkinDef> ImportSkins(JArray items)
        {
            var list = new List<SkinDef>();
            foreach (JObject j in items)
            {
                string id = (string)j["id"];
                var s = GetOrCreate<SkinDef>($"{DataRoot}/Skins/{id}.asset");
                s.id = id;
                s.nameKey = (string)j["nameKey"];
                s.shirt = Hex((string)j["shirt"]);
                s.pants = Hex((string)j["pants"]);
                s.hat = Hex((string)j["hat"]);
                s.hatType = ParseEnum<HatType>((string)j["hatType"]);
                s.unlockTotalEarned = (long)j["unlockTotalEarned"];
                EditorUtility.SetDirty(s);
                list.Add(s);
            }
            return list;
        }

        /// <summary>
        /// Turns the design sentences of tutorial_quest.json ("drop logs on sawIn", "saw_speed pad", …) into
        /// trigger / target fields; prototype zone ids (sawIn, in_chair, …) become scene zone ids (saw_in, chair_in, …).
        /// </summary>
        public static void ParseTutorialStep(TutorialDef.Step step)
        {
            string on = step.completeOn.Trim();
            string[] words = on.Split(' ');
            if (on.StartsWith("drop ") || on.StartsWith("pick "))
            {
                step.trigger = on.StartsWith("drop ") ? TutorialTrigger.Drop : TutorialTrigger.Pick;
                step.triggerId = ZoneId(words[words.Length - 1]);
            }
            else if (on.Contains("chop")) step.trigger = TutorialTrigger.Chop;
            else if (on.Contains("cash")) step.trigger = TutorialTrigger.Cash;
            else if (on.Contains("pad")) step.trigger = TutorialTrigger.Pad;
            else throw new System.FormatException($"Unknown tutorial trigger '{on}'.");

            string target = step.arrowTarget.Trim();
            if (target.Contains("tree"))
            {
                step.target = TutorialTarget.NearestTree;
                step.targetId = "";
            }
            else if (target.EndsWith(" pad"))
            {
                step.target = TutorialTarget.Pad;
                step.targetId = target.Substring(0, target.Length - " pad".Length);
            }
            else
            {
                step.target = TutorialTarget.Zone;
                step.targetId = ZoneId(target.Replace(" zone", ""));
            }
        }

        /// <summary>Prototype zone id → scene zone id.</summary>
        public static string ZoneId(string protoId)
        {
            switch (protoId)
            {
                case "sawIn": return "saw_in";
                case "sawOut": return "saw_out";
                case "saw2In": return "saw2_in";
                case "saw2Out": return "saw2_out";
            }
            if (protoId.StartsWith("in_")) return protoId.Substring(3) + "_in";
            if (protoId.StartsWith("out_")) return protoId.Substring(4) + "_out";
            return protoId; // shelf_chair, cash0, …
        }

        static TutorialDef ImportTutorial(JArray items)
        {
            var t = GetOrCreate<TutorialDef>(DataRoot + "/Tutorial.asset");
            t.steps.Clear();
            foreach (JObject j in items)
            {
                var step = new TutorialDef.Step
                {
                    textKey = (string)j["key"],
                    completeOn = (string)j["completeOn"],
                    arrowTarget = (string)j["arrowTarget"],
                };
                ParseTutorialStep(step);
                t.steps.Add(step);
            }
            EditorUtility.SetDirty(t);
            return t;
        }

        // ---------- helpers ----------

        public static JObject ReadObject(string file) => JObject.Parse(File.ReadAllText(Path.Combine(DesignDataDir, file)));

        public static JArray ReadArray(string file) => JArray.Parse(File.ReadAllText(Path.Combine(DesignDataDir, file)));

        static ItemType ParseItem(string id) => ParseEnum<ItemType>(id);

        static T ParseEnum<T>(string value) where T : struct =>
            System.Enum.TryParse(value, true, out T result)
                ? result
                : throw new InvalidDataException($"Unknown {typeof(T).Name} '{value}'.");

        static Vector2 V2(JToken t) => new Vector2((float)t[0], (float)t[1]);

        static Vector3 V3(JToken t) => new Vector3((float)t[0], (float)t[1], (float)t[2]);

        static ProtoRange Range(JToken t)
        {
            float a = (float)t[0], b = (float)t[1];
            return new ProtoRange(Mathf.Min(a, b), Mathf.Max(a, b));
        }

        static float[] Floats(JToken t)
        {
            var arr = (JArray)t;
            var result = new float[arr.Count];
            for (int i = 0; i < arr.Count; i++) result[i] = (float)arr[i];
            return result;
        }

        static Color Hex(string hex) =>
            ColorUtility.TryParseHtmlString(hex, out Color c) ? c : throw new InvalidDataException($"Bad colour '{hex}'.");

        public static T GetOrCreate<T>(string path) where T : ScriptableObject
        {
            var asset = AssetDatabase.LoadAssetAtPath<T>(path);
            if (asset != null) return asset;
            EnsureFolder(Path.GetDirectoryName(path).Replace('\\', '/'));
            asset = ScriptableObject.CreateInstance<T>();
            AssetDatabase.CreateAsset(asset, path);
            return asset;
        }

        public static void EnsureFolder(string path)
        {
            if (AssetDatabase.IsValidFolder(path)) return;
            string parent = Path.GetDirectoryName(path).Replace('\\', '/');
            EnsureFolder(parent);
            AssetDatabase.CreateFolder(parent, Path.GetFileName(path));
        }
    }
}
