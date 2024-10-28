#pragma once

#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "BattleTTT.hpp"
#include "Alchemist.hpp"


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
            cout << "\nThe battle beings now!";

            BoardManager battleBoard;
            RuleChecker battleChecker;

            RuleChecker* rules = &battleChecker;
            BoardManager *battleB = &battleBoard;

            Alchemist alchemist1(battleB, "$");
            Alchemist alchemist2(battleB, "@");
            Alchemist* alch1 = &alchemist1;
            Alchemist* alch2 = &alchemist2;

            BattleTTT battleTTT(alch1, alch2, battleB, rules); 
            
            battleTTT.runGameLoop();

        }
        
	}

};

