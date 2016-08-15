#include "Hero.h"

//'x' and 'y' is position , meshName = name of the mesh , typeoftile = geometry type , numberoftextures = amount of textures for 'typeOfTile' 1 texture = 1
Hero::Hero(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile[],int numberOfTextures)
	: moveX(0)
	, moveY(0)
	, initX(x)
	, initY(y)
	, Avatar(x, y, meshName, typeOfTile[0])
{
	for (int i = 0; i < numberOfTextures; ++i)
	{
		this->texture[i] = typeOfTile[i];
	}
}

Hero::~Hero()
{
}

// Update Jump Upwards
void Hero::UpdateJumpUpwards(double dt)
{
	if (moveUp)
	{
		Position.y += (int)(8.0f /** dt * 60.f*/);
		UpwardsFrame -= 1;

	}
	if (!moveUp || UpwardsFrame <= 0)
	{
		inMidAir_Up = false;
		inMidAir_Down = true;
	}
}

// Update FreeFall
void Hero::UpdateFreeFall(double dt)
{
	Position.y += (int)(8.0f/* * dt * 60.f*/);
}

//status::done
void Hero::UpdateJump(double dt)
{
	//check for falling
	if (isOnGround())
	{
		SetOnFreeFall(moveDown);
	}
	// update jumping upwards
	else if (isJumpUpwards())
	{
		UpdateJumpUpwards(dt);
	}
	// update falling
	else if (isFreeFall())
	{
		//Check if the hero is still in mid air...
		if (moveDown)
		{
			Position.y -= (int)(8.0f /** dt * 60.f*/);
		}
		else
		{
			inMidAir_Down = false;
		}
	}
}

//status::done
void Hero::Update(TileMap* tilemap , double dt)
{
	for (vector<PowerUp*>::iterator iter = inventory->powerUpList.begin(); iter != inventory->powerUpList.end(); iter++)
	{
		PowerUp *go = (PowerUp *)*iter;

		if (go->powerUpDuration > 0)
		{
			if (go->powerup == "Scale")
				scale.y = 2.f;
		}
		else
		{
			scale.y = 1.f;
		}
	}

	moveLeft = moveRight = moveUp = moveDown = true;

	inventory->Update(dt);

	moveX = (tilemap->GetScreenWidth() * 0.5f) + tilemap->offSet_x;
	moveY = (tilemap->GetScreenHeight() * 0.7f) + tilemap->offSet_y;

	Scrolling(tilemap, tilemap->offSet_x , moveX , moveY , tilemap->offSet_y + 160, 60.f * dt);
	
	Constrain(tilemap);
}

//status::done
void Hero::Constrain(TileMap* tilemap)
{
	if (Position.x < 0)
		Position.x = 0;
	if (Position.x > tilemap->GetMapWidth() - tilemap->GetTileSize())
		Position.x = tilemap->GetMapWidth() - tilemap->GetTileSize();
	if (Position.y < 0)
		Position.y = 0;
	if (Position.y > tilemap->GetMapHeight() - tilemap->GetTileSize())
		Position.y = tilemap->GetMapHeight() - tilemap->GetTileSize();
}

//Soft-Reset
void Hero::Reset(TileMap* tilemap)
{
	SetPos(initX, initY);
	SetAnimationCounterLR(0);
	SetAnimationInvert(false);
	SetToStop();
	inventory->powerUpList.clear();
	scale.y = 1.f;
	tilemap->offSet_x = 0;
	tilemap->fineOffSet_y = 0;
}

//Full-Reset
void Hero::Restart(TileMap* tilemap)
{
	health = 3;
}

// status:done
void Hero::Scrolling(TileMap* tilemap,const int leftBorder, const int rightBorder,
		const int topBorder, const int bottomBorder,
		float timeDiff)
{
	if (Position.x <= leftBorder)
	{
		tilemap->offSet_x += Position.x - leftBorder;
		if (tilemap->offSet_x < 0)
			tilemap->offSet_x = 0;	
	}
	else if (Position.x >= rightBorder)
	{
		tilemap->offSet_x += Position.x - rightBorder;
		if (tilemap->offSet_x > tilemap->GetMapWidth()  - tilemap->GetScreenWidth())	// This must be changed to soft-coded
			tilemap->offSet_x = tilemap->GetMapWidth() - tilemap->GetScreenWidth();
	}
	if (Position.y >= topBorder)
	{
		tilemap->offSet_y += Position.y - topBorder;
		if (tilemap->offSet_y > tilemap->GetMapHeight() - tilemap->GetScreenHeight())
			tilemap->offSet_y = tilemap->GetMapHeight() - tilemap->GetScreenHeight();
	}
	else if (Position.y <= bottomBorder)
	{
		tilemap->offSet_y += Position.y - bottomBorder;
		if (tilemap->offSet_y < 0)	// This must be changed to soft-coded
			tilemap->offSet_y = 0;
	}
}

void Hero::MoveLeftRight(const bool mode, const float timeDiff,TileMap* tilemap)
{
	if (mode)
	{
		//move left
		if (moveLeft)
		{
			Position.x -= (int)(8.0f * timeDiff);
		}
		AnimationInvert = true;
		AnimationCounterLR--;
		if (AnimationCounterLR < 0)
			AnimationCounterLR = 3;
	}
	else
	{
		//move right
		if (moveRight)
		{
			Position.x += (int)(8.0f * timeDiff);
		}
		AnimationInvert = false;
		AnimationCounterLR++;
		if (AnimationCounterLR > 3)
			AnimationCounterLR = 0;
	}

	SetTexture(texture[AnimationCounterLR]);
}

void Hero::MoveUpDown(const bool mode, const float timeDiff, TileMap* tilemap)
{
	if (mode)
	{
		if (moveUp)
			Position.y += (int)(8.0f * timeDiff);

		AnimationInvert = true;
		AnimationCounterUD--;
		if (AnimationCounterUD < 0)
			AnimationCounterUD = 3;
	}
	else
	{
		if (moveDown)
		{
			Position.y -= (int)(8.0f * timeDiff);
		}
		AnimationInvert = false;
		AnimationCounterUD++;
		if (AnimationCounterUD > 3)
			AnimationCounterUD = 0;
	}

	SetTexture(texture[AnimationCounterLR]);
}

