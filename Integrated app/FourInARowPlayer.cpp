#include "BoardGame_Classes.hpp"
#include <iostream>
#include <string>
using namespace std;

FourInARowPlayer::FourInARowPlayer(char symbol) : Player(symbol) {
    this->name = "Player";
}

void FourInARowPlayer::get_move(int& x, int& y) {
    user_input:
    cout << "\n" << name << ", please enter your move column (0 to 6): ";
    cin >> y;
    if (y>=0 && y<=6){
        x = 0; // In this game, the row will be determined automatically
    }
    else{
        goto user_input;
    }
}
