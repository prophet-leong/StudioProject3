#include "EnemyAI.h"

EnemyAI::EnemyAI(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile[], int numberOfTextures)
	:Avatar(x,y,meshName,typeOfTile[0])
{
	for (int i = 0; i < numberOfTextures; ++i)
	{
		this->texture[i] = typeOfTile[i];
	}
}

EnemyAI::~EnemyAI()
{
}

void EnemyAI::CheckAI_State(GameObject* other, TileMap* tilemap)
{
	float distanceHeroToEnemy = CalculateDistance();

	if (!patrol && chase || !attack)
	{
		ChangeStrategy(new AI_state_idle);
	}

	if (!WayPointReach() && reachWayPoint)
	{
		reachWayPoint = false;
	} 
	if (WayPointReach() && !reachWayPoint && chase)
	{
		reachWayPoint = true;
		patrol = false;
	}
	if (distanceHeroToEnemy > GetSearchRadius() && patrol)
	{
		ChangeStrategy(new AI_state_partol);
	}

	if (distanceHeroToEnemy < GetSearchRadius())
	{
		patrol = false;
		chase = false;
		ChangeStrategy(new AI_state_chase);
	}

	if (chase && !patrol && !reachWayPoint)
	{
		patrol = true;
	}

	if (distanceHeroToEnemy < GetAttackRadius() && attack)
	{
		ChangeStrategy(new AI_state_attack);
		attack = false;
	}
}

void EnemyAI::ChangeStrategy(AI_state* theNewAI_State, bool bDelete)
{
	if (bDelete == true)
	{
		if (this->theAI_State != NULL)
		{
			delete this->theAI_State;
			this->theAI_State = NULL;
		}
	}
	this->theAI_State = theNewAI_State;
	if (this->theAI_State != NULL)
	{
		this->theAI_State->SetDestination(this->Destination.x, this->Destination.y);
		this->theAI_State->SetEnemyPosition(this->theEnemyPosition.x, this->theEnemyPosition.y);
	}
}

float EnemyAI::CalculateDistance()
{
	// a^2 + b^2 = c^2
	return ((Position.x - theEnemyPosition.x) * (Position.x - theEnemyPosition.x) + (Position.y - theEnemyPosition.y)*(Position.y - theEnemyPosition.y));
}

bool EnemyAI::WayPointReach()
{
	// a^2 + b^2 = c^2
	return (((Position.x - Destination.x) * (Position.x - Destination.x) + (Position.y - Destination.y)*(Position.y - Destination.y)) < 10.f);
}

void EnemyAI::UpdataTimer(double dt)
{
	if (!patrol || !chase || !attack) Time += dt;

	if (Time >= patrolWaitTime && reachWayPoint && !patrol)
	{
		patrol = true;
		Time = 0.f;
	}
	if (Time >= chaseWaitTime && !patrol && !chase) 
	{
		chase = true;
		Time = 0.f;
	}
	if (Time >= attackWaitTime && !attack)
	{
		attack = true;
		Time = 0.f;
	}
}

void EnemyAI::init()
{
	switch (type)
	{
	case GHOST:
	{
				  break;
	}
	case BOSS_GHOST:
	{   
					   break;
	}
	}
	

}

void EnemyAI::Update(double dt)
{
	UpdataTimer(dt);

	if (theAI_State != NULL)
	{
		theAI_State->Update(dt);
		theAI_State->GetEnemyPosition((Position.x), (Position.y));
	}
}

bool EnemyAI::CheckCollision(GameObject* other, TileMap *tilemap)
{
	return false;
}

void EnemyAI::CollisionResponse(GameObject* other, TileMap *tilemap)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// SET

//void EnemyAI::SetPosition(float x, float y)
//{
//	this->Position.x = x;
//	this->Position.y = y;
//}
//
//void EnemyAI::SetEnemyPosition(float x, float y)
//{
//	this->theEnemyPosition.x = x;
//	this->theEnemyPosition.y = y;
//}
//
//void EnemyAI::SetDestination(float x, float y)
//{
//	this->Destination.x = x;
//	this->Destination.y = y;
//}
//
//void EnemyAI::SetWayPoint(Vector2 point)
//{
//	this->wayPoint.push_back(point);
//
//}
//
//void EnemyAI::SetPatrolTimer(float timer)
//{
//	this->patrolTimer = timer;
//}
//
//void EnemyAI::SetChaseTimer(float timer)
//{
//	this->chaseTimer = timer;
//}
//
//void EnemyAI::SetAttackTimer(float timer)
//{
//	this->attackTimer = timer;
//}
//
//void EnemyAI::SetPatrolWaitTime(float time)
//{
//	this->patrolWaitTime = time;
//}
//
//void EnemyAI::SetChaseWaitTime(float time)
//{
//	this->chaseWaitTime = time;
//}
//
//void EnemyAI::SetAttackWaitTime(float time)
//{
//	this->attackWaitTime = time;
//}
//
//
//
//void EnemyAI::SetSearchRadius(float distance)
//{
//	this->SearchRadius = distance;
//}
//
//void EnemyAI::SetAttackRadius(float distance)
//{
//	this->AttackRadius = distance;
//}
//
//void EnemyAI::SetDamage(int damage)
//{
//	this->damage = damage;
//}
//
//void EnemyAI::SetWayPointIndex(int point)
//{
//	this->wayPointIndex = point;
//}
//
//void EnemyAI::SetPatrol(bool state)
//{
//	this->patrol = state;
//}
//
//void EnemyAI::SetChase(bool state)
//{
//	this->chase = state;
//}
//
//void EnemyAI::SetAttack(bool state)
//{
//	this->attack = state;
//}
//
//void EnemyAI::SetTimer(bool state)
//{
//	this->timer = state;
//}
//

////////////////////////////////////////////////////////////////////////////////////////////////
// GET

//float EnemyAI::GetPosition_x()
//{
//	return this->Position.x;
//}
//
//float EnemyAI::GetPosition_y()
//{
//	return this->Position.y;
//}
//
//float EnemyAI::GetEnemyPosition_x()
//{
//	return this->theEnemyPosition.x;
//}
//
//float EnemyAI::GetEnemyPosition_y()
//{
//	return this->theEnemyPosition.y;
//}
//
//float EnemyAI::GetDestination_x()
//{
//	return this->Destination.x;
//}
//
//float EnemyAI::GetDestination_y()
//{
//	return this->Destination.y;
//}
//
//int EnemyAI::GetwayPointIndex()
//{
//	return this->wayPointIndex;
//}
//
//int EnemyAI::GetWaypointSize()
//{
//	return this->wayPoint.size();
//}
//
//float EnemyAI::GetPatrolTimer()
//{
//	return this->patrolTimer;
//}
//
//float EnemyAI::GetChaseTimer()
//{
//	return this->chaseTimer;
//}
//
//float EnemyAI::GetAttackTimer()
//{
//	return this->attackTimer;
//}
//
//float EnemyAI::GetPatrolWaitTime()
//{
//	return this->patrolWaitTime;
//}
//
//float EnemyAI::GetChaseWaitTime()
//{
//	return this->chaseWaitTime;
//}
//
//float EnemyAI::GetAttackWaitTime()
//{
//	return this->attackWaitTime;
//}
//
//
//float EnemyAI::GetSearchRadius()
//{
//	return this->SearchRadius;
//}
//
//float EnemyAI::GetAttackRadius()
//{
//	return this->AttackRadius;
//}
//
//int EnemyAI::GetDamage()
//{
//	return this->damage;
//}
//
//bool EnemyAI::GetPatrol()
//{
//	return this->patrol;
//}
//
//bool EnemyAI::GetChase()
//{
//	return this->chase;
//}
//
//bool EnemyAI::GetAttack()
//{
//	return this->attack;
//}
//
//bool EnemyAI::GetTimer()
//{
//	return this->timer;
//}
//
