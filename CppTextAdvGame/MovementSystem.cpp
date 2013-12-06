#include "MovementSystem.h"
#include "Artemis\Entity.h"

void MovementSystem::processEntity(artemis::Entity &e)
{
	PositionComponent &c = *positionMapper.get(e);
	if (c.uniqueRoomId != nullptr)
	{
		
	}
}