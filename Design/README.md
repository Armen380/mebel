# Furniture Factory — Unity Mobile Handoff

Working title: **Կահույքի Գործարան / Furniture Factory / Мебельная фабрика**
Genre: casual 3D idle-arcade tycoon ("My Perfect Hotel"-style carry-and-upgrade loop)
Target: iOS + Android, portrait-first (landscape must also work), Unity 6 LTS + URP.

This package contains everything needed for Claude Code to plan and rebuild the playable web prototype as a native Unity mobile game, with the same mechanics, numbers, layout and look.

## What is in here

| Path | What it is |
|---|---|
| `../CLAUDE.md` | Instructions for Claude Code (merged into the project root CLAUDE.md). |
| `docs/01_GAME_DESIGN.md` | Full game design: core loop, every feature, progression, unlock order. |
| `docs/02_SYSTEMS_SPEC.md` | Precise behaviour of every system (stacks, zones, machines, pads, AI state machines, customers, cars, trucks, robots, unlocks, save). This is the source of truth for logic. |
| `docs/03_UNITY_ARCHITECTURE.md` | Proposed Unity project structure, packages, scripts, ScriptableObjects, scene hierarchy, mobile performance rules. |
| `docs/04_IMPLEMENTATION_PLAN.md` | Milestones in build order, each with acceptance criteria. |
| `docs/05_ART_UI_AUDIO.md` | Visual style, colour palette, fonts, UI/HUD layout, models list, VFX, SFX. |
| `docs/06_FUTURE_DREAM_HOUSE.md` | Planned (not yet built) Dream House mode, so the architecture leaves room for it. |
| `data/*.json` | All tunable data extracted from the prototype: products, upgrades, pads, economy formulas, skins, tutorial, world layout coordinates, localization (hy / en / ru). |
| `reference/prototype.html` | The complete playable prototype (single file, three.js). It is the reference implementation. When the docs and the code disagree, the code wins. |
| `reference/screenshots/*.png` | 15 screenshots of every area of the prototype. |

## How to run the prototype

Open `reference/prototype.html` in Chrome (needs internet for three.js r128 from cdnjs and Google Fonts).
Controls: WASD / arrows, Q throws carried items away. On a phone: drag anywhere for the virtual joystick.
The menu has a **Test: +25 Lv, +250K ֏** button for jumping ahead (press 6 times to reach Lv 150 and plumbing).

## How to use this with Claude Code

1. Create an empty Unity 6 LTS project (3D URP template), e.g. `FurnitureFactory/`.
2. Copy this whole folder into the project as `FurnitureFactory/Design/` and copy `CLAUDE.md` to the project root.
3. Open the project folder in Claude Code and start with:

   > Read CLAUDE.md and everything in Design/. Then write a detailed implementation plan for Milestone 1 from Design/docs/04_IMPLEMENTATION_PLAN.md, list the scripts and assets you will create, and wait for my OK before writing code.

4. Go milestone by milestone. After each milestone, play it in the Editor and on a phone, then continue.

Recommended Claude Code setup: install the Unity MCP / Unity CLI integration if available so Claude Code can create GameObjects, run play mode and read the console directly.
