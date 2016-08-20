#include "Bullet_Surround.h"
#include "avatar.h"
#include "MyMath.h"
Bullet_Surround::Bullet_Surround(Vector2 position, Vector2 direction, int damage, int speed,GEOMETRY_TYPE type ,BULLET_ELEMENT element,float radius,float theta)
:Bullet(position,direction,damage,speed,type,element)
{
	//default position will be player postion in the case
	defaultPosition = position;
	meshName = "BULLET_SURROUND";
	this->radius = radius;
	this->theta = theta;
}
void Bullet_Surround::Update(GameObject*go,double dt)
{
	float offset = size*0.5f;
	defaultPosition = go->GetPosition() + Vector2(offset,offset);
	Position.x = radius*cos(Math::DegreeToRadian(theta));
	Position.y = radius*sin(Math::DegreeToRadian(theta));
	Position = Position + defaultPosition;
	theta += dt * 120;
}
bool Bullet_Surround::CheckCollision(GameObject* other, TileMap*tilemap)
{
	if ((Position - other->GetPosition()).LengthSquare() <= scale.x*size*size)
	{
		return true;
	}
	return false;
}
void Bullet_Surround::CollisionResponse(GameObject* other, TileMap*tilemap)
{
	if (other->meshName == "GEO_ENEMY")
	{
		Avatar* enemy = (Avatar*)other;
		enemy->TakeDamage(damage);
		enemy->SetElementState(element);
	}
}
void Bullet_Surround::SetRadiusFromPlayer(float radius)
{
	this->radius = radius;
}

Bullet_Surround::~Bullet_Surround()
{
}
