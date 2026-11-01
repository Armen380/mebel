using FF.Data;
using FF.Editor.Art;
using FF.Gameplay.Effects;
using UnityEditor;
using UnityEngine;
using UnityEngine.Rendering;

namespace FF.Editor
{
    /// <summary>
    /// Systems/Effects: the shared chimney-smoke and confetti particle systems of the prototype (<c>puff</c>: grey
    /// icosahedra rising 1.1 m/s, growing 1 + 1.4·t, fading over 2 s; <c>burst</c>: 0.14 m cubes, gravity 12 m/s²,
    /// resting on the ground, 1.4 s). Both only emit through <see cref="EffectsSystem"/>.
    /// </summary>
    public static class EffectsBuilder
    {
        const string ParticleShader = "Universal Render Pipeline/Particles/Simple Lit";

        public static EffectsSystem Build(Transform systems, BuildingKit kit)
        {
            Transform old = systems.Find("Effects");
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var root = new GameObject("Effects");
            root.transform.SetParent(systems, false);

            ParticleSystem smoke = Smoke(root.transform, kit);
            ParticleSystem confetti = Confetti(root.transform, kit);
            var effects = root.AddComponent<EffectsSystem>();
            effects.Setup(smoke, confetti);
            return effects;
        }

        static ParticleSystem Smoke(Transform parent, BuildingKit kit)
        {
            ParticleSystem ps = NewSystem(parent, "Smoke", 170);
            ParticleSystem.MainModule main = ps.main;
            main.startLifetime = 2f;
            main.startSize = 0.2f;
            main.startColor = Color.white;

            ParticleSystem.SizeOverLifetimeModule size = ps.sizeOverLifetime;
            size.enabled = true;
            size.size = new ParticleSystem.MinMaxCurve(1f, AnimationCurve.Linear(0f, 1f, 1f, 3.8f)); // 1 + 1.4·t over 2 s

            ParticleSystem.ColorOverLifetimeModule color = ps.colorOverLifetime;
            color.enabled = true;
            var gradient = new Gradient();
            Color puff = new Color32(0xf3, 0xef, 0xe8, 0xff);
            gradient.SetKeys(new[] { new GradientColorKey(puff, 0f), new GradientColorKey(puff, 1f) },
                new[] { new GradientAlphaKey(0.8f, 0f), new GradientAlphaKey(0f, 1f) });
            color.color = gradient;

            Render(ps, kit.icosahedron, ParticleMaterial("Smoke", true));
            return ps;
        }

        static ParticleSystem Confetti(Transform parent, BuildingKit kit)
        {
            ParticleSystem ps = NewSystem(parent, "Confetti", 140);
            ParticleSystem.MainModule main = ps.main;
            main.startLifetime = 1.4f;
            main.startSize = 0.14f;
            main.gravityModifier = 12f / 9.81f;
            main.startRotation3D = true;
            main.startRotationX = new ParticleSystem.MinMaxCurve(0f, Mathf.PI * 2f);
            main.startRotationY = new ParticleSystem.MinMaxCurve(0f, Mathf.PI * 2f);
            main.startRotationZ = new ParticleSystem.MinMaxCurve(0f, Mathf.PI * 2f);

            // the cubes stop on the ground (prototype: y clamped to 0.05, velocity zeroed)
            var floor = new GameObject("Floor").transform;
            floor.SetParent(ps.transform, false);
            floor.position = new Vector3(0f, 0.05f, 0f);
            ParticleSystem.CollisionModule collision = ps.collision;
            collision.enabled = true;
            collision.type = ParticleSystemCollisionType.Planes;
            collision.SetPlane(0, floor);
            collision.dampen = 1f;
            collision.bounce = 0f;
            collision.lifetimeLoss = 0f;

            Render(ps, kit.cube, ParticleMaterial("Confetti", false));
            return ps;
        }

        static ParticleSystem NewSystem(Transform parent, string name, int maxParticles)
        {
            var go = new GameObject(name);
            go.transform.SetParent(parent, false);
            var ps = go.AddComponent<ParticleSystem>();
            ps.Stop(true, ParticleSystemStopBehavior.StopEmittingAndClear);
            ParticleSystem.MainModule main = ps.main;
            main.loop = true;
            main.playOnAwake = true;
            main.startSpeed = 0f;
            main.maxParticles = maxParticles;
            main.simulationSpace = ParticleSystemSimulationSpace.World;
            ParticleSystem.EmissionModule emission = ps.emission;
            emission.rateOverTime = 0f; // emitted from code only
            ParticleSystem.ShapeModule shape = ps.shape;
            shape.enabled = false;
            return ps;
        }

        static void Render(ParticleSystem ps, Mesh mesh, Material material)
        {
            var r = ps.GetComponent<ParticleSystemRenderer>();
            r.renderMode = ParticleSystemRenderMode.Mesh;
            r.mesh = mesh;
            r.sharedMaterial = material;
            r.shadowCastingMode = ShadowCastingMode.Off;
            r.receiveShadows = false;
            r.alignment = ParticleSystemRenderSpace.World;
        }

        static Material ParticleMaterial(string name, bool transparent)
        {
            string path = $"{MaterialPaletteEditor.Folder}/Particles_{name}.mat";
            var m = AssetDatabase.LoadAssetAtPath<Material>(path);
            if (m != null) return m;
            m = new Material(Shader.Find(ParticleShader)) { enableInstancing = true };
            m.SetColor("_BaseColor", Color.white);
            if (transparent)
            {
                m.SetFloat("_Surface", 1);
                m.SetFloat("_Blend", 0);
                m.SetFloat("_SrcBlend", (float)BlendMode.SrcAlpha);
                m.SetFloat("_DstBlend", (float)BlendMode.OneMinusSrcAlpha);
                m.SetFloat("_ZWrite", 0);
                m.SetOverrideTag("RenderType", "Transparent");
                m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
                m.renderQueue = (int)RenderQueue.Transparent;
            }
            AssetDatabase.CreateAsset(m, path);
            return m;
        }
    }
}
