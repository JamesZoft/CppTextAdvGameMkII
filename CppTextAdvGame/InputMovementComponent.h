#pragma once
#include "Artemis\Component.h"
#include <string>
class InputMovementComponent : 	public artemis::Component
{
public:
	InputMovementComponent();
	std::string getInput() { return input; }
	~InputMovementComponent();
private:
	std::string input;
};

