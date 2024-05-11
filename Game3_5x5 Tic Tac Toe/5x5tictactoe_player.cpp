#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;


// The only changes made to five_by_five_TicTcaToe_Player, is that in terminal it asks u to enter x and y from 0 to 4

five_by_five_TicTacToe_Player::five_by_five_TicTacToe_Player (char symbol) : Player(symbol){}

five_by_five_TicTacToe_Player::five_by_five_TicTacToe_Player (int order, char symbol) : Player(order,symbol){}

void five_by_five_TicTacToe_Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

string five_by_five_TicTacToe_Player::to_string(){
    return Player::to_string();
}

char five_by_five_TicTacToe_Player::get_symbol() {
    return Player::get_symbol();
}
