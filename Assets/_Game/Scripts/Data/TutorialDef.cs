using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    /// <summary>Event that completes a tutorial step (prototype <c>emit(e, a)</c>).</summary>
    public enum TutorialTrigger
    {
        Chop,
        Drop,
        Pick,
        Cash,
        Pad,
    }

    /// <summary>What the tutorial arrow points at.</summary>
    public enum TutorialTarget
    {
        NearestTree,
        Zone,
        Pad,
    }

    [CreateAssetMenu(menuName = "FF/Tutorial", fileName = "Tutorial")]
    public sealed class TutorialDef : ScriptableObject
    {
        [Serializable]
        public sealed class Step
        {
            public string textKey;
            [Tooltip("Design text from tutorial_quest.json (the importer derives the fields below from it).")]
            public string completeOn;
            public string arrowTarget;

            public TutorialTrigger trigger;
            [Tooltip("Zone id for Drop / Pick (empty = any zone); pad id for Pad (empty = any pad).")]
            public string triggerId;
            public TutorialTarget target;
            [Tooltip("Zone or pad id the arrow points at.")]
            public string targetId;
        }

        public List<Step> steps = new List<Step>();
    }
}
