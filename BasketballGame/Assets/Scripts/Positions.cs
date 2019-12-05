using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Positions : MonoBehaviour
{
    Vector3 StartPos;
    public int current;

    void Start()
    {
        StartPos = transform.position;
    }

    public void ChangePos(int pos)
    {
        current = pos;
        switch (pos)
        {
            case 0:
                transform.position = new Vector3(StartPos.x, StartPos.y, StartPos.z);               
                break;
            case 1:
                transform.position = new Vector3(StartPos.x + 6f, StartPos.y + 5.5f, StartPos.z);

                break;
            case 2:
                transform.position = new Vector3(StartPos.x - 6.8f, StartPos.y + 4.6f, StartPos.z);
                break;
            case 3:
                transform.position = new Vector3(StartPos.x - 3f, StartPos.y + 5.5f, StartPos.z);
                break;
        }
        
    }
}
