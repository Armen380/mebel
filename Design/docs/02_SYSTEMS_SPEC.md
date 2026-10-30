# 02 — Systems Specification (engine-neutral)

Function names in brackets refer to `reference/prototype.html`. All numbers: `data/economy.json`.

## 1. Item stacks  [class Stack, sendTo, move, carryLayout, pileLayout]
- An item = a typed prefab: `log, plank, clay, iron, bill, chair, sofa, wardrobe, table, kitchen, sink, material`. Each type has a stack height H (log .30, plank .11, clay .28, iron .24, material .30, bill .055, chair .50, sofa .44, wardrobe .84, table .50, kitchen .58, sink .56).
- `Stack { anchor Transform, layout fn, cap, items[], incoming, type, fixedType }`. `n = items.Count + incoming` (items in flight count, so capacity checks are race-free). A non-fixed stack takes the type of its first item and becomes untyped again when emptied.
- **Carry layout**: vertical column above the hands, offset (0, i·H, 0) on an anchor at (0, 0.92, 0.56) local to the character.
- **Pile layout(cols, rows, sx, sz)**: grid layers; item i → layer ⌊i/(cols·rows)⌋.
- **Transfer (sendTo)**: reparent to world, tween position from start to the live target slot over 0.22–0.35 s with a sine arc (+1 unit at mid), then parent to the anchor and snap to its layout slot. `incoming++` at start, `--` at end. Player transfer cadence: one item every 0.075 s (cash 0.035 s). Workers 0.12 s.

## 2. Zones  [addZone]
Flat dashed square markers (2.4 m) with an arrow glyph and a localized label (e.g. "PLANKS", "SHELF", "REGISTER"). Radius 1.3. Kinds:
- `drop` (accepts(type), canAccept()): player/worker unloads matching items.
- `pickup`: player loads if empty-handed or same type and has room.
- `cash`: bills pile on the register counter; standing here collects them (each bill flies to the player then adds its value) and also counts as "player is serving this register".
Only the first matching zone acts per tick. Zones have `active()`; inactive ones are hidden and ignored. Counter tags above piles show `n/cap`.

## 3. Machines (factories)  [updMachine]
State idle/busy. When idle: `k = min(1+qtyLv, ⌊input.items/inN⌋, ⌊(outCap-out.n)/outN⌋)`; if k≥1 consume k·inN items (fly into the machine mouth and despawn), start timer `baseCycle/(1+0.35·speedLv)`. On finish spawn k·outN outputs at the mouth and send them to the output pile. Input/output capacities = base × (1 + 0.6·qty + 0.1·speed).
Visual: sawmill blade spins while busy; press hammer bobs while busy. Chimney smoke puffs (rate ↑ with speed and when busy), roof fan spins.

## 4. Building growth  [setBuildingLevel]
Rebuild a "deco" child group from (speedLv s, qtyLv q):
- tier = min(3, ⌊(s+q)/3⌋); trim colours [#6d4325, #a23b2b, #3d6f8a, #d9a520]; windows lit (#ffe39a) from tier 2, side windows from tier 1.
- q floors of 1.25 m (4.9×3.5 footprint, 4 windows each, trim band). Roof sits on top floor.
- s≥1 chimney, s≥5 second chimney, s≥3 roof fan, s≥7 tank, s=8 & q=3 gold flag.
- On purchase: bounce (scale y +16% / xz −6% decaying sine 0.55 s), 28 confetti cubes, SFX, floating text.
- **Occlusion fade** [fadeBuildings]: when the player is behind a building (|dx|<4.2 and building.z−15 < player.z < building.z−2.3 in proto coords), swap all its materials to cached transparent clones (opacity .22, no shadows). In Unity: material property block or a dithered "occluded" shader.

## 5. Resource nodes  [makeTree, makeRock, tryChop, updNode]
Node {type log|clay|iron, alive, regrow, hardness, reservedBy}. Player within 1.6 m of the nearest alive node with room → chop: progress += dt·rate; every 0.3 s a shake + chop SFX; when progress ≥ chopTime·hardness: node dies (tree topples over 0.4 s / rock shrinks), spawn min(2, room) items into the chopper's stack, regrow timer (tree 9 s, rocks 12 s), then grow back with an elastic scale-in. Workers reserve their target node.

## 6. Ground pads  [addPad, updPads, drawPad]
Pad = 1.8 m square texture redrawn when the remaining price changes: honey background, white glyph, remaining price "1.5K ֏", green fill rising bottom→top with progress. Hidden when `!show()` or at max level.
Paying: player within 0.95 m, standing still ≥ 0.3 s, money > 0 → each frame `amt = min(money, remaining, ceil(price·dt/1.4))`, money -= amt, paid += amt; a bill flies from player to pad every 0.07 s with a coin SFX. When paid ≥ price: level++, paid=0, `onLevel(level)`, floating "done" text, save. Price = `round(base·ECON.cost·mul^level/50)·50`.

## 7. Player  [updPlayer, collide]
Kinematic. Input vector (joystick or keys) → speed 4.4·(1+0.12·speedLv). Facing lerps to movement direction. Collision = push-out from AABB list `blocks` (buildings, shop walls, register stalls, materials-shop walls, sawmill 2, dream-house fence) with 0.3 m radius, plus region rules (see world_layout.playerBounds). Throw: all carried items fly 1.5 m forward with random spread and shrink away.

## 8. Workers (AI)
All kinematic `moveTo(target, speed)` with arrive threshold 0.06 m. Walking animation = leg/arm swing; carrying = arms forward; chopping = axe arm swing.
- **Lumberjack** [updLumber]: if carrying ≥ cap → deliver to `sawIns()[0]` (active saw input with smallest n), unload at 0.12 s cadence, else pick nearest alive *unreserved* tree, reserve, chop at 0.75 rate.
- **Carrier / Stocker / Section carrier / Robot** [updCarrier]: job = {from, to, want}. Phase get: go to `from`, take until cap/want or source empty. Phase put: go to `to`, unload while `to.canAccept()`; if blocked 1.5 s drop the job. Leftover items with no job pick a target by type. Idle → rest spot.
  - `pickJob(only, dockFirst, sec)`: factory outputs with items (largest first) → `goodsTarget(type)` = the emptier of shelf (and materials-shop shelf) with room, else a free truck bay; then planks from the fullest saw output → emptiest plank-factory input. Stocker: shelves only. Section carrier: plumbing/material only.
  - **Robot scoring** [robotJob]: candidate jobs with score; pick the max > 0.15.
    - Shelf job: `(1 − n/cap) + 1.5·waitingCustomers + (empty?1:0) + (factoryOutput>80%?1:0) − 0.9·otherRobotsHeadingThere`.
    - Truck job: `1.1 + 0.8·(truck.n/8) + (outputFull?1:0) − 0.9·busy`.
    - Planks job: `1.2·(1 − in.n/inCap) + (factoryIdleAndStarving?1.6:0) − 0.9·busy`.
    - All minus distance/60. `want` = free room at the target. Label + urgent flag for the floating tag.
  - Routing [routeVia/goTo]: trips between the front yard and the mines yard go via (53,−6.2)↔(53,−14.4) (gap east of the materials factory).
- **Miner** [updMiner]: way-points through the factory gap (44,−6.2)↔(44,−14.6); picks clay vs iron by which factory input has the lower fill ratio; mines, returns, unloads.
- **Cashier / Section cashier** [assignStaff, updCashier]: every frame section cashiers take materials-shop registers (6,7), then cashiers take remaining active registers in order [0,6,1,2,7,3,4,5]. Stand at (x−1.15, z+0.1) facing the counter; `post=true` when arrived.
- **Manager** [updManager]: target = active register with most bills; collect one bill every 0.08 s straight into the balance.
- **Consultant**: idle near (7+7·idx, 6.4), sways.

## 9. Customers  [spawnCustomer, updCustomers, leave]
State machine: (way-points) → `shelf` → `reg` → `out`.
- Spawn walkers every `max(1.1, 5 − 0.5·ads − 0.3·shopLv)` s while walk-ins < `4 + ads + 2·shopLv`. Want = random owned product. Path: sidewalk spawn → door-out → door-in (main or materials shop by product).
- Shelf queue per shelf: slot 0 at (shelf.x, shelf.z+1.45), others +0.85 z, alternating ±0.35 x. Front customer takes 1 item when available (0.35 s), then goes to the least-busy register of its shop (via approach point z+3.6).
- Register queue: (x+1.25, qz0 + qi·1.05). Front customer is served only if a server is present (player on cash pad ×1.4, cashier ×1). After 0.9 s accumulated: bill (value = salePrice × n × (1+0.15·consult)) flies onto the counter pile, XP added, floating "+500 ֏", leave.
- Patience 45 s (×1.6 with consultant) while waiting at an empty shelf → angry face, leave. Bubble shows the wanted product icon when the shelf is empty; a cash icon when waiting at a register with nobody serving.
- **Car customers** [spawnCar, updCars, carLeave]: every 6–11 s if a car-park slot < `min(8, 4+shopLv)` is free. Car path: (140,12.3) → driveway (33,12.3) → aisle (33,19.6) → (slotX,19.6) → (slotX,22.6) nose-in; speed 10 on road, 3.4 in the lot, heading lerps. Then a customer spawns beside the car and walks (slotX+1.15,19.6) → (doorX,18) → door. On leaving it walks back the same way; when it reaches the car it despawns and the car reverses to the aisle, drives to (33,14.6) and east to (140,14.6), then frees the slot.

## 10. Trucks  [makeTruck, updTrucks]
States: away(10 s) → in (drive along lane 14.6 from x −80 to bay x, decelerating) → park (move to z 12.3) → bay (accept furniture from dock zone until 8) → wait 0.6 s → unpark → out (accelerate to 18 m/s east) → at x>80 pay out (Σ round(salePrice·1.4)), XP, small money pop → away. One truck per bay; number of bays = 1 + parking level.

## 11. Shop expansion  [shopW, layoutShop, refreshBlocks]
Target wall x = 25 + 4.2·lv; current x lerps 3/s. Floor plane scales, floor stripes beyond the wall hidden, right wall + plants move, front-right wall segment scales. Blockers recomputed from the target. Register i is active when `i < 1 + min(regLv, shopLv)` (main 0–5), materials-shop register 6 with plumbing, 7 with its pad.

## 12. Economy
`salePrice = round(base·0.85·(1+0.25·quality)/10)·10`. Level XP need `round(8+4.5·lv)`. Panel upgrade cost `round(base·1.25·mul^lv/50)·50`. Truck payout ×1.4. Tutorial and unlock gates as in `data/`.

## 13. Unlocks & notifications  [checkUnlocks, notify, updUnlock]
`checkUnlocks(silent)` runs on boot (silent: just marks already-unlocked ids as seen), level-up, shop level change, plumbing purchase, quest completion, money ≥ 100K. Each id shows once: queue of cards, 4.6 s each, only during play. Optional target sets a guide arrow for 12 s (if no tutorial target) until the player is within 1.5 m.

## 14. Tutorial  [QUEST, emit]
8 steps, events `chop, drop(zoneId), pick(zoneId), cash, pad`. A bobbing cone arrow above the current target. Step text from localization `q1..q8`.

## 15. Localization  [I18N, t(), applyLang, TEXT_REDRAW]
Keys in `data/localization_{hy,en,ru}.json` ({name} placeholders). Includes world texts (building signs, zone labels, billboard). In Unity: Unity Localization string tables + Smart Strings; world signs use TextMeshPro (3D) so they update live on locale change. Default locale: saved choice, else device language (ru/en), else hy.

## 16. Save  [S, save()]
```json
{
  "version": 3,
  "money": 0, "total": 0, "xp": 0, "level": 1,
  "lv":   { "cap":0,"speed":0,"axe":0,"lumber":0,"carrier":0,"robot":0,"miner":0,"secCarrier":0,"secCashier":0,
            "cashier":0,"stocker":0,"manager":0,"consult":0,"ads":0,"quality":0 },
  "pads": { "<padId>": { "lv":0, "paid":0 } },
  "owned": { "chair": true, "sofa": false, "...": false, "saw2": false, "house": false },
  "skin": "lumber", "quest": 0, "lang": "hy",
  "seen": { "<unlockId>": 1 }
}
```
Item piles and worker positions are not saved (rebuild workers from `lv` counts on load; piles start empty). Autosave every 3 s, on pause/background, after every purchase.
