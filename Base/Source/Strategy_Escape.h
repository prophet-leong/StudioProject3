#pragma once
#include "Strategy.h"
#include "Vector2.h"

class Strategy_Escape
	: public Strategy
{
public:
	Strategy_Escape(void);
	~Strategy_Escape(void);

	void Update(void);
	void SetDestination(const float x, const float y);
	void GetEnemyPosition(float& x, float& y);
	void SetEnemyPosition(const float x, const float y);

private:

};
