using System.Collections.Generic;
using FF.Core;
using FF.Data;
using FF.Gameplay.World;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>
    /// Prototype <c>shopW / layoutShop</c>: the right wall of the main shop sits at x = 25 + 4.2·shop level; when the
    /// level grows it slides out (lerp 3/s) and the floor, its stripes and the front-right wall follow. Starts at the
    /// target width (no animation after loading a save).
    /// </summary>
    public sealed class ShopExpansion : MonoBehaviour
    {
        const float LerpRate = 3f, Epsilon = 0.005f, StripeMargin = 0.15f;

        [SerializeField] Transform floor;
        [SerializeField] List<Transform> stripes = new List<Transform>();
        [SerializeField] Transform rightWall;
        [SerializeField] Transform frontRightWall;
        [SerializeField] Transform frontRightTrim;

        EconomyConfig _economy;
        WorldLayout.MainShopSettings _shop;
        IUpgradeLevels _levels;
        float _current;

        public float CurrentWallX => _current;

        /// <summary>Editor tools only.</summary>
        public void Setup(Transform floorPlane, List<Transform> floorStripes, Transform wall, Transform frontWall, Transform frontTrim)
        {
            floor = floorPlane;
            stripes = floorStripes;
            rightWall = wall;
            frontRightWall = frontWall;
            frontRightTrim = frontTrim;
        }

        void Start()
        {
            var db = Services.Get<GameDatabase>();
            _economy = db.economy;
            _shop = db.world.mainShop;
            _levels = Services.Get<IUpgradeLevels>();
            _current = Target();
            Layout(_current);
        }

        float Target() => _economy.ShopWallX(_levels.GetLevel(WorldStateSync.ShopPadId));

        void Update()
        {
            float target = Target();
            if (Mathf.Abs(target - _current) <= Epsilon) return;
            _current += (target - _current) * Mathf.Min(1f, Mathf.Min(Time.deltaTime, 0.05f) * LerpRate);
            Layout(_current);
        }

        /// <summary>Prototype <c>layoutShop(w)</c>.</summary>
        void Layout(float wallX)
        {
            float minX = _shop.floorMinX, doorX = _shop.doorX.max;
            Vector3 s = floor.localScale;
            floor.localScale = new Vector3(wallX - minX, s.y, s.z);
            floor.localPosition = new Vector3((minX + wallX) / 2f, floor.localPosition.y, floor.localPosition.z);
            for (int i = 0; i < stripes.Count; i++)
            {
                bool show = stripes[i].localPosition.x < wallX - StripeMargin;
                if (stripes[i].gameObject.activeSelf != show) stripes[i].gameObject.SetActive(show);
            }
            rightWall.localPosition = new Vector3(wallX, rightWall.localPosition.y, rightWall.localPosition.z);
            float front = wallX - doorX;
            Stretch(frontRightWall, front, doorX + front / 2f);
            Stretch(frontRightTrim, front + 0.1f, doorX + front / 2f);
        }

        static void Stretch(Transform t, float width, float centerX)
        {
            t.localScale = new Vector3(width, t.localScale.y, t.localScale.z);
            t.localPosition = new Vector3(centerX, t.localPosition.y, t.localPosition.z);
        }
    }
}
