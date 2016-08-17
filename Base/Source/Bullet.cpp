#include "Bullet.h"


Bullet::Bullet(Vector2 position, Vector2 direction, int damage, int speed,GEOMETRY_TYPE Geo_Type ,BULLET_ELEMENT element)
:GameObject(position.x,position.y,"Bullet",Geo_Type)
{
	this->Direction = direction;
	this->damage = damage;
	this->bulletSpeed = speed;
	this->element = element;
	active = true;
}
bool Bullet::CheckCollision(GameObject* go ,float units)
{
	if ((Position - go->GetPosition()).LengthSquare() <= units*units)
	{
		return true;
	}
}
void Bullet::Update(GameObject* go ,double dt)
{
	if (active)
	{
		Position = Position + (Direction*(float)bulletSpeed);
		if (CheckCollision(go,5))
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
