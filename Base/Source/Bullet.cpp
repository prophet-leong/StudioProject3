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
#include <iostream>
bool Bullet::CheckCollision(GameObject* go)
{
	if ((Position - go->GetPosition()).LengthSquare() <= 15*15)
	{
		std::cout << GetPosition().x << "  " << GetPosition().y << std::endl;
		std::cout << go->GetPosition().x << "  " << go->GetPosition().y << std::endl;
		return true;
	}
	return false;
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

Bullet::~Bullet()
{
}
