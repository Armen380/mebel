using System;
using System.Collections.Generic;

namespace FF.Core
{
    /// <summary>
    /// Minimal service registry filled by the scene installer at startup.
    /// Resolve once (Awake/Start) and cache; never call from per-frame code.
    /// </summary>
    public static class Services
    {
        static readonly Dictionary<Type, object> Registry = new Dictionary<Type, object>();

        public static void Register<T>(T service) where T : class =>
            Registry[typeof(T)] = service ?? throw new ArgumentNullException(nameof(service));

        public static T Get<T>() where T : class =>
            Registry.TryGetValue(typeof(T), out object s)
                ? (T)s
                : throw new InvalidOperationException($"Service {typeof(T).Name} is not registered.");

        public static bool TryGet<T>(out T service) where T : class
        {
            bool found = Registry.TryGetValue(typeof(T), out object s);
            service = found ? (T)s : null;
            return found;
        }

        public static void Clear() => Registry.Clear();
    }
}
