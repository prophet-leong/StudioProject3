#ifndef POWERUP_PASSIVE_H
#define POWERUP_PASSIVE_H

#include "PowerUp.h"
class PowerUp_Passive:public PowerUp
{
public:
	PowerUp_Passive(GameObject *go,int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp = "POWERUP_PASSIVE");
	virtual ~PowerUp_Passive();

};

#endif // !POWERUP_PASSIVE_H
