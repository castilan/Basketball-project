#include <iostream>
#include "dynamicarray.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#include "player.h"

Game::Game() {
    score[0] = 0;
    score[1] = 0;
}

Game::Game(vector<Player>& teamA, vector<Player>& teamB, string name) {
    score[0] = 0;
    score[1] = 0;
    this->teamA = teamA;
    this->teamB = teamB;
    this->teamAName = name;
    this->teamBName = "OPPONENT";
}

Game::~Game() {

}

void Game::playPossession() {

}

bool contestedOutcome(int statA, int statB) {
    int affectA = statA;
    int affectB = statB;
    int total = affectB - affectA;
    int chance;
    if(total < 1) {total = 1;}
    srand(time(0));
    chance = rand()%99 + 1;
    if(chance <= total) {return true;}
    return false;
}

bool openOutcome(int statA, int statB) {
    int affectA = statA;
    int affectB = statB/3;
    int total = affectA - affectB;
    int chance;
    srand(time(0));
    chance = rand()%99 + 1;
    if(chance <= total) {return true;}
    return false;
}

bool jumpBall(int statA, int statB) {
    int total = statA + statB;
    srand(time(0));
    int chance = rand() % total + 1;
    if(chance <= statA) {return true;}
    return false;
}

void Game::playGame() {
    cout << BOLDYELLOW << "JUMP BALL" << RESET << endl;
    bool possession = jumpBall(teamA.at(3).GetRebounding(), teamB.at(3).GetRebounding());
    if(possession) {cout << "Jump Ball Won" << endl;}
    int current = 0;
    string choice;
    while(score[0] < 21 && score[1] < 21) {
        cout << this->teamAName << ": " << score[0] << "   " << this->teamBName << ": " << score[1] << endl;
        if(possession) {
            cout << "A. Shoot 3          X. Drive" << endl;
            cout << "B. Crossover        Y. Pass" << endl;
            getline(cin, choice);
            if(choice == "A") {
                srand(time(0));
                if(rand() % 100 > 25) {
                    if(openOutcome(teamA.at(current).GetShooting(), teamB.at(current).GetShotContest())) {score[0] = score[0] + 3;}
                }
                else
                    if(contestedOutcome(teamA.at(current).GetShooting(), teamB.at(current).GetShotContest())) {score[0] = score[0] + 3;}
            }
        }

        else {
            cout << "A. Contest 3        X. Defend Drive" << endl;
            cout << "B. Guard Perimeter  Y. Intercept Pass" << endl;
            getline(cin, choice);
        }
    }
}