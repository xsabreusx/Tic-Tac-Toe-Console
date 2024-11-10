#pragma once
#include "BasePlayer.hpp"
#include "BoardManager.hpp"
#include <vector>

class Chronomage : public BasePlayer {
private:
    std::string archetypeSpecial = "Time Reversal";
    std::string mark = "";
    std::string name = "";
    int winStreak = 0;
    bool specialUsed = false;

    // Internal history of board states to keep track of moves
    std::vector<std::vector<std::string>> boardHistory;

public:

    Chronomage(BoardManager* b, const std::string& n, const std::string& m) : board(b), name(n), mark(m) {
        // Initialize with the current board state
        boardHistory.push_back(board->getBoardState());
    }

    std::string getMark() override {
        return mark;
    }

    void move() override {
        int boardMove = 0;

        std::cout << "\nSelect a move: ";
        std::cin >> boardMove;
        while (std::cin.fail() || boardMove < 1 || boardMove > 9 || board->occupiedCell(boardMove - 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nThat's not a valid option. Try again: ";
            std::cin >> boardMove;
        }

        // Make the move and save the board state
        board->makeMove(boardMove - 1, mark);
        saveBoardState();
    }

    void prompt() override {
        int moveNumber = 0;

        std::cout << "\nHarness the power of time, Chronomage!";
        if (!specialUsed) {
            std::cout << "\n(1) Normal Move";
            std::cout << "\n(2) Special Move (Time Reversal)";
            std::cout << "\nAwaiting choice: ";
            std::cin >> moveNumber;
            while (std::cin.fail() || moveNumber < 1 || moveNumber > 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nInvalid choice. Try again: ";
                std::cin >> moveNumber;
            }
            if (moveNumber == 1) {
                move();
            }
            else if (moveNumber == 2) {
                specialMove();
            }
        }
        else {
            std::cout << "\nYou have already used your Time Reversal.";
            move();
        }
    }

    void specialMove() override {
        int turnsBack;
        std::cout << "\n" << archetypeSpecial << " activated! How many turns would you like to go back? (1-3): ";
        std::cin >> turnsBack;

        // Validate the number of turns back
        while (std::cin.fail() || turnsBack < 1 || turnsBack > 3 || turnsBack >= boardHistory.size()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid number of turns. Choose between 1 and 3, or a number that does not exceed the current history size: ";
            std::cin >> turnsBack;
        }

        // Revert the board to the previous state
        restoreBoardState(turnsBack);
        std::cout << "\nTime has been reversed by " << turnsBack << " turn(s)!";
        specialUsed = true;
    }

    void addWin() override {
        winStreak += 1;
    }

    int getWinStreak() override {
        return winStreak;
    }

    bool getSpecialAvailability() override {
        return !specialUsed;
    }

private:
    BoardManager* board;

    // Saves the current board state to the history
    void saveBoardState() {
        boardHistory.push_back(board->getBoardState());
    }

    // Restores the board state from a specified number of turns back
    void restoreBoardState(int turnsBack) {
        int targetIndex = boardHistory.size() - 1 - turnsBack;
        std::vector<std::string> previousState = boardHistory[targetIndex];
        board->setBoardState(previousState);

        // Remove all states after the restored state
        boardHistory.erase(boardHistory.begin() + targetIndex + 1, boardHistory.end());
    }
};

