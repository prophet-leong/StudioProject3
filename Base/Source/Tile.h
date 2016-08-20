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
		POWERUP_ATTACK_TYPE,
		POWERUP_SHIELD_TYPE,
		POWERUP_HEALTH,
		POWERUP_SHOOTINGSPEED,
		POWERUP_MOVESPEED,
		TILE_END,
	};

	Tile(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, TILE_TYPE type = NORMAL);
	~Tile();

	TILE_TYPE GetType();

private:
	TILE_TYPE tiletype;
};





#endif