#include "Hero.h"

//'x' and 'y' is position , meshName = name of the mesh , typeoftile = geometry type , numberoftextures = amount of textures for 'typeOfTile' 1 texture = 1
Hero::Hero(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile[],int numberOfTextures)
	: moveX(0)
	, moveY(0) 
	, Avatar(x, y, meshName, typeOfTile[0])
{
	for (int i = 0; i < numberOfTextures; ++i)
	{
		this->texture[i] = typeOfTile[i];
	}
	heroShield = 0;
	heroDamage = 1;
	DamageBoost = 0;
	attackTime = 0.2f;
	attackTimer = 0.2f;
	allowAttack = true;
	direction.Set(1, 0);
	currentPowerUp = 0;
	inventory = new Bag();
}

Hero::~Hero()
{
	delete inventory;
}
 
//status::done
void Hero::Update(TileMap* tilemap , double dt)
{
	if (!inventory->powerUpList.empty())
	{
		PowerUp *go = inventory->powerUpList[currentPowerUp];
		go->Update(dt);
		switch (go->GetIncrementStat())
		{
			case SHIELD:
			{
				if (go->active && go->GetActivated() == false)
				{
					heroShield = go->GetIncrement();
					go->SetActivated(true);
				}
			}
		}
	}
	AttackCooldown(dt);
	BulletUpdate(dt);
	moveLeft = moveRight = moveUp = moveDown = true;

	inventory->Update(dt);

	moveX = (tilemap->GetScreenWidth() * 0.5f) + tilemap->offSet_x;
	moveY = (tilemap->GetScreenHeight() * 0.7f) + tilemap->offSet_y;

	Scrolling(tilemap, moveX, moveX , moveY , moveY, 60.f * dt);
	
	Constrain(tilemap);
}

Bullet* Hero::FetchGO()
{
	for (std::vector<Bullet*>::iterator iter = Projectile.begin(); iter != Projectile.end(); ++iter)
	{
		Bullet *go = *iter;
		if (!go->active)
		{
			go->active = true;
			return go;
		}
	}
	Bullet *newBullet = new Bullet();
	Projectile.push_back(newBullet);
	return newBullet;
}

void Hero::NextPowerUp()
{
	if (currentPowerUp < inventory->powerUpList.size())
		currentPowerUp++;
	else
		currentPowerUp = 0;
}

void Hero::AttackCooldown(double dt)
{
	if (allowAttack == false)
	{
		attackTimer -= dt;
		if (attackTimer <= 0)
			allowAttack = true;
	}
}

void Hero::NormalAttack()
{
	if (allowAttack == true)
	{
		attackTimer = attackTime;
		allowAttack = false;
		Bullet* newBullet = FetchGO();
		newBullet->set(Position, direction, heroDamage);
		newBullet->SetScale(Vector2(0.5f, 0.5f));
	}
}

void Hero::SkillAttack()
{
	if (allowAttack == true && !inventory->powerUpList.empty() && inventory->powerUpList[currentPowerUp]->GetIncrementStat() == ATTACK)
	{
		attackTimer = attackTime;
		allowAttack = false;
		inventory->powerUpList[currentPowerUp];
		Bullet* newBullet = FetchGO();
		newBullet->set(Position, direction, heroDamage + inventory->powerUpList[currentPowerUp]->GetIncrement(), 5, GEO_FIRESALT, FIRE);
		newBullet->SetScale(Vector2(0.5f, 0.5f));
	}
}

void Hero::BulletUpdate(double dt)
{
	for (int i = 0; i < Projectile.size(); ++i)
	{
		Projectile[i]->Update(dt);
	}
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
	SetAnimationCounterLR(0);
	SetAnimationInvert(false);
	tilemap->offSet_x = 0;
	tilemap->offSet_y = 0;
}

//Full-Reset
void Hero::Restart()
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
		direction.Set(-1, 0);
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
		direction.Set(1, 0);
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
		{
			Position.y += (int)(8.0f * timeDiff);
		}
		direction.Set(0, 1);
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
		direction.Set(0, -1);
		AnimationInvert = false;
		AnimationCounterUD++;
		if (AnimationCounterUD > 3)
			AnimationCounterUD = 0;
	}

	SetTexture(texture[AnimationCounterLR]);
}

void Hero::HeroTakeDamage(int damage)
{
	if (heroShield <= 0)
		health -= damage;
	else
		heroShield -= damage;
		
}

Bullet* Hero::BulletCollision(GameObject* other, TileMap* tilemap)
{
	for (int i = 0; i < Projectile.size(); ++i)
	{
		if (Projectile[i]->active)
		{
			if (Projectile[i]->CheckCollision(other,tilemap))
			{
				Projectile[i]->CollisionResponse(other, tilemap);
				return Projectile[i];
			}
		}
	}
	return NULL;
}
//virtual collision
bool Hero::CheckCollision(GameObject* other, TileMap *tilemap)
{
	Bullet* bullet = BulletCollision(other, tilemap);
	if (bullet != NULL)
	{
 		bullet->SetUnactive();
		if (other->meshName == "GEO_ENEMY")
		{
			Avatar* enemy = (Avatar*)other;
			enemy->health -= bullet->GetDamage();
			enemy->SetElementState(bullet->GetElementType());
			//temp isdead
			if (enemy->health <= 0)
			{
				enemy->active = false;
			}
			cout << enemy->health << endl;
		}
	}

	return BasicCheckCollision(other,tilemap);
}

void Hero::CollisionResponse(GameObject* other, TileMap *tilemap)
{
	BasicCollisionResponse(other, tilemap);
}


