using System;
using System.Collections.Generic;
using FF.Data;
using FF.Gameplay.Zones;
using UnityEngine;

namespace FF.AI
{
    /// <summary>A product factory as workers see it: input, output and the shop shelf of its product.</summary>
    public sealed class ProductionLine
    {
        public string ProductId;
        public string ProductNameKey;
        public ItemType InputType;
        public int InputPerCycle;
        public IPile Input;
        public IPile Output;
        public IPile Shelf;
        /// <summary>Is the factory's machine running a batch right now?</summary>
        public Func<bool> MachineBusy;
    }

    public enum JobLabel
    {
        None,
        Shelf,
        Planks,
    }

    /// <summary>Carry job: take from <see cref="From"/> (until <see cref="Want"/> or full), unload at <see cref="To"/>.</summary>
    public sealed class WorkerJob
    {
        public IPile From;
        public IPile To;
        /// <summary>0 = as many as fit.</summary>
        public int Want;
        public float Score;
        public JobLabel Label;
        public string ProductNameKey;
        public bool Urgent;
    }

    /// <summary>
    /// Prototype carrier helpers (<c>sawIns / sawOuts / plankTarget / goodsTarget / pickJob</c> and the leftover rule of
    /// <c>updCarrier</c>). Ties keep the list order, like the prototype's stable sort.
    /// </summary>
    public static class CarrierJobs
    {
        /// <summary>Emptiest working sawmill input (<c>sawIns()[0]</c>).</summary>
        public static IPile SawInput(IReadOnlyList<IPile> sawInputs)
        {
            IPile best = null;
            foreach (IPile p in sawInputs)
                if (p.IsActive && (best == null || p.Count < best.Count)) best = p;
            return best;
        }

        /// <summary>Fullest working sawmill output with planks in it (<c>sawOuts()[0]</c>).</summary>
        public static IPile SawOutput(IReadOnlyList<IPile> sawOutputs)
        {
            IPile best = null;
            foreach (IPile p in sawOutputs)
                if (p.IsActive && p.Settled > 0 && (best == null || p.Settled > best.Settled)) best = p;
            return best;
        }

        /// <summary>Plank-factory input with the lowest fill ratio below 1 (<c>plankTarget</c>).</summary>
        public static IPile PlankTarget(IReadOnlyList<ProductionLine> lines)
        {
            IPile best = null;
            float bestRatio = 1f;
            foreach (ProductionLine l in lines)
            {
                if (l.InputType != ItemType.Plank || !l.Input.IsActive) continue;
                float ratio = (float)l.Input.Count / l.Input.Capacity;
                if (ratio < bestRatio)
                {
                    bestRatio = ratio;
                    best = l.Input;
                }
            }
            return best;
        }

        /// <summary>Prototype <c>goodsTarget</c> without docks (M7): the product's shelf when it has room.</summary>
        public static IPile GoodsTarget(ProductionLine line) =>
            line.Shelf != null && line.Shelf.IsActive && line.Shelf.Count < line.Shelf.Capacity ? line.Shelf : null;

        /// <summary>
        /// Prototype <c>pickJob(only)</c>: goods from the fullest factory output to its shelf; otherwise (carriers only)
        /// planks from the fullest sawmill output to the emptiest plank-factory input.
        /// </summary>
        public static WorkerJob Pick(IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> sawOutputs, bool shelvesOnly,
            List<ProductionLine> scratch)
        {
            scratch.Clear();
            foreach (ProductionLine l in lines)
                if (l.Output.IsActive && l.Output.Settled > 0) scratch.Add(l);
            // stable: most items first
            for (int i = 1; i < scratch.Count; i++)
            {
                ProductionLine x = scratch[i];
                int j = i - 1;
                while (j >= 0 && scratch[j].Output.Settled < x.Output.Settled)
                {
                    scratch[j + 1] = scratch[j];
                    j--;
                }
                scratch[j + 1] = x;
            }
            foreach (ProductionLine l in scratch)
            {
                IPile to = GoodsTarget(l);
                if (to != null) return new WorkerJob { From = l.Output, To = to };
            }
            if (shelvesOnly) return null;
            IPile planks = SawOutput(sawOutputs);
            IPile target = planks != null ? PlankTarget(lines) : null;
            return target != null ? new WorkerJob { From = planks, To = target } : null;
        }

        /// <summary>Where items already in hand go when there is no job (prototype <c>updCarrier</c> leftover rule).</summary>
        public static IPile LeftoverTarget(ItemType type, IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> sawInputs)
        {
            if (type == ItemType.Plank) return PlankTarget(lines);
            if (type == ItemType.Log) return SawInput(sawInputs);
            foreach (ProductionLine l in lines)
                if (l.Output.ItemType == type) return GoodsTarget(l);
            return null;
        }
    }

    /// <summary>
    /// Prototype <c>robotJob</c>: scores every delivery and takes the most urgent one above the threshold —
    /// customers waiting at an empty shelf &gt; a factory idle without planks &gt; a nearly full factory output.
    /// Truck jobs join with the docks in M7.
    /// </summary>
    public static class RobotScoring
    {
        public static WorkerJob Best(Vector3 robot, IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> sawOutputs,
            Func<IPile, int> waitingCustomers, Func<IPile, int> otherRobotsHeadingTo, EconomyConfig e)
        {
            WorkerJob best = null;
            foreach (ProductionLine l in lines)
            {
                IPile output = l.Output;
                if (!output.IsActive || output.Settled == 0) continue;
                float full = (float)output.Count / output.Capacity > e.robotFullOutputRatio ? e.robotFullOutputBonus : 0f;
                IPile shelf = l.Shelf;
                if (shelf == null || !shelf.IsActive) continue;
                int room = shelf.Capacity - shelf.Count;
                if (room <= 0) continue;
                int waiting = waitingCustomers(shelf);
                bool empty = shelf.Count == 0;
                float score = (1f - (float)shelf.Count / shelf.Capacity) + waiting * e.robotWaitingWeight + (empty ? e.robotEmptyBonus : 0f)
                              + full - otherRobotsHeadingTo(shelf) * e.robotBusyPenalty;
                Consider(ref best, robot, output, shelf, room, score, JobLabel.Shelf, l.ProductNameKey, waiting > 0 || empty, e);
            }

            IPile planks = CarrierJobs.SawOutput(sawOutputs);
            if (planks != null)
                foreach (ProductionLine l in lines)
                {
                    if (l.InputType != ItemType.Plank || !l.Input.IsActive) continue;
                    IPile input = l.Input;
                    int room = input.Capacity - input.Count;
                    if (room <= 0) continue;
                    bool starving = input.Settled < l.InputPerCycle && !l.MachineBusy();
                    float score = (1f - (float)input.Count / input.Capacity) * e.robotPlankWeight + (starving ? e.robotStarvingBonus : 0f)
                                  - otherRobotsHeadingTo(input) * e.robotBusyPenalty;
                    Consider(ref best, robot, planks, input, room, score, JobLabel.Planks, l.ProductNameKey, starving, e);
                }

            return best != null && best.Score > e.robotMinScore ? best : null;
        }

        static void Consider(ref WorkerJob best, Vector3 robot, IPile from, IPile to, int want, float score, JobLabel label,
            string nameKey, bool urgent, EconomyConfig e)
        {
            Vector3 f = from.Position;
            float dx = robot.x - f.x, dz = robot.z - f.z;
            score -= Mathf.Sqrt(dx * dx + dz * dz) / e.robotDistanceDivisor;
            if (best != null && score <= best.Score) return; // first of equal scores wins, like the stable sort
            best = new WorkerJob { From = from, To = to, Want = want, Score = score, Label = label, ProductNameKey = nameKey, Urgent = urgent };
        }
    }

    /// <summary>Prototype <c>assignStaff</c>: cashiers take the next free active register in a fixed order.</summary>
    public static class StaffAssignment
    {
        /// <summary>Main and materials-shop registers interleave: 0, 6, 1, 2, 7, 3, 4, 5.</summary>
        public static readonly int[] RegisterOrder = { 0, 6, 1, 2, 7, 3, 4, 5 };

        /// <param name="registerActive">Index = register number.</param>
        /// <param name="assigned">Receives the register number per cashier (−1 = none).</param>
        public static void AssignCashiers(IReadOnlyList<bool> registerActive, int cashiers, int[] assigned)
        {
            int next = 0;
            for (int c = 0; c < cashiers; c++)
            {
                assigned[c] = -1;
                while (next < RegisterOrder.Length)
                {
                    int r = RegisterOrder[next++];
                    if (r < registerActive.Count && registerActive[r])
                    {
                        assigned[c] = r;
                        break;
                    }
                }
            }
        }
    }

    /// <summary>
    /// Trips between the front yard and the back factory row go through the gap between front buildings nearest to the
    /// trip (our two-row layout; prototype <c>routeVia</c> only routes the mines trip).
    /// </summary>
    public static class WorkerRoutes
    {
        /// <summary>Adds the way-points (Unity space) for a trip; nothing when the trip stays on one side.</summary>
        public static void Via(Vector3 from, Vector3 to, WorldLayout.WorkerLayoutSettings s, float fenceZ, List<Vector3> into)
        {
            into.Clear();
            float backZ = -fenceZ; // Unity z of the fence line
            bool fromBack = from.z > backZ, toBack = to.z > backZ;
            if (fromBack == toBack || from.x > s.backRowMaxX || to.x > s.backRowMaxX) return;
            float mid = (from.x + to.x) / 2f, gap = s.backRowGapsX[0];
            foreach (float g in s.backRowGapsX)
                if (Mathf.Abs(g - mid) < Mathf.Abs(gap - mid)) gap = g;
            var front = new Vector3(gap, 0f, -s.gapFrontZ);
            var back = new Vector3(gap, 0f, -s.gapBackZ);
            into.Add(fromBack ? back : front);
            into.Add(fromBack ? front : back);
        }
    }
}
