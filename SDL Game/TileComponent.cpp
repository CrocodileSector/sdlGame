#include "TileComponent.h"

TileComponent::TileComponent(int x, int y, int h, int w, int type)
{
	m_srcRect.x = x;
	m_srcRect.y = y;
	m_srcRect.h = h;
	m_srcRect.w = w;
	m_type = static_cast<eTileType>(type);
}

TileComponent::TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, int typeID)
{

	if (typeID != 0)
	{
		std::cout << "wth..." << std::endl;
	}

	eTileType tileType = static_cast<eTileType>(typeID);
	switch (tileType)
	{
	case Water:
		m_texture = TextureManager::LoadTexture("Assets/water.png");
		break;
	case Dirt:
		m_texture = TextureManager::LoadTexture("Assets/dirt.png");
		break;
	case Grass:
		m_texture = TextureManager::LoadTexture("Assets/grass.png");
		break;
	}

	m_srcRect.x = srcX;
	m_srcRect.y = srcY;
	m_srcRect.w = m_srcRect.h = tsize;
	m_destRect.w = m_destRect.h = tsize * tscale;

	if (m_transform)
		m_transform->SetPos(static_cast<float>(xpos), static_cast<float>(ypos));
	else
		m_transform = new TransformComponent(static_cast<float>(xpos), static_cast<float>(ypos));
}

TileComponent::~TileComponent()
{
	if (m_texture)
		SDL_DestroyTexture(m_texture);
}

void TileComponent::init()
{
}

void TileComponent::update()
{
	m_destRect.x = static_cast<int>(m_transform->GetX());
	m_destRect.y = static_cast<int>(m_transform->GetY());
}

void TileComponent::draw()
{
	TextureManager::Draw(m_texture, m_srcRect, m_destRect);
}