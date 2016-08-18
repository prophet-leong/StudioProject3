#include "Gate.h"
/***********************************************/
/*!
\brief
default constructor
*/
/***********************************************/
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
/***********************************************/
/*!
\brief
overloaded constructor that creates the object
\param x: the x coordinate of the gate
		y: the y coordinate of the gate
		meshName : the meshName of the gate
		typeofTile : the thing to render
		generator: a pointer to the generator used
*/
/***********************************************/
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
/***********************************************/
/*!
\brief
default destructor
*/
/***********************************************/
Gate::~Gate()
{

}
/***********************************************/
/*!
\brief
return the location of the next room
\returns
vector2 containing location of the next room
*/
/***********************************************/
Vector2 Gate::GetLocation()
{
	return nextLocation;
}

/***********************************************/
/*!
\brief
set Location 
\param newLocation:the location of the next room
*/
/***********************************************/
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

/***********************************************/
/*!
\brief
Check for collision detection between objects
\ param theHero:the Player
tilemap : the current map used
\returns
returns whether or not gate collided with anything
*/
/***********************************************/
bool Gate::CheckCollision(GameObject* theHero, TileMap* tilemap)
{
	if (theHero->meshName != "HERO")
		return false;

	return (GetPosition() - theHero->GetPosition()).LengthSquare()< tilemap->GetTileSize() * tilemap->GetTileSize();
}

/***********************************************/
/*!
\brief
Response if player touch the gate
\ param theHero:the Player
		tilemap : the current map used
*/
/***********************************************/
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
