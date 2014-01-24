#pragma once
#include "InputMovementComponent.h"
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"

class InputMovementSystem : public artemis::EntityProcessingSystem
{
private:
	artemis::ComponentMapper<InputMovementComponent> inputMapper;

public:
	InputMovementSystem() {
		addComponentType<InputMovementComponent>();
	};
	void processEntity(artemis::Entity &e);
	void processEntities(artemis::ImmutableBag<artemis::Entity*> & bag);
	bool checkProcessing();
	void initialize() {
		inputMapper.init(*world);
	};
	InputMovementSystem();
	~InputMovementSystem();
};

