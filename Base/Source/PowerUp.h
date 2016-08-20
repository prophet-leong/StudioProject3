#ifndef POWER_UP
#define POWER_UP
#include "GeometryType.h"
#include "GameObject.h"
#include <string>
#include "BULLET_ELEMENT.h"
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
	PowerUp(int x, int y, GEOMETRY_TYPE typeOfTile, string PowerUp = "POWERUP");
	virtual ~PowerUp();

	virtual void Update(double dt) = 0;
	virtual void activate(){};
	INCREMENT_STAT GetIncrementStat();
	//limit for the sp
	void SetSPCost(int SP);
	int GetSPCost();
	//set or return the value of stat increase
	void SetIncrementStat(INCREMENT_STAT stat);
	int GetIncrement();
	void SetIncrement(int increase);
	//name of powerup
	void SetPowerUpName(string newName);
	string GetPowerUpName();
	//run once when activated
	void SetActivated(bool activated);
	bool GetActivated();
	GEOMETRY_TYPE GetGeoType();
	//element
	BULLET_ELEMENT GetElementType();
	void SetElementType(BULLET_ELEMENT elementType);
private:
	BULLET_ELEMENT elementType = NO_ELEMENT;
	bool activated;
	INCREMENT_STAT increment_type;
	int increment;
	int SP_Cost;
};
#endif