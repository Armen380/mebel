using System.Collections.Generic;
using Newtonsoft.Json.Linq;
using UnityEditor;
using UnityEditor.Localization;
using UnityEngine;
using UnityEngine.Localization;
using UnityEngine.Localization.Settings;
using UnityEngine.Localization.Tables;

namespace FF.Editor
{
    /// <summary>
    /// Builds the Unity Localization setup from Design/data/localization_{hy,en,ru}.json:
    /// locales, one string table collection <see cref="TableName"/>, Smart Strings for "{name}" placeholders,
    /// and the startup selectors (device language, else Armenian).
    /// </summary>
    public static class LocalizationImporter
    {
        public const string TableName = "Game";
        public const string Root = "Assets/_Game/Localization";
        public const string DefaultLocale = "hy";
        public static readonly string[] LocaleCodes = { "hy", "en", "ru" };

        static readonly Dictionary<string, string> LocaleNames = new Dictionary<string, string>
        {
            { "hy", "Armenian (hy)" },
            { "en", "English (en)" },
            { "ru", "Russian (ru)" },
        };

        [MenuItem("FF/Import Localization", priority = 1)]
        public static void Import()
        {
            DataImporter.EnsureFolder(Root + "/Locales");
            DataImporter.EnsureFolder(Root + "/Tables");

            LocalizationSettings settings = EnsureSettings();
            var locales = new List<Locale>();
            foreach (string code in LocaleCodes) locales.Add(EnsureLocale(code));

            LocalizationSettings.ProjectLocale = locales[0];
            ConfigureStartupSelectors(settings);

            StringTableCollection collection = LocalizationEditorSettings.GetStringTableCollection(TableName)
                                               ?? LocalizationEditorSettings.CreateStringTableCollection(TableName, Root + "/Tables", locales);

            int keys = 0;
            foreach (Locale locale in locales)
            {
                var table = (StringTable)(collection.GetTable(locale.Identifier) ?? collection.AddNewTable(locale.Identifier));
                JObject strings = DataImporter.ReadObject($"localization_{locale.Identifier.Code}.json");
                foreach (KeyValuePair<string, JToken> pair in strings)
                {
                    if (collection.SharedData.GetEntry(pair.Key) == null) collection.SharedData.AddKey(pair.Key);
                    string value = (string)pair.Value;
                    StringTableEntry entry = table.AddEntry(pair.Key, value);
                    entry.IsSmart = value.Contains("{");
                }
                keys = Mathf.Max(keys, strings.Count);
                EditorUtility.SetDirty(table);
            }

            EditorUtility.SetDirty(collection.SharedData);
            EditorUtility.SetDirty(collection);
            EditorUtility.SetDirty(settings);
            AssetDatabase.SaveAssets();
            Debug.Log($"[FF] Localization imported: {locales.Count} locales, {keys} keys in table '{TableName}'.");
        }

        static LocalizationSettings EnsureSettings()
        {
            LocalizationSettings settings = LocalizationEditorSettings.ActiveLocalizationSettings;
            if (settings != null) return settings;

            string path = Root + "/LocalizationSettings.asset";
            settings = AssetDatabase.LoadAssetAtPath<LocalizationSettings>(path);
            if (settings == null)
            {
                settings = ScriptableObject.CreateInstance<LocalizationSettings>();
                settings.name = "LocalizationSettings";
                AssetDatabase.CreateAsset(settings, path);
            }
            LocalizationEditorSettings.ActiveLocalizationSettings = settings;
            return settings;
        }

        static Locale EnsureLocale(string code)
        {
            Locale locale = LocalizationEditorSettings.GetLocale(new LocaleIdentifier(code));
            if (locale != null) return locale;

            string path = $"{Root}/Locales/{code}.asset";
            locale = AssetDatabase.LoadAssetAtPath<Locale>(path);
            if (locale == null)
            {
                locale = Locale.CreateLocale(code);
                locale.name = LocaleNames[code];
                locale.LocaleName = LocaleNames[code];
                AssetDatabase.CreateAsset(locale, path);
            }
            LocalizationEditorSettings.AddLocale(locale);
            return locale;
        }

        /// <summary>Command line → device language (if hy/en/ru) → Armenian.</summary>
        static void ConfigureStartupSelectors(LocalizationSettings settings)
        {
            List<IStartupLocaleSelector> selectors = settings.GetStartupLocaleSelectors();
            SpecificLocaleSelector specific = null;
            foreach (IStartupLocaleSelector s in selectors)
                if (s is SpecificLocaleSelector sl) specific = sl;
            if (specific == null)
            {
                specific = new SpecificLocaleSelector();
                selectors.Add(specific);
            }
            specific.LocaleId = new LocaleIdentifier(DefaultLocale);
        }
    }
}
