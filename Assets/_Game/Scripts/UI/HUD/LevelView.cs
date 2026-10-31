using FF.Core;
using TMPro;
using UnityEngine;

namespace FF.UI.HUD
{
    /// <summary>Level pill + XP bar (prototype <c>hudLevel</c>).</summary>
    public sealed class LevelView : MonoBehaviour
    {
        [SerializeField] TMP_Text level;
        [Tooltip("Fill of the XP bar; its anchorMax.x is set to xp / needed.")]
        [SerializeField] RectTransform fill;

        IProgressView _progress;
        int _level = -1, _xp = -1;

        void Start() => _progress = Services.Get<IProgressView>();

        void LateUpdate()
        {
            int lv = _progress.Level, xp = _progress.Xp;
            if (lv == _level && xp == _xp) return;
            if (lv != _level) level.SetText("Lv {0}", (float)lv);
            _level = lv;
            _xp = xp;
            Vector2 max = fill.anchorMax;
            max.x = Mathf.Clamp01((float)xp / Mathf.Max(1, _progress.XpNeeded));
            fill.anchorMax = max;
        }
    }
}
