// =============================================================================
// TICTACTOE.CPP - Base TicTacToe Implementation
// =============================================================================
// Validation of moves, x Row (0-2), y Column (0-2) 

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "TicTacToe.h"

TicTacToe::TicTacToe() {                               // Constructor initialising game of 3 rows and columns
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
}

bool TicTacToe::isValidMove(int x, int y) {           // X and Y are moves
    if (x < 0 || x > 2 || y < 0 || y > 2) {           // 3 = invalid, -1 = invalid
        return false;
    }
	if (board[x][y] != 0) {                           // Checking if the board is in use of X or O
	    return false;
	}

	return true;
}

void TicTacToe::addMove(int x, int y, int player) {    // Allocating space for player moves
	board[x][y] = player;
}

int TicTacToe::gameStatus() {                         // Win Loss Tie
    for (int i = 0; i < 3; i++) {                     // Check columns for a win
        int countX = 0;
        int countO = 0;

        for (int j = 0; j < 3; j++) {                 // Checking rows for a win
            if (board[i][j] == 1) {
                countX++;
            } else if (board[i][j] == -1) {
                countO++;
            }

            if (countX == 3) {
                return 1;                             // Player X wins
            } else if (countO == 3) {
                return -1;                            // Player O wins
            }
        }
    }

    for (int j = 0; j < 3; j++) {                    // Check columns for a win
        int countX = 0;
        int countO = 0;

        for (int i = 0; i < 3; i++) {                // Check rows for a win
            if (board[i][j] == 1) {
                countX++;
            } else if (board[i][j] == -1) {
                countO++;
            }
        }

        if (countX == 3)
            return 1;
        else if (countO == 3)
            return -1;
    }
    if ((board[0][0] == 1 && board[1][1] == 1 &&         // Check diagonals 1 for a win
         board[2][2] == 1) ||
        (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)) {
        return 1;
    }

    if ((board[0][0] == -1 && board[1][1] == -1 &&
         board[2][2] == -1) ||                          // Check diagonal -1 for a win
        (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1)) {
        return -1;
    }

	if (noOfMoves >= 9)
		return 2;

	return 0;
}

int TicTacToe::getNoOfMoves() {                         // Returns the private property in class TicTacToe
    return noOfMoves;
}

void TicTacToe::increaseNoOfMoves() {                  // Increases the private property in class TicTacToe
    noOfMoves++;
}

void TicTacToe::getCurrentBoard(int boardData[3][3]) {           // Copys the current state of the TicTacToe board to boardData array
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            boardData[row][col] = board[row][col];
        }
    }
}
