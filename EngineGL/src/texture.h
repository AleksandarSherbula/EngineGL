#pragma once

class Texture
{
public:
	unsigned int mID;

	int mWidth, mHeight;

	unsigned int mInternalFormat;
	unsigned int mImageFormat;

	unsigned int mWrapS;
	unsigned int mWrapT;
	unsigned int mFilterMin;
	unsigned int mFilterMax;

	Texture();
	void generate(unsigned int width, unsigned int height, unsigned char* data);

	void bind(int slot);
	void unbind();
};