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
	virtual bool CheckCollision(Avatar* go, TileMap *tilemap){ return false; };
	virtual void CollisionResponse(Avatar* other, TileMap *tilemap){};
	virtual bool checkdeath(){ return false; };
	virtual void Init(int x, int y, string meshName, GEOMETRY_TYPE geotype);
};

class C_SpikeTrap : public C_Traps
{
private:

public:
	C_SpikeTrap();
	C_SpikeTrap(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type = Trap_type::SPIKE_TRAP);
	virtual ~C_SpikeTrap();

	virtual bool CheckCollision(Avatar* other, TileMap *tilemap);
	virtual void CollisionResponse(Avatar* other, TileMap *tilemap);
	virtual bool checkdeath();
};

class C_PoisonedBlock : public C_Traps
{
public:
	C_PoisonedBlock();
	C_PoisonedBlock(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type traptype);
	~C_PoisonedBlock();

	virtual bool CheckCollision(Avatar* other, TileMap *tilemap);
	virtual void CollisionResponse(Avatar* other, TileMap *tilemap);
	virtual bool checkdeath();

};

#endif