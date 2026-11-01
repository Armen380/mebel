# PLAN

Read this file at the start of every session. Current work is at the top.
Full approved plan for M0+M1 (with details per step): see the sections below.

## In progress

### Fix: Android build output got committed — 2026-11-01 (branch `chore/untrack-build-artifacts`)
Cause: the user's Android test build wrote `first.apk`, `first_BackUpThisFolder_ButDontShipItWithYourGame/` (IL2CPP backup,
752 files) and `.utmp/` (CMake temp) into the project root; Claude's `git add -A` in df46b3b committed the last two
(≈15 M lines) plus Unity IAP (`com.unity.purchasing` 5.4.4, added by the build setup) and they reached main via PR #4.
No secrets inside (checked: no keystores/keys/tokens); CMake files contain local paths (/Users/armen/...).
- [x] Remove the artifacts from the index (files stay on disk), ignore `*_BackUpThisFolder_ButDontShipItWithYourGame/`, `*_BurstDebugInformation_DoNotShip/`, `.utmp/`, `*.aab`, `*.symbols.zip`, `Builds/`
- [x] Ask the user: purge the artifacts from git history (force-push main) or not; keep or remove Unity IAP → user: no history rewrite (cleanup commit only); keep Unity IAP (`com.unity.purchasing` 5.4.4, `Assets/Resources/BillingMode.json`)
- [ ] PR → main, sync local main
- Rule from now on: stage files explicitly / review `git status` fully before committing; never `git add -A` blindly.

### M4 — Upgrade pads, building growth, upgrades panel — 2026-11-01 (branch `m4-upgrades`)
Status: **In progress** — plan approved 2026-11-01 with all recommendations.
Goal (04_IMPLEMENTATION_PLAN): pads work; buildings grow; panel prices match upgrades.json.
Prototype refs: `makeBuilding / setBuildingLevel / TRIMS` (~659–705), `refreshBuilding / capMul / fadeBuildings / setGhost /
ghostOf` (~1115–1140), `puff / burst / updParticles` (~1108–1114), building pop/bounce/fans/flag/smoke in `updMachine` (~1084),
Lv chip in `setupLabels` (~1503), `UPG / upPrice / upLocked / lockText` (~238–256, 452–456), `renderShop / openSheet /
buy click` (~1572–1597), `hudMoney` badge (~1446), sheet CSS (~118–139), saw2_buy (~918).

- [x] 0. Branch `m4-upgrades` from main; commit the pending font SDF assets first
- [ ] A. Data: `BuildingKit` SO (meshes + palette colours used by growth: trims, lit/unlit windows, chimney, fan, tank, flag); every growth colour pre-created in MaterialPalette + a transparent "ghost" twin per colour (opacity 0.22, made in the Editor so the shader variant ships); `UpgradeDef` gets name/desc keys + value format (items / % / sec / people / bots / price / customers)
- [ ] B. Building growth: `BuildingVisual` rebuilds the Deco group from (speed s, qty q) exactly like `setBuildingLevel` (tier trims, lit windows, q floors of 1.25 m, roof on top, chimneys at s ≥ 1 / 5, roof fan s ≥ 3, tank s ≥ 7, gold flag s = 8 & q = 3); pop-in (new building), bounce on upgrade (scale y +16 % / xz −6 %, decaying sine), fans spin (fast while busy), flag sways
- [ ] C. Effects: chimney smoke (rate ↑ with speed and when busy, max 160) and 28-cube confetti burst — Unity ParticleSystem, one shared system each, pooled; on a speed/qty pad: bounce + confetti + floating `f.cap` ("×2 output · 38 slots")
- [ ] D. Lv tag over every working building: honey pill "Lv 3 · ×2" / "MAX · ×4" (new world-tag style), hidden while the building is faded
- [ ] E. Occlusion fade (`fadeBuildings`): player behind a building (|dx| < 4.2, 2.3…15 m behind) → its renderers switch to the ghost materials, no shadows; back on when the player leaves
- [ ] F. Pads: every sawmill / factory speed + qty pad (effects already live through the machines, now with growth) + `saw2_buy` (Sawmill 2: building pops in, lot disappears, blockers rebuilt, toast `t.saw2`); generic "owned building" switch (building ↔ lot) reused by M5 factory buy pads
- [ ] G. Upgrades panel (bottom sheet, prototype `.sheet`): "Upgrades" honey button top-right with the red badge when something is affordable; header title + balance + close; pad note; group headers; rows: name, description, level pips, "5 items → 7 items", green price button / grey when too expensive / lock text (`Shop Lv N`, plumbing) / MAX; buying spends money (`upPrice`), joystick off while open, scrolls on phones, safe area
- [ ] H. Upgrade effects live now: carry capacity, walk speed, axe speed (player); ads (spawn rate + walk-in cap), quality (sale price), consultant (bill +15 %, patience ×1.6 — locked until shop Lv 5, M5)
- [ ] I. EditMode tests: growth layout per (s, q) (floors, chimneys, fan, tank, flag, tier), upgrade prices vs upgrades.json `costPerLevel_beforeECON` × ECON, lock rules, value texts, badge rule, ownership switch + blockers, Lv tag text, fade region
- [ ] J. Play Mode check: buy all saw_speed / saw_qty levels (test money), watch growth / smoke / confetti / Lv tag / fade; buy Sawmill 2; panel on phone portrait; Console clean
- [ ] K. Commit `M4: building growth, pads, upgrades panel`, push, user play-test, PR → main

Decisions (approved by the user):
1. Which pads in M4 [speed/qty of every sawmill and factory + saw2_buy now; factory buy pads, shop expansion and register pads in M5, truck/parking in M7, reg_annex/sink in M8 — as those milestones list them; "every pad works" is then met at the end of M8]
2. Worker / staff / section rows of the panel (workers come in M6, section staff in M8) [show only the Player and Business groups now (cap, speed, axe, ads, quality); each other group appears with its milestone, so nobody pays for workers that do not exist yet]
3. Dev language button sits top-right where the "Upgrades" button goes [move it under the Upgrades button until the real menu (M9)]

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

## Done

### M3 play-test changes (user requests) — 2026-10-31 (branch `m3-shop`, before the M3 merge)
Result: tutorial text wraps on phones, dollars before the number, factories in two lines (pairs across the fence); user play-test OK 2026-11-01. These are deliberate design changes away from the prototype (the user decides; the
prototype no longer wins for layout and currency).
- [x] 1. Tutorial text must fit a phone screen: the quest bar (and toast subtitle) wrap to the safe-area width minus 16 px margins (prototype `max-width: calc(100% - 32px)`)
- [x] 2. Currency: dollars, sign before the number — `$430`, `$1.9K`, `+$430`; HUD coin shows `$`; cash zones and buy-pad glyphs `$`; the 5 localization strings with ֏ in hy/en/ru; CLAUDE.md non-negotiable updated
- [x] 3. Factories in two lines, "pairs across the fence" like the sawmills (user picked this layout):
  - front row (z −10, facing the road): Sawmill 1 (−10), Chair (−2), Wardrobe (6); front slot x 14 stays empty
  - back row behind the fence (z −23.5, zones at z −18.8 between building and fence): Sawmill 2 (−10), Sofa (−2), Table (6), Kitchen (14)
  - Sink (40) and Material (48) stay next to the mines yard
  - back yard widened from x −18.5…−1.5 to −18.5…20.5; the fence is open over the whole yard width (as for the sawmill yard today); region rule yard split moves from x 15 to 27
  - pads: every factory at x + 4 (front speed −11.1 / qty −8.8, back speed −24.6 / qty −22.3), buy pad on the building spot (front −9.6, back −23.1); saw2 pads move from x −4.4 to −6 (Sofa now stands there)
  - data: products.json `factoryX` + new `factoryRow`, pads.json positions, world_layout.json back row + yard; blockers per row; tests that compare against the prototype layout get the new reference numbers
  - Result: 503/503 tests green; Play Mode: phone portrait 1080×2340 wraps step 7 (ru) onto 2 lines, `$12K` / `$1.9K` everywhere, back yard reachable, back lots in a row behind the open fence. Unity rewrote two URP settings assets during the session (volume profile, shader prefiltering) — reverted, not part of this change.
  - Game view is left at a custom 1920×1080 size after the portrait check (no API to restore "Free Aspect").
- [x] 4. Tests green, Play Mode check (phone portrait text, $ everywhere, walk into the back yard, back factories behind the fence), commit, push

### M3 — Shop, customers, registers, money, XP, HUD, tutorial — 2026-10-31 (branch `m3-shop`)
Result: shop, walk-in customers, registers, cash, money/XP/levels, HUD, 8-step tutorial, 4 upgrade pads; 503 tests green; user play-test OK 2026-11-01; merged into main.
Goal (04_IMPLEMENTATION_PLAN): full 8-step tutorial completes; money and XP match prototype formulas.
Prototype refs: shelves + registers (~941–960), customers `spawnCustomer/chooseReg/updCustomers/leave` (~1336–1440),
`regServer` (~1245), cash zone in `updPlayer` (~1170), `addMoney/addXP/onLevel/toast` (~1445–1462), `QUEST/emit/renderQuest`
+ arrow (~1464–1482, 1641), `addPad/drawPad/updPads` (~716–760), HUD markup/CSS (~24–60, 150–166), `floatText` (~1496).

- [x] 0. Branch `m3-shop` from main
- [x] A. Data
  - EconomyConfig: customer numbers (spawn 5 − 0.5·ads − 0.3·shop, min 1.1; walk-ins 4 + ads + 2·shop; walk 2.9 m/s; patience 45 s ×1.6 with consultant; take delay 0.3 / take 0.35 s; serve 0.9 s, player serve ×1.4; bill value formula), bill/cash flight timings, floating text rise
  - WorldLayout: shelf geometry (pile, queue slots 1.45 + 0.85·i, ±0.35), register queue (x + 1.25, z − 0.5 + 1.05·i, approach +3.6), cash zone offset (−1.45, −0.1) + cash pile, pad size 1.8
  - TutorialDef: structured steps (event drop/pick/chop/cash/pad + zone id + arrow target); the importer maps the `completeOn` texts of tutorial_quest.json
- [x] B. Progress (pure C#): `GameProgress` — money, total earned, xp, level, quest step, pad states {lv, paid}; implements `IUpgradeLevels` (pads by id, panel upgrades 0 until M4); `LevelMath.AddXp` (xpNeed = round(8 + 4.5·lv), multi-level-ups); GameEvents MoneyChanged / XpChanged / LevelUp / CashCollected. Saving comes in M5 (restart = new game until then)
- [x] C. Shop: shelves for every product (LayoutBuilder; active when owned) with shelf zones (cap 8 + 3·shop level, pile 2×2); register cash zones (kind Cash, ֏ glyph, honey tint, bills pile on the counter); register active rule i < 1 + min(reg, shop)
- [x] D. Customers: 12 pre-built skin variants (prototype palettes, seeded) pooled; `CustomerDirector` = port of `updCustomers` (spawn timer + cap, shelf/register queues, take item, choose least-busy register, served by the player standing on the cash zone, bill → counter pile, XP, "+430 ֏" float, leave, patience → angry); pure `CustomerQueues` (slot positions) + `CustomerRules`; bubbles (wanted product icon / cash icon / angry face) as a new world-tag style with icons generated from the prototype SVGs
- [x] E. Cash: the player on a cash zone collects one bill per 0.035 s (bill flies to the player, then money is added)
- [x] F. HUD: money pill (coin ֏ + `fmt`, bump on gain), level pill + XP bar, quest bar ("1/8" + text), bottom hint until step 2, level-up toast (`t.level`, `t.newFactory`/`t.keepGoing`), floating texts layer (pooled)
- [x] G. Tutorial: `TutorialService` advances on GameEvents exactly like `emit()`; bobbing/spinning honey cone arrow over the target (nearest tree, zone, pad)
- [x] H. Upgrade pads (needed for tutorial step 8 — see decision 1): `UpgradePad` paying mechanic (0.95 m, still ≥ 0.3 s, amt = min(money, remain, max(1, ⌈price·dt/1.4⌉)), bill flies every 0.07 s, level++, "done" float, PadCompleted event) + pad visual (honey rounded square, green fill from the bottom, glyph, remaining price). Active in M3: saw_speed, saw_qty, chair_speed, chair_qty (their effects already work through the machines); other pads come with their milestones
- [x] I. EditMode tests: LevelMath/GameProgress, bill value / sale price, CustomerQueues slots, spawn interval / walk-in cap / patience, register choice, pad payment + prices, tutorial parsing + matching, CompactChangeKey — 502/502 green
- [x] J. Play Mode check (scripted teleports): whole tutorial 1→8 completes; 5 chair sales = 2150 ֏ (5 × 430), XP 15 → Lv 2 with 2/17; saw_speed pad 1900 → Lv 1, next price 3300, sawmill storage 26/33; angry customers leave after 45 s; toast, bubbles, floats, cash pill seen; Console clean
- [x] K. Commit `M3: shop, customers, registers, money, XP, HUD, tutorial` (e2d3353 + df46b3b), push, user play-test OK, PR → main

Decisions (approved by the user):
1. Tutorial step 8 needs an upgrade pad, pads are M4 [move the pad paying mechanic + visual into M3, only for the 4 sawmill/chair pads; M4 keeps building growth, confetti, Lv tags, occlusion fade, upgrades panel]
2. Customer looks [12 pre-built colour variants from the prototype palettes, pooled; not a new random colour per customer]
3. HUD buttons "Upgrades" and "Menu" [not in M3 — they come with the panel (M4) and the menu (M9)]

Notes:
- Zone order in ZoneRegistry: machine zones, then shelves, then cash zones (prototype interleaves shelves with factories; zones never overlap, so the first-match rule gives the same result).
- `FF/Build Game Scene` keeps existing item / customer prefabs (stable file ids, no git churn); use `FF/Build Item Prefabs` / `FF/Build Customer Prefabs` to rebuild them after shape changes.
- In landscape on a desktop-sized Game view the level toast overlaps the quest bar (HUD is scaled for phones); same layout as the prototype on a phone.

Not in M3 (their milestones): car customers + car park (M7), unlock cards (with M5 product expansion), workers serving registers (M6), materials shop + bulk customers (M8), saving (M5), SFX (M9).

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

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
