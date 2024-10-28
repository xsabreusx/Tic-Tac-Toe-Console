#pragma once

#include "BoardManager.hpp"
#include "BasePlayer.hpp"
#include "RuleChecker.hpp"


class BattleTTT
{
private:
	
	BasePlayer* player1;
	BasePlayer* player2;

	BoardManager* boardManager;  // Reference to BoardManager for board operations
	RuleChecker* ruleChecker;    // Reference to RuleChecker for validating moves and checking wins

	int player1Streak = 0;
	int player2Streak = 0;

public:

	BattleTTT(BasePlayer* p1, BasePlayer* p2, BoardManager* board, RuleChecker* rules) {
		this->player1 = p1;
		this->player2 = p2;
		this->boardManager = board;
		this->ruleChecker = rules;
	}


	void runGameLoop() {
		cout << "\nImplementation in progress please try again soon...";
	}


};

