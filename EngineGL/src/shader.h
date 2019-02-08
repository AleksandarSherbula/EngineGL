#pragma once

#include "math.h"

class Shader
{
public:
	unsigned int mID;

	Shader() {}
	void bind();
	void createShader(const char* vertexSource, const char* fragmentSource, const char* geometrySource);
private:
	unsigned int compileShader(const char* source, unsigned int type);
public:
	void setUniformInteger(const char* name, int value);
	void setUniformFloat(const char* name, float value);
	void setUniformVector2f(const char* name, float x, float y);
	void setUniformVector2f(const char* name, Vector2& value);
	void setUniformVector3f(const char* name, float x, float y, float z);
	void setUniformVector3f(const char* name, Vector3& value);
	void setUniformVector4f(const char* name, float x, float y, float z, float w);
	void setUniformVector4f(const char* name, Vector4& value);
	void setUniformMatrix4fv(const char* name, Matrix4& matrix);
};