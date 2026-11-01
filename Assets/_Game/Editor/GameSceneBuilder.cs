using FF.Core;
using FF.Data;
using System.Collections.Generic;
using FF.Editor.Art;
using FF.Editor.Characters;
using FF.Editor.Items;
using FF.Editor.World;
using FF.Gameplay.Bootstrap;
using FF.Gameplay.CameraRig;
using FF.Gameplay.Effects;
using FF.Gameplay.Production;
using FF.Gameplay.Input;
using FF.Gameplay.Items;
using FF.Gameplay.Nodes;
using FF.Gameplay.Pads;
using FF.Gameplay.Player;
using FF.Gameplay.Shop;
using FF.Gameplay.Tutorial;
using FF.Gameplay.Zones;
using FF.UI.DevTools;
using FF.UI.HUD;
using FF.UI.Input;
using FF.UI.Layout;
using FF.UI.Localization;
using FF.UI.WorldTags;
using TMPro;
using Unity.Cinemachine;
using Unity.Cinemachine.TargetTracking;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.Rendering;
using UnityEngine.Rendering.Universal;
using UnityEngine.UI;

namespace FF.Editor
{
    /// <summary>
    /// Scene assembly for Game.unity: environment (sky, fog, ambient, sun), item prefabs, world blockout,
    /// production (machines + zones), player, systems, input, Cinemachine camera rig and the HUD.
    /// Safe to run again: it rebuilds what it owns.
    /// </summary>
    public static class GameSceneBuilder
    {
        public const string InputAssetPath = "Assets/_Game/Input/FF_Input.inputactions";
        static readonly Color32 Sky = new Color32(0xbf, 0xe3, 0xf0, 0xff);
        static readonly Color32 Walnut = new Color32(0x2b, 0x1d, 0x14, 0xff);
        static readonly Color32 Cream = new Color32(0xfb, 0xf1, 0xde, 0xff);
        /// <summary>CSS px of the prototype (390 px wide phone) → HUD canvas units (1080 reference width).</summary>
        internal const float Px = 1080f / 390f;

        [MenuItem("FF/Build Game Scene", priority = 10)]
        public static void Build()
        {
            EditorSceneManager.OpenScene(SceneSetup.GameScenePath);
            var db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

            SetupEnvironment(db.world);
            ItemPrefabBuilder.Build(false);
            LayoutBuilder.Build();
            List<Zone> zones = ProductionBuilder.Build(db);
            ShopBuilder.Result shop = ShopBuilder.Build(db);
            zones.AddRange(shop.Zones);
            BuildingKit kit = BuildingKitBuilder.Build(db); // after the blockout: ghosts for every palette colour
            Transform player = SpawnPlayer(db.world);
            foreach (BuildingFader fader in Root("World").GetComponentsInChildren<BuildingFader>(true)) fader.Setup(player);
            SetupSystems(zones, shop, player, kit);
            MoveInputAggregator input = SetupInput();
            VirtualJoystick joystick = SetupHud(db);
            Wire(input, "joystickSource", joystick);
            Wire(player.GetComponent<PlayerMover>(), "input", input);
            SetupCamera(player, db.world);

            EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
            EditorSceneManager.SaveOpenScenes();
            AssetDatabase.SaveAssets();
            Debug.Log("[FF] Game scene built (world, production, player, systems, input, camera, HUD).");
        }

        // ---------- environment ----------

        static void SetupEnvironment(WorldLayout w)
        {
            RenderSettings.skybox = null;
            RenderSettings.fog = true;
            RenderSettings.fogMode = FogMode.Linear;
            RenderSettings.fogColor = Sky;
            RenderSettings.fogStartDistance = 42f;
            RenderSettings.fogEndDistance = 95f;
            // prototype HemisphereLight(sky #ffffff, ground #7a9a55, 0.72)
            RenderSettings.ambientMode = AmbientMode.Trilight;
            RenderSettings.ambientSkyColor = new Color(0.72f, 0.72f, 0.72f);
            RenderSettings.ambientEquatorColor = Color.Lerp(new Color(0.72f, 0.72f, 0.72f), (Color)new Color32(0x7a, 0x9a, 0x55, 0xff) * 0.72f, 0.5f);
            RenderSettings.ambientGroundColor = (Color)new Color32(0x7a, 0x9a, 0x55, 0xff) * 0.72f;

            Transform worldRoot = Root("World");
            Transform old = worldRoot.Find("Sun");
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var sunGo = new GameObject("Sun");
            sunGo.transform.SetParent(worldRoot, false);
            var sun = sunGo.AddComponent<Light>();
            sun.type = LightType.Directional;
            sun.color = new Color32(0xff, 0xf1, 0xd6, 0xff);
            sun.intensity = 1.1f;
            sun.shadows = LightShadows.Soft;
            sun.shadowBias = 0.05f;
            // prototype sun sits at player + (14, 26, 12) proto and points at the player
            Vector3 fromPlayer = ProtoCoords.ToUnity(14f, 26f, 12f);
            sunGo.transform.rotation = Quaternion.LookRotation(-fromPlayer.normalized, Vector3.up);
            RenderSettings.sun = sun;
        }

        // ---------- systems ----------

        static void SetupSystems(List<Zone> zones, ShopBuilder.Result shop, Transform player, BuildingKit kit)
        {
            Transform systems = Root("Systems");
            foreach (string name in new[] { "Items", "Zones", "Nodes", "Customers", "Pads", "Tutorial" })
            {
                Transform old = systems.Find(name);
                if (old != null) Object.DestroyImmediate(old.gameObject);
            }

            var items = new GameObject("Items");
            items.transform.SetParent(systems, false);
            var pool = items.AddComponent<ItemPool>();
            var flights = items.AddComponent<ItemFlights>();

            var zoneGo = new GameObject("Zones");
            zoneGo.transform.SetParent(systems, false);
            var zoneRegistry = zoneGo.AddComponent<ZoneRegistry>();
            zoneRegistry.SetZones(zones);

            var nodeGo = new GameObject("Nodes");
            nodeGo.transform.SetParent(systems, false);
            var nodeRegistry = nodeGo.AddComponent<NodeRegistry>();
            nodeRegistry.SetNodes(new List<ResourceNode>(Root("World").GetComponentsInChildren<ResourceNode>(true)));

            var customers = new GameObject("Customers");
            customers.transform.SetParent(systems, false);
            var director = customers.AddComponent<CustomerDirector>();
            director.Setup(ShopBuilder.BuildCustomerVariants(false), shop.Shelves, shop.Registers, player);

            var padGo = new GameObject("Pads");
            padGo.transform.SetParent(systems, false);
            var padSystem = padGo.AddComponent<PadSystem>();
            padSystem.Setup(shop.Pads, player.GetComponent<PlayerMover>());
            padGo.AddComponent<PadRewards>();
            EffectsSystem effects = EffectsBuilder.Build(systems, kit);

            var tutorialGo = new GameObject("Tutorial");
            tutorialGo.transform.SetParent(systems, false);
            var tutorial = tutorialGo.AddComponent<TutorialService>();
            tutorial.Setup(player);
            ShopBuilder.BuildTutorialArrow(Root("World"), tutorial);

            var installer = systems.GetComponentInChildren<GameInstaller>(true);
            Wire(installer, "itemPool", pool);
            Wire(installer, "itemFlights", flights);
            Wire(installer, "zones", zoneRegistry);
            Wire(installer, "nodes", nodeRegistry);
            Wire(installer, "pads", padSystem);
            Wire(installer, "effects", effects);
            foreach (Object o in new Object[] { zoneRegistry, nodeRegistry, director, padSystem, tutorial }) EditorUtility.SetDirty(o);
        }

        // ---------- player & input ----------

        static Transform SpawnPlayer(WorldLayout w)
        {
            Transform actors = Root("Actors");
            Transform old = actors.Find("Player");
            if (old != null) Object.DestroyImmediate(old.gameObject);

            GameObject prefab = CharacterRigBuilder.BuildPlayerPrefab();
            var player = (GameObject)PrefabUtility.InstantiatePrefab(prefab, actors);
            player.name = "Player";
            player.transform.position = ProtoCoords.ToUnity(w.playerBounds.playerSpawn);
            player.transform.rotation = Quaternion.Euler(0, 180, 0); // faces the camera like the prototype at start
            return player.transform;
        }

        static MoveInputAggregator SetupInput()
        {
            var actions = AssetDatabase.LoadAssetAtPath<InputActionAsset>(InputAssetPath);
            InputSystem.actions = actions; // project-wide actions = ours

            Transform systems = Root("Systems");
            Transform old = systems.Find("Input");
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var go = new GameObject("Input");
            go.transform.SetParent(systems, false);
            var aggregator = go.AddComponent<MoveInputAggregator>();
            Wire(aggregator, "moveAction", ActionReference("Player/Move"));
            return aggregator;
        }

        /// <summary>The persistent InputActionReference sub-asset that the importer generates for an action.</summary>
        internal static InputActionReference ActionReference(string path)
        {
            foreach (Object o in AssetDatabase.LoadAllAssetsAtPath(InputAssetPath))
                if (o is InputActionReference r && r.action != null && $"{r.action.actionMap.name}/{r.action.name}" == path)
                    return r;
            throw new System.InvalidOperationException($"No InputActionReference for {path} in {InputAssetPath}");
        }

        // ---------- HUD ----------

        static VirtualJoystick SetupHud(GameDatabase db)
        {
            Transform ui = Root("UI");
            Transform hud = ui.Find("HUD");
            for (int i = hud.childCount - 1; i >= 0; i--) Object.DestroyImmediate(hud.GetChild(i).gameObject);

            BuildWorldTags(hud, db);
            BuildFloatingTexts(hud);

            RectTransform safe = Rect("SafeArea", hud);
            Stretch(safe);
            safe.gameObject.AddComponent<SafeAreaFitter>();

            // joystick area first so every other HUD element is above it and gets touches first
            RectTransform area = Rect("JoystickArea", safe);
            Stretch(area);
            area.gameObject.AddComponent<Image>().color = new Color(0, 0, 0, 0);
            Sprite knobSprite = AssetDatabase.GetBuiltinExtraResource<Sprite>("UI/Skin/Knob.psd");

            RectTransform stickBase = Rect("Base", area);
            stickBase.anchorMin = stickBase.anchorMax = new Vector2(0.5f, 0.5f);
            stickBase.sizeDelta = new Vector2(330, 330);
            Image ring = stickBase.gameObject.AddComponent<Image>();
            ring.sprite = knobSprite;
            ring.color = new Color(1, 1, 1, 0.55f);
            ring.raycastTarget = false;
            RectTransform fill = Rect("Fill", stickBase);
            fill.anchorMin = fill.anchorMax = new Vector2(0.5f, 0.5f);
            fill.sizeDelta = new Vector2(312, 312);
            Image fillImage = fill.gameObject.AddComponent<Image>();
            fillImage.sprite = knobSprite;
            fillImage.color = new Color32(0x2b, 0x1d, 0x14, 0x60);
            fillImage.raycastTarget = false;
            RectTransform knob = Rect("Knob", stickBase);
            knob.anchorMin = knob.anchorMax = new Vector2(0.5f, 0.5f);
            knob.sizeDelta = new Vector2(140, 140);
            Image knobImage = knob.gameObject.AddComponent<Image>();
            knobImage.sprite = knobSprite;
            knobImage.color = new Color32(0xfb, 0xf1, 0xde, 0xff);
            knobImage.raycastTarget = false;

            var joystick = area.gameObject.AddComponent<VirtualJoystick>();
            Wire(joystick, "stickBase", stickBase);
            Wire(joystick, "knob", knob);

            HudBuilder.BuildTopLeft(safe);
            HudBuilder.BuildQuestBar(safe);
            HudBuilder.BuildToast(safe);
            BuildThrowButton(safe);
            RectTransform upgradesButton = HudBuilder.BuildUpgradesButton(safe, out GameObject badge);
            BuildLocaleButton(safe);
            HudBuilder.BuildUpgradesPanel(hud, db, upgradesButton.GetComponent<Button>(), badge, joystick);
            return joystick;
        }

        /// <summary>Full-screen layer for floating world texts ("+$430", "Faster!"); ignores touches.</summary>
        static void BuildFloatingTexts(Transform hud)
        {
            RectTransform layer = Rect("FloatingTexts", hud);
            Stretch(layer);
            RectTransform t = Rect("Template", layer);
            t.anchorMin = t.anchorMax = Vector2.zero;
            t.pivot = new Vector2(0.5f, 0f);
            t.sizeDelta = new Vector2(400, 80);
            var label = t.gameObject.AddComponent<TextMeshProUGUI>();
            label.font = HudBuilder.Font("Black");
            label.fontSize = 20 * Px;
            label.color = HudBuilder.Honey;
            label.alignment = TextAlignmentOptions.Bottom;
            label.textWrappingMode = TextWrappingModes.NoWrap;
            label.raycastTarget = false;
            label.outlineColor = Walnut;
            label.outlineWidth = 0.2f;
            Wire(layer.gameObject.AddComponent<FloatingTextLayer>(), "template", label);
        }

        /// <summary>Full-screen layer under everything else: world tags follow world positions, ignore touches.</summary>
        static void BuildWorldTags(Transform hud, GameDatabase db)
        {
            RectTransform layer = Rect("WorldTags", hud);
            Stretch(layer);

            RectTransform pill = Rect("PillTemplate", layer);
            pill.anchorMin = pill.anchorMax = Vector2.zero; // positions are set from the bottom-left corner
            pill.pivot = new Vector2(0.5f, 0f);
            Image bg = pill.gameObject.AddComponent<Image>();
            bg.sprite = TextureFactory.Pill();
            bg.type = Image.Type.Sliced;
            bg.raycastTarget = false;
            var group = pill.gameObject.AddComponent<HorizontalLayoutGroup>();
            group.padding = new RectOffset(Mathf.RoundToInt(10 * Px), Mathf.RoundToInt(10 * Px), Mathf.RoundToInt(3 * Px), Mathf.RoundToInt(3 * Px));
            group.childControlWidth = group.childControlHeight = true;
            group.childForceExpandWidth = group.childForceExpandHeight = false;
            var fitter = pill.gameObject.AddComponent<ContentSizeFitter>();
            fitter.horizontalFit = fitter.verticalFit = ContentSizeFitter.FitMode.PreferredSize;

            RectTransform labelRect = Rect("Label", pill);
            var label = labelRect.gameObject.AddComponent<TextMeshProUGUI>();
            label.text = "0/0";
            label.fontSize = 13 * Px;
            label.textWrappingMode = TextWrappingModes.NoWrap;
            label.alignment = TextAlignmentOptions.Center;
            label.raycastTarget = false;

            RectTransform iconRect = Rect("Icon", pill);
            Image icon = iconRect.gameObject.AddComponent<Image>();
            icon.raycastTarget = false;
            icon.preserveAspect = true;
            var iconSize = iconRect.gameObject.AddComponent<LayoutElement>();
            iconSize.preferredWidth = iconSize.preferredHeight = 24 * Px;
            iconRect.gameObject.SetActive(false);

            var tags = layer.gameObject.AddComponent<WorldTagLayer>();
            Wire(tags, "pillTemplate", pill);
            tags.SetIcons(HudBuilder.BubbleIcons(db));
        }

        /// <summary>Prototype <c>.throw</c>: 72 px walnut circle bottom-right with a trash icon and "Throw".</summary>
        static void BuildThrowButton(Transform safe)
        {
            RectTransform root = Rect("ThrowButton", safe);
            root.anchorMin = root.anchorMax = root.pivot = new Vector2(1, 0);
            root.anchoredPosition = new Vector2(-16 * Px, 22 * Px);
            root.sizeDelta = new Vector2(72 * Px, 72 * Px);

            RectTransform content = Rect("Content", root);
            Stretch(content);
            Sprite circle = TextureFactory.Circle();

            RectTransform shadow = Rect("Shadow", content);
            Stretch(shadow);
            shadow.anchoredPosition = new Vector2(0, -4 * Px);
            Image shadowImage = shadow.gameObject.AddComponent<Image>();
            shadowImage.sprite = circle;
            shadowImage.color = new Color(0, 0, 0, 0.3f);
            shadowImage.raycastTarget = false;

            RectTransform face = Rect("Face", content);
            Stretch(face);
            Image faceImage = face.gameObject.AddComponent<Image>();
            faceImage.sprite = circle;
            faceImage.color = Walnut;
            var button = face.gameObject.AddComponent<Button>();
            button.targetGraphic = faceImage;

            RectTransform icon = Rect("Icon", face);
            icon.anchorMin = icon.anchorMax = new Vector2(0.5f, 0.5f);
            icon.sizeDelta = new Vector2(26 * Px, 26 * Px);
            icon.anchoredPosition = new Vector2(0, 6.5f * Px);
            Image iconImage = icon.gameObject.AddComponent<Image>();
            iconImage.sprite = TextureFactory.TrashIcon();
            iconImage.color = Cream;
            iconImage.raycastTarget = false;

            RectTransform labelRect = Rect("Label", face);
            labelRect.anchorMin = labelRect.anchorMax = new Vector2(0.5f, 0.5f);
            labelRect.sizeDelta = new Vector2(68 * Px, 14 * Px);
            labelRect.anchoredPosition = new Vector2(0, -15 * Px);
            var label = labelRect.gameObject.AddComponent<TextMeshProUGUI>();
            label.text = "Նետել";
            label.fontSize = 11 * Px;
            label.enableAutoSizing = true;
            label.fontSizeMin = 6 * Px;
            label.fontSizeMax = 11 * Px;
            label.alignment = TextAlignmentOptions.Center;
            label.color = Cream;
            label.raycastTarget = false;
            labelRect.gameObject.AddComponent<LocalizedTmpText>().SetKey("ui.throw");

            var throwButton = root.gameObject.AddComponent<ThrowButton>();
            Wire(throwButton, "button", button);
            Wire(throwButton, "content", content.gameObject);
        }

        static void BuildLocaleButton(Transform parent)
        {
            RectTransform button = Rect("DevLocaleButton", parent);
            button.anchorMin = button.anchorMax = button.pivot = new Vector2(1, 1);
            // dev button: under the Upgrades button until the real menu (M9)
            button.anchoredPosition = new Vector2(-16 * Px, -(12 + 44 + 10) * Px);
            button.sizeDelta = new Vector2(150, 96);
            Image bg = button.gameObject.AddComponent<Image>();
            bg.sprite = AssetDatabase.GetBuiltinExtraResource<Sprite>("UI/Skin/UISprite.psd");
            bg.type = Image.Type.Sliced;
            bg.color = new Color32(0x2b, 0x1d, 0x14, 0xe0);
            button.gameObject.AddComponent<Button>();

            RectTransform labelRect = Rect("Label", button);
            Stretch(labelRect);
            var label = labelRect.gameObject.AddComponent<TextMeshProUGUI>();
            label.text = "HY";
            label.fontSize = 44;
            label.alignment = TextAlignmentOptions.Center;
            label.color = new Color32(0xfb, 0xf1, 0xde, 0xff);
            label.raycastTarget = false;

            var sw = button.gameObject.AddComponent<LocaleSwitchButton>();
            Wire(sw, "label", label);
        }

        // ---------- camera ----------

        static void SetupCamera(Transform player, WorldLayout w)
        {
            Transform rig = Root("CameraRig");
            for (int i = rig.childCount - 1; i >= 0; i--) Object.DestroyImmediate(rig.GetChild(i).gameObject);

            var camGo = new GameObject("Main Camera") { tag = "MainCamera" };
            camGo.transform.SetParent(rig, false);
            var cam = camGo.AddComponent<Camera>();
            cam.clearFlags = CameraClearFlags.SolidColor;
            cam.backgroundColor = Sky;
            cam.fieldOfView = w.camera.fieldOfView;
            cam.nearClipPlane = w.camera.nearClip;
            cam.farClipPlane = w.camera.farClip;
            camGo.AddComponent<AudioListener>();
            camGo.AddComponent<UniversalAdditionalCameraData>();
            camGo.AddComponent<CinemachineBrain>();

            var vcamGo = new GameObject("PlayCamera");
            vcamGo.transform.SetParent(rig, false);
            var vcam = vcamGo.AddComponent<CinemachineCamera>();
            vcam.Follow = player;
            vcam.LookAt = player;
            var follow = vcamGo.AddComponent<CinemachineFollow>();
            follow.TrackerSettings.BindingMode = BindingMode.WorldSpace;
            Vector3 o = w.camera.playOffset;
            follow.FollowOffset = ProtoCoords.ToUnity(o.x, o.y, o.z);
            var composer = vcamGo.AddComponent<CinemachineRotationComposer>();
            composer.Composition.DeadZone.Enabled = false;
            composer.TargetOffset = new Vector3(0, w.camera.lookAtHeight, 0);

            vcamGo.transform.position = player.position + follow.FollowOffset;
            vcamGo.transform.LookAt(player.position + composer.TargetOffset);
            camGo.transform.SetPositionAndRotation(vcamGo.transform.position, vcamGo.transform.rotation);

            var cameraRig = vcamGo.AddComponent<GameCameraRig>();
            Wire(cameraRig, "playCamera", vcam);
            Wire(cameraRig, "follow", follow);
            Wire(cameraRig, "composer", composer);
        }

        // ---------- helpers ----------

        static Transform Root(string name) => (GameObject.Find(name) ?? new GameObject(name)).transform;

        internal static RectTransform Rect(string name, Transform parent)
        {
            var go = new GameObject(name, typeof(RectTransform));
            go.transform.SetParent(parent, false);
            return (RectTransform)go.transform;
        }

        internal static void Stretch(RectTransform r)
        {
            r.anchorMin = Vector2.zero;
            r.anchorMax = Vector2.one;
            r.offsetMin = Vector2.zero;
            r.offsetMax = Vector2.zero;
        }

        internal static void Wire(Object target, string field, Object value)
        {
            var so = new SerializedObject(target);
            SerializedProperty p = so.FindProperty(field) ?? throw new System.ArgumentException($"{target.GetType().Name}.{field} not found");
            p.objectReferenceValue = value;
            so.ApplyModifiedPropertiesWithoutUndo();
        }
    }
}
