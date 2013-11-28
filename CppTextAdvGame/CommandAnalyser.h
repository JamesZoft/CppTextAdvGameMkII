#pragma once
#include <string>

class CommandAnalyser
{
public:
	CommandAnalyser();
	bool analyse(std::string command);
	~CommandAnalyser();
};

