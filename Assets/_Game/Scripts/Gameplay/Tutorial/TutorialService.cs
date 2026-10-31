using FF.Core;
using FF.Data;
using FF.Gameplay.Nodes;
using FF.Gameplay.Pads;
using FF.Gameplay.Progress;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Tutorial
{
    /// <summary>
    /// Prototype <c>QUEST / emit</c>: the current step completes on its gameplay event and the quest index moves on.
    /// Also answers where the arrow should point (<c>QUEST[i].target()</c>).
    /// </summary>
    public sealed class TutorialService : MonoBehaviour
    {
        const float TreeArrowHeight = 3.6f;
        const float DefaultArrowHeight = 3f;

        [SerializeField] Transform player;

        TutorialDef _def;
        GameProgress _progress;
        ZoneRegistry _zones;
        NodeRegistry _nodes;
        PadSystem _pads;

        public bool IsFinished => _progress.QuestStep >= _def.steps.Count;
        public TutorialDef.Step Current => IsFinished ? null : _def.steps[_progress.QuestStep];

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform playerTransform) => player = playerTransform;

        void Awake()
        {
            _def = Services.Get<GameDatabase>().tutorial;
            _progress = Services.Get<GameProgress>();
        }

        void Start()
        {
            _zones = Services.Get<ZoneRegistry>();
            _nodes = Services.Get<NodeRegistry>();
            _pads = Services.Get<PadSystem>();
        }

        void OnEnable()
        {
            GameEvents.Chopped += OnChopped;
            GameEvents.ZoneDropped += OnDropped;
            GameEvents.ZonePicked += OnPicked;
            GameEvents.CashCollected += OnCash;
            GameEvents.PadCompleted += OnPad;
        }

        void OnDisable()
        {
            GameEvents.Chopped -= OnChopped;
            GameEvents.ZoneDropped -= OnDropped;
            GameEvents.ZonePicked -= OnPicked;
            GameEvents.CashCollected -= OnCash;
            GameEvents.PadCompleted -= OnPad;
        }

        void OnChopped() => Emit(TutorialTrigger.Chop, null);
        void OnDropped(string zoneId) => Emit(TutorialTrigger.Drop, zoneId);
        void OnPicked(string zoneId) => Emit(TutorialTrigger.Pick, zoneId);
        void OnCash() => Emit(TutorialTrigger.Cash, null);
        void OnPad(string padId, int level) => Emit(TutorialTrigger.Pad, padId);

        void Emit(TutorialTrigger trigger, string id)
        {
            TutorialDef.Step step = Current;
            if (step != null && TutorialRules.Matches(step, trigger, id)) _progress.AdvanceQuest();
        }

        /// <summary>World point the arrow hovers over for the current step; false when there is none.</summary>
        public bool TryGetTarget(out Vector3 target)
        {
            target = default;
            TutorialDef.Step step = Current;
            if (step == null) return false;
            switch (step.target)
            {
                case TutorialTarget.NearestTree:
                    ResourceNode tree = _nodes.Nearest(player.position, ItemType.Log);
                    if (tree == null) return false;
                    target = tree.Position;
                    target.y = TreeArrowHeight;
                    return true;
                case TutorialTarget.Zone:
                    for (int i = 0; i < _zones.Zones.Count; i++)
                        if (_zones.Zones[i].Id == step.targetId)
                        {
                            target = _zones.Zones[i].Position;
                            target.y = DefaultArrowHeight;
                            return true;
                        }
                    return false;
                case TutorialTarget.Pad:
                    UpgradePad pad = _pads.Find(step.targetId);
                    if (pad == null || !pad.IsVisible) return false;
                    target = pad.Position;
                    target.y = DefaultArrowHeight;
                    return true;
            }
            return false;
        }
    }

    public static class TutorialRules
    {
        /// <summary>Prototype <c>QUEST[i].done(e, a)</c>: same event; the id must match when the step names one.</summary>
        public static bool Matches(TutorialDef.Step step, TutorialTrigger trigger, string id) =>
            step.trigger == trigger && (string.IsNullOrEmpty(step.triggerId) || step.triggerId == id);
    }
}
