#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* textureFile)
{
	SDL_Surface* textureSurface = IMG_Load(textureFile);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::GetRenderer(), textureSurface);

	if (!texture)
		std::cout << "Failed to load texture " << textureFile << "... SDL Error: " << SDL_GetError() << std::endl;

	SDL_FreeSurface(textureSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect)
{
	if (!Game::hasRenderer())
		return;

	if (SDL_RenderCopy(Game::GetRenderer(), texture, NULL, &destRect) == -1)
	{
		std::stringstream err;
		err << "Failed to render with SDL Error: " << SDL_GetError() << std::endl;
		std::cout << err.str();
	}
}