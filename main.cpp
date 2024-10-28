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

    cout << "\n\n** Welcome to Battle Tic Tac Toe!! **";
    cout << "\n**---------------------------------**";
    cout << "\n\nSelect your game type:\n";
    cout << "\n (1) Regular Tic Tac Toe";
    cout << "\n (2) Battle Tic Tac Toe";
    cout << "\n\nAwaiting Input: ";
    cin >> gametypeChoice;
    
    while (cin.fail() || gametypeChoice > 2 || gametypeChoice < 1)
    {
        cin.clear();
        cin.ignore();
        cout << "Invalid option, please try again: ";
        cin >> gametypeChoice;
    }

    if (gametypeChoice == 1)
    {
        mm.beginGame(1);
    }
    else if (gametypeChoice == 2)
    {
        mm.beginGame(2);
    }

    //Ending message
    cout << "\n*.* Good game!!! *.*\n";

    return 0;
}
