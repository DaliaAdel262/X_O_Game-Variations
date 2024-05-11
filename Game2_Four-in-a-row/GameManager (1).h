#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

#include "BoardGame_Classes (1).h"

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];

public:
    GameManager(Board* bPtr, Player* playerPtr[2]);
    void run();
};

#endif
