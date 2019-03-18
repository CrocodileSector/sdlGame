#pragma once

#include "Game.h"

#include <vector>

class Map
{
public:

	Map();
	~Map();

	void LoadMap(int defaultMap[20][25]);
	void DrawMap();

private:

	enum eMapTextureTypes
	{
		WATER = 0,
		DIRT,
		GRASS
	};

	std::vector<SDL_Texture*> m_textures;
	SDL_Rect srcRect, dstRect;

	int map[20][25];
};