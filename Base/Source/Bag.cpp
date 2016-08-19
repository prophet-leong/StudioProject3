#include "Bag.h"
#include "PowerUp_Attack.h"
#include "PowerUp_Shield.h"
Bag::Bag()
{
	PowerUp_Shield *shield = new PowerUp_Shield(0, 0, GEO_COIN, "Shield", 3, 2.0f);
	powerUpList.push_back(shield);
	PowerUp_Attack *a = new PowerUp_Attack(0, 0, GEO_COIN, "FIRE", 5, 20, true);
	powerUpList.push_back(a);
}

Bag::~Bag()
{

}

void Bag::Update(double dt)
{
	for (vector<PowerUp*>::iterator iter = powerUpList.begin(); iter != powerUpList.end(); iter++)
	{
		PowerUp *go = (PowerUp *)*iter;
		if (!go->active)
			continue;
		go->Update(dt);
	}
}