#pragma once
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;


class BoardManager {
public:
    BoardManager() : board_{ "1", "2", "3", "4", "5", "6", "7", "8", "9" } {}

    void displayBoard() const // Method to display a cool custom board
    {
        cout << "\n== Tic Tac Toe ==";
        cout << "\n=================";
        cout << "\n  " << board_[0] << "  |  " << board_[1] << "  |  " << board_[2] << "  ";
        cout << horizontalDivider_;
        cout << "\n  " << board_[3] << "  |  " << board_[4] << "  |  " << board_[5] << "  ";
        cout << horizontalDivider_;
        cout << "\n  " << board_[6] << "  |  " << board_[7] << "  |  " << board_[8] << "  ";
        cout << horizontalDivider_;

    }
    
    //Method to change the board, returns true if move is valid, false otherwise
    bool makeMove(int index, string playerSymbol) {
        if (index < 0 || index > 8) 
        {
            return false; // Invalid index
        }
        else if ( isdigit(board_[index][0]) )
        {
            board_[index] = playerSymbol; // Make the move
            return true;
        }
        else
        {
            return false;
        }
        
    }

    string getCell(int index) const
    {
        if (index < 0 || index > 8) 
        {
            return ""; // Return empty string if index is invalid
        }
        else
        {
            return board_[index];
        }
        
    }
    bool isFull() const
    {
        for (const auto& cell : board_)
        {
            if (isdigit(cell[0])) {
                return false; // There is still an unoccupied cell
            }
        }
        return true; // All cells are occupied
        
    }

    bool occupiedCell(int i) const
    {
        if (board_[i - 1] == "1" ||
            board_[i - 1] == "2" ||
            board_[i - 1] == "3" ||
            board_[i - 1] == "4" ||
            board_[i - 1] == "5" ||
            board_[i - 1] == "6" ||
            board_[i - 1] == "7" ||
            board_[i - 1] == "8" ||
            board_[i - 1] == "9")
        {
            return false;
        }
        else return true;
    }

    void clearBoard()
    {
        board_ = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    }

    void setSpot(int i, string s)
    {
        board_[i] = s;
    }


    std::vector<std::string> getBoardState() const {
        return board_;
    }

    void setBoardState(const std::vector<std::string>& newBoardState) {
        if (newBoardState.size() == board_.size()) {
            board_ = newBoardState;
        }
        else {
            // Optional: Handle error if the input size doesn't match the board size
            std::cerr << "Error: Mismatched board state size.\n";
        }
    }

    bool boardisEmpty() {
        if (board_[0] == "1"
            && board_[1] == "2"
            && board_[2] == "3"
            && board_[3] == "4"
            && board_[4] == "5"
            && board_[5] == "6"
            && board_[6] == "7"
            && board_[7] == "8"
            && board_[8] == "9")
        {
            return true;
        }
        else return false;
    }

private:
    vector<string> board_ = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };  // This is the initial state of the board in every game
    string title_ = "\n== Tic Tac Toe ==\n=================";
    string horizontalDivider_ = "\n-----------------";
    string verticalDivider_ = "  |  ";
    string leftEdge_ = "\n ";
    string rightEdge_ = "  ";
};

