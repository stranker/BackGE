#include "GameBase.h"
#include "TypeDefs.h"
#include "Triangle.h"

#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>

GLuint VertexArrayID;


GameBase::GameBase(int _screenWidht, int _screenHeight, string _screenName) :
	screenHeight(_screenHeight),
	screenWidth(_screenWidht),
	screenName(_screenName)
{
}
GameBase::~GameBase()
{
}
bool GameBase::Start()
{
	cout << "GameBase::Start()" << endl;	
	window = new Window(screenHeight,screenWidth,screenName);
	if (!window->Start())
	{
		return false;
	}
	renderer = new Renderer(window);
	if (!renderer->Start())
	{
		return false;
	}
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	return OnStart();
}
bool GameBase::Stop()
{
	cout << "GameBase::Stop()" << endl;
	OnStop();
	if (renderer != NULL)
	{

		renderer->Stop();
		delete renderer;
	}
	if (window != NULL)
	{
		window->Stop();
		delete window;
	}
	return true;
}
void GameBase::Loop()
{
	cout << "GameBase::Loop()" << endl;
	bool aux = true;
	Triangle* triangulo = new Triangle(renderer);
	float g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	triangulo->SetVertices(g_vertex_buffer_data, 3);
	do
	{
		aux = OnUpdate();
		renderer->SetClearColor(1, 0, 1, 1);
		triangulo->Draw();
		renderer->ClearScreen();
		renderer->SwapBuffers();
		window->PollEvents();
	} while (aux && !window->ShouldClose());
}
