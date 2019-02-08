#include "vector3.h"

Vector3::Vector3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3::Vector3(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}

Vector3::Vector3(Vector2 vec2, float z)
{
	this->x = vec2.x;
	this->y = vec2.y;
	this->z = z;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool Vector3::operator==(Vector3& other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

Vector3& Vector3::add(float scaler)
{
	this->x += scaler;
	this->y += scaler;
	this->z += scaler;

	return *this;
}

Vector3& Vector3::add(Vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Vector3& Vector3::subtract(Vector3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

Vector3& Vector3::multiply(Vector3& other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;

	return *this;
}

Vector3& Vector3::divide(Vector3& other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;

	return *this;
}

Vector3& operator+(Vector3 left, Vector3& right)
{
	return left.add(right);
}

Vector3& operator-(Vector3 left, Vector3& right)
{
	return left.subtract(right);
}

Vector3& operator*(Vector3 left, Vector3& right)
{
	return left.multiply(right);
}

Vector3& operator/(Vector3 left, Vector3& right)
{
	return left.divide(right);
}

std::ostream & operator<<(std::ostream& os, const Vector3& vector)
{
	os << "x = "<< vector.x <<", y = "<< vector.y << ", z = " << vector.z;
	return os;
}

Vector3& Vector3::operator+(float scaler)
{
	return add(scaler);
}

Vector3& Vector3::operator+=(Vector3 & other)
{
	*this = *this + other;
	return *this;
}

Vector3& Vector3::operator-=(Vector3 & other)
{
	*this = *this - other;
	return *this;
}

Vector3& Vector3::operator*=(Vector3 & other)
{
	*this = *this * other;
	return *this;
}

Vector3& Vector3::operator/=(Vector3 & other)
{
	*this = *this / other;
	return *this;
}