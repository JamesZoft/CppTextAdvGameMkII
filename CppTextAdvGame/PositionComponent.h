#pragma once
#include "Artemis\Component.h"
#include "Room.h"

class PositionComponent : public artemis::Component
{
	public:
		int* uniqueRoomId;
		PositionComponent(int* uniqueRoomId)
		{
			this->uniqueRoomId = uniqueRoomId;
		};
};

