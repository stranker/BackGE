#pragma once
#include "Entity.h"
class Triangle :
	public Entity
{
private:
	float* vertex;
	int vtxCount;
	bool shoulDispose = false;
	unsigned int bufferID;
public:
	Triangle(Renderer* renderer);
	~Triangle();
	void Draw() override;
	void SetVertices(float* vertices, int vtxCount);
};

