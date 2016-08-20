#include "PowerUp.h"

PowerUp::PowerUp(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUpName)
:GameObject(x,y,PowerUpName,typeOfTile)
{
}

PowerUp::~PowerUp()
{

}
string PowerUp::GetPowerUpName()
{
	return meshName;
}
void PowerUp::SetPowerUpName(string newName)
{
	this->meshName = newName;
}
INCREMENT_STAT PowerUp::GetIncrementStat()
{
	return increment_type;
}
void PowerUp::SetIncrementStat(INCREMENT_STAT stat)
{
	increment_type = stat;
}
int PowerUp::GetIncrement()
{
	return increment;
}
void PowerUp::SetIncrement(int increase)
{
	increment = increase;
}
GEOMETRY_TYPE PowerUp::GetGeoType()
{
	return type;
}
void PowerUp::SetSPCost(int SP)
{
	SP_Cost = SP;
}
int PowerUp::GetSPCost()
{
	return SP_Cost;
}
BULLET_ELEMENT PowerUp::GetElementType()
{
	return elementType;
}
void PowerUp::SetElementType(BULLET_ELEMENT elementType)
{
	this->elementType = elementType;
}