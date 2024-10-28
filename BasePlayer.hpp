#pragma once

#include <string>

class BasePlayer
{

public:
	virtual std::string getMark() = 0;
	virtual void move() = 0;
	virtual void prompt() = 0;
	virtual ~BasePlayer() = default;

};

