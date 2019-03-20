#pragma once
#include "ECS.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
private:
	Vector2D m_pos;
	Vector2D m_velocity;
	int speed = 3;
	int m_height = 32;
	int m_width = 32;
	int m_scale = 1;

public:
	TransformComponent() = default;

	TransformComponent(float x, float y) 
		: m_pos(x, y), m_velocity(Velocity) { }

	TransformComponent(int scale)
		: m_pos(Position), m_velocity(Velocity), m_scale(scale) { }

	TransformComponent(float x, float y, int h, int w, int s)
		: m_pos(x, y), m_velocity(Velocity), m_height(h), m_width(w), m_scale(s) { }

	float GetX() const { return m_pos.GetX(); }
	float GetY() const { return m_pos.GetY(); }

	int GetHeight() const { return m_height; }
	int GetWidth() const { return m_width; }
	int GetScale() const { return m_scale; }

	Vector2D& GetPos() { return m_pos; }
	Vector2D& GetVelocity () { return m_velocity; }

	void SetPos(float x, float y) { m_pos.SetXY(x, y); }
	void SetPosX(float val) { m_pos.SetX(val); }
	void SetPosY(float val) { m_pos.SetY(val); }

	void SetVelocity(float x, float y) { m_velocity.SetXY(x, y); }
	void SetVelocityX(float val) { m_velocity.SetX(val); }
	void SetVelocityY(float val) { m_velocity.SetY(val); }

	void update() override
	{
		float xScalar = m_velocity.GetX() * speed;
		float yScalar = m_velocity.GetY() * speed;
		m_pos.Add(xScalar, yScalar);
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