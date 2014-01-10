#pragma once
#include "Artemis\Component.h"
#include "Room.h"

class PositionComponent : public artemis::Component
{

private:
	const int uniqueRoomId;
public:
	PositionComponent(int _uniqueRoomId) : uniqueRoomId(_uniqueRoomId)
	{};
};

