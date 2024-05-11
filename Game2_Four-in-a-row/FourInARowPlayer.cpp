#include "FourInARowPlayer.h"

FourInARowPlayer::FourInARowPlayer(char symbol) : Player(symbol) {
    this->name = "Player";
}

void FourInARowPlayer::get_move(int& x, int& y) {
    cout << "\n" << name << ", please enter your move column (0 to 6): ";
    cin >> y;
    x = 0; // In this game, the row will be determined automatically
}
