#include "Vector4.h"

Vector4::Vector4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

Vector4::Vector4(float value)
{
	this->x = value;
	this->y = value;
	this->y = value;
	this->y = value;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool Vector4::operator==(Vector4& other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
}

Vector4& Vector4::add(float scaler)
{
	this->x += scaler;
	this->y += scaler;
	this->z += scaler;
	this->w += scaler;

	return *this;
}

Vector4& Vector4::add(Vector4& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;

	return *this;
}

Vector4& Vector4::subtract(Vector4& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;

	return *this;
}

Vector4& Vector4::multiply(Vector4& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	this->w *= other.w;

	return *this;
}

Vector4& Vector4::divide(Vector4& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	this->w /= other.w;

	return *this;
}

Vector4& operator+(Vector4 left, Vector4& right)
{
	return left.add(right);
}

Vector4& operator-(Vector4 left, Vector4& right)
{
	return left.subtract(right);
}

Vector4& operator*(Vector4 left, Vector4& right)
{
	return left.multiply(right);
}

Vector4& operator/(Vector4 left, Vector4& right)
{
	return left.divide(right);
}

std::ostream & operator<<(std::ostream& os, const Vector4& vector)
{
	os << "x = "<< vector.x <<", y = "<< vector.y <<", z = "<< vector.z << ", w = " << vector.w;
	return os;
}

Vector4& Vector4::operator+(float scaler)
{
	return add(scaler);
}

Vector4& Vector4::operator+=(Vector4 & other)
{
	*this = *this + other;
	return *this;
}

Vector4& Vector4::operator-=(Vector4 & other)
{
	*this = *this - other;
	return *this;
}

Vector4& Vector4::operator*=(Vector4 & other)
{
	*this = *this * other;
	return *this;
}

Vector4& Vector4::operator/=(Vector4 & other)
{
	*this = *this / other;
	return *this;
}