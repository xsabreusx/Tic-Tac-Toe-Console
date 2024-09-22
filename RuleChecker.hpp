#pragma once
#include "BoardManager.hpp"
using namespace std;

class RuleChecker {
public:
    // Method to check if a player has won by forming a row, column, or diagonal
    bool checkWin(const BoardManager& boardManager, string playerSymbol)
    {
        // Defining the winning combinations: rows, columns, and diagonals
        const int winPatterns[8][3] = {
            {0, 1, 2}, // Row 1
            {3, 4, 5}, // Row 2
            {6, 7, 8}, // Row 3
            {0, 3, 6}, // Column 1
            {1, 4, 7}, // Column 2
            {2, 5, 8}, // Column 3
            {0, 4, 8}, // Diagonal top-left to bottom-right
            {2, 4, 6}  // Diagonal top-right to bottom-left
        };

        // Loop through the win patterns and check if the player has any winning combination
        for (int i = 0; i < 8; ++i) {
            if (boardManager.getCell(winPatterns[i][0]) == playerSymbol &&
                boardManager.getCell(winPatterns[i][1]) == playerSymbol &&
                boardManager.getCell(winPatterns[i][2]) == playerSymbol) {
                return true; // Player has won
            }
        }

        return false; // No winning pattern found
    }

    // Method to check if the move is valid
    bool isValidMove(const BoardManager& boardManager, int index)
    {
        // Ensure the index is valid (within 0 to 8)
        if (index < 0 || index > 8) {
            return false; // Invalid index
        }

        // Check if the selected cell is still available
        string cellValue = boardManager.getCell(index);
        if (isdigit(cellValue[0])) {
            return true; // The cell is available
        }

        return false; // The cell is already occupied
    }
};
