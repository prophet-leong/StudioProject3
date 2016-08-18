#include "Traps.h"


C_Traps::C_Traps() : Collideables(), Damage_taken(0), traptype(SPIKE_TRAP)
{

}

C_Traps::C_Traps(int x, int y, string meshName, GEOMETRY_TYPE geotype, float damage_taken) : Collideables(x, y, meshName, geotype)
{
	this->Damage_taken = damage_taken;
}

C_Traps::~C_Traps()
{

}