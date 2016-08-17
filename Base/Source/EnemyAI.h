#ifndef ENEMY_AI_H 
#define ENEMY_AI_H

#include "avatar.h"
#include "AI_State_Idle.h"
#include "AI_State_Attack.h"
#include "AI_State_chase.h"
#include "AI_State_partol.h"
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

	// SET
	void SetPosition(float, float);
	void SetEnemyPosition(float, float);
	void SetDestination(float, float);
	void SetWayPoint(Vector2);

	void SetPatrolTimer(float);
	void SetChaseTimer(float);
	void SetAttackTimer(float);

	void SetPatrolWaitTime(float);
	void SetChaseWaitTime(float);
	void SetAttackWaitTime(float);

	void SetSearchRadius(float);
	void SetAttackRadius(float);

	void SetDamage(int);
	void SetWayPointIndex(int);

	void SetPatrol(bool);
	void SetChase(bool);
	void SetAttack(bool);
	void SetTimer(bool);

	//Get
	float GetPosition_x();
	float GetPosition_y();
	float GetEnemyPosition_x();
	float GetEnemyPosition_y();
	float GetDestination_x();
	float GetDestination_y();
	int GetwayPointIndex();
	int GetWaypointSize();

	float GetPatrolTimer();
	float GetChaseTimer();
	float GetAttackTimer();

	float GetPatrolWaitTime();
	float GetChaseWaitTime();
	float GetAttackWaitTime();
	
	float GetAttackRadius();
	float GetSearchRadius();

	int GetDamage();

	bool GetPatrol();
	bool GetChase();
	bool GetAttack();
	bool GetTimer();
	
	void CheckAI_State(GameObject* other, TileMap* tilemap);
	void ChangeStrategy(AI_state* theNewAI_State, bool bDelete = true);

	float CalculateDistance();
	bool WayPointReach();
	
	void UpdataTimer(double);

	void init();
	void Update(double);
	
private:
	Vector2 Position;
	Vector2 theEnemyPosition;
	Vector2 Destination;
	vector<Vector2> wayPoint;

	AI_state* theAI_State;

	float patrolTimer;
	float chaseTimer;
	float attackTimer;

	float patrolWaitTime;
	float chaseWaitTime;
	float attackWaitTime;

	float SearchRadius;
	float AttackRadius;

	int damage;
	int wayPointIndex;

	bool reachWayPoint;
	bool patrol;
	bool chase;
	bool attack;
	bool timer;
};


#endif