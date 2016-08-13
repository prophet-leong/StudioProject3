#include "Tile.h"

Tile::Tile(int x,int y , string meshName, string meshTexture)
	: GameObject(x,y,meshName,meshTexture)
	, type(NORMAL)
{

}

Tile::~Tile()
{}