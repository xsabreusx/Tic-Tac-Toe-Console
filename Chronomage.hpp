#pragma once
#include "BasePlayer.hpp"
#include "BoardManager.hpp"
#include <vector>
#include <iostream>
#include <limits>

/////////////////////// Extra credit class - Turns back time a specified number of turns ////////////////////////
class Chronomage : public BasePlayer {
private:
    std::string archetypeSpecial = "Time Reversal";
    std::string mark = "";
    std::string name = "";
    int winStreak = 0;
    int specialsUsed = 0;
    int reversalLimit = 3;

    // Internal history of board states to keep track of moves
    std::vector<std::vector<std::string>> boardHistory;

    BoardManager* board;

    // Saves the current board state to the history
    void saveBoardState() {
        if (boardHistory.empty() || boardHistory.back() != board->getBoardState()) {
            boardHistory.push_back(board->getBoardState());
        }
    }

    // Restores the board state from a specified number of turns back
    void restoreBoardState(int turnsBack) {
        int targetIndex = static_cast<int>(boardHistory.size()) - 1 - turnsBack;

        if (targetIndex < 0) {
            std::cerr << "\nError: Cannot revert further back in time.\n";
            return;
        }

        board->setBoardState(boardHistory[targetIndex]);

        // Remove all states after the restored state
        boardHistory.resize(targetIndex + 1);
    }

public:
    Chronomage(BoardManager* b, const std::string& n, const std::string& m) : board(b), name(n), mark(m) {
        saveBoardState(); // Initialize with the current board state
    }

    Chronomage(BoardManager* b, const std::string& m) : board(b), mark(m) {
        saveBoardState(); // Initialize with the current board state
    }

    std::string getMark() override {
        return mark;
    }

    void move() override {
        int boardMove = 0;

        std::cout << "\nSelect a move: ";
        std::cin >> boardMove;
        while (std::cin.fail() || boardMove < 1 || boardMove > 9 || board->occupiedCell(boardMove)) {
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
        saveBoardState();
        int moveNumber = 0;

        std::cout << "\nA Chronomage is a Master of Entropy!!";
        if (specialsUsed < reversalLimit && boardHistory.size() > 2) {
            std::cout << "\n(1) Normal Move";
            std::cout << "\n(2) Time Reversal" << " (maximum of " << reversalLimit << " uses)";
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
            } else if (moveNumber == 2) {
                specialMove();
            }
        } else {
            std::cout << "\nHowever, the gods restrict me to normal moves currently, like a peasant!";
            move();
        }
    }

    void specialMove() override {
        int turnsBack;
        std::cout << "\n" << archetypeSpecial << " activated! How many turns would you like to go back? (1-" << std::min(reversalLimit, static_cast<int>(boardHistory.size() - 1)) << "): ";
        std::cin >> turnsBack;

        while (std::cin.fail() || turnsBack < 1 || turnsBack > reversalLimit || turnsBack >= static_cast<int>(boardHistory.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid chronometric coordinates! Choose between 1 and 3, or a number smaller than the number of turns: ";
            std::cin >> turnsBack;
        }

        restoreBoardState(turnsBack);
        std::cout << "\nTime has been reversed by " << turnsBack << " turn(s)!";
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<--------------------------<<<<<<<<<";
        std::cout << "\n<<<<<--- TIME ALWAYS WINS. HAHAHAHAHA!!!  ----<<<<<<<<<";
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<--------------------------<<<<<<<<<";
        specialsUsed++;
        saveBoardState();
    }

    void addWin() override {
        winStreak += 1;
    }

    int getWinStreak() override {
        return winStreak;
    }

    bool getSpecialAvailability() override {
        return specialsUsed < reversalLimit;
    }
};

