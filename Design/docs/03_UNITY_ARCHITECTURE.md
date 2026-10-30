# 03 — Unity Architecture

## Versions & packages
- Unity 6 LTS (6000.0.x), **URP** (Mobile renderer asset: no HDR, MSAA 2x, shadow distance 35, 1 cascade, soft shadows off on low tier).
- Input System (on-screen floating joystick + keyboard), TextMeshPro, Cinemachine 3, Localization, Addressables (optional, later).
- Optional: DOTween (UI pops), Unity Mobile Notifications / IAP / LevelPlay ads — only after approval (Milestone 9).
- Build targets: Android (IL2CPP, ARM64, min API 24) and iOS (min 13). Portrait primary, auto-rotation allowed.

## Folder layout
```
Assets/_Game/
  Art/        Materials (flat-colour URP Lit/Simple Lit), Models (low-poly FBX later), Textures, Fonts
  Prefabs/    Characters/, Items/, Buildings/, Zones/, Pads/, Vehicles/, UI/, VFX/
  Data/       ScriptableObjects (ProductDef, UpgradeDef, PadDef, SkinDef, EconomyConfig, WorldLayout)
  Localization/  String tables hy/en/ru
  Scenes/     Boot.unity, Game.unity
  Scripts/
    Core/       GameBootstrap, GameEvents, Services, ProtoCoords, Pool, Tween, NumberFormat
    Data/       *Def ScriptableObjects, JsonImporter (Editor)
    Save/       SaveData, SaveService
    Gameplay/   ItemType, Item, ItemStack, StackLayouts, Zone(+Drop/Pickup/Cash), Machine, BuildingVisual,
                BuildingFader, ResourceNode, UpgradePad, PadVisual, Player, PlayerCarry, Blockers,
                ShopController (expansion, registers, shelves), Register, DeliveryYard, Truck, CarPark, Car,
                UnlockService, TutorialService, EconomyService, LevelService
    AI/         Agent (kinematic mover + anim), LumberjackAI, CarrierAI (+Stocker, SectionCarrier modes),
                RobotAI (scoring), MinerAI, CashierAI, ManagerAI, ConsultantAI, CustomerAI, CustomerSpawner
    UI/         HUD, MoneyPill (+delivery pop), LevelPill, UpgradesPanel, MainMenu, LanguageSwitch,
                SkinCarousel, TutorialBar, UnlockCard, WorldTag (counters/labels over 3D), FloatingText,
                VirtualJoystick, ThrowButton
  Editor/     DataImporter (reads Design/data/*.json → ScriptableObjects), LayoutBuilder (places pads/zones
              from WorldLayout for quick iteration)
```

## Key types
```csharp
enum ItemType { Log, Plank, Clay, Iron, Bill, Chair, Sofa, Wardrobe, Table, Kitchen, Sink, Material }

[CreateAssetMenu] class ProductDef : ScriptableObject {
  string id; ItemType item; ItemType input; int inputPerCycle; float cycleSeconds;
  int basePrice; int xp; int unlockLevel; long factoryCost; ProductDef unlocksWith;
  float factoryX; bool materialsShop; Color wall, roof; LocalizedString name, sign; Sprite icon; GameObject itemPrefab;
}
[CreateAssetMenu] class UpgradeDef : ScriptableObject { string id; string group; int max; long baseCost; float mul;
  int requiresShopLevel; bool requiresPlumbing; LocalizedString name, desc; }
[CreateAssetMenu] class PadDef : ScriptableObject { string id; Vector2 protoPos; string glyph; long baseCost; float mul; int max; }
[CreateAssetMenu] class EconomyConfig : ScriptableObject { float priceMul=.85f, costMul=1.25f, truckMul=1.4f; /* + formulas as methods */ }
```

- `ItemStack` (plain C# + anchor Transform): `Count`, `Incoming`, `Type`, `Capacity` (Func<int>), `Push(Item, duration)`, `Pop()`. Items fly via a pooled tween runner (no coroutines per item).
- `Zone : MonoBehaviour` with `ZoneKind`, `ItemStack Stack`, `Func<bool> Active`, `Func<ItemType,bool> Accepts`, label key. A `ZoneRegistry` lets the player and AI query nearby zones (no physics; distance checks on a short list).
- `UpgradePad` owns `PadDef`, persisted `PadState{lv,paid}`, `Func<bool> Show`, `UnityEvent<int> OnLevel`. `PadVisual` renders the price into a TMP text on the pad + a fill quad (no runtime texture redraw needed in Unity).
- `Machine` references input/output zones, `ProductDef` or sawmill config, and a `BuildingVisual` (rebuilds floors/chimneys/fan/tank/flag from (s,q) using small prefabs; bounce + confetti on upgrade).
- `BuildingFader` swaps renderers to an "occluded" material variant when the player is behind.
- `Agent` = kinematic mover + simple procedural animation (legs/arms rotate) — later replaceable by Animator with Mixamo-style clips.
- `RobotAI` implements the scoring in 02_SYSTEMS_SPEC §8 exactly; expose weights in a ScriptableObject for tuning.

## Scene hierarchy (Game.unity)
```
Game
  Systems (GameBootstrap, SaveService, EconomyService, LevelService, UnlockService, TutorialService, Pools)
  CameraRig (Cinemachine follow + menu orbit)
  World
    Ground, Roads (main road, lanes, zebra, car park, dream-house road)
    Forest (trees spawned from layout)
    Sawmills (Saw1, Saw2Yard)
    FactoryRow (Chair, Sofa, Wardrobe, Table, Kitchen, Plumbing, Materials) each: Lot, Building, InZone, OutZone, Pads
    MinesYard (gate, rocks)
    MainShop (floor, walls, door arch, shelves, registers, expansion pad, register pad)
    MaterialsShop
    DeliveryYard (bays, truck pad, parking pad)
    CarPark
    DreamHousePlot (placeholder)
    Fences, Props
  Actors (Player, Workers, Customers, Cars, Trucks)
  UI (Canvas: HUD, TutorialBar, UnlockCard, WorldTags layer, UpgradesPanel, MainMenu, Joystick)
```

## Mobile performance rules
- Static batching for world props; GPU instancing on shared flat-colour materials (one material per colour, as the prototype does with its material cache).
- Pools: items (per type), bills, customers, cars, particles, floating texts, world tags.
- Max ~60 agents on screen; AI ticks every frame but job selection (robots, carriers) only when idle.
- World tags (counters "12/30", price chips) via a single screen-space canvas updated in LateUpdate; cull when off-screen or far.
- Target 60 fps, cap with `Application.targetFrameRate = 60`; quality tiers Low/Medium/High (shadows off on Low).
- Avoid per-frame allocations (no `new Vector3` in hot loops is fine in C#, but no LINQ/closures/strings).

## Save
`SaveService` serializes `SaveData` (schema in spec §16) with JsonUtility/Newtonsoft to `persistentDataPath/save.json`, versioned with migration hook. Autosave every 3 s if dirty, on `OnApplicationPause(true)` and after purchases.
