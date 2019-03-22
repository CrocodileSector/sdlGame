#pragma once

#include "Components.h"

class TileComponent : public Component
{
private:
	TransformComponent* m_transform = nullptr;
	ColliderComponent* m_collider = nullptr;

	SDL_Texture* m_texture;

	SDL_Rect m_srcRect, m_destRect;
	eTileType m_type;

public:
	TileComponent() = default;

	TileComponent(int x, int y, int h, int w, int type);

	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, int typeID);

	~TileComponent();

	void init() override;

	void update() override;

	void draw() override;
};