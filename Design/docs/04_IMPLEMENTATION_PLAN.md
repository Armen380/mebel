# 04 — Implementation Plan (milestones)

Each milestone ends with: no Console errors, a play-test checklist for the user, a commit.

## M0 — Project setup
- Unity 6 LTS URP project, packages (Input System, TMP, Cinemachine, Localization), folder layout, Boot + Game scenes.
- Editor `DataImporter`: reads `Design/data/*.json` → ScriptableObjects. Localization tables hy/en/ru imported from JSON.
- Fonts: Noto Sans Armenian + Noto Sans TMP assets with fallback chain; check Armenian and Cyrillic glyphs render.
- `ProtoCoords.ToUnity(x,z) => new Vector3(x,0,-z)`.
**Done when**: data assets exist and print correct values; a test TMP text shows "Կահույքի Գործարան / Мебельная фабрика".

## M1 — Player, camera, input, world blockout
- Ground, main road, factory row lots, shop floor, fences as primitives at layout coordinates.
- Player character (blocky primitive rig), floating joystick + keyboard, kinematic movement with AABB blockers and region bounds, Cinemachine follow (offset from layout, portrait ×1.45).
**Done when**: player walks everywhere allowed and is blocked by buildings/fences; feels like the prototype on a phone.

## M2 — Items, stacks, zones, trees, sawmill, chair factory
- Item prefabs, `ItemStack` with arc tweens, carry layout, pile layouts.
- Resource nodes (trees: chop, fall, regrow), sawmill + chair machine with in/out zones and counters.
- Throw button.
**Done when**: chop → logs → sawmill → planks → chair workshop → chairs loop works with correct timings and capacities.

## M3 — Shop, customers, registers, money, XP, HUD
- Shelves, walk-in customers (queues, bubbles, patience), register serving by player, bills pile, cash collection, money/level HUD, floating texts, level-up toast.
- Tutorial 8 steps with arrow.
**Done when**: full tutorial completes; money and XP match prototype formulas.

## M4 — Upgrade pads, building growth, upgrades panel
- `UpgradePad` paying mechanic and visuals; factory speed/qty, storage multipliers, `BuildingVisual` growth + bounce + confetti + Lv tag; occlusion fade.
- Upgrades panel with groups, locks, badges; player upgrades.
**Done when**: every pad in `pads.json` works; buildings grow; panel prices match `upgrades.json`.

## M5 — Product line expansion & shop growth
- Factory lots with Buy pads gated by level, Sofa/Wardrobe/Table/Kitchen.
- Shop expansion (animated wall), register pads, up to 6 registers, shelf capacity.
- Unlock cards + guide arrow, save/load + autosave.
**Done when**: from a fresh save you can reach Lv 35 and own all furniture factories; restart restores everything.

## M6 — Workers & robots
- Lumberjack, Carrier, Stocker, Cashier, Manager, Consultant, Robot (scoring + task tag), Second sawmill + back yard + fader.
**Done when**: a fully staffed factory runs without the player; robots prioritise empty shelves with waiting customers.

## M7 — Delivery & car park
- Truck bays, trucks state machine, dock zones, payout pop next to balance.
- Car park, cars, car customers crossing the zebra.
**Done when**: trucks and cars loop indefinitely without getting stuck (soak test 30 min).

## M8 — Plumbing & Building materials
- Mines yard (gate opens), clay/iron rocks, Plumbing + Materials factories, materials shop with its own door/shelves/registers, Miner, Section carrier, Section cashier, routing through the factory gap.
- Dream House plot placeholder with road, arch, billboard (localized), work area.
**Done when**: Lv 150 content works end-to-end.

## M9 — Polish & release prep
- Menu (language switch, skins with orbit camera), settings (sound, haptics, quality), SFX/music, haptics on pickups/purchases, app icon, splash.
- Optional with approval: rewarded ads (2× delivery payout, instant cash), IAP (no ads, starter pack), analytics, cloud save.
- Performance pass on a low-end Android; build AAB/IPA.

## M10 (later) — Dream House mode
See 06_FUTURE_DREAM_HOUSE.md.
