#include "texture.h"
#include "glErrorCheck.h"

#include "GL\glew.h"

#include <iostream>

Texture::Texture()
	:mWidth(0), mHeight(0), mInternalFormat(GL_RGB), mImageFormat(GL_RGB), mWrapS(GL_REPEAT),
	mWrapT(GL_REPEAT), mFilterMin(GL_LINEAR), mFilterMax(GL_LINEAR)
{
	GLCall(glGenTextures(1, &mID));
}

void Texture::generate(unsigned int width, unsigned int height, unsigned char* data)
{
	mWidth = width;
	mHeight = height;
	GLCall(glBindTexture(GL_TEXTURE_2D, mID));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mWrapS));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mWrapT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mFilterMin));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mFilterMax));

	if (data)
	{
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, mInternalFormat, mWidth, mHeight, 0, mImageFormat, GL_UNSIGNED_BYTE, data));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));
	}
	else
	{
		std::cout << "Failed to load texture.\n";
	}

}

void Texture::bind(int slot)
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, mID));
}

void Texture::unbind()
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}