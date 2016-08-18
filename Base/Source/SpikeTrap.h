#ifndef SPIKETRAP_H_
#define SPIKETRAP_H_
#include "Traps.h"

class C_SpikeTrap : public C_Traps
{
private:

public:
	C_SpikeTrap();
	C_SpikeTrap(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type = Trap_type::SPIKE_TRAP);
	virtual ~C_SpikeTrap();

	virtual bool CheckCollision(GameObject* other, TileMap *tilemap);
	virtual void CollisionResponse(GameObject* other, TileMap *tilemap);
	bool checkdeath();
};


#endif