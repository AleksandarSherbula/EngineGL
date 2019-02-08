#pragma once

#include "vector2.h"
#include "vector3.h"

#include <iostream>

class Vector4
{
public:
	float x, y, z, w;

	Vector4();
	Vector4(float value);
	Vector4(float x, float y, float z, float w);
	Vector4(Vector2 vector2, float z, float w);
	Vector4(Vector3 vector3, float w);

	friend Vector4& operator+ (Vector4 left, Vector4& right);
	friend Vector4& operator- (Vector4 left, Vector4& right);
	friend Vector4& operator* (Vector4 left, Vector4& right);
	friend Vector4& operator/ (Vector4 left, Vector4& right);

	bool operator==(Vector4& other);

	Vector4& operator+ (float scaler);
	Vector4& operator+= (Vector4& other);
	Vector4& operator-= (Vector4& other);
	Vector4& operator*= (Vector4& other);
	Vector4& operator/= (Vector4& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector4& vector);
	
private:
	Vector4& add(float scaler);
	Vector4& add(Vector4& other);
	Vector4& subtract(Vector4& other);
	Vector4& multiply(Vector4& other);
	Vector4& divide(Vector4& other);
};