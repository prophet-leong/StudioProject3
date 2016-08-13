#ifndef POWER_UP
#define POWER_UP
#include "GameObject.h"

class PowerUp : public GameObject
{
public:
	PowerUp(int x, int y, string meshName,GEOMETRY_TYPE typeOfTile, string PowerUp, float Duration);
	~PowerUp();

	void Update(double dt);

	string powerup;
	float powerUpDuration;

};
#endif