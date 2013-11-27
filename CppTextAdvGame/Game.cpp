#include "Game.h"
#include <string>
#include <iostream>
#include "Console.h">



Game::Game()
{
}

void Game::play()
{
	using namespace std;
	string name;
	cout << "Please enter your name!" << endl;
	cin >> name;
	Console::write("Welcome to Erazhar, the magical castle of the dreaded Lord Torhazar! You must find your way through the maze of rooms to the room where Torhazar resides,");
	Console::write("and kill him. He has many monsters guarding his maze, but there are also magical treasures, lost in the ages awaiting your discovery!\n");
	Console::write(std::string("Good luck, ") + name + std::string("!"));
	bool playing = true;
	while (playing)
	{
		std::string input;
		cin >> input;
		playing = CommandAnalyser::analyse
	}
}


Game::~Game()
{
}
