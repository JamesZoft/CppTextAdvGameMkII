#pragma once
#include <string>
#include "InputCallback.h"
#include "Artemis\Entity.h"
#include "Artemis\SystemManager.h"
#include <functional>

class CommandAnalyser
{
public:
	CommandAnalyser();
	void analyse(std::string);
	void listAvailablePositions(artemis::SystemManager*, artemis::Entity &player);
	~CommandAnalyser();
private:
	std::string* stringCommands;
};

