#include "Vector2D.h"

eVector2DType DefaultVector2DType = Position;

Vector2D::Vector2D() : x(0.0f), y(0.0f), m_type(DefaultVector2DType) { }
Vector2D::Vector2D(eVector2DType vType) : x(0.0f), y(0.0f), m_type(vType) { }
Vector2D::Vector2D(float ix, float iy) : x(ix), y(iy), m_type(DefaultVector2DType) { }
Vector2D::Vector2D(float ix, float iy, eVector2DType vType) : x(ix), y(iy), m_type(vType) { }


Vector2D& Vector2D::Add(const Vector2D& oVec)
{
	this->x += oVec.x;
	this->y += oVec.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& oVec)
{
	this->x -= oVec.x;
	this->y -= oVec.y;

	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& oVec)
{
	this->x *= oVec.x;
	this->y *= oVec.y;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& oVec)
{
	this->x /= oVec.x;
	this->y /= oVec.y;

	return *this;
}

Vector2D& operator + (Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator - (Vector2D& v1, const Vector2D& v2)
{
	return v1.Subtract(v2);
}

Vector2D& operator * (Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiply(v2);
}

Vector2D& operator / (Vector2D& v1, const Vector2D& v2)
{
	return v1.Divide(v2);
}

Vector2D& operator += (Vector2D& v1, const Vector2D& v2)
{
	return v1 + v2;
}

Vector2D& operator -= (Vector2D& v1, const Vector2D& v2)
{
	return v1 - v2;
}

Vector2D& operator *= (Vector2D& v1, const Vector2D& v2)
{
	return v1 * v2;
}
Vector2D& operator /= (Vector2D& v1, const Vector2D& v2)
{
	return v1 / v2;
}

std::ostream& operator << (std::ostream& oStream, const Vector2D& vec)
{
	oStream << "(" << vec.GetX() << ", " << vec.GetY() << ")";
	return oStream;
}