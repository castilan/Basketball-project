using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class SelectedPlayers
{
    private static int center, left, right, post;

    public static int Center
    {
        get
        {
            return center;
        }
        set
        {
            center = value;
        }
    }

    public static int Left
    {
        get
        {
            return left;
        }
        set
        {
            left = value;
        }
    }

    public static int Right
    {
        get
        {
            return right;
        }
        set
        {
            right = value;
        }
    }

    public static int Post
    {
        get
        {
            return post;
        }
        set
        {
            post = value;
        }
    }
}

