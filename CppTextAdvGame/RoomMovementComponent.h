#pragma once
#include "Artemis\Component.h"
#include "PositionComponent.h"
#include <string>
class RoomMovementComponent : public artemis::Component
{
public:
	RoomMovementComponent();
	Room moveRoom(PositionComponent currPos, std::string newRoom);
	~RoomMovementComponent();
};

