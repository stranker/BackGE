#include "Renderer.h"
#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <glm/glm.hpp>

Renderer::Renderer(Window* _window) :
window(_window)
{	
}


Renderer::~Renderer()
{
}

bool Renderer::Start() const
{
	cout << "Renderer::Start()" << endl;
	glGenVertexArrays(1, (GLuint*)VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glfwMakeContextCurrent((GLFWwindow*)window->GetWindowPrt());
	return true;
}
bool Renderer::Stop() const
{
	cout << "Renderer::Stop()" << endl;
	return true;
}
void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}
void Renderer::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::SwapBuffers() 
{
	glfwSwapBuffers((GLFWwindow*)window->GetWindowPrt());
}

unsigned int Renderer::GenBuffer(float* buffer, int size)
{
	unsigned int vertexBuffer;
	// Generar un buffer, poner el resultado en el vertexbuffer que acabamos de crear
	glGenBuffers(1, &vertexBuffer);
	// Los siguientes comandos le darán características especiales al 'vertexbuffer' 
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	// Darle nuestros vértices a  OpenGL.
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	return vertexBuffer;
}

 void Renderer::DrawBuffer(unsigned int vtxBuffer, int size)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vtxBuffer);
	glVertexAttribPointer(
		0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
		3,                  // tamaño
		GL_FLOAT,           // tipo
		GL_FALSE,           // normalizado?
		0,                    // Paso
		(void*)0            // desfase del buffer
	);
	// Dibujar el triángulo !
	glDrawArrays(GL_TRIANGLES, 0, size); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
	glDisableVertexAttribArray(0);
}
