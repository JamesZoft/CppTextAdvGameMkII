#pragma once
#include <string>
#include "InputCallback.h"
#include "Artemis\Entity.h"

class CommandAnalyser
{
public:
	CommandAnalyser();
	std::function<bool(artemis::Entity&)> analyse(std::string command);
	~CommandAnalyser();
private:
	std::string* stringCommands;
};

