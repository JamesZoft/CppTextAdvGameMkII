#pragma once
#include <string>
class MessageFactory
{
public:
	MessageFactory();
	std::string generateRoomListMessage();
	~MessageFactory();
};

