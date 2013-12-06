#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include <map>

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:
		artemis::ComponentMapper<PositionComponent> positionMapper;
	public:
		MovementSystem() {
			addComponentType<PositionComponent>();
		};

		virtual void initialize() {
			positionMapper.init(*world);
		};

		void processEntity(artemis::Entity &e);
};

