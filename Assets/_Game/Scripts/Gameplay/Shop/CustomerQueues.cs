using System.Collections.Generic;
using FF.Data;
using UnityEngine;

namespace FF.Gameplay.Shop
{
    /// <summary>Queue slot positions of the prototype's <c>updCustomers</c>, in Unity space (prototype +z = Unity −z).</summary>
    public static class CustomerQueues
    {
        /// <summary>Shelf slot i: front customer centred, the others alternate ±side further back.</summary>
        public static Vector3 ShelfSlot(Vector3 zone, int queueIndex, WorldLayout.MainShopSettings s)
        {
            float x = queueIndex == 0 ? 0f : queueIndex % 2 == 1 ? s.shelfQueueSide : -s.shelfQueueSide;
            return new Vector3(zone.x + x, 0f, zone.z - (s.shelfQueueFirst + queueIndex * s.shelfQueueStep));
        }

        /// <summary>Register slot i: a line beside the counter going toward the road.</summary>
        public static Vector3 RegisterSlot(Vector3 register, int queueIndex, WorldLayout.MainShopSettings s) =>
            new Vector3(register.x + s.registerQueueDx, 0f, register.z - (s.registerQueueZ0 + queueIndex * s.registerQueueStep));

        /// <summary>Point a customer walks to before joining a register queue.</summary>
        public static Vector3 RegisterApproach(Vector3 register, WorldLayout.MainShopSettings s) =>
            new Vector3(register.x + s.registerQueueDx, 0f, register.z - (s.registerQueueZ0 + s.registerApproach));

        /// <summary>
        /// Prototype <c>chooseReg</c>: the candidate with the fewest customers; ties go to the earlier one.
        /// Returns −1 when there is no candidate.
        /// </summary>
        public static int LeastBusy(IReadOnlyList<int> candidates, IReadOnlyList<int> customersPerRegister)
        {
            int best = -1, bestCount = int.MaxValue;
            for (int i = 0; i < candidates.Count; i++)
            {
                int r = candidates[i], count = customersPerRegister[r];
                if (count < bestCount)
                {
                    best = r;
                    bestCount = count;
                }
            }
            return best;
        }
    }
}
