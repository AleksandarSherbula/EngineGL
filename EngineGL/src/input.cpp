#include "input.h"
#include "GLFW\glfw3.h"

bool Input::Keys[1024];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Input::Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			Input::Keys[key] = GL_FALSE;
	}
}

