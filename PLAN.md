# PLAN

Read this file at the start of every session. Current work is at the top.
Full approved plan for M0+M1 (with details per step): see the sections below.

## In progress

### GitHub repo + Design/ setup — 2026-10-31
- [x] Move `FurnitureFactory_Unity_Handoff/` → `Design/` (outside Assets), merge its CLAUDE.md into root CLAUDE.md
- [x] `git init -b main`, `.gitignore` (Unity), Git LFS (`brew install git-lfs`) + `.gitattributes`
- [x] First commit: template project + Design/ + rules
- [ ] User creates an empty GitHub repo and sends the URL → `git remote add origin <URL>`
- [ ] User runs the first `git push -u origin main` (credentials are the user's)

Notes:
- `gh` not installed, no SSH keys → user pushes; PRs are made on github.com.
- Branches: `m0-setup`, `m1-player-world`, merged into `main` after the user's play-test.
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"?

### M0 — Project setup — 2026-10-31 (branch `m0-setup`)
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
- [ ] Commit `M0: ...`

Notes / discrepancies:
- pads.json `costPerLevel_beforeECON` used banker's rounding in 3 places (saw_speed lv1 2600, chair_speed lv1 2600, table_speed lv2 55100); prototype Math.round gives 2650/2650/55150 → prototype wins (test has explicit overrides).
- pads.json `reg` position is text ("next register slot") → imported as register 1 (26.4, 3.5) like `placeRegPad()` on a fresh save.
- Fonts come from github.com/notofonts (official Noto static TTFs; google/fonts only has variable fonts).
- `capture game_view --save_path` writes under `Assets/` — move the file out and delete `Assets/Temp` after use.
- Editor tooling run order on a fresh clone: FF/Import Design Data → FF/Setup Fonts → FF/Setup Render Settings → FF/Setup Scenes.

### M1 — Player, camera, input, world blockout — 2026-10-31
- [ ] A. Look: fog/background #bfe3f0 (42–95), ambient gradient #ffffff/#7a9a55, sun #fff1d6 from SE; MaterialLibrary SO (one Simple Lit material per colour, instancing)
- [ ] B. Editor LowPolyMeshFactory: flat-shaded icosahedron, N-segment cylinder
- [ ] C. Editor LayoutBuilder (`FF/Build World Blockout`): ground, roads, car park, zebra, fences, back yards, dream plot, sawmill 1, chair factory, empty lots, shop walls/door, register 0, delivery bays, forest (seeded jitter), localized signs, Static flags
- [ ] D. Aabb2D + CollisionResolver (push-out r=0.3), PlayerRegionRules, BlockerSet.Build(WorldLayout, WorldStateSnapshot)
- [ ] E. Input: FF_Input.inputactions (Move, Throw), IMoveInput, VirtualJoystick (UI), MoveInputAggregator (deadzone 0.12), SafeAreaFitter
- [ ] F. Player: CharacterRigBuilder → Player prefab (makeChar), CharacterRig, CharacterAnimator (animChar), PlayerMover (updPlayer), spawn proto (-4,0)
- [ ] G. Camera: Cinemachine 3 Follow offset (0,14.5,-13.5), look y=0.4, FOV 42, PortraitOffsetScaler ×1.45
- [ ] H. EditMode tests: CollisionResolver, PlayerRegionRules, BlockerSet, MoveInputAggregator
- [ ] I. Verify in Play Mode (portrait + landscape screenshots vs reference), user checklist → commit `M1: ...`

Notes:
- Prototype wins over docs: unowned factory lots are walkable (blocker only after purchase).

## Done

### Install Unity CLI — 2026-10-29
- [x] Check project (Unity 6000.6.7f1, `com.unity.pipeline` 0.9.1-exp.1 already in manifest)
- [x] Install Unity CLI 1.0.0-beta.14 → `~/.unity/bin/unity`
- [x] Verify connection: `unity status` → `ready`, port 7800

Result: CLI works and can drive the open Mebel Editor.

### Set up session rules — 2026-10-29
- [x] Create CLAUDE.md (session-start rules, project facts)
- [x] Create PLAN.md (this file)

Result: every new session reads PLAN.md first and continues from it.
