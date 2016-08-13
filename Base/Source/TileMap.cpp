#include "TileMap.h"
#include <iostream>

using std::cin;
using std::cout;

TileMap::TileMap(void) {

	map.clear();
	numRows = 0;
	numColumns = 0;
	mapWidth = 0;
	mapHeight = 0;
	screenWidth = 0;
	screenHeight = 0;
	fineOffSet_x = fineOffSet_y = offSet_x = offSet_y = tileOffSet_x = tileOffSet_y = 0;

}

TileMap::~TileMap(void) {

	map.clear();

}

bool TileMap::LoadFile(const string& mapName, const int screenWidth, const int screenHeight) {

	//Open the file.
	ifstream file(mapName.c_str());
	//If file is successfully opened.
	if (!file.is_open()) {
		cout << "Error: Cannot open file " << mapName << "." << endl;
		return false;
	}

	//Empty our current map.
	map.clear();
	numRows = 0;
	numColumns = 0;

	string currentLine = "";
	while(getline(file, currentLine)) 
	{
		// If this line is a comment line, or an empty line, then ignore it.
		++numRows;
		
		if (currentLine == "") 
			continue;


		//currentLine.find("//*") != NULL
		//A new row of tiles.
		vector<int> currentRow;
		currentRow.resize(numColumns, 0); //Make it the size of the largest row.

		//Create a istringstream object with currentLine as it's content.
		istringstream iss(currentLine);
		string tileVariable;

		int columnCounter = 0;

		while (getline(iss, tileVariable, ',')) {
			// Count the number of columns
			++columnCounter;
			//Is the current column we are in right now larger than the size of our current row?
			if (columnCounter > currentRow.size()) {
				numColumns = columnCounter;
				currentRow.resize(numColumns, 0);
				for (vector<vector<int> >::iterator iter = map.begin(); iter != map.end(); ++iter) {
					(*iter).resize(numColumns, 0);
				}
			}
			currentRow[columnCounter - 1] = atoi(tileVariable.c_str());
		}
		//Add the current row to our map.
		//map.push_back(currentRow);
		map.insert(map.begin(), currentRow);
	}

	//Close the file after we're done.
	file.close();

	mapHeight = tilesize*numRows;
	mapWidth = tilesize *numColumns;

	mapTileHeight = numRows;
	mapTileWidth = numColumns;

	 this->screenWidth = screenWidth;
	 this->screenHeight = screenHeight;

	return true;

}

bool TileMap::LoadMap(const string& mapName, const int screenWidth, const int screenHeight) {

	if (LoadFile(mapName, screenWidth, screenHeight) == true)
	{
		printf("Map (%s) has been successfully loaded!\n", mapName.c_str());
		return true;
	}

	return false;

}

void TileMap::Update()
{
	tileOffSet_x = (int)(offSet_x / GetTileSize());
	if (tileOffSet_x + GetScreenTileWidth() > GetMapTileWidth())
		tileOffSet_x = GetMapTileWidth() - GetScreenTileWidth();

	tileOffSet_y = (int)(offSet_y / GetTileSize());
	if (tileOffSet_y + GetScreenTileHeight() > GetMapTileHeight())
		tileOffSet_y = GetMapTileHeight() - GetScreenTileHeight();

}

int TileMap::GetNumRows() const
{
	return this->numRows;
}

int TileMap::GetNumColumns() const
{
	return this->numColumns;
}

int TileMap::GetTileSize() const
{
	return tilesize;
}

int TileMap::GetMapHeight() const
{
	return mapHeight;
}

int TileMap::GetMapWidth() const
{
	return mapWidth;
}

int TileMap::GetScreenWidth() const
{
	return screenWidth;
}

int TileMap::GetScreenHeight() const
{
	return screenHeight;
}

int TileMap::GetMapTileHeight() const
{
	return mapTileHeight;
}

int TileMap::GetMapTileWidth() const
{
	return mapTileWidth;
}

int TileMap::GetScreenTileWidth() const
{
	return (screenWidth / tilesize);
}

int TileMap::GetScreenTileHeight() const
{
	return (screenHeight/tilesize);
}