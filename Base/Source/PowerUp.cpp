#include "PowerUp.h"

PowerUp::PowerUp(int x, int y, string meshName, string meshTexture, string PowerUp, float Duration)
	:GameObject(x,y,meshName,meshTexture)
	, powerup(PowerUp)
	, powerUpDuration(Duration)
{

}

PowerUp::~PowerUp()
{

}
void PowerUp::Update(double dt)
{
	if (powerUpDuration > 0)
	{
		powerUpDuration -= dt;
		if (powerUpDuration <= 0)
		{
			active = false;
			powerUpDuration = 0.f;
		}
	}
}