using System;
using UnityEngine;

namespace FF.Data
{
    /// <summary>Closed interval in prototype units.</summary>
    [Serializable]
    public struct ProtoRange
    {
        public float min;
        public float max;

        public ProtoRange(float min, float max)
        {
            this.min = min;
            this.max = max;
        }

        public float Center => (min + max) * 0.5f;
        public float Size => max - min;
    }

    /// <summary>Axis-aligned rectangle in prototype coordinates (x east, z south).</summary>
    [Serializable]
    public struct ProtoRect
    {
        public float x1;
        public float x2;
        public float z1;
        public float z2;

        public ProtoRect(float x1, float x2, float z1, float z2)
        {
            this.x1 = x1;
            this.x2 = x2;
            this.z1 = z1;
            this.z2 = z2;
        }
    }

    /// <summary>
    /// Every position of the map, in <b>prototype coordinates</b> (Vector2 = (x, z)). Convert with
    /// <c>FF.Core.ProtoCoords</c> at the point of use. Values come from Design/data/world_layout.json;
    /// fields the JSON only describes in words keep prototype defaults (function named in the tooltip).
    /// </summary>
    [CreateAssetMenu(menuName = "FF/World Layout", fileName = "WorldLayout")]
    public sealed class WorldLayout : ScriptableObject
    {
        [Serializable]
        public sealed class CameraSettings
        {
            [Tooltip("updCamera(): offset from the player, prototype axes (y up, +z toward the camera).")]
            public Vector3 playOffset = new Vector3(0f, 14.5f, 13.5f);
            public float portraitMultiplier = 1.45f;
            [Tooltip("Portrait when height > width * this.")]
            public float portraitAspect = 1.1f;
            public float lookAtHeight = 0.4f;
            public float positionLerpRate = 4.5f;
            public float lookLerpRate = 6f;
            public float fieldOfView = 42f;
            public float nearClip = 0.1f;
            public float farClip = 200f;
            public float menuOrbitRadius = 5.4f;
            public float menuOrbitRadiusPortrait = 6.2f;
            public float menuOrbitHeight = 1.7f;
            public float menuOrbitSpeed = 0.22f;
        }

        [Serializable]
        public sealed class Sawmill1Settings
        {
            public Vector2 center = new Vector2(-10f, -10f);
            public Vector2 footprint = new Vector2(5.4f, 4f);
            public Vector2 sawIn = new Vector2(-11.7f, -5.3f);
            public Vector2 sawOut = new Vector2(-8.3f, -5.3f);
            [Tooltip("Proto (x, y, z).")]
            public Vector3 machineMouth = new Vector3(-10f, 1.1f, -7.6f);
        }

        [Serializable]
        public sealed class Sawmill2Settings
        {
            public ProtoRange yardX = new ProtoRange(-18.5f, -1.5f);
            public ProtoRange yardZ = new ProtoRange(-27.6f, -13.6f);
            public ProtoRange accessRoadX = new ProtoRange(-18.6f, -13f);
            public ProtoRange accessRoadZ = new ProtoRange(-13.9f, -5.3f);
            public Vector2 building = new Vector2(-10f, -23.5f);
            public Vector2 saw2In = new Vector2(-11.7f, -18.8f);
            public Vector2 saw2Out = new Vector2(-8.3f, -18.8f);
            [Tooltip("Proto (x, y, z). Prototype machines.push({id:'saw2', mouth}).")]
            public Vector3 machineMouth = new Vector3(-10f, 1.1f, -21.1f);
        }

        [Serializable]
        public sealed class FactoryRowSettings
        {
            public float rowZ = -10f;
            public Vector2 footprint = new Vector2(5.4f, 4f);
            [Tooltip("Zones: in = (x + inDx, zoneZ), out = (x + outDx, zoneZ).")]
            public float inZoneDx = -1.7f;
            public float outZoneDx = 1.7f;
            public float zoneZ = -5.3f;
            [Tooltip("Pads: speed = (x + padDx, speedPadZ), qty = (x + padDx, qtyPadZ), buy = (x, buyPadZ).")]
            public float padDx = 4f;
            public float speedPadZ = -11.1f;
            public float qtyPadZ = -8.8f;
            public float buyPadZ = -9.6f;
        }

        /// <summary>Prototype <c>pileLayout(cols, rows, sx, sz)</c> placed at zone + offset (<c>addZone</c> pile option).</summary>
        [Serializable]
        public struct PileSettings
        {
            public int cols;
            public int rows;
            [Tooltip("Spacing (x, z) between items in one layer, prototype units.")]
            public Vector2 spacing;
            [Tooltip("Pile anchor relative to the zone centre, proto (x, y, z).")]
            public Vector3 offset;

            public PileSettings(int cols, int rows, float sx, float sz, Vector3 offset)
            {
                this.cols = cols;
                this.rows = rows;
                spacing = new Vector2(sx, sz);
                this.offset = offset;
            }
        }

        /// <summary>Zones and piles of sawmills and factories (prototype ~905–933). Not in world_layout.json.</summary>
        [Serializable]
        public sealed class ProductionSettings
        {
            [Tooltip("Side of the dashed ground marker (m). Prototype groundPlane(…, 2.4).")]
            public float zoneMarkerSize = 2.4f;
            public PileSettings sawIn = new PileSettings(1, 3, 0f, 0.34f, new Vector3(0f, 0.02f, -1.55f));
            public PileSettings sawOut = new PileSettings(1, 2, 0f, 0.36f, new Vector3(0f, 0.02f, -1.55f));
            public PileSettings plankIn = new PileSettings(1, 2, 0f, 0.36f, new Vector3(0f, 0.02f, -1.55f));
            public PileSettings mineIn = new PileSettings(2, 2, 0.46f, 0.38f, new Vector3(0f, 0.02f, -1.55f));
            public PileSettings productOut = new PileSettings(2, 2, 0.72f, 0.62f, new Vector3(0f, 0.02f, -1.5f));
            [Tooltip("Factory machine mouth = (factoryX, mouthY, mouthZ) proto.")]
            public float factoryMouthY = 1.05f;
            public float factoryMouthZ = -7.5f;
            [Tooltip("Counter tag height above a pile anchor (prototype stackChip setY(1.9)).")]
            public float counterTagHeight = 1.9f;
            [Tooltip("Side of an upgrade pad (m). Prototype PlaneGeometry(1.8, 1.8).")]
            public float padSize = 1.8f;
        }

        [Serializable]
        public sealed class GridSettings
        {
            public int cols;
            public int rows;
            public Vector2 origin;
            public Vector2 step;
            public float jitter;
        }

        [Serializable]
        public sealed class MinesSettings
        {
            public ProtoRange x = new ProtoRange(34f, 60f);
            public ProtoRange z = new ProtoRange(-25f, -13.6f);
            public GridSettings clay = new GridSettings { cols = 4, rows = 4, origin = new Vector2(36.5f, -15.8f), step = new Vector2(2.4f, -2.4f), jitter = 0.5f };
            public GridSettings iron = new GridSettings { cols = 5, rows = 4, origin = new Vector2(47f, -15.8f), step = new Vector2(2.4f, -2.4f), jitter = 0.5f };
        }

        [Serializable]
        public sealed class MainShopSettings
        {
            public float floorMinX = 2.9f;
            public ProtoRange floorZ = new ProtoRange(0.5f, 9.7f);
            public ProtoRange doorX = new ProtoRange(17.95f, 22.05f);
            public float doorZ = 9.7f;
            public float shelfBaseX = 4.6f;
            public float shelfStepX = 2.8f;
            public float shelfPileZ = 1.6f;
            public float shelfZoneZ = 3.3f;
            public float[] registersX = { 22.2f, 26.4f, 30.6f, 34.8f, 39f, 43.2f };
            public float stallCenterZ = 3.5f;
            public Vector2 expansionPad = new Vector2(14.4f, 8.3f);
            [Tooltip("Shelf pile relative to the shelf zone (prototype pile [0, .14, −1.7], pileLayout(2, 2, .74, .6)).")]
            public PileSettings shelfPile = new PileSettings(2, 2, 0.74f, 0.6f, new Vector3(0f, 0.14f, -1.7f));
            public float shelfCounterHeight = 2.4f;
            [Tooltip("Shelf queue: slot i at (x ± side (alternating, 0 for the front), zoneZ + first + i·step).")]
            public float shelfQueueFirst = 1.45f;
            public float shelfQueueStep = 0.85f;
            public float shelfQueueSide = 0.35f;
            [Tooltip("Register queue: slot i at (x + dx, stallZ + z0 + i·step); customers come in via (x + dx, stallZ + z0 + approach).")]
            public float registerQueueDx = 1.25f;
            public float registerQueueZ0 = -0.5f;
            public float registerQueueStep = 1.05f;
            public float registerApproach = 3.6f;
            [Tooltip("Cash zone = register + offset; its bill pile is placed relative to the zone.")]
            public Vector2 cashZoneOffset = new Vector2(-1.45f, -0.1f);
            public PileSettings cashPile = new PileSettings(2, 2, 0.5f, 0.3f, new Vector3(1.45f, 1.09f, 1.1f));
            public float cashCounterHeight = 2f;
            [Tooltip("Customers enter through doorIn + random x in ±jitter/2 and this z offset.")]
            public float doorJitter = 2f;
            public float doorInsideOffset = -0.4f;
        }

        [Serializable]
        public sealed class MaterialsShopSettings
        {
            public ProtoRange x = new ProtoRange(46.4f, 60.6f);
            public ProtoRange z = new ProtoRange(0.5f, 9.7f);
            public ProtoRange doorX = new ProtoRange(50f, 53f);
            public float shelfSinkX = 48f;
            public float shelfMaterialX = 50.6f;
            public float[] registersX = { 54.4f, 58.2f };
        }

        [Serializable]
        public sealed class DeliverySettings
        {
            public float[] baysX = { -4f, -9.2f, -14.4f };
            public float truckParkZ = 12.3f;
            public float truckLaneZ = 14.6f;
            public float dockZoneZ = 10.1f;
            public Vector2 truckPad = new Vector2(1.2f, 10.4f);
            public Vector2 parkingPad = new Vector2(-1.4f, 7.6f);
        }

        [Serializable]
        public sealed class RoadSettings
        {
            public ProtoRange z = new ProtoRange(11.2f, 15.8f);
            public float laneWestboundZ = 12.3f;
            public float laneEastboundZ = 14.6f;
            public ProtoRange sidewalkZ = new ProtoRange(16.7f, 18.3f);
            public float zebraX = 20f;
        }

        [Serializable]
        public sealed class CarParkSettings
        {
            public ProtoRange x = new ProtoRange(9.6f, 34.8f);
            public ProtoRange z = new ProtoRange(18.6f, 25.2f);
            [Tooltip("Slot i x = slotBaseX + slotStepX * i.")]
            public float slotBaseX = 11.5f;
            public float slotStepX = 2.6f;
            public int slotCount = 8;
            public float aisleZ = 19.6f;
            public float slotZ = 22.6f;
            public float drivewayX = 33f;
        }

        [Serializable]
        public sealed class CustomerPathSettings
        {
            public Vector2 spawn = new Vector2(34f, 17.5f);
            public Vector2 exit = new Vector2(42f, 17.5f);
            public Vector2 mainDoorOut = new Vector2(20f, 11.4f);
            public Vector2 mainDoorIn = new Vector2(20f, 8.5f);
            public Vector2 annexDoorOut = new Vector2(51.5f, 11.4f);
            public Vector2 annexDoorIn = new Vector2(51.5f, 8.5f);
        }

        [Serializable]
        public sealed class DreamHouseSettings
        {
            public ProtoRange plotX = new ProtoRange(72f, 98f);
            public ProtoRange plotZ = new ProtoRange(-26f, -4f);
            public float accessRoadX = 85f;
            public ProtoRange accessRoadZ = new ProtoRange(-4f, 11.2f);
            public float archZ = -4f;
            public Vector2 foundationCenter = new Vector2(81f, -17f);
            public Vector2 foundationSize = new Vector2(11f, 8f);
            public Vector2 billboard = new Vector2(81f, -23.2f);
            public Vector2 workArea = new Vector2(93.5f, -15f);
        }

        /// <summary>Player region rules of the prototype <c>collide()</c>.</summary>
        [Serializable]
        public sealed class PlayerBoundsSettings
        {
            public ProtoRange x = new ProtoRange(-31.5f, 100f);
            public ProtoRange z = new ProtoRange(-39.4f, 25.6f);
            [Tooltip("North of this z only the back areas are allowed.")]
            public float fenceZ = -13.2f;
            [Tooltip("Inside the fence gap (z > this) the player is pushed back to fenceZ instead of sideways.")]
            public float gateDepthZ = -13.9f;
            [Tooltip("x ≤ this belongs to the sawmill back yard, x > this to the mines yard.")]
            public float backAreaSplitX = 15f;
            public ProtoRange sawYardX = new ProtoRange(-18.2f, -1.8f);
            public float sawYardMinZ = -27.2f;
            public ProtoRange minesYardX = new ProtoRange(34.4f, 59.6f);
            public float minesYardMinZ = -24.6f;
            public float dreamPlotMinX = 62f;
            public float dreamPlotMinZ = -25.6f;
            public float collisionRadius = 0.3f;
            public Vector2 playerSpawn = new Vector2(-4f, 0f);
        }

        /// <summary>Blocker rectangles of the prototype <c>refreshBlocks()</c>.</summary>
        [Serializable]
        public sealed class BlockerSettings
        {
            public ProtoRect sawmill1 = new ProtoRect(-12.7f, -7.3f, -12f, -7.2f);
            public ProtoRect sawmill2 = new ProtoRect(-12.7f, -7.3f, -25.5f, -20.7f);
            public ProtoRect shopLeftWall = new ProtoRect(2.75f, 3.05f, 0.4f, 9.85f);
            public ProtoRect shopFrontLeftWall = new ProtoRect(2.75f, 17.95f, 9.55f, 9.85f);
            [Tooltip("Right wall = (wallX ± halfThickness) × wallZ; front-right = (frontRightMinX .. wallX + halfThickness) × frontWallZ.")]
            public float shopWallHalfThickness = 0.15f;
            public ProtoRange shopWallZ = new ProtoRange(0.4f, 9.85f);
            public ProtoRange shopFrontWallZ = new ProtoRange(9.55f, 9.85f);
            public float shopFrontRightMinX = 22.05f;
            public ProtoRect[] dreamPlotFence =
            {
                new ProtoRect(71.85f, 72.15f, -26f, -4f),
                new ProtoRect(97.85f, 98.15f, -26f, -4f),
                new ProtoRect(72f, 98f, -26.15f, -25.85f),
                new ProtoRect(72f, 82.6f, -4.15f, -3.85f),
                new ProtoRect(87.4f, 98f, -4.15f, -3.85f),
            };
            public ProtoRect[] materialsShopWalls =
            {
                new ProtoRect(46.25f, 46.55f, 0.4f, 9.85f),
                new ProtoRect(60.45f, 60.75f, 0.4f, 9.85f),
                new ProtoRect(46.25f, 50f, 9.55f, 9.85f),
                new ProtoRect(53f, 60.75f, 9.55f, 9.85f),
            };
            [Tooltip("Owned factory = (x ± factoryHalfX) × factoryZ.")]
            public float factoryHalfX = 2.7f;
            public ProtoRange factoryZ = new ProtoRange(-12f, -7.2f);
            [Tooltip("Active register stall = (x ± halfX) × (stallZ ± halfZ).")]
            public Vector2 registerHalfSize = new Vector2(0.62f, 1.55f);
        }

        public CameraSettings camera = new CameraSettings();
        public float fenceLineZ = -13.6f;
        public Sawmill1Settings sawmill1 = new Sawmill1Settings();
        public Sawmill2Settings sawmill2 = new Sawmill2Settings();
        public FactoryRowSettings factories = new FactoryRowSettings();
        public ProductionSettings production = new ProductionSettings();
        public GridSettings forest = new GridSettings { cols = 5, rows = 7, origin = new Vector2(-30.5f, -11.8f), step = new Vector2(2.4f, 2.55f), jitter = 0.7f };
        public MinesSettings mines = new MinesSettings();
        public MainShopSettings mainShop = new MainShopSettings();
        public MaterialsShopSettings materialsShop = new MaterialsShopSettings();
        public DeliverySettings delivery = new DeliverySettings();
        public RoadSettings road = new RoadSettings();
        public CarParkSettings carPark = new CarParkSettings();
        public CustomerPathSettings customerPaths = new CustomerPathSettings();
        public DreamHouseSettings dreamHouse = new DreamHouseSettings();
        public PlayerBoundsSettings playerBounds = new PlayerBoundsSettings();
        public BlockerSettings blockers = new BlockerSettings();
    }
}
