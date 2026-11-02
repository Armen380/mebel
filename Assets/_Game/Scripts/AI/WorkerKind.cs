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
    }

    public static class WorkerKinds
    {
        public static readonly WorkerKind[] All =
        {
            WorkerKind.Lumber, WorkerKind.Carrier, WorkerKind.Robot, WorkerKind.Cashier, WorkerKind.Stocker,
            WorkerKind.Manager, WorkerKind.Consultant,
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
