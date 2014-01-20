#include "EntityFactory.h"
#include "MovementComponent.h"
#include "InputMovementComponent.h"
#include "PositionComponent.h"

using namespace artemis;

Entity* EntityFactory::createPlayer()
{
	Entity* player = &em.create();
	player->addComponent(new MovementComponent());
	player->addComponent(new InputMovementComponent());
	player->addComponent(new PositionComponent());
	return player;
}