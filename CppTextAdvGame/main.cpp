#include "Game.h"
#ifdef _MSC_VER
#pragma comment (lib, "ArtemisCpp.lib")
#endif


int main()
{
	Game* game = new Game();
	game->play();
}