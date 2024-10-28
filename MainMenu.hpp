#pragma once
#include <cctype>
#include <string>
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "BattleTTT.hpp"
#include "Alchemist.hpp"


class MainMenu
{
private:

public:

    bool isValidMark(const string& mark) {
        // Check if the mark is exactly one character long
        if (mark.length() != 1) return false;

        // Check if the mark is a letter or one of the allowed symbols
        char c = mark[0];
        return isalpha(c) || c == '?' || c == '!' || c == '*' ||
            c == '~' || c == '$' || c == '%' || c == '#';
    }

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
            string player1Name;
            string player2Name;
            string player1Mark;
            string player2Mark;

            cout << "\nThe battle begins soon!";
            cout << "\nPlayer 1, enter your mark (A to Z, a to z, ?, !, *, ~, $, %, #): ";

            while (true) {
                getline(cin, player1Mark);

                if (isValidMark(player1Mark)) {
                    break;  // Valid input, exit the loop
                }
                else {
                    cin.clear();
                    cout << "\nInvalid input. Enter a valid player mark: ";
                }
            }

            cout << "\nPlayer 2, enter your mark (A to Z, a to z, ?, !, *, ~, $, %, #): ";

            while (true) {
                getline(cin, player2Mark);

                if (isValidMark(player2Mark)) {
                    break;  
                }
                else {
                    cin.clear();
                    cout << "\nInvalid input. Enter a valid player mark: ";
                }
            }

            BoardManager battleBoard;
            RuleChecker battleChecker;

            RuleChecker* rules = &battleChecker;
            BoardManager *battleB = &battleBoard;

            Alchemist alchemist1(battleB, player1Mark);
            Alchemist alchemist2(battleB, player2Mark);

            Alchemist* alch1 = &alchemist1;
            Alchemist* alch2 = &alchemist2;

            BattleTTT battleTTT(alch1, alch2, battleB, rules); 
            
            battleTTT.runGameLoop();

        }
        
	}

};

