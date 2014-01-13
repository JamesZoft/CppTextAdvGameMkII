#include "PositionComponent.h"

const int PositionComponent::getUniqueRoomId()
{
	return uniqueRoomId;
}

bool operator==(PositionComponent p1, PositionComponent p2)
{
	return p1.getUniqueRoomId() == p2.getUniqueRoomId();
}