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


	void runGameLoop() 
    {
        bool gameOver = false;

        while (!gameOver) 
        {
            boardManager->displayBoard();  // Display the current board state

            cout << "\n\n" << player1->getMark() << "'s turn.\n";

            player1->prompt();  // Call the player's prompt function to input move
            // Check if the current player has won

            if (ruleChecker->checkWin(*boardManager, player1->getMark()))
            {
                boardManager->displayBoard();  // Show final board state
                cout << "\n" << player1->getMark() << " wins!\n";
                gameOver = true;

                break;
            }

            else if (boardManager->isFull())
            {  // Check for a tie
                boardManager->displayBoard();
                cout << "\nIt's a tie!\n";
                gameOver = true;

                break;
            }
            /////////////////////////////---check symmetry---//////////////////////////////

            boardManager->displayBoard();  // Display the current board state

            cout << "\n\n" << player2->getMark() << "'s turn.\n";

            player2->prompt();  // Call the player's prompt function to input move
            // Check if the current player has won

            if (ruleChecker->checkWin(*boardManager, player2->getMark()))
            {
                boardManager->displayBoard();  // Show final board state
                cout << "\n" << player2->getMark() << " wins!\n";
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
        cout << "\nGame over. Thanks for playing!\n";
        


        

    }

};

