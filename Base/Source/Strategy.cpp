#include"Strategy.h"
#include <iostream>

using namespace std;

Strategy::Strategy()
{

}

Strategy::~Strategy()
{

}

void Strategy::Update()
{
	cout << "void Strategy::Update()" << endl;
}

int Strategy::CalculateDistance()
{
	return ((theDestination.x - theEnemyPosition.x) * (theDestination.x - theEnemyPosition.x)
		+ (theDestination.y - theEnemyPosition.y)*(theDestination.y - theEnemyPosition.y));
}

