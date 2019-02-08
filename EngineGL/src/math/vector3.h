#pragma once

#include "vector2.h"

#include <iostream>

class Vector3
{
public:
	float x, y, z;

	Vector3();
	Vector3(float value);
	Vector3(Vector2 vec2, float z);
	Vector3(float x, float y, float z);

	friend Vector3& operator+ (Vector3 left, Vector3& right);
	friend Vector3& operator- (Vector3 left, Vector3& right);
	friend Vector3& operator* (Vector3 left, Vector3& right);
	friend Vector3& operator/ (Vector3 left, Vector3& right);

	bool operator==(Vector3& other);

	Vector3& operator+ (float scaler);
	Vector3& operator+= (Vector3& other);
	Vector3& operator-= (Vector3& other);
	Vector3& operator*= (Vector3& other);
	Vector3& operator/= (Vector3& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
	
private:
	Vector3& add(float scaler);
	Vector3& add(Vector3& other);
	Vector3& subtract(Vector3& other);
	Vector3& multiply(Vector3& other);
	Vector3& divide(Vector3& other);
};