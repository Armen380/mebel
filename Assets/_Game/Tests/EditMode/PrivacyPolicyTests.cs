using FF.Data;
using FF.Editor;
using NUnit.Framework;

namespace FF.Tests
{
    /// <summary>Stores want the privacy policy reachable inside the app (user request 2026-11-09).</summary>
    public sealed class PrivacyPolicyTests
    {
        [Test]
        public void Config_HasPublicHttpsPolicyUrl()
        {
            AdsConfig config = AdsSetup.Config();
            StringAssert.StartsWith("https://", config.privacyPolicyUrl);
        }
    }
}
