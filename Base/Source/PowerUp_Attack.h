#pragma once
#include "PowerUp.h"
class PowerUp_Attack:public PowerUp
{
public:
	PowerUp_Attack(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp,int damageBoost,int sp_Cost,BULLET_ELEMENT elementType);
	~PowerUp_Attack();
private:
	int damageBoost;
};

