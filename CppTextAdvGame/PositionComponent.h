#pragma once
#include "Artemis\Component.h"
#include "Room.h"
#include "UniqueRoomIdFactory.h"

class PositionComponent : public artemis::Component
{

private:
	const int uniqueRoomId;
public:
	PositionComponent() : uniqueRoomId(UniqueRoomIdFactory::generateNewUniqueRoomId())
	{};
	const int getUniqueRoomId();
	
};
bool operator==(PositionComponent, PositionComponent);
