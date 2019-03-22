#include "TransformComponent.h"

TransformComponent::TransformComponent(float x, float y)
	: m_pos(x, y), m_velocity(Velocity) { }

TransformComponent::TransformComponent(int scale)
	: m_pos(Position), m_velocity(Velocity), m_scale(scale) { }

TransformComponent::TransformComponent(float x, float y, int h, int w, int s)
	: m_pos(x, y), m_velocity(Velocity), m_height(h), m_width(w), m_scale(s) { }

void TransformComponent::update()
{
	float xScalar = m_velocity.GetX() * speed;
	float yScalar = m_velocity.GetY() * speed;
	m_pos.Add(xScalar, yScalar);
}

TransformComponent& TransformComponent::operator + (const Vector2D& vec)
{
	m_pos += vec;
	return *this;
}
TransformComponent& TransformComponent::operator - (const Vector2D& vec)
{
	m_pos -= vec;
	return *this;
}
TransformComponent& TransformComponent::operator * (const Vector2D& vec)
{
	m_pos *= vec;
	return *this;
}
TransformComponent& TransformComponent::operator / (const Vector2D& vec)
{
	m_pos /= vec;
	return *this;
}
TransformComponent& TransformComponent::operator += (const Vector2D& vec)
{
	m_pos += vec;
	return *this;
}
TransformComponent& TransformComponent::operator -= (const Vector2D& vec)
{
	m_pos -= vec;
	return *this;
}
TransformComponent& TransformComponent::operator *= (const Vector2D& vec)
{
	m_pos *= vec;
	return *this;
}
TransformComponent& TransformComponent::operator /= (const Vector2D& vec)
{
	m_pos /= vec;
	return *this;
}