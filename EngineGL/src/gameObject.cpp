#include "gameObject.h"

GameObject::GameObject()
	: mPosition(0.0f), mRotation(0.0f), mSize(0.0f), mSprite(), mColor(1.0f), isSolid(false), isDestroyed(false)
{

}

GameObject::GameObject(Vector2 position, float rotation, Vector2 size, Texture& sprite, Vector3 color)
	: mPosition(position), mRotation(rotation), mSize(size), mSprite(sprite), mColor(color), isSolid(false), isDestroyed(false)
{

}

void GameObject::draw(SpriteRenderer& renderer)
{
	renderer.drawSprite(mSprite, mPosition, mRotation, mSize, mColor);
}
