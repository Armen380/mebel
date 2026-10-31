using FF.Data;
using FF.Gameplay.Bootstrap;
using FF.UI.DevTools;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem.UI;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

namespace FF.Editor
{
    /// <summary>Creates Boot.unity and Game.unity with the root hierarchy from 03_UNITY_ARCHITECTURE and registers them in Build Settings.</summary>
    public static class SceneSetup
    {
        public const string ScenesDir = "Assets/_Game/Scenes";
        public const string BootScenePath = ScenesDir + "/Boot.unity";
        public const string GameScenePath = ScenesDir + "/Game.unity";

        public static readonly string[] GameRoots = { "Systems", "CameraRig", "World", "Actors", "UI" };

        [MenuItem("FF/Setup Scenes", priority = 3)]
        public static void Setup()
        {
            DataImporter.EnsureFolder(ScenesDir);
            CreateBootScene();
            CreateGameScene();
            EditorBuildSettings.scenes = new[]
            {
                new EditorBuildSettingsScene(BootScenePath, true),
                new EditorBuildSettingsScene(GameScenePath, true),
            };
            EditorSceneManager.OpenScene(GameScenePath);
            Debug.Log("[FF] Scenes ready: Boot (index 0) → Game (index 1).");
        }

        static void CreateBootScene()
        {
            Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
            new GameObject("BootLoader").AddComponent<BootLoader>();
            var cam = new GameObject("BootCamera").AddComponent<Camera>();
            cam.clearFlags = CameraClearFlags.SolidColor;
            cam.backgroundColor = new Color32(0xbf, 0xe3, 0xf0, 0xff);
            EditorSceneManager.SaveScene(scene, BootScenePath);
        }

        static void CreateGameScene()
        {
            Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
            foreach (string root in GameRoots) new GameObject(root);

            var installer = new GameObject("GameInstaller").AddComponent<GameInstaller>();
            installer.transform.SetParent(Find("Systems"), false);
            var so = new SerializedObject(installer);
            so.FindProperty("database").objectReferenceValue = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            so.ApplyModifiedPropertiesWithoutUndo();

            var camGo = new GameObject("Main Camera") { tag = "MainCamera" };
            camGo.transform.SetParent(Find("CameraRig"), false);
            camGo.AddComponent<Camera>();
            camGo.AddComponent<AudioListener>();

            CreateUi();
            EditorSceneManager.SaveScene(scene, GameScenePath);
        }

        static void CreateUi()
        {
            Transform ui = Find("UI");
            var canvasGo = new GameObject("HUD", typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
            canvasGo.transform.SetParent(ui, false);
            canvasGo.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;
            var scaler = canvasGo.GetComponent<CanvasScaler>();
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1080, 1920);
            scaler.matchWidthOrHeight = 0.5f;

            var es = new GameObject("EventSystem", typeof(EventSystem), typeof(InputSystemUIInputModule));
            es.transform.SetParent(ui, false);

            var textGo = new GameObject("M0Check", typeof(RectTransform), typeof(TextMeshProUGUI), typeof(M0Check));
            textGo.transform.SetParent(canvasGo.transform, false);
            var rt = (RectTransform)textGo.transform;
            rt.anchorMin = new Vector2(0, 0.4f);
            rt.anchorMax = new Vector2(1, 0.6f);
            rt.offsetMin = new Vector2(40, 0);
            rt.offsetMax = new Vector2(-40, 0);
            var tmp = textGo.GetComponent<TextMeshProUGUI>();
            tmp.alignment = TextAlignmentOptions.Center;
            tmp.fontSize = 64;
            tmp.color = new Color32(0x2b, 0x1d, 0x14, 0xff);
            tmp.text = "Կահույքի Գործարան / Мебельная фабрика";
            var check = new SerializedObject(textGo.GetComponent<M0Check>());
            check.FindProperty("label").objectReferenceValue = tmp;
            check.ApplyModifiedPropertiesWithoutUndo();
        }

        static Transform Find(string root) => GameObject.Find(root).transform;
    }
}
