#ifndef MAP_2D_H
#define MAP_2D_H

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Vector2.h"
using namespace std;

class TileMap {

private:
	int numRows, numColumns; //Number of tiles in the map.

	bool LoadFile(const string& mapName,const int screenWidth,const int screenHeight);

	const int tilesize = 32;
	int mapWidth, mapHeight, mapTileWidth, mapTileHeight, screenWidth, screenHeight;

public:
	//offsets
	int fineOffSet_x, offSet_x, tileOffSet_x, fineOffSet_y, offSet_y, tileOffSet_y;

	vector< vector<int> > map;

	//Constructor(s) & Destructor
	TileMap(void);
	~TileMap(void);
	//Functions
	bool LoadMap(const string& mapName, const int screenWidth, const int screenHeight);
	void Update();

	//Getters
	int GetNumRows() const;
	int GetNumColumns() const;
	int GetTileSize() const;
	int GetMapWidth() const;
	int GetMapHeight() const;
	int GetMapTileWidth() const;
	int GetMapTileHeight() const;
	int GetScreenWidth() const;
	int GetScreenHeight() const;
	int GetScreenTileWidth() const;
	int GetScreenTileHeight() const;
};

#endif