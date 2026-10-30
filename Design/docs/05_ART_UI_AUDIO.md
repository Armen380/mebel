# 05 — Art, UI, Audio

## Visual style
Bright, low-poly, flat-shaded (no textures except signs/UI). Chunky blocky characters (box head, box body, box limbs). Soft directional light from the south-east, hemisphere ambient (sky #ffffff / ground #7a9a55), sky & fog colour #bfe3f0 (fog 42–95 m). See `reference/screenshots/`.

## Palette (UI tokens)
| Token | Hex | Use |
|---|---|---|
| walnut | #2b1d14 | panels, pills, sign backgrounds |
| walnut-2 / -3 | #3a281b / #523a27 | cards, disabled |
| honey | #f3b33d | primary buttons, pads, accents |
| honey-dark | #c4861a | button shadow |
| cream | #fbf1de | text on dark |
| muted | #cbb697 | secondary text |
| leaf | #5cae4a / #3d8a31 | buy buttons, XP, pad fill, cash chips |
| danger | #d9573b | badges, FULL tag, angry, "NEW" kicker |
World: grass #9cce68, yard paving #e8d29f, road #5d5a57, sidewalk #d8d0c0, shop floor #cfa877, fences #a77447.
Factory wall/roof colours per product in `data/products.json`.

## Typography
Noto Sans Armenian (Armenian) with Noto Sans fallback (Latin/Cyrillic), weights 700/800/900. Big rounded-feel bold numbers; tabular numerals in counters.

## HUD (portrait)
- Top-left: balance pill (coin icon "֏" + amount), below it level pill "Lv N" + XP bar. Delivery payouts pop as a small green chip with a truck icon to the right of the balance (rises & fades, 2.2 s).
- Top-right: Upgrades button (honey, person+ icon, red badge when anything affordable), Pause. A hidden "Home" button (house icon) reserved for the future Dream House shop.
- Under the top row: tutorial bar (step "3/8" + text). Below: unlock card (cream card, honey border, icon tile, "NEW" kicker, title, hint) sliding in.
- Bottom-right: round Throw button (trash icon) when carrying. Bottom-centre hint text early in the tutorial.
- World tags: dark pill counters "12/30" over piles, honey "Lv 5 · ×2" above buildings, dark "Opens at Lv 22" over lots, blue robot task tags, white customer bubbles with product icons.
- Upgrades panel: bottom sheet, grouped rows: name, description, level pips, "5 items → 7 items", green price button / "MAX" / lock text.
- Main menu: bottom sheet over the orbiting character; kicker, big two-tone title, intro, language segmented control, skin cards, Play, New game (two-tap), controls hint.

## Models (start as primitives, replace later)
Characters (player 5 skins, lumberjack, carrier, robot, miner, section carrier, cashiers, manager, consultant, customers, contractors-style hard hats), items (log, plank, clay brick, iron ore, bill, chair, sofa, wardrobe, table, kitchen cabinet, sink, steel-beam bundle), buildings (factory shell + deco parts: floor module, chimney, fan, tank, flag), sawmill blade, press hammer, shelves, register stall with striped awning, truck, sedan car (8 colours), trees, clay/iron rocks, fences, lamps, arch, billboard (house illustration), bushes, pallets.

## VFX
Item arc flights, chop shake, tree fall / rock shrink, regrow pop, chimney smoke puffs, confetti burst on building upgrade, pad fill, money bills flying to pads, floating "+500 ֏" texts, level-up toast, building bounce.

## Audio (prototype uses simple synth blips — replace with real SFX)
coin (bill collected/paid), chop (axe thunk), quest step, purchase, level up, throw, truck engine pass, car door, shop door bell, ambient birds/town loop, light upbeat music. Haptics: light on pickup batches, medium on purchase/level-up.
