#ifndef AI_STATE_IDLE_H
#define AI_STATE_IDLE_H

#include "AI_State.h"
#include "Vector2.h"

class AI_state_idle : public AI_state
{
public:
	AI_state_idle(void);
	~AI_state_idle(void);

	void Update(double);
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	void SetEnemyPosition(const float x, const float y);

private:

};

#endif