# Mebel — Furniture Factory (Unity mobile)

You are building a Unity 6 (URP) mobile game that recreates a finished web prototype
("Կահույքի Գործարան / Furniture Factory / Мебельная фабрика") 1:1 in mechanics, numbers and layout,
then makes it production-quality for iOS/Android.

## Session start (ALWAYS do this first)

1. Read [PLAN.md](PLAN.md) before doing anything else in a new session.
2. Continue from the task marked **In progress**, or from the first unchecked step.
3. If the user asks for something new, add it to PLAN.md before starting work.

## Plan file rules

- Every piece of work gets a plan in [PLAN.md](PLAN.md): a task heading, a date, and a checklist of steps.
- Write the plan to PLAN.md **before** starting the work, not after.
- Tick steps (`- [x]`) as soon as they are done, so a fresh session can pick up exactly where work stopped.
- When a task is finished, move it under **Done** with a one-line result.
- Note decisions, blockers and anything a fresh session would need to know under the task.

## Source of truth (Design/)

- `Design/reference/prototype.html` is the reference implementation (three.js). Read the relevant part
  of it before implementing any system. If a doc and the prototype disagree, the prototype wins —
  note the discrepancy in PLAN.md.
- `Design/docs/02_SYSTEMS_SPEC.md` explains the prototype logic in engine-neutral terms.
- `Design/docs/04_IMPLEMENTATION_PLAN.md` — milestones M0…M10 with acceptance criteria.
- `Design/data/*.json` holds all numbers. Import them into ScriptableObjects (menu `FF/Import Design Data`);
  never hard-code tunables in MonoBehaviours.
- `Design/reference/screenshots/` shows the intended look.
- `Design/` lives outside `Assets/` on purpose: Unity does not import it.

## Coordinate conversion

Prototype uses +x east, +z south (toward the road and the camera), y up. In Unity use **(x, y, -z)**
so the camera sits at negative Z looking toward +Z. All positions in `Design/data/world_layout.json`
and `pads.json` are prototype coordinates; convert once in `ProtoCoords.ToUnity`. Runtime code works
in Unity coordinates only. 1 unit = 1 m.

## Non-negotiables

- Portrait-first mobile, 60 fps on a mid-range Android (e.g. Snapdragon 7-series), works in landscape too. Respect safe areas.
- Floating virtual joystick anywhere on screen (touch), WASD/arrows in Editor. Q / Throw button drops carried items.
- All gameplay text goes through Unity Localization with three locales: `hy` (default), `en`, `ru`.
  Keys and strings are in `Design/data/localization_*.json`. Fonts cover Armenian and Cyrillic
  (Noto Sans Armenian + Noto Sans, TextMeshPro font assets with fallback).
- Currency: US dollar, sign before the number — `$430`, `$1.2K`, `+$430` (user decision 2026-10-31; the prototype used
  the dram `֏` after the number). Number format: 1.2K, 3.4M (`fmt()` in the prototype → `NumberFormat`).
- Save with a versioned JSON in `Application.persistentDataPath`, autosave every 3 s and on pause/quit. Schema in 02_SYSTEMS_SPEC.md §Save.
- No physics for gameplay. Movement, carrying, stacks and AI are kinematic and deterministic, like the prototype. Simple AABB blockers for buildings/walls/fences.
- Pool everything that spawns repeatedly (items, bills, customers, cars, particles, floating texts).

## Architecture & code conventions

- Code lives in `Assets/_Game/Scripts/`, one assembly definition per layer:
  `FF.Core ← FF.Data ← FF.Gameplay ← FF.UI` (dependencies point down only), plus `FF.Editor`
  and `FF.Tests.EditMode`. `FF.AI` and `FF.Save` are added in their milestones. Namespaces match the assemblies.
- Logic that can be tested without a scene (collision, region rules, formulas, number format) lives in
  plain C# classes and is covered by EditMode tests. MonoBehaviours are thin adapters.
- One responsibility per MonoBehaviour. Data in ScriptableObjects. Systems talk through the static
  `GameEvents` hub (e.g. `OnMoneyChanged`, `OnLevelUp`, `OnPadCompleted`, `OnUnlock`).
- No `FindObjectOfType` in Update. Cache references. No LINQ, closures or string building in per-frame code.
- Unity Input System, TextMeshPro, Cinemachine 3 (follow camera), URP, Unity Localization.
  DOTween is allowed for UI/pop tweens (or a tiny own tween helper).
- Art: simple low-poly primitives first (as in the prototype); swap in proper models later through prefabs only.
- The world blockout is generated into `Game.unity` by the Editor `LayoutBuilder` (menu `FF/Build World Blockout`) from data.

## Workflow

- Work milestone by milestone from `Design/docs/04_IMPLEMENTATION_PLAN.md`. Before each milestone,
  post a plan (files, prefabs, ScriptableObjects, scene changes) and wait for the user's approval.
- If something is unclear, or you have doubts or ideas — ask the user first, implement after.
- After each milestone: enter Play Mode, check the Console for errors, run the tests, and give the user a short test checklist.
- Commit after each milestone with a clear message (branch per milestone, merged into `main` after the user's play-test).
- Ask before adding third-party packages, ads, analytics or IAP SDKs.

## Project facts

- Unity Editor: 6000.6.7f1 (Unity 6), URP, Input System. (The design docs say "6000.0 LTS"; we use 6000.6.)
- Unity CLI is installed at `~/.unity/bin/unity` (if `unity` is not on PATH, use that full path).
- The project has `com.unity.pipeline`, so a running Editor can be driven live:
  - `unity status` — check the Editor is connected (state `ready`).
  - `unity command` — list available command groups (scene, gameobject, prefab, material, build, ...).
- When an Editor is connected, change scenes/prefabs/assets through `unity command` or Editor scripts,
  not by hand-editing `.unity` / `.prefab` / `.asset` files.
- Editor tooling (menu **FF**), run in this order on a fresh clone: Import Design Data → Setup Fonts →
  Setup Render Settings → Setup Scenes → Build Game Scene (rebuilds item prefabs, world blockout, production
  zones/machines, player prefab, systems, input, camera, HUD).
- Tests: `unity command test run --mode EditMode`. Play Mode automation tips are in PLAN.md (M1 notes).
- Git: repo in the project root, Git LFS for fonts/images/models/audio. Remote `origin` =
  https://github.com/Armen380/mebel (public). `gh` is installed and logged in by the user (keyring):
  Claude pushes branches and opens/merges PRs with `gh`. Never run `gh auth login`/enter credentials;
  if auth breaks, ask the user to log in again.

## Communication

- The user writes in Armenian (often in Latin letters). Reply in Armenian.
