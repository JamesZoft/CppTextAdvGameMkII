#include "CommandAnalyser.h"
#include <string>
#include "InputCallback.h"
#include <vector>
#include "MovementSystem.h"
#include <functional>
#include "Artemis\Entity.h"
#include "PositionComponent.h"
#include "Artemis\ComponentType.h"
#include "Artemis\SystemManager.h"
#include "Console.h"
#include "cpp-utils-master\stringutils.hpp"

const enum Commands { attack = 0, move, pickup, look };
const std::vector<std::string> strCommands {"attack", "move", "pickup", "look"};

CommandAnalyser::CommandAnalyser()
{
}

void blah(artemis::SystemManager* sm)
{
	sm->getSystem<MovementSystem>();
}

void CommandAnalyser::analyse(std::string command)
{
	if (command.find("attack"))
	{

	}
	if (command.find("move") != command.npos)
	{
		if (command == "move")
		{
			std::string fullCommand("move ");
			std::cout << "Move where? Your options are:" << std::endl;
			listAvailablePositions(sm, player);
			std::string id;
			std::cin >> id;
			fullCommand += id;
			return analyse(fullCommand);
		}
		//else
		//{
		//	MovementSystem* ms = sm->getSystem<MovementSystem>();
		//	std::string inputMoveLocation = util::string::split(command, " ")[1];
		//	PositionComponent* nextPos = ms->getPositionComponentWithId(util::string::to<int>(inputMoveLocation));
		//	return [=](artemis::Entity* e) { return ms->moveEntity(e, nextPos); };
		//}
	}
	else
	{

	}
}



CommandAnalyser::~CommandAnalyser()
{
}
