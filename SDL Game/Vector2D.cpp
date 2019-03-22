#include "Vector2D.h"

eVector2DType DefaultVector2DType = Position;

Vector2D::Vector2D() : x(0.0f), y(0.0f), m_type(DefaultVector2DType) { }
Vector2D::Vector2D(eVector2DType vType) : x(0.0f), y(0.0f), m_type(vType) { }
Vector2D::Vector2D(float ix, float iy) : x(ix), y(iy), m_type(DefaultVector2DType) { }
Vector2D::Vector2D(float ix, float iy, eVector2DType vType) : x(ix), y(iy), m_type(vType) { }

void Vector2D::AddX(float ix)
{
	x += ix;
}
void Vector2D::SubtractX(float ix)
{
	x -= ix;
}
void Vector2D::MultiplyX(float ix)
{
	if (ix != 0)
		x *= ix;
}

void Vector2D::DivideX(float ix)
{
	if (ix != 0)
		x /= ix;
}

void Vector2D::AddY(float iy)
{
	y += iy;
}

void Vector2D::SubtractY(float iy)
{
	y -= iy;
}

void Vector2D::MultiplyY(float iy)
{
	if (iy != 0)
		y *= iy;
}

void Vector2D::DivideY(float iy)
{
	if (iy != 0.0f)
		y /= iy;
}


void Vector2D::AddX(int ix)
{
	x += ix;
}

void Vector2D::SubtractX(int ix)
{
	x -= ix;
}

void Vector2D::MultiplyX(int ix)
{
	if (ix != 0)
		x *= ix;
}

void Vector2D::DivideX(int ix)
{
	if (ix != 0)
		x /= ix;
}

void Vector2D::AddY(int iy)
{
	y += iy;
}

void Vector2D::SubtractY(int iy)
{
	y -= iy;
}

void Vector2D::MultiplyY(int iy)
{
	if (iy != 0)
		y *= iy;
}

void Vector2D::DivideY(int iy)
{
	if (iy != 0.0f)
		y /= iy;
}

void Vector2D::Add(float ix, float iy)
{
	AddX(ix);
	AddY(iy);
}

void Vector2D::Subtract(float ix, float iy)
{
	SubtractX(ix);
	SubtractY(iy);
}

void Vector2D::Multiply(float ix, float iy)
{
	MultiplyX(ix);
	MultiplyY(iy);
}

void Vector2D::Divide(float ix, float iy)
{
	DivideX(ix);
	DivideY(iy);
}

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