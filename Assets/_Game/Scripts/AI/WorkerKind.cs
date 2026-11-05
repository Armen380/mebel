namespace FF.AI
{
    /// <summary>Worker types hired in the Upgrades panel (prototype <c>WORKER_SKIN</c> keys).</summary>
    public enum WorkerKind
    {
        Lumber,
        Carrier,
        Robot,
        Cashier,
        Stocker,
        Manager,
        Consultant,
        /// <summary>Digs clay / iron for the Plumbing and Building materials factories (M8).</summary>
        Miner,
        /// <summary>Carries only plumbing and building materials (M8).</summary>
        SectionCarrier,
        /// <summary>Works only the materials-shop registers (M8).</summary>
        SectionCashier,
    }

    public static class WorkerKinds
    {
        public static readonly WorkerKind[] All =
        {
            WorkerKind.Lumber, WorkerKind.Carrier, WorkerKind.Robot, WorkerKind.Cashier, WorkerKind.Stocker,
            WorkerKind.Manager, WorkerKind.Consultant, WorkerKind.Miner, WorkerKind.SectionCarrier, WorkerKind.SectionCashier,
        };

        /// <summary>Upgrade id in upgrades.json; one worker per level.</summary>
        public static string UpgradeId(WorkerKind kind)
        {
            switch (kind)
            {
                case WorkerKind.Lumber: return "lumber";
                case WorkerKind.Carrier: return "carrier";
                case WorkerKind.Robot: return "robot";
                case WorkerKind.Cashier: return "cashier";
                case WorkerKind.Stocker: return "stocker";
                case WorkerKind.Manager: return "manager";
                case WorkerKind.Miner: return "miner";
                case WorkerKind.SectionCarrier: return "secCarrier";
                case WorkerKind.SectionCashier: return "secCashier";
                default: return "consult";
            }
        }

        public static bool TryFromUpgrade(string upgradeId, out WorkerKind kind)
        {
            foreach (WorkerKind k in All)
                if (UpgradeId(k) == upgradeId)
                {
                    kind = k;
                    return true;
                }
            kind = default;
            return false;
        }
    }
}
