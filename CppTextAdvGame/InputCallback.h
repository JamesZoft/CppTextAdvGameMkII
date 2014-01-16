#pragma once
#include "Artemis\SystemManager.h"
#include "Artemis\Entity.h"
class InputCallback
{
public:
	virtual ~InputCallback();
	void InputCallback::listAvailablePositions(artemis::SystemManager*, artemis::World, artemis::Entity&);
};

