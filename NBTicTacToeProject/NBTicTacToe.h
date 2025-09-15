// =============================================================================
// NBTICTACTOE.H - NB TicTacToe Class Header
// =============================================================================
// Nine TicTacToe board with advanced game mechanics

#ifndef NBTICTACTOE_H_
#define NBTICTACTOE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

#include "TicTacToe.h"
#include "Coordinate.h"

class NBTicTacToe {
public:
    NBTicTacToe(int x, int y);                        // Constructor with coordinates
    int play();                                       // Main game
    void getXMove(char playerSymbol, int &x, int &y); // Bot Move
    void getOMove(char playerSymbol, int &x, int &y); // Human Move
    void displayBoards();                             // Board visualisation
    void getCurrentBoard(int boardData[3][3]);        // Current board state
private:
    TicTacToe grid[3][3];                             // Nine TicTacToe board
    Coordinate currentBoard;                          // Constructor - Values of X&Y on current board
};

#endif /* NBTICTACTOE_H_ */
