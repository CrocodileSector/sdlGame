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

	void AddX(float ix) { x += ix; }
	void SubtractX(float ix) { x -= ix; }
	void MultiplyX(float ix)
	{
		if(ix != 0)
			x *= ix;
	}

	void DivideX(float ix)
	{ 
		if(ix != 0)
			x /= ix; 
	}

	void AddY(float iy) { y += iy; }
	void SubtractY(float iy) { y -= iy; }
	void MultiplyY(float iy)
	{
		if (iy != 0)
			y *= iy;
	}

	void DivideY(float iy)
	{
		if (iy != 0.0f)
			y /= iy;
	}


	void AddX(int ix) { x += ix; }
	void SubtractX(int ix) { x -= ix; }
	void MultiplyX(int ix)
	{
		if (ix != 0)
			x *= ix;
	}

	void DivideX(int ix)
	{
		if (ix != 0)
			x /= ix;
	}

	void AddY(int iy) { y += iy; }
	void SubtractY(int iy) { y -= iy; }
	void MultiplyY(int iy)
	{
		if (iy != 0)
			y *= iy;
	}

	void DivideY(int iy)
	{
		if (iy != 0.0f)
			y /= iy;
	}

	void Add(float ix, float iy) { AddX(ix); AddY(iy); }
	void Subtract(float ix, float iy) { SubtractX(ix); SubtractY(iy); }
	void Multiply(float ix, float iy) { MultiplyX(ix); MultiplyY(iy); }
	void Divide(float ix, float iy) { DivideX(ix); DivideY(iy); }

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