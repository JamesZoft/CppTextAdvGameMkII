#pragma once
class UniqueRoomIdFactory
{
public:
	UniqueRoomIdFactory();
	static int generateNewUniqueRoomId();
	~UniqueRoomIdFactory();
private:
	static int currMaxId;
};

