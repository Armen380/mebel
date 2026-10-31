using System;
using System.Collections.Generic;
using UnityEngine;

namespace FF.Data
{
    [CreateAssetMenu(menuName = "FF/Tutorial", fileName = "Tutorial")]
    public sealed class TutorialDef : ScriptableObject
    {
        [Serializable]
        public sealed class Step
        {
            public string textKey;
            public string completeOn;
            public string arrowTarget;
        }

        public List<Step> steps = new List<Step>();
    }
}
