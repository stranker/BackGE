#include "Game.h"



bool Game::OnStart()
{
	cout << "Game::OnStart()" << endl;
	return true;
}

bool Game::OnStop()
{
	cout << "Game::OnStop()" << endl;
	return true;
}

bool Game::OnUpdate()
{
	cout << "Game::OnUpdate()" << endl;
	contador++;
	if (contador > 200)
	{
		return false;
	}
	return true;
}

Game::Game()
{
}


Game::~Game()
{
}
