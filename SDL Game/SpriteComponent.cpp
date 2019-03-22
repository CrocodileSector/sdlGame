#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const char* pathToTexture)
{
	m_texture = TextureManager::LoadTexture(pathToTexture);
}

SpriteComponent::~SpriteComponent()
{
	if (m_texture)
		SDL_DestroyTexture(m_texture);
}

void SpriteComponent::SetTexture(const char* pathToTexture)
{
	SDL_Texture* lastTexture = m_texture;
	m_texture = TextureManager::LoadTexture(pathToTexture);
	SDL_DestroyTexture(lastTexture);
}

void SpriteComponent::init()
{
	m_transform = &(m_entity->getComponent<TransformComponent>());

	srcRect.x = srcRect.y = 0;

	srcRect.h = m_transform->GetHeight();
	srcRect.w = m_transform->GetWidth();
}

void SpriteComponent::update()
{
	destRect.x = static_cast<int>(m_transform->GetX());
	destRect.y = static_cast<int>(m_transform->GetY());
	destRect.h = m_transform->GetHeight() * m_transform->GetScale();
	destRect.w = m_transform->GetWidth() * m_transform->GetScale();
}

void SpriteComponent::draw()
{
	TextureManager::Draw(m_texture, srcRect, destRect);
}