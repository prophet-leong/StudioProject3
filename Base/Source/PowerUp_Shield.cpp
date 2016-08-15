#include "PowerUp_Shield.h"


PowerUp_Shield::PowerUp_Shield(int x, int y, GEOMETRY_TYPE typeOfTile, string powerUpName, int damageMitigation, float maxDuration)
:PowerUp(x, y, typeOfTile, powerUpName)
{
	this->damageMitigation = damageMitigation;
	this->maxDuration = maxDuration;
	this->duration = maxDuration;
}
void PowerUp_Shield::Update(/*Hero* hero,*/ double dt)
{
	if (active)
	{
		/*hero->health;*/
	}
}

PowerUp_Shield::~PowerUp_Shield()
{
}
