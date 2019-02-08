#pragma once

#include "shader.h"
#include "texture.h"

#include <map>
#include <string>

class ResourceManager
{
public:
	static std::map<std::string, Shader> shaders;
	static std::map<std::string, Texture> textures;

	static Shader setShader(const char* filepath, std::string name);
	static Shader& getShader(std::string name);

	static Texture setTexture(const char* filepath, std::string name, bool isAlpha);
	static Texture& getTexture(std::string name);

	static void clear();
private:
	ResourceManager() {}
	static Shader loadShaderFromFile(const char* filepath);
	static Texture loadTextureFromFile(const char* filepath, bool isAlpha);
};