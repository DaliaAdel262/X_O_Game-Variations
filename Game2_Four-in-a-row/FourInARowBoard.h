//
// Created by Mohamed Rabea Mohamed Ali on 12/12/2023.
//
#ifndef _FOUR_IN_A_ROW_BOARD_H
#define _FOUR_IN_A_ROW_BOARD_H

#include "BoardGame_Classes (1).h"

class FourInARowBoard : public Board {
public:
    FourInARowBoard();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;

private:
    const int rows = 6;
    const int cols = 7;
};

#endif
