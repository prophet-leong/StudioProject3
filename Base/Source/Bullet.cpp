#include "Bullet.h"



Bullet::Bullet(Vector2 position, Vector2 direction, int damage, int speed, BULLET_ELEMENT element)
{
	this->position = position;
	this->Direction = direction;
	this->damage = damage;
	this->bulletSpeed = speed;
	this->element = element;
}
Vector2 Bullet::GetPosition()
{
	return position;
}

int Bullet::GetDamage()
{
	return damage;
}
Bullet::~Bullet()
{
}
