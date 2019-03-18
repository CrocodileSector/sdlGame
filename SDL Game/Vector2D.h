#pragma once

#include <iostream>

class Vector2D
{
private:
	float x, y;

	Vector2D& Add(const Vector2D& oVec);
	Vector2D& Subtract(const Vector2D& oVec);
	Vector2D& Multiply(const Vector2D& oVec);
	Vector2D& Divide(const Vector2D& oVec);

public:
	Vector2D() : x(0.0f), y(0.0f) { }
	Vector2D(float ix, float iy) : x (ix), y (iy) { }

	float GetX() const { return x; }
	float GetY() const { return y; }
	void SetCoordinates(float ix, float iy) { x = ix; y = iy; }

	void Add(float ix, float iy) { x += ix; y += iy; }
	void Subtract(float ix, float iy) { x -= ix; y -= iy; }
	void Multiply(float ix, float iy) { x *= ix; y *= iy; }
	void Divide(float ix, float iy) { x /= ix; y /= iy; }

	friend Vector2D& operator + (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator - (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator * (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator / (Vector2D& v1, const Vector2D& v2);

	friend Vector2D& operator += (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator -= (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator *= (Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator /= (Vector2D& v1, const Vector2D& v2);

	friend std::ostream& operator << (const std::ostream& oStream, const Vector2D& vec);
};