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
                transform.position = new Vector3(StartPos.x + 4.7f, StartPos.y + 4.2f, StartPos.z);
                break;
            case 2:
                transform.position = new Vector3(StartPos.x - 5.3f, StartPos.y + 3.6f, StartPos.z);
                break;
            case 3:
                transform.position = new Vector3(StartPos.x - 2.5f, StartPos.y + 4.2f, StartPos.z);
                break;
        }
        
    }
}
