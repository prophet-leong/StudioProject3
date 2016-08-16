#ifndef HERO_H
#define HERO_H

#include "avatar.h"
#include "TileMap.h"
#include "Bullet.h"

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
	void Restart(TileMap* tilemap);
	//movement
	void MoveLeftRight(const bool mode, const float timeDiff,TileMap* tilemap);
	void MoveUpDown(const bool mode, const float timeDiff, TileMap* tilemap);
	void HeroTakeDamage(int damage);
	//debound for attacking so that spamming wont occur
	void AttackCooldown(double dt);
	void NormalAttack();
	void SkillAttack();
	//bullet update
	void BulletUpdate(double dt);
	vector<Bullet>Projectile;
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