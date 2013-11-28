#include "CommandAnalyser.h"
#include <string>
#include "InputCallback.h"
#include <vector>

const enum Commands { attack = 0, move, pickup, look };
const std::vector<std::string> strCommands {"attack", "move", "pickup", "look"};

CommandAnalyser::CommandAnalyser()
{
}

bool CommandAnalyser::analyse(std::string command, InputCallback *callback)
{
	if (command == "attack")
	{

	}
}

CommandAnalyser::~CommandAnalyser()
{
}
