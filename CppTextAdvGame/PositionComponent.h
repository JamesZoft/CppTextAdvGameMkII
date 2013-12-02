#pragma once
#include "Artemis\Component.h"
#include "Room.h"

class PositionComponent : public artemis::Component
{

	public:
		Room currRoom;
		PositionComponent(Room currRoom)
		{
			this->currRoom = currRoom;
		};
};

