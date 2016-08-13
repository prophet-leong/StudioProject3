#include "Bag.h"

Bag::Bag()
	: score(0)
	, coins(0)
{
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