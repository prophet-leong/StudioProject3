#ifndef BULLET_SURROUND_H
#define BULLET_SURROUND_H

#include "Bullet.h"
class Bullet_Surround:public Bullet
{
public:
	Bullet_Surround(Vector2 position, Vector2 direction = (0, 0), int damage = 1, int speed = 0, GEOMETRY_TYPE type = GEO_SALT, BULLET_ELEMENT = BULLET_ELEMENT::NO_ELEMENT, float radius = 15.0f, float theta = 0.f);
	~Bullet_Surround();
	virtual void Update(GameObject*go ,double dt);
	virtual bool CheckCollision(GameObject* other, TileMap*tilemap);
	virtual void CollisionResponse(GameObject* other, TileMap*tilemap);
	void SetRadiusFromPlayer(float radius);
private:
	float theta;
	float radius;
};

#endif // !BULLET_SURROUND_H
