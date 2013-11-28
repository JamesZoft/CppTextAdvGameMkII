#pragma once
#include <string>
#include "InputCallback.h"

class CommandAnalyser
{
public:
	CommandAnalyser();
	bool analyse(std::string command, InputCallback *callback);
	~CommandAnalyser();
private:
	std::string* stringCommands;
};

