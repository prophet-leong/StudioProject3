#include "PowerUp.h"

PowerUp::PowerUp(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUpName)
{
	this->x = x;
	this->y = y;
	this->type = typeOfTile;
	this->PowerUpName = PowerUpName;
	this->inBag = inBag;
}

PowerUp::~PowerUp()
{

}

bool PowerUp::GetInBag()
{
	return inBag;
}
void PowerUp::SetInBag(bool isInBag)
{
	this->inBag = isInBag;
}
string PowerUp::GetPowerUpName()
{
	return PowerUpName;
}
void PowerUp::SetPowerUpName(string newName)
{
	this->PowerUpName = newName;
}