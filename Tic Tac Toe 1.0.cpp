/*

Portfolio 1: Tic Tac Toe
Name: Humberto
CSC 122

*/

#include <iostream>
#include <string>
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "GameLoopRunner.hpp"
using namespace std;

int main()
{
    //Displays a starting message
    cout << "\nWelcome! The game is on!\n";

    //Initializes the game components
    BoardManager boardManager;         //Manages the board state
    RuleChecker ruleChecker;           //Manages game rules (valid moves and win checks)

    GameLoopRunner gameLoop(boardManager, ruleChecker); //Runs the game loop and passes the necessary class objects to the GameLoopRunnerClass

    //Runs the Tic Tac Toe game by calling the runGameLoop function
    gameLoop.runGameLoop();

    //Ending message
    cout << "\n*.* Good game!!! *.*\n";

    return 0;
}
