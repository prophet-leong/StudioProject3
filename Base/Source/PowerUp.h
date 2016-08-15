#ifndef POWER_UP
#define POWER_UP
#include "GeometryType.h"

//#include "Hero.h"
#include <string>
using std::string;

// power up needs to be able to be rendered on screen after the death of a boss monster
// but also need to be able to be kept in bag
class PowerUp
{
public:
	PowerUp(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp);
	~PowerUp();
	virtual void Update(/*Hero& hero ,*/ double dt)=0;
	virtual void activate() =0;
	bool GetInBag();
	void SetInBag(bool isInBag);
	string GetPowerUpName();
	void SetPowerUpName(string newName);
	bool active;
private:

	GEOMETRY_TYPE type;
	bool inBag;
	int x;
	int y;
	string PowerUpName;

};
#endif