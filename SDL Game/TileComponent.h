#pragma once

#include "Components.h"

class TileComponent : public Component
{
private:
	TransformComponent* m_transform;
	SpriteComponent* m_sprite;
	ColliderComponent* m_collider = nullptr;

	SDL_Rect m_rect;
	eTileType m_type;

public:
	TileComponent() = default;

	TileComponent(int x, int y, int h, int w, int type)
	{
		m_rect.x = x;
		m_rect.y = y;
		m_rect.h = h;
		m_rect.w = w;
		m_type = static_cast<eTileType>(type);
	}

	void init() override
	{
		m_transform = &(m_entity->addComponent<TransformComponent>(static_cast<float>(m_rect.x), static_cast<float>(m_rect.y), m_rect.h, m_rect.w, 1));
		
		switch (m_type)
		{
		case Water:
			m_collider = &(m_entity->addComponent<ColliderComponent>("waterTile"));
			m_sprite = &(m_entity->addComponent<SpriteComponent>("Assets/water.png"));
			break;
		case Grass:
			m_collider = &(m_entity->addComponent<ColliderComponent>("grassTile"));
			m_sprite = &(m_entity->addComponent<SpriteComponent>("Assets/dirt.png"));
			break;
		case Dirt:
			m_collider = &(m_entity->addComponent<ColliderComponent>("dirtTile"));
			m_sprite = &(m_entity->addComponent<SpriteComponent>("Assets/grass.png"));
			break;
		default:
			throw std::runtime_error("Default case at initialize step for map tile");
			break;
		}
	}

	void update() override
	{
		m_rect.x = m_transform->GetX();
		m_rect.y = m_transform->GetY();
	}
};