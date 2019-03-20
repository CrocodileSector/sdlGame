#pragma once

#include "Game.h"
#include "ECS.h"
#include "TransformComponent.h"

class Collision;

class ColliderComponent : public Component
{
private:
	SDL_Rect m_collider;
	std::string m_tag;
	TransformComponent* m_transform;

public:
	ColliderComponent(std::string tag) : m_tag(tag) { }

	const std::string& GetTag() const { return m_tag; }
	const SDL_Rect& GetCollider() const { return m_collider; }

	TransformComponent* GetTransform() const
	{
		if (m_transform)
			return m_transform;
	}

	void init() override
	{
		m_transform = &(m_entity->getComponent<TransformComponent>());

		if (m_tag.compare("player") == 0)
			Game::RegisterCollider(this, true);
		else
			Game::RegisterCollider(this, false);
	}

	void update() override
	{
		m_collider.x = static_cast<int>(m_transform->GetX());
		m_collider.y = static_cast<int>(m_transform->GetY());

		m_collider.w = m_transform->GetWidth() * m_transform->GetScale();
		m_collider.h = m_transform->GetHeight() * m_transform->GetScale();
	}
};