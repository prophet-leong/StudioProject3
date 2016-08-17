#include "Traps.h"


C_Traps::C_Traps()
{

}
C_Traps::C_Traps(Vector2 position, float damage_taken)
{
	this->Position = position;
	this->Damage_taken = damage_taken;
}
C_Traps::~C_Traps()
{

}

C_SpikeTrap::C_SpikeTrap()
{

}
C_SpikeTrap::C_SpikeTrap(Vector2 position, float damage_taken, GEOMETRY_TYPE type, Trap_type traptype)
{
	this->Position = position;
	this->Damage_taken = damage_taken;
	type = GEO_SPIKE_TRAP;
	traptype = SPIKE_TRAP;
}
C_SpikeTrap::~C_SpikeTrap()
{

}
bool C_SpikeTrap::CheckCollision(Avatar* other, TileMap *tilemap)
{
	if (other->meshName == "HERO")
	{
			return (GetPosition() - other->GetPosition()).LengthSquare() <= tilemap->GetTileSize() * tilemap->GetTileSize();
	}
}
void C_SpikeTrap::CollisionResponse(Avatar* other, TileMap *tilemap)
{
	if (other->meshName == "HERO")
	{
		other->health -= 1;
	}
}
bool C_SpikeTrap::checkdeath()
{
	return true;
}

C_PoisonedBlock::C_PoisonedBlock()
{

}
C_PoisonedBlock::C_PoisonedBlock(Vector2 position, float damage_taken, GEOMETRY_TYPE type, Trap_type traptype)
{
	this->Position = position;
	this->Damage_taken = damage_taken;
	type = GEO_SPIKE_TRAP;
	traptype = POISONED_BLOCK;
}
C_PoisonedBlock::~C_PoisonedBlock()
{

}

bool C_PoisonedBlock::CheckCollision(Avatar* other, TileMap *tilemap)
{

}
void C_PoisonedBlock::CollisionResponse(Avatar* other, TileMap *tilemap)
{

}
bool C_PoisonedBlock::checkdeath()
{

}