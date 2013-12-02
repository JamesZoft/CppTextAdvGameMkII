#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include "RoomMovementComponent.h"

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:

		artemis::ComponentMapper<RoomMovementComponent> roomMovementMapper;
		artemis::ComponentMapper<PositionComponent> positionMapper;
	public:
		MovementSystem() {
			addComponentType<RoomMovementComponent>();
			addComponentType<PositionComponent>();
		};

		virtual void initialize() {
			roomMovementMapper.init(*world);
			positionMapper.init(*world);
		};

		virtual void processEntity(artemis::Entity &e) {
			//positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
			//positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
		};
};

