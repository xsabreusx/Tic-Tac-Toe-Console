/*

Portfolio 2: Battle TTT
Name: Humberto
CSC 122

*/

#include <iostream>
#include <string>
#include <cassert>
#include <limits>
#include "GameLogger.hpp"
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "BattleTTT.hpp"
#include "BasePlayer.hpp"
#include "Alchemist.hpp"
#include "Paladin.hpp"
#include "Chronomage.hpp"
#include "MainMenu.hpp"

using namespace std;

int main()
{
    /////////--- Test Driver ---//////// 
    // Checks important functions to the proper working of the game

    BoardManager testboard1;
    testboard1.setSpot(1, "X");  // Checking setSpot
    testboard1.setSpot(2, "A");
    assert(testboard1.getCell(1) == "X");
    assert(testboard1.getCell(2) == "A");

    testboard1.makeMove(3, "Z");
    assert(testboard1.getCell(3) == "Z");

    testboard1.makeMove(3, "X"); // Checking that makeMove doesn't overwrite cells
    assert(testboard1.getCell(3) == "Z");

    BoardManager boardTest;
    for (int i = 0; i < 9; ++i) {
        assert(boardTest.getCell(i) == to_string(i + 1));
    }

    boardTest.setSpot(1, "X");
    boardTest.clearBoard();
    for (int i = 0; i < 9; ++i) {
        assert(boardTest.getCell(i) == to_string(i + 1));
    }

    for (int i = 0; i < 9; ++i) {
        boardTest.setSpot(i, "X");
    }
    assert(boardTest.isFull() == true);

    boardTest.clearBoard();
    assert(boardTest.isFull() == false);

    assert(boardTest.makeMove(10, "X") == false); // Invalid index
    assert(boardTest.makeMove(-1, "X") == false); // Negative index

    RuleChecker ruleChecker;
    boardTest.setSpot(0, "X");
    boardTest.setSpot(1, "X");
    boardTest.setSpot(2, "X");
    assert(ruleChecker.checkWin(boardTest, "X") == true);

    boardTest.clearBoard();
    boardTest.setSpot(0, "O");
    boardTest.setSpot(3, "O");
    boardTest.setSpot(6, "O");
    assert(ruleChecker.checkWin(boardTest, "O") == true);

    MainMenu menu;            // Menu checks
    assert(menu.isValidMark("X") == true);
    assert(menu.isValidMark("?") == true);
    assert(menu.isValidMark("!") == true);
    assert(menu.isValidMark("@") == false);

    menu.clearMarksSelection();
    assert(menu.isMarkTaken("X") == false);

    cout << "\nAll assert checks passed.\n";

    /////////////////////////////////////
    
    
    
    int gametypeChoice = 0;

    MainMenu mm;

    mm.beginGame();


    return 0;
}
