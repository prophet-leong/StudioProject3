#ifndef STRATEGY_H
#define STRATEGY_H

#include "Vector2.h"

class Strategy
{
public:
	Strategy();
	~Strategy();

	virtual void Update() = 0;
	virtual void SetDestination(const float x, const float y) = 0;
	virtual void GetEnemyPosition(float &x, float &y) = 0;
	virtual void SetEnemyPosition(const float x, const float y) = 0;

	int CalculateDistance();

	Vector2 theDestination;
	Vector2 theEnemyPosition;
private:
};



#endif