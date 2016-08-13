#ifndef TILE_H
#define TILE_H
#include "GameObject.h"

class Tile : public GameObject
{
public:
	Tile(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	~Tile();

	enum TILE_TYPE
	{
		NORMAL,
		VICTORY,
		INVISIBLE,
		POINTS,
		POWERUP,
		MUSHROOM,
		COIN,
		TILE_END,
	};
	TILE_TYPE type;


private:


};





#endif