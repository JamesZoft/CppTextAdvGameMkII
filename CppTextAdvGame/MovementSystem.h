#pragma once
#pragma comment(lib, "ArtemisCpp.lib")
#include "Artemis\EntityProcessingSystem.h"
#include "Artemis\ComponentMapper.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"

class MovementSystem : public artemis::EntityProcessingSystem
{
	private:
		artemis::ComponentMapper<VelocityComponent> velocityMapper;
		artemis::ComponentMapper<PositionComponent> positionMapper;
	public:
		MovementSystem() {
			addComponentType<VelocityComponent>();
			addComponentType<PositionComponent>();
		};

		virtual void initialize() {
			velocityMapper.init(*world);
			positionMapper.init(*world);
		};

		virtual void processEntity(artemis::Entity &e) {
			positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
			positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
		};
};
