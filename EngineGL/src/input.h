#pragma once

struct GLFWwindow;

struct Input
{
	static bool Keys[1024];
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);