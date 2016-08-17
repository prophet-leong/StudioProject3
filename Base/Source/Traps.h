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
};
class C_Traps : public Collideables
{
private:
	Vector2 Position;
	float Damage_taken;
public:
	C_Traps();
	C_Traps(Vector2 position,float damage_taken);
	virtual ~C_Traps();
	virtual bool CheckCollision(Avatar* go, TileMap *tilemap){ return false; };
	virtual void CollisionResponse(Avatar* other, TileMap *tilemap){};
	virtual bool checkdeath(){ return false; };
};

class C_SpikeTrap : public C_Traps
{
public:
	C_SpikeTrap();
	C_SpikeTrap(Vector2 position, float damage_taken, GEOMETRY_TYPE type = GEO_SPIKE_TRAP, Trap_type = Trap_type::SPIKE_TRAP);
	virtual ~C_SpikeTrap();

	virtual bool CheckCollision(Avatar* other, TileMap *tilemap);
	virtual void CollisionResponse(Avatar* other, TileMap *tilemap);
	virtual bool checkdeath();
};

#endif