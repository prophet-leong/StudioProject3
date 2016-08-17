#include "AI_State_Partol.h"
#include <iostream>

using namespace std;

AI_state_partol::AI_state_partol()
{
}

AI_state_partol::~AI_state_partol()
{
}

void AI_state_partol::Update(double dt)
{


}

void AI_state_partol::SetDestination(const float x, const float y)
{
	this->theDestination.x = x;
	this->theDestination.y = y;
}

void AI_state_partol::GetEnemyPosition(float& x, float& y)
{
	x = this->theEnemyPosition.x;
	y = this->theEnemyPosition.y;
}

void AI_state_partol::SetEnemyPosition(const float x, const float y)
{
	this->theEnemyPosition.x = x;
	this->theEnemyPosition.y = y;
}


/*
void EnemyAI::SetPatrolSpeed(float speed)
{
	this->patrolSpeed = speed;
}
float EnemyAI::GetPatrolSpeed()
{
	return this->patrolSpeed;
}
*/
