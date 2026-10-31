using System.Collections.Generic;
using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;

namespace FF.UI.HUD
{
    /// <summary>
    /// Prototype <c>floatText / updFloats</c>: honey text that rises 1.4 m/s from a world point and fades as 1 − t²
    /// over 1 s. Pooled; runs after the camera brain.
    /// </summary>
    [DefaultExecutionOrder(10000)]
    public sealed class FloatingTextLayer : MonoBehaviour
    {
        [SerializeField] TMP_Text template;

        struct Entry
        {
            public TMP_Text Text;
            public Vector3 World;
            public float Time;
        }

        readonly List<Entry> _active = new List<Entry>(16);
        readonly Stack<TMP_Text> _free = new Stack<TMP_Text>();
        RectTransform _rect;
        Camera _camera;
        float _rise, _lifetime;

        void Awake()
        {
            _rect = (RectTransform)transform;
            template.gameObject.SetActive(false);
        }

        void Start()
        {
            _camera = Camera.main;
            EconomyConfig economy = Services.Get<GameDatabase>().economy;
            _rise = economy.floatTextRise;
            _lifetime = economy.floatTextSeconds;
        }

        void OnEnable() => GameEvents.FloatText += Spawn;

        void OnDisable() => GameEvents.FloatText -= Spawn;

        void Spawn(Vector3 world, string text)
        {
            TMP_Text t = _free.Count > 0 ? _free.Pop() : Instantiate(template, transform);
            t.SetText(text);
            t.alpha = 1f;
            t.gameObject.SetActive(true);
            _active.Add(new Entry { Text = t, World = world });
        }

        void LateUpdate()
        {
            if (_camera == null) return;
            Rect r = _rect.rect;
            float dt = Time.deltaTime;
            for (int i = _active.Count - 1; i >= 0; i--)
            {
                Entry e = _active[i];
                e.Time += dt;
                if (e.Time > _lifetime)
                {
                    e.Text.gameObject.SetActive(false);
                    _free.Push(e.Text);
                    _active.RemoveAt(i);
                    continue;
                }
                Vector3 world = e.World;
                world.y += e.Time * _rise;
                Vector3 v = _camera.WorldToViewportPoint(world);
                var rt = (RectTransform)e.Text.transform;
                rt.anchoredPosition = new Vector2(v.x * r.width, v.y * r.height);
                e.Text.alpha = Mathf.Max(0f, 1f - e.Time * e.Time);
                _active[i] = e;
            }
        }
    }
}
