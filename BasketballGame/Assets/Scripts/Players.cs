using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Players : MonoBehaviour
{

    playerData center = new playerData();
    playerData left = new playerData();
    playerData right = new playerData();
    playerData post = new playerData();
    playerData centerCPU = new playerData();
    playerData leftCPU = new playerData();
    playerData rightCPU = new playerData();
    playerData postCPU = new playerData();

    public Text COName;
    public Text LOName;
    public Text ROName;
    public Text POName;
    public Text CDName;
    public Text LDName;
    public Text RDName;
    public Text PDName;

    public TextAsset jsonFile;

    public ScoreScript score;
    public Positions pos;
    public GameObject offense;
    public GameObject defense;

    public GameObject centerO;
    public GameObject leftO;
    public GameObject rightO;
    public GameObject postO;
    public GameObject centerD;
    public GameObject leftD;
    public GameObject rightD;
    public GameObject postD;

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
        centerCPU = all.players[2];
        leftCPU = all.players[5];
        rightCPU = all.players[7];
        postCPU = all.players[10];
    }

    void swapPos(GameObject one, GameObject two)
    {
        Vector3 temp = one.transform.position;
        one.transform.position = two.transform.position;
        two.transform.position = temp;
    }

    // Update is called once per frame
    void Update()
    {
        COName.text = center.initialname;
        LOName.text = left.initialname;
        ROName.text = right.initialname;
        POName.text = post.initialname;
        CDName.text = centerCPU.initialname;
        LDName.text = leftCPU.initialname;
        RDName.text = rightCPU.initialname;
        PDName.text = postCPU.initialname;
    }

    public void SwapSides()
    {
        playerData temp1 = center;
        playerData temp2 = left;
        playerData temp3 = right;
        playerData temp4 = post;
        center = centerCPU;
        left = leftCPU;
        right = rightCPU;
        post = postCPU;
        centerCPU = temp1;
        leftCPU = temp2;
        rightCPU = temp3;
        postCPU = temp4;
        //pos.ChangePos(0);
        
        swapPos(centerO, centerD);
        swapPos(leftO, leftD);
        swapPos(rightO, rightD);
        swapPos(postO, postD);
}

    public void Shoot3(bool isPlayer)
    {
        playerData player1 = new playerData();
        playerData player2 = new playerData();
        switch (pos.current)
        {
            case 0:
                player1 = center;
                player2 = centerCPU;
                break;
            case 1:
                player1 = right;
                player2 = rightCPU;
                break;
            case 2:
                player1 = left;
                player2 = leftCPU;
                break;
            case 3:
                player1 = post;
                player2 = postCPU;
                break;
        }
        if (!isPlayer)
        {
            playerData temp = player1;
            player1 = player2;
            player2 = temp;
        }
        System.Random rng = new System.Random();
        int contest = rng.Next(4);
        int chance = player1.shooting * 2 / 3;
        if (contest==0)
        {
            chance -= player2.shotContest/2;
        }
        if (rng.Next(100) < chance)
        {
            score.shoot3(isPlayer);
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
