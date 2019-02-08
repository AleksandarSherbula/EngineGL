#pragma once

#include "shader.h"
#include "texture.h"
#include "math.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader& shader);

	void drawSprite(Texture& texture, Vector2 position, float rotate = 0.0f, 
		Vector2 size = Vector2(10.0f), Vector3 color = Vector3(1.0f));
private:
	Shader mShader;
	unsigned int mQuadVAO;
	void initData();
};