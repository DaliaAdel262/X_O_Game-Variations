////
//// Created by Mohamed Rabea Mohamed Ali on 12/12/2023.
////
#include "FourInARowBoard.h"

// Definition of the FourInARowBoard class
FourInARowBoard::FourInARowBoard() {
    n_rows = rows;
    n_cols = cols;
    board = new char*[rows];
    for (int i = 0; i < rows; ++i) {
        board[i] = new char[cols];
        for (int j = 0; j < cols; ++j)
            board[i][j] = ' ';
    }
}

// Implementation of the update_board function for the FourInARowBoard class
bool FourInARowBoard::update_board(int x, int y, char symbol) {
    if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] == ' ') {
        // Find the lowest empty square in the selected column
        for (int i = rows - 1; i >= 0; --i) {
            if (board[i][y] == ' ') {
                board[i][y] = symbol;
                n_moves++;
                return true;
            }
        }
    }
    return false;
}

// Implementation of the display_board function for the FourInARowBoard class
void FourInARowBoard::display_board() {
    for (int i = 0; i < rows; ++i) {
        cout << "| ";
        for (int j = 0; j < cols; ++j)
            cout << board[i][j] << " | ";
        cout << "\n-----------------------------\n";
    }
    cout << "  0   1   2   3   4   5   6\n";
}

// Implementation of the is_winner function for the FourInARowBoard class
bool FourInARowBoard::is_winner() {
    // Check for four-in-a-row horizontally
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            if (board[i][j] == board[i][j + 1] &&
                board[i][j + 1] == board[i][j + 2] &&
                board[i][j + 2] == board[i][j + 3] &&
                board[i][j] != ' ') {
                return true;
            }
        }
    }

    // Check for four-in-a-row vertically
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == board[i + 1][j] &&
                board[i + 1][j] == board[i + 2][j] &&
                board[i + 2][j] == board[i + 3][j] &&
                board[i][j] != ' ') {
                return true;
            }
        }
    }

    // Check for four-in-a-row diagonally (bottom-left to top-right)
    for (int i = 3; i < rows; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            if (board[i][j] == board[i - 1][j + 1] &&
                board[i - 1][j + 1] == board[i - 2][j + 2] &&
                board[i - 2][j + 2] == board[i - 3][j + 3] &&
                board[i][j] != ' ') {
                return true;
            }
        }
    }

    // Check for four-in-a-row diagonally (top-left to bottom-right)
    for (int i = 3; i < rows; ++i) {
        for (int j = 3; j < cols; ++j) {
            if (board[i][j] == board[i - 1][j - 1] &&
                board[i - 1][j - 1] == board[i - 2][j - 2] &&
                board[i - 2][j - 2] == board[i - 3][j - 3] &&
                board[i][j] != ' ') {
                return true;
            }
        }
    }

    return false;
}

// Implementation of the is_draw function for the FourInARowBoard class
bool FourInARowBoard::is_draw() {
    return (n_moves == rows * cols && !is_winner());
}

bool FourInARowBoard::game_is_over() {
    return n_moves >= rows * cols;
}
