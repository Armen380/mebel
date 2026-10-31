# PLAN

Read this file at the start of every session. Current work is at the top.
Full approved plan for M0+M1 (with details per step): see the sections below.

## In progress

### Next: M3 — 2026-10-31
- [ ] Write the M3 plan from `Design/docs/04_IMPLEMENTATION_PLAN.md` and get the user's approval (no code before that)

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

## Done

### M2 — Items, stacks, zones, trees, sawmill, chair factory — 2026-10-31 (branch `m2-production`)
Result: chop → logs → sawmill → planks → chairs loop with prototype timings/capacities, zones, counters, FULL tag, Throw; 485 tests green; user play-test OK; merged into main.
Goal (04_IMPLEMENTATION_PLAN): chop → logs → sawmill → planks → chair workshop → chairs loop works with
correct timings and capacities; Throw button. Prototype refs: `H/PROTO/makeItem` (~529), `Stack/sendTo/fly/updTweens` (~557),
`addZone` (~648), sawmill + factory zones (~905–933), `makeTree/updNode/nearestNode/tryChop` (~1038), `updMachine` (~1084),
`updPlayer` zone loop + `throwAll` (~1156–1182), counter chips `stackChip` + "FULL" chip (~1501, 1514).

- [x] 0. Branch `m2-production` from main; commit the 4 pending font SDF assets first (1fd0eba)
- [x] A. Data
  - `ItemCatalog` SO: per ItemType stack height H (prototype table; not in JSON → note), prefab, pool prewarm count
  - `PileLayoutSettings` (cols, rows, spacingX, spacingZ, anchor offset) in WorldLayout for sawIn/sawOut, plank-in, mine-in, product-out piles; capacities stay in EconomyConfig
  - `EconomyConfig`: add chop range 1.6, chop hit interval 0.3, flight durations (player 0.24, chop 0.32, machine in 0.3+0.02i / out 0.35+0.05i, throw 0.3+0.03i), arc heights, throw distance 1.5 / spread 1.2; importer keeps them
- [x] B. Item visuals: Editor `ItemPrefabBuilder` (menu `FF/Build Item Prefabs`) → `Prefabs/Items/*.prefab` for all 12 types from `PROTO` (log, plank, clay, iron, bill, chair, sofa, wardrobe, table, kitchen, sink, material), shared palette materials
- [x] C. Stacks (pure C#, FF.Gameplay/Items): `ItemStack` (items + incoming, fixed/non-fixed type rules, capacity func, `Pop`), `IStackLayout` → `CarryLayout`, `PileLayout`; `ItemArc` math (lerp + sin arc)
- [x] D. Runtime items: `Item` (type, pooled), `ItemPool` (per type, prewarmed, no Instantiate in play), `ItemFlights` — one runner with a struct list (no coroutines, no per-item allocations): fly-to-stack (live target slot), fly-and-despawn (machine mouth), throw-then-shrink
- [x] E. Zones: `Zone` MonoBehaviour (kind drop/pickup, accepts, stack, capacity, active), `ZoneRegistry` (short list, distance checks); pure `ZoneTransferRules` (first matching zone per tick, drop/pickup conditions, cooldown 0.075 s); ground marker = dashed rounded square (Editor-generated texture, tint per kind) + glyph ↓/↑ (baked into the texture) + localized label (`in.log`, `in.plank`, product sign)
- [x] F. Resource nodes: pure `ResourceNodeState` (alive, regrow 9 s, fall, grow elastic, shake) + `Chopper` (`tryChop`: progress·rate, hit every 0.3 s, yield min(2, room), hardness, type check, chop time from axe level); `ResourceNode` animates the tree `Top` (topple 0.4 s, regrow pop, shake); `NodeRegistry.Nearest`; forest trees get the component in LayoutBuilder (rocks come in M8)
- [x] G. Machines: pure `MachineCore` (`updMachine`: k = min(1+qty, ⌊in/inN⌋, ⌊(outCap−out.n)/outN⌋), cycle = base/(1+0.35·speed), capacities ×(1+0.6q+0.1s)); `Machine` adapter (zones, mouth, flights) + `MachineVisual` (saw blade spin, press bob); sawmill 1 (log 1 → plank 2, 1.6 s), sawmill 2 (inactive until owned), every product factory (active when owned → only chair at start)
- [x] H. Player: `PlayerCarrier` (carry stack on the rig anchor, cap 5+2·lv), `PlayerInteractor` (chop nearest node within 1.6 m and face it, zone loop, `StillTime` kept), animator Carrying/Chopping flags; `ThrowAll` (Q key + Throw action + HUD button)
- [x] I. UI: `ThrowButton` (bottom-right round walnut button, trash icon, `ui.throw`, visible only while carrying, safe area); `WorldTagLayer` — one screen-space canvas with pooled pills: pile counters "n/cap" over active zones, red "FULL" (`c.full`) over the player; UI reads Core interfaces only (`ICarrier`, `IWorldTagSource`)
- [x] J. Scene: `FF/Build Game Scene` adds Systems/Items (pool + flights), zones + machines from data, wires player and HUD
- [x] K. EditMode tests: ItemStack (incl. throw TakeAll), layouts (vs prototype formulas), ItemArc, ZoneTransferRules, Chopper, ResourceNodeState, MachineCore, StorageCapacity — 485/485 green
- [x] L. Play Mode check (scripted teleports): 3 trees → 5 logs (2+2+1, hands cap 5) → sawmill 5 logs → 10 planks → 5 planks to chairs → 2 chairs + 1 plank left; counters, FULL tag, Throw button, throw → items back in the pool; Console clean. No per-frame allocations by code review (no profiler run)
- [x] M. Commit `M2: items, stacks, zones, trees, sawmill, chair factory` (99f6b6c), push, user play-test OK (2026-10-31), PR → main

Decisions (approved by the user):
- SFX (chop/throw/pick) [later, M9; M2 raises GameEvents hooks only]
- Tween engine [own small runner, no DOTween]
- Pile counters + "FULL" tag in M2 [yes]
- Prototype quirk: chop progress is not reset when the player walks away from a tree [keep 1:1]

Notes:
- Not in Design/data JSON, taken from the prototype into data assets: item stack heights `H` (ItemCatalog), pile layouts + mouths (WorldLayout.production, sawmill2.machineMouth), flight/throw/chop timings and node hardness (EconomyConfig).
- Noto Sans has no ↓/↑ glyphs → the arrow is drawn into the zone marker textures (Art/Textures/ZoneMarker_*.png, generated by TextureFactory; delete a PNG to regenerate).
- Scene parts per machine: World/Production/Machine_<id> (zones Zone_<id>_in/_out with Marker + Pile). Zone order = prototype order (ZoneRegistry list).
- Pad levels (`saw_speed`, `chair_qty`, …) are read through IUpgradeLevels by id; all 0 until M4/M5.
- Play Mode automation: teleporting the player via `script eval` is faster than simulating keys (helpers in the session scratchpad, not in the repo).

### GitHub repo + Design/ setup — 2026-10-31
Result: Design/ in place, repo on github.com/Armen380/mebel, gh set up so Claude pushes/opens PRs.
- [x] Move `FurnitureFactory_Unity_Handoff/` → `Design/` (outside Assets), merge its CLAUDE.md into root CLAUDE.md
- [x] `git init -b main`, `.gitignore` (Unity), Git LFS (`brew install git-lfs`) + `.gitattributes`
- [x] First commit: template project + Design/ + rules
- [x] User creates an empty GitHub repo and sends the URL → `git remote add origin https://github.com/Armen380/mebel.git`
- [x] User installed `gh` and ran `gh auth login` (account Armen380); `gh auth setup-git`; pushed `main`, `m0-setup`, `m1-player-world` (22 LFS objects)

Notes:
- `gh` is installed and logged in (keyring, HTTPS): Claude pushes and opens PRs with `gh`. Login/credentials stay the user's.
- Branches: `m0-setup`, `m1-player-world`, merged into `main` after the user's play-test.

### M0 — Project setup — 2026-10-31 (branch `m0-setup`)
Result: packages, asmdefs, data import, localization hy/en/ru, fonts, scenes, 428 tests green; merged into main.
Decisions: M0 fully + M1, separate commits; asmdef + EditMode tests; Cinemachine 3; fonts downloaded;
remove packages ai.assistant, ai.inference, collab-proxy.
- [x] A. Packages: cinemachine 6.6.0 (CM3 API, Unity 6.6 built-in version), localization 1.5.13, test-framework 1.8.0, newtonsoft-json 3.2.2; removed ai.assistant/ai.inference/collab-proxy; TMP Essentials → `Assets/TextMesh Pro`
- [x] A. URP Mobile_RPAsset: HDR off, MSAA 2x, shadow distance 35, 1 cascade; Mobile quality for Editor/Standalone/Android/iOS (`FF/Setup Render Settings`)
- [x] B. Folders `Assets/_Game/...`; asmdefs FF.Core, FF.Data, FF.Gameplay, FF.UI, FF.Editor, FF.Tests.EditMode; SampleScene deleted (default InputSystem_Actions is replaced in M1.E)
- [x] C. Core: ProtoCoords, Aabb2D, NumberFormat (exact JS toFixed), JsMath (JS Math.round), GameEvents, Services, AppSettings, IMoveInput
- [x] D. Data SOs: ProductDef, UpgradeDef, PadDef, SkinDef, EconomyConfig (+formulas), TutorialDef, WorldLayout, GameDatabase
- [x] D. Editor DataImporter (`FF/Import Design Data`), idempotent
- [x] E. Localization (`FF/Import Localization`, also run by the data import): hy/en/ru, table `Game` (167 keys), Smart Strings for `{x}`; selectors: command line → device → hy
- [x] F. Fonts (`FF/Setup Fonts`): Noto Sans Armenian + Noto Sans Bold/ExtraBold/Black (from notofonts, OFL) → TMP dynamic SDF; default = Armenian ExtraBold → fallback Noto Sans ExtraBold
- [x] G. Scenes (`FF/Setup Scenes`): Boot.unity (BootLoader: 60 fps, wait localization, load Game), Game.unity (Systems/GameInstaller, CameraRig, World, Actors, UI); temporary M0Check
- [x] H. EditMode tests: ProtoCoords, NumberFormat (401 cases generated from the prototype fmt() in Node), EconomyConfig, DataImport — 428/428 green
- [x] Verify: Play Mode shows "Կահույքի Գործարան / Мебельная фабрика" + ֏, data log correct (chair 430 ֏, xp(Lv1) 13, saw_speed 1.9K ֏), no Console errors
- [x] Commit `M0: project setup, data import, localization, fonts` (140ddc1)

Notes / discrepancies:
- pads.json `costPerLevel_beforeECON` used banker's rounding in 3 places (saw_speed lv1 2600, chair_speed lv1 2600, table_speed lv2 55100); prototype Math.round gives 2650/2650/55150 → prototype wins (test has explicit overrides).
- pads.json `reg` position is text ("next register slot") → imported as register 1 (26.4, 3.5) like `placeRegPad()` on a fresh save.
- Fonts come from github.com/notofonts (official Noto static TTFs; google/fonts only has variable fonts).
- `capture game_view --save_path` writes under `Assets/` — move the file out and delete `Assets/Temp` after use.
- Editor tooling run order on a fresh clone: FF/Import Design Data → FF/Setup Fonts → FF/Setup Render Settings → FF/Setup Scenes.

### M1 — Player, camera, input, world blockout — 2026-10-31 (branch `m1-player-world`)
Result: walkable world blockout, player, joystick/WASD, Cinemachine camera, 451 tests green, user play-test OK; merged into main.
- [x] A. Look (`FF/Build Game Scene`): background + linear fog #bfe3f0 42–95, trilight ambient (white / #7a9a55 ×0.72), sun #fff1d6 from the prototype sun offset; MaterialPalette SO + one Simple Lit material per colour (GPU instancing) in Art/Materials
- [x] B. Editor LowPolyMeshFactory: flat-shaded plane, icosahedron, N-segment cylinder/cone, hemisphere → Art/Meshes
- [x] C. Editor LayoutBuilder (`FF/Build World Blockout`) → World/Blockout (946 renderers): ground, roads, car park, zebra, fences, saw back yard, mines yard + closed gate, dream plot (arch, lamps, foundation, billboard blockout), sawmill 1, chair factory, lots, sawmill 2 lot, shop walls/door/plants, register stalls, materials shop (inactive), delivery bays, forest 5×7 (seeded jitter), localized 3D signs (LocalizedTmpText). State-dependent parts are built inactive.
- [x] D. CollisionResolver (push-out r=0.3, prototype tie order), PlayerRegionRules (Unity space), BlockerSet.Build + WorldStateSnapshot.NewGame, WorldCollision service
- [x] E. Input: FF_Input.inputactions (Move WASD/arrows/stick, Throw Q/buttonWest) = project-wide actions (default InputSystem_Actions deleted); MoveInputAggregator; VirtualJoystick (floating, full-screen area under the HUD); SafeAreaFitter; dev LocaleSwitchButton (top-right, hy/en/ru)
- [x] F. Player: CharacterRigBuilder → Prefabs/Characters/Player.prefab (makeChar, skin from SkinDef, all hat types), CharacterRig, CharacterAnimator (animChar), PlayerMover (updPlayer movement), spawn proto (-4, 0)
- [x] G. Camera: CinemachineBrain + CinemachineCamera (Follow world-space offset (0, 14.5, -13.5), RotationComposer look y 0.4, damping = 4.6 / lerp rate), GameCameraRig applies FOV 42 / clip / portrait ×1.45 from WorldLayout.camera
- [x] H. EditMode tests: CollisionResolver, PlayerRegionRules (20k-point fuzz vs a direct port of collide()), BlockerSet (= refreshBlocks() on a new game + late game), MoveInputMath — 451/451 green
- [x] I. Play Mode check: landscape frame ≈ screenshot 02, portrait (×1.45) ≈ screenshot 15; walking: blocked by chair factory (z 6.90), saw back yard reachable to its back fence, main fence and closed mines gate stop at 13.2, shop walls + door work, dream plot reachable; no Console errors
- [x] User play-test OK (2026-10-31) → PRs merged into `main`, pushed

Notes:
- Prototype wins over docs: unowned factory lots are walkable (blocker only after purchase).
- Region rule detail (prototype): deep behind the fence outside the yards x is clamped to the yard wall (not pushed back to the fence).
- Colours look a little darker than the prototype (three.js r128 output without sRGB encoding looks brighter) — tune in the M9 polish pass if needed.
- Automating input in Play Mode: Editor must tick unfocused (`editor.playmode set_run_in_background --enable true`, `editor set_auto_tick --enable true`); the real macOS keyboard ignores simulated keys, so add a virtual one first (`InputSystem.AddDevice<Keyboard>("FFTestKeyboard").MakeCurrent()`) and set Input settings background behaviour to IgnoreFocus; restore everything afterwards. Use `simulate_key --action down/up` (press = down+up at once).

### Install Unity CLI — 2026-10-29
- [x] Check project (Unity 6000.6.7f1, `com.unity.pipeline` 0.9.1-exp.1 already in manifest)
- [x] Install Unity CLI 1.0.0-beta.14 → `~/.unity/bin/unity`
- [x] Verify connection: `unity status` → `ready`, port 7800

Result: CLI works and can drive the open Mebel Editor.

### Set up session rules — 2026-10-29
- [x] Create CLAUDE.md (session-start rules, project facts)
- [x] Create PLAN.md (this file)

Result: every new session reads PLAN.md first and continues from it.
