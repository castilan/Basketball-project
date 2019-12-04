using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Players : MonoBehaviour
{

    public playerData center = new playerData();
    public playerData left;
    public playerData right;
    public playerData post;
    public playerData centerCPU;
    public playerData leftCPU;
    public playerData rightCPU;
    public playerData postCPU;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GameHandler.Start");
        allPlayers all = new allPlayers();

        string json = File.ReadAllText("Assets/players.json");
        Debug.Log(json);
        all = JsonUtility.FromJson<allPlayers>(json);
        center = all.players[0];
        Debug.Log(center.name);
        //left = all.players[2];

        
    }

    // Update is called once per frame
    void Update()
    {
        
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
