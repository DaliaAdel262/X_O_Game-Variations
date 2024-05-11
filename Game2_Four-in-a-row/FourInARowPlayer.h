#ifndef _FOUR_IN_A_ROW_PLAYER_H
#define _FOUR_IN_A_ROW_PLAYER_H

#include "BoardGame_Classes (1).h"

class FourInARowPlayer : public Player {
public:
    FourInARowPlayer(char symbol);
    FourInARowPlayer(int order, char symbol) : Player(order, symbol) {}
    void get_move(int& x, int& y) override;
};

#endif
