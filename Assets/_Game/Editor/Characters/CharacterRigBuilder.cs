using FF.Data;
using FF.Editor.World;
using FF.Gameplay.Characters;
using FF.Gameplay.Player;
using UnityEditor;
using UnityEngine;

namespace FF.Editor.Characters
{
    /// <summary>
    /// Builds the blocky character of the prototype's <c>makeChar()</c> from a SkinDef. Parts are placed in
    /// prototype-local axes (the face looks toward local +Z = Unity forward), so limb angles carry over unchanged.
    /// </summary>
    public static class CharacterRigBuilder
    {
        public const string PlayerPrefabPath = "Assets/_Game/Prefabs/Characters/Player.prefab";
        const int Shoe = 0x2b1d14, Belt = 0x3b2a1e, Eye = 0x1d140d;

        [MenuItem("FF/Build Player Prefab", priority = 21)]
        public static GameObject BuildPlayerPrefab()
        {
            var db = AssetDatabase.LoadAssetAtPath<GameDatabase>(DataImporter.DatabasePath);
            GameObject go = Build("Player", db.DefaultSkin);
            var animator = go.GetComponent<CharacterAnimator>();
            var mover = go.AddComponent<PlayerMover>();
            GameSceneBuilder.Wire(mover, "animator", animator);
            var carrier = go.AddComponent<PlayerCarrier>();
            var interactor = go.AddComponent<PlayerInteractor>();
            GameSceneBuilder.Wire(interactor, "mover", mover);
            GameSceneBuilder.Wire(interactor, "carrier", carrier);
            GameSceneBuilder.Wire(interactor, "animator", animator);
            GameSceneBuilder.Wire(interactor, "throwAction", GameSceneBuilder.ActionReference("Player/Throw"));
            DataImporter.EnsureFolder("Assets/_Game/Prefabs/Characters");
            GameObject prefab = PrefabUtility.SaveAsPrefabAsset(go, PlayerPrefabPath);
            Object.DestroyImmediate(go);
            Debug.Log($"[FF] Player prefab saved with skin '{db.DefaultSkin.id}'.");
            return prefab;
        }

        public static GameObject Build(string name, SkinDef skin)
        {
            var b = new Blockout(mirrorZ: false);
            var root = new GameObject(name);
            int shirt = Hex(skin.shirt), pants = Hex(skin.pants), hat = Hex(skin.hat), skinTone = Hex(skin.skin);

            Transform body = b.Group("Body", root.transform);
            Transform hipL = b.Group("HipL", body, -0.14f, 0, 0.52f);
            Transform hipR = b.Group("HipR", body, 0.14f, 0, 0.52f);
            foreach (Transform hip in new[] { hipL, hipR })
            {
                b.Box(hip, 0.22f, 0.52f, 0.24f, pants, 0, -0.26f, 0, "Leg");
                b.Box(hip, 0.24f, 0.08f, 0.3f, Shoe, 0, -0.5f, 0.03f, "Shoe");
            }

            b.Box(body, 0.62f, 0.62f, 0.38f, shirt, 0, 0.84f, 0, "Torso");
            b.Box(body, 0.64f, 0.08f, 0.4f, Belt, 0, 0.56f, 0, "Belt");
            b.Box(body, 0.46f, 0.44f, 0.44f, skinTone, 0, 1.37f, 0, "Head");
            b.Box(body, 0.07f, 0.09f, 0.02f, Eye, -0.1f, 1.4f, 0.225f, "Eye");
            b.Box(body, 0.07f, 0.09f, 0.02f, Eye, 0.1f, 1.4f, 0.225f, "Eye");
            BuildHat(b, body, skin.hatType, hat);

            Transform shL = b.Group("ShoulderL", body, -0.41f, 0, 1.08f);
            Transform shR = b.Group("ShoulderR", body, 0.41f, 0, 1.08f);
            foreach (Transform sh in new[] { shL, shR })
            {
                b.Box(sh, 0.2f, 0.5f, 0.22f, shirt, 0, -0.22f, 0, "Arm");
                b.Box(sh, 0.18f, 0.14f, 0.2f, skinTone, 0, -0.53f, 0, "Hand");
            }

            Transform axe = b.Group("Axe", shR, 0, 0.08f, -0.56f);
            axe.localRotation = Quaternion.Euler(90, 0, 0);
            b.Box(axe, 0.06f, 0.75f, 0.06f, 0x8b5a2b, 0, 0, 0, "Handle");
            b.Box(axe, 0.06f, 0.22f, 0.26f, 0xa5aeb8, 0, 0.3f, 0.11f, "Blade");
            axe.gameObject.SetActive(false);

            Transform anchor = b.Group("CarryAnchor", root.transform, 0, 0.56f, 0.92f);

            var rig = root.AddComponent<CharacterRig>();
            rig.body = body;
            rig.hipLeft = hipL;
            rig.hipRight = hipR;
            rig.shoulderLeft = shL;
            rig.shoulderRight = shR;
            rig.axe = axe.gameObject;
            rig.carryAnchor = anchor;
            root.AddComponent<CharacterAnimator>();
            return root;
        }

        static void BuildHat(Blockout b, Transform body, HatType type, int color)
        {
            switch (type)
            {
                case HatType.Beanie:
                    b.Box(body, 0.5f, 0.2f, 0.48f, color, 0, 1.66f, 0, "Hat");
                    b.Box(body, 0.16f, 0.1f, 0.16f, color, 0, 1.8f, 0, "HatPompom");
                    break;
                case HatType.Hard:
                    b.Hemisphere(body, 0.3f, color, 0, 1.58f, 0, "Hat");
                    b.Cyl(body, 0.36f, 0.36f, 0.04f, color, 12, 0, 1.58f, 0.02f, "HatBrim");
                    break;
                case HatType.Cap:
                    b.Box(body, 0.48f, 0.14f, 0.48f, color, 0, 1.65f, 0, "Hat");
                    b.Box(body, 0.42f, 0.04f, 0.24f, color, 0, 1.6f, 0.32f, "HatPeak");
                    break;
                case HatType.Crown:
                    b.Cyl(body, 0.27f, 0.25f, 0.2f, color, 6, 0, 1.68f, 0, "Hat");
                    for (int i = 0; i < 6; i++)
                    {
                        float a = i / 6f * 2 * Mathf.PI;
                        b.Box(body, 0.07f, 0.12f, 0.07f, color, Mathf.Sin(a) * 0.24f, 1.83f, Mathf.Cos(a) * 0.24f, "CrownTip");
                    }
                    break;
            }
        }

        static int Hex(Color c)
        {
            Color32 c32 = c;
            return (c32.r << 16) | (c32.g << 8) | c32.b;
        }
    }
}
