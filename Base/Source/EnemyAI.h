#ifndef ENEMY_AI_H 
#define ENEMY_AI_H

#include "avatar.h"
#include <vector>

using std::vector;

class EnemyAI : public Avatar
{
	enum State
	{
		IDLE,
		ATTACK,
		CHASE,
		PATROL,
		ESPA,

		NUM_STATE
	};


	enum Enemy
	{
		GHOST,

		BOSS_GHOST,

		NUM_GHOST
	};

public:
	
	EnemyAI(int x, int y, string meshName, GEOMETRY_TYPE tileOfTile[], int numberOfTextures);
	~EnemyAI();
	void init();

	//set
	void SetDestination(int,int);
	void SetWayPoint(Vector2);

	void SetPatrolSpeed(float);
	void SetChaseSpeed(float);
	void SetPatrolWaitTime(float);
	void SetChaseWaitTime(float);
	void SetPatrolTimer(float);
	void SetChaseTimer(float);
	void SetwayPointIndex(int);

	// get
	int GetDestination_x();
	int GetDestination_y();

	float GetPatrolSpeed;
	float GetChaseSpeed;
	float GetPatrolWaitTime;
	float GetChaseWaitTime;
	float GetPatrolTimer;
	float GetChaseTimer;
	int GetwayPointIndex;



	//virtual void init();
	void Update();
	
private:


	Vector2 Destination;
	vector<Vector2> wayPoint;

	
	float patrolSpeed;
	float chaseSpeed;

	float patrolWaitTime;
	float chaseWaitTime;

	float patrolTimer;
	float chaseTimer;
	
	int wayPointIndex;

};


#endif