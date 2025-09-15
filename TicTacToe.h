// =============================================================================
// TICTACTOE.H - Base TicTacToe Class Header
// =============================================================================
// 3x3 Tic-Tac-Toe game implementation
// Handles board logic, move validation, and win detection

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

const int BOARDSIZE = 3;

class TicTacToe {
private:
	int board[BOARDSIZE][BOARDSIZE]; // Game board: 0 = empty, 1 = X, -1 = O
	int noOfMoves; // Number of moves 
public:
	TicTacToe(); // Constructor
	bool isValidMove(int, int); // Validates move coordinates
	void addMove(int, int, int); // Places player move
	int gameStatus(); // Returns game state
	//void displayBoard(); Disable displayBoard function
	int getNoOfMoves();  // Returns move count
	void increaseNoOfMoves();  // Increments move counter
	void getCurrentBoard(int boardData[3][3]); // Copies board state
};

#endif /* TICTACTOE_H_ */
