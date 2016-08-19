#include "SpikeTrap.h"


C_SpikeTrap::C_SpikeTrap() : C_Traps()
{

}

C_SpikeTrap::C_SpikeTrap(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken, Trap_type traptype) : C_Traps(x, y, meshName, geotype, damage_taken)
{
	traptype = SPIKE_TRAP;
}
C_SpikeTrap::~C_SpikeTrap()
{

}
bool C_SpikeTrap::CheckCollision(GameObject* other, TileMap *tilemap)
{
	return (GetPosition() - other->GetPosition()).LengthSquare() <= tilemap->GetTileSize() * tilemap->GetTileSize();
}
void C_SpikeTrap::CollisionResponse(GameObject* other, TileMap *tilemap)
{
	Avatar* Other = (Avatar*)other;
	if (Other->meshName == "HERO")
	{
		Other->TakeDamage(1);
	}
}
bool C_SpikeTrap::checkdeath()
{
	return true;
}