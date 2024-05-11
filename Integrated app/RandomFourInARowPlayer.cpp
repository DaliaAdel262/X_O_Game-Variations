//
// Created by Mohamed Rabea Mohamed Ali on 12/12/2023.
//


#include <iostream>
#include <string>
#include "BoardGame_Classes.hpp"
using namespace std;


RandomFourInARowPlayer::RandomFourInARowPlayer(char symbol) : FourInARowPlayer(symbol) {
    this->name = "Random Computer Player";
}

void RandomFourInARowPlayer::get_move(int& x, int& y) {
    // Implement logic to generate a random move for Four-in-a-row
    // Ensure the move is valid (i.e., the selected column is not full)
}

