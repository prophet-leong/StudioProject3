#include "PowerUp_Attack.h"

PowerUp_Attack::PowerUp_Attack(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUpName, int damageBoost ,int sp_Cost ,BULLET_ELEMENT elementType)
:PowerUp(x, y, typeOfTile,PowerUpName)
{
	this->damageBoost = damageBoost;
	SetSPCost(sp_Cost);
	SetElementType(elementType);
	SetIncrementStat(ATTACK);
}
void PowerUp_Attack::Update(double dt)
{
	SetIncrement(damageBoost);
}
PowerUp_Attack ::~PowerUp_Attack()
{

}