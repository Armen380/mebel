using FF.Core;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Movement
{
    /// <summary>
    /// Where the player may walk (prototype <c>collide()</c> region part), evaluated in Unity space.
    /// Beyond the factory fence only the sawmill back yard, the mines yard (when open) and the dream plot are allowed.
    /// </summary>
    public sealed class PlayerRegionRules
    {
        readonly float _minX, _maxX, _minZ, _maxZ;
        readonly float _fenceZ, _gateDepthZ, _splitX;
        readonly float _sawYardMinX, _sawYardMaxX, _sawYardMaxZ;
        readonly float _minesMinX, _minesMaxX, _minesMaxZ;
        readonly float _dreamMinX, _dreamMaxZ;

        public PlayerRegionRules(WorldLayout.PlayerBoundsSettings b)
        {
            // Proto z grows toward the camera; Unity z = -proto z, so proto minimums become Unity maximums.
            _minX = b.x.min;
            _maxX = b.x.max;
            _minZ = ProtoCoords.ToUnityZ(b.z.max);
            _maxZ = ProtoCoords.ToUnityZ(b.z.min);
            _fenceZ = ProtoCoords.ToUnityZ(b.fenceZ);
            _gateDepthZ = ProtoCoords.ToUnityZ(b.gateDepthZ);
            _splitX = b.backAreaSplitX;
            _sawYardMinX = b.sawYardX.min;
            _sawYardMaxX = b.sawYardX.max;
            _sawYardMaxZ = ProtoCoords.ToUnityZ(b.sawYardMinZ);
            _minesMinX = b.minesYardX.min;
            _minesMaxX = b.minesYardX.max;
            _minesMaxZ = ProtoCoords.ToUnityZ(b.minesYardMinZ);
            _dreamMinX = b.dreamPlotMinX;
            _dreamMaxZ = ProtoCoords.ToUnityZ(b.dreamPlotMinZ);
        }

        /// <param name="pos">Ground position (Unity x, z), adjusted in place.</param>
        /// <param name="minesOpen">Plumbing owned: the mines yard gate is open.</param>
        public void Apply(ref Vector2 pos, bool minesOpen)
        {
            pos.x = Mathf.Clamp(pos.x, _minX, _maxX);
            pos.y = Mathf.Clamp(pos.y, _minZ, _maxZ);
            if (pos.y <= _fenceZ) return; // front of the fence: free

            if (pos.x >= _dreamMinX)
            {
                if (pos.y > _dreamMaxZ) pos.y = _dreamMaxZ;
                return;
            }

            bool mines = pos.x > _splitX;
            if (!mines && pos.y > _sawYardMaxZ) pos.y = _sawYardMaxZ;
            if (mines && pos.y > _minesMaxZ) pos.y = _minesMaxZ;

            if (mines && !minesOpen)
            {
                pos.y = _fenceZ;
                return;
            }

            float a = mines ? _minesMinX : _sawYardMinX;
            float b = mines ? _minesMaxX : _sawYardMaxX;
            if (pos.x < a || pos.x > b)
            {
                // Still in the gap of the fence line: step back out; deeper inside: slide along the yard wall.
                if (pos.y < _gateDepthZ) pos.y = _fenceZ;
                else pos.x = Mathf.Clamp(pos.x, a, b);
            }
        }
    }
}
