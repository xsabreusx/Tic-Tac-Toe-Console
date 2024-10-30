#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "BoardManager.hpp"
#include "RuleChecker.hpp"
#include "RegularTTT.hpp"
#include "BattleTTT.hpp"
#include "Alchemist.hpp"
#include "Paladin.hpp"

using namespace std;

class MainMenu
{
public:
    void displayMenu() const {
        cout << "\n=== Welcome to Tic-Tac-Toe! ===";
        cout << "\nChoose your game mode:";
        cout << "\n1. Regular Tic-Tac-Toe";
        cout << "\n2. Battle Tic-Tac-Toe";
        cout << "\n3. Quit";
        cout << "\n=============================";
        cout << "\nEnter your choice: ";
    }

    bool isValidMark(const string& mark) const {
        if (mark.length() != 1) return false;
        char c = mark[0];
        return isalpha(c) || c == '?' || c == '!' || c == '*' ||
            c == '~' || c == '$' || c == '%' || c == '#';
    }

    bool isMarkTaken(const string& mark) const {
        return find(takenMarks.begin(), takenMarks.end(), mark) != takenMarks.end();
    }

    void clearMarksSelection() {
        takenMarks.clear();
    }

    void beginGame() {
        int choice;
        while (true) {
            displayMenu();
            cin >> choice;

            if (cin.fail() || (choice < 1 || choice > 3)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input! Please try again.\n";
            }
            else if (choice == 3) {
                cout << "\nThanks for playing! Goodbye.\n";
                break;
            }
            else {
                runSelectedGame(choice);
            }
        }
    }

private:

    vector<string>takenMarks;

    void runSelectedGame(int choice) {
        if (choice == 1) {
            cout << "\nStarting Regular Tic-Tac-Toe!\n";
            BoardManager boardManager;
            RuleChecker ruleChecker;
            RegularTTT regularTTT(boardManager, ruleChecker);
            regularTTT.runGameLoop();
        }
        else if (choice == 2) {
            cout << "\nStarting Battle Tic-Tac-Toe!\n";
            setupBattleGame();
        }
    }

    void setupBattleGame() {
        string player1Mark, player2Mark;

        player1Mark = getPlayerMark(1);
        player2Mark = getPlayerMark(2);

        BoardManager battleBoard;
        RuleChecker battleChecker;
        Alchemist alchemist1(&battleBoard, player1Mark);
        Paladin paladin2(&battleBoard, player2Mark); // Example with a Paladin

        BattleTTT battleTTT(&alchemist1, &paladin2, &battleBoard, &battleChecker);
        clearMarksSelection();
        battleTTT.runGameLoop();
    }

    string getPlayerMark(int playerNumber) {
        string mark;
        while (true) {
            cout << "\nPlayer " << playerNumber
                << ", enter your mark (A-Z, a-z, ?, !, *, ~, $, %, #): ";
            cin >> mark;

            if (!isValidMark(mark)) {
                cout << "\nInvalid mark! Please try again.";
                continue;
            }

            if (isMarkTaken(mark)) {
                cout << "\nThis mark is already taken! Please choose another.";
                continue;
            }

            // Store the valid mark in the takenMarks vector
            takenMarks.push_back(mark);
            return mark;
        }
    }
};

