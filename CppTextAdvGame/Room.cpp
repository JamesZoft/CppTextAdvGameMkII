#include "Room.h"
#include <string>

Room::Room()
{
}

void Room::setName(std::string _name)
{
	name = _name;
}

std::string Room::getName()
{
	return name;
}

Room::~Room()
{
}
