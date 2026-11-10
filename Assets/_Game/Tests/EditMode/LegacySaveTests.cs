using System.IO;
using FF.Save;
using NUnit.Framework;

namespace FF.Tests
{
    /// <summary>1.0.1 fix: the pre-rename desktop save is brought over once, so "New game" really starts over.</summary>
    public sealed class LegacySaveTests
    {
        string _dir;

        [SetUp]
        public void SetUp()
        {
            _dir = Path.Combine(Path.GetTempPath(), "ff-legacy-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(Path.Combine(_dir, "old"));
        }

        [TearDown]
        public void TearDown()
        {
            if (Directory.Exists(_dir)) Directory.Delete(_dir, true);
        }

        [Test]
        public void CopiesOnce_ThenNewGameStaysNew()
        {
            string legacy = Path.Combine(_dir, "old", "save.json");
            string target = Path.Combine(_dir, "new", "save.json");
            File.WriteAllText(legacy, "{\"level\":983}");

            Assert.IsTrue(SaveService.MigrateLegacy(legacy, target));
            Assert.AreEqual("{\"level\":983}", File.ReadAllText(target));
            Assert.IsFalse(File.Exists(legacy), "old file renamed");
            Assert.IsTrue(File.Exists(Path.Combine(_dir, "old", "save.migrated.json")));

            File.Delete(target); // "New game"
            Assert.IsFalse(SaveService.MigrateLegacy(legacy, target));
            Assert.IsFalse(File.Exists(target));
        }

        [Test]
        public void NeverOverwritesAnExistingSave()
        {
            string legacy = Path.Combine(_dir, "old", "save.json");
            string target = Path.Combine(_dir, "save.json");
            File.WriteAllText(legacy, "old");
            File.WriteAllText(target, "current");
            Assert.IsFalse(SaveService.MigrateLegacy(legacy, target));
            Assert.AreEqual("current", File.ReadAllText(target));
            Assert.IsTrue(File.Exists(legacy));
        }
    }
}
