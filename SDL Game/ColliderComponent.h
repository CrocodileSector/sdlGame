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
	ColliderComponent(std::string tag);

	const std::string& GetTag() const { return m_tag; }
	const SDL_Rect& GetCollider() const { return m_collider; }

	TransformComponent* GetTransform() const;

	void init() override;
	void update() override;
};