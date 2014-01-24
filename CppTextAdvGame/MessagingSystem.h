#pragma once
#include "Artemis\EntityProcessingSystem.h"
#include "Message.h"
#include "Artemis\ComponentMapper.h"
class MessagingSystem : public artemis::EntityProcessingSystem
{
private:
	artemis::ComponentMapper<Message> messageMapper;
public: 
	MessagingSystem() {
		addComponentType<Message>();
	};
	void processEntity(artemis::Entity &e);
	void processEntities(artemis::ImmutableBag<artemis::Entity*> & bag);
	bool checkProcessing();
	void initialize() {
		messageMapper.init(*world);
	};
	~MessagingSystem();
};

