using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneMngr : MonoBehaviour {

    public void SceneChange(string sceneName)
    {
        //Debug.Log("Cambiando a " + sceneName);
        SceneManager.LoadScene(sceneName);
    }

    public void ExitGame()
    {
        //Debug.Log("Saliendo de juego");
        Application.Quit();
    }
}
