using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Players : MonoBehaviour
{

    public playerData center = new playerData();
    public playerData left = new playerData();
    public playerData right = new playerData();
    public playerData post = new playerData();
    public playerData centerCPU = new playerData();
    public playerData leftCPU = new playerData();
    public playerData rightCPU = new playerData();
    public playerData postCPU = new playerData();

    public Text COName;
    public Text LOName;
    public Text ROName;
    public Text POName;
    public Text CDName;
    public Text LDName;
    public Text RDName;
    public Text PDName;

    // Start is called before the first frame update
    void Start()
    {
        //Debug.Log("GameHandler.Start");
        allPlayers all = new allPlayers();

        string json = File.ReadAllText("Assets/players.json");
        all = JsonUtility.FromJson<allPlayers>(json);
        center = all.players[0];
        left = all.players[1];
        right = all.players[2];
        post = all.players[3];
        centerCPU = all.players[4];
        leftCPU = all.players[5];
        rightCPU = all.players[6];
        postCPU = all.players[7];

        COName.text = center.name;
        LOName.text = left.name;
        ROName.text = right.name;
        POName.text = post.name;
        CDName.text = centerCPU.name;
        LDName.text = leftCPU.name;
        RDName.text = rightCPU.name;
        PDName.text = postCPU.name;
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
