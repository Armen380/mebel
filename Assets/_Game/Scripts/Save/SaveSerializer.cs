using System;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace FF.Save
{
    /// <summary>JSON text ↔ <see cref="SaveData"/> with a version field and a migration step per old version.</summary>
    public static class SaveSerializer
    {
        public static string ToJson(SaveData data)
        {
            data.version = SaveData.CurrentVersion;
            return JsonConvert.SerializeObject(data, Formatting.Indented);
        }

        /// <exception cref="FormatException">The text is not a save file.</exception>
        public static SaveData FromJson(string json)
        {
            JObject root;
            try
            {
                root = JObject.Parse(json);
            }
            catch (JsonException e)
            {
                throw new FormatException("Save file is not valid JSON.", e);
            }
            Migrate(root);
            SaveData data = root.ToObject<SaveData>() ?? throw new FormatException("Save file is empty.");
            data.version = SaveData.CurrentVersion;
            return data;
        }

        /// <summary>Upgrades older layouts in place. The prototype renamed pad <c>reg2</c> to <c>reg</c>.</summary>
        static void Migrate(JObject root)
        {
            if (root["pads"] is JObject pads && pads["reg2"] != null && pads["reg"] == null)
            {
                pads["reg"] = pads["reg2"];
                pads.Remove("reg2");
            }
            // v4 → v5 (M10): no field changes; a missing "home" deserializes to an empty HomeSave.
            if (root["home"] is JValue) root.Remove("home");
        }
    }
}
