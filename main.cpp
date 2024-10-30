/*

Portfolio 2: Battle TTT
Name: Humberto
CSC 122

*/

#include <iostream>
#include <string>
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "MainMenu.hpp"
using namespace std;

int main()
{
    int gametypeChoice = 0;

    MainMenu mm;

    mm.beginGame();

    /////////outdated version below ////////////
    //
    //while (cin.fail() || gametypeChoice > 2 || gametypeChoice < 1)
    //{
    //    cin.clear();
    //    cin.ignore();
    //    cout << "Invalid option, please try again: ";
    //    cin >> gametypeChoice;
    //}

    //if (gametypeChoice == 1)
    //{
    //    mm.beginGame(1);
    //}
    //else if (gametypeChoice == 2)
    //{
    //    mm.beginGame(2);
    //}

    ////Ending message
    //cout << "\n*.* Good game!!! *.*\n";

    return 0;
}
