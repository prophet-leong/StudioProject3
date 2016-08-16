#include "PowerUp_Attack.h"

PowerUp_Attack::PowerUp_Attack(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUpName, int damageBoost ,int sp_Cost , bool inBag)
:PowerUp(x, y, typeOfTile,PowerUpName)
{
	this->damageBoost = damageBoost;
	SetSPCost(sp_Cost);
}
void PowerUp_Attack::Update(double dt)
{
	SetIncrementStat(ATTACK);
	SetIncrement(damageBoost);
}
PowerUp_Attack ::~PowerUp_Attack()
{

}