#include "Tile.h"

Tile::Tile(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile)
	: GameObject(x, y, meshName, typeOfTile)
	, type(NORMAL)
{

}

Tile::~Tile()
{}