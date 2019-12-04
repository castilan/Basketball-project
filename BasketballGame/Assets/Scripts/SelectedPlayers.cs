using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class SelectedPlayers
{

    private static int center = 0;
    private static int left = 4;
    private static int right = 8;
    private static int post = 11;

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

