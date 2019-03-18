#pragma once

#include "ECS.h"
#include "TextureManager.h"
#include "TransformComponent.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* m_transformPos;
	SDL_Texture* m_texture;

	SDL_Rect srcRect, destRect;

public:
	SpriteComponent(const char* pathToTexture)
	{
		m_texture = TextureManager::LoadTexture(pathToTexture);
	}

	SpriteComponent() = default;
	~SpriteComponent() = default;

	void SetTexture(const char* pathToTexture)
	{
		SDL_Texture* lastTexture = m_texture;
		m_texture = TextureManager::LoadTexture(pathToTexture);
		SDL_DestroyTexture(lastTexture);
	}

	void init() override 
	{
		m_transformPos = &(m_entity->getComponent<TransformComponent>());

		srcRect.x = srcRect.y = 0;
		srcRect.h = srcRect.w = 32;
		destRect.h = destRect.w = 32;
	}

	void update() override
	{
		destRect.x = (int)m_transformPos->GetX();
		destRect.y = (int)m_transformPos->GetY();
	}

	void draw() override
	{
		TextureManager::Draw(m_texture, srcRect, destRect);
	}
};