#ifndef HERO_H
#define HERO_H

#include "avatar.h"

class Hero : public Avatar
{
public:
	Hero(int x,int y,string meshName,string meshTexture[]);
	~Hero();

	enum GEOMETRY_TYPE
	{
		GEO_TILEHERO_FRAME0,
		GEO_TILEHERO_FRAME1,
		GEO_TILEHERO_FRAME2,
		GEO_TILEHERO_FRAME3,
		NUM_GEOMETRY,
	};

	string texture[NUM_GEOMETRY];

	//update
	void Update(TileMap* tilemap,double dt);
	void UpdateJump(double dt);
	void UpdateJumpUpwards(double dt);
	void UpdateFreeFall(double dt);

	//functions
	void Scrolling(TileMap* tilemap,const int leftBorder, const int rightBorder,
		const int topBorder, const int bottomBorder,
		float timeDiff);
	void Constrain(TileMap* tilemap);
	void Reset(TileMap* tilemap);
	void Restart(TileMap* tilemap);
	//movement
	void MoveLeftRight(const bool mode, const float timeDiff,TileMap* tilemap);
	void MoveUpDown(const bool mode, const float timeDiff, TileMap* tilemap);

private:
//hero info
	int moveX, moveY;
	int initX, initY;

};

















#endif