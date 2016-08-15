#include "EnemyAI.h"

EnemyAI::EnemyAI(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile[], int numberOfTextures)
: theStrategy(NULL)
, Avatar(x, y, meshName, typeOfTile[0])
{
	for (int i = 0; i < numberOfTextures; ++i)
	{
		this->texture[i] = typeOfTile[i];
	}
}

EnemyAI::~EnemyAI()
{
}
void EnemyAI::init()
{
	switch (type)
	{
	case GHOST:
	{
				  this->patrolSpeed = 2.f;
				  this->chaseSpeed = 5.f;
				  this->patrolWaitTime = 1.f;
				  this->chaseWaitTime = 5.f;
				  this->patrolTimer = 0.f;
				  this->chaseTimer = 0.f;
				  break;
	}
	case BOSS_GHOST:
	{   
					   this->chaseSpeed = 3.f;
					   break;
	}
	}
	

}

void EnemyAI::Update()
{

}
