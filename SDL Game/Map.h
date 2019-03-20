#pragma once

#include "Game.h"

class Map
{
public:

	Map();
	~Map();

	static void LoadMap(std::string mapFile, int sizeX, int sizeY);

private:
};