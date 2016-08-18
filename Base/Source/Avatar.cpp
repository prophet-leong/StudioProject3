#include "avatar.h"

Avatar::Avatar()
	:Collideables()
	, AnimationCounterLR(0)
	, AnimationCounterUD(0)
	, AnimationInvert(false)
	, moveUp(true)
	, moveDown(true)
	, moveLeft(true)
	, moveRight(true)
	, health(0)
{

}

Avatar::Avatar(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile)
	: Collideables(x, y, meshName, typeOfTile)
	, AnimationCounterLR(0)
	, AnimationCounterUD(0)
	, AnimationInvert(false)
	, moveUp(true)
	, moveDown(true)
	, moveLeft(true)
	, moveRight(true)
	, health(0)
{
	//inventory = new Bag();
}

Avatar::~Avatar()
{
	//delete inventory;
}

/////////////////FUNCTIONS///////////////////////

bool Avatar::BasicCheckCollision(GameObject* other,TileMap* tilemap)
{
	return ( (GetPosition() - other->GetPosition()).LengthSquare() < 1.5f*tilemap->GetTileSize()*tilemap->GetTileSize() );
}
bool Avatar::CheckCollision(GameObject* other, TileMap* tilemap)
{
	return ((GetPosition() - other->GetPosition()).LengthSquare() < 1.5f*tilemap->GetTileSize()*tilemap->GetTileSize());
}
void Avatar::CollisionContainer(GameObject* other, TileMap* tilemap)
{
	if (other->type == GEO_TILEGROUND && BasicCheckCollision(other,tilemap) == true)//|| whatever other object you want that have collision)
		BasicCollisionResponse(other, tilemap);
}
void Avatar::BasicCollisionResponse(GameObject* other, TileMap* tilemap)
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

//default bullet updates
Bullet* Avatar::BulletCollision(GameObject* other)
{
	for (int i = 0; i < Projectile.size(); ++i)
	{
		if (Projectile[i]->active)
		{
			if (Projectile[i]->CheckCollision(other))
			{
				Projectile[i]->CollisionResponse();
				return Projectile[i];
			}
		}
	}
	return NULL;
}
Bullet* Avatar::FetchGO()
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
void Avatar::BulletUpdate(double dt)
{
	for (int i = 0; i < Projectile.size(); ++i)
	{
		Projectile[i]->Update(dt);
	}
}
void Avatar::SetElementState(BULLET_ELEMENT element)
{
	this->element = element;
	element_Status = 1.0f;
	tick = 2;
}
void Avatar::ElementStateUpdate()
{
	if (element != BULLET_ELEMENT::NO_ELEMENT)
	{
		if (element_Status <= 0)
		{
			switch (element)
			{
			case FIRE:
			{
				if (tick == 0)
					element = BULLET_ELEMENT::NO_ELEMENT;
				else
				{
					--tick;
					--health;
				}
			}
			}
		}
	}
}