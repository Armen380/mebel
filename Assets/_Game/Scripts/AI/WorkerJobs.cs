using System;
using System.Collections.Generic;
using FF.Core;
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
        /// <summary>Plumbing / Building materials (prototype <c>p.annex</c>): the only lines section carriers serve.</summary>
        public bool Section;
        /// <summary>Is the factory's machine running a batch right now?</summary>
        public Func<bool> MachineBusy;
    }

    public enum JobLabel
    {
        None,
        Shelf,
        Planks,
        Truck,
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

    /// <summary>What a carrying worker moves (update 1.0.1 worker roles).</summary>
    public enum CarrierRole
    {
        /// <summary>Carriers: planks from the sawmills to the factories.</summary>
        Planks,
        /// <summary>Stockers: finished goods to the shelves and trucks.</summary>
        Goods,
        /// <summary>Section carriers: Plumbing / Building materials to their shelves and trucks.</summary>
        Section,
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
            for (int psi = 0; psi < sawInputs.Count; psi++)
            {
                IPile p = sawInputs[psi];
                if (p.IsActive && (best == null || p.Count < best.Count)) best = p;
            }
            return best;
        }

        /// <summary>Fullest working sawmill output with planks in it (<c>sawOuts()[0]</c>).</summary>
        public static IPile SawOutput(IReadOnlyList<IPile> sawOutputs)
        {
            IPile best = null;
            for (int psi = 0; psi < sawOutputs.Count; psi++)
            {
                IPile p = sawOutputs[psi];
                if (p.IsActive && p.Settled > 0 && (best == null || p.Settled > best.Settled)) best = p;
            }
            return best;
        }

        /// <summary>Plank-factory input with the lowest fill ratio below 1 (<c>plankTarget</c>).</summary>
        public static IPile PlankTarget(IReadOnlyList<ProductionLine> lines)
        {
            IPile best = null;
            float bestRatio = 1f;
            for (int lli = 0; lli < lines.Count; lli++)
            {
                ProductionLine l = lines[lli];
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

        static bool HasRoom(IPile p) => p != null && p.IsActive && p.Count < p.Capacity;

        /// <summary>The product's shelf when it has room (stockers, prototype <c>only</c>).</summary>
        public static IPile ShelfTarget(ProductionLine line) => HasRoom(line.Shelf) ? line.Shelf : null;

        /// <summary>First open dock with a parked truck that still has room (prototype <c>freeDock</c>).</summary>
        public static IPile FreeDock(IReadOnlyList<IPile> docks)
        {
            if (docks == null) return null;
            for (int i = 0; i < docks.Count; i++)
                if (HasRoom(docks[i])) return docks[i];
            return null;
        }

        /// <summary>
        /// Prototype <c>goodsTarget(type, dockFirst)</c>: the shelf when it has room, else a free truck dock; robots
        /// (<paramref name="dockFirst"/>) try the dock first.
        /// </summary>
        public static IPile GoodsTarget(ProductionLine line, IReadOnlyList<IPile> docks, bool dockFirst)
        {
            IPile shelf = ShelfTarget(line);
            if (dockFirst) return FreeDock(docks) ?? shelf;
            return shelf ?? FreeDock(docks);
        }

        /// <summary>
        /// Prototype <c>pickJob</c>, split by role (user decision 2026-11-10, update 1.0.1 — the prototype let carriers
        /// take furniture too): <see cref="CarrierRole.Planks"/> (carriers) only planks from the fullest sawmill output to
        /// the emptiest plank-factory input; <see cref="CarrierRole.Goods"/> (stockers) goods from the fullest factory
        /// output to its shelf, else a free truck dock; <see cref="CarrierRole.Section"/> the same for Plumbing / Building
        /// materials only.
        /// </summary>
        public static WorkerJob Pick(IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> sawOutputs, CarrierRole role,
            IReadOnlyList<IPile> docks, List<ProductionLine> scratch)
        {
            if (role == CarrierRole.Planks)
            {
                IPile planks = SawOutput(sawOutputs);
                IPile target = planks != null ? PlankTarget(lines) : null;
                return target != null ? new WorkerJob { From = planks, To = target } : null;
            }
            bool sectionOnly = role == CarrierRole.Section;
            scratch.Clear();
            for (int lli = 0; lli < lines.Count; lli++)
            {
                ProductionLine l = lines[lli];
                if ((!sectionOnly || l.Section) && l.Output.IsActive && l.Output.Settled > 0) scratch.Add(l);
            }
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
            for (int si = 0; si < scratch.Count; si++)
            {
                ProductionLine l = scratch[si];
                IPile to = GoodsTarget(l, docks, false);
                if (to != null) return new WorkerJob { From = l.Output, To = to };
            }
            return null;
        }

        /// <summary>
        /// Where items already in hand go when there is no job (prototype <c>updCarrier</c> leftover rule): goods to the
        /// shelf, else a truck (robots dock first); planks / logs / clay / iron to the input that uses them.
        /// </summary>
        public static IPile LeftoverTarget(ItemType type, IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> sawInputs,
            bool dockFirst, IReadOnlyList<IPile> docks)
        {
            if (type == ItemType.Plank) return PlankTarget(lines);
            if (type == ItemType.Log) return SawInput(sawInputs);
            // clay / iron: the factory that uses it (prototype in_sink / in_material)
            for (int lli = 0; lli < lines.Count; lli++)
            {
                ProductionLine l = lines[lli];
                if (l.InputType == type && l.InputType != ItemType.Plank) return l.Input;
            }
            for (int lli = 0; lli < lines.Count; lli++)
            {
                ProductionLine l = lines[lli];
                if (l.Output.ItemType == type) return GoodsTarget(l, docks, dockFirst);
            }
            return null;
        }
    }

    /// <summary>
    /// Prototype <c>robotJob</c> without the plank jobs (user decision 2026-11-10, update 1.0.1: robots carry only
    /// finished goods): scores every delivery and takes the most urgent one above the threshold — customers waiting at an
    /// empty shelf &gt; a truck waiting at the dock &gt; a nearly full factory output.
    /// </summary>
    public static class RobotScoring
    {
        public static WorkerJob Best(Vector3 robot, IReadOnlyList<ProductionLine> lines, IReadOnlyList<IPile> docks, Func<IPile, int> waitingCustomers, Func<IPile, int> otherRobotsHeadingTo, EconomyConfig e)
        {
            var best = new Candidate();
            for (int lli = 0; lli < lines.Count; lli++)
            {
                ProductionLine l = lines[lli];
                IPile output = l.Output;
                if (!output.IsActive || output.Settled == 0) continue;
                float full = (float)output.Count / output.Capacity > e.robotFullOutputRatio ? e.robotFullOutputBonus : 0f;
                IPile shelf = l.Shelf;
                if (shelf != null && shelf.IsActive && shelf.Capacity - shelf.Count > 0)
                {
                    int room = shelf.Capacity - shelf.Count;
                    int waiting = waitingCustomers(shelf);
                    bool empty = shelf.Count == 0;
                    float score = (1f - (float)shelf.Count / shelf.Capacity) + waiting * e.robotWaitingWeight + (empty ? e.robotEmptyBonus : 0f)
                                  + full - otherRobotsHeadingTo(shelf) * e.robotBusyPenalty;
                    Consider(ref best, robot, output, shelf, room, score, JobLabel.Shelf, l.ProductNameKey, waiting > 0 || empty, e);
                }

                // prototype: a parked truck with room takes any furniture
                IPile dock = CarrierJobs.FreeDock(docks);
                if (dock != null)
                {
                    int n = dock.Count, order = e.truckOrderSize;
                    float score = e.robotTruckBase + (float)n / order * e.robotTruckFillWeight + full - otherRobotsHeadingTo(dock) * e.robotBusyPenalty;
                    Consider(ref best, robot, output, dock, order - n, score, JobLabel.Truck, null, false, e);
                }
            }

            if (!best.Set || best.Score <= e.robotMinScore) return null;
            // one allocation, only for the job taken (idle robots score every frame)
            return new WorkerJob
            {
                From = best.From, To = best.To, Want = best.Want, Score = best.Score, Label = best.Label,
                ProductNameKey = best.ProductNameKey, Urgent = best.Urgent,
            };
        }

        struct Candidate
        {
            public bool Set;
            public IPile From, To;
            public int Want;
            public float Score;
            public JobLabel Label;
            public string ProductNameKey;
            public bool Urgent;
        }

        static void Consider(ref Candidate best, Vector3 robot, IPile from, IPile to, int want, float score, JobLabel label,
            string nameKey, bool urgent, EconomyConfig e)
        {
            Vector3 f = from.Position;
            float dx = robot.x - f.x, dz = robot.z - f.z;
            score -= Mathf.Sqrt(dx * dx + dz * dz) / e.robotDistanceDivisor;
            if (best.Set && score <= best.Score) return; // first of equal scores wins, like the stable sort
            best = new Candidate
            {
                Set = true, From = from, To = to, Want = want, Score = score, Label = label, ProductNameKey = nameKey, Urgent = urgent,
            };
        }
    }

    /// <summary>Prototype <c>assignStaff</c>: cashiers take the next free active register in a fixed order.</summary>
    public static class StaffAssignment
    {
        /// <summary>Main and materials-shop registers interleave: 0, 6, 1, 2, 7, 3, 4, 5.</summary>
        public static readonly int[] RegisterOrder = { 0, 6, 1, 2, 7, 3, 4, 5 };

        /// <summary>Materials-shop registers section cashiers take, in order.</summary>
        public static readonly int[] SectionOrder = { 6, 7 };

        /// <summary>
        /// Prototype <c>assignStaff</c>: section cashiers take the active materials-shop registers first, then cashiers take
        /// the remaining active registers in <see cref="RegisterOrder"/>.
        /// </summary>
        /// <param name="registerActive">Index = register number.</param>
        /// <param name="sectionAssigned">Receives the register number per section cashier (−1 = none).</param>
        /// <param name="assigned">Receives the register number per cashier (−1 = none).</param>
        public static void AssignStaff(IReadOnlyList<bool> registerActive, int sectionCashiers, int[] sectionAssigned,
            int cashiers, int[] assigned)
        {
            int next = 0;
            for (int c = 0; c < sectionCashiers; c++)
            {
                sectionAssigned[c] = -1;
                while (next < SectionOrder.Length)
                {
                    int r = SectionOrder[next++];
                    if (IsActive(registerActive, r))
                    {
                        sectionAssigned[c] = r;
                        break;
                    }
                }
            }
            next = 0;
            for (int c = 0; c < cashiers; c++)
            {
                assigned[c] = -1;
                while (next < RegisterOrder.Length)
                {
                    int r = RegisterOrder[next++];
                    if (IsActive(registerActive, r) && !Taken(sectionAssigned, sectionCashiers, r))
                    {
                        assigned[c] = r;
                        break;
                    }
                }
            }
        }

        /// <summary>Cashiers only (no section cashiers).</summary>
        public static void AssignCashiers(IReadOnlyList<bool> registerActive, int cashiers, int[] assigned) =>
            AssignStaff(registerActive, 0, Array.Empty<int>(), cashiers, assigned);

        static bool IsActive(IReadOnlyList<bool> registerActive, int r) => r < registerActive.Count && registerActive[r];

        static bool Taken(int[] assigned, int count, int r)
        {
            for (int i = 0; i < count; i++)
                if (assigned[i] == r) return true;
            return false;
        }
    }

    /// <summary>Prototype <c>updMiner</c> decisions: which rock to dig and the way through the factory gap.</summary>
    public static class MinerRules
    {
        /// <summary>Clay when the Plumbing input is no fuller (by ratio) than the Materials input, else iron.</summary>
        public static ItemType ChooseResource(IPile clayInput, IPile ironInput)
        {
            if (clayInput == null) return ItemType.Iron;
            if (ironInput == null) return ItemType.Clay;
            return Fill(clayInput) <= Fill(ironInput) ? ItemType.Clay : ItemType.Iron;
        }

        static float Fill(IPile p) => p.Capacity > 0 ? (float)p.Settled / p.Capacity : 1f;

        /// <summary>Is a proto z inside the mines yard (north of the yard edge)?</summary>
        public static bool InYard(float protoZ, WorldLayout.WorkerLayoutSettings s) => protoZ <= s.minesYardEdgeZ;

        /// <summary>Way-points (Unity space) into the yard (front → back) or out of it (back → front).</summary>
        public static void GapWay(bool intoYard, WorldLayout.WorkerLayoutSettings s, List<Vector3> into)
        {
            into.Clear();
            Vector3 front = ProtoCoords.ToUnity(s.minerGapFront), back = ProtoCoords.ToUnity(s.minerGapBack);
            into.Add(intoYard ? front : back);
            into.Add(intoYard ? back : front);
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
