#pragma once
#include "GameObject.h"
#include "TileMap.h"

class Collideables:public GameObject
{
public:
	Collideables(){};
	Collideables(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	virtual ~Collideables();
	virtual void CollisionContainer(GameObject * other, TileMap* tilemap){};
};

