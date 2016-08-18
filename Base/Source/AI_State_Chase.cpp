#include "AI_State_Chase.h"
#include <iostream>

using namespace std;

AI_state_chase::AI_state_chase()
{
}

AI_state_chase::~AI_state_chase()
{
}

void AI_state_chase::Update(double dt)
{
	cout << "void AI_state_chase::Update()" << endl;
	// run toward hero
}

void AI_state_chase::SetDestination(const float x, const float y)
{
	this->theDestination.x = x;
	this->theDestination.y = y;
}

void AI_state_chase::GetEnemyPosition(float& x, float& y)
{
	x = this->theEnemyPosition.x;
	y = this->theEnemyPosition.y;
}

void AI_state_chase::SetEnemyPosition(const float x, const float y)
{
	this->theEnemyPosition.x = x;
	this->theEnemyPosition.y = y;
}

/*
void EnemyAI::SetChaseSpeed(float speed)
{
	this->chaseSpeed = speed;
}
float EnemyAI::GetChaseSpeed()
{
	return this->chaseSpeed;
}
*/