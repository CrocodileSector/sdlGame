#pragma once

#include <string>
#include <vector>

class Map
{
public:

	Map(int ms, int ts);
	~Map();

	void LoadMap(std::string path, int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int xpos, int ypos, int tileType);

private:
	int mapScale;
	int tileSize;
	int scaledSize;

};