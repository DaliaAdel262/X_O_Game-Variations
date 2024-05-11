#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// constructor that initializes number of rows and columns, and dynamically allocates for each coordinate
// so that it's changed with every move.
// board is basically a 2d array of pointers for each coordinate.
five_by_five_TicTacToe_Board::five_by_five_TicTacToe_Board() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// function that displays board every time a move will be made.
void five_by_five_TicTacToe_Board::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// board is updated with a symbol after each move.
bool five_by_five_TicTacToe_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Is_Winner function determines if X won or O won or draw ocurred
string five_by_five_TicTacToe_Board::Is_Winner(){
    int X_wins=0;
    int O_wins=0;

    // loop to check for horizontal three in a row
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= 2; j++) {
                if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X'){
                    X_wins++;
                }
                else if(board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' ){
                    O_wins++;
                }
            }
        }

        // loop to check for vertical three in a row
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i <= 2; i++) {
                if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X'){
                    X_wins++;
                }
                else if(board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O'){
                    O_wins++;
                }
            }
        }

        // loop to check for left diagonal three in a row
        for (int i: {0, 1, 2}) {
            for (int j: {0, 1, 2}) {
                if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' ){
                    X_wins++;
                }
                else if(board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O'){
                    O_wins++;
                }
            }
        }

        // loop to check for right diagonal three in a row
        for (int i: {2,1,0}) {
            for (int j: {4,3,2}) {
                if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X' ){
                    X_wins++;
                }
                else if(board[i][j] == 'O' && board[i + 1][j - 1] == 'O' && board[i + 2][j - 2] == 'O'){
                    O_wins++;
                }
            }
        }
        if (X_wins>O_wins){
            return ("X");
        }
        else if (O_wins>X_wins){
            return ("O");
        }
        else{
            return ("Draw");
        }
}

// a draw is declared after 24 moves and no winner was declared.
bool five_by_five_TicTacToe_Board::is_draw() {
    return (n_moves == 24 && Is_Winner()=="Draw");
}

bool five_by_five_TicTacToe_Board::game_is_over () {
    return n_moves >=24;
}

// the moves function is used for an if condition in GameManager where it will only call the is_winner function
// if this function returns true (24 moves have been made)
bool five_by_five_TicTacToe_Board::moves() {
    if (n_moves==24){
        return true;
    }
    else{
        return false;
    }
}
