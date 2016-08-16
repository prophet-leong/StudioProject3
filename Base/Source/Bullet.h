#ifndef BULLET_H
#define BULLET_H
#include <Vector2.h>
enum BULLET_ELEMENT
{
	NO_ELEMENT,
	FIRE,
	ICE,
	EARTH,
	WIND,
	NUM_ELEMENTS
};
class Bullet
{
public:
	Bullet(Vector2 position, Vector2 direction, int damage, int speed, BULLET_ELEMENT = BULLET_ELEMENT::NO_ELEMENT);
	~Bullet();
	Vector2 GetPosition();
	int GetDamage();
private:
	BULLET_ELEMENT element;
	int bulletSpeed;
	int damage;
	Vector2 position;
	Vector2 Direction;
};

#endif // !BULLET_H