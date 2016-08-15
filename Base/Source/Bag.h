#ifndef BAG_H
#define BAG_H
#include "PowerUp.h"
#include <vector>
using std::vector;

struct Bag
{
	Bag();
	~Bag();

	void Update(double dt);

	vector<PowerUp*>powerUpList;
};
#endif