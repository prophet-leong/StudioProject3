#include "Strategy_Kill.h"
#include "Assignment.h"

Strategy_Kill::Strategy_Kill()
{

}

Strategy_Kill::~Strategy_Kill()
{

}

void Strategy_Kill::Update()
{
	int distanceHeroToEnemy = CalculateDistance();
	if (distanceHeroToEnemy < 10000.f)
	{
		if (distanceHeroToEnemy < 625.0f)
			currentState = REPEL;
		else if (distanceHeroToEnemy - 5.f > 625.0f)
			currentState = ATTACK;
		else
			currentState = IDLE;
	}
	else
		currentState = IDLE;

	switch (currentState)
	{
	case ATTACK:
		theEnemyPosition.x += (theDestination.x - theEnemyPosition.x > 0 ? 5 : -5);
		break;
	case REPEL:
		theEnemyPosition.x += (theDestination.x - theEnemyPosition.x > 0 ? -5 : 5);
		break;
	}

}

void Strategy_Kill::SetDestination(const float x, const float y)
{
	theDestination.x = x;
	theDestination.y = y;
}

void Strategy_Kill::GetEnemyPosition(float &x, float &y)
{
	x = theEnemyPosition.x;
	y = theEnemyPosition.y;
}

void Strategy_Kill::SetEnemyPosition(const float x, const float y)
{
	theEnemyPosition.x = x;
	theEnemyPosition.y = y;
}

Strategy_Kill::CURRENT_STATE Strategy_Kill::GetState()
{
	return currentState;
}

void Strategy_Kill::SetState(CURRENT_STATE theEnemyState)
{
	currentState = theEnemyState;
}

