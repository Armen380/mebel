# PLAN

Read this file at the start of every session. Current work is at the top.
Full approved plan for M0+M1 (with details per step): see the sections below.

## In progress

### Release prep (user request 2026-11-06: "do the LevelPlay app, keystore, IPA and Profiler yourself; tell me what you cannot") (branch `release-prep`)
Status: **In progress**
- [x] iOS: Apple team F83UUGVD8Y (already signed in to Xcode) set in Unity (automatic signing); fresh Xcode export; xcodebuild archive + export with `-allowProvisioningUpdates` → Builds/iOS-Archive/ipa/FurnitureFactory.ipa (134 MB, App Store Connect signing). Fix: Xcode 27 needs iOS ≥ 15 for every pod (IronSource / Unity Ads declare 12–13) → `IosPostBuild` adds a Podfile post_install block (order 45, between Podfile generation and pod install).
- [x] LevelPlay (Hayk gave the user "Monetize - Add Apps" on 2026-11-06): apps "Furniture Factory" not live yet, COPPA not directed — Android app key 2952cc20d with Rewarded ad unit q8ybm9nl3ctr3hcq, iOS app key 2952d351d with Rewarded ad unit udyuaxjrga2ir42g (reward "Bonus" × 1; the game computes the money itself); written to Data/AdsConfig.asset. launchTestSuite on for development builds only — turn it off before the release.
- [ ] Android upload keystore (user decision 2026-11-06: "I don't have the key — create and save it"): Claude generates it outside the repo in `~/Keystores/FurnitureFactory/` (`upload.keystore`, alias `upload`, RSA 2048, 10000 days, random password in `upload.properties`, chmod 600; never committed — the repo is public). `FF/Build/Android Release AAB` reads that file when Player Settings has no keystore and sets the passwords only for the build.
  - [x] Generate the key and properties file (keytool from Unity's OpenJDK, PKCS12, same password for store and key; SHA-256 E0:E6:C8:D2:…:48:FC)
  - [x] BuildMenu reads the properties file and clears the keystore fields after the build (no home path or password in ProjectSettings)
  - [x] Build the release AAB, verify the signature → Builds/Android/FurnitureFactory-1.0.0.aab (50 MB, 2.6 min), jarsigner "jar verified", signer CN=Armen380 with the SHA-256 above. Note: the build takes > 30 s, so call it from `script eval` with a larger `--timeout` (or wait on `BuildPipeline.isBuildingPlayer`)
  - [ ] The user backs up the folder (password manager / cloud); with Play App Signing a lost upload key can be reset through Play support
- [x] Ads on the phone (Galaxy S25, 2026-11-07): dev APK with the real keys → "[FF] LevelPlay SDK initialized successfully", Test Suite opens by itself (app key 2952cc20d, SDK 9.7.0, GDPR consent True, COPPA False); network ironSource (bidding) only; Rewarded in Test mode: "Ad loaded successfully", the ironSource demo video plays. Live ads not shown on purpose (own clicks on live ads break the policy) — add the phone as a test device in LevelPlay before trying in-game buttons with live ads.
- [x] Profiler on the phone (Galaxy S25 — a flagship, not mid-range; graphics High; the user's Lv 278 save, 2026-11-07): 60.0 fps locked (avg 16.66 ms, p95 17.2, p99 17.4, max 26.9 over 2000 frames), CPU work ≈ 5 ms (WaitForLastPresentation 9.8 ms), scripts 0.6 ms Update + 0.6 ms LateUpdate, rendering 2 ms. GC every frame ≈ 480 B: WorkerDirector.Update ≈ 250 B (idle robots run RobotScoring.Best each frame: two new delegates, boxed foreach enumerators over IReadOnlyList, a WorkerJob per better candidate), RewardOffersView.Update ≈ 220 B (LevelPlay IsAdReady() over JNI each frame). Console: "Vulkan: Shader requires a compute buffer unity_ParticleInstanceData … skipping draw calls" — mesh particles with GPU instancing are not drawn on Vulkan.
  - [x] WorkerJobs: index loops instead of foreach over IReadOnlyList; RobotScoring keeps the best candidate in a struct and allocates one WorkerJob at the end
  - [x] WorkerDirector: cached delegates for WaitingCustomers / RobotsHeadingTo
  - [x] RewardedAdManager: IsReady cached, IsAdReady() polled every 0.5 s (real time)
  - [x] EffectsBuilder: GPU instancing off on mesh particle renderers (Vulkan)
  - [x] Tests green (618/618), dev APK rebuilt, profiled again on the same save: 60.0 fps, p95 17.0 ms, p99 17.1, max 18.3 (was 26.9); GC on 13 of 154 sampled frames (was every frame), ≈ 128 B/frame on average — what is left is first-time Instantiate of world tags / customers while their pools fill after launch, plus the 0.5 s ad-ready poll (8 B); no Vulkan particle warning any more. Scene patched in place (Smoke / Confetti renderers); URP also added the default UniversalAdditionalLightData to Sun on save.
  - Follow-up (not blocking): profile on a real mid-range phone (Snapdragon 7-series) if one is available; prewarm world tags / customers if Instantiate shows up after the first minute. the phone was unplugged; on a mid-range phone if one is available.
- [x] Release builds with the ads rework (2026-11-09, user: "давай начнём"): the Test Suite is already dev-only (`launchTestSuite && Debug.isDebugBuild`), no change needed. Release AAB 1.0.0 (1) rebuilt from main → Builds/Android/FurnitureFactory-1.0.0.aab (51.7 MB), jar verified, signer CN=Armen380, SHA-256 E0:E6:…:48:FC.
  - Fix: the build writes ProjectSettings to disk while the store values are set, so the keystore path (home folder) and IL2CPP Master stayed in ProjectSettings.asset after the release AAB (passwords never hit the disk). `BuildMenu.RestoreAfterStoreBuild` now puts IL2CPP back to Release and calls `AssetDatabase.SaveAssets()` after the AAB and the iOS export.
  - [x] iOS: platform switched to iOS, Xcode project exported (team F83UUGVD8Y); xcodebuild archive + export → Builds/iOS-Archive/ipa/FurnitureFactory.ipa (125 MB, 1.0.0 (1), App Store Connect signing). Platform switched back to Android afterwards.
  - Fix: the ATT prompt (`IosPostBuild.TrackingDescription`) still said "Ads only appear when you choose to watch one for a reward" — untrue since the interstitials; now "…The game shows ads between levels and short videos you choose to watch for a reward." IPA rebuilt and checked.
  - The iOS export also stores static batching on + IL2CPP Release for iPhone in ProjectSettings (set by `BuildMenu.Performance`, committed now).
  - Tests 625/625.
- [ ] Upload the AAB to Google Play Console and the IPA to App Store Connect (the user; needs the app records there).


### Ads fill + optimization pass (user request 2026-11-07: "ads don't show, and optimize the game") (branch `release-prep`)
Status: **Done** (optimization 2026-11-07, Unity Ads 2026-11-08) — user decision 2026-11-07: B (add Unity Ads) + all optimization items 1–7 (not A).
Why no ads: the game asks correctly — logcat on the phone: "[FF] Rewarded ad failed to load: Mediation No fill; retry in 30 s". The only network is ironSource, the apps are new and "not live" in any store, so live demand returns no fill; the HUD buttons appear only when an ad is loaded (by design). Test ads load fine through the Test Suite.
Ads options:
- [ ] A. Register the phone as a LevelPlay test device (dashboard › Testing; needs the phone's advertising ID) → the in-game buttons get test ads now
- [x] B. Unity Ads (2026-11-08, after Hayk created the Unity Cloud project "Furniture Factory" in org 7 Grexov): Unity Ads apps Android Game ID 800428941 + iOS Game ID 800428942 (not child-directed), bidding placements BP_Rewarded_Android / BP_Rewarded_iOS (Rewarded only); LevelPlay › Instances › UnityAds filled for 2952cc20d and 2952d351d (instance "Rewarded"), saved — the Android app now lists ironSource + UnityAds bidders. No code change: the adapter was already in the build. Phone 2026-11-08: Test Suite › Ad networks lists ironSource + UnityAds (SDK 4.21.0, adapter 5.16.0); UnityAds Rewarded in Test mode loads and shows; the game itself then logs "[FF] Rewarded ad loaded (unityads)" — the HUD ad buttons have fill now.
- (history) B. Add Unity Ads as a second network — found 2026-11-07: the adapter is already in the project and the build (ISUnityAdsAdapterDependencies.xml, unityads-adapter 5.16.0 in the APK), and Unity Ads is set up at the LevelPlay account level; what is missing is the UnityAds instance of our two apps (LevelPlay › Instances › UnityAds needs a Unity Ads Game ID + placement ID). Those come from Unity Cloud org "7 Grexov" (18967030193245, the org with Boltiki) › Monetization › Apps › Add app — **blocked**: creating the project there fails ("could not process your request"); the user is an org "User" (App Editor, Monetization Editor…), and only the owner (Hayk) / a manager can create projects. Next: Hayk creates a project "Furniture Factory" in the org (or gives the user the Manager role); then add the Android + iOS apps to it, make Rewarded placements, and fill the LevelPlay UnityAds instances (Game ID, placement ID, Rewarded on).
- (original text) B. Add Unity Ads as a second network (adapter via the Ads Mediation package + an instance in the LevelPlay dashboard) → more fill after launch (third-party SDK — needs the user's OK)
- Real fill also grows once the app is live on Google Play / App Store.
Optimization (data: Galaxy S25 already 60 fps / CPU ≈ 5 ms; the aim is mid-range and low-end phones, battery and size):
- [x] 1. Static batching on for Android (the world blockout is marked Static, but static batching is off in Player Settings)
- [x] 2. Optimized frame pacing on (Android) — steadier 60 fps, less jank
- [x] 3. Menu at 30 fps (nothing moves but the orbit camera) — battery
- [x] 4. Prewarm world tags and customers so no Instantiate happens in play (the last GC on the phone)
- [x] 5. Render stats at the end-game save in the Editor (batches / SetPass / triangles), cut what stands out (shadow casters on small props, far objects)
- [x] 6. Build size: managed stripping Minimal → Low (with link.xml for reflection users), ASTC textures, check the 86 MB APK breakdown (Build Report)
- [x] 7. Tests, dev APK, Profiler again on the phone (and on Low tier to emulate a weak phone) — tests 619/619, dev APK built (83.9 MB) from the clean scene (a scene save had re-serialized 168 TMP texts; reverted, only the prewarm values kept). Phone (2026-11-07): new APK installs and starts with no exceptions (stripping Low), LevelPlay init + Test Suite OK, menu in Russian OK; menu Profiler 30.0 fps (p95 34.4 ms). The first gameplay capture was invalid (the phone locked itself). Redone: save loads (Lv 282, $415K); play 60.0 fps over 1234 frames, p95 17.8 ms, p99 19.0, max 21.6; no Instantiate during play any more; GC on 27 of 124 sampled frames — the 3 s autosave (SaveService JSON, by design), Input System binding resolve once after the menu, TMP text changes. Low-tier check on a weak phone not done (no such phone); the S25 can't emulate it.
Status of this task: optimization done; Unity Ads blocked on the Unity Cloud project (Hayk).
Notes (done 2026-11-07):
- 1–3: `BuildMenu.Performance()` sets static batching (Android + iOS), Android optimized frame pacing; `AppSettings.FrameRate(inMenu)` — `MenuPause` sets 30 in the menu / 60 in play (SettingsApplier no longer touches the frame rate). Test FrameRate_MenuHalf_PlaySixty.
- 4: WorldTagLayer makes `prewarmPills` = 96 tags at start (end-game save has 74 sources); CustomerDirector prewarm 2 → 4 per variant (12 variants → 48; 20 walk-ins + car customers).
- 5: Editor, end-game save, High: 739 draw calls, 87 SetPass, 10.3K triangles, 372 shadow casters; shadow-casting renderers by root — Workers 582, Customers 496, Blockout 627. Characters are ~16 cubes each, so small parts inside the silhouette (Eye, Belt, Shoe, Hand, HatPompom, HatPeak, CrownTip, axe Handle / Blade) cast no shadow now (`CharacterRigBuilder.TrimShadows`, applied to the 22 worker / customer prefabs; Player.prefab left alone — it has an older uncommitted rebuild).
- 6: APK breakdown: libil2cpp.so 78 MB + global-metadata 14.8 MB of 180 MB uncompressed; managed stripping Minimal → Low with `Assets/_Game/link.xml` (FF.*, Newtonsoft, Localization, LevelPlay kept whole); IL2CPP Release for dev builds, Master for the store AAB / iOS export.

## Done

### Android version code 2 (user request 2026-11-09: "Да, слить и собрать") (branch `version-code-2`)
Result: release AAB 1.0.0 (code 2) with the in-app privacy policy link → Builds/Android/FurnitureFactory-1.0.0-2.aab; PR #20 merged. The user uploads it to Play Console (internal testing).
Status: **Done**
The AAB already in Play Console (1.0.0, code 1) has no in-app privacy policy link; Google only takes a higher version code.
- [x] Merge PR #19 (privacy link) into main
- [x] `AppIdentity.AndroidVersionCode = 2` (Setup used a hard-coded 1); AAB file name gets the code (FurnitureFactory-1.0.0-2.aab)
- [x] Release AAB from main + this change; verify jar signature, package com.incode.furniturefactory, versionCode 2 → Builds/Android/FurnitureFactory-1.0.0-2.aab (52.2 MB), jar verified, signer CN=Armen380 SHA-256 E0:E6:…:48:FC, manifest versionCode 2 / versionName 1.0.0. Keystore noise (`AndroidKeystoreName: '{inproject}: '`) reverted.
- [x] Commit, PR #20 → main

### Privacy policy link in the game (user request 2026-11-09: "Да, добавить") (branch `privacy-link`)
Result: main menu shows "Privacy policy" next to "Ad privacy" (opens https://armen380.github.io/mebel/privacy/ from AdsConfig, en / ru / hy); PR #19 merged.
Status: **Done**
Google wants the policy linked inside the app too. Plan: the menu's "Ad privacy" link gets a row partner "Privacy policy" that opens https://armen380.github.io/mebel/privacy/ in the browser.
- [x] `AdsConfig.privacyPolicyUrl` (data, not in the MonoBehaviour); `PrivacyPolicyLink` (FF.UI.Menu) opens it with Application.OpenURL
- [x] Localization key `ui.privacy_policy` in en / ru / hy, re-import (only the 4 string-table assets changed)
- [x] MenuBuilder: links row (Ad privacy left, Privacy policy right, wrap on narrow screens); scene patched in place. Note: patching the already-open scene re-serialized ~170 TMP texts (1.9K-line diff) — reverted, reopened Game.unity fresh (OpenSceneMode.Single) and patched again → only the new objects in the diff.
- [x] Tests 626/626; Play Mode: menu shows both links (Russian wraps to two lines each), PrivacyPolicyLink active with the URL, no console errors. Opening the URL itself not clicked in the Editor (would open the user's browser) — check on the phone.
- [x] Commit, PR → main after the user's OK ("Да, слить и собрать")

### Privacy policy page (user request 2026-11-09) — GitHub Pages
Result: `docs/privacy/index.html` (en / ru / hy), published with GitHub Pages from `main` /docs → https://armen380.github.io/mebel/privacy/ — for the Google Play listing (and App Store). Developer "Incode", contact armenzakaryan888@gmail.com (user's choice). Content: no data collected by us (progress stays on the device); Unity LevelPlay (ironSource) + Unity Ads collect ad ID / IP / device info; consent dialog + main-menu "Ad privacy" link, ATT on iOS; not for children under 13.
- [x] Write the page, Pages from main /docs, check the URL
- [x] Google also wants the policy linked inside the app → done in "Privacy policy link in the game"

### Android package com.incode.furniturefactory — 2026-11-09 (branch `android-package`)
Result: Android package is com.incode.furniturefactory (the Play Console app record), iOS keeps com.armen380.furniturefactory; release AAB rebuilt and accepted by Google Play (internal testing); merged into main.
Status: **Done**
Play Console rejected the AAB: the app record there is "com.incode.furniturefactory" (ours was com.armen380.furniturefactory). Only the Android package changes; iOS / Standalone keep com.armen380.furniturefactory (the IPA is already built with it) unless App Store Connect needs otherwise.
- [x] `AppIdentity`: separate `AndroidPackage` = com.incode.furniturefactory, run FF/Setup App Identity (icon PNGs it re-saved were reverted — unchanged art)
- [x] Rebuild the release AAB → Builds/Android/FurnitureFactory-1.0.0.aab (52.2 MB): manifest package com.incode.furniturefactory, jar verified, signer CN=Armen380 SHA-256 E0:E6:…:48:FC
- [x] Commit, PR → main after the user's OK ("Принял, слить")

### New app icon from the user's art — 2026-11-09 (branch `app-icon`)
Result: the user's artwork is the app icon on Android (adaptive, whole picture visible) and iOS (no alpha); release AAB + IPA rebuilt; store listing copies in Builds/StoreIcons; user checked on the phone; merged into main.
Status: **Done**
The user sent a 1408×768 picture with the icon (worker with a hammer, "FURNITURE FACTORY" sign) in a white rounded frame on orange. Kept as `Design/reference/app_icon/app_icon_source.jpg`.
- [x] Crop the artwork inside the frame (art x 412–998, y 91–679 bottom-up; inset 36 px so the art's own rounded corners don't show → square x 448, y 128, 514 px) and scale to 1024 (bilinear) → `Assets/_Game/Art/AppIcon/AppIcon.png`. The source is only ~514 px, so the 1024 icon is a bit soft — a larger original would be sharper.
- [x] `AppIdentity`: uses that picture instead of the generated chair — iOS / default icon = the art; Android adaptive: background = the art in the 72/108 visible part, around it a blurred copy of the art (stretched edge pixels made streaks), foreground transparent, so launchers show the whole art and the mask only rounds the corners. Opaque icons are saved as RGB (App Store rejects an alpha channel); the APK has the new launcher layers, the Xcode Icon-Store-1024 has no alpha.
- [x] Store listing copies: `Builds/StoreIcons/google_play_icon_512.png`, `app_store_icon_1024.png` (no alpha)
- [x] Check on the phone (home screen icon) — dev APK installed on the Galaxy S25 (2026-11-09); the user checked the icon: OK
- [x] Rebuild the release AAB (52.2 MB, jar verified, upload key) + IPA (128.7 MB, archive + export OK); platform back to Android
- [x] Commit, PR → main after the user's OK ("Иконка ок, слить")

### Ads rework: interstitial every 3 levels + centered offer popup — 2026-11-09 (branch `ads-interstitial`)
Result: forced interstitial every 3rd level (not in menu/tutorial, 60 s after start, 2 min after any ad, audio paused) + one centered offer popup with ✕ (×2 payout or bonus, once per 5 min) replacing the corner buttons; 625 tests green; checked on the phone; user play-test OK; PR #14 merged into main.
User decisions 2026-11-08: a forced interstitial (full-screen, no reward) every 3 levels; the bottom-left green buttons go away and are replaced by a popup in the middle of the screen with an offer and a close cross; the popup comes at most once per 5 minutes (plus right after a truck pays, ×2).
This reverses the M9 rule "no ads ever interrupt play (rewarded only)" — the user's call.
Plan:
- [x] 0. Branch `ads-interstitial` from main
- [x] A. Dashboards (2026-11-08): LevelPlay Interstitial ad units — Android `t4pf8f0eljdrjpz8`, iOS `xciid1prmx7bgb8b`; Unity Ads placements BP_Interstitial_Android (Game ID 800428941) / BP_Interstitial_iOS (800428942); LevelPlay UnityAds instances now Rewarded + Interstitial for both apps (saved). Was: LevelPlay — Interstitial ad unit for Furniture Factory Android + iOS; Unity Ads — BP_Interstitial_Android / BP_Interstitial_iOS placements; LevelPlay › Instances › UnityAds — Interstitial instance for both apps. Ids into `AdsConfig` (`androidInterstitialAdUnitId`, `iosInterstitialAdUnitId`)
- [x] B. `InterstitialAdManager` (FF.Ads, same pattern as RewardedAdManager: preloaded, 30 s retry, cached readiness, ILRD log) + `IInterstitialAds` in Core
- [x] C. `InterstitialRules` (Core, pure, tested): show on level-up when level % 3 == 0, not in the menu, not during the tutorial, at least `interstitialMinGap` = 120 s after any ad (interstitial or rewarded) and 60 s after the session starts; shown ~1.5 s after the level-up so the player sees the level-up first; skipped silently when no ad is loaded. Numbers in AdsConfig
- [x] D. `AdOfferPopup` (UI/HUD, replaces RewardOffersView buttons): centered card with icon, title, amount, "▶ Watch" button and a ✕ close button; two offers — "×2 payout +$X" for 8 s after a truck pays (only when the cash offer is not up) and "Bonus +$X" (instant cash: 2 min of income, ≥ $500) every 5 min; ✕ / ignoring it starts the cooldown; game keeps running behind it (no pause); hidden while an interstitial or rewarded ad is open, in the menu and when no ad is ready. Texts in hy / en / ru (ad.offer.title, ad.offer.double, ad.offer.cash, ad.offer.watch)
- [x] E. Remove the bottom-left buttons (RewardOffersView) from the HUD builder and scene
Notes (2026-11-08):
- D changed while building it: trucks pay often late in the game, so ×2 after every truck would pop the card all the time. One shared cooldown (5 min, `instantCashCooldown`) for every popup; when it is over the card offers ×2 if a truck paid in the last 8 s, else bonus cash; it stays 12 s (`cashOfferWindow`, honey bar runs out) or until ✕ / Watch, then the cooldown restarts. First offer 2.5 min after start.
- `AdClock` (Core) records any ad on screen / the last ad end (rewarded too) for the 2-minute gap; the interstitial pauses audio while it shows.
- The consent text `ads.text` now says ads show between levels (hy / en / ru).
- Scene patched in place (fresh OpenScene → replace RewardOffers with AdOffer, AdsSetup.Build → Ads has Initializer + Rewarded + Interstitial + Scheduler) → no TMP churn.
- Editor check with LevelPlay mock ads: both units load; forced popup shows "Бонус +$500 / Смотреть рекламу", Watch → mock rewarded → reward paid, card hidden; level-up 1110 → interstitial shown (audio paused), closed → audio back, next ad loaded; level-up 1113 right after → not shown (gap). Note: the Editor save still has the tutorial at 5/8 — interstitials never show before the tutorial is done.
- [x] F. EditMode tests (625/625, AdScheduleTests) ✓ + Play Mode check with LevelPlay mock ads in the Editor ✓ + phone check ✓ (2026-11-08, Galaxy S25: Test Suite UnityAds Interstitial test ad loaded + shown; the game logs "Interstitial ad loaded (unityads)"; the centered offer popup appeared in play and Watch started a live rewarded ad. The forced interstitial itself needs a natural level-up during play — left to the user's play-test)
- [x] G. Commit, push, user play-test OK 2026-11-09, PR #14 merged into main

### M9 — Polish & release prep — 2026-11-05 (branch `m9-polish`)
Result: menu (pause) with language switch, skins and orbit camera; settings (sound, music, vibration, graphics tiers Low / Medium / High); CC0 sounds + music; haptics; pool sizes from an end-game soak; app identity + icon; rewarded ads (LevelPlay, ×2 payout + instant cash, consent + ATT); dev APK / release AAB / iOS Xcode export; 618 tests green; user play-test OK 2026-11-06 (camera fix); merged into main.
Goal (04_IMPLEMENTATION_PLAN): menu (language switch, skins with orbit camera), settings (sound, haptics, quality), SFX / music,
haptics on pickups / purchases, app icon, splash; performance pass on a low-end Android; build AAB / IPA. Optional with
approval: rewarded ads, IAP, analytics, cloud save.
Prototype refs: menu HTML (175–198) + css, `SKINS` (459–465), `setSkin` (1141–1146), `sfx` (1436–1442), `renderSkins / openMenu /
startPlay / btnTest / btnReset` (1546–1570), menu orbit camera in `updCamera` (1607–1612), skin unlock card (checkUnlocks 1680);
docs 01 §9, 03 (performance rules), 05 (menu, audio, haptics); screenshot 01_menu_skins_language.png.
Already in place: SkinDef ×5 (gold unlocks at 100K total earned), `skin` in the save, `CharacterRigBuilder` takes a SkinDef,
menu texts (ui.h1, ui.kicker, ui.intro, ui.skin, ui.play, ui.continue, ui.test, ui.new, ui.reset, ui.controls, skin.*, ui.earn,
un.skin.*), dev HUD buttons (HY language, Test, New game) that the menu replaces.

- [x] 0. Branch `m9-polish` from main
- [x] A. Main menu = pause screen (prototype `#menu`): bottom sheet over the game — kicker with the app version, two-tone title, intro, language segmented control Հայ / EN / RU, "Choose a character" skin cards (colour swatch, name, gold locked with "Earn $100K"), Play (first launch) / Continue, row "Test: +25 Lv, +$250K" (development builds only) + New game (two-tap confirm), controls hint. The game opens in the menu; a Menu button in the HUD opens it; the HUD, joystick and input are off while it is open; the dev HUD buttons go away
- [x] B. Menu camera: Cinemachine orbit around the player (0.22 rad/s, radius 6.2 portrait / 5.4 landscape, height 1.7, look at y −0.55 / −0.05), blends to the follow camera on Play; the player faces the camera angle and stands still
- [x] C. Skins: picking a card swaps the player's look at once (prebuilt prefab per skin, carried items move over), saved in `skin`; card "New character: Golden" when total earned reaches $100K (prototype `skin_gold`)
- [x] D. Settings in the menu: sound on/off, music on/off, vibration on/off, graphics Low / Medium / High (Low: no shadows, no MSAA, render scale 0.8; Medium: shadows 35 m 1 cascade, MSAA 2×; High: soft shadows, render scale 1.0); default by device (low RAM / old GPU → Low); stored per device (PlayerPrefs). New texts in the three tables
- [x] E. Audio: `AudioService` (pooled 2D sources, Music / SFX mixer groups, per-sound cooldown like the prototype's coin 50 ms): coin, chop, quest step, purchase, level up, throw, truck pass, car door, shop door bell, ambient town loop, light music loop; triggered through GameEvents (no audio code in gameplay)
- [x] F. Haptics: light on pickup batches, medium on purchase / level up; Android vibrator with amplitude (AndroidJavaObject), iOS impact feedback via a tiny native plugin (.mm), nothing in the Editor; off in settings
- [x] G. Performance: item pool prewarm sized for the full game (M7 follow-up), no GC allocations per frame in steady play (Profiler), world tags culled off-screen, static batching / instancing check, quality tiers above; profile a development build on the user's Android phone (Profiler over USB) at the end-game save (all factories, 60+ agents)
- [x] H. App identity: product name, bundle id, version 1.0.0 (build 1), app icon (low-poly in the game's style, all Android / iOS sizes), launch screen in the game's colours without the Unity logo
- [x] I. Builds: Android AAB (IL2CPP, ARM64 + ARMv7, latest target API) signed with the user's keystore (the user creates it and types the passwords); iOS: Xcode project export (the user signs and archives the IPA in Xcode)
- [x] L. Rewarded ads (user decision 2026-11-05): LevelPlay (Unity's ad mediation, includes Unity Ads) via its UPM package; two placements from the docs — "×2" on a delivery payout (button on the payout chip for a few seconds after a truck pays) and "instant cash" (HUD button when ads are ready, amount and cooldown to be agreed); test-mode ads in the Editor / development builds; consent (GDPR / UMP) and iOS ATT prompt; the user creates the LevelPlay account and gives the app keys. No ads ever interrupt play (rewarded only)
- [x] J. EditMode tests (menu state, skin unlock, settings → quality tier mapping, audio cooldowns, pool sizes) + Play Mode check (menu ↔ play, skins, settings, sounds) + device check
- [x] K. Commit `M9: polish and release prep`, push, user play-test, PR → main

Notes (implementation):
- A–C: `GameMode` (Core) — the game opens in the menu; `MenuPause` sets time scale 0 in the menu (the prototype runs no simulation there), the player's animator and the Cinemachine brain use real time; `MainMenu` (UI/Menu) on its own "Menu" canvas hides the HUD through a CanvasGroup; `MenuCameraOrbit` places a second Cinemachine camera (priority 20 in the menu), the brain blends 1.1 s. Player / interactor / unlock cards / tutorial arrow do nothing in the menu. The dev HUD buttons (HY, Test, New game) are gone — Test (development builds only) and New game live in the menu.
- Kicker shows "v" + app version (the prototype's "Prototype · v0.3" text is not used).
- Skins: the player prefab has every hat type ("Hat_{type}") and `PlayerLook` swaps palette materials of torso / arms / legs; `PlayerSkin` (ISkinSelection) keeps it in `GameProgress.Skin` → save `skin`; Golden unlock card "skin_gold" when total earned ≥ $100K (checked on money changes).
- D: `GameSettings` (Core, PlayerPrefs keys ff.sound / ff.music / ff.vibration / ff.quality; tests use a dictionary store); first launch: Editor → High, devices by `QualityRules.DefaultTier` (RAM < 3.5 GB or < 6 cores → Low, RAM < 6.5 GB → Medium, else High). `FF/Setup Render Settings` now makes quality levels Low / Medium / High (Mobile_Low_RPAsset: no shadows, no MSAA, scale 0.75; Mobile_RPAsset: hard shadows 35 m, MSAA 2×, scale 0.9 — was 0.8; Mobile_High_RPAsset: soft shadows 2048, MSAA 4×, scale 1.0) on every platform; `SettingsApplier` switches the level. Menu row: sound / music / vibration toggles + graphics segmented control. New texts ui.sound / ui.music / ui.vibration / ui.graphics / ui.gLow / ui.gMed / ui.gHigh (Armenian written by Claude — the user should check them).
- E: sounds copied from the downloads (user OK 2026-11-05) into Audio/Sfx and Audio/Music, sources in Audio/CREDITS.md (Kenney RPG / Interface / Casino / Impact / Music Jingles; OpenGameArt "Happy Clappy Loop" by OwlishMedia, "Ambient bird sounds" by isaiah658 — all CC0). `AudioLibrary` (Data, FF/Build Audio Library: volumes, pitch jitter, cooldowns; effects mono decompress-on-load, loops streamed Vorbis) + `AudioService` (8 pooled 2D voices; events: MoneyChanged(bump) coin, ChopHit(rock) chop / mine, QuestChanged, PadCompleted / UpgradeBought purchase, LevelUp, Thrown, TruckDelivered payout, GameEvents.Sound: Click / CarDoor / DoorBell / TruckPass). Truck engine pass is synthesized in code. No AudioMixer (per-source volumes; settings mute). Effects except clicks are silent in the menu. The chosen files were picked by name / length, not by ear — easy to swap in the table of AudioLibraryBuilder.
- F: `Haptics` (light on pickups / cash / felled node, ≤ every 0.25 s; medium on purchases and level-ups). Android VibrationEffect.createOneShot (Handheld.Vibrate fallback also adds the VIBRATE permission); iOS UIImpactFeedbackGenerator via Plugins/iOS/FFHaptics.mm. Not testable in the Editor — device check in J.
- G (Editor part): end-game soak on the user's save (Lv 983, 36 workers, 31 customers, ×4, 16 game minutes): peaks logs 66, planks 156, clay 26, iron 21, bills 17, chairs 43, sinks 16, the rest ≤ 9 → prewarm Log 80, Plank 180, Clay / Iron 32, Bill 40, Chair 52, other products 30 (builder keeps larger Inspector values); `ItemPool.Created(type)` reports pool growth. Editor GC numbers (8 KB / 148 allocs per frame in play, 13 KB / 178 in the paused menu) are the Editor's own overhead — the real per-frame check needs the Profiler on a development build on the phone (still open, with the device check). World tags were already culled off-screen; static batching on the blockout since M1.
- H: `FF/Setup App Identity` (AppIdentity.cs): "Furniture Factory", com.armen380.furniturefactory (Android / iOS / Standalone), company Armen380, version 1.0.0 (Android code 1, iOS build 1); generated 1024 px icons in Art/AppIcon (honey + walnut-outlined wooden chair; Android adaptive background / foreground); Unity splash off, launch colour = sky #bfe3f0. ProjectSettings.asset committed from now on (it also carries the preloaded LocalizationSettings and input actions the build needs).
- L (2026-11-06, user answers: GDPR + CCPA, ILRD stub yes, a new initializer script, one manager per format; rewarded only; bid floors skipped — can be added later): Ads Mediation 9.6.0 (Android: mediation-sdk 9.7.0 + Unity Ads adapter + play-services-ads-identifier, which brings the AD_ID permission, resolved into the gradle templates by the Mobile Dependency Resolver; iOS through CocoaPods at export). New assembly `FF.Ads`: `LevelPlayInitializer` (waits for the consent answer, then iOS ATT via Plugins/iOS/ATTRequester.mm, then SetGDPRConsent / SetCCPA, then Init; optional Test Suite in development builds) and `RewardedAdManager` (IRewardedAds; created on init, preloaded on purpose, retries a failed load in 30 s, reward granted from OnAdRewarded on the next frame, ILRD logged per ad). `AdsConfig` asset (Data/AdsConfig.asset): Android / iOS app keys and rewarded unit ids — empty until the user creates the LevelPlay app (the Editor uses mock ads with placeholders), dashboard placements off, instant-cash cooldown 300 s, ×2 window 8 s. `IosPostBuild` writes NSUserTrackingUsageDescription. UI: `RewardOffersView` (bottom-left green pills, only while an ad is ready: "▶ ×2 +$X" for 8 s after a truck pays, "▶ +$X" instant cash = two minutes of income via `IncomeMeter`, ≥ $500, every 5 min) and `AdsConsentDialog` (first launch over the menu + "Ad privacy" link). Checked in the Editor: consent dialog → LevelPlay init → mock ad loaded → ×2 offer shown → mock ad → +$4,800 granted.
- Renaming the app moved the desktop save folder (Application Support/DefaultCompany/Mebel → Armen380/Furniture Factory) and PlayerPrefs: the user's save was copied to the new folder, and `SaveService` copies a legacy desktop save once when the new one is missing. Phones: the new bundle id is a new app anyway.
- I: `FF/Build` menu (BuildMenu.cs) into git-ignored Builds/: Android Development APK (debug key, Profiler connection; built 2026-11-06: 63 MB, 3.4 min, gradle with the ad dependencies OK), Android Release AAB (stops with a dialog until the user's keystore is set in Publishing Settings), iOS Xcode Project (exported: IL2CPP, Podfile IronSourceSDK 9.7 + Unity Ads adapter, pods installed, 82 SKAdNetwork ids, ATT description). Gotcha: an iOS export that switches the platform inside BuildPlayer runs iOS-only post-build steps compiled for Android (no SKAdNetwork ids, no ATT text) — the menu now switches first and asks to run again; IosPostBuild edits the plist as text without `#if UNITY_IOS`.
- J (partial): 618/618 EditMode (14 new in PolishTests). Device: dev APK on the user's Galaxy S25 (SM-S931B, Android 17) runs (menu, skins, settings OK; only Unity's harmless AssetPackManager ClassNotFound log; ads off without keys); the user profiles it.
- Play-test fix (user, 2026-11-06, phone): "the camera is as if on the floor, nothing visible" — after Play the menu camera stayed live (both Cinemachine cameras had priority 0, so the last enabled one won). The menu camera is now enabled only in the menu (placed on its orbit spot first), the play camera has priority 10. Checked in the Editor: menu → play → menu → play switches the live camera each time.
- Gotchas: `GetComponent() ?? AddComponent()` does not work on Unity objects (fake null) — use TryGetComponent; synchronous `GetLocalizedString` inside `SelectedLocaleChanged` re-enters Addressables — refresh texts on the next frame.

Decisions (user, 2026-11-05):
1. Sounds: Kenney CC0 packs (+ a CC0 music loop); the exact files are listed to the user before downloading.
2. Monetization in M9: rewarded ads (step L); no IAP.
3. App: "Furniture Factory", bundle id com.armen380.furniturefactory, company Armen380.
4. Builds: Android AAB signed with the user's keystore + iOS Xcode project (the user archives the IPA).

Follow-ups (open, need the user):
- LevelPlay: create the app in the dashboard, put the Android / iOS app keys and rewarded ad unit ids into Data/AdsConfig.asset; optionally the dashboard placements (double_payout, instant_cash → useDashboardPlacements) and bid floors; run the Test Suite once (launchTestSuite in a development build), then turn it off.
- Google Play: the user creates the upload keystore (Player Settings › Publishing Settings) → FF › Build › Android Release AAB.
- iOS: open Builds/iOS/Unity-iPhone.xcworkspace, set the team, archive the IPA.
- Profiler on a mid-range Android (the S25 is a flagship); GC per frame on device.
- Idea: on phones show only the touch part of the controls hint.

### M8 — Plumbing & Building materials — 2026-11-05 (branch `m8-plumbing`)
Result: Plumbing buy pad (Lv 150) also opens Building materials, the mines yard (16 clay + 20 iron rocks) and the materials shop (registers 6 / 7); Miner, Section carrier, Section cashier; unlock cards; 604 tests green, 16-min soak clean; play-test fix (section group in Upgrades); user play-test OK 2026-11-05; merged into main.
Goal (04_IMPLEMENTATION_PLAN): mines yard (gate opens), clay / iron rocks, Plumbing + Materials factories, materials shop
with its own door / shelves / registers, Miner, Section carrier, Section cashier, routing through the factory gap; Dream
House placeholder. Done when the Lv 150 content works end-to-end.
Prototype refs: PRODUCTS sink / material (232–235), UPG miner / secCarrier / secCashier (245–247), `ownFactory` + `with` (1015–1019),
`refreshBlocks` materials-shop walls (1032), materials-shop block (968–981), `reg_annex` pad (984), rocks `makeRock` (1003–1004, 1049–1056),
gate / back area (888–900, 1639), `updMiner` + GAP (1217–1235), `assignStaff` / `updCashier` (1204–1216), `pickJob(sec)` / `updCarrier` rest
(1307–1318), `checkUnlocks` mines / matshop / with / staff (1668–1679), WORKER_SKIN (1186–1197); spec §6–§8.

Already in place from M1–M7 (only wire up / verify): mines-yard fence, gate and signs, materials-shop shell, Plumbing and
Materials machines + their speed / qty pads, shelves at x 48 / 50.6, registers 6 / 7 with their activity rule, customers
routed to the annex door by product, `PlayerRegionRules.minesOpen`, ResourceNode clay / iron hardness and regrow, item
prefabs clay / iron / sink / material, Dream House plot (fence, arch, road, lamps, foundation, billboard, work area, "Soon").

- [x] 0. Branch `m8-plumbing` from main
- [x] A. Buying Plumbing: pad `sink_buy` ($1.5M × ECON, shows from Lv 150) at (40, −9.6) with the "Lv 150" lot chip; `Ownership.Own("sink")` also owns every product with `unlocksWith = sink` (Materials), sets `OwnsPlumbing`, toast "t.sinkOpened"; old saves keep working (plumbing is derived from owned "sink")
- [x] B. World switches at runtime (no rebuild): gate hides, mines yard / materials shop show, materials-shop walls join the blockers (4 AABBs), register 6 activates, pad `reg_annex` ($400K × ECON, max 1) at (58.2, 3.5) opens register 7, shelves 48 / 50.6 show; the player can enter the mines yard
- [x] C. Rocks: clay 4×4 from (36.5, −15.8), iron 5×4 from (47, −15.8), step 2.4, seeded jitter ±0.25; low-poly prefab like `makeRock` (ground slab + icosahedron top, iron with orange ore bits); hardness 1.5 / 1.8, regrow 12 s, shrink on depletion and elastic grow back; mined like trees (axe level, 2 items per rock), only with plumbing; registered in NodeRegistry
- [ ] D. Factories: Plumbing (2 clay → sink, 5 s) and Materials (2 iron → material, 5.5 s) run end-to-end — player carries clay / iron in, products to the materials-shop shelves, annex customers buy and pay at registers 6 / 7, trucks take sinks / materials
- [x] E. Workers (upgrades group "Plumbing & Materials", locked until plumbing):
  - Miner (max 4): spawns at (44, −5); goes through the factory gap (44, −6.2) ↔ (44, −14.6); picks clay or iron by the emptier factory input; mines, carries 5, unloads into the input; idles at (44, −5) without plumbing
  - Section carrier (max 3): only Plumbing / Materials outputs → their shelves (or a free truck dock), rests at (43.4 + i·1.2, −3.4)
  - Section cashier (max 2): spawns at (51.5, 8), takes registers 6 / 7 before the cashiers do, idles at (47.6 + i·1.2, 8.4)
  - Carriers / robots holding clay or iron deliver it to the matching factory input (prototype `updCarrier`); prefabs per WORKER_SKIN (miner brown shirt + hard hat, section carrier blue + hard hat, section cashier grey + cap)
- [x] F. Unlock cards: Plumbing factory at Lv 150 (price), "Building materials" with-card, "Clay pit and iron mine" → (47, −17), "Building materials shop" → (51.5, 6), staff cards for the three section workers
- [x] G. EditMode tests: ownership with `unlocksWith`, plumbing-derived state + blockers, register 6 / 7 activity, rock grid positions / hardness / regrow, miner resource choice and gap way-points, section carrier job filter, section cashier register order (6, 7 first), unlock cards, save round-trip
- [x] H. Play Mode on a copy of the user's save (Lv 150 + money given in the session only): buy plumbing, mine by hand, hire the section workers, check the full chain and the Console; 15-minute soak at ×4 with all workers; restore the save → done 2026-11-05 on the user's save (already Lv 258; backed up and restored): Plumbing pad visible, bought → Materials owned, mines yard + materials shop shown, gate gone, 16 clay + 20 iron rocks, sink / material speed + qty pads and the 2nd-register pad shown; all 7 unlock cards shown; 4 miners, 3 section carriers, 2 section cashiers hired, register 7 bought; the player mined 2 iron by hand in ~6 s. Soak ×4, 199 → 1 152 s of game time: miners kept cycling yard ↔ inputs (clay and iron), both factories busy, materials-shop shelves full (23/23) so section carriers took the rest to the truck docks (prototype goodsTarget), section cashiers posted at registers 6 and 7, annex customers paid. Console: no errors from our code (only Unity IAP's token error and the known pool-prewarm warnings → M9).
- [x] I. Commit `M8: plumbing and building materials`, push, user play-test, PR → main

Notes (implementation):
- `WorldStateSnapshot.OwnsPlumbing` is now derived from owning "sink"; `Ownership` also owns products whose `unlocksWith` is the bought one; `PadRewards` shows "t.sinkOpened" and rebuilds blockers for `reg_annex`; `WorldStateSync` sets `AnnexSecondRegister`.
- `PlumbingSwitch` on the blockout root shows MinesYard / MaterialsShop and hides the Gate (on load and on the "sink" unlock). Rocks are ResourceNodes under MinesYard/Rocks (seed 20261105), so they only count while the yard is open.
- `LockedLabel.Kind.OpensWith` ("Building materials / Opens with Plumbing") on the Materials lot; `sink_buy` and `reg_annex` (rule OwnerOwned, owner sink) pads in ShopBuilder.
- Workers: `WorkerKind.Miner / SectionCarrier / SectionCashier` (enum order = prefab order), `MinerRules` (resource by input fill ratio, gap way-points), `CarrierJobs.Pick(sectionOnly)`, clay / iron leftovers go to their factory input, `StaffAssignment.AssignStaff` (section cashiers on 6 / 7 first). Miners reuse the lumberjack chop rate 0.75 and reach 1.1 (same in the prototype).
- Unlock cards: `FactoryWith` (fac_material), `Mines`, `MaterialsShop`; icons "mine" and "shop" from the prototype UN_ICON.
- G: 604/604 EditMode (15 new in PlumbingTests).

Play-test fixes (user, 2026-11-05):
- "No Miner and no Section carrier in Upgrades": the Upgrades sheet still filtered out the group g.section (an M4 placeholder "joins with plumbing in M8", missed because my Play Mode check hired the section staff through the shop API). The filter is gone: every group shows, like the prototype `renderShop`; section rows stay locked ("Plumbing") until it is bought. Checked in Play Mode on the user's save: the group shows Miner / Section carrier / Section cashier, buying a miner through its button hires one; 604/604 EditMode.

Prototype quirks / not ported (prototype wins):
- The back "sales area" (BULK wholesale zones at (51.4, −30.4 / −33.6), register 8, contractor customers, "Sales area seller") is dead code in the prototype: `buildBulk()` is never called and the register list has 8 entries, so register 8 never exists. Not built (texts stay in the tables).
- `routeVia` (gap at x 53) only served those bulk zones; only the miner's gap at x 44 is used.

### More workers: +1 hire limit — 2026-11-05 (branch `workers-plus-one`)
Result: lumber / carrier / robot 5, stocker 4, manager / consultant 3 (cashier 8 unchanged); own rest / stand spots for the extra carrier and manager; 589 tests green; user play-test OK 2026-11-05; merged into main.
User request (2026-11-05, after the M7 play-test): workers are too few, add one more of each.
Decision (user): every hired worker except the cashier gets +1 max level — lumber, carrier, robot 4→5; stocker 3→4;
manager, consultant 2→3. Cashier stays at 8 (only 6 main registers + 1 annex, a 9th would idle). The extra level costs
the same formula round(base·1.25·mul^lv/50)·50: lumber $109,800, carrier $161,050, robot $1,658,900, stocker $119,800,
manager $156,250, consultant $312,500. Deviation from the prototype (`UPG` max values) — on purpose.

- [x] 0. Branch `workers-plus-one` from main (after the M7 merge)
- [x] A. Design/data/upgrades.json: `max` +1 and `costPerLevel_beforeECON` extended for the six ids; FF/Import Design Data
- [x] B. Check the code has no hidden 4/3/2 caps (rest spots, manager stands, consultant spots, robot tag, upgrade pips) and the 5th / 4th / 3rd worker gets a sane spot
- [x] C. Tests: upgrade max levels and new-level prices; full EditMode run
- [x] D. Play Mode: hire the extra workers on a copy of the save, check spots and Console; restore the save
- [x] E. Commit, push, PR; merge after the user's play-test

Notes:
- B: carriers rested on 4 REST spots round-robin, so a 5th sat on the 1st one's spot → `WorkerLayoutSettings.CarrierRest(i)` continues the row (5th at (0, −1.2)); managers had two stands (−0.4 / +0.7 from the cash zone) → `ManagerStandZ(i)`, the 3rd stands at −1.5. Stocker / robot / cashier / manager idle and consultant spots were already start + i·step (consultant 3 at x 21).
- C: 589/589 EditMode (new: hire limits + last-level prices, carrier rest, manager stand).
- D: Play Mode on the user's save (backed up, restored after): all six bought up to the new limit (31 workers), after 60 s every new worker had a job or its own spot; no new Console errors on play / stop. A one-frame NullReference burst (87, at 14:12:23) came when the first test run timed out and stopped Play Mode — not from this change, not reproduced on a normal stop.
- `Game.unity` shows Editor re-serialization noise (TMP auto-size, Cinemachine streaming version) — not committed.

### M7 — Delivery & car park — 2026-11-02 (branch `m7-delivery`)
Result: trucks with bays, docks and payout pop; cars with car-park customers over the zebra; truck loads kept in save v4; 580 tests green, 30-min soak with 0 stuck vehicles; user play-test OK 2026-11-05; merged into main.
Goal (04_IMPLEMENTATION_PLAN): truck bays, truck state machine, dock zones, payout pop next to the balance; car park, cars,
car customers crossing the zebra. Done when trucks and cars loop indefinitely without getting stuck (soak test 30 min).
Prototype refs: `LANE/PARK/ORDER/BAYZ` (645), bays + truck/parking pads (987–1000), `makeTruck / updTrucks` (1405–1432),
bay chip (1506–1511), `moneyPop` + `.mpop` (1457, css 32–34), `LOT / buildLot / makeCar / spawnCar / carLeave / updCars` (824–866),
car customer path in `spawnCustomer / leave` (1357–1365), car spawn timer (1376), `freeDock / goodsTarget` (1267–1269),
robot truck job (1285–1286); spec §9 (car customers), §10; data: economy.json `truckOrderSize/truckAwaySeconds/carPark`,
world_layout.json `delivery / road / carPark`, pads.json `truck / parking`.

- [x] 0. Branch `m7-delivery` from main
- [x] A. Data: `DeliveryConfig` numbers (order 8, away 10 s, start x −80, despawn x > 80, in-speed clamp((bayX − x)·1.6, 3, 18), park/unpark 3 m/s, out accel 9 → 18 m/s, full-wait 0.6 s, bed pile 2×4 at 0.66 × 0.64) and car numbers (spawn 6–11 s, slots min(8, 4 + shopLv), road 10 / lot 3.4 m/s, heading lerp 8, spawn x 140, 8 colours) — from the JSON where it has them, prototype constants otherwise (noted as such)
- [x] B. Prefabs (low-poly like the prototype, pooled): Truck (`makeTruck`: dark chassis, red cab, windshield, wooden bed with sides, 4 rolling wheels, load anchor) and Car (`makeCar`: body, glass, roof, bumpers, glowing head / tail lights, 4 wheels; colour per spawn)
- [x] C. Bays and docks: 3 bays at x −4 / −9.2 / −14.4, bay i active when i < 1 + parking level (inactive bays hidden); dock zone "TRUCK" accepts any furniture and its pile is the parked truck's bed, open only while a truck is at the bay and has < 8; marker bright with a truck, dim without. `Zone` gets an "any product" accept mode and a swappable pile
- [x] D. Trucks (pure `TruckStateMachine`, tested): away (10 s) → in (lane 14.6 from x −80, slowing to the bay) → park (to z 12.3) → bay (load until 8, then 0.6 s) → unpark → out (accelerate east) → past x 80: payout Σ round(salePrice·1.4) + Σ XP, then away. One truck per bay; extra trucks wait. Truck pad (+1 truck, max 4) and Parking pad (+1 bay, max 2) work; trucks spawn from the pad level on load
- [x] E. Bay tag (prototype chip): "No truck" (bay 0, no trucks bought) / "Arriving…" / "n/8" / "Free · N s" / "Free"
- [x] F. Payout pop: small green chip with a truck icon to the right of the balance, "+$12K", slides in, holds, rises and fades in 2.2 s; several can overlap (pooled)
- [x] G. Workers: carriers send furniture to a free dock when its shelf is full (prototype `goodsTarget`); robots get the truck job (score 1.1 + 0.8·n/8 + (output > 80 % ? 1) − 0.9·other robots, tag "Truck") and drop leftovers dock-first; the M6 notes "truck jobs in M7" are closed
- [x] H. Cars (`CarDirector`): every 6–11 s, if a slot below min(8, 4 + shopLv) is free and a product is owned, a car comes from x 140 on the west lane (z 12.3) → driveway (33, 12.3) → aisle (33, 19.6) → (slotX, 19.6) → nose-in (slotX, 22.6); 10 m/s on the road, 3.4 in the lot. Parked → its driver walks (slotX + 1.15, 19.6) → (20, 18) → over the zebra to the shop door and shops as usual; leaving, walks back, gets in, the car reverses to the aisle, drives to (33, 14.6) and east off-screen, the slot frees. Car customers don't count toward the walk-in limit
- [x] I. EditMode tests (580/580 green): truck states and timings, payout with ×1.4 and XP, bay assignment / waiting trucks, dock accept rules, bay tag state, carrier and robot dock jobs, car-park slot count, car path points and speed rule, car customer way-points
- [x] J. Play Mode + soak: 30 min of game time (time scale ×4) with 4 trucks, 3 bays, robots, carriers and cars: a watchdog reports any truck or car stuck in one state (> 60 s, parked cars > patience + shopping time); Console without errors → done 2026-11-04: 2 046 s of game time at ×4 on the user's save (4 trucks, 3 bays, 3 robots, 4 carriers): 50 deliveries, every truck kept cycling (the 4th waits for a free bay), cars parked / shopped / left with max 18 s arriving and 92 s parked, 0 stuck vehicles, no errors (the user's save was backed up before and restored after)
- [x] K. Commit `M7: delivery and car park`, push, user play-test, PR → main

Notes (implementation):
- New code: `FF.Gameplay.Delivery` (TruckMotion pure state machine, DeliveryRules: free bay / bay chip / payout, Truck, TruckBay, DeliveryDirector, DeliveryCargo) and `FF.Gameplay.CarPark` (CarRoute + CarMotion pure, Car, CarDirector); `Zone` got an "any product" mode and a lent pile (`UsePile`); `WorldTagStyle.Note` for the bay chip; `GameEvents.TruckDelivered` → `PayoutPopView` (HUD). Editor: `VehiclePrefabBuilder` (menu FF/Build Vehicle Prefabs, Prefabs/Vehicles), bays + truck / parking pads in `ShopBuilder`.
- Prototype quirks kept: trucks slide sideways between the lane and the bay; the bay chip says "Arriving…" while a full truck pulls out.
- Save v4: `trucks` = item types per truck index; restored trucks stand at the first free open bay with their load; a truck keeps its entry until it has delivered, so quitting while it drives away pays later instead of losing the load.
- Play Mode (user save, 4 trucks / 3 bays given in the session only): carriers and robots load trucks, the player can drop furniture on a dock, trucks cycle and pay ("+$4.8K" chip next to the balance), the 4th truck waits for a free bay; cars park, drivers shop and walk back over the zebra; save → restart restores each bed exactly.

Follow-up (M9 performance): item pools of furniture are prewarmed with 4 each (M2 value; the builder keeps tuned values), so with all factories and trucks they grow at runtime ("Item pool 'Chair' ran dry" warnings) — size them for the full game.

Decisions (user, 2026-11-02):
1. Truck loads on restart [save them — deviation from the prototype, which loses them]: the save gets the furniture on each docked truck (types in order); on load the truck stands at its bay with that load. Save version +1 with migration (older saves → empty trucks). Covered by a save round-trip test.

### M6 — Workers & robots — 2026-11-02 (branch `m6-workers`)
Result: lumberjacks, carriers, stockers, robots (scored jobs + task tag), cashiers, manager, consultant; back-row trips through the gaps; Upgrades sheet tap/scroll fixes; 557 tests green; user play-test OK 2026-11-02; merged into main.
Goal (04_IMPLEMENTATION_PLAN): a fully staffed factory runs without the player; robots prioritise empty shelves with waiting customers.
Prototype refs: `REST / WORKER_SKIN / spawnWorker` (~1184–1203), `assignStaff / updCashier` (~1205–1216), `updManager / updConsult /
regServer` (~1239–1250), `updLumber` (~1251–1265), `plankTarget / goodsTarget / sawOuts / sawIns / pickJob / updCarrier` (~1266–1336),
`robotJob` (~1274–1296), `makeRobot` (~581), boot spawn (~1716), `.chip.bot` (~65), spec §8; numbers: economy.json `workers`.
Section workers (miner, section carrier / cashier) come with plumbing in M8; truck jobs with the docks in M7.

- [x] 0. Branch `m6-workers` from main
- [x] A. Data: `WorkerDef` per kind (speed 3.4 / robot 5.2, carry cap lumber 4 / robot 8 / others 5, chop rate 0.75, transfer 0.12 s, stuck 1.5 s, rest spots, skin colours from WORKER_SKIN) imported from economy.json `workers` + prototype constants
- [x] B. Prefabs: one per worker kind from the character rig (prototype skins: hard hat lumberjack, teal carrier, cream cashier, green stocker, navy manager, purple consultant) + the robot rig of `makeRobot` (wheel base, glowing ring, chest screen, head visor, antenna); pooled by a `WorkerDirector` that spawns `lv` workers per kind on load and one more on every purchase
- [x] C. Shared kinematic motor (prototype `moveTo`, arrive 0.06 m) used by customers and workers; walking / carrying / chopping animation as for the player
- [x] D. Lumberjack (`updLumber`): nearest unreserved tree, reserve, chop at 0.75, carry 4, deliver to the emptiest working sawmill input, one log per 0.12 s
- [x] E. Carrier / Stocker (`pickJob / updCarrier`): carrier moves goods from the fullest factory output to the emptiest shelf with room, else planks from the fullest sawmill output to the emptiest plank-factory input; stocker shelves only; leftovers find a target by type; blocked for 1.5 s → drop the job; idle → rest spot
- [x] F. Robot (`robotJob`): scores every job — shelf: (1 − n/cap) + 1.5·waiting customers + (empty ? 1) + (output > 80 % ? 1) − 0.9·other robots heading there; planks: 1.2·(1 − in/cap) + (factory idle and starving ? 1.6) − 0.9·busy; all − distance/60; takes the best above 0.15; teal task tag over it ("Shelf · Chairs", "Planks → Sofas", "!" when urgent). Pure scoring function, tested against the prototype numbers
- [x] G. Cashier (`assignStaff / updCashier`): takes the next free active register in prototype order, stands at the counter, serves at rate 1 (player on the zone 1.4 wins); Manager (`updManager`): goes to the register with most bills, collects one per 0.08 s into the balance; Consultant (`updConsult`): stands in the shop and sways (effect already live: bills +15 %, patience ×1.6)
- [x] H. Paths: workers walk straight lines like the prototype, except trips between the front yard and the back factory row, which go through the gap between front buildings nearest to the trip (our two-row layout; the prototype has a single row and only routes the mines trip, `routeVia`)
- [x] I. Upgrades panel: Workers (lumberjack, carrier, robot) and Shop staff (cashier, stocker, manager, consultant) groups appear; shop toast gets "Can hire: …" back; unlock cards for staff that open with the shop level ("New staff: Stocker")
- [x] J. EditMode tests (557/557 green): carrier job choice (goods first, emptiest shelf, planks fallback, stocker shelves only), robot scores and threshold, register assignment order, lumberjack target / delivery choice, motor arrive rule, worker counts from levels, staff unlock cards
- [x] K. Play Mode check: shop Lv 5, hired 2 lumberjacks, 2 carriers, cashier, manager, robot; player parked in the forest for 2 min → logs → planks → chairs → shelf → 36 sales (+$15 480), Lv 1 → 6, without the player; robot took "! Shelf · Chair" (empty shelf, customers waiting); restart → 7 workers back; Console clean apart from Unity IAP's services-token error
- [x] L. Commit `M6: workers and robots`, push, user play-test, PR → main
- [x] Bug (user play-test 2026-11-02): a tap anywhere on the Upgrades sheet closes it — must close only on the ✕ button or outside the sheet. Cause: the sheet panel is a child of the backdrop Button, so uGUI bubbles the click up to it. Fix: backdrop and panel become siblings. Checked in Play Mode: tap inside → stays open, backdrop → closes, ✕ → closes
- [x] Bug (user play-test 2026-11-02): scrolling the Upgrades list works badly. Causes: (1) the list has no raycast surface (cards and texts ignore pointers), so a drag only scrolls when it starts on a price button; (2) every money change (several per second with workers) re-localizes and re-lays out every row. Fix: transparent hit surface on the scroll viewport, elastic scrolling with inertia and a usable wheel step; money changes only update the buttons and the balance, once per frame and only when they change. Checked in Play Mode: a ray at the middle of the list hits Body, a 600 px drag scrolls, inertia keeps rolling after release, buttons go grey at $10 and green again after a refill; 557/557 tests

Notes:
- New FF.AI assembly (WorkerDirector, Worker, pure CarrierJobs / RobotScoring / StaffAssignment / WorkerRoutes); Gameplay only exposes hooks (Register.StaffRate, IPile on zones, AgentMotor).
- "→" is missing from Noto Sans: Noto Sans Symbols Bold (notofonts, OFL) is now the second TMP fallback (FontSetup) — fixes "Planks → Sofas" and any other arrow in texts.
- Lumberjacks use the player's axe level for chop time, like the prototype's `tryChop` → `st.chop()`.
- Truck jobs for carriers / robots come with the docks in M7; section staff with plumbing in M8.

Decisions (approved by the user):
1. Worker paths [straight lines like the prototype, but trips to / from the back factory row go through the nearest gap between front buildings, so nobody walks through the walls]
2. Section staff (miner, section carrier / cashier) [stay hidden until M8 with plumbing; the Workers and Shop staff groups open now]

### M5 — Product line expansion, shop growth, unlock cards, save — 2026-11-02 (branch `m5-expansion`)
Result: factory buy pads + lock chips, shop expansion, register pads (6 registers), unlock cards with guide arrow, versioned save/autosave, dev panel; 545 tests green; user play-test OK 2026-11-02; merged into main.
Goal (04_IMPLEMENTATION_PLAN): from a fresh save you can reach Lv 35 and own all furniture factories; restart restores everything.
Prototype refs: factory buy pads + lock chips (~935–941, `ownFactory` ~1015), `shopW / layoutShop / refreshBlocks` (~456, 1022–1035),
shop pad + `shopUnlockText` (~973, 1021), register pad + `placeRegPad` (~970–972), `notify / checkUnlocks / updUnlock / UN_ICON`
(~1647–1695), guide arrow (~1641–1643), save/load (`KEY`, `S`, `save()`, `visibilitychange` ~256–264, 1723), spec §13, §16;
CSS `.unlock` (~106–114), `.chip.locked` (~71).

- [x] 0. Branch `m5-expansion` from main
- [x] A. Factory buy pads (sofa, wardrobe, table, kitchen; sink in M8): pad shows on the lot when the factory is not owned and the player level ≥ unlock level; paying it → factory owned (building pops in, lot goes, shelf + machine + zones + speed/qty pads appear, blockers rebuilt), toast "sign · New factory opened"
- [x] B. Lock chips over lots (`.chip.locked`): "Sofas / Opens at Lv 5" (honey second line) while level < unlock; "Sawmill 2" over its lot; "Dream house / Soon" over the dream plot — new world-tag style with two lines
- [x] C. Shop expansion pad (`shop`, max 5): right wall moves to x = 25 + 4.2·lv, animated (lerp 3/s): floor, floor stripes, right wall + plants, front-right wall + trim; blockers follow; shelves +3 each level, more / faster walk-ins (already live through the level); toast "Shop Lv N" + "Can hire: … · +1 register slot"
- [x] D. Register pad (`reg`, max 5): visible while reg < shop level, sits on the next free register slot and moves after each purchase; register i active when i < 1 + min(reg, shop) — stall appears, blockers + customers use it
- [x] E. Pad visibility rules as one tested function (upgrade pads: owner owned; buy pads: not owned and level ≥ unlock; register pad: reg < shop; shop pad: always) instead of per-pad flags
- [x] F. Unlock cards (`notify / checkUnlocks / updUnlock`): queue, one card at a time for 4.6 s, slide-in, cream card with honey border, icon tile, "NEW", title + subtitle; each id once (`seen`); guide arrow to the target for 12 s or until within 1.5 m (tutorial arrow wins). Cards now: factory reachable (with its price), new register slot, Sawmill 2 (after the tutorial), dream plot (after the tutorial). Checked on boot (silent), level-up, shop level, tutorial end
- [x] G. Save (new `FF.Save` assembly): versioned JSON (`version`, money, total, xp, level, quest, lv{}, pads{lv, paid}, owned{}, seen{}, lang, skin) in `persistentDataPath/save.json`, written atomically (temp file + replace); autosave every 3 s when changed, on pause / focus loss / quit, right after every purchase; load at boot before the world starts (owned buildings, shop width, registers, pads, upgrades, tutorial step, language); migration hook per version; a broken file → backup + new game. Piles and positions are not saved (as in the prototype)
- [x] H. Editor menu `FF/Delete Save` (new game while testing)
- [x] I. EditMode tests (545/545 green): pad visibility rules, shop wall x / blockers per level, register slot + active rule, unlock rules (which cards, once only), save round-trip (every field), version / broken-file handling, owned factories after load
- [x] J. Play Mode check: dev +25 Lv → card "Sofa factory · $19K"; bought Sofa $18.75K, Wardrobe $75K, Table $187.5K, Kitchen $500K (partial payment kept) — back row Sofas / Tables / Kitchens; shop Lv 5 (wall x 46) + 5 register pads → 6 registers; stop + start Play → level, money, owned, shop, registers, seen cards, language (ru) and the cap upgrade restored; new game shows "Wardrobes / Opens at Lv 12"; Console clean except Unity IAP's own services-token error
- [x] K. Commit `M5: factory purchases, shop growth, unlock cards, save` (984e6bf), push, user play-test OK, PR → main

Notes:
- Tests through the Pipeline CLI need the Editor ticking when it is not focused: `unity command editor set_auto_tick --enable true` (otherwise the run times out after "Running N tests").
- Unity IAP (kept by the user) logs "[InAppPurchasing] RequestFailedException" in the Editor (Unity Services token exchange) — not from our code.
- Shop toast says "Shop Lv N · +1 register slot"; the prototype's "Can hire: …" part comes back with staff in M6.
- Save file: `persistentDataPath/save.json` (macOS Editor: ~/Library/Application Support/DefaultCompany/Mebel/); `FF/Delete Save`, `FF/Reveal Save Folder`.

Decisions (approved by the user):
1. Unlock cards for things that are not in the game yet — staff (M6), mines / materials shop (M8), skins (M9) [show only cards for what already works: factories, registers, Sawmill 2, dream plot; the others come with their milestones]
2. Testing up to Lv 35 takes hours of play [add a dev panel for Editor / development builds only: "+25 Lv, +$250K" (the prototype's menu test button) and "New game"; not in release builds]
3. Consultant upgrade unlocks at shop Lv 5, but the staff group stays hidden until M6 [keep it hidden until M6 with the other staff]

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

### Fix: Android build output got committed — 2026-11-01 (branch `chore/untrack-build-artifacts`)
Cause: the user's Android test build wrote `first.apk`, `first_BackUpThisFolder_ButDontShipItWithYourGame/` (IL2CPP backup,
752 files) and `.utmp/` (CMake temp) into the project root; Claude's `git add -A` in df46b3b committed the last two
(≈15 M lines) plus Unity IAP (`com.unity.purchasing` 5.4.4, added by the build setup) and they reached main via PR #4.
No secrets inside (checked: no keystores/keys/tokens); CMake files contain local paths (/Users/armen/...).
- [x] Remove the artifacts from the index (files stay on disk), ignore `*_BackUpThisFolder_ButDontShipItWithYourGame/`, `*_BurstDebugInformation_DoNotShip/`, `.utmp/`, `*.aab`, `*.symbols.zip`, `Builds/`
- [x] Ask the user: purge the artifacts from git history (force-push main) or not; keep or remove Unity IAP → user: no history rewrite (cleanup commit only); keep Unity IAP (`com.unity.purchasing` 5.4.4, `Assets/Resources/BillingMode.json`)
- [x] PR → main, sync local main (PR #5)
- Rule from now on: stage files explicitly / review `git status` fully before committing; never `git add -A` blindly.

### M4 — Upgrade pads, building growth, upgrades panel — 2026-11-01 (branch `m4-upgrades`)
Result: buildings grow with their pads (floors, chimneys, fan, tank, flag, Lv tag, fade, effects), Sawmill 2 buy pad, Upgrades panel (Player + Business); 530 tests green; user play-test OK 2026-11-01; merged into main.
Goal (04_IMPLEMENTATION_PLAN): pads work; buildings grow; panel prices match upgrades.json.
Prototype refs: `makeBuilding / setBuildingLevel / TRIMS` (~659–705), `refreshBuilding / capMul / fadeBuildings / setGhost /
ghostOf` (~1115–1140), `puff / burst / updParticles` (~1108–1114), building pop/bounce/fans/flag/smoke in `updMachine` (~1084),
Lv chip in `setupLabels` (~1503), `UPG / upPrice / upLocked / lockText` (~238–256, 452–456), `renderShop / openSheet /
buy click` (~1572–1597), `hudMoney` badge (~1446), sheet CSS (~118–139), saw2_buy (~918).

- [x] 0. Branch `m4-upgrades` from main; commit the pending font SDF assets first
- [x] A. Data: `BuildingKit` SO (meshes + palette colours used by growth: trims, lit/unlit windows, chimney, fan, tank, flag); every growth colour pre-created in MaterialPalette + a transparent "ghost" twin per colour (opacity 0.22, made in the Editor so the shader variant ships); `UpgradeDef` gets name/desc keys + value format (items / % / sec / people / bots / price / customers)
- [x] B. Building growth: `BuildingVisual` rebuilds the Deco group from (speed s, qty q) exactly like `setBuildingLevel` (tier trims, lit windows, q floors of 1.25 m, roof on top, chimneys at s ≥ 1 / 5, roof fan s ≥ 3, tank s ≥ 7, gold flag s = 8 & q = 3); pop-in (new building), bounce on upgrade (scale y +16 % / xz −6 %, decaying sine), fans spin (fast while busy), flag sways
- [x] C. Effects: chimney smoke (rate ↑ with speed and when busy, max 160) and 28-cube confetti burst — Unity ParticleSystem, one shared system each, pooled; on a speed/qty pad: bounce + confetti + floating `f.cap` ("×2 output · 38 slots")
- [x] D. Lv tag over every working building: honey pill "Lv 3 · ×2" / "MAX · ×4" (new world-tag style), hidden while the building is faded
- [x] E. Occlusion fade (`fadeBuildings`): player behind a building (|dx| < 4.2, 2.3…15 m behind) → its renderers switch to the ghost materials, no shadows; back on when the player leaves
- [x] F. Pads: every sawmill / factory speed + qty pad (effects already live through the machines, now with growth) + `saw2_buy` (Sawmill 2: building pops in, lot disappears, blockers rebuilt, toast `t.saw2`); generic "owned building" switch (building ↔ lot) reused by M5 factory buy pads
- [x] G. Upgrades panel (bottom sheet, prototype `.sheet`): "Upgrades" honey button top-right with the red badge when something is affordable; header title + balance + close; pad note; group headers; rows: name, description, level pips, "5 items → 7 items", green price button / grey when too expensive / lock text (`Shop Lv N`, plumbing) / MAX; buying spends money (`upPrice`), joystick off while open, scrolls on phones, safe area
- [x] H. Upgrade effects live now: carry capacity, walk speed, axe speed (player); ads (spawn rate + walk-in cap), quality (sale price), consultant (bill +15 %, patience ×1.6 — locked until shop Lv 5, M5)
- [x] I. EditMode tests (530/530 green): growth layout per (s, q) (floors, chimneys, fan, tank, flag, tier), upgrade prices vs upgrades.json `costPerLevel_beforeECON` × ECON, lock rules, value texts, badge rule, ownership switch + blockers, Lv tag text, fade region
- [x] J. Play Mode check: saw_speed 8 + saw_qty 3 → 3 floors, gold trim, lit windows, 2 chimneys with smoke, fan, tank, flag, storage 86/108; fade with the player behind it; Sawmill 2 bought for $25K (pads $3.1K / $7.5K, blocker added); chair_qty → confetti, Lv 2 · ×2, 38/19, next $12K; panel in phone portrait (ru) with wrapping, grey too-expensive and green buttons; Console clean
- [x] K. Commit `M4: building growth, pads, upgrades panel` (8068190), push, user play-test OK, PR → main

Notes:
- Noto Sans has no "→": the panel draws an arrow icon between the values; values sit on their own line under the pips (one line does not fit a phone row).
- Ghost (faded) materials live in Art/Materials/Ghost, one per lit palette colour; BuildingKitBuilder adds missing ones on every scene build.
- Sawmill 2 now sits in Blockout/Sawmill2Slot/{Building, Lot} with an OwnedBuilding switch (same as every FactoryRow/<id>).
- UpgradesPanel lives on the HUD root (always active); its sheet is a child that it shows / hides.

Decisions (approved by the user):
1. Which pads in M4 [speed/qty of every sawmill and factory + saw2_buy now; factory buy pads, shop expansion and register pads in M5, truck/parking in M7, reg_annex/sink in M8 — as those milestones list them; "every pad works" is then met at the end of M8]
2. Worker / staff / section rows of the panel (workers come in M6, section staff in M8) [show only the Player and Business groups now (cap, speed, axe, ads, quality); each other group appears with its milestone, so nobody pays for workers that do not exist yet]
3. Dev language button sits top-right where the "Upgrades" button goes [move it under the Upgrades button until the real menu (M9)]

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

### M3 play-test changes (user requests) — 2026-10-31 (branch `m3-shop`, before the M3 merge)
Result: tutorial text wraps on phones, dollars before the number, factories in two lines (pairs across the fence); user play-test OK 2026-11-01. These are deliberate design changes away from the prototype (the user decides; the
prototype no longer wins for layout and currency).
- [x] 1. Tutorial text must fit a phone screen: the quest bar (and toast subtitle) wrap to the safe-area width minus 16 px margins (prototype `max-width: calc(100% - 32px)`)
- [x] 2. Currency: dollars, sign before the number — `$430`, `$1.9K`, `+$430`; HUD coin shows `$`; cash zones and buy-pad glyphs `$`; the 5 localization strings with ֏ in hy/en/ru; CLAUDE.md non-negotiable updated
- [x] 3. Factories in two lines, "pairs across the fence" like the sawmills (user picked this layout):
  - front row (z −10, facing the road): Sawmill 1 (−10), Chair (−2), Wardrobe (6); front slot x 14 stays empty
  - back row behind the fence (z −23.5, zones at z −18.8 between building and fence): Sawmill 2 (−10), Sofa (−2), Table (6), Kitchen (14)
  - Sink (40) and Material (48) stay next to the mines yard
  - back yard widened from x −18.5…−1.5 to −18.5…20.5; the fence is open over the whole yard width (as for the sawmill yard today); region rule yard split moves from x 15 to 27
  - pads: every factory at x + 4 (front speed −11.1 / qty −8.8, back speed −24.6 / qty −22.3), buy pad on the building spot (front −9.6, back −23.1); saw2 pads move from x −4.4 to −6 (Sofa now stands there)
  - data: products.json `factoryX` + new `factoryRow`, pads.json positions, world_layout.json back row + yard; blockers per row; tests that compare against the prototype layout get the new reference numbers
  - Result: 503/503 tests green; Play Mode: phone portrait 1080×2340 wraps step 7 (ru) onto 2 lines, `$12K` / `$1.9K` everywhere, back yard reachable, back lots in a row behind the open fence. Unity rewrote two URP settings assets during the session (volume profile, shader prefiltering) — reverted, not part of this change.
  - Game view is left at a custom 1920×1080 size after the portrait check (no API to restore "Free Aspect").
- [x] 4. Tests green, Play Mode check (phone portrait text, $ everywhere, walk into the back yard, back factories behind the fence), commit, push

### M3 — Shop, customers, registers, money, XP, HUD, tutorial — 2026-10-31 (branch `m3-shop`)
Result: shop, walk-in customers, registers, cash, money/XP/levels, HUD, 8-step tutorial, 4 upgrade pads; 503 tests green; user play-test OK 2026-11-01; merged into main.
Goal (04_IMPLEMENTATION_PLAN): full 8-step tutorial completes; money and XP match prototype formulas.
Prototype refs: shelves + registers (~941–960), customers `spawnCustomer/chooseReg/updCustomers/leave` (~1336–1440),
`regServer` (~1245), cash zone in `updPlayer` (~1170), `addMoney/addXP/onLevel/toast` (~1445–1462), `QUEST/emit/renderQuest`
+ arrow (~1464–1482, 1641), `addPad/drawPad/updPads` (~716–760), HUD markup/CSS (~24–60, 150–166), `floatText` (~1496).

- [x] 0. Branch `m3-shop` from main
- [x] A. Data
  - EconomyConfig: customer numbers (spawn 5 − 0.5·ads − 0.3·shop, min 1.1; walk-ins 4 + ads + 2·shop; walk 2.9 m/s; patience 45 s ×1.6 with consultant; take delay 0.3 / take 0.35 s; serve 0.9 s, player serve ×1.4; bill value formula), bill/cash flight timings, floating text rise
  - WorldLayout: shelf geometry (pile, queue slots 1.45 + 0.85·i, ±0.35), register queue (x + 1.25, z − 0.5 + 1.05·i, approach +3.6), cash zone offset (−1.45, −0.1) + cash pile, pad size 1.8
  - TutorialDef: structured steps (event drop/pick/chop/cash/pad + zone id + arrow target); the importer maps the `completeOn` texts of tutorial_quest.json
- [x] B. Progress (pure C#): `GameProgress` — money, total earned, xp, level, quest step, pad states {lv, paid}; implements `IUpgradeLevels` (pads by id, panel upgrades 0 until M4); `LevelMath.AddXp` (xpNeed = round(8 + 4.5·lv), multi-level-ups); GameEvents MoneyChanged / XpChanged / LevelUp / CashCollected. Saving comes in M5 (restart = new game until then)
- [x] C. Shop: shelves for every product (LayoutBuilder; active when owned) with shelf zones (cap 8 + 3·shop level, pile 2×2); register cash zones (kind Cash, ֏ glyph, honey tint, bills pile on the counter); register active rule i < 1 + min(reg, shop)
- [x] D. Customers: 12 pre-built skin variants (prototype palettes, seeded) pooled; `CustomerDirector` = port of `updCustomers` (spawn timer + cap, shelf/register queues, take item, choose least-busy register, served by the player standing on the cash zone, bill → counter pile, XP, "+430 ֏" float, leave, patience → angry); pure `CustomerQueues` (slot positions) + `CustomerRules`; bubbles (wanted product icon / cash icon / angry face) as a new world-tag style with icons generated from the prototype SVGs
- [x] E. Cash: the player on a cash zone collects one bill per 0.035 s (bill flies to the player, then money is added)
- [x] F. HUD: money pill (coin ֏ + `fmt`, bump on gain), level pill + XP bar, quest bar ("1/8" + text), bottom hint until step 2, level-up toast (`t.level`, `t.newFactory`/`t.keepGoing`), floating texts layer (pooled)
- [x] G. Tutorial: `TutorialService` advances on GameEvents exactly like `emit()`; bobbing/spinning honey cone arrow over the target (nearest tree, zone, pad)
- [x] H. Upgrade pads (needed for tutorial step 8 — see decision 1): `UpgradePad` paying mechanic (0.95 m, still ≥ 0.3 s, amt = min(money, remain, max(1, ⌈price·dt/1.4⌉)), bill flies every 0.07 s, level++, "done" float, PadCompleted event) + pad visual (honey rounded square, green fill from the bottom, glyph, remaining price). Active in M3: saw_speed, saw_qty, chair_speed, chair_qty (their effects already work through the machines); other pads come with their milestones
- [x] I. EditMode tests: LevelMath/GameProgress, bill value / sale price, CustomerQueues slots, spawn interval / walk-in cap / patience, register choice, pad payment + prices, tutorial parsing + matching, CompactChangeKey — 502/502 green
- [x] J. Play Mode check (scripted teleports): whole tutorial 1→8 completes; 5 chair sales = 2150 ֏ (5 × 430), XP 15 → Lv 2 with 2/17; saw_speed pad 1900 → Lv 1, next price 3300, sawmill storage 26/33; angry customers leave after 45 s; toast, bubbles, floats, cash pill seen; Console clean
- [x] K. Commit `M3: shop, customers, registers, money, XP, HUD, tutorial` (e2d3353 + df46b3b), push, user play-test OK, PR → main

Decisions (approved by the user):
1. Tutorial step 8 needs an upgrade pad, pads are M4 [move the pad paying mechanic + visual into M3, only for the 4 sawmill/chair pads; M4 keeps building growth, confetti, Lv tags, occlusion fade, upgrades panel]
2. Customer looks [12 pre-built colour variants from the prototype palettes, pooled; not a new random colour per customer]
3. HUD buttons "Upgrades" and "Menu" [not in M3 — they come with the panel (M4) and the menu (M9)]

Notes:
- Zone order in ZoneRegistry: machine zones, then shelves, then cash zones (prototype interleaves shelves with factories; zones never overlap, so the first-match rule gives the same result).
- `FF/Build Game Scene` keeps existing item / customer prefabs (stable file ids, no git churn); use `FF/Build Item Prefabs` / `FF/Build Customer Prefabs` to rebuild them after shape changes.
- In landscape on a desktop-sized Game view the level toast overlaps the quest bar (HUD is scaled for phones); same layout as the prototype on a phone.

Not in M3 (their milestones): car customers + car park (M7), unlock cards (with M5 product expansion), workers serving registers (M6), materials shop + bulk customers (M8), saving (M5), SFX (M9).

Notes:
- Open question to user: change "Communication" rule to "reply in the language of the user's message (Armenian or Russian)"? The user writes Russian; replies are in Russian until decided.

### M2 — Items, stacks, zones, trees, sawmill, chair factory — 2026-10-31 (branch `m2-production`)
Result: chop → logs → sawmill → planks → chairs loop with prototype timings/capacities, zones, counters, FULL tag, Throw; 485 tests green; user play-test OK; merged into main.
Goal (04_IMPLEMENTATION_PLAN): chop → logs → sawmill → planks → chair workshop → chairs loop works with
correct timings and capacities; Throw button. Prototype refs: `H/PROTO/makeItem` (~529), `Stack/sendTo/fly/updTweens` (~557),
`addZone` (~648), sawmill + factory zones (~905–933), `makeTree/updNode/nearestNode/tryChop` (~1038), `updMachine` (~1084),
`updPlayer` zone loop + `throwAll` (~1156–1182), counter chips `stackChip` + "FULL" chip (~1501, 1514).

- [x] 0. Branch `m2-production` from main; commit the 4 pending font SDF assets first (1fd0eba)
- [x] A. Data
  - `ItemCatalog` SO: per ItemType stack height H (prototype table; not in JSON → note), prefab, pool prewarm count
  - `PileLayoutSettings` (cols, rows, spacingX, spacingZ, anchor offset) in WorldLayout for sawIn/sawOut, plank-in, mine-in, product-out piles; capacities stay in EconomyConfig
  - `EconomyConfig`: add chop range 1.6, chop hit interval 0.3, flight durations (player 0.24, chop 0.32, machine in 0.3+0.02i / out 0.35+0.05i, throw 0.3+0.03i), arc heights, throw distance 1.5 / spread 1.2; importer keeps them
- [x] B. Item visuals: Editor `ItemPrefabBuilder` (menu `FF/Build Item Prefabs`) → `Prefabs/Items/*.prefab` for all 12 types from `PROTO` (log, plank, clay, iron, bill, chair, sofa, wardrobe, table, kitchen, sink, material), shared palette materials
- [x] C. Stacks (pure C#, FF.Gameplay/Items): `ItemStack` (items + incoming, fixed/non-fixed type rules, capacity func, `Pop`), `IStackLayout` → `CarryLayout`, `PileLayout`; `ItemArc` math (lerp + sin arc)
- [x] D. Runtime items: `Item` (type, pooled), `ItemPool` (per type, prewarmed, no Instantiate in play), `ItemFlights` — one runner with a struct list (no coroutines, no per-item allocations): fly-to-stack (live target slot), fly-and-despawn (machine mouth), throw-then-shrink
- [x] E. Zones: `Zone` MonoBehaviour (kind drop/pickup, accepts, stack, capacity, active), `ZoneRegistry` (short list, distance checks); pure `ZoneTransferRules` (first matching zone per tick, drop/pickup conditions, cooldown 0.075 s); ground marker = dashed rounded square (Editor-generated texture, tint per kind) + glyph ↓/↑ (baked into the texture) + localized label (`in.log`, `in.plank`, product sign)
- [x] F. Resource nodes: pure `ResourceNodeState` (alive, regrow 9 s, fall, grow elastic, shake) + `Chopper` (`tryChop`: progress·rate, hit every 0.3 s, yield min(2, room), hardness, type check, chop time from axe level); `ResourceNode` animates the tree `Top` (topple 0.4 s, regrow pop, shake); `NodeRegistry.Nearest`; forest trees get the component in LayoutBuilder (rocks come in M8)
- [x] G. Machines: pure `MachineCore` (`updMachine`: k = min(1+qty, ⌊in/inN⌋, ⌊(outCap−out.n)/outN⌋), cycle = base/(1+0.35·speed), capacities ×(1+0.6q+0.1s)); `Machine` adapter (zones, mouth, flights) + `MachineVisual` (saw blade spin, press bob); sawmill 1 (log 1 → plank 2, 1.6 s), sawmill 2 (inactive until owned), every product factory (active when owned → only chair at start)
- [x] H. Player: `PlayerCarrier` (carry stack on the rig anchor, cap 5+2·lv), `PlayerInteractor` (chop nearest node within 1.6 m and face it, zone loop, `StillTime` kept), animator Carrying/Chopping flags; `ThrowAll` (Q key + Throw action + HUD button)
- [x] I. UI: `ThrowButton` (bottom-right round walnut button, trash icon, `ui.throw`, visible only while carrying, safe area); `WorldTagLayer` — one screen-space canvas with pooled pills: pile counters "n/cap" over active zones, red "FULL" (`c.full`) over the player; UI reads Core interfaces only (`ICarrier`, `IWorldTagSource`)
- [x] J. Scene: `FF/Build Game Scene` adds Systems/Items (pool + flights), zones + machines from data, wires player and HUD
- [x] K. EditMode tests: ItemStack (incl. throw TakeAll), layouts (vs prototype formulas), ItemArc, ZoneTransferRules, Chopper, ResourceNodeState, MachineCore, StorageCapacity — 485/485 green
- [x] L. Play Mode check (scripted teleports): 3 trees → 5 logs (2+2+1, hands cap 5) → sawmill 5 logs → 10 planks → 5 planks to chairs → 2 chairs + 1 plank left; counters, FULL tag, Throw button, throw → items back in the pool; Console clean. No per-frame allocations by code review (no profiler run)
- [x] M. Commit `M2: items, stacks, zones, trees, sawmill, chair factory` (99f6b6c), push, user play-test OK (2026-10-31), PR → main

Decisions (approved by the user):
- SFX (chop/throw/pick) [later, M9; M2 raises GameEvents hooks only]
- Tween engine [own small runner, no DOTween]
- Pile counters + "FULL" tag in M2 [yes]
- Prototype quirk: chop progress is not reset when the player walks away from a tree [keep 1:1]

Notes:
- Not in Design/data JSON, taken from the prototype into data assets: item stack heights `H` (ItemCatalog), pile layouts + mouths (WorldLayout.production, sawmill2.machineMouth), flight/throw/chop timings and node hardness (EconomyConfig).
- Noto Sans has no ↓/↑ glyphs → the arrow is drawn into the zone marker textures (Art/Textures/ZoneMarker_*.png, generated by TextureFactory; delete a PNG to regenerate).
- Scene parts per machine: World/Production/Machine_<id> (zones Zone_<id>_in/_out with Marker + Pile). Zone order = prototype order (ZoneRegistry list).
- Pad levels (`saw_speed`, `chair_qty`, …) are read through IUpgradeLevels by id; all 0 until M4/M5.
- Play Mode automation: teleporting the player via `script eval` is faster than simulating keys (helpers in the session scratchpad, not in the repo).

### GitHub repo + Design/ setup — 2026-10-31
Result: Design/ in place, repo on github.com/Armen380/mebel, gh set up so Claude pushes/opens PRs.
- [x] Move `FurnitureFactory_Unity_Handoff/` → `Design/` (outside Assets), merge its CLAUDE.md into root CLAUDE.md
- [x] `git init -b main`, `.gitignore` (Unity), Git LFS (`brew install git-lfs`) + `.gitattributes`
- [x] First commit: template project + Design/ + rules
- [x] User creates an empty GitHub repo and sends the URL → `git remote add origin https://github.com/Armen380/mebel.git`
- [x] User installed `gh` and ran `gh auth login` (account Armen380); `gh auth setup-git`; pushed `main`, `m0-setup`, `m1-player-world` (22 LFS objects)

Notes:
- `gh` is installed and logged in (keyring, HTTPS): Claude pushes and opens PRs with `gh`. Login/credentials stay the user's.
- Branches: `m0-setup`, `m1-player-world`, merged into `main` after the user's play-test.

### M0 — Project setup — 2026-10-31 (branch `m0-setup`)
Result: packages, asmdefs, data import, localization hy/en/ru, fonts, scenes, 428 tests green; merged into main.
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
- [x] Commit `M0: project setup, data import, localization, fonts` (140ddc1)

Notes / discrepancies:
- pads.json `costPerLevel_beforeECON` used banker's rounding in 3 places (saw_speed lv1 2600, chair_speed lv1 2600, table_speed lv2 55100); prototype Math.round gives 2650/2650/55150 → prototype wins (test has explicit overrides).
- pads.json `reg` position is text ("next register slot") → imported as register 1 (26.4, 3.5) like `placeRegPad()` on a fresh save.
- Fonts come from github.com/notofonts (official Noto static TTFs; google/fonts only has variable fonts).
- `capture game_view --save_path` writes under `Assets/` — move the file out and delete `Assets/Temp` after use.
- Editor tooling run order on a fresh clone: FF/Import Design Data → FF/Setup Fonts → FF/Setup Render Settings → FF/Setup Scenes.

### M1 — Player, camera, input, world blockout — 2026-10-31 (branch `m1-player-world`)
Result: walkable world blockout, player, joystick/WASD, Cinemachine camera, 451 tests green, user play-test OK; merged into main.
- [x] A. Look (`FF/Build Game Scene`): background + linear fog #bfe3f0 42–95, trilight ambient (white / #7a9a55 ×0.72), sun #fff1d6 from the prototype sun offset; MaterialPalette SO + one Simple Lit material per colour (GPU instancing) in Art/Materials
- [x] B. Editor LowPolyMeshFactory: flat-shaded plane, icosahedron, N-segment cylinder/cone, hemisphere → Art/Meshes
- [x] C. Editor LayoutBuilder (`FF/Build World Blockout`) → World/Blockout (946 renderers): ground, roads, car park, zebra, fences, saw back yard, mines yard + closed gate, dream plot (arch, lamps, foundation, billboard blockout), sawmill 1, chair factory, lots, sawmill 2 lot, shop walls/door/plants, register stalls, materials shop (inactive), delivery bays, forest 5×7 (seeded jitter), localized 3D signs (LocalizedTmpText). State-dependent parts are built inactive.
- [x] D. CollisionResolver (push-out r=0.3, prototype tie order), PlayerRegionRules (Unity space), BlockerSet.Build + WorldStateSnapshot.NewGame, WorldCollision service
- [x] E. Input: FF_Input.inputactions (Move WASD/arrows/stick, Throw Q/buttonWest) = project-wide actions (default InputSystem_Actions deleted); MoveInputAggregator; VirtualJoystick (floating, full-screen area under the HUD); SafeAreaFitter; dev LocaleSwitchButton (top-right, hy/en/ru)
- [x] F. Player: CharacterRigBuilder → Prefabs/Characters/Player.prefab (makeChar, skin from SkinDef, all hat types), CharacterRig, CharacterAnimator (animChar), PlayerMover (updPlayer movement), spawn proto (-4, 0)
- [x] G. Camera: CinemachineBrain + CinemachineCamera (Follow world-space offset (0, 14.5, -13.5), RotationComposer look y 0.4, damping = 4.6 / lerp rate), GameCameraRig applies FOV 42 / clip / portrait ×1.45 from WorldLayout.camera
- [x] H. EditMode tests: CollisionResolver, PlayerRegionRules (20k-point fuzz vs a direct port of collide()), BlockerSet (= refreshBlocks() on a new game + late game), MoveInputMath — 451/451 green
- [x] I. Play Mode check: landscape frame ≈ screenshot 02, portrait (×1.45) ≈ screenshot 15; walking: blocked by chair factory (z 6.90), saw back yard reachable to its back fence, main fence and closed mines gate stop at 13.2, shop walls + door work, dream plot reachable; no Console errors
- [x] User play-test OK (2026-10-31) → PRs merged into `main`, pushed

Notes:
- Prototype wins over docs: unowned factory lots are walkable (blocker only after purchase).
- Region rule detail (prototype): deep behind the fence outside the yards x is clamped to the yard wall (not pushed back to the fence).
- Colours look a little darker than the prototype (three.js r128 output without sRGB encoding looks brighter) — tune in the M9 polish pass if needed.
- Automating input in Play Mode: Editor must tick unfocused (`editor.playmode set_run_in_background --enable true`, `editor set_auto_tick --enable true`); the real macOS keyboard ignores simulated keys, so add a virtual one first (`InputSystem.AddDevice<Keyboard>("FFTestKeyboard").MakeCurrent()`) and set Input settings background behaviour to IgnoreFocus; restore everything afterwards. Use `simulate_key --action down/up` (press = down+up at once).

### Install Unity CLI — 2026-10-29
- [x] Check project (Unity 6000.6.7f1, `com.unity.pipeline` 0.9.1-exp.1 already in manifest)
- [x] Install Unity CLI 1.0.0-beta.14 → `~/.unity/bin/unity`
- [x] Verify connection: `unity status` → `ready`, port 7800

Result: CLI works and can drive the open Mebel Editor.

### Set up session rules — 2026-10-29
- [x] Create CLAUDE.md (session-start rules, project facts)
- [x] Create PLAN.md (this file)

Result: every new session reads PLAN.md first and continues from it.
