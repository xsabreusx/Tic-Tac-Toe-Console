#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class GameLogger {
private:
    string logFileName{ "gamelog.txt" };
    int player1_wins = 0;
    int player2_wins = 0;
    int ties = 0;
    string player1_name = "X";
    string player2_name = "O";

public:
    
    // Another method to log the win counts for two players
    void logRecord() {

        ofstream logFile(logFileName, ios::out); // Overwrite mode

        if (!logFile) {
            cerr << "Error: Could not open log file " << logFileName << " for writing." << endl;
            return;
        }

        logFile << "=== Tic Tac Toe Game Log ===\n";
        logFile << "Player 1 (" << player1_name << "): " << player1_wins << " wins\n";
        logFile << "Player 2 (" << player2_name << "): " << player2_wins << " wins\n";
        logFile << "Ties: " << ties << "\n";
        logFile << "============================\n";

        logFile.close();
        cout << "\nGame log updated successfully in " << logFileName << endl;
    }

    
    void clearLog() {
        ofstream logFile(logFileName, ios::out | ios::trunc); // Truncate mode

        if (!logFile) {
            cerr << "\nError: Could not open log file " << logFileName << " for clearing." << endl;
            return;
        }

        logFile.close();
        cout << "\nGame log cleared successfully." << endl;
    }

    // Useful getters and setters
    void setplayer1Wins(int a) {
        player1_wins = a;
    }

    void setplayer2Wins(int a) {
        player2_wins = a;
    }

    int getplayer1Wins() {
        return player1_wins;
    }

    int getplayer2Wins() {
        return player2_wins;
    }

    void setplayer1Name(string a) {
        player1_name = a;
    }

    void setplayer2Name(string a) {
        player2_name = a;
    }

    string getplayer1Name() {
        return player1_name;
    }

    string getplayer2Name() {
        return player2_name;
    }

    void increment_P1() {
        player1_wins++;
    }
    void increment_P2() {
        player2_wins++;
    }

    void increment_Ties() {
        ties++;
    }
};
