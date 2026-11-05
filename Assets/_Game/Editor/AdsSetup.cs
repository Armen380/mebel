using FF.Ads;
using FF.Data;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>Ads system objects for the game scene: AdsConfig asset (keys filled in by the user), initializer, rewarded manager.</summary>
    public static class AdsSetup
    {
        public const string ConfigPath = DataImporter.DataRoot + "/AdsConfig.asset";

        public static AdsConfig Config() => DataImporter.GetOrCreate<AdsConfig>(ConfigPath);

        public static void Build(Transform systems)
        {
            Transform old = systems.Find("Ads");
            if (old != null) Object.DestroyImmediate(old.gameObject);
            var go = new GameObject("Ads");
            go.transform.SetParent(systems, false);
            AdsConfig config = Config();
            go.AddComponent<LevelPlayInitializer>().Setup(config);
            go.AddComponent<RewardedAdManager>().Setup(config);
        }
    }
}
