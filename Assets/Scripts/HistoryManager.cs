using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HistoryManager : MonoBehaviour {
    private static GameObject canvas;
    private static GameObject text;
    private static GameObject anchorText;
    public int timeWait;
    public int offset;
    public static string[] texts;
    public static float timeText;

    // Use this for initialization
    // Use this for initialization
    void Start() {
        texts = null;
        canvas = GameObject.Find("Canvas");
        text = (GameObject)Resources.Load("TextPrefab");
        anchorText = GameObject.Find("anchorText");
    }

    // Update is called once per frame
    void Update () {
		
	}


    public static IEnumerator textSlow(string x)
    {
        GameObject text = GameObject.Find("Text");
        Text t = text.GetComponent<Text>();
        t.text = "";
        for (int i = 0; i < x.Length; ++i)
        {
            t.text += x[i];
            yield return new WaitForSeconds(timeText);

        }

    }


    public static IEnumerator showText(string [] texts)
    {

            for (int i = 0; i < texts.Length; i++)
            {
                GameObject temp = Instantiate(text, anchorText.transform);
                Text t = temp.GetComponent<Text>();
                t.text = texts[i];
                temp.transform.position = new Vector3(0, -5 * i, 0);
                yield return new WaitForSeconds(3);
            }
    }
}
