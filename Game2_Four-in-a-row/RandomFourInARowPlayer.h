//
// Created by Mohamed Rabea Mohamed Ali on 12/12/2023.
//
#ifndef _RANDOM_FOUR_IN_A_ROW_PLAYER_H
#define _RANDOM_FOUR_IN_A_ROW_PLAYER_H

#include "FourInARowPlayer.h"

class RandomFourInARowPlayer : public FourInARowPlayer {
public:
    RandomFourInARowPlayer(char symbol);
    void get_move(int& x, int& y) override;
};

#endif
