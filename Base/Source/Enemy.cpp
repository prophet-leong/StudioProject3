#include "Enemy.h"

Enemy::Enemy(int x ,int y,string meshName,GEOMETRY_TYPE typeOfTile[],int numberOfTextures)
	: theStrategy(NULL)
	, Avatar(x, y, meshName, typeOfTile[0])
{
	for (int i = 0; i < numberOfTextures; ++i)
	{
		this->texture[i] = typeOfTile[i];
	}
}

Enemy::~Enemy()
{
	if (theStrategy != NULL)
	{
		delete
			theStrategy;
		theStrategy = NULL;
	}
}
// Set the destination of this enemy 
void Enemy::SetDestination(const int pos_x,const int pos_y)
{
	theDestination.x = pos_x;
	theDestination.y = pos_y;
	if (theStrategy != NULL)
	{
		theStrategy->SetDestination(theDestination.x, theDestination.y);
	}
}
// Set the destination of this enemy 
int Enemy::GetDestination_x()
{
	return theDestination.x;
}
// Set the destination of this enemy 
int Enemy::GetDestination_y()
{
	return theDestination.y;
}
/********************************************************************************
Hero Update
********************************************************************************/
void Enemy::Update()
{
	if (theStrategy != NULL)
	{
		theStrategy ->Update();
		theStrategy->GetEnemyPosition((Position.x), (Position.y)); 
		AnimationInvert = false;
		AnimationCounterLR++;
		if (AnimationCounterLR > 3)
			AnimationCounterLR = 0;
		SetTexture(texture[AnimationCounterLR]);
	}
}
/********************************************************************************
Strategy
********************************************************************************/
void Enemy::ChangeStrategy(Strategy* theNewStrategy,bool bDelete)
{
	if (bDelete == true)
	{
		if (theStrategy != NULL)
		{
			delete theStrategy;
			theStrategy = NULL;
		}
	}
	theStrategy = theNewStrategy;
	if (theStrategy != NULL)
	{
		theStrategy ->SetDestination(theDestination.x, theDestination.y);
		theStrategy ->SetEnemyPosition( Position.x, Position.y);
	}
}

