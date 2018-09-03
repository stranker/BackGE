#pragma once
#include "Renderer.h"
#include "Material.h"
class Entity
{
public:
	Entity(Renderer* renderer);
	~Entity();
	virtual void Draw() = 0;
protected:
	Renderer * renderer;
};

