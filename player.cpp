#include <iostream>
#include "player.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

using namespace std;

Player::Player() {
    name = "none";
    shooting = 0; //o
    shotContest = 0;
    speed = 0; //0
    lateralQuickness = 0;
    passing = 0; //o
    steal = 0;
    ballHandle = 0; //o
    perimeterD = 0;
    driving = 0; //0
    postShooting = 0; //o
    block = 0;
    postHandle = 0; //0
    postD = 0;
    rebounding = 0;

}

Player::~Player() {

}

void statColor(int stat) {
    if(stat >= 90) {cout << BOLDGREEN << stat << RESET; return;}
    if(stat >= 80) {cout << GREEN << stat << RESET; return;}
    if(stat >= 70) {cout << BOLDYELLOW << stat << RESET; return;}
    if(stat >= 60) {cout << YELLOW << stat << RESET; return;}
    if(stat < 60) {cout <<  RED << stat << RESET; return;}
}

void Player::printPlayer() {
    cout << this->GetName() << endl;
    cout << "  Shooting: "; statColor(this->GetShooting()); cout << "   Driving: "; statColor(this->GetDriving());
    cout << "   Ball Handle: "; statColor(this->GetBallHandle()); cout << "   Passing: "; statColor(this->GetPassing());
    cout << "   Speed: ";  statColor(this->GetSpeed()); cout << "   Post Handle: ";  statColor(this->GetPostHandle());
    cout << "   Post Shooting: "; statColor(this->GetPostShooting()); cout << endl;
    cout << "  Shot Contest: "; statColor(this->GetShotContest()); cout << "   Lateral Quickness: "; statColor(this->GetLateralQuickness());
    cout << "   Perimeter D: "; statColor(this->GetPerimeterD()); cout << "   Steal: "; statColor(this->GetSteal());
    cout << "   Post D: "; statColor(this->GetPostD()); cout << "   Block: "; statColor(this->GetBlock());
    cout << "   Rebounding: "; statColor(this->GetRebounding()); cout << endl;
}

#define BLACK   "\033[30m"      /* Black */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"