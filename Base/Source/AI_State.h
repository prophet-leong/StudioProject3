#ifndef AI_STATE_H
#define AI_STATE_H

#include "Vector2.h"

class AI_state
{
public:
	AI_state();
	~AI_state();

	virtual void Update(double) = 0;
	virtual void SetDestination(const float x, const float y) = 0;
	virtual void GetEnemyPosition(float &x, float &y) = 0;
	virtual void SetEnemyPosition(const float x, const float y) = 0;

	Vector2 theDestination;
	Vector2 theEnemyPosition;

private:
	
	
};



#endif