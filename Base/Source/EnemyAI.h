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
	virtual~EnemyAI();

	// SET
	void SetPosition(float x, float y){ this->Position.x = x; this->Position.y = y; }
	void SetEnemyPosition(float x, float y){ this->theEnemyPosition.x = x; this->theEnemyPosition.y = y; }
	void SetDestination(float x, float y){ this->Destination.x = x; this->Destination.y = y; }
	void SetWayPoint(Vector2 point){ this->wayPoint.push_back(point); }

	void SetPatrolTimer(float timer){ this->patrolTimer = timer; }
	void SetChaseTimer(float timer){ this->chaseTimer = timer; }
	void SetAttackTimer(float timer){ this->attackTimer = timer; }
	void SetTime(float time){ this->Time = time; }

	void SetPatrolWaitTime(float time){ this->patrolWaitTime = time; }
	void SetChaseWaitTime(float time){ this->chaseWaitTime = time; }
	void SetAttackWaitTime(float time){ this->attackWaitTime = time; }

	void SetSearchRadius(float distance){ this->SearchRadius = distance; }
	void SetAttackRadius(float distance){ this->AttackRadius = distance; }

	void SetDamage(int damage){ this->damage = damage; }
	void SetWayPointIndex(int point){ this->wayPointIndex = point; }

	void SetPatrol(bool state){ this->patrol = state; }
	void SetChase(bool state){ this->chase = state; }
	void SetAttack(bool state){ this->attack = state; }

	//Get
	float GetPosition_x(){ return Position.x; }
	float GetPosition_y(){ return Position.y; }
	float GetEnemyPosition_x(){ return theEnemyPosition.x; }
	float GetEnemyPosition_y(){ return theEnemyPosition.y; }
	float GetDestination_x(){ return Destination.x; }
	float GetDestination_y(){ return Destination.y; }
	int GetwayPointIndex(){ return wayPointIndex; }
	int GetWaypointSize(){ return wayPoint.size(); }

	float GetPatrolTimer(){ return patrolTimer; }
	float GetChaseTimer(){ return chaseTimer; }
	float GetAttackTimer(){ return attackTimer; }
	float GetTime(){ return Time; }

	float GetPatrolWaitTime(){ return patrolWaitTime; }
	float GetChaseWaitTime(){ return chaseWaitTime; }
	float GetAttackWaitTime(){ return attackWaitTime; }
	
	float GetAttackRadius(){ return AttackRadius; }
	float GetSearchRadius(){ return SearchRadius; }

	int GetDamage(){ return damage; }

	bool GetPatrol(){ return patrol; }
	bool GetChase(){ return chase; }
	bool GetAttack(){ return attack; }
	
	void CheckAI_State(GameObject* other, TileMap* tilemap);
	void ChangeStrategy(AI_state* theNewAI_State, bool bDelete = true);

	float CalculateDistance();
	bool WayPointReach();
	
	void UpdataTimer(double);

	virtual void init();
	virtual void Update(double);
	
private:
	Vector2 Position;
	Vector2 theEnemyPosition;
	Vector2 Destination;
	vector<Vector2> wayPoint;

	AI_state* theAI_State;

	float patrolTimer;
	float chaseTimer;
	float attackTimer;
	
	float Time; // can remove the top 3 timer 



	float patrolWaitTime;
	float chaseWaitTime;
	float attackWaitTime;

	float SearchRadius;
	float AttackRadius;

	int damage;
	int wayPointIndex;

	bool reachWayPoint;

	bool patrol;
	bool chase; // chase = chase is over!!!!!!!!
	bool attack;
};


#endif