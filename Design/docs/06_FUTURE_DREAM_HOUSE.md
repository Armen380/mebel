# 06 — Future: Dream House mode (not built yet)

Owner's intent: after the business is big, invest all earned money into building and furnishing a personal **Dream House**.

## What exists now (placeholder)
- Fenced plot east of the factories (proto x 72–98, z −26…−4) reached by its own asphalt road from the main road (x 85), entrance arch "DREAM HOUSE", foundation outline with stakes and strings (centre 81,−17, 11×8 m), billboard with a house illustration and "Coming soon", and an empty paved **work area** (93.5,−15) that is reserved for the owner (no NPC workers there).
- Save field `owned.house` (false) and a hidden HUD **Home** button that must appear only after the house section is bought.

## Planned design (to be confirmed with the owner before building)
- Buy the house section (big price) → the Home button appears in the HUD (top bar, house logo). It opens a separate **Home Store** menu (not a world kiosk).
- Construction phases bought in the Home Store: foundation → walls → roof → windows/doors → garden; each phase is built visually on the plot (scaffold + pop-in).
- Furnishing: rooms (living room, kitchen, bedroom, bathroom). Items can be bought in the store; furniture types should reuse the game's own products (chairs, sofas, wardrobes, tables, kitchen, plumbing, building materials) with optional "premium" variants.
- Optional: placing furniture with a simple grid editor inside the house; house value / comfort score; rewards for completing rooms.

## Architecture hooks to keep now
- Keep `ProductDef` reusable for house items. Keep a `HouseService` stub and `owned.house` in the save. Keep the Home button and an empty `HomeStorePanel` prefab disabled.
