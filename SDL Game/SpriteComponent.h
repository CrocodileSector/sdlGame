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
	SpriteComponent(const char* pathToTexture);

	~SpriteComponent();

	void SetTexture(const char* pathToTexture);

	void init() override;

	void update() override;

	void draw() override;
};