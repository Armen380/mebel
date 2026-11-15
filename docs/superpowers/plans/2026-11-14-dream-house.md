# Dream House (M10) Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal.** Build the Dream House on the plot east of the factories:
- four paid construction stages;
- four rooms and a yard with fixed slots, filled with the player's own factory furniture and with Home Store items;
- a Home Store catalog;
- a cut-away interior view;
- a comfort score that raises sale prices.

All of it is in the Armenian tuff style.

**Architecture.**
- **Data.** Numbers live in `Design/data/dream_house.json`, imported into a new `HomeDef` ScriptableObject. Stages are four
  new `pads.json` pads.
- **Pure logic.** Slots, storage, comfort, buying, room gifts and stage gating live in `FF.Gameplay.Home.HomeRules` /
  `HomeState`, covered by EditMode tests.
- **Service.** `HomeService` is registered by `GameInstaller` and implements the Core interfaces `IHomeStore` and
  `IHomeBonus`.
- **Adapters.** These are thin MonoBehaviours: slots, counter, cut-away, HUD chip, catalog panel.
- **Editor.** Builders (`HouseBuilder`) generate the house, the store and the slot visuals into Game.unity.

**Tech Stack.** Unity 6000.6.7f1 URP, C#, Unity Localization, TextMeshPro, Cinemachine 3, Newtonsoft (Editor import),
Unity Test Framework (EditMode). Unity CLI: `~/.unity/bin/unity`.

**Spec.** `docs/superpowers/specs/2026-11-14-dream-house-design.md`

## Global Constraints

- **Code layout.**
  - Assemblies `FF.Core ← FF.Data ← FF.Gameplay ← FF.UI`. FF.UI reaches gameplay only through Core interfaces and
    `GameEvents`.
  - `FF.Save` maps the save.
- **Coordinates.** Prototype coordinates in all JSON. Convert only through `ProtoCoords` / Blockout helpers.
- **Per-frame code.** No LINQ, closures, string building or `Find*`. Cache references.
- **Strings.** Every player-facing string goes through table `Game` with keys in `localization_{en,ru,hy}.json`, then
  `FF/Import Design Data`. The Armenian text is drafted by Claude and flagged for the user's review.
- **Money.** Format `$1.2K`. Stage pads use the pad price formula (×1.25 ECON). Catalog prices in
  `dream_house.json` are final dollars (no ECON).
- **Save.** Version becomes 5. A v4 save loads with an empty home and no stages built.
- **Art.** Low-poly primitives with shared `MaterialPalette` materials. New colours:
  - tuff `#d9967f`;
  - tuff trim `#b9735f`;
  - roof `#c4643f`;
  - walnut `#7a4a2b`;
  - pomegranate `#b3263a`;
  - vine `#5f9a3a`.
- **Scope.** No physics, no new packages, 60 fps.
- **Unity workflow.**
  - Wait for compile before Play Mode: poll the new type by reflection plus `!EditorApplication.isCompiling`.
  - Patch Game.unity from a fresh `OpenScene`.
  - Back up and restore the user's save around Play Mode automation.
  - Reset `runInBackground` afterwards.
- **Git.**
  - Branch `m10-dream-house`.
  - Stage files explicitly, never `git add -A`.
  - Commit messages end with `Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>`.
- **Test command.**
  `~/.unity/bin/unity command test run --mode EditMode --format json > <scratch>/t.json`, then grep `"Failed"`.
  Expected: 0 failed.

**Spec refinement (Claude's call).** Stage ownership is stored as the four stage pads' levels, which are already
saved in `pads`. No `owned.house_*` keys. `WorldStateSnapshot.HouseStage` (0–4) is derived from them in
`WorldStateSync.Apply`.

## Review Focus

1. **Carrying several products onto the plot.**
   - A stack of 5 chairs next to two empty chair slots fills exactly those two. The other 3 stay in hand.
   - Products never go into a slot of another type.
   - Test: `HomeRulesTests.FactorySlot_AcceptsOnlyItsProduct_OnePerSlot` (Task 2).
2. **Buying more than can ever be placed.**
   - Owned count (storage + placed) of a group can't exceed that group's slot count. The Buy button disables at the
     cap.
   - Test: `HomeRulesTests.Buy_CappedBySlotCount` (Task 2).
3. **A room gift paid twice** after save/load or a variant swap.
   - Tests: `HomeRulesTests.RoomGift_PaidOnce_EvenAfterSwap` (Task 2) and `HomeSaveTests.RewardedRooms_RoundTrip`
     (Task 3).
4. **The player trapped by the new walls,** or by a stage built while standing inside the footprint.
   - Door gaps stay open. A player inside a wall rect after a rebuild is pushed out, never stuck.
   - Test: `BlockerSetTests.HouseWalls_DoorGapIsWalkable` (Task 5).
5. **Language switch while the catalog is open,** and catalog rows for items not yet available.
   - Rows re-localize. Unavailable rows show the requirement and can't be bought.
   - Test: `HomeRulesTests.Buy_RefusedWhenAreaClosed` (Task 2); the language case is checked in Play Mode (Task 11).

---

### Task 1: Dream-house data, import and strings

**Files:**
- Create: `Design/data/dream_house.json`
- Create: `Assets/_Game/Scripts/Data/HomeDef.cs`
- Modify: `Assets/_Game/Scripts/Data/GameDatabase.cs` (add `public HomeDef home;`)
- Modify: `Assets/_Game/Editor/DataImporter.cs` (`ImportHome`, called from `Import()`)
- Modify: `Design/data/pads.json`: four pads `house_found` (1600), `house_walls` (8000), `house_roof` (24000),
  `house_windows` (60000). Each has costMultiplier 1, maxLevel 1, glyph `⌂`, the same `pos` in front of the door
  (≈ (81, −11.2)) and `visibleWhen` `"previous house stage"`.
- Modify: `Design/data/world_layout.json`:
  - `dreamHouse.house`: footprint rect, front-wall z, door width 1.6, roof height;
  - `dreamHouse.store`: building rect on the work area, counter point;
  - `blockers.houseWalls`: wall rects with gaps for the front door and three inner doorways.
- Modify: `Assets/_Game/Scripts/Data/WorldLayout.cs` (fields for the above).
- Modify: `Design/data/localization_{en,ru,hy}.json`.
- Test: `Assets/_Game/Tests/EditMode/HomeDataTests.cs`

**Interfaces:**
- Produces (FF.Data):

```csharp
public sealed class HomeDef : ScriptableObject {
  public double comfortBonusPerPoint = 0.001;   // max comfort 200 → +20 %
  public List<AreaDef> areas; public List<SlotDef> slots; public List<HomeItemDef> items;
  public HomeItemDef Item(string id); public AreaDef Area(string id); public SlotDef Slot(string id);
  [Serializable] public sealed class AreaDef { public string id, nameKey; public int requiresStage; public long gift; }
  [Serializable] public sealed class SlotDef { public string id, area, group; public ItemType product; public int comfort;
                                               public Vector2 protoPos; public float yaw; }   // product != None ⇒ factory slot, group empty
  [Serializable] public sealed class HomeItemDef { public string id, group, nameKey, icon; public long price; public int comfort; }
}
```

- `PadDef.visibleWhen == "previous house stage"` is read by Task 5.

**Content.** Builder's values inside these bounds.

- **Areas.**

  | Area | requiresStage | gift |
  |---|---|---|
  | `living` | 2 | $5K |
  | `kitchen` | 2 | $15K |
  | `bedroom` | 2 | $40K |
  | `bathroom` | 2 | $500K |
  | `yard` | 1 | $100K |

- **32 slots,** following the spec table:
  - living: `sofa`, `table`, `chair1`, `chair2`, `carpet`, `lamp`, `tv`, `painting`, `plant`;
  - kitchen: `kitchen`, `chair1`, `chair2`, `fridge`, `stove`, `bowl`;
  - bedroom: `wardrobe`, `bed`, `nightstand`, `carpet`, `lamp`;
  - bathroom: `sink`, `tub`, `mirror`, `towel`;
  - yard: `pergola`, `tree`, `flowers1`, `flowers2`, `bench`, `fountain`, `pool`, `lamps`.

  Slot ids are `<area>_<name>`. Factory slots have a comfort value. Store slots have comfort 0, because their comfort
  comes from the placed item.
- **Catalog groups:** carpet ×3 variants (`carpet_vishap`, `carpet_garden`, `carpet_star`), lamp ×2, painting ×2
  (`painting_ararat`, `painting_garni`), flowers ×2 (`flowers_rose`, `flowers_tulip`). Every other group has one item.
- **Prices:** $300 (lamp) to $1.2M (pool).
- **Comfort:** tuned so the best possible house (all slots, best variant in each) totals **200**.
- **Localization keys:**
  - `home.stage.<id>`, `home.area.<id>`, `home.item.<id>`;
  - `home.store.title`, `home.tab.house`, `home.tab.yard`, `home.buy`, `home.owned` (`{n}`), `home.placed`,
    `home.needs` (`{stage}`), `home.comfort` (`{n}`), `home.bonus` (`{p}`);
  - `t.roomDone` (`{room}`, `{gift}`), `sign.homeStore`;
  - pad done keys `done.house`;
  - changed `un.dream.s` ("build your house now").
- **Pad done key.** `DataImporter.PadDoneKey` maps `house_*` to `done.house`.

- [ ] **Step 1: Write the failing test** `HomeDataTests`:
  - `Import_HasAreasSlotsItems`: 5 areas, 32 slots, `Slot("living_sofa").product == ItemType.Sofa`.
  - `EveryStoreSlotGroupHasAnItem`: for each slot with `product == None`, some item has `group == slot.group`.
  - `BestHouseComfortIs200`: sum over slots of the factory comfort or the max comfort of the group's items == 200.
  - `HousePadsExist`: `db.Pad("house_found").baseCost == 1600`, … `house_windows` 60000.
  - `HomeKeysInAllLocales`: every `nameKey` in the three locale JSON files.
- [ ] **Step 2: Run the tests.** Expected: FAIL (no `HomeDef`).
- [ ] **Step 3: Implement.** `HomeDef`, the JSON files, `ImportHome` (asset `Assets/_Game/Data/Home.asset`), the
  WorldLayout fields and the strings. Run `FF/Import Design Data` via
  `unity command script eval --code "FF.Editor.DataImporter.ImportAll();"`.
- [ ] **Step 4: Run the tests.** Expected: all pass, 0 failed overall.
- [ ] **Step 5: Commit.**
  `git add Design/data/dream_house.json Design/data/pads.json Design/data/world_layout.json Design/data/localization_*.json Assets/_Game/Scripts/Data/HomeDef.cs* Assets/_Game/Scripts/Data/GameDatabase.cs Assets/_Game/Scripts/Data/WorldLayout.cs Assets/_Game/Editor/DataImporter.cs Assets/_Game/Data/Home.asset* Assets/_Game/Data/Pads/house_* Assets/_Game/Localization Assets/_Game/Tests/EditMode/HomeDataTests.cs*`
  (check `git status` for the exact new asset paths)
  → `M10: dream house data, import and strings`

### Task 2: Pure home logic

**Files:**
- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeState.cs`
- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeRules.cs`
- Test: `Assets/_Game/Tests/EditMode/HomeRulesTests.cs`

**Interfaces:**
- Consumes: `HomeDef` (Task 1), `ItemType`.
- Produces:

```csharp
public sealed class HomeState {
  public readonly Dictionary<string,string> Placed;   // slotId → item id (factory slots: product id, e.g. "sofa")
  public readonly Dictionary<string,int> Storage;     // item id → count
  public readonly HashSet<string> RewardedAreas;
}
public static class HomeRules {
  bool IsAreaOpen(HomeDef d, string areaId, int stage);
  bool CanPlaceFactory(HomeDef d, HomeState s, HomeDef.SlotDef slot, int stage, ItemType carried);
  void PlaceFactory(HomeState s, HomeDef.SlotDef slot);                       // Placed[slot.id] = product id (lower-case)
  bool TryPlaceFromStorage(HomeDef d, HomeState s, HomeDef.SlotDef slot, int stage, out string itemId); // first item of slot.group in catalog order with Storage > 0
  int  OtherVariants(HomeDef d, HomeState s, HomeDef.SlotDef slot, List<string> into); // storage items of the group ≠ placed
  bool Swap(HomeState s, HomeDef.SlotDef slot, string itemId);                 // placed → storage, itemId from storage → placed
  int  Owned(HomeDef d, HomeState s, string group);                           // storage + placed of the group
  bool IsItemAvailable(HomeDef d, HomeDef.HomeItemDef item, int stage);        // some slot of item.group is in an open area
  bool CanBuy(HomeDef d, HomeState s, HomeDef.HomeItemDef item, int stage, long money); // available, money ≥ price, Owned(group) < slots of group
  void Buy(HomeState s, HomeDef.HomeItemDef item);                            // Storage[item.id]++
  int  Comfort(HomeDef d, HomeState s);
  double SaleMultiplier(HomeDef d, int comfort) => 1 + d.comfortBonusPerPoint * comfort;
  bool IsAreaComplete(HomeDef d, HomeState s, string areaId);
  bool TryClaimGift(HomeDef d, HomeState s, string areaId, out long gift);    // complete && not rewarded → add to RewardedAreas
}
```

- [ ] **Step 1: Write the failing tests** (hand-built `HomeDef` via `ScriptableObject.CreateInstance`, 2 areas,
  a few slots):
  - `FactorySlot_AcceptsOnlyItsProduct_OnePerSlot`: Sofa slot refuses Chair. After `PlaceFactory`,
    `CanPlaceFactory(...Sofa)` is false.
  - `Slots_ClosedUntilAreaStage`: interior slot with stage 1 → false; stage 2 → true. Yard opens at stage 1.
  - `Buy_CappedBySlotCount`: group `carpet` has 2 slots. After buying 2 carpets (any variants),
    `CanBuy` is false even with money.
  - `Buy_RefusedWhenAreaClosed`: `IsItemAvailable(bed, stage 1)` is false.
  - `StorageItem_PlacedThenSwapped_ComfortFollowsPlacedItem`.
  - `RoomGift_PaidOnce_EvenAfterSwap`: complete area → gift once; swap → `TryClaimGift` false.
  - `SaleMultiplier_200Comfort_Is1_2`.
- [ ] **Step 2: Run the tests.** Expected: FAIL (types missing).
- [ ] **Step 3: Implement `HomeState` and `HomeRules`.** Static, allocation-free except the caller's list.
- [ ] **Step 4: Run the tests.** Expected: PASS, 0 failed overall.
- [ ] **Step 5: Commit.** The Home folder and the test → `M10: home rules (slots, storage, comfort, gifts)`

### Task 3: Save v5

**Files:**
- Modify: `Assets/_Game/Scripts/Save/SaveData.cs`
  - `CurrentVersion = 5`;
  - `public HomeSave home = new HomeSave();` with
    `class HomeSave { Dictionary<string,string> slots; Dictionary<string,int> storage; List<string> rooms; }`.
- Modify: `Assets/_Game/Scripts/Save/SaveMapper.cs`: `Capture(..., HomeState home)` and `Apply(..., HomeState home)`.
  Overloads keep the old signatures with `home = null` working.
- Modify: `Assets/_Game/Scripts/Save/SaveSerializer.cs`: `Migrate` comment for v5 (a missing `home` deserializes to
  the default).
- Modify: `Assets/_Game/Scripts/Save/SaveService.cs`: pass `Services.Get<HomeService>().State`.
- Test: `Assets/_Game/Tests/EditMode/HomeSaveTests.cs`

**Interfaces:** Consumes `HomeState` (Task 2) and `HomeService.State` (Task 4). Task 4 produces `HomeService`; the
save wiring step in `SaveService` runs after Task 4. Order the commits: tests and mapper here, the `SaveService` line
in Task 4.

- [ ] **Step 1: Write the failing tests:**
  - `V4Save_LoadsWithEmptyHome`: JSON without `home`, `version: 4` → `home.slots.Count == 0`, `version == 5`.
  - `Home_RoundTrip`: placed, storage and rooms survive Capture → Serialize → Deserialize → Apply.
  - `RewardedRooms_RoundTrip`.
- [ ] **Step 2: Run the tests.** Expected: FAIL.
- [ ] **Step 3: Implement** the SaveData, Mapper and Serializer changes.
- [ ] **Step 4: Run the tests.** Expected: PASS, including the existing `LegacySaveTests`.
- [ ] **Step 5: Commit.** → `M10: save v5 with home state`

### Task 4: HomeService, sale bonus and room gifts

**Files:**
- Create: `Assets/_Game/Scripts/Core/IHomeStore.cs`:

```csharp
public interface IHomeBonus { double SaleMultiplier { get; } }
public interface IHomeStore {
  int Stage { get; } int Comfort { get; } int StorageCount { get; }
  bool IsAvailable(string itemId); bool CanBuy(string itemId); int OwnedInGroup(string itemId); bool IsPlaced(string itemId);
  bool Buy(string itemId);
  bool Swap(string slotId, string itemId);
}
```

- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeService.cs`
  - Plain class: `HomeService(HomeDef def, GameProgress progress, WorldStateSnapshot state)` implementing both
    interfaces.
  - `HomeState State`.
  - `bool TryPlaceFactory(string slotId, ItemType carried)`.
  - `bool TryPlaceFromStorage(string slotId)`.
  - After every placement: `TryClaimGift` → `progress.AddMoney(gift)`, toast `t.roomDone`, and confetti at the room
    centre via the existing effects burst.
  - Raises `GameEvents.RaiseHomeChanged()`.
- Modify: `Assets/_Game/Scripts/Core/GameEvents.cs`:
  - `event Action HomeChanged`;
  - `event Action<string> HomeVariantPicker` (slot id; null = hide);
  - `event Action<bool> HomeStoreOpen`;
  - raisers, plus `Reset` clearing them.
- Modify: `Assets/_Game/Scripts/Data/EconomyConfig.cs`:
  `long SalePrice(int basePrice, int qualityLevel, double homeMultiplier)` =
  `RoundToLong(base·price·(1+q·quality)·home/10)·10`. The two-argument overload calls it with 1.
- Modify: `Assets/_Game/Scripts/Gameplay/Shop/CustomerDirector.cs:194` and
  `Assets/_Game/Scripts/Gameplay/Delivery/DeliveryRules.cs:61`: pass `IHomeBonus.SaleMultiplier`.
  `DeliveryRules` gets a `double homeMultiplier` parameter. Update its callers.
- Modify: `Assets/_Game/Scripts/Gameplay/Bootstrap/GameInstaller.cs`: register `HomeService` as itself,
  `IHomeStore` and `IHomeBonus`.
- Modify: `SaveService` (the Task 3 wiring line).
- Test: extend `Assets/_Game/Tests/EditMode/EconomyConfigTests.cs` and `DeliveryTests.cs`.

- [ ] **Step 1: Write the failing tests:**
  - `SalePrice_WithHomeMultiplier`: `SalePrice(500, 0, 1.2) == 510`; `SalePrice(500, 0, 1.0) == 430`, unchanged.
  - `TruckPayout_UsesHomeMultiplier`.
- [ ] **Step 2: Run the tests.** Expected: FAIL.
- [ ] **Step 3: Implement** the above.
- [ ] **Step 4: Run all EditMode tests.** Expected: 0 failed.
- [ ] **Step 5: Commit.** → `M10: home service, comfort sale bonus, room gifts`

### Task 5: Construction stages, world state and walls

**Files:**
- Modify: `Assets/_Game/Scripts/Gameplay/Pads/PadRules.cs`: `PadRule.AfterPad`. Visible when the `ownerOwned`
  argument is true; the caller computes it.
- Modify: `Assets/_Game/Scripts/Gameplay/Pads/UpgradePad.cs`: for `AfterPad`, `ownerOwned` is
  `owner` empty ? tutorialDone : `_progress.GetLevel(owner) >= 1`. Use the same tutorial-done test as
  `UnlockService`.
- Modify: `Assets/_Game/Scripts/Gameplay/World/WorldStateSnapshot.cs`: `public int HouseStage;` and
  `public static readonly string[] HouseStagePads = { "house_found", "house_walls", "house_roof", "house_windows" };`.
- Modify: `Assets/_Game/Scripts/Gameplay/World/WorldStateSync.cs`: `HouseStage` = the count of leading stage pads with
  level ≥ 1.
- Modify: `Assets/_Game/Scripts/Gameplay/World/BlockerSet.cs`: add `layout.blockers.houseWalls` when
  `HouseStage >= 2`.
- Modify: `Assets/_Game/Scripts/Gameplay/Pads/PadRewards.cs`: a `house_*` pad → `WorldStateSync.Apply`,
  `_collision.Rebuild`, toast (`home.stage.<id>`, `done.house`), `GameEvents.RaiseHomeChanged()`.
- Modify: `Assets/_Game/Editor/World/ShopBuilder.cs`: `AddPad` for the four stages with `PadRule.AfterPad`, owner =
  the previous pad id (empty for `house_found`).
- Modify: `Assets/_Game/Scripts/Gameplay/Unlocks/UnlockService.cs`: the dream card target is the `house_found` pad
  position.
- Test: `BlockerSetTests`, `UpgradeTests` (or a new `HouseStageTests.cs`).

- [ ] **Step 1: Write the failing tests:**
  - `HouseStage_CountsLeadingStagePads`: found=1, walls=0, roof=1 → 1.
  - `HouseWalls_OnlyFromWallsStage`: stage 1 has no wall rects; stage 2 has them.
  - `HouseWalls_DoorGapIsWalkable`: the door centre and each inner doorway centre (from layout) are inside no blocker.
    A point pushed out from inside a wall ends outside every rect.
  - `AfterPad_VisibleOnlyAfterPrevious`.
- [ ] **Step 2: Run the tests.** Expected: FAIL.
- [ ] **Step 3: Implement.**
- [ ] **Step 4: Run all EditMode tests.** Expected: 0 failed.
- [ ] **Step 5: Commit.** → `M10: house stage pads, walls and world state`

### Task 6: House, yard and store visuals (Editor)

**Files:**
- Create: `Assets/_Game/Editor/World/HouseBuilder.cs`, called from `LayoutBuilder.BuildDreamPlot`. It builds under
  `DreamHousePlot`:
  - `Stage1..Stage4` groups: tuff slab and steps; walls with arched openings and inner walls; hipped terracotta roof;
    door, window frames and balcony rail. Each group carries `StageVisual`.
  - `Roof` and `FrontWall` sub-objects referenced for Task 9.
  - The Home Store building (tuff, arched front, counter, `sign.homeStore`) with `StageVisual` stage 1.
- Create: `Assets/_Game/Scripts/Gameplay/Home/StageVisual.cs`
  - `[SerializeField] int stage; GameObject root; GameObject[] hideWhenBuilt`.
  - Shows when `state.HouseStage >= stage`, popping in via the existing `BuildingVisual.PlayPop`.
  - Hides the stakes, strings, billboard and `DreamSoon` chip at the stages given.
- Modify: `Assets/_Game/Editor/Art/LowPolyMeshFactory.cs`: `Arch(float width, float height, float depth, int segments)`
  → `Art/Meshes/Arch.asset`.
- Modify: `Assets/_Game/Editor/Art/TextureFactory.cs`:
  - `CarpetTexture(string id)`: 3 ornament patterns, 256 px, `Art/Textures/Carpet_*.png`, LFS;
  - line icons for the catalog items (same `LineIcon` style as `HudBuilder.ProductIcon`).
- Modify: `Assets/_Game/Scripts/Data/MaterialPalette` colours: add the Global Constraints colours through
  `MaterialPaletteEditor` (toned like the rest).

- [ ] **Step 1: Build.** Run `FF/Build World Blockout` (or the full `Build Game Scene`) via the CLI.
  `git diff --stat` of Game.unity shows only the plot changes.
- [ ] **Step 2: Check it in Play Mode.** Back up the save, use DevCheats to set money and buy the stages, then take
  screenshots of each stage from the play camera and from an aerial pullback. Compare with the spec style. Console
  shows 0 errors.
- [ ] **Step 3: Commit** the builder, meshes, textures, palette and Game.unity →
  `M10: Armenian house, yard and home store visuals`

### Task 7: Slots in the world

**Files:**
- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeSlot.cs`
  - `[SerializeField] string slotId; GameObject ghost; Transform modelRoot` plus a model per accepted item id
    (factory: one).
  - Factory slots own a `Zone` (Drop, accepts `slot.product`, capacity 1, active while open and empty).
- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeSlotSystem.cs`. One Update loop over all slots, like `PadSystem`:
  - factory slot: when its zone stack has a settled item → pop it, return it to `ItemPool`,
    `HomeService.TryPlaceFactory`;
  - store slot: player within `padRadius`, still ≥ `padStillSeconds`, empty, and storage has its group → 
    `TryPlaceFromStorage`, pop the model, play the sound;
  - placed store slot with other variants, still ≥ 0.5 s → `GameEvents.RaiseHomeVariantPicker(slotId)`. Leaving
    raises it with null.
  - Ghost and model visibility follow `HomeState` on `HomeChanged`.
- Create: `Assets/_Game/Scripts/UI/HUD/VariantPicker.cs`: a row of 2–3 icon buttons above the joystick.
  Click → `IHomeStore.Swap`.
- Modify: `HouseBuilder`: slot objects with ghost (MaterialPalette ghost material) and models built from primitives.
  Factory models reuse the product item prefabs from `ItemCatalog`.
- Modify: `HudBuilder` (the picker).
- Test: covered by `HomeRulesTests`; this task is verified in Play Mode.

- [ ] **Step 1: Implement and rebuild the scene.**
- [ ] **Step 2: Check it in Play Mode** (stage 2 via cheats):
  - 3 chairs carried → 2 living + 2 kitchen chair slots fill in order of proximity, and the rest stay in hand;
  - a store carpet placed;
  - a second carpet variant → picker → swap;
  - comfort changes;
  - 0 console errors.
- [ ] **Step 3: Commit.** → `M10: home slots, placement and variant picker`

### Task 8: Home Store catalog

**Files:**
- Create: `Assets/_Game/Scripts/Gameplay/Home/HomeStoreCounter.cs`: player within `padRadius` of the counter and still
  ≥ `padStillSeconds` → `RaiseHomeStoreOpen(true)` once. Leaving the radius → `RaiseHomeStoreOpen(false)`.
- Create: `Assets/_Game/Scripts/UI/Home/HomeStorePanel.cs` and `HomeStoreRow.cs`, in the Upgrades panel style:
  - tabs House / Yard (House = items whose group has a slot in any non-yard area);
  - each row: icon, name, `+N` comfort, price, Buy;
  - state "Owned ×N" / "Placed" / "Needs walls" (greyed);
  - re-localizes on language change;
  - the balance refreshes on `MoneyChanged`;
  - opens and closes on `HomeStoreOpen` and on ✕ / backdrop.
- Modify: `Assets/_Game/Editor/HudBuilder.cs`: `BuildHomeStorePanel`.
- Modify: `Assets/_Game/Editor/GameSceneBuilder.cs`: call it, and add `HomeSlotSystem` and the counter to Systems.

- [ ] **Step 1: Implement and rebuild.**
- [ ] **Step 2: Check it in Play Mode:**
  - the panel opens at the counter and closes when walking away;
  - Buy spends money and the storage count rises;
  - a capped item's button is disabled;
  - "Needs walls" shows at stage 1;
  - switching hy/en/ru while open re-localizes.
- [ ] **Step 3: Commit.** → `M10: home store catalog`

### Task 9: Inside view (cut-away and camera)

**Files:**
- Create: `Assets/_Game/Scripts/Gameplay/Home/HouseCutaway.cs`
  - `[SerializeField] GameObject roof, frontWall; GameObject frontWallLow`.
  - While the player is inside `dreamHouse.house` footprint and `HouseStage >= 3`: lerp the roof and front-wall scale
    to 0 (or swap to the low cut-away) over 0.25 s, and call `GameCameraRig.SetZoom(0.75f)`. Reverse on exit.
- Modify: `Assets/_Game/Scripts/Gameplay/CameraRig/GameCameraRig.cs`:
  - `public void SetZoom(float scale)`;
  - `FollowOffset = base · portrait · _zoom`, with `_zoom` easing at `positionLerpRate`.

- [ ] **Step 1: Implement and rebuild.**
- [ ] **Step 2: Check it in Play Mode:** walk in and out; the roof and wall hide and return; no camera jump; 60 fps
  (Profiler or Stats) on the plot.
- [ ] **Step 3: Commit.** → `M10: house cut-away and camera zoom`

### Task 10: HUD comfort chip, guide and texts

**Files:**
- Create: `Assets/_Game/Scripts/UI/HUD/ComfortChip.cs`
  - house icon, `home.comfort`, `home.bonus` (+x %), and the storage count when > 0;
  - shown when `IHomeStore.Stage >= 1`;
  - refreshes on `HomeChanged`.
- Modify: `HudBuilder` (the chip under the money pill).
- Modify: `UnlockService`: after `house_found`, a one-time guide to the counter (seen id `home_store`).

- [ ] **Step 1: Implement and rebuild.**
- [ ] **Step 2: Check it in Play Mode:** the chip appears after the foundation, the numbers match `HomeRules`, the
  guide arrows lead to the store once.
- [ ] **Step 3: Commit.** → `M10: comfort chip and home store guide`

### Task 11: Verification and hand-off

- [ ] **Step 1: Run all EditMode tests.** Expected: 0 failed. Console: 0 errors.
- [ ] **Step 2: Full Play Mode run-through from a new game:**
  - tutorial;
  - foundation;
  - store;
  - a yard item;
  - walls;
  - chairs into the living room;
  - room gift (cheats for money);
  - save → restart Play → state restored;
  - v4 save from the backup loads.
- [ ] **Step 3: Test checklist for the user.** Write it and update PLAN.md (tick the M10 steps).
- [ ] **Step 4: Push and open a PR.** Push branch `m10-dream-house` and open a PR. Merge after the user's play-test
  OK.

### Task 12 (after the user's OK): Release 1.0.2

- [ ] **`AppIdentity`.** Version `1.0.2`, Android code 4, iOS build 4.
- [ ] **AAB.** Build it with `FF.Editor.BuildMenu.AndroidReleaseBundle()` (background) and verify it.
- [ ] **IPA.** Build the Xcode project, archive, export and verify it (see PLAN.md notes).
- [ ] **Screenshots.** New first screenshot of the furnished house and a yard shot at all store sizes
  (`Builds/Screenshots/...`).
- [ ] **Store texts.** Description lead, "What's new" and review notes in en/ru.
- [ ] **Uploads.** IPA upload only on the user's go-ahead; the AAB follows the user's Google Play decision.
