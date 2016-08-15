#ifndef ENEMY_H 
#define ENEMY_H
#include "avatar.h"
#include "TileMap.h"
#include "Strategy.h"

class Enemy : public Avatar
{
public:
	Enemy(int x, int y, string meshName, GEOMETRY_TYPE tileOfTile[], int numberOfTextures);
	virtual ~Enemy();

	GEOMETRY_TYPE texture[NUM_GEOMETRY];
	

	// Set the destination of this enemy 
	void SetDestination(const int pos_x,const int pos_y);
	// Set the destination of this enemy 
	int GetDestination_x();
	// Set the destination of this enemy 
	int GetDestination_y();

	// ENEMY Update 
	void Update();
	// Strategy
	void ChangeStrategy(Strategy* theNewStrategy, bool bDelete = true);

private:
	// The Destination is the position of the Hero 
	Vector2 theDestination;
	Strategy* theStrategy;
};




#endif