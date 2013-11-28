#include "Console.h"
#include <string>
#include <iostream>


Console::Console()
{
}

void Console::write(std::string str)
{
	std::cout << str << std::endl;
}

Console::~Console()
{
}
