#include "Strategy_Escape.h"
#include <iostream>

using namespace std;

Strategy_Escape::Strategy_Escape()
{
}

Strategy_Escape::~Strategy_Escape()
{
}

void Strategy_Escape::Update(void)
{
	//theEnemyPosition.x += (theDestination.x - theEnemyPosition.x > 0 ? -5 : 5 );
	//theEnemyPosition.y = theEnemyPosition.y + (theDestination.y - theEnemyPosition.y > 0 ? 5 : -5 );
}

void Strategy_Escape::SetDestination(const float x, const float y)
{
	theDestination.x = x;
	theDestination.y = y;
}

void Strategy_Escape::GetEnemyPosition(float& x, float& y)
{
	x = theEnemyPosition.x;
	y = theEnemyPosition.y;
}

void Strategy_Escape::SetEnemyPosition(const float x, const float y)
{
	theEnemyPosition.x = x;
	theEnemyPosition.y = y;
}
