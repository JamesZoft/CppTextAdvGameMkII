#include "Game.h"
#include <string>
#include <iostream>
#include "Console.h"
#include "GameCallback.h"
#include "CommandAnalyser.h"
#include "Artemis\World.h"
#include "MovementSystem.h"
#include "Artemis\SystemManager.h"
#include "Artemis\Entity.h"
#include <windows.h>

Game::Game()
{
}

void Game::play()
{
	using namespace std;
	string name;
	cout << "Please enter your name!" << endl;
	cin >> name;
	Console::write("Welcome to Erazhar, the magical castle of the dreaded Lord Torhazar! You must find your way through the maze of rooms to the room where Torhaz resides,");
	Console::write("and kill him. He has many monsters guarding his maze, but there are also magical treasures lost in the ages, awaiting your discovery!\n");
	Console::write(std::string("Good luck, ") + name + std::string("!"));
	bool playing = true;
	CommandAnalyser *analyser = new CommandAnalyser;
	artemis::World world;
	artemis::SystemManager * sm = world.getSystemManager();
	MovementSystem *movementSys = (MovementSystem*)sm->setSystem(new MovementSystem());
	artemis::EntityManager * em = world.getEntityManager();
	sm->initializeAll();

	artemis::Entity &player = em->create();

	player.refresh();

	player.addComponent(movementSys->getPositionComponentWithId(0));
	while (playing)
	{
		world.loopStart();
		movementSys->process();
		std::string input;
		cin >> input;
		std::function<bool (artemis::Entity*)> returnFunc = analyser->analyse(input, world, &player);
		if (returnFunc == nullptr)
			playing = false;
		else
			returnFunc(&player);
        Sleep(160);
	}
}


Game::~Game()
{
}
