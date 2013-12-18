#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include <map>

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:
		artemis::ComponentMapper<PositionComponent> currPosMapper;
		artemis::ComponentMapper<PositionComponent> nextPosMapper;
		bool moveEntity(artemis::Entity &e, PositionComponent &currPos, PositionComponent &nextPos);
	public:
		MovementSystem();

		virtual void initialize() {
			currPosMapper.init(*world);
			nextPosMapper.init(*world);
		};

		void processEntity(artemis::Entity &e);
};

