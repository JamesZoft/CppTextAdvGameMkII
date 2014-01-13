#include "UniqueRoomIdFactory.h"


UniqueRoomIdFactory::UniqueRoomIdFactory()
{
}

int UniqueRoomIdFactory::generateNewUniqueRoomId()
{
	return currMaxId++;
}

UniqueRoomIdFactory::~UniqueRoomIdFactory()
{
}
