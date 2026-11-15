using FF.Data;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>
    /// One fixed Dream House slot in the world (M10): a translucent ghost while it is open and empty, and the model of
    /// the placed item. Factory slots also own a drop <see cref="Zone"/> for the carried product. Logic lives in
    /// <see cref="HomeSlotSystem"/> / <see cref="HomeRules"/>.
    /// </summary>
    public sealed class HomeSlot : MonoBehaviour
    {
        const float PopRate = 2.6f, Overshoot = 1.7f;

        [SerializeField] string slotId;
        [SerializeField] GameObject ghost;
        [Tooltip("Factory slots: the drop zone for the carried product; null for Home Store slots.")]
        [SerializeField] Zone zone;
        [Tooltip("Item ids with a model (factory slot: the product id).")]
        [SerializeField] string[] modelIds;
        [SerializeField] GameObject[] models;

        GameObject _shown;
        float _pop = 1f;

        public string SlotId => slotId;
        public Zone Zone => zone;
        public Vector3 Position => transform.position;
        public HomeDef.SlotDef Def { get; set; }

        /// <summary>Editor tools only.</summary>
        public void Setup(string id, GameObject ghostObject, Zone dropZone, string[] ids, GameObject[] modelObjects)
        {
            slotId = id;
            ghost = ghostObject;
            zone = dropZone;
            modelIds = ids;
            models = modelObjects;
        }

        /// <summary>Shows the ghost or the placed item's model; pops a model that appears during play.</summary>
        public void Show(string placedId, bool open, bool animate)
        {
            if (ghost != null) ghost.SetActive(open && placedId == null);
            GameObject model = null;
            for (int i = 0; i < models.Length; i++)
            {
                bool on = placedId != null && modelIds[i] == placedId;
                if (on) model = models[i];
                if (models[i].activeSelf != on) models[i].SetActive(on);
            }
            if (model != null && model != _shown && animate) _pop = 0f;
            _shown = model;
        }

        void Update()
        {
            if (_pop >= 1f || _shown == null) return;
            _pop = Mathf.Min(1f, _pop + Time.deltaTime * PopRate);
            float k = _pop - 1f;
            float s = 1f + (Overshoot + 1f) * k * k * k + Overshoot * k * k;
            _shown.transform.localScale = Vector3.one * Mathf.Max(0.01f, s);
        }
    }
}
