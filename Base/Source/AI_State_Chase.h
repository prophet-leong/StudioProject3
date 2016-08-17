#ifndef AI_STATE_CHASE_H
#define AI_STATE_CHASE_H

#include "AI_State.h"
#include "Vector2.h"

class AI_state_chase : public AI_state
{
public:
	AI_state_chase(void);
	~AI_state_chase(void);

	void Update(double);
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	void SetEnemyPosition(const float x, const float y);

	/*
	void SetChaseSpeed(float);
	float GetChaseSpeed();
	*/

	float chaseSpeed;
	

};

#endif