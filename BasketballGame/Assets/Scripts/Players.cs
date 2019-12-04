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

    public TextAsset jsonFile;

    // Start is called before the first frame update
    void Start()
    {
        //Debug.Log("GameHandler.Start");
        allPlayers all = new allPlayers();

        string json = jsonFile.text;
        all = JsonUtility.FromJson<allPlayers>(json);
        center = all.players[SelectedPlayers.Center];
        left = all.players[SelectedPlayers.Left];
        right = all.players[SelectedPlayers.Right];
        post = all.players[SelectedPlayers.Post];
        centerCPU = all.players[4];
        leftCPU = all.players[5];
        rightCPU = all.players[6];
        postCPU = all.players[7];

        COName.text = center.initialname;
        LOName.text = left.initialname;
        ROName.text = right.initialname;
        POName.text = post.initialname;
        CDName.text = centerCPU.initialname;
        LDName.text = leftCPU.initialname;
        RDName.text = rightCPU.initialname;
        PDName.text = postCPU.initialname;
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
        public string initialname;
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
