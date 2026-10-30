using FF.Core;
using FF.Data;
using FF.Editor.Characters;
using FF.Editor.World;
using FF.Gameplay.CameraRig;
using FF.Gameplay.Input;
using FF.Gameplay.Player;
using FF.UI.DevTools;
using FF.UI.Input;
using FF.UI.Layout;
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
    /// Milestone 1 scene assembly for Game.unity: environment (sky, fog, ambient, sun), world blockout,
    /// player, input, Cinemachine camera rig and the HUD joystick. Safe to run again: it rebuilds what it owns.
    /// </summary>
    public static class GameSceneBuilder
    {
        public const string InputAssetPath = "Assets/_Game/Input/FF_Input.inputactions";
        static readonly Color32 Sky = new Color32(0xbf, 0xe3, 0xf0, 0xff);

        [MenuItem("FF/Build Game Scene", priority = 10)]
        public static void Build()
        {
            EditorSceneManager.OpenScene(SceneSetup.GameScenePath);
            var db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);

            SetupEnvironment(db.world);
            LayoutBuilder.Build();
            Transform player = SpawnPlayer(db.world);
            MoveInputAggregator input = SetupInput();
            VirtualJoystick joystick = SetupHud();
            Wire(input, "joystickSource", joystick);
            Wire(player.GetComponent<PlayerMover>(), "input", input);
            SetupCamera(player, db.world);

            EditorSceneManager.MarkSceneDirty(EditorSceneManager.GetActiveScene());
            EditorSceneManager.SaveOpenScenes();
            AssetDatabase.SaveAssets();
            Debug.Log("[FF] Game scene built (M1: world, player, input, camera, HUD).");
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
        static InputActionReference ActionReference(string path)
        {
            foreach (Object o in AssetDatabase.LoadAllAssetsAtPath(InputAssetPath))
                if (o is InputActionReference r && r.action != null && $"{r.action.actionMap.name}/{r.action.name}" == path)
                    return r;
            throw new System.InvalidOperationException($"No InputActionReference for {path} in {InputAssetPath}");
        }

        // ---------- HUD ----------

        static VirtualJoystick SetupHud()
        {
            Transform ui = Root("UI");
            Transform hud = ui.Find("HUD");
            for (int i = hud.childCount - 1; i >= 0; i--) Object.DestroyImmediate(hud.GetChild(i).gameObject);

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

            BuildLocaleButton(safe);
            return joystick;
        }

        static void BuildLocaleButton(Transform parent)
        {
            RectTransform button = Rect("DevLocaleButton", parent);
            button.anchorMin = button.anchorMax = button.pivot = new Vector2(1, 1);
            button.anchoredPosition = new Vector2(-32, -32);
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

        static RectTransform Rect(string name, Transform parent)
        {
            var go = new GameObject(name, typeof(RectTransform));
            go.transform.SetParent(parent, false);
            return (RectTransform)go.transform;
        }

        static void Stretch(RectTransform r)
        {
            r.anchorMin = Vector2.zero;
            r.anchorMax = Vector2.one;
            r.offsetMin = Vector2.zero;
            r.offsetMax = Vector2.zero;
        }

        static void Wire(Object target, string field, Object value)
        {
            var so = new SerializedObject(target);
            SerializedProperty p = so.FindProperty(field) ?? throw new System.ArgumentException($"{target.GetType().Name}.{field} not found");
            p.objectReferenceValue = value;
            so.ApplyModifiedPropertiesWithoutUndo();
        }
    }
}
