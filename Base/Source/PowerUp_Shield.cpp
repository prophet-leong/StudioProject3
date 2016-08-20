#include "PowerUp_Shield.h"


PowerUp_Shield::PowerUp_Shield(int x, int y, GEOMETRY_TYPE typeOfTile, string powerUpName, int damageMitigation, float maxDuration)
:PowerUp(x, y, typeOfTile, powerUpName)
{
	this->active = false;
	this->damageMitigation = damageMitigation;
	this->maxDuration = maxDuration;
	this->duration = maxDuration;
	SetIncrementStat(INCREMENT_STAT::SHIELD);
	SetIncrement(damageMitigation);
	SetSPCost(50);
}
void PowerUp_Shield::Update(GameObject*go,double dt)
{
	if (active)
	{
		duration -= dt;
		if (duration <= 0)
		{
			active = false;
			duration = maxDuration;
		}
	}
}

PowerUp_Shield::~PowerUp_Shield()
{
}
