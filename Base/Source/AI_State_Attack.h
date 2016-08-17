#ifndef AI_STATE_ATTACK_H
#define AI_STATE_ATTACK_H

#include "AI_State.h"
#include "Vector2.h"

class AI_state_attack : public AI_state
{
public:
	AI_state_attack(void);
	~AI_state_attack(void);

	void Update(double);
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	void SetEnemyPosition(const float x, const float y);

	float attackSpeed;

};

#endif