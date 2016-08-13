#ifndef ENEMY_H 
#define ENEMY_H
#include "avatar.h"
#include "Strategy.h"

class Enemy : public Avatar
{
public:
	Enemy(int x, int y, string meshName, string meshTexture[]);
	~Enemy();

	enum GEOMETRY_TYPE
	{
		GEO_TILEENEMY_FRAME0,
		GEO_TILEENEMY_FRAME1,
		GEO_TILEENEMY_FRAME2,
		GEO_TILEENEMY_FRAME3,
		NUM_GEOMETRY,
	};
	string texture[NUM_GEOMETRY];

	// Set the destination of this enemy 
	void SetDestination(const int pos_x,const int pos_y);
	// Set the destination of this enemy 
	int GetDestination_x();
	// Set the destination of this enemy 
	int GetDestination_y();

	//Functions
	void CheckStrategy(Avatar* other);
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