#pragma once
#include "Exports.h"
#include "Window.h"
#include <iostream>

using namespace std;

class ENGINEDLL_API Renderer
{
private:
	unsigned int VertexArrayID;
public:
	Renderer(Window* _window);
	~Renderer();
	bool Start() const;
	bool Stop() const;
	void SetClearColor(float r, float g, float b,float a);
	void ClearScreen();
	void SwapBuffers();
	unsigned int GenBuffer(float* buffer, int size);
	void DrawBuffer(unsigned int vtxBuffer, int size);
private:
	Window* window;
};

