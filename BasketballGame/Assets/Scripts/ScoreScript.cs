using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreScript : MonoBehaviour
{
    private int playerScore = 0;
    private int cpuScore = 0;
    Text score;
    public GameObject scoreObj;
    public GameObject WinText;
    public GameObject LoseText;
    public GameObject RestartB;
    public GameObject Actions;
    public GameObject Names;
    public Text FinalScoreText;
    public GameObject FinalScore;

    public int PlayerScore { get => playerScore; set => playerScore = value; }
    public int CPUScore { get => cpuScore; set => cpuScore = value; }

    public void shoot3 (bool isPlayer)
    {
        if (isPlayer)
            playerScore += 3;
        else
            cpuScore += 3;
    }

    public void shoot2(bool isPlayer)
    {
        if (isPlayer)
            playerScore += 2;
        else
            cpuScore += 2;
    }

    // Start is called before the first frame update
    void Start()
    {
        score = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        score.text = PlayerScore + " - " + cpuScore;
        if (PlayerScore >= 21)
        {
            FinalScoreText.text = score.text;
            WinText.SetActive(true);
            RestartB.SetActive(true);
            Actions.SetActive(false);
            Names.SetActive(false);
            scoreObj.SetActive(false);
            FinalScore.SetActive(true);
        }
        if (CPUScore >= 21)
        {
            FinalScoreText.text = score.text;
            LoseText.SetActive(true);
            RestartB.SetActive(true);
            Actions.SetActive(false);
            Names.SetActive(false);
            scoreObj.SetActive(false);
            FinalScore.SetActive(true);
        }
    }
}
