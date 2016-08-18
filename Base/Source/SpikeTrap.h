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

	bool CheckCollision(Avatar* other, TileMap *tilemap);
	void CollisionResponse(Avatar* other, TileMap *tilemap);
	bool checkdeath();
};


#endif