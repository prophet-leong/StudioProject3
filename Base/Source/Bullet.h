#ifndef BULLET_H
#define BULLET_H
#include <Vector2.h>
#include "GeometryType.h"
#include "GameObject.h"
enum BULLET_ELEMENT
{
	NO_ELEMENT,
	FIRE,
	ICE,
	EARTH,
	WIND,
	NUM_ELEMENTS
};
class Bullet :public GameObject
{
public:
	Bullet(Vector2 position, Vector2 direction, int damage, int speed = 10,GEOMETRY_TYPE type = GEO_SALT ,BULLET_ELEMENT = BULLET_ELEMENT::NO_ELEMENT);
	~Bullet();
	void Update(double dt);
	int GetDamage();
private:
	BULLET_ELEMENT element;
	int bulletSpeed;
	int damage;
	Vector2 Direction;
};

#endif // !BULLET_H