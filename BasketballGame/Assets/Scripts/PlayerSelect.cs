using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerSelect : MonoBehaviour
{
    public playerData displayed = new playerData();
    public Text DisplayName;
    private int current = 0;
    public allPlayers all = new allPlayers();

    // Start is called before the first frame update
    void Start()
    {
        string json = File.ReadAllText("Assets/players.json");
        all = JsonUtility.FromJson<allPlayers>(json);
    }

    // Update is called once per frame
    void Update()
    {
        displayed = all.players[current];
        DisplayName.text = displayed.name;
    }

    public void next()
    {
        current++;
        if (current >= all.players.Length)
        {
            current = 0;
        }
    }

    public void prev()
    {
        current--;
        if (current < 0)
        {
            current = all.players.Length-1;
        }
    }

    [System.Serializable]
    public class allPlayers
    {
        public playerData[] players;
    }

    [System.Serializable]
    public class playerData
    {
        public string name;
        public int shooting;
        public int shotContest;
        public int speed;
        public int lateralQuickness;
        public int passing;
        public int steal;
        public int ballHandle;
        public int perimeterD;
        public int driving;
        public int postShooting;
        public int block;
        public int postHandle;
        public int postD;
        public int rebounding;
    }
}
