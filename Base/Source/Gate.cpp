#include "Gate.h"

Gate::Gate()
	:Collideables()
	, generator(NULL)
	, up(false)
	, down(false)
	, left(false)
	, right(false)
{
	active = false;
}

Gate::Gate(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, Generator*generator)
	: Collideables(x, y, meshName, typeOfTile)
	, up(false)
	, down(false)
	, left(false)
	, right(false)
{
	active = false;
	this->generator = generator;
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

	if (nextLocation == Vector2(0, 1)) 
		up = true; 
	else if (nextLocation == Vector2(0, -1)) 
		down = true; 
	else if (nextLocation == Vector2(-1, 0)) 
		left = true; 
	else if (nextLocation == Vector2(1, 0)) 
		right = true;

}

bool Gate::CheckCollision(GameObject* theHero, TileMap* tilemap)
{
	if (theHero->meshName != "HERO")
		return false;

	return (GetPosition() - theHero->GetPosition()).LengthSquare()< tilemap->GetTileSize() * tilemap->GetTileSize();
}

void Gate::CollisionResponse(GameObject* theHero, TileMap* tilemap)
{
	generator->GoToNextLevel(nextLocation);
	if (up)
		SharedData::GetInstance()->SD_CurrDoor = UP;
	else if (down)
		SharedData::GetInstance()->SD_CurrDoor = DOWN;
	else if (left)
		SharedData::GetInstance()->SD_CurrDoor = LEFT;
	else if (right)
		SharedData::GetInstance()->SD_CurrDoor = RIGHT;
}

bool Gate::Check(Vector2 Check)
{
	return generator->Check(Check);
}