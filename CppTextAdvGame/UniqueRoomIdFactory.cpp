#include "UniqueRoomIdFactory.h"

int UniqueRoomIdFactory::currMaxId;

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
