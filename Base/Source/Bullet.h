#ifndef BULLET_H
#define BULLET_H
#include <Vector2.h>
#include "GeometryType.h"
#include "Collideables.h"
enum BULLET_ELEMENT
{
	NO_ELEMENT,
	FIRE,
	ICE,
	EARTH,
	WIND,
	NUM_ELEMENTS
};
class Bullet :public Collideables
{
public:
	Bullet();
	Bullet(Vector2 position, Vector2 direction, int damage, int speed = 10,GEOMETRY_TYPE type = GEO_SALT ,BULLET_ELEMENT = BULLET_ELEMENT::NO_ELEMENT);
	~Bullet();
	void set(Vector2 position, Vector2 direction, int damage, int speed = 10, GEOMETRY_TYPE type = GEO_SALT, BULLET_ELEMENT = BULLET_ELEMENT::NO_ELEMENT);
	void Update(double dt);
	int GetDamage();
	BULLET_ELEMENT GetElementType();
	void SetUnactive();
	virtual bool CheckCollision(GameObject* other,TileMap*tilemap);
	virtual void CollisionResponse(GameObject* other, TileMap*tilemap);
private:
	Vector2 defaultPosition;
	BULLET_ELEMENT element;
	int bulletSpeed;
	int damage;
	Vector2 Direction;
};

#endif // !BULLET_H