#include "resourceManager.h"

#include "GL\glew.h"
#include "SOIL\SOIL.h"

#include <sstream>
#include <fstream>

std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture> ResourceManager::textures;

Shader ResourceManager::setShader(const char* filepath, std::string name)
{
	shaders[name] = loadShaderFromFile(filepath);
	return shaders[name];
}

Shader& ResourceManager::getShader(std::string name)
{
	return shaders[name];
}

Texture ResourceManager::setTexture(const char* filepath, std::string name, bool isAlpha)
{
	textures[name] = loadTextureFromFile(filepath, isAlpha);
	return textures[name];
}

Texture& ResourceManager::getTexture(std::string name)
{
	return textures[name];
}

void ResourceManager::clear()
{
	for (auto iter : shaders)
		glDeleteProgram(iter.second.mID);
	for (auto iter : textures)
		glDeleteTextures(1, &iter.second.mID);
}

Shader ResourceManager::loadShaderFromFile(const char* filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else if (type != ShaderType::NONE)
		{
			ss[(int)type] << line << "\n";
		}
	}

	Shader shader;
	shader.createShader(ss[0].str().c_str(), ss[1].str().c_str(), nullptr);
	return shader;
}

Texture ResourceManager::loadTextureFromFile(const char * filepath, bool isAlpha)
{
	Texture texture;
	if (isAlpha)
	{
		texture.mInternalFormat = GL_RGBA;
		texture.mImageFormat = GL_RGBA;
	}

	int width, height;
	unsigned char* data = SOIL_load_image(filepath, &width, &height, 0, texture.mImageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

	texture.generate(width, height, data);
	SOIL_free_image_data(data);
	return texture;
}
