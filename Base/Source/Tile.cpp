#include "Tile.h"

Tile::Tile(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile,TILE_TYPE type)
	: GameObject(x, y, meshName, typeOfTile)
	, tiletype(type)
{

}

Tile::~Tile()
{

}

Tile::TILE_TYPE Tile::GetType()
{
	return tiletype;
}