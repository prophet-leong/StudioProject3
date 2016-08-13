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

	int score;
	short coins;
	vector<PowerUp *> powerUpList;
};
#endif