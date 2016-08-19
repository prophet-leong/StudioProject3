#ifndef TILE_H
#define TILE_H
#include "GameObject.h"

class Tile : public GameObject
{
public:
	enum TILE_TYPE
	{
		NORMAL,
		ROCK,
		POWERUP_FIRE,
		POWERUP_SHIELD,
		TILE_END,
	};
	Tile(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, TILE_TYPE tiletype = NORMAL);
	~Tile();

	TILE_TYPE GetType();

private:
	TILE_TYPE tiletype;


};





#endif