#pragma once

#include <string>
#include <iostream>
using namespace std;

class BasePlayer
{

public:
	virtual string getMark() = 0;
	virtual void move() = 0;
	virtual void prompt() = 0;
	
	virtual void specialMove() = 0;
	virtual void addWin()=0;
	virtual bool getSpecialAvailability()=0;
	virtual int getWinStreak() = 0;

	virtual ~BasePlayer() = default;
};

