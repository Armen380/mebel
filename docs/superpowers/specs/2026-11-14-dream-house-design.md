# Dream House (M10) — design

Date: 2026-11-14. Status: draft for the user's approval (builder check done; the user answered its questions).

## Intent and why

1. **App Store.** Apple rejected 1.0 under guideline 4.3(a) ("spam": too similar to other idle-arcade games).
   The game needs a feature of its own that a reviewer sees within 5–10 minutes of play.
2. **Long-term goal.** The design (01_GAME_DESIGN §1, 06_FUTURE_DREAM_HOUSE) always meant the money to end up in
   building and furnishing the player's own Dream House.

The house is built in the same proximity style as the rest of the game. It is furnished partly with furniture from
the player's own factories and partly with items bought in a Home Store next to the plot. Its look is Armenian.

## User decisions (2026-11-14)

- **Variant A: build it by hand like the rest of the game.**
  - Construction stages are yellow pads on the plot, paid with money.
  - The player carries furniture from the player's own factories into the house.
- **Home Store.** A shop next to the house where the player buys everything the factories don't make (house and
  yard items).
- **Entering the house.** The player can walk into the house and furnish, improve and look after the house and
  the yard.
- **Furnishing with fixed spots.** Each room shows a translucent outline ("a sofa goes here"). Walk up to it and
  the item is placed. Where several variants are owned, the player picks one. No free placement.
- **Style: Armenian motifs.** Pink tuff stone, arches over windows and the door, a vine pergola in the yard,
  a pomegranate tree, carpets with Armenian ornament.
- **How it's built: same scene, Home Store as a catalog panel.** No separate interior scene and no loading.
  The roof and front wall fade out when the player is inside.
- **Reviewer reach (answer 1б).** No special house tutorial and no discounted starter stages. The house grows at its
  own pace; the uniqueness is shown to Apple through the screenshots, the description and the review notes.
- **"Look after" means furnishing (answer 2а).** Buying, placing and swapping items and variants. No upkeep mechanic
  (watering, cleaning, repairs, decaying comfort) in this milestone; it may come in a later update.

## Goals

- **Reach.** The plot opens after the tutorial, and the first stage (foundation, ≈$2K) is affordable within the
  first minutes. A reviewer will most likely see the foundation, the Home Store and a yard item; the furnished
  interior reaches Apple through the screenshots (answer 1б).
- **Interior.** Four rooms with fixed slots: living room, kitchen, bedroom, bathroom.
- **Yard.** A yard with its own slots for the pergola, trees, flower beds, fountain and so on.
- **Home Store.** A small tuff building with a counter. Standing at the counter opens a catalog panel with
  House and Yard tabs.
- **Comfort score.**
  - Every placed item adds comfort.
  - Comfort gives a small permanent bonus to sale prices.
  - Completing a room gives a one-time cash gift.
- **Data and integration.**
  - All numbers live in `Design/data/dream_house.json`, imported into ScriptableObjects (project rule).
  - Saved, localized in hy/en/ru, and pooled where anything spawns.
  - 60 fps on mid-range Android.
- **Store presence.** New screenshots and description lines that lead with the house. Version 1.0.2, iOS and
  Android.

## Non-goals (this milestone)

- Free placement, rotation or a grid editor.
- A separate interior scene or loading screens.
- NPC workers or visitors in the house. The work area is the owner's only, as in the prototype placeholder.
- A second floor, house tours, or visiting other players.
- A HUD "Home" button or teleport. The plot is reached on foot.
- An upkeep mechanic (watering, cleaning, repairs, comfort decay) — answer 2а; a candidate for a later update.
- A dedicated house tutorial or discounted starter stages — answer 1б.
- IAP or ads specific to the house. The existing rewarded ad stays as it is.

## Anti-goals (failure even if it works)

- The house noticeably slows the main game, or the comfort bonus breaks the economy.
- The store listing doesn't make the house obvious: the screenshots and the description must lead with it.
- Cluttered phone UI or hard-to-hit targets.
- Frame drops on the plot.
- Old saves break.

## Constraints

- Unity 6 URP, low-poly primitives built by Editor scripts, the shared `MaterialPalette` (one material per colour,
  ghost variants exist), no physics, kinematic AABB blockers.
- Architecture rules from CLAUDE.md:
  - pure-C# logic with EditMode tests;
  - thin MonoBehaviours;
  - `GameEvents`;
  - data in ScriptableObjects;
  - no LINQ, closures or allocations per frame.
- Prototype coordinates convert through `ProtoCoords`.
- Plot geometry (`world_layout.json → dreamHouse`), in proto coordinates:
  - plot x 72–98, z −26…−4;
  - arch / entrance at z −4 (road side, facing the camera);
  - foundation centre (81, −17), 11×8 m;
  - billboard (81, −23.2);
  - work area (93.5, −15).
- `PlayerRegionRules` already lets the player onto the plot (x ≥ 62, z ≥ −25.6).
- Save is versioned JSON (`SaveData` v4). This milestone adds v5 with migration from v4 (defaults: nothing built).
- The money format stays `$1.2K`.

## Approaches considered

1. **Same scene; stages as pads; Home Store as a catalog panel; fixed slots** (chosen).
   - Reuses PadSystem (partial payment, visibility rules), the proximity transfer used by shelves, and the panel
     style of the Upgrades panel.
   - No loading. The world and the house share one state.
2. **Separate interior scene and a physical shop with a pad per item.**
   - The interior could be more detailed.
   - Costs: a load on every entry, two scenes to keep in sync, and dozens of item pads that don't fit next to
     the plot.
   - About 1.5× the work. Rejected.
3. **Everything bought in a menu (variant B).**
   - Simplest to build.
   - Rejected by the user: it plays like any shop menu and isn't distinct.

## Design

### Layout on the plot (proto coordinates; final positions are the builder's call within the plot)

```
                 road (x 85) ↓
   ┌──────────────── arch z −4 ─────────────────┐
   │ flower beds   path            ┌──────────┐ │
   │ pomegranate                   │HOME STORE│ │  ← on the work area (93.5, −15)
   │                               │ counter  │ │
   │      ┌──────────── HOUSE 11×8 ─┐└──────────┘ │
   │      │ living room │ kitchen    │  pergola    │
   │      │─────door────┼────────────│  fountain   │
   │      │ bedroom     │ bathroom   │  pool spot  │
   │      └─────────────┴────────────┘             │
   │  billboard (removed once the walls stand)     │
   └────────────────────────────────────────────────┘ z −26
```

- **House shape.** The house stands on the existing foundation outline. Its front door faces the road and the
  camera. Inner walls split it into four rooms with doorways.
- **Collision.**
  - Outer and inner walls are AABB blockers with door and doorway gaps, added to `BlockerSet` once the walls
    stage is owned.
  - Before that, the foundation area can be walked over.

### Construction stages (pads)

Four pads in front of the house, shown one at a time. Each one appears after the previous stage is built.

| # | Stage | Price (before ECON) | What appears |
|---|-------|---------------------|--------------|
| 1 | Foundation | 1 600 (≈$2K) | tuff slab, steps, stakes and strings removed |
| 2 | Walls | 8 000 | outer and inner tuff walls, arched door and window openings |
| 3 | Roof | 24 000 | low hipped roof, terracotta tiles |
| 4 | Windows & doors | 60 000 | wooden door, window frames with arches, balcony rail |

- **Pad behaviour.** Stages are new `pads.json` entries with a "previous stage owned" visibility rule.
  PadSystem's partial payment, sounds and FX apply unchanged.
- **Build animation.** Each stage pops in with the existing build effect (scaffold → pop) used for factories.
- **Prices are my call.** They are tuned so that stage 1 is reachable in the first minutes and stage 4 lands
  around the sofa or wardrobe stage of the main game. Final values go in the data file and get a balance pass in
  play-test.

### When furnishing opens

- **Interior.** Slots appear when stage 2 (walls) is owned, so the reviewer can reach furnishing early.
- **Yard.** Slots appear with stage 1.
- **Home Store.** Opens with stage 1.

### Slots

A slot is a fixed spot with:

- an id;
- a room (or the yard);
- an accepted source: a factory product type (Chair, Sofa, …) or a Home Store item group (carpet, lamp, bed, …);
- a comfort value;
- a placement pose.

Empty slots show a translucent ghost (MaterialPalette ghost material) of the item, plus a small icon tag.

| Room | Factory slots (carry in) | Home Store slots |
|------|--------------------------|------------------|
| Living room | Sofa, Table, Chair ×2 | Carpet, Lamp, TV, Painting, Plant |
| Kitchen | Kitchen, Chair ×2 | Fridge, Stove, Pomegranate bowl (decor) |
| Bedroom | Wardrobe | Bed, Nightstand, Carpet, Lamp |
| Bathroom | Sink | Bathtub, Mirror, Towel rail |
| Yard | — | Vine pergola, Pomegranate tree, Flower bed ×2, Bench, Fountain, Pool, Lamp posts |

Two consequences are intended:
- The bathroom needs a Sink, so it can only be finished after Plumbing (Lv 150). It is the late-game room.
- The yard has no factory slots.

**Factory slots.**
- Carrying the matching product into a slot's radius places it, one item per slot, using the same proximity and
  flight as stocking a shelf.
- The item is consumed and not sold.
- It shows in the slot's look, re-using that product's existing world model.

**Home Store slots.**
- Items bought in the catalog go to **home storage** (counts per item).
- Walking up to an empty slot whose group has an item in storage places it with the same flight effect.
- Storage is shown in the catalog and as a small box count on the HUD comfort chip.

**Variants.**
- Some groups have 2–3 variants: carpet ornaments, paintings, lamps, flower colours. Factory products have no variants.
- If a placed slot has other owned variants in storage, standing still on it for 0.5 s opens a small picker
  (a row of 2–3 icons). Picking swaps the item, and the old one goes back to storage.
- Comfort counts the placed item only.

**Unique items.** The pool and fountain are single items.

### Home Store

- **Building.** A small pink-tuff building with an arched front and a counter.
- **Opening the catalog.**
  - Standing still on the counter pad opens the catalog panel; walking off closes it.
  - The panel works like the Upgrades panel: modal, safe-area aware, and it closes with ✕.
- **Catalog layout.**
  - Two tabs: House and Yard.
  - Each row shows an icon, a localized name, comfort `+N`, a price and a Buy button.
  - A row shows "Owned ×N" or "Placed" when it applies.
  - Items whose slot isn't available yet are shown greyed with their requirement ("Needs walls").
- **Price range.**
  - About $300 (lamp) to about $1M+ (pool), spread so every phase of the main game has something to buy.
  - Exact prices and comfort values go in `dream_house.json` (builder fills them in, user tunes them in play-test).
- **Buying.** Buying spends money instantly (not the gradual pad payment) and plays the purchase sound.

### Entering the house

- **Detection.** When the player is inside the house footprint and stage 3 (roof) is owned:
  - the roof and the south (front) wall fade out over about 0.25 s. The wall drops to a low cut-away, or the
    material swaps to its ghost variant (builder's call, whichever reads better and costs less);
  - the camera follow offset scales to ×0.75 so the camera moves in.
- **Leaving.** Leaving the footprint reverses it.
- **Before the roof.** Before stage 3 there's nothing to hide.

### Comfort and rewards

- **Comfort.** Comfort is the sum of the placed items' comfort.
- **Sale bonus.** Sale prices get `× (1 + comfortBonus × comfort)`:
  - the sale formula gains a `homeMultiplier` term;
  - shown as "+x% income";
  - `comfortBonus` and comfort values are tuned so a fully furnished house gives about +20%. That is my call:
    noticeable, but it doesn't break the economy.
- **Room gift.** Filling every slot of a room once gives a one-time gift (data value per room), with a toast and
  confetti. It is saved so it can't repeat.
- **HUD chip.**
  - After stage 1, a small HUD chip shows the house icon, the comfort value and the income bonus.
  - It also shows the storage box count when storage isn't empty.
  - Tapping the chip does nothing in v1.

### Armenian look (primitives)

- **Palette.** New colours:
  - pink tuff `#d9967f`;
  - darker tuff trim `#b9735f`;
  - terracotta roof `#c4643f`;
  - walnut wood `#7a4a2b`;
  - vine green;
  - pomegranate red `#b3263a`.
- **Arches.** A new `LowPolyMeshFactory` arch mesh (half-ring extrusion) for the door, windows, store front and
  pergola.
- **Carpets.** Procedural textures from `TextureFactory`, a few Armenian-ornament-style patterns (geometric
  medallions, borders), 256 px, LFS.
- **Billboard and arch sign.** The billboard (house illustration, "Coming soon") is removed when the walls go up.
  The `dream.title` arch sign stays.

### Save (v5)

- `owned`: stages reuse the pad and `owned` mechanism, keyed `house_found`, `house_walls`, `house_roof`,
  `house_windows`.
- `home`:
  - `slots`: slot id → placed item id (variant);
  - `storage`: item id → count;
  - `rooms`: list of room ids whose gift was paid.
- Migration v4 → v5: an empty `home`.

### Unlocks, guide and tutorial

- **Unlock card and guide.**
  - The existing "Dream house plot" unlock card and guide arrows point to the foundation pad.
  - After stage 1, the guide points to the Home Store once, the first time.
- **Strings.**
  - The `un.dream.s` text changes from "soon you will build" to an invitation to build now.
  - New strings in en/ru/hy. The Armenian text is drafted by Claude and must be checked by the user.

### Localization keys (new)

- Stage names.
- Room names.
- Item names.
- Catalog UI: tabs, Buy, Owned ×N, Placed, Needs …
- Comfort chip.
- Room-complete toast.

### Store and review (release step, not code)

- **Release.** Version 1.0.2 (iOS build 4, Android code 4). 1.0.1 is not released on its own: 1.0.2 carries its
  changes, which are already on main (Claude's call).
- **iOS.** The rejected 1.0 version record in App Store Connect is renamed to 1.0.2, and the new build is submitted
  for it.
- **Android.** Per the user's earlier decision, 1.0.2 goes to Google Play after 1.0 is published there.
- **Screenshots.** New first screenshot of the furnished Armenian house and a yard screenshot, for iPhone and
  iPad sizes and Android.
- **Text.** The description's first lines and the "What's new" text lead with the house.
- **Notes for Apple.** A reply in the review notes that lists the new unique feature.

## Left to the builder

- Exact slot positions and poses inside the 11×8 footprint.
- Item models built from primitives.
- Catalog prices and comfort values within the stated ranges.
- The fade technique for roof and wall.
- The variant picker's exact look.
- How storage and slot state are split between pure-C# classes and adapters, following the project's
  architecture rules.
- Test coverage of the pure logic:
  - slot acceptance;
  - comfort sum and multiplier;
  - room completion;
  - save migration;
  - stage visibility rules.
