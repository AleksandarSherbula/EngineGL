#include "vector2.h"

Vector2::Vector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2::Vector2(float value)
{
	this->x = value;
	this->y = value;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Vector2::operator==(Vector2& other)
{
	return this->x == other.x && this->y == other.y;
}

Vector2& Vector2::add(float scaler)
{
	this->x += scaler;
	this->y += scaler;

	return *this;
}

Vector2& Vector2::add(Vector2& other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Vector2& Vector2::subtract(Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

Vector2& Vector2::multiply(Vector2& other)
{
	this->x *= other.x;
	this->y *= other.y;

	return *this;
}

Vector2& Vector2::divide(Vector2& other)
{
	this->x /= other.x;
	this->y /= other.y;

	return *this;
}

Vector2& operator+(Vector2 left, Vector2& right)
{
	return left.add(right);
}

Vector2& operator-(Vector2 left, Vector2& right)
{
	return left.subtract(right);
}

Vector2& operator*(Vector2 left, Vector2& right)
{
	return left.multiply(right);
}

Vector2& operator/(Vector2 left, Vector2& right)
{
	return left.divide(right);
}

std::ostream & operator<<(std::ostream& os, const Vector2& vector)
{
	os << "x = "<< vector.x <<", y = "<< vector.y;
	return os;
}

Vector2& Vector2::operator+(float scaler)
{
	return add(scaler);
}

Vector2& Vector2::operator+=(Vector2 & other)
{
	*this = *this + other;
	return *this;
}

Vector2& Vector2::operator-=(Vector2 & other)
{
	*this = *this - other;
	return *this;
}

Vector2& Vector2::operator*=(Vector2 & other)
{
	*this = *this * other;
	return *this;
}

Vector2& Vector2::operator/=(Vector2 & other)
{
	*this = *this / other;
	return *this;
}