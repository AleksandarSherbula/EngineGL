#pragma once

#include <iostream>

class Vector2
{
public:
	float x, y;

	Vector2();
	Vector2(float value);
	Vector2(float x, float y);

	friend Vector2& operator+ (Vector2 left, Vector2& right);
	friend Vector2& operator- (Vector2 left, Vector2& right);
	friend Vector2& operator* (Vector2 left, Vector2& right);
	friend Vector2& operator/ (Vector2 left, Vector2& right);

	bool operator==(Vector2& other);

	Vector2& operator+ (float scaler);
	Vector2& operator+= (Vector2& other);
	Vector2& operator-= (Vector2& other);
	Vector2& operator*= (Vector2& other);
	Vector2& operator/= (Vector2& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);
	
private:
	Vector2& add(float scaler);
	Vector2& add(Vector2& other);
	Vector2& subtract(Vector2& other);
	Vector2& multiply(Vector2& other);
	Vector2& divide(Vector2& other);
};