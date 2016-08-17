#ifndef AI_STATE_PARTOL_H
#define AI_STATE_PARTOL_H

#include "AI_State.h"
#include "Vector2.h"

class AI_state_partol : public AI_state
{
public:
	AI_state_partol(void);
	~AI_state_partol(void);

	void Update(double);
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	void SetEnemyPosition(const float x, const float y);

	/*
	void SetPatrolSpeed(float);
	float GetPatrolSpeed();
	*/

	float patrolSpeed;
};

#endif