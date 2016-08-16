#include "avatar.h"

Avatar::Avatar()
	:GameObject()
{

}

Avatar::Avatar(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile)
	: GameObject(x, y, meshName, typeOfTile)
	, inMidAir_Down(false)
	, inMidAir_Up(false)
	, jumpSpeed(0)
	, UpwardsFrame(0)
	, AnimationCounterLR(0)
	, AnimationCounterUD(0)
	, AnimationInvert(false)
	, moveUp(true)
	, moveDown(true)
	, moveLeft(true)
	, moveRight(true)
{
	inventory = new Bag();
}

Avatar::~Avatar()
{
	delete inventory;
}
/////////////////FUNCTIONS///////////////////////

bool Avatar::CheckCollision(GameObject* other,TileMap* tilemap)
{
	return ( (GetPosition() - other->GetPosition()).LengthSquare() < 1.5f*tilemap->GetTileSize()*tilemap->GetTileSize() );
}
void Avatar::CollisionResponse(GameObject* other, TileMap* tilemap)
{
	if (other->type == GEO_TILEGROUND)//|| whatever other object you want that have collision)
	{
		if (GetPosition().x < other->GetPosition().x && other->GetPosition().x - GetPosition().x <= tilemap->GetTileSize())
		{
			if (GetPosition().y >= other->GetPosition().y && GetPosition().y - other->GetPosition().y < tilemap->GetTileSize() ||
				other->GetPosition().y >= GetPosition().y && other->GetPosition().y - GetPosition().y < tilemap->GetTileSize())
				moveRight = false;
		}
		else if (other->GetPosition().x < GetPosition().x && GetPosition().x - other->GetPosition().x <= tilemap->GetTileSize())
		{
			if (GetPosition().y >= other->GetPosition().y && GetPosition().y - other->GetPosition().y < tilemap->GetTileSize() ||
				other->GetPosition().y >= GetPosition().y && other->GetPosition().y - GetPosition().y < tilemap->GetTileSize())
				moveLeft = false;
		}

		if (GetPosition().y < other->GetPosition().y && other->GetPosition().y - GetPosition().y <= tilemap->GetTileSize())
		{
			if (GetPosition().x >= other->GetPosition().x && GetPosition().x - other->GetPosition().x < tilemap->GetTileSize() * 0.75f ||
				other->GetPosition().x >= GetPosition().x && other->GetPosition().x - GetPosition().x < tilemap->GetTileSize() * 0.75f)
				moveUp = false;
		}
		else if (other->GetPosition().y < GetPosition().y && GetPosition().y - other->GetPosition().y <= tilemap->GetTileSize())
		{
			if (GetPosition().x >= other->GetPosition().x && GetPosition().x - other->GetPosition().x < tilemap->GetTileSize()* 0.75f ||
				other->GetPosition().x >= GetPosition().x && other->GetPosition().x - GetPosition().x < tilemap->GetTileSize()* 0.75f)
				moveDown = false;
		}
	}
}

void Avatar::CheckStrategy(GameObject* other, TileMap* tilemap)
{

}

//////////////////SETTERS////////////////////

//Animation
void Avatar::SetAnimationCounterLR(int AnimationCounterLR)
{
	this->AnimationCounterLR = AnimationCounterLR;
}

void Avatar::SetAnimationCounterUD(int AnimationCounterUD)
{
	this->AnimationCounterUD = AnimationCounterUD;
}

void Avatar::SetAnimationInvert(bool AnimationInvert)
{
	this->AnimationInvert = AnimationInvert;
}


// Jump
// Set the player's status to free fall mode
void Avatar::SetOnFreeFall(bool isOnFreeFall)
{
	if (isOnFreeFall)
	{
		inMidAir_Up = false;
		inMidAir_Down = true;
	}
}

// Set the player to jumping upwards
void Avatar::SetToJumpUpwards(bool isOnJumpUpwards)
{
	if (isOnJumpUpwards && isOnGround())
	{
		inMidAir_Up = true;
		inMidAir_Down = false;
		UpwardsFrame = 16;
	}

}

// Set jumpSpeed of the player
void Avatar::SetJumpSpeed(int newjumpSpeed)
{
	this->jumpSpeed = jumpSpeed;
}

// Stop the player's movement
void Avatar::SetToStop(void)
{
	inMidAir_Up = false;
	inMidAir_Down = false;
}

//////////////////////GETTERS/////////////////////

//Animation
int Avatar::GetAnimationCounterLR()
{
	return AnimationCounterLR;
}

int Avatar::GetAnimationCounterUD()
{
	return AnimationCounterUD;
}

bool Avatar::GetAnimationInvert()
{
	return AnimationInvert;
}

///Jump
// Returns true if the player is on ground
bool Avatar::isOnGround()
{
	return (!inMidAir_Up && !inMidAir_Down);
}

// Returns true if the player is jumping upwards
bool Avatar::isJumpUpwards()
{
	return (inMidAir_Up && !inMidAir_Down);
}

// Returns true if the player is on freefall
bool Avatar::isFreeFall()
{
	return (!inMidAir_Up  && inMidAir_Down);
}

int Avatar::GetJumpspeed()
{
	return jumpSpeed;
}
