#pragma once
#pragma comment(lib, "ArtemisCpp.lib")
#include "Artemis\Component.h"

class VelocityComponent : public artemis::Component
{
	public:
		float velocityX;
		float velocityY;

		VelocityComponent(float velocityX, float velocityY)
		{
			this->velocityX = velocityX;
			this->velocityY = velocityY;
		};
};

