#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <vector>
#include <string>

#include "player.h"

using namespace std;

class Game {
   public:
        Game();
        Game(vector<Player>& teamA, vector<Player>& teamB, string name);
        ~Game();
        void playPossession();
        void playGame();

   private:
        int score[2];
        vector<Player> teamA;
        vector<Player> teamB;
        string teamAName;
        string teamBName;
};

#endif