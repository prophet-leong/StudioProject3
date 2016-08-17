#include "Bullet.h"


Bullet::Bullet()
{
	active = false;
}
Bullet::Bullet(Vector2 position, Vector2 direction, int damage, int speed,GEOMETRY_TYPE Geo_Type ,BULLET_ELEMENT element)
:Collideables(position.x, position.y, "Bullet", Geo_Type),
defaultPosition(position)
{
	this->Direction = direction;
	this->damage = damage;
	this->bulletSpeed = speed;
	this->element = element;
	active = true;
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
	meshName = "Bullet";
	type = Geo_Type;
}
bool Bullet::CheckCollision(GameObject* go ,float units)
{
	if ((Position - go->GetPosition()).LengthSquare() <= units*units)
	{
		return true;
	}
}
void Bullet::CollisionResponse()
{
	SetUnactive();
}
void Bullet::Update(double dt)
{
	if (active)
	{
		Position = Position + (Direction*(float)bulletSpeed);
		if ((defaultPosition - Position).LengthSquare() > 100.f*100.f)
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

Bullet::~Bullet()
{
}
