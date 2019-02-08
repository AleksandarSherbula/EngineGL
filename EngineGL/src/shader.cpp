#include "shader.h"

#include "GL\glew.h"
#include "glErrorCheck.h"

#include <iostream>

void Shader::bind()
{
	GLCall(glUseProgram(mID));
}

void Shader::createShader(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
{
	unsigned int vs, fs, gs;

	vs = compileShader(vertexSource, GL_VERTEX_SHADER);
	fs = compileShader(fragmentSource, GL_FRAGMENT_SHADER);

	if (geometrySource != nullptr)
	{
		gs = compileShader(geometrySource, GL_GEOMETRY_SHADER);
	}

	GLCall(mID = glCreateProgram());
	GLCall(glAttachShader(mID, vs));
	GLCall(glAttachShader(mID, fs));

	if (geometrySource != nullptr)
	{
		GLCall(glAttachShader(mID, gs));
	}

	GLCall(glLinkProgram(mID));
	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	if (geometrySource != nullptr)
	{
		GLCall(glDeleteShader(gs));
	}
}

unsigned int Shader::compileShader(const char * source, unsigned int type)
{
	GLCall(GLuint id = glCreateShader(type));
	GLCall(glShaderSource(id, 1, &source, nullptr));
	GLCall(glCompileShader(id));

	int result;
	GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (!result)
	{
		int length;
		GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
		char* message = (char*)alloca(length * sizeof(char));
		GLCall(glGetShaderInfoLog(id, length, &length, message));
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
			<< " shader." << std::endl;
		std::cout << message << std::endl;

		GLCall(glDeleteShader(id));
	}

	return id;
}

void Shader::setUniformInteger(const char* name, int value)
{
	GLCall(glUniform1i(glGetUniformLocation(mID, name), value));
}

void Shader::setUniformFloat(const char* name, float value)
{
	GLCall(glUniform1f(glGetUniformLocation(mID, name), value));
}

void Shader::setUniformVector2f(const char* name, float x, float y)
{
	GLCall(glUniform2f(glGetUniformLocation(mID, name), x, y));
}

void Shader::setUniformVector2f(const char* name, Vector2& value)
{
	GLCall(glUniform2f(glGetUniformLocation(mID, name), value.x, value.y));
}

void Shader::setUniformVector3f(const char* name, float x, float y, float z)
{
	GLCall(glUniform3f(glGetUniformLocation(mID, name), x, y, z));
}

void Shader::setUniformVector3f(const char* name, Vector3& value)
{
	GLCall(glUniform3f(glGetUniformLocation(mID, name), value.x, value.y, value.z));
}

void Shader::setUniformVector4f(const char* name, float x, float y, float z, float w)
{
	GLCall(glUniform4f(glGetUniformLocation(mID, name), x, y, z, w));
}

void Shader::setUniformVector4f(const char* name, Vector4& value)
{
	GLCall(glUniform4f(glGetUniformLocation(mID, name), value.x, value.y, value.z, value.w));
}

void Shader::setUniformMatrix4fv(const char* name, Matrix4& matrix)
{
	GLCall(glUniformMatrix4fv(glGetUniformLocation(mID, name), 1, GL_FALSE, matrix.mElements));
}
