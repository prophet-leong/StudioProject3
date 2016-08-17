#pragma once
#include "GameObject.h"
class Collideables:public GameObject
{
public:
	Collideables(){};
	Collideables(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	virtual ~Collideables();
	virtual bool CheckCollision(){ return false; };
	virtual void CollisionResponse(){};
};

