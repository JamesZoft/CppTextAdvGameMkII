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

std::function<bool(artemis::Entity*)> CommandAnalyser::analyse(std::string command, artemis::World world, artemis::Entity& player)
{
	if (command.find("attack"))
	{

	}
	if (command.find("move") != command.npos)
	{
		artemis::SystemManager* sm = world.getSystemManager();
		if (command == "move")
		{
			std::string fullCommand("move ");
			std::cout << "Move where? Your options are:" << std::endl;
			listAvailablePositions(sm, player);
			std::string id;
			std::cin >> id;
			fullCommand += id;
			return analyse(fullCommand, world, player);
		}
		else
		{
			MovementSystem* ms = sm->getSystem<MovementSystem>();
			std::string inputMoveLocation = util::string::split(command, " ")[1];
			PositionComponent* nextPos = ms->getPositionComponentWithId(util::string::to<int>(inputMoveLocation));
			return [=](artemis::Entity* e) { return ms->moveEntity(e, nextPos); };
		}
	}
	else
	{

	}
	return nullptr;
}

void CommandAnalyser::listAvailablePositions(artemis::SystemManager* sm, artemis::Entity &player)
{
	auto adjPositions = ((MovementSystem*)sm->getSystem<MovementSystem>())->getAdjacentPositions(player.getComponent<PositionComponent>());
	for (auto pc : adjPositions)
	{
		Console::write("- " + util::string::from<int>(pc->getUniqueRoomId()));
	}
}

CommandAnalyser::~CommandAnalyser()
{
}
