#include "RoomMovementComponent.h"
#include "Artemis\Component.h"
#include "Room.h"
#include <string>

RoomMovementComponent::RoomMovementComponent()
{
}

Room RoomMovementComponent::moveRoom(PositionComponent currPos, std::string newRoom)
{
	Room *r = new Room();
	return *r;
}

RoomMovementComponent::~RoomMovementComponent()
{
}
