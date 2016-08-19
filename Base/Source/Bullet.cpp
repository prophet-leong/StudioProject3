#include "Bullet.h"

Bullet::Bullet()
{
	meshName = "Bullet";
	active = false;
}

Bullet::Bullet(Vector2 position, Vector2 direction, int damage, int speed,GEOMETRY_TYPE Geo_Type ,BULLET_ELEMENT element)
:Collideables(position.x, position.y, "Bullet", Geo_Type),
defaultPosition(position)
{
	active = true;
	this->Direction = direction;
	this->damage = damage;
	this->bulletSpeed = speed;
	this->element = element;
}

void Bullet::set(Vector2 position, Vector2 direction, int damage, int speed, GEOMETRY_TYPE Geo_Type, BULLET_ELEMENT element)
{
	active = true;
	this->Direction = direction;
	this->damage = damage;
	this->bulletSpeed = speed;
	this->element = element;
	SetPos(position);
	defaultPosition = position;
	type = Geo_Type;
}

bool Bullet::CheckCollision(GameObject* other, TileMap*tilemap)
{
	if ((Position - other->GetPosition()).LengthSquare() <= scale.x*size*size)
	{
		return true;
	}
	return false;
}

void Bullet::CollisionResponse(GameObject* other, TileMap*tilemap)
{
	SetUnactive();
}

void Bullet::Update(double dt)
{
	if (active)
	{

		Position = Position + (Direction*(float)bulletSpeed);
		if ((defaultPosition - Position).LengthSquare() > 250.f*250.f)
			SetUnactive();
	}
}

void Bullet::SetUnactive()
{
	active = false;
}

int Bullet::GetDamage()
{
	return damage;
}

BULLET_ELEMENT Bullet::GetElementType()
{
	return element;
}

Bullet::~Bullet()
{
}
