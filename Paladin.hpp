#pragma once
#include "BasePlayer.hpp"
#include "BoardManager.hpp"

class Paladin : public BasePlayer {

private:
    string archetypeSpecial = "Push";
    string mark = "";
    string name = "";
    int winStreak = 0;
    int specialMoveCount = 0;
    bool specialAvailability = true;
    BoardManager* board;

public:
    std::string getMark() override {
        return mark;
    }

    void move() override {
        int boardMove = 0;
        cout << "\nSelect a move: ";
        cin >> boardMove;
        while (cin.fail() || boardMove < 1 || boardMove > 9 || board->occupiedCell(boardMove)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nThat's not a good option. Try again: ";
            cin >> boardMove;
        }
        board->makeMove(boardMove - 1, mark);
    }

    void prompt() override {
        int moveNumber = 0;
        cout << "\nYou will soon understand the power of the Paladin!";
        if (specialAvailability) {
            cout << "\n(1) Normal Move";
            cout << "\n(2) Special Move";
            cout << "\nAwaiting choice: ";
            cin >> moveNumber;
            while (cin.fail() || moveNumber < 1 || moveNumber > 2) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nThat was not a good option. Try again: ";
                cin >> moveNumber;
            }
            if (moveNumber == 1) {
                move();
            }
            if (moveNumber == 2) {
                specialMove();
            }
        }
        else {
            cout << "\nA paladin is destined to win!";
            move();
        }
    }

    void specialMove() {                // The Paladin special moves meets requirements but seems underpowered compared to transmute
        int originSpot = 0;
        int targetSpot = 0;

        cout << "\n" << archetypeSpecial << " ability activated!";
        cout << "\nSelect a spot to push (must be occupied by any mark): ";
        cin >> originSpot;
        while (cin.fail() || originSpot < 1 || originSpot > 9 || !board->occupiedCell(originSpot)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid spot. Please pick an occupied spot: ";
            cin >> originSpot;
        }

        cout << "\nSelect an adjacent spot to push to (must be empty): ";
        cin >> targetSpot;
        while (cin.fail() || targetSpot < 1 || targetSpot > 9 || !isAdjacent(originSpot, targetSpot) || board->occupiedCell(targetSpot)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid choice. Pick an adjacent, empty spot: ";
            cin >> targetSpot;
        }

        board->setSpot(targetSpot - 1, board->getCell(originSpot - 1)); // Move mark to the new spot
        board->setSpot(originSpot - 1, to_string(originSpot)); // Clear the original spot

        cout << "\n|||>>>>>>>>>|||>>>>>>>>>|||>>>>>>>>>|||>>>>>>";
        cout << "\nNOW YOU SEE THE POWER OF THE PALADIN'S SHIELD";
        cout << "\n|||>>>>>>>>>|||>>>>>>>>>|||>>>>>>>>>|||>>>>>>";
        cout << "\n";
    }

    void addWin() {
        winStreak++;
    }

    int getWinStreak() {
        return winStreak;
    }

    bool getSpecialAvailability() {
        return specialAvailability;
    }

    Paladin(BoardManager* b, string n, string m) {
        mark = m;
        name = n;
        this->board = b;
    }

    Paladin(BoardManager* b, string m) {
        mark = m;
        this->board = b;
    }

private:
    // Helper function to check if two spots are adjacent on a 3x3 board
    bool isAdjacent(int origin, int target) const {
        const int adjacentPairs[16][2] = {
            {1, 2}, {1, 4}, {2, 3}, {2, 5}, {3, 6},
            {4, 5}, {4, 7}, {5, 6}, {5, 8}, {6, 9},
            {7, 8}, {8, 9}, {1, 5}, {3, 5}, {5, 7}, {5, 9}
        };
        for (const auto& pair : adjacentPairs) {
            if ((pair[0] == origin && pair[1] == target) || (pair[0] == target && pair[1] == origin)) {
                return true;
            }
        }
        return false;
    }
};
