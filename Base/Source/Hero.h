#ifndef HERO_H
#define HERO_H

#include "avatar.h"
#include "TileMap.h"


class Hero : public Avatar
{
public:
	Hero(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile[], int numberOfTextures);
	virtual ~Hero();

	GEOMETRY_TYPE texture[4];

	//update
	void Update(TileMap* tilemap,double dt);

	//functions
	void Scrolling(TileMap* tilemap,const int leftBorder, const int rightBorder,
		const int topBorder, const int bottomBorder,
		float timeDiff);
	void Constrain(TileMap* tilemap);
	void Reset(TileMap* tilemap);
	void Restart();
	void CollisionContainer(GameObject* other, TileMap* tilemap);
	void CollisionContainer(Avatar * other);
	//movement
	void MoveLeftRight(const bool mode, const float timeDiff,TileMap* tilemap);
	void MoveUpDown(const bool mode, const float timeDiff, TileMap* tilemap);
	void HeroTakeDamage(int damage);
	
	//debound for attacking so that spamming wont occur
	void AttackCooldown(double dt);
	void NormalAttack();
	void SkillAttack();
	//bullet update
	Bullet* BulletCollision(GameObject* other);
	Bullet*FetchGO();
	void BulletUpdate(double dt);
private:
//hero info
	//hero basic value
	bool allowAttack;
	float attackTimer;
	float attackTime;
	int heroDamage;
	int heroHealth;
	int currentPowerUp;
	//buffed values
	int heroShield;
	int DamageBoost;
	int moveX, moveY;
	int initX, initY;

};


#endif