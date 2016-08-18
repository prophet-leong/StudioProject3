#ifndef POISONBLOCK_H_
#define POISONBLOCK_H_
#include "Traps.h"


class C_PoisonedBlock : public C_Traps
{
public:
	C_PoisonedBlock();
	C_PoisonedBlock(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type traptype);
	~C_PoisonedBlock();

	bool CheckCollision(Avatar* other, TileMap *tilemap);
	void CollisionResponse(Avatar* other, TileMap *tilemap);
	bool checkdeath();

};

#endif