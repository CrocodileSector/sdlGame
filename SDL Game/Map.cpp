#include "Map.h"

#include <fstream>

Map::Map()
{
}

Map::~Map()
{
}

void Map::LoadMap(std::string mapFile, int sizeX, int sizeY)
{
	int tile = -1;
	std::ifstream fs(mapFile, std::fstream::in);
	
	while (!fs.eof())
	{
		for (int y = 0; y < sizeY; ++y)
		{
			for (int x = 0; x < sizeX; ++x)
			{
				fs >> tile;
				fs.ignore();

				if (tile != -1)
					Game::AddTile(tile, 32 * x, 32 * y);
			}
		}
	}

	fs.close();
}