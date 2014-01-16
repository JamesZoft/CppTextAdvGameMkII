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
	std::function<bool(artemis::Entity&)> analyse(std::string, artemis::World, artemis::Entity &player);
	void listAvailablePositions(artemis::SystemManager*, artemis::Entity &player);
	~CommandAnalyser();
private:
	std::string* stringCommands;
};

