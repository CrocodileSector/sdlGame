#pragma once

#include "ECS.h"
#include "TextureManager.h"
#include "TransformComponent.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* m_transform;
	SDL_Texture* m_texture;

	SDL_Rect srcRect, destRect;

public:
	SpriteComponent(const char* pathToTexture)
	{
		m_texture = TextureManager::LoadTexture(pathToTexture);
	}

	~SpriteComponent()
	{
		if (m_texture)
			SDL_DestroyTexture(m_texture);
	}

	void SetTexture(const char* pathToTexture)
	{
		SDL_Texture* lastTexture = m_texture;
		m_texture = TextureManager::LoadTexture(pathToTexture);
		SDL_DestroyTexture(lastTexture);
	}

	void init() override 
	{
		m_transform = &(m_entity->getComponent<TransformComponent>());

		srcRect.x = srcRect.y = 0;

		srcRect.h = m_transform->GetHeight();
		srcRect.w = m_transform->GetWidth();
	}

	void update() override
	{
		destRect.x = static_cast<int>(m_transform->GetX());
		destRect.y = static_cast<int>(m_transform->GetY());
		destRect.h = m_transform->GetHeight() * m_transform->GetScale();
		destRect.w = m_transform->GetWidth() * m_transform->GetScale();
	}

	void draw() override
	{
		TextureManager::Draw(m_texture, srcRect, destRect);
	}
};