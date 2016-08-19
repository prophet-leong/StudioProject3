#ifndef GATE_H
#define GATE_H
#include "Collideables.h"
#include "Hero.h"
#include "MapGenerator.h"
#include "SharedData.h"

/**************************************************/
/*!
\file		Gate.h
\author		Chua Teck Lee
\par		Email:C_tecklee@hotmail.com
\brief		Class to define a Gate
*/
/**************************************************/

/**************************************************/
/*!
			Class Gate:
\brief		Defines a Gate Object and its methods
*/
/**************************************************/

class Gate : public Collideables
{
public:
	Gate();
	Gate(int x, int y, string meshName, GEOMETRY_TYPE typeOfTile, Generator * generator);
	virtual ~Gate();

	virtual bool CheckCollision(GameObject* theHero, TileMap* tilemap);
	virtual void CollisionResponse(GameObject* theHero, TileMap* tilemap);

	Vector2 GetLocation();
	void SetLocation(Vector2 newLocation);
	
	//public direction
	bool up, down, left, right;
private:

	Vector2 nextLocation;
	Generator* generator;
};

#endif