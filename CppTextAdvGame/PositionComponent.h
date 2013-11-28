#pragma once
#pragma comment(lib, "ArtemisCpp.lib")
#include "Artemis\Component.h"

class PositionComponent : public artemis::Component
{

	public:
		float posX;
		float posY;
		PositionComponent(float posX, float posY)
		{
			this->posX = posX;
			this->posY = posY;
		};
};

