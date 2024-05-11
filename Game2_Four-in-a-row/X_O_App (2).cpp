#include <iostream>
#include "FourInARowPlayer.h"
#include "RandomFourInARowPlayer.h"
#include "FourInARowBoard.h"
#include "GameManager (1).h"

using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new FourInARowPlayer(1, 'X');

    cout << "Welcome to Four-in-a-row XO Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;

    if (choice != 1)
        players[1] = new FourInARowPlayer(2, 'O');
    else
        players[1] = new RandomFourInARowPlayer('O');

    GameManager four_in_a_row_game(new FourInARowBoard(), players);
    four_in_a_row_game.run();
//    system("pause");

    return 0;
}
