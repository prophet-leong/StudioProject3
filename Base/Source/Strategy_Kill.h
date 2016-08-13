#ifndef STRATEGY_KILL_H 
#define STRATEGY_KILL_H
#include"Strategy.h"
#include "Vector2.h"

class Strategy_Kill :public Strategy
{
public:
	Strategy_Kill();
	~Strategy_Kill();

	void Update();
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float &x, float &y);
	void SetEnemyPosition(const float x, const float y);

	enum CURRENT_STATE
	{
		IDLE,
		REPEL,
		ATTACK,
		NUM_ENEMY_STATE,
	};

	CURRENT_STATE GetState();
	void SetState(CURRENT_STATE);


private:

	CURRENT_STATE currentState;
};


#endif