#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include<stdio.h>

#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */

#include "dynamicarray.h"
#include "player.h"

using namespace std;

const int SIZE = 12;

void setStats(Player& player, int stats[14]) {
    player.SetShooting(stats[0]);
    player.SetShotContest(stats[1]);
    player.SetSpeed(stats[2]);
    player.SetLateralQuickness(stats[3]);
    player.SetPassing(stats[4]);
    player.SetSteal(stats[5]);
    player.SetBallHandle(stats[6]);
    player.SetPerimeterD(stats[7]);
    player.SetDriving(stats[8]);
    player.SetPostShooting(stats[9]);
    player.SetBlock(stats[10]);
    player.SetPostHandle(stats[11]);
    player.SetPostD(stats[12]);
    player.SetRebounding(stats[13]);
}

bool getStats1(string name, Player& player) {
    if(name == "sidney moncrief") {
        player.SetName("Sidney Moncrief");
        int stats[] = {75, 98, 88, 96, 80, 96, 86, 98, 82, 30, 60, 30, 70, 30};
        setStats(player, stats);
        return true;
    }
    if(name == "mark price") {
        player.SetName("Mark Price");
        int stats[] = {97, 75, 80, 70, 92, 70, 92, 75, 70, 65, 30, 30, 35, 40};
        setStats(player, stats);
        return true;
    }
    if(name == "derrick rose") {
        player.SetName("Derrick Rose");
        int stats[] = {78, 78, 96, 80, 86, 70, 90, 76, 97, 30, 70, 30, 35, 50};
        setStats(player, stats);
        return true;
    }
    return false;
}

bool getStats2(string name, Player& player) {\
    if(name == "ron artest") {
        player.SetName("Ron Artest");
        int stats[] = {80, 97, 80, 92, 70, 94, 70, 96, 80, 30, 70, 60, 80, 65};
        setStats(player, stats);
        return true;
    }
    if(name == "tracy mcgrady") {
        player.SetName("Tracy McGrady");
        int stats[] = {86, 76, 90, 70, 80, 70, 86, 70, 95, 70, 85, 70, 40, 50};
        setStats(player, stats);
        return true;
    }
    if(name == "julius erving") {
        player.SetName("Julius Erving");
        int stats[] = {76, 86, 90, 86, 74, 74, 80, 84, 99, 70, 70, 80, 80, 70};
        setStats(player, stats);
        return true;
    }
    return false;
}

bool getStats3(string name, Player& player) {
    if(name == "scottie pippen") {
        player.SetName("Scottie Pippen");
        int stats[] = {78, 97, 82, 94, 80, 94, 80, 96, 90, 50, 75, 80, 80, 75};
        setStats(player, stats);
        return true;
    }
    if(name == "carmelo anthony") {
        player.SetName("Carmelo Anthony");
        int stats[] = {92, 78, 86, 76, 70, 70, 86, 76, 88, 90, 45, 80, 70, 60};
        setStats(player, stats);
        return true;
    }
    if(name == "glen rice") {
        player.SetName("Glen Rice");
        int stats[] = {97, 80, 80, 75, 75, 75, 80, 78, 70, 75, 50, 70, 75, 40};
        setStats(player, stats);
        return true;
    }
    return false;
}

bool getStats4(string name, Player& player) {
    if(name == "alonzo mourning") {
        player.SetName("Alonzo Mourning");
        int stats[] = {70, 90, 70, 75, 70, 85, 30, 80, 75, 80, 99, 80, 99, 95};
        setStats(player, stats);
        return true;
    }
    if(name == "dirk nowitzki") {
        player.SetName("Dirk Nowitzki");
        int stats[] = {90, 76, 60, 45, 80, 40, 70, 55, 60, 99, 80, 88, 82, 86};
        setStats(player, stats);
        return true;
    }
    if(name == "shaquille o'neal") {
        player.SetName("Shaquille O'Neal");
        int stats[] = {50, 88, 85, 70, 70, 65, 60, 70, 90, 50, 89, 99, 90, 96};
        setStats(player, stats);
        return true;
    }
    return false;
}

string lowerWord(string word) {
    int length = word.length();
    string lower;
    char temp;
    for(int i = 0; i < length; i++) {
        temp = tolower(word.at(i));
        lower = lower + temp;
    }
    return lower;
}

void selectPlayers(vector<Player>& players, string names[]) {
    string player1, player2, player3, player4;
    cout << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << names[i];
        if(i%3 == 2) {cout << endl;}
        else {cout << "      ";}
    }
    cout << endl;

    cout << "Select one player from the first row: " << endl;
    getline(cin, player1);
    while(!getStats1(lowerWord(player1), players.at(0))) {
        cout << "Invalid selection. Please try again." << endl;
        getline(cin, player1);
    }

    cout << "Select one player from the second row: " << endl;
    getline(cin, player2);
    while(!getStats2(lowerWord(player2), players.at(1))) {
        cout << "Invalid selection. Please try again." << endl;
        getline(cin, player2);
    }

    cout << "Select one player from the third row: " << endl;
    getline(cin, player3);
    while(!getStats3(lowerWord(player3), players.at(2))) {
        cout << "Invalid selection. Please try again." << endl;
        getline(cin, player3);
    }

    cout << "Select one player from the fourth row: " << endl;
    getline(cin, player4);
    while(!getStats4(lowerWord(player4), players.at(3))) {
        cout << "Invalid selection. Please try again." << endl;
        getline(cin, player4);
    }

}

void setAIPlayers(vector<Player>& team) {
    srand(time(0));
    string choices [] = {"Sidney Moncrief", "Mark Price", "Derrick Rose", "Ron Artest", "Tracy McGrady", "Julius Erving", "Scottie Pippen", "Carmelo Anthony", "Glen Rice", "Alonzo Mourning", "Dirk Nowitzki", "Shaquille O'Neal"};
    int temp = rand()%3;
    getStats1(lowerWord(choices[temp]), team.at(0));
    temp = rand()%3 + 3;
    getStats2(lowerWord(choices[temp]), team.at(1));
    temp = rand()%3 + 6;
    getStats3(lowerWord(choices[temp]), team.at(2));
    temp = rand()%3 + 9;
    getStats4(lowerWord(choices[temp]), team.at(3));
}

void printPlayers(vector<Player> players) {
    for(int i = 0; i < 4; i++) {
        players.at(i).printPlayer();
    }
}

void statColors(int stat) {
    if(stat >= 90) {cout << BOLDGREEN << stat << RESET; return;}
    if(stat >= 80) {cout << GREEN << stat << RESET; return;}
    if(stat >= 70) {cout << BOLDYELLOW << stat << RESET; return;}
    if(stat >= 60) {cout << YELLOW << stat << RESET; return;}
    if(stat < 60) {cout <<  RED << stat << RESET; return;}
}

void comparePlayer(Player player1, Player player2) {
    int difference;
    cout << endl;
    cout << YELLOW << "PLAYER COMPARISON:  " << BLUE << player1.GetName() << RESET << " vs " << RED << player2.GetName() << RESET << endl;

    cout << "  Shooting:          "; statColors(player1.GetShooting()); cout << "  ";
    difference = player2.GetShooting() - player1.GetShooting(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetShooting()); cout << endl;

    cout << "  Driving:           "; statColors(player1.GetDriving()); cout << "  ";
    difference = player2.GetDriving() - player1.GetDriving(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetDriving()); cout << endl;

    cout << "  Ball Handle:       "; statColors(player1.GetBallHandle()); cout << "  ";
    difference = player2.GetBallHandle() - player1.GetBallHandle(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetBallHandle()); cout << endl;

    cout << "  Passing:           "; statColors(player1.GetPassing()); cout << "  ";
    difference = player2.GetPassing() - player1.GetPassing(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetPassing()); cout << endl;

    cout << "  Speed:             "; statColors(player1.GetSpeed()); cout << "  ";
    difference = player2.GetSpeed() - player1.GetSpeed(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetSpeed()); cout << endl;

    cout << "  Post Handle:       "; statColors(player1.GetPostHandle()); cout << "  ";
    difference = player2.GetPostHandle() - player1.GetPostHandle(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetPostHandle()); cout << endl;

    cout << "  Post Shooting:     "; statColors(player1.GetPostShooting()); cout << "  ";
    difference = player2.GetPostShooting() - player1.GetPostShooting(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetPostShooting()); cout << endl;

    cout << "  Shot Contest:      "; statColors(player1.GetShotContest()); cout << "  ";
    difference = player2.GetShotContest() - player1.GetShotContest(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetShotContest()); cout << endl;

    cout << "  Lateral Quickness: "; statColors(player1.GetLateralQuickness()); cout << "  ";
    difference = player2.GetLateralQuickness() - player1.GetLateralQuickness(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetLateralQuickness()); cout << endl;

    cout << "  Perimeter D:       "; statColors(player1.GetPerimeterD()); cout << "  ";
    difference = player2.GetPerimeterD() - player1.GetPerimeterD(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetPerimeterD()); cout << endl;

    cout << "  Steal:             "; statColors(player1.GetSteal()); cout << "  ";
    difference = player2.GetSteal() - player1.GetSteal(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetSteal()); cout << endl;

    cout << "  Post D:            "; statColors(player1.GetPostD()); cout << "  ";
    difference = player2.GetPostD() - player1.GetPostD(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetPostD()); cout << endl;

    cout << "  Block:             "; statColors(player1.GetBlock()); cout << "  ";
    difference = player2.GetBlock() - player1.GetBlock(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetBlock()); cout << endl;

    cout << "  Rebounding:        "; statColors(player1.GetRebounding()); cout << "  ";
    difference = player2.GetRebounding() - player1.GetRebounding(); if(difference > 0) {cout << GREEN << "+" << difference << RESET;} else if(difference < 0){cout << RED << difference << RESET;} else {cout << " " << difference;}
    cout << "  "; statColors(player2.GetRebounding()); cout << endl;
}

int main( ) {

    string teamName;
    int tempInt = 6;
    string choices;
    string tempString;
    cout << endl;
    cout << BOLDYELLOW << "NBA 2K MOBILE" << RESET << endl;
    cout << endl;
    cout << "Enter a team name" << endl;
    getline(cin, teamName);
    cout << endl;
    //cout << "Tip: Enter all names and choices with proper capitalization" << endl;
    string names [] = {"'83 Sidney Moncrief - Bucks", "'93 Mark Price - Cavs", "'11 Derrick Rose - Bulls", "'04 Ron Artest - Pacers", "'00 Tracy McGrady - Raptors", "'76 Julius Erving - Nets", "'96 Scottie Pippen - Bulls", "'13 Carmelo Anthony - Knicks", "'95 Glen Rice - Hornets", "'99 Alonzo Mourning - Heat", "'05 Dirk Nowitzki - Mavs", "'95 Shaquille O'Neal - Magic" };
    vector<Player> players(4);
    vector<Player> AI(4);
    setAIPlayers(AI);
    selectPlayers(players, names);
    cout << endl;
    cout << BOLDBLUE << teamName << RESET << endl;
    printPlayers(players);
    cout << endl;
    cout << BOLDRED << "OPPONENT" << RESET << endl;
    printPlayers(AI);
    cout << endl;
    cout << "Would you like to:  " << "Compare player or Continue" << endl;
    getline(cin, choices);
    while(lowerWord(choices) != "continue" && lowerWord(choices) != "compare player") {
        cout << "INVALID CHOICE" << endl;
        getline(cin, choices);
    }
    while(lowerWord(choices) != "continue") {
        cout << "Enter a player from your team to compare" << endl;
        //cin >> tempInt;
        getline(cin, tempString);
        for(int i = 0; i < 4; i++) {
            if(lowerWord(players.at(i).GetName()) == lowerWord(tempString)) {tempInt = i;}
        }
        //tempInt = tempInt - 1;
        while(tempInt == 6) {
            cout << "INVALID PLAYER" << endl;
            getline(cin, tempString);
            for(int i = 0; i < 4; i++) {
                if(lowerWord(players.at(i).GetName()) == lowerWord(tempString)) {tempInt = i;}
            }
        }
        comparePlayer(players.at(tempInt), AI.at(tempInt));
        cout << endl;
        cout << "Would you like to:  " << "Compare player or Continue" << endl;
        getline(cin, choices);
        while(lowerWord(choices) != "continue" && lowerWord(choices) != "compare player") {
            cout << "INVALID CHOICE" << endl;
            getline(cin, choices);
        }
    }
    Game game = Game(players, AI, teamName);
    game.playGame();
}