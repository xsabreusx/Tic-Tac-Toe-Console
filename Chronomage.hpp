#pragma once
#include "BasePlayer.hpp"
#include "BoardManager.hpp"
#include <vector>
/////////////////////// Extra credit class - Turns back time a specified number of turns ////////////////////////
class Chronomage : public BasePlayer {
private:
    string archetypeSpecial = "Time Reversal";
    string mark = "";
    string name = "";
    int winStreak = 0;
    int specialsUsed = 0;
    int reversalLimit = 3;
    bool specialAvailable = true;
    // Internal history of board states to keep track of moves
    vector<vector<string>> boardHistory;

    BoardManager* board;

    // Saves the current board state to the history
    void saveBoardState() {
        boardHistory.push_back(board->getBoardState());
    }

    // Restores the board state from a specified number of turns back
    void restoreBoardState(int turnsBack) {
        int targetIndex = boardHistory.size() - 1 - turnsBack;
        vector<string> previousState = boardHistory[0];
        if (targetIndex < 0) {
            vector<string> previousState = boardHistory[0];
        }
        else {
            vector<string> previousState = boardHistory[targetIndex];
        }
        board->setBoardState(previousState);

        // Remove all states after the restored state
        //boardHistory.erase(boardHistory.begin() + targetIndex + 1, boardHistory.end());
    }

public:

    Chronomage(BoardManager* b, const std::string& n, const std::string& m) : board(b), name(n), mark(m) {
        // Initialize with the current board state
        boardHistory.push_back(board->getBoardState());
    }

    Chronomage(BoardManager* b, const std::string& m) : board(b), mark(m) {
        // Initialize with the current board state
        boardHistory.push_back(board->getBoardState());
    }

    string getMark() override {
        return mark;
    }

    void move() override {
        int boardMove = 0;

        cout << "\nSelect a move: ";
        cin >> boardMove;
        while (cin.fail() || boardMove < 1 || boardMove > 9 || board->occupiedCell(boardMove)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nThat's not a valid option. Try again: ";
            cin >> boardMove;
        }

        // Make the move and save the board state
        board->makeMove(boardMove - 1, mark);
        saveBoardState();
    }

    void prompt() override {
        saveBoardState();
        int moveNumber = 0;

        cout << "\nA Chronomage is a Master of Entropy!!";
        if (specialsUsed < reversalLimit && boardHistory.size() > 2) {
            cout << "\n(1) Normal Move";
            cout << "\n(2) Time Reversal" << " (maximum of " << reversalLimit << " uses)";
            cout << "\nAwaiting choice: ";
            cin >> moveNumber;
            while (cin.fail() || moveNumber < 1 || moveNumber > 2) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nInvalid choice. Try again: ";
                cin >> moveNumber;
            }
            if (moveNumber == 1) {
                move();
            }
            else if (moveNumber == 2) {
                specialMove();
            }
        }
        else {
            specialAvailable = false;
            cout << "\nHowever, the gods restrict me to normal moves currently, like a peasant!";
            move();
        }
    }

    void specialMove() override {
        int turnsBack;
        cout << "\n" << archetypeSpecial << " activated! How many turns would you like to go back? (1-3): ";
        cin >> turnsBack;

        // Validate the number of turns back
        while (cin.fail() || turnsBack < 1 || turnsBack > 3 || turnsBack > boardHistory.size()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nInvalid chronometric coordinates! Choose between 1 and 3, or a number smaller than the number of turns: ";
            cin >> turnsBack;
        }

        // Revert the board to the previous state
        restoreBoardState(turnsBack);
        cout << "\nTime has been reversed by " << turnsBack << " turn(s)!";
        cout << "\n<<<<<<<<<<<<<<<<<<<<--------------------------<<<<<<<<<";
        cout << "\n<<<<<--- TIME ALWAYS WINS. HAHAHAHAHA!!!  ----<<<<<<<<<";
        cout << "\n<<<<<<<<<<<<<<<<<<<<--------------------------<<<<<<<<<";
        specialsUsed++;
    }

    void addWin() override {
        winStreak += 1;
    }

    int getWinStreak() override {
        return winStreak;
    }

    bool getSpecialAvailability() override {
        return true;
    }

};

