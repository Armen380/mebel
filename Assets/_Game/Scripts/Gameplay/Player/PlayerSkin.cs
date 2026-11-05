using System;
using FF.Core;
using FF.Data;
using FF.Gameplay.Progress;
using UnityEngine;

namespace FF.Gameplay.Player
{
    /// <summary>
    /// Skin choice (prototype <c>S.skin / setSkin</c>): applies the saved skin on start, switches on request when it is
    /// unlocked (Golden: total earned ≥ its threshold) and saves it.
    /// </summary>
    [RequireComponent(typeof(PlayerLook))]
    public sealed class PlayerSkin : MonoBehaviour, ISkinSelection
    {
        GameDatabase _db;
        GameProgress _progress;
        PlayerLook _look;

        public string Current => _progress.Skin;
        public event Action<string> Changed;

        void Awake()
        {
            _db = Services.Get<GameDatabase>();
            _progress = Services.Get<GameProgress>();
            _look = GetComponent<PlayerLook>();
            Services.Register<ISkinSelection>(this);
        }

        void Start()
        {
            // a skin that is unknown or not (or no longer) unlocked falls back to the default one
            if (!IsUnlocked(_progress.Skin) || !_look.Has(_progress.Skin)) _progress.Skin = _db.DefaultSkin.id;
            _look.Apply(_progress.Skin);
        }

        public bool IsUnlocked(string id) => SkinRules.IsUnlocked(_db.Skin(id), _progress.TotalEarned);

        public bool Select(string id)
        {
            if (id == _progress.Skin) return true;
            if (!IsUnlocked(id) || !_look.Apply(id)) return false;
            _progress.Skin = id;
            GameEvents.RaiseProgressChanged();
            Changed?.Invoke(id);
            return true;
        }
    }

    public static class SkinRules
    {
        /// <summary>Prototype <c>locked = s.unlock &amp;&amp; S.total &lt; s.unlock</c>.</summary>
        public static bool IsUnlocked(SkinDef skin, long totalEarned) =>
            skin != null && (skin.unlockTotalEarned <= 0 || totalEarned >= skin.unlockTotalEarned);
    }
}
