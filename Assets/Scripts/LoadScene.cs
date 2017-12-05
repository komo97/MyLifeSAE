using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System.IO;
using UnityEngine.UI;


public class LoadScene : MonoBehaviour {


    [DllImport("LuaUnity", EntryPoint = "Load")]
    public static extern int Load(string a);

    [DllImport("LuaUnity", EntryPoint = "GetPage")]
    public static extern System.IntPtr GetPage(int nPage,int idText);

    [DllImport("LuaUnity", EntryPoint = "GetPageNum")]
    public static extern int GetPageNum();

    [DllImport("LuaUnity", EntryPoint = "GetPageNumTexts")]
    public static extern int GetPageNumTexts(int nPage);



    void Start () {
        //    Load("Level1.lua");
        Debug.Log(Load("c:/Level1.lua"));
        HistoryManager.texts = new string[GetPageNumTexts(1)];
        for (int i = 0; i < GetPageNumTexts(1); i++)
        {
            Debug.Log(GetPageNum());
            Debug.Log(Marshal.PtrToStringAnsi(GetPage(1, i)));
            HistoryManager.texts[i] = Marshal.PtrToStringAnsi(GetPage(1, i));
        }
        StartCoroutine(HistoryManager.showText(HistoryManager.texts));
    }
	
	// Update is called once per frame
	void Update () {
    }






}
