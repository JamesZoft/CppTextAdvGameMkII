#include "InputMovementSystem.h"

void InputMovementSystem::processEntity(artemis::Entity &e)
{
	std::string input = inputMapper.get(e)->getInput;

}

void InputMovementSystem::processEntities(artemis::ImmutableBag<artemis::Entity*> & bag)
{
	for (int i = 0; i < bag.getCount; i++)
	{
		processEntity(*bag.get(i));
	}
}


bool InputMovementSystem::checkProcessing();
{

}

InputMovementSystem::~InputMovementSystem()
{
}
