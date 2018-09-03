#include "Triangle.h"

Triangle::Triangle(Renderer* renderer) : Entity(renderer)
{
}


Triangle::~Triangle()
{
}

void Triangle::Draw()
{
	if (shoulDispose)
	{
		renderer->DrawBuffer(bufferID, vtxCount);
	}
}

void Triangle::SetVertices(float * vertices, int _vtxCount)
{
	vertex = vertices;
	vtxCount = _vtxCount;
	bufferID = renderer->GenBuffer(vertex, vtxCount);
	shoulDispose = true;
}
