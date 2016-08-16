#ifndef POWER_UP
#define POWER_UP
#include "GeometryType.h"
#include "GameObject.h"
#include <string>
using std::string;

// power up needs to be able to be rendered on screen after the death of a boss monster
// but also need to be able to be kept in bag
enum INCREMENT_STAT
{
	NO_SKILL,
	SHIELD,
	ATTACK,
	NUM_INCREMENT_STAT
};
class PowerUp:public GameObject
{
public:
	PowerUp(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp);
	virtual ~PowerUp();

	virtual void Update(double dt) = 0;
	virtual void activate(){};
	INCREMENT_STAT GetIncrementStat();
	void SetSPCost(int SP);
	int GetSPCost();
	void SetIncrementStat(INCREMENT_STAT stat);
	int GetIncrement();
	void SetIncrement(int increase);
	bool GetInBag();
	void SetInBag(bool isInBag);
	string GetPowerUpName();
	void SetPowerUpName(string newName);
	void SetActivated(bool activated);
	bool GetActivated();
	GEOMETRY_TYPE GetGeoType();
private:
	bool inBag;
	bool activated;
	INCREMENT_STAT increment_type;
	GEOMETRY_TYPE type;
	int increment;
	int SP_Cost;
};
#endif