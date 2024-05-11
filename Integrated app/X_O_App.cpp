// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;

int main() {

    user_input:
    int choice;
    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Which came would you like to play?\n"
            "1- 3x3 X-O game\n"
            "2- 5x5 X-O game\n"
            "3- Connect Four game\n"
            "4- Pyramid Tic Tac Toe game\n";
    cin >> choice;
    if (choice == 1){
        Player* players[2];
        players[0] = new Player (1, 'x');
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        goto user_input;
    }
    else if(choice == 2){
        Player* players[2];
        players[0] = new five_by_five_TicTacToe_Player (1, 'x');
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new five_by_five_TicTacToe_Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager task3_game (new five_by_five_TicTacToe_Board(), players);
        task3_game.run();
        goto user_input;
    }
    else if (choice==3){
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
        goto user_input;
    }
    else if (choice==4){
        int choice;
        Player *players[2];
        players[0] = new Player(1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            // Player pointer points to child
            players[1] = new RandomPlayer('o', 3);

        GameManager pyramidtictactoe_game(new PyramidTicTacToe_Board, players);
        pyramidtictactoe_game.run();
        goto user_input;
    }
}
