#include "Game.h"

int main() {
	Game* game = new Game();
	if (game->Start())
	{
		game->Loop();
	}
	// TODO: startup
	game->Stop();
	cin.get();
	delete game;
	
	return 0;
}