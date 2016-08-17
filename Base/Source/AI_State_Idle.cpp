#include "AI_state_idle.h"
#include <iostream>

using namespace std;

AI_state_idle::AI_state_idle()
{
}

AI_state_idle::~AI_state_idle()
{
}

void AI_state_idle::Update(double dt)
{
	
}

void AI_state_idle::SetDestination(const float x, const float y)
{
	this->theDestination.x = x;
	this->theDestination.y = y;
}

void AI_state_idle::GetEnemyPosition(float& x, float& y)
{
	x = this->theEnemyPosition.x;
	y = this->theEnemyPosition.y;
}

void AI_state_idle::SetEnemyPosition(const float x, const float y)
{
	this->theEnemyPosition.x = x;
	this->theEnemyPosition.y = y;
}
