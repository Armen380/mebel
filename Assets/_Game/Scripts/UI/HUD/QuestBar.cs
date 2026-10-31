using FF.Core;
using FF.Data;
using TMPro;
using UnityEngine;
using UnityEngine.Localization;

namespace FF.UI.HUD
{
    /// <summary>Tutorial bar (prototype <c>renderQuest</c>): "1/8" + step text; the bottom hint shows until step 2.</summary>
    public sealed class QuestBar : MonoBehaviour
    {
        const int HintLastStep = 1;

        [SerializeField] GameObject bar;
        [SerializeField] TMP_Text stepLabel;
        [SerializeField] TMP_Text text;
        [SerializeField] GameObject hint;

        readonly LocalizedString _text = new LocalizedString { TableReference = "Game" };
        TutorialDef _tutorial;
        IProgressView _progress;
        int _step = -1;

        void Start()
        {
            _tutorial = Services.Get<GameDatabase>().tutorial;
            _progress = Services.Get<IProgressView>();
        }

        void OnDestroy() => _text.StringChanged -= OnText;

        void OnText(string value) => text.SetText(value);

        void LateUpdate()
        {
            int step = _progress.QuestStep;
            if (step == _step) return;
            _step = step;
            bool active = step < _tutorial.steps.Count;
            bar.SetActive(active);
            hint.SetActive(step <= HintLastStep);
            if (!active) return;
            stepLabel.SetText("{0}/{1}", (float)(step + 1), (float)_tutorial.steps.Count);
            bool first = _text.IsEmpty;
            _text.TableEntryReference = _tutorial.steps[step].textKey;
            if (first) _text.StringChanged += OnText; // subscribing loads the string; later key changes reload it
        }
    }
}
