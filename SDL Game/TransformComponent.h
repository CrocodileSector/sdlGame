#pragma once
#include "ECS.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
	Vector2D m_pos;

public:
	TransformComponent() = default;

	TransformComponent(float x, float y) : m_pos(x, y) { }

	float GetX() const { return m_pos.GetX(); }
	float GetY() const { return m_pos.GetY(); }

	Vector2D& Get2DVec() { return m_pos; }

	void SetPos(float x, float y) { m_pos.SetCoordinates(x, y); }

	void init() override { }

	void update() override
	{
		const float inc = 1.0f;
		m_pos.Add(inc, inc);
	}

	TransformComponent& operator + (const Vector2D& vec) 
	{
		m_pos += vec;
		return *this;
	}
	TransformComponent& operator - (const Vector2D& vec)
	{
		m_pos -= vec;
		return *this;
	}
	TransformComponent& operator * (const Vector2D& vec)
	{
		m_pos *= vec;
		return *this;
	}
	TransformComponent& operator / (const Vector2D& vec)
	{
		m_pos /= vec;
		return *this;
	}
	TransformComponent& operator += (const Vector2D& vec)
	{
		m_pos += vec;
		return *this;
	}
	TransformComponent& operator -= (const Vector2D& vec)
	{
		m_pos -= vec;
		return *this;
	}
	TransformComponent& operator *= (const Vector2D& vec)
	{
		m_pos *= vec;
		return *this;
	}
	TransformComponent& operator /= (const Vector2D& vec)
	{
		m_pos /= vec;
		return *this;
	}
};