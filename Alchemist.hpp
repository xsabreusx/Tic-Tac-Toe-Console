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
			cin.ignore();
			cout << "\nStop wasting time and pick a valid move!";
			cin >> boardMove;
		}

		board->makeMove(boardMove-1, mark);

	}

	void prompt() override {

		int moveNumber = 0;

		cout << "\nMatter itself is my plaything!!";
		if (specialAvailability)
		{
			cout << "\n(1) Normal Move";
			cout << "\n(2) Special Move";
			cout << "\nAwaiting choice: ";
			cin >> moveNumber;
			while (cin.fail() || moveNumber < 1 || moveNumber > 2)
			{
				cin.clear();
				cin.ignore();
				cout << "\nWe are wasting time. Try again: ";
				cin >> moveNumber;
			}
			if (moveNumber == 1)
			{
				move();
			}
			if (moveNumber == 2)
			{
				specialMove();
			}
		}
		else {
			cout << "\nMy victory is inevitable...";
			move();
		}
		
	}

	void specialMove()
	{
		int spotMove1 = 0;
		int spotMove2 = 0;

		string temp;
		cout << "\n" << archetypeSpecial << " has been cast!!";
		cout << "\nSelect an occupied spot in the board to Transmute: ";
		cin >> spotMove1;
		while (cin.fail() || spotMove1 < 1 || spotMove1 > 9 || !board->occupiedCell(spotMove1)) {
			cin.clear();
			cin.ignore();
			cout << "\nStop wasting time and pick a valid move!";
			cin >> spotMove1;
		}

		cout << "\nSelect another occupied spot in the board to transmute: ";
		cin >> spotMove2;
		while (cin.fail() || spotMove2 < 1 || spotMove2 > 9 || !board->occupiedCell(spotMove1)) {
			cin.clear();
			cin.ignore();
			cout << "\nStop wasting time and pick a valid move!";
			cin >> spotMove2;
		}

		temp = board->getCell(spotMove1-1);
		board->setSpot(spotMove1 - 1, board->getCell(spotMove2-1));
		board->setSpot(spotMove2-1, temp);
		
		cout << "\nBehold the power of transmutation!! Mwahahaha";

	}

	void addWin()
	{
		winStreak = winStreak+1;
	}

	int getWinStreak() {
		return winStreak;
	}

	bool getSpecialAvailability()
	{
		return specialAvailability;
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

