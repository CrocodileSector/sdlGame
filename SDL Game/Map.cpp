#include "Map.h"

#include "Game.h"
#include "Components.h"

#include <fstream>

extern EntityManager manager;

Map::Map(int ms, int ts) : mapScale(ms), tileSize(ts)
{
	scaledSize = ms * ts;
}

Map::~Map()
{
}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
	int c = -1;
	std::fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	if (mapFile.is_open())
	{
		for (int y = 0; y < sizeY; y++)
		{
			for (int x = 0; x < sizeX; x++)
			{
				mapFile >> c;
				mapFile.ignore();

				if (c != 0)
				{
					std::cout << "wth here..." << std::endl;
				}

				srcX = x * tileSize;
				srcY = y * tileSize;

				AddTile(srcX, srcY, x * scaledSize, y * scaledSize, c);
			}
		}
	}

	mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos, int tileType)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, tileType);
	//tile.addGroup(Game::groupMap);
}