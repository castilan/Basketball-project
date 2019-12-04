using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Positions : MonoBehaviour
{
    Vector3 StartPos;

    void Start()
    {
        StartPos = transform.position;
    }

    public void ChangePos(int pos)
    {
        switch(pos)
        {
            case 0:
                transform.position = new Vector3(StartPos.x, StartPos.y, StartPos.z);
                break;
            case 1:
                transform.position = new Vector3(StartPos.x + 4f, StartPos.y + 3.6f, StartPos.z);
                break;
            case 2:
                transform.position = new Vector3(StartPos.x - 4.4f, StartPos.y + 3f, StartPos.z);
                break;
            case 3:
                transform.position = new Vector3(StartPos.x - 2f, StartPos.y + 3.6f, StartPos.z);
                break;
        }
        
    }
}
