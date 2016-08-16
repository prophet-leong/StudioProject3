#include "Bag.h"
#include "PowerUp_Attack.h"

Bag::Bag()
{
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