#include "window.h"

#include <iostream>

Window::Window(const char* title, int width, int height)
	: mTitle(title), mWidth(width), mHeight(height)
{
	init();
}

void Window::init()
{
	if (!glfwInit())
		std::cout << "Failed to initialize GLFW.\n";

	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
	if (!mWindow)
	{
		glfwTerminate();
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetFramebufferSizeCallback(mWindow, windowResize);
	glfwSetKeyCallback(mWindow, key_callback);
	glfwMakeContextCurrent(mWindow);

	if (glewInit() != GLEW_OK)
		std::cout << "Failed to initialize GLEW." << "\n";

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::cout << glGetString(GL_VERSION) << std::endl;
}

bool Window::closed()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(mWindow, true);
	}
	return glfwWindowShouldClose(mWindow);
}

void Window::clear(float r, float g, float b, float a)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(r, g, b, a);
}

void Window::update()
{
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}

void windowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
