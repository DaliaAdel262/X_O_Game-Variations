#include "GameManager (1).h"

GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i = 0; i < 2; ++i) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                cout << "Invalid move! Try again.\n";
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();

            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins!\n";
                return;
            }

            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}