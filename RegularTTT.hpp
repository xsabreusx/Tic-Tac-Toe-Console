#pragma once
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include <iostream>
#include <string>
using namespace std;

class RegularTTT {
public:
    //Constructor to initialize the game with BoardManager and RuleChecker dependencies
    RegularTTT(BoardManager& board, RuleChecker& rules)
        : boardManager(board), ruleChecker(rules) {}

    //Method to start and run the game loop
    void runGameLoop()
    {
        
        string currentPlayerSymbol = "X"; //Player 1 starts with "X" by default
        bool gameInProgress = true;
        int moveCount = 0;
        string replayC = "Yes";
        bool rematch = true;

        while (rematch == true) 
        {
            while (gameInProgress) {
                boardManager.displayBoard(); //Display the current state of the board
                cout << "\nPlayer " << currentPlayerSymbol << ", enter a position (1-9): ";
                int move;
                cin >> move;
                while (cin.fail()) //Ensures a valid integer input into the game runner
                {
                    cin.clear();
                    cin.ignore();
                    cout << "\nMake a valid move: ";
                    cin >> move;
                }

                //Converts move input to zero-based index by substracting one from it
                move--;

                // Validates the move
                if (!ruleChecker.isValidMove(boardManager, move)) {
                    cout << "\nInvalid move! Try again.\n";
                    continue;
                }

                //Makees the move on the board
                boardManager.makeMove(move, currentPlayerSymbol);
                moveCount++;

                //Checks if the current player has won
                if (ruleChecker.checkWin(boardManager, currentPlayerSymbol)) {
                    boardManager.displayBoard();
                    cout << "\nPlayer " << currentPlayerSymbol << " WON!!\n";
                    gameInProgress = false;
                    break;
                }

                //Checks if the board is full but nobody has won, resulting in a tie
                if (boardManager.isFull()) {
                    boardManager.displayBoard();
                    gameInProgress = false;
                    cout << "\nIt's a tie!\n";
                    break;
                }

                //Switches player after every valid move
                currentPlayerSymbol = (currentPlayerSymbol == "X") ? "O" : "X";
            }

            cout << "\nWould you like to play again? (Y or N): ";
            cin >> replayC;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "\nInvalid input. Ending game.";
                boardManager.clearBoard();
                rematch = false;
            }
            else if (replayC == "Yes" || replayC == "Y" || replayC == "Yep")
            {
                cout << "\nStarting new game.";
                replayC = "Yes";
                boardManager.clearBoard();
                rematch = true;
                gameInProgress = true;

            }
            else { 
                rematch = false;

            }
        }
        
    }

private:
    BoardManager& boardManager;  // Reference to BoardManager for board operations
    RuleChecker& ruleChecker;    // Reference to RuleChecker for validating moves and checking wins
};
