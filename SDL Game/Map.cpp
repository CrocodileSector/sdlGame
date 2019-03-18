#include "Map.h"

#include "TextureManager.h"

int defaultMap[20][25] =
{
	{1,1,1,1,1,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
	{2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},

	{2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},

	{0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},

	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},

	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},

	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},

	{0,0,0,0,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2},
	{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2},
};

Map::Map()
{
	m_textures.push_back(TextureManager::LoadTexture("Assets/water.png"));
	m_textures.push_back(TextureManager::LoadTexture("Assets/dirt.png"));
	m_textures.push_back(TextureManager::LoadTexture("Assets/grass.png"));

	LoadMap(defaultMap);

	srcRect.x = srcRect.y = 0;
	dstRect.x = dstRect.y = 0;
	srcRect.h = srcRect.w = 32;
	dstRect.h = dstRect.w = 32;
}

Map::~Map()
{

}

void Map::LoadMap(int mapArr[20][25])
{
	for (int row = 0; row < 20; ++row)
	{
		for (int column = 0; column < 25; ++column)
		{
			map[row][column] = mapArr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int textureType = -1;
	for (int row = 0; row < 20; ++row)
	{
		for (int column = 0; column < 25; ++column)
		{
			textureType = map[row][column];

			dstRect.x = column * 32;
			dstRect.y = row * 32;

			TextureManager::Draw(m_textures[textureType], srcRect, dstRect);
		}
	}
}