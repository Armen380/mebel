using FF.Editor;
using NUnit.Framework;

namespace FF.Tests.EditMode
{
    public class IosPostBuildTests
    {
        const string Plist =
            "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<plist version=\"1.0\">\n<dict>\n  <key>CFBundleName</key>\n  <string>FF</string>\n</dict>\n</plist>\n";

        [Test]
        public void WithKey_AddsTheKeyInsideTheRootDict()
        {
            string result = IosPostBuild.WithKey(Plist, "ITSAppUsesNonExemptEncryption", "<false/>");
            int key = result.IndexOf("<key>ITSAppUsesNonExemptEncryption</key>", System.StringComparison.Ordinal);
            Assert.That(key, Is.GreaterThan(0));
            Assert.That(result.IndexOf("<false/>", key, System.StringComparison.Ordinal), Is.GreaterThan(key));
            Assert.That(key, Is.LessThan(result.LastIndexOf("</dict>", System.StringComparison.Ordinal)));
        }

        [Test]
        public void WithKey_LeavesAnExistingKeyAlone()
        {
            string once = IosPostBuild.WithKey(Plist, "ITSAppUsesNonExemptEncryption", "<false/>");
            Assert.That(IosPostBuild.WithKey(once, "ITSAppUsesNonExemptEncryption", "<false/>"), Is.EqualTo(once));
        }
    }
}
