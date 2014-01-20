#pragma once
#include "Artemis\Entity.h"
class EntityFactory
{
public:
	artemis::Entity* createPlayer();
	EntityFactory(artemis::EntityManager& _em) : em(_em)
	{};
private:
	artemis::EntityManager& em;
};

