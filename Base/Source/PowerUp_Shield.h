#ifndef POWERUP_SHIELD
#define POWERUP_SHIELD
#include "PowerUp.h"

class PowerUp_Shield:public PowerUp
{
public:
	PowerUp_Shield(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp , int damageMitigation , float maxDuration);
	~PowerUp_Shield();
	virtual void Update(/*Hero* hero , */double dt);
private:
	int damageMitigation;
	float maxDuration;
	float duration;
};

#endif // !POWERUP_SHIELD
