// =============================================================================
// NBTICTACTOE.CPP - NB TicTacToe Implementation
// =============================================================================
// Nine-board TicTacToe with Player vs Bot gameplay

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#include "TicTacToe.h"
#include "NBTicTacToe.h"

NBTicTacToe::NBTicTacToe(int x, int y) {                                      // Constructor - Initialize game with starting coordinates
    currentBoard.x = x;
    currentBoard.y = y;
    for (int i = 0; i < 3; i++) {                                             // Initialize 3x3 grid of TicTacToe boards
        for (int j = 0; j < 3; j++) {
            grid[i][j] = TicTacToe();
        }
    }
}

void NBTicTacToe::getXMove(char playerSymbol, int &x, int &y) {               // Player move input - Get coordinates from Player
    if (grid[currentBoard.x][currentBoard.y].getNoOfMoves() >= 9) {           // Check if current board is full
        x = -1;
        y = -1;
        return;
    }

    int row, col;
    do {                                                                      // Get valid input from player
        cin >> row >> col;
        cout << endl;
    } while (!grid[currentBoard.x][currentBoard.y].isValidMove(row - 1, col - 1));

    x = row - 1;                                                              // Convert to 0-based indexing
    y = col - 1;                                                              // Convert to 0-based indexing
}

void NBTicTacToe::getOMove(char playerSymbol, int &x, int &y) {               // Bot move generation - Random valid move
    if (grid[currentBoard.x][currentBoard.y].getNoOfMoves() >= 9) {           // Check if current board is full
        x = -1;
        y = -1;
        return;
    }

    do {                                                                      // Generate random valid move
        x = rand() % BOARDSIZE;
        y = rand() % BOARDSIZE;
    } while (!grid[currentBoard.x][currentBoard.y].isValidMove(x, y));
}

int NBTicTacToe::play() {                                                     // Main game loop - Controls game flow and win conditions
    int player = -1;                                                          // Current player: -1 = Bot, 1 = Player
    int done = 0;                                                             // Game status flag

    displayBoards();                                                          // Show initial empty board state (board 5 active)

    while (done == 0) {                                                       // Game loop continues until game ends
        char playerSymbol = (player == 1) ? 'X' : 'O';                        // Player = X, Bot = O
        string playerName = (player == 1) ? "Player" : "Bot";

        // Show current board number BEFORE getting move
        int current_board_number = (currentBoard.x) * 3 + currentBoard.y + 1;
        cout << playerName << " (" << playerSymbol << ") enter move in Board " 
             << current_board_number << " *CURRENT*: ";

        int x, y;

        if (player == 1) {                                                    // Get move based on current player
            getXMove(playerSymbol, x, y);
        } else {
            getOMove(playerSymbol, x, y);
        }

        int winningBoard_x = currentBoard.x;                                  // Store the board where the move was made BEFORE updating currentBoard
        int winningBoard_y = currentBoard.y;            

        grid[currentBoard.x][currentBoard.y].addMove(x, y, player);           // Apply move to board
        grid[currentBoard.x][currentBoard.y].increaseNoOfMoves();
        
        done = grid[winningBoard_x][winningBoard_y].gameStatus();             // Game checker for win where move was made

        currentBoard.x = x;                                                   // Update current board for next move
        currentBoard.y = y;

        displayBoards();                                                      // Show updated board state with next board active

        if (done == 1) {                                                      // Handle game end conditions
            int winning_board_number = (winningBoard_x) * 3 + winningBoard_y + 1;
            cout << "\n" << string(80, '=') << "\n";
            cout << "PLAYER WINS ON BOARD " << winning_board_number << "! :D CONGRATS!" << endl;
            cout << string(80, '=') << "\n";
            return 1;
        } else if (done == -1) {
            int winning_board_number = (winningBoard_x) * 3 + winningBoard_y + 1;
            cout << "\n" << string(80, '=') << "\n";
            cout << "BOT WINS ON BOARD " << winning_board_number << "! :( BETTER LUCK NEXT TIME!" << endl;
            cout << string(80, '=') << "\n";
            return -1;
        } else if (done == 2) {
            int draw_board_number = (winningBoard_x) * 3 + winningBoard_y + 1;
            cout << "\n" << string(80, '=') << "\n";
            cout << "DRAW GAME ON BOARD " << draw_board_number << "! CLOSE ONE" << endl;
            cout << string(80, '=') << "\n";
            return 0;
        }

        player = (player == 1) ? -1 : 1;                                      // Switch players
    }

    return 0;
}

void NBTicTacToe::displayBoards() {                                           // Display all boards - Shows 3x3 grid of TicTacToe boards
    cout << "\n" << string(90, '=') << "\n";
    cout << "                    NINE-BOARD TIC-TAC-TOE" << endl;
    cout << string(90, '=') << "\n";
    
    for (int boardRow = 0; boardRow < 3; boardRow++) {                        // Process each row of boards
        cout << "         ";
        for (int boardCol = 0; boardCol < 3; boardCol++) {
            int boardNum = boardRow * 3 + boardCol + 1;
            cout << "BOARD " << boardNum;
            if (boardRow == currentBoard.x && boardCol == currentBoard.y) {
                cout << " *ACTIVE*";
            } else {
                cout << "        ";
            }
            if (boardCol < 2) cout << "    ";
        }
        cout << "\n";
        
        vector<string> displayRows(3, "");                                    // Store formatted rows for each board
        
        for (int boardCol = 0; boardCol < 3; boardCol++) {                    // Process each board in current row
            int boardData[3][3];
            grid[boardRow][boardCol].getCurrentBoard(boardData);
            
            for (int cellRow = 0; cellRow < 3; cellRow++) {                   // Format each row of current board
                string rowString = "    ";                                    // Add padding
                
                for (int cellCol = 0; cellCol < 3; cellCol++) {
                    char playerSymbol = ' ';
                    if (boardData[cellRow][cellCol] == 1)                     // Player = X
                        playerSymbol = 'X';
                    else if (boardData[cellRow][cellCol] == -1)               // Bot = O
                        playerSymbol = 'O';
                    
                    rowString += " ";
                    rowString += playerSymbol;
                    rowString += " ";
                    if (cellCol != 2)
                        rowString += "|";                                     // Cell separator
                }
                
                rowString += "    ";                                          // Add padding
                
                if (boardCol < 2) {                                           // Add board separator except for last board
                    rowString += "  |  ";
                }
                
                displayRows[cellRow] += rowString;
            }
        }
        
        for (int rowIdx = 0; rowIdx < 3; rowIdx++) {                          // Output formatted rows for current board row
            cout << displayRows[rowIdx] << endl;
            if (rowIdx != 2) {
                cout << "    ---+---+---      |      ---+---+---      |      ---+---+---" << endl;
            }
        }
        
        if (boardRow != 2) {                                                  // Add separator between board rows
            cout << string(90, '-') << endl;
        }
    }
    
    cout << string(90, '=') << "\n";
    cout << "Instructions: Enter row column (1-3) (1-3) e.g 1 1" << endl;
    cout << "Your move will be played on the *CURRENT* Board, the Bots move will go to the corrosponding board." << endl;
    cout << string(90, '=') << "\n";
}

void NBTicTacToe::getCurrentBoard(int boardData[3][3]) {                       // Get current board state - Returns board data for current active board
    grid[currentBoard.x][currentBoard.y].getCurrentBoard(boardData);
}