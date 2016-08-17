#include "Gate.h"

Gate::Gate()
	:GameObject()
	, generator(NULL)
{
	active = false;
}

Gate::Gate(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, Generator generator)
	: GameObject(x,y,meshName,typeOfTile)
{
	active = false;
	this->generator = &generator;
}

Gate::~Gate()
{

}

Vector2 Gate::GetLocation()
{
	return nextLocation;
}

void Gate::SetLocation(Vector2 newLocation)
{
	nextLocation = newLocation;
}

bool Gate::CheckCollision(Avatar* theHero, TileMap* tilemap)
{
	if (theHero->meshName != "HERO")
		return false;

	return (GetPosition() - theHero->GetPosition()).LengthSquare()< tilemap->GetTileSize() * tilemap->GetTileSize();
}

void Gate::CollisionResponse()
{
	generator->GoToNextLevel(nextLocation);
}

bool Gate::Check(Vector2 Check)
{
	return generator->Check(Check);
}