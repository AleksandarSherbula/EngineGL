#include "matrix4.h"
#include "vector3.h"

Matrix4::Matrix4()
{
	for (int i = 0; i < 4 * 4; i++)
		mElements[i] = 0.0f;

	mElements[0 * 4 + 0] = 1.0f;
	mElements[1 * 4 + 1] = 1.0f;
	mElements[2 * 4 + 2] = 1.0f;
	mElements[3 * 4 + 3] = 1.0f;
}

Matrix4::Matrix4(float diagonal)
{
	for (int i = 0; i < 4 * 4; i++)
		mElements[i] = 0;

	mElements[0 * 4 + 0] = diagonal;
	mElements[1 * 4 + 1] = diagonal;
	mElements[2 * 4 + 2] = diagonal;
}

Matrix4::Matrix4(float* elements)
{
	for (int i = 0; i < 4 * 4; i++)
		mElements[i] = elements[i];
}

Matrix4& Matrix4::multiply(const Matrix4& other)
{
	const float* a = mElements;
	const float* b = other.mElements;

	float c[4 * 4];

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			// column * row
			c[x * 4 + y] =
				a[0 * 4 + y] * b[x * 4 + 0] +
				a[1 * 4 + y] * b[x * 4 + 1] +
				a[2 * 4 + y] * b[x * 4 + 2] +
				a[3 * 4 + y] * b[x * 4 + 3];
		}

	for (int i = 0; i < 4 * 4; i++)
	{
		mElements[i] = c[i];
	}

	return *this;
}

Matrix4 operator*(Matrix4 left, Matrix4& right)
{
	return left.multiply(right);
}

std::ostream& operator<<(std::ostream & os, Matrix4 matrix)
{
	for (int i = 0; i < 4; i++)
	{
		os << "|" << matrix.mElements[0 + i * 4] << " " << matrix.mElements[1 + i * 4] << " " <<
			matrix.mElements[2 + i * 4] << " " << matrix.mElements[3 + i * 4] << "|" << std::endl;
	}

	return os;
}

Matrix4& Matrix4::operator*=(Matrix4& other)
{
	*this = *this * other;
	return *this;
}

Matrix4& Matrix4::translate(const Vector3& translation)
{
	Matrix4 transMat;

	transMat.mElements[3 * 4 + 0] = translation.x;
	transMat.mElements[3 * 4 + 1] = translation.y;
	transMat.mElements[3 * 4 + 2] = translation.z;

	*this *= transMat;

	return *this;
}

Matrix4& Matrix4::rotate(float angle, const Vector3& axis)
{
	float r = angle;
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;
	float omc = 1.0f - cos(r);

	float c = cos(angle);
	float s = sin(angle);

	Matrix4 rotMat;

	rotMat.mElements[0 + 0 * 4] = c + x * x * omc;
	rotMat.mElements[1 + 0 * 4] = x * y * omc - z * s;
	rotMat.mElements[2 + 0 * 4] = z * x * omc + y * s;

	rotMat.mElements[0 + 1 * 4] = x * y * omc + z * s;
	rotMat.mElements[1 + 1 * 4] = c + y * y * omc;
	rotMat.mElements[2 + 1 * 4] = z * y * omc - x * s;

	rotMat.mElements[0 + 2 * 4] = x * z * omc - y * s;
	rotMat.mElements[1 + 2 * 4] = y * z * omc + x * s;
	rotMat.mElements[2 + 2 * 4] = c + z * z * omc;

	*this *= rotMat;

	return *this;
}

Matrix4& Matrix4::scale(const Vector3& size)
{
	Matrix4 sizeMat;

	sizeMat.mElements[0 * 4 + 0] = size.x;
	sizeMat.mElements[1 * 4 + 1] = size.y;
	sizeMat.mElements[2 * 4 + 2] = size.z;

	*this *= sizeMat;
	return *this;
}

Matrix4 Matrix4::orthographic(float left, float right, float top, float bottom, float near, float far)
{
	Matrix4 ortho;

	ortho.mElements[0 * 4 + 0] = 2.0f / (right - left);
	ortho.mElements[1 * 4 + 1] = 2.0f / (bottom - top);
	ortho.mElements[2 * 4 + 2] = -2.0f / (far - near);

	ortho.mElements[3 * 4 + 0] = -1 * ((right + left) / (right - left));
	ortho.mElements[3 * 4 + 1] = -1 * ((bottom + top) / (bottom - top));
	ortho.mElements[3 * 4 + 2] = -1 * ((far + near) / (far - near));

	return ortho;
}
