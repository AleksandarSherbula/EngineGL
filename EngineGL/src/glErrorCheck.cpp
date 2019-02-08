#include "glErrorCheck.h"

#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	if (GLenum errorCode = glGetError())
	{
		const char* error = "NO ERROR";
		switch (errorCode)
		{
		case GL_INVALID_ENUM:					error = "INVALID ENUM";						break;
		case GL_INVALID_VALUE:					error = "INVALID VALUE";					break;
		case GL_INVALID_OPERATION:				error = "INVALID OPERATION";				break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:	error = "INVALID FRAMEBUFFER OPERATION";	break;
		case GL_OUT_OF_MEMORY:					error = "OUT OF MEMORY";					break;
		}
		std::cout << "[OpenGL error]: " << error << ": "
			<< function << ": " << file << ": " << line << std::endl;

		return false;
	}

	return true;
}