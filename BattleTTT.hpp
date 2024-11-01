#pragma once

#include "BoardManager.hpp"
#include "BasePlayer.hpp"
#include "RuleChecker.hpp"


class BattleTTT
{
private:
	
	BasePlayer* player1;
	BasePlayer* player2;

	BoardManager* boardManager;  // Reference to BoardManager for board operations
	RuleChecker* ruleChecker;    // Reference to RuleChecker for validating moves and checking wins

	int player1Streak = 0;
	int player2Streak = 0;

public:

	BattleTTT(BasePlayer* p1, BasePlayer* p2, BoardManager* board, RuleChecker* rules) {
		this->player1 = p1;
		this->player2 = p2;
		this->boardManager = board;
		this->ruleChecker = rules;
	}

    //BattleTTT(Alchemist* p1, Alchemist* p2, BoardManager* board, RuleChecker* rules) {
    //    this->player1 = p1;
    //    this->player2 = p2;
    //    this->boardManager = board;
    //    this->ruleChecker = rules;
    //}


	void runGameLoop() 
    {
        bool gameOver = false;

        while (!gameOver)
        {
            while (!gameOver)
            {
                boardManager->displayBoard();  // Display the current board state

                cout << "\n\n" << player1->getMark() << "'s turn.\n";

                player1->prompt();  // Call the player's prompt function to input move

                if (ruleChecker->checkWin(*boardManager, player1->getMark()))
                {
                    boardManager->displayBoard();  // Show final board state
                    cout << "\n" << player1->getMark() << " wins!\n";
                    gameOver = true;
                    player1->addWin();
                    break;
                }

                else if (boardManager->isFull())
                {  // Check for a tie
                    boardManager->displayBoard();
                    cout << "\nIt's a tie!\n";
                    gameOver = true;

                    break;
                }
                /////////////////////////////---check for symmetry---//////////////////////////////

                boardManager->displayBoard();  // Display the current board state

                cout << "\n\n" << player2->getMark() << "'s turn.\n";

                player2->prompt();  // Call the player's prompt function to input move

                if (ruleChecker->checkWin(*boardManager, player2->getMark()))
                {
                    boardManager->displayBoard();  // Show final board state
                    cout << "\n" << player2->getMark() << " WINS!!!!!!!\n";
                    gameOver = true;
                    player2->addWin();
                    break;
                }

                else if (boardManager->isFull())
                {  // Check for a tie
                    boardManager->displayBoard();
                    cout << "\nIt's a tie!\n";
                    gameOver = true;

                    break;
                }

            }
            // Rematch logic for Battle TTT. Exits to main menu if selection is no.
            int rematchChoice = 0;
            cout << "\n\n===============================";
            cout << "\nSelect if you'd like a rematch:";
            cout << "\n1. Yes";
            cout << "\n2. No";
            cout << "\n===============================";
            cout << "\nYour choice: ";
            cin >> rematchChoice;
            while (cin.fail() || rematchChoice < 1 || rematchChoice > 2) {
                cin.clear();
                cin.ignore();
                cout << "\nInvalid choice. Try again: ";
                cin >> rematchChoice;
            }
            if (rematchChoice == 1) {
                gameOver = false;
                cout << "\nPrepare to play again!!";
                boardManager->clearBoard();
                cout << "\n\n=================";
                cout << "\nScore records: ";
                cout << "\n-----------------";
                cout << "\nPlayer " << player1->getMark() << " wins: " << player1->getWinStreak();
                cout << "\nPlayer " << player2->getMark() << " wins: " << player2->getWinStreak();
                cout << "\n=================";
                cout << "\n";
            }
            else if (rematchChoice == 2) {
                gameOver = true;
            }

        }
        gameOver = true;
        cout << "\nExiting Battle Tic Tac Toe...\n";
    }

};

