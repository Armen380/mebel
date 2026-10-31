namespace FF.Gameplay.Production
{
    /// <summary>
    /// Prototype <c>updMachine</c> batching and timing, without visuals. When idle, starts
    /// k = min(parallel batches, ⌊input/inN⌋, ⌊(outCap − out.n)/outN⌋) batches; when the cycle ends, the
    /// owner spawns k·outN outputs.
    /// </summary>
    public sealed class MachineCore
    {
        public int InputPerCycle { get; }
        public int OutputPerCycle { get; }

        public bool Busy { get; private set; }
        public float Elapsed { get; private set; }
        public int Batch { get; private set; }

        public MachineCore(int inputPerCycle, int outputPerCycle)
        {
            InputPerCycle = inputPerCycle < 1 ? 1 : inputPerCycle;
            OutputPerCycle = outputPerCycle < 1 ? 1 : outputPerCycle;
        }

        /// <summary>Batches the idle machine can start now (0 = cannot start).</summary>
        /// <param name="inputSettled">Items lying in the input pile (in-flight ones do not count).</param>
        /// <param name="outputCount">Output pile count including items flying in.</param>
        public int BatchesAvailable(int inputSettled, int outputCount, int outputCapacity, int parallelBatches)
        {
            if (Busy) return 0;
            int free = outputCapacity - outputCount;
            int room = free >= 0 ? free / OutputPerCycle : -1;
            int k = parallelBatches;
            if (inputSettled / InputPerCycle < k) k = inputSettled / InputPerCycle;
            if (room < k) k = room;
            return k < 1 ? 0 : k;
        }

        /// <summary>Starts <paramref name="batches"/> batches; the owner consumes batches·inN input items.</summary>
        public void Start(int batches)
        {
            Busy = true;
            Elapsed = 0f;
            Batch = batches;
        }

        /// <summary>Advances a busy machine. Returns the number of outputs to spawn when the cycle ends, else 0.</summary>
        /// <param name="cycleSeconds">EconomyConfig.FactoryCycleSeconds(base, speed level), read every frame.</param>
        public int Tick(float dt, float cycleSeconds)
        {
            if (!Busy) return 0;
            Elapsed += dt;
            if (Elapsed < cycleSeconds) return 0;
            Busy = false;
            return Batch * OutputPerCycle;
        }
    }
}
