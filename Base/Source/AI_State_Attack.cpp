#include "AI_State_Attack.h"
#include <iostream>

using namespace std;

AI_state_attack::AI_state_attack()
{
}
AI_state_attack::~AI_state_attack()
{
}

void AI_state_attack::Update(double dt)
{


}

void AI_state_attack::SetDestination(const float x, const float y)
{
	this->theDestination.x = x;
	this->theDestination.y = y;
}

void AI_state_attack::GetEnemyPosition(float& x, float& y)
{
	x = this->theEnemyPosition.x;
	y = this->theEnemyPosition.y;
}

void AI_state_attack::SetEnemyPosition(const float x, const float y)
{
	this->theEnemyPosition.x = x;
	this->theEnemyPosition.y = y;
}
