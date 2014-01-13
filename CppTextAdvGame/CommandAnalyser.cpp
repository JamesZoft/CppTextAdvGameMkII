#include "CommandAnalyser.h"
#include <string>
#include "InputCallback.h"
#include <vector>
#include "MovementSystem.h"
#include <functional>
#include "Artemis\Entity.h"
#include "PositionComponent.h"
#include "Artemis\ComponentType.h"

const enum Commands { attack = 0, move, pickup, look };
const std::vector<std::string> strCommands {"attack", "move", "pickup", "look"};

CommandAnalyser::CommandAnalyser()
{
}

std::function<bool (artemis::Entity&)> CommandAnalyser::analyse(std::string command)
{
	if (command == "attack")
	{

	}
	if (command == "move")
	{
		PositionComponent nextPos;
		return [=, &ms](artemis::Entity& e) { return ms.moveEntity(e, nextPos); };
	}
	return nullptr;
}

CommandAnalyser::~CommandAnalyser()
{
}
