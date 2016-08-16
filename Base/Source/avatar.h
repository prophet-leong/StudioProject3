#ifndef AVATAR_H
#define AVATAR_H
#include "GameObject.h"
#include "Bag.h"
#include "TileMap.h"

class Avatar :public GameObject
{
public:
	Avatar();
	Avatar(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile);
	virtual ~Avatar();

	//functions
	//virtual void update(double dt) = 0;
	virtual bool CheckCollision(GameObject* other, TileMap* tilemap);
	virtual void CollisionResponse(GameObject* other, TileMap* tilemap);
	virtual void CheckStrategy(GameObject* other, TileMap* tilemap);

	//setters
	void SetAnimationCounterLR(int AnimationCounterLR);
	void SetAnimationCounterUD(int AnimationCounterUD);
	void SetAnimationInvert(bool AnimationInvert);

	//jumping
	void SetOnFreeFall(bool isOnFreeFall);
	void SetToJumpUpwards(bool isOnJumpUpwards);
	void SetJumpSpeed(int newJumpSpeed);
	void SetToStop();

	//getters
	int GetAnimationCounterUD();
	int GetAnimationCounterLR();
	bool GetAnimationInvert();

	//jumping
	bool isOnGround();
	bool isJumpUpwards();
	bool isFreeFall();
	int   GetJumpspeed();

	//public variables
	bool moveUp, moveDown, moveLeft, moveRight;
	//for different powerups
	Bag* inventory;
	Vector2 direction;

protected:
	//for Animation
	bool AnimationInvert;
	int AnimationCounterLR;
	int AnimationCounterUD;

	//for jumping
	bool inMidAir_Up, inMidAir_Down;
	int jumpSpeed;
	int UpwardsFrame;

};









#endif