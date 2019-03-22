#pragma once

#include <iostream>
#include "Defines.h"

class Vector2D
{
private:
	float x, y;
	eVector2DType m_type;
	
	Vector2D& Add(const Vector2D& oVec);
	Vector2D& Subtract(const Vector2D& oVec);
	Vector2D& Multiply(const Vector2D& oVec);
	Vector2D& Divide(const Vector2D& oVec);

public:
	Vector2D();
	Vector2D(eVector2DType vType);
	Vector2D(float ix, float iy);
	Vector2D(float ix, float iy, eVector2DType vType);

	float GetX() const { return x; }
	float GetY() const { return y; }

	void SetX(float val) { x = val; }
	void SetY(float val) { y = val; }

	void SetXY(float ix, float iy) { x = ix; y = iy; }

	void AddX(float ix);
	void SubtractX(float ix);
	void MultiplyX(float ix);
	void DivideX(float ix);

	void AddY(float iy);
	void SubtractY(float iy);
	void MultiplyY(float iy);
	void DivideY(float iy);

	void AddX(int ix);
	void SubtractX(int ix);
	void MultiplyX(int ix);
	void DivideX(int ix);

	void AddY(int iy);
	void SubtractY(int iy);
	void MultiplyY(int iy);
	void DivideY(int iy);

	void Add(float ix, float iy);
	void Subtract(float ix, float iy);
	void Multiply(float ix, float iy);
	void Divide(float ix, float iy);

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