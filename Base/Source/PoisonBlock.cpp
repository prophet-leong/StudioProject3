#include "PoisonBlock.h"

C_PoisonedBlock::C_PoisonedBlock() : C_Traps()
{

}
C_PoisonedBlock::C_PoisonedBlock(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type traptype) : C_Traps(x, y, meshName, geotype, damage_taken)
{
	traptype = POISONED_BLOCK;
}
C_PoisonedBlock::~C_PoisonedBlock()
{

}

bool C_PoisonedBlock::CheckCollision(Avatar* other, TileMap *tilemap)
{
	if (other->meshName == "HERO")
	{
		return (GetPosition() - other->GetPosition()).LengthSquare() <= tilemap->GetTileSize() * tilemap->GetTileSize();
	}
}
void C_PoisonedBlock::CollisionResponse(Avatar* other, TileMap *tilemap)
{
	if (other->meshName == "HERO")
	{
		other->health -= 1;
	}
}
bool C_PoisonedBlock::checkdeath()
{
	return false;
}