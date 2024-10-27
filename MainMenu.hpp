#pragma once

#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "BattleTTT.hpp"


class MainMenu
{
private:

public:

	void beginGame(int choice) {

        if (choice == 1)
        {
            //Displays a starting message
            cout << "\nWelcome! The game is on!\n";

            //Initializes the game components
            BoardManager boardManager;         //Manages the board state
            RuleChecker ruleChecker;           //Manages game rules (valid moves and win checks)

            RegularTTT regularTTT(boardManager, ruleChecker); //Runs the game loop and passes the necessary class objects to the GameLoopRunnerClass

            //Runs the Tic Tac Toe game by calling the runGameLoop function
            regularTTT.runGameLoop();
        }

        else if (choice == 2)
        {
            cout << "\nFeature implementation in progress... try again later";
        }
        
	}

};

