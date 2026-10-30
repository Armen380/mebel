# 01 — Game Design Document

## 1. Pitch
You run a furniture business in a small low-poly town. Chop trees, saw planks, carry them to workshops, put finished furniture on shop shelves, serve customers, ship orders by truck, and reinvest everything into bigger factories, more staff, robots and new product lines. Long-term goal: earn enough to build and furnish your own **Dream House** (future mode).

Reference feel: *My Perfect Hotel*, *Idle Lumber Empire*, *Burger Please*. One finger, constant small rewards, things physically stack in your arms and visibly grow.

## 2. Core loop
1. **Gather**: walk next to a tree → auto-chop (axe swing) → tree falls → 2 logs fly into your arms. Trees regrow in 9 s.
2. **Process**: stand on a factory's input pad (↓) → items fly from your stack into the input pile. The machine converts input → output on a timer.
3. **Collect**: stand on the output pad (↑) → products fly onto your stack (only one item type at a time).
4. **Sell**: drop furniture on its shop shelf (or on a parked truck). Customers come, take an item, queue at a register, get served, leave a bill on the counter.
5. **Cash in**: stand at the register's cash pad → bills fly to you → balance increases.
6. **Invest**: stand on yellow ground pads (factory speed/quantity, new factory, trucks, parking, registers, shop expansion), or buy worker/player upgrades in the Upgrades panel.

Everything is proximity-based: no tapping on world objects. Standing still for 0.3 s on a yellow pad starts paying into it gradually (money visibly flies onto the pad, pad fills green bottom→top, remaining price counts down). Partial payment is kept.

## 3. Production chains
| Product | Input | Input/cycle | Base cycle | Base price ֏ | XP | Unlock Lv | Factory cost ֏ |
|---|---|---|---|---|---|---|---|
| Chair | planks | 2 | 2.6 s | 500 | 3 | 1 (owned) | — |
| Sofa | planks | 3 | 3.4 s | 1 500 | 6 | 5 | 15 000 |
| Hallway wardrobe | planks | 4 | 4.2 s | 3 000 | 9 | 12 | 60 000 |
| Table | planks | 3 | 4.0 s | 5 000 | 12 | 22 | 150 000 |
| Kitchen furniture | planks | 5 | 5.2 s | 8 500 | 16 | 35 | 400 000 |
| Plumbing (sink) | clay | 2 | 5.0 s | 16 000 | 25 | 150 | 1 500 000 |
| Building materials | iron | 2 | 5.5 s | 24 000 | 30 | 150 | opens free with Plumbing |

Sawmill: 1 log → 2 planks, 1.6 s. A second sawmill can be bought (20K) in the back yard behind the first one.
Clay and iron are mined from rocks in the **mines yard** behind the plumbing/material factories (opens with plumbing). Rocks shrink when mined and regrow after 12 s; iron is harder (1.8× chop time) than clay (1.5×).
Prices/costs above are base values; see `data/economy.json` for the ECON multipliers (sale ×0.85, costs ×1.25, truck ×1.4) and the exact formulas.

## 4. Progression
- **XP / Level**: every sale gives the product XP (×items for multi-buy). XP for next level = `round(8 + 4.5 × level)`. ≈51.5K XP to reach Lv 150.
- Factories unlock to *buy* at their level; a "Buy" pad appears on the fenced empty lot where the factory will stand.
- **Shop level 0–5** (expansion pad): physically widens the shop (right wall slides out), +3 shelf capacity, +1 register slot, more customers, +1 car-park slot. Staff unlocks by shop level: Lv 2 Stocker, Lv 4 Manager, Lv 5 Consultant.
- **Plumbing (Lv 150, 1.5M)** opens in one go: Plumbing factory, Building-materials factory, mines yard (clay + iron), Building-materials shop (separate shop block with its own door, shelves and registers) and the Plumbing & Materials staff group.
- **Dream House plot** (east, at the end of its own road) is visible from the start as a "Coming soon" placeholder.

### Unlock cards
Whenever something new becomes available, a "NEW" card slides in at the top (icon, title, one-line hint) and a yellow arrow points at the place for 12 s. Each card shows once (persisted). Triggers: factory buyable, staff unlocked, new register slot, second sawmill (after tutorial), mines, materials shop, dream-house plot (after tutorial), new skin.

## 5. Upgrades
### Ground pads (in the world)
Per factory (incl. both sawmills): **Speed** (max 8, cycle ÷ (1+0.35·lv)) and **Quantity** (max 3, parallel batches = 1+lv). Both also raise that factory's storage: ×(1 + 0.6·qty + 0.1·speed).
Buildings visibly grow with each upgrade: Quantity adds a floor with windows; Speed adds chimney (Lv1), roof fan (Lv3), second chimney (Lv5), metal tank (Lv7); trim colour tiers brown→red→blue→gold; lit windows from tier 2; gold flag at max. Each purchase: squash-and-stretch bounce + confetti + floating text "×2 output · 38 slots". A "Lv N · ×k" tag floats above every factory.
Other pads: New truck (max 4), Parking (truck bays 1→3), Register (+1 main register, gated by shop level, pad sits on the next free slot), Materials-shop 2nd register, Shop expansion (max 5), Second sawmill, Factory purchase pads.

### Upgrades panel (HUD button)
Groups and items (costs in `data/upgrades.json`):
- **Player**: Capacity (5+2/lv items, max 8), Speed (+12%/lv, max 6), Sharp axe (max 6).
- **Workers**: Lumberjack (max 4), Carrier (max 4), Robot carrier (max 4).
- **Plumbing & Materials** (locked until plumbing): Miner (4), Section carrier (3), Section cashier (2).
- **Shop staff**: Cashier (8), Stocker (3, shop Lv 2), Manager (2, shop Lv 4), Consultant (2, shop Lv 5).
- **Business**: Advertising (more customers, max 6), Quality (+25% price per level, max 8).
Locked rows show the requirement on the button ("Shop Lv 2", "Plumbing").

## 6. Characters
- **Player**: blocky low-poly worker, 5 skins (Lumberjack, Craftsman, Ranger, Night owl, Golden — unlocks at 100K total earned). Skin choice in the main menu, the menu camera orbits the character.
- **Lumberjack**: chops nearest unreserved tree, carries 4 logs to the emptier sawmill.
- **Carrier**: simple rules — furniture → its shelf (else a truck), planks → emptiest plank factory.
- **Robot carrier**: hovering robot, faster (5.2) and carries 8. Uses **need-based priority scoring** (see spec): customer waiting at empty shelf > idle factory without planks > truck waiting > nearly full factory output. Shows its current task in a small tag ("Shelf · Chair", "Planks → Sofa", "! " prefix when urgent). Robots never stand at registers.
- **Miner**: walks through the factory gap into the mines yard, mines clay or iron (whichever factory input is emptier), delivers.
- **Section carrier**: only plumbing/materials → materials shop or trucks.
- **Cashier / Section cashier**: stand at registers and serve. Without a cashier the player must stand at the register cash pad to serve (player serves 1.4× faster).
- **Stocker**: only factory output → shop shelves.
- **Manager**: walks between registers collecting bills straight into the balance.
- **Consultant**: stands in the shop; customers +60% patience and pay +15% per consultant level.
- **Walk-in customers**: random clothes, enter through the shop door, queue at the shelf of the product they want (bubble icon if empty), take 1, queue at the least busy register, pay, leave. Angry face and leave after 45 s with nothing.
- **Car customers**: drive in on the road, turn into the car park across the road, park nose-in, driver walks over the zebra crossing into the shop (or the materials shop), buys, walks back, reverses out and drives away.

## 7. Trucks / delivery
Delivery yard west of the shop with 1–3 bays. A truck drives in along the road, parks, waits for an 8-item order of any furniture. When full it drives off; after it leaves the screen the payout (1.4× sale price, plus XP) is added and a small green "+12K ֏" chip with a truck icon pops next to the balance (no big centre message). It returns after 10 s.

## 8. World map (top view, prototype coordinates; see data/world_layout.json)
```
 z=-27 ┌ saw yard (Sawmill 2) ┐                 ┌ mines yard (clay | iron) ┐     ┌ Dream House plot ┐
 z=-13.6 fence ─────────────┘  ────────────────── └─────────── fence ───────┘     │ foundation, sign │
 z=-10   [Saw1][Chair][Sofa][Wardrobe][Table][Kitchen]   [Plumbing][Materials]     └──── arch ──┬─────┘
 z=-5    input/output pads row                                                                   │
 z=0..9.7  delivery yard |  MAIN SHOP (grows east)  →|   | MATERIALS SHOP |                     │ own road
 z=11..16  ══════════════ main road (trucks east lane, cars west lane) ═══ zebra x=20 ════════════╧═══
 z=18..25           car park (8 slots)
 forest x<-18
```

## 9. Menu, HUD, meta
- **Main menu** (also the pause screen): title, language switch (Հայ / EN / RU), skin carousel, Play/Continue, New game (two-tap confirm), Test button (dev builds only).
- **HUD**: balance pill (top-left) with level pill + XP bar below, Upgrades button (badge when something is affordable), Pause. Tutorial bar under the top row (8 steps, arrow in the world). Unlock card slot below it. Throw button bottom-right when carrying. "FULL" tag over the player when at capacity.
- **Tutorial (8 steps)**: chop → logs to sawmill → take planks → planks to chair workshop → take chairs → chairs to shelf → serve & collect cash → buy first pad.

## 10. Difficulty target
Medium. First new factory (Sofa, Lv 5) ≈ 26 chair sales. Prices/costs/XP are centralised so balancing is a data change.
