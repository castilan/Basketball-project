#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {
    public:
        Player();
        ~Player();
        void printPlayer();
        string GetName() {return name;}
        void SetName(string stat) {name = stat;}
        int GetShooting() {return shooting;}
        void SetShooting(int stat) {shooting = stat;}
        int GetShotContest() {return shotContest;}
        void SetShotContest(int stat) {shotContest = stat;}
        int GetSpeed() {return speed;}
        void SetSpeed(int stat) {speed = stat;}
        int GetLateralQuickness() {return lateralQuickness;}
        void SetLateralQuickness(int stat) {lateralQuickness = stat;}
        int GetPassing() {return passing;}
        void SetPassing(int stat) {passing = stat;}
        int GetSteal() {return steal;}
        void SetSteal(int stat) {steal = stat;}
        int GetBallHandle() {return ballHandle;}
        void SetBallHandle(int stat) {ballHandle = stat;}
        int GetPerimeterD() {return perimeterD;}
        void SetPerimeterD(int stat) {perimeterD = stat;}
        int GetDriving() {return driving;}
        void SetDriving(int stat) {driving = stat;}
        int GetPostShooting() {return postShooting;}
        void SetPostShooting(int stat) {postShooting = stat;}
        int GetBlock() {return block;}
        void SetBlock(int stat) {block = stat;}
        int GetPostHandle() {return postHandle;}
        void SetPostHandle(int stat) {postHandle = stat;}
        int GetPostD() {return postD;}
        void SetPostD(int stat) {postD = stat;}
        int GetRebounding() {return rebounding;}
        void SetRebounding(int stat) {rebounding = stat;}
    private:
        string name;
        int shooting; //shoot 3
        int shotContest;
        int speed; //drive to basket
        int lateralQuickness;
        int passing; //pass to teammate
        int steal;
        int ballHandle; // cross opponent
        int perimeterD;
        int driving;
        int postShooting;
        int block;
        int postHandle;
        int postD;
        int rebounding;
};

#endif