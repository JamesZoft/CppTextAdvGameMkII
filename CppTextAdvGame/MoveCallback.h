#pragma once
#include "InputCallback.h"

class MoveCallback :
	public InputCallback
{
public:
	MoveCallback();
	bool executeCallback();
	~MoveCallback();
};

