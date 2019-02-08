#pragma once

#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "input.h"

class Window
{
private:
	const char* mTitle;
	float mWidth, mHeight;
	GLFWwindow* mWindow;
	void init();
public:
	Window() {}
	Window(const char* title, int width, int height);
	bool closed();
	void clear(float r, float g, float b, float a);
	void update();
};
void windowResize(GLFWwindow* window, int width, int height);