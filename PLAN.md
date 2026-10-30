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

### M0 — Project setup — 2026-10-31
Decisions: M0 fully + M1, separate commits; asmdef + EditMode tests; Cinemachine 3; fonts downloaded from github.com/google/fonts;
remove packages ai.assistant, ai.inference, collab-proxy.
- [ ] A. Packages: add cinemachine 3, localization, test-framework, nuget.newtonsoft-json; remove ai.assistant/ai.inference/collab-proxy; TMP Essentials
- [ ] A. URP Mobile_RPAsset: HDR off, MSAA 2x, shadow distance 35, 1 cascade
- [ ] B. Folders `Assets/_Game/...`; asmdefs FF.Core, FF.Data, FF.Gameplay, FF.UI, FF.Editor, FF.Tests.EditMode; delete SampleScene + default InputSystem_Actions
- [ ] C. Core: ProtoCoords, NumberFormat (fmt), GameEvents, Services
- [ ] D. Data SOs: ProductDef, UpgradeDef, PadDef, SkinDef, EconomyConfig, TutorialDef, WorldLayout
- [ ] D. Editor DataImporter (`FF/Import Design Data`), idempotent
- [ ] E. Localization: locales hy (default)/en/ru, String Table Collection `Game` imported from JSON; device language → else hy
- [ ] F. Fonts: Noto Sans Armenian + Noto Sans → TMP dynamic font assets with fallback, TMP default
- [ ] G. Scenes: Boot.unity (GameBootstrap, 60 fps, load Game), Game.unity (Systems/CameraRig/World/Actors/UI); temporary M0Check
- [ ] H. EditMode tests: ProtoCoords, NumberFormat, EconomyConfig, DataImport
- [ ] Verify (no Console errors, tests green, Armenian + Cyrillic render) → commit `M0: ...`

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
