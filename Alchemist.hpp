#pragma once

#include "BasePlayer.hpp"
#include "BoardManager.hpp"


class Alchemist : public BasePlayer
{
private:
	string archetypeSpecial = "Transmutation";
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
			cout << "\nStop wasting time! Pick a valid move: ";
			cin >> boardMove;
		}

		board->makeMove(boardMove-1, mark);

	}

	void prompt() override {

		int moveNumber = 0;

		cout << "\nMatter itself is the Alchemist's plaything!!";
		if (specialAvailability)
		{
			cout << "\n(1) Normal Move";
			cout << "\n(2) Transmutation";
			cout << "\nAwaiting choice: ";
			cin >> moveNumber;
			while (cin.fail() || moveNumber < 1 || moveNumber > 2)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nWe are wasting time. Try again: ";
				cin >> moveNumber;
			}
			if (moveNumber == 1)
			{
				move();
			}
			if (moveNumber == 2 && countOccupiedSpots() >= 2)
			{
				specialMove();
			}
			if (moveNumber == 2 && countOccupiedSpots() < 2)
			{
				cout << "\nI need at least two occupied spots on the board to use my transmutation power...";
				move();
			}
		}
		else {
			cout << "\nMy victory is inevitable...";
			move();
		}
		
	}

	void specialMove() override // The alchemist special move 
	{
		int spotMove1 = 0;
		int spotMove2 = 0;

		string temp;
		cout << "\n" << archetypeSpecial << " has been cast!!";
		cout << "\nSelect an occupied spot in the board to Transmute: ";
		cin >> spotMove1;
		while (cin.fail() || spotMove1 < 1 || spotMove1 > 9 || !board->occupiedCell(spotMove1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nStop wasting time and pick a valid move!: ";
			cin >> spotMove1;
		}

		cout << "\nSelect another occupied spot in the board to transmute: ";
		cin >> spotMove2;
		while (cin.fail() || spotMove2 < 1 || spotMove2 > 9 || !board->occupiedCell(spotMove2)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nStop wasting time and pick a valid move!: ";
			cin >> spotMove2;
		}

		temp = board->getCell(spotMove1-1);
		board->setSpot(spotMove1 - 1, board->getCell(spotMove2-1));
		board->setSpot(spotMove2-1, temp);
		specialMoveCount++;
		cout << "\n\n*'**'**'**'**'**'**'**'**'**'**'**'**'**'**'**'**'**'";
		cout << "\n*'* BEHOLD THE POWER OF TRANSMUTATION!! MWAHAHAHA *'*";
		cout << "\n*'**'**'*'**'*'**'*'**'*'**'*'**'*'**'*'**'*'**'*'**'";
		
	}

	void addWin() override
	{
		winStreak = winStreak+1;
	}

	int getWinStreak()override {
		return winStreak;
	}

	bool getSpecialAvailability() override
	{
		return specialAvailability;
	}

	int countOccupiedSpots() const {
		int occupiedCount = 0;
		for (int i = 1; i <= 9; ++i) {
			if (board->occupiedCell(i)) {  // Check each cell for occupancy
				++occupiedCount;
			}
		}
		return occupiedCount;
	}

	// Constructor options. 
	Alchemist(BoardManager* b, string n, string m)
	{
		mark = m;
		name = n;
		this->board = b;
	}

	Alchemist(BoardManager *b, string m)
	{
		mark = m;
		this->board = b;
	}

};

