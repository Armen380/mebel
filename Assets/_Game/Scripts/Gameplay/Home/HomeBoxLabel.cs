using UnityEngine;

namespace FF.Gameplay.Home
{
    /// <summary>The icon labels on a Home Store box (M10): the item group's line icon, set per box with a property block.</summary>
    public sealed class HomeBoxLabel : MonoBehaviour
    {
        static readonly int BaseMap = Shader.PropertyToID("_BaseMap");
        static MaterialPropertyBlock _block;

        [SerializeField] Renderer[] labels;

        /// <summary>Editor tools only.</summary>
        public void Setup(Renderer[] labelRenderers) => labels = labelRenderers;

        public void SetIcon(Texture icon)
        {
            _block ??= new MaterialPropertyBlock();
            foreach (Renderer r in labels)
            {
                r.GetPropertyBlock(_block);
                if (icon != null) _block.SetTexture(BaseMap, icon);
                r.SetPropertyBlock(_block);
            }
        }
    }
}
