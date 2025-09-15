// =============================================================================
// MAIN.CPP - Welcome to the Tic Tac Toe game!
// =============================================================================
// The game allows two players to play against each other, with one player being a bot.
// The bot uses a random number generator to make its moves.
// Compile: g++ -o tictactoe TicTacToe.cpp NBTicTacToe.cpp main.cpp
// Run: .\tictactoe

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "TicTacToe.h"
#include "NBTicTacToe.h"

int main() {
    srand(time(nullptr));                             // Random number generator for X bot

    NBTicTacToe boards[3][3] = {                      // 3*3 2DArray setting co-ordinates of the Board
        {NBTicTacToe(0, 0), NBTicTacToe(0, 1), NBTicTacToe(0, 2)},
        {NBTicTacToe(1, 0), NBTicTacToe(1, 1), NBTicTacToe(1, 2)},
        {NBTicTacToe(2, 0), NBTicTacToe(2, 1), NBTicTacToe(2, 2)}
    };

    int initialX = 1;                                 // Choose your board to play
    int initialY = 1;

    NBTicTacToe& game = boards[initialX][initialY];

    game.play();                                      // Start of game

    return 0;
}
