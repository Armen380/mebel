using FF.Save;
using UnityEditor;
using UnityEngine;

namespace FF.Editor
{
    /// <summary>Editor helpers for the save file.</summary>
    public static class SaveMenu
    {
        [MenuItem("FF/Delete Save", priority = 100)]
        static void DeleteSave()
        {
            SaveService.Delete(SaveService.DefaultPath);
            Debug.Log($"[FF] Save deleted: {SaveService.DefaultPath}");
        }

        [MenuItem("FF/Reveal Save Folder", priority = 101)]
        static void Reveal() => EditorUtility.RevealInFinder(Application.persistentDataPath);
    }
}
