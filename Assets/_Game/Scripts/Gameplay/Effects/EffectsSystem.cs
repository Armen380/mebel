using UnityEngine;

namespace FF.Gameplay.Effects
{
    /// <summary>
    /// Prototype <c>puff</c> (chimney smoke) and <c>burst</c> (28 confetti cubes) on two shared, pooled Unity particle
    /// systems built by the scene builder. Emitting reuses particles; nothing is instantiated.
    /// </summary>
    public sealed class EffectsSystem : MonoBehaviour
    {
        const int MaxSmoke = 160;
        const int ConfettiCount = 28;
        const float SmokeRise = 1.1f, SmokeDrift = 0.3f;
        const float ConfettiMinSpeed = 2f, ConfettiSpeedRange = 3f, ConfettiUp = 4f, ConfettiUpRange = 3f, ConfettiSpin = 10f;

        static readonly Color32[] ConfettiColors =
        {
            new Color32(0xf3, 0xb3, 0x3d, 0xff), new Color32(0x5c, 0xae, 0x4a, 0xff),
            new Color32(0xfb, 0xf1, 0xde, 0xff), new Color32(0xd9, 0x57, 0x3b, 0xff),
        };

        [SerializeField] ParticleSystem smoke;
        [SerializeField] ParticleSystem confetti;

        /// <summary>Editor tools only.</summary>
        public void Setup(ParticleSystem smokeSystem, ParticleSystem confettiSystem)
        {
            smoke = smokeSystem;
            confetti = confettiSystem;
        }

        public void Puff(Vector3 position)
        {
            if (smoke.particleCount > MaxSmoke) return;
            var p = new ParticleSystem.EmitParams
            {
                position = position,
                velocity = new Vector3((Random.value - 0.5f) * SmokeDrift, SmokeRise, (Random.value - 0.5f) * SmokeDrift),
                applyShapeToPosition = false,
            };
            smoke.Emit(p, 1);
        }

        public void Burst(Vector3 position)
        {
            for (int i = 0; i < ConfettiCount; i++)
            {
                float a = Random.value * Mathf.PI * 2f, speed = ConfettiMinSpeed + Random.value * ConfettiSpeedRange;
                float spin = Random.value * ConfettiSpin * Mathf.Rad2Deg;
                var p = new ParticleSystem.EmitParams
                {
                    position = position,
                    velocity = new Vector3(Mathf.Cos(a) * speed, ConfettiUp + Random.value * ConfettiUpRange, Mathf.Sin(a) * speed),
                    startColor = ConfettiColors[Random.Range(0, ConfettiColors.Length)],
                    angularVelocity3D = new Vector3(spin, spin, 0f),
                    applyShapeToPosition = false,
                };
                confetti.Emit(p, 1);
            }
        }
    }
}
