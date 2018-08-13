#pragma once

#include "GameBase.h"

class Game : public GameBase
{
private:
	int contador = 0;
protected:
	bool OnStart() override;
	bool OnStop() override;
	bool OnUpdate() override;
public:
	Game();
	~Game();
};

