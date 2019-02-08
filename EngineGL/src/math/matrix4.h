#pragma once

#include <iostream>

class Vector3;

class Matrix4
{
public:
	float mElements[4 * 4];

	Matrix4();
	Matrix4(float diagonal);
	Matrix4(float* elements);

	friend Matrix4 operator* (Matrix4 left, Matrix4& right);
	friend std::ostream& operator<<(std::ostream& os, Matrix4 matrix);

	Matrix4& operator*=(Matrix4& other);

	Matrix4& translate(const Vector3& translation);
	Matrix4& rotate(float angle, const Vector3& axis);
	Matrix4& scale(const Vector3& size);

	static Matrix4 orthographic(float left, float right, float bottom, float top, float near, float far);
private:
	Matrix4& multiply(const Matrix4& other);
};