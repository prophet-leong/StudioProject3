#ifndef TRAPS_H_
#define TRAPS_H_
#include "Collideables.h"
#include "avatar.h"
#include "Vector2.h"
#include "TileMap.h"

enum Trap_type
{
	TRAP_START=0,
	SPIKE_TRAP,
	POISONED_BLOCK,
};
class C_Traps : public Collideables
{
protected:
	float Damage_taken;
	Trap_type traptype;
public:
	C_Traps();
	C_Traps(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken);
	virtual ~C_Traps();
	virtual bool checkdeath(){ return false; };
};


#endif