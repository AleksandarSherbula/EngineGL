#pragma once

#include "math.h"
#include "spriteRenderer.h"

class GameObject
{
public:
	Vector2 mPosition;
	float mRotation;
	Vector2 mSize;
	Texture mSprite;
	Vector3 mColor;

	bool isSolid;
	bool isDestroyed;

	GameObject();
	GameObject(Vector2 position, float rotation, Vector2 size, Texture& sprite, Vector3 color = Vector3(1.0f));

	virtual void draw(SpriteRenderer& renderer);
};